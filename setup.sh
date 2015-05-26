#!/bin/sh

echo 49 > /sys/class/gpio/export
echo both > /sys/class/gpio/gpio49/edge

echo 48 > /sys/class/gpio/export
echo out > /sys/class/gpio/gpio48/direction
