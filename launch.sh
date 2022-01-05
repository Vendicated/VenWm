#!/bin/sh

_DISPLAY=:69
trap "killall Xephyr" EXIT

Xephyr -ac -screen 800x600 $_DISPLAY &
sleep .2
DISPLAY=$_DISPLAY ./venwm