#include <stdio.h>
#include "log.h"
#include "wm.h"

int main(int argc, char* argv[]) {
    WmInit(NULL);
    WmRun();
    return 0;
}
