//
// Created by ven on 05/01/2022.
//

#include "wm.h"
#include "log.h"
#include "util.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdbool.h>

const int BUFFER_SIZE = 1024;

// BEGIN not exported

Display *mDisplay;
Window mRoot;

int handleInitErr(Display *display, XErrorEvent *event) {
    if (LIKELY(event->error_code == BadAccess)) {
        LogFatal("An X session is already running on display %s.", XDisplayString(display));
    }
    return 0;
}

int handleErr(Display *display, XErrorEvent *event) {
    char errorText[BUFFER_SIZE];
    XGetErrorText(mDisplay, event->error_code, errorText, BUFFER_SIZE);

    LogError("Error on display %s D:\n\t%Request %d (%s)\n\tError %d (%s)",
             XDisplayString(display),
             event->request_code,
             X_REQUEST_CODE_NAMES[event->request_code],
             event->error_code,
             errorText
    );
    return 0;
}

// END not exported

void WmInit(const char *displayName) {
    mDisplay = XOpenDisplay(displayName);
    CHECK_NOT_NULL(mDisplay, "Failed to open display %s", XDisplayName(displayName));
    mRoot = XDefaultRootWindow(mDisplay);
}


void WmRun() {
    XSetErrorHandler(&handleInitErr);
    XSelectInput(mDisplay, mRoot, SubstructureRedirectMask | SubstructureNotifyMask);
    XSync(mDisplay, false);

    XSetErrorHandler(&handleErr);

    XGrabServer(mDisplay);
    Window root, parent;
    Window *children;
    unsigned int childrenCount;

    CHECK(XQueryTree(mDisplay, mRoot, &root, &parent, &children, &childrenCount), "Failed to query X tree");
    CHECK_EQ(root, mRoot, "Root returned by tree query differs from own root window, aborting.");

    for (int i = 0; i < childrenCount; i++) {
        // TODO
    }

    XUngrabServer(mDisplay);
    XFree(children);

    LogInfo("Woohoo init!!");
    while (1) {
        XEvent event;
        XNextEvent(mDisplay, &event);
        LogDebug("Next Event");
    }
}

void WmKill() {
    XCloseDisplay(mDisplay);
}
