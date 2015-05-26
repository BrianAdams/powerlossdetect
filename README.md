# powerlossdetect

This project is a proof of concept for detecting a signal that power is about to fail and then using an interrupt to do a safe emergency shutdown of the O/S within 100ms.

The was built with the Debian O/S

The electrical circuit is a timed circuit. When the 5V is pulled from the tether line, this circuit immediately takes one of the pins on the beaglebone high.  The circuit then keeps the actual power up for > 100ms.

The DP-gpio-set device has not been tested yet.  It is intended to remove the pull down from the pin.

To test:

```
sudo bash setup.sh
sudo node powerdown
```

The blink.js cycles another pin a 1ms so that you can stick in on an oscope and use it to detect when the O/S has stopped. 
