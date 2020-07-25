# Ksipna

A small keyfob to wake up a sleeping laptop - useful on external monitor setups
where the laptop lid is closed and you need to wake up the laptop without
opening the lid.

It sends a single character (currently `[` as it's broken on my keyboard) and
waits 1 second until another event can be triggered.

The device is a "Rubber Ducky" with a male USB A and nothing else. I'm abusing the
analog input to go low when touched and be kind high when not (I'm using `A0`).
It's not a perfect mechanism, but it's a nice hack. You don't have to solder
anything and you can touch it from both sides (heh - *wink*) in case of a
reversed USB port.

I won't go into BOM details as you just need [this](https://www.diymore.cc/products/diymore-beetle-badusb-micro-atmega32u4-au-development-expansion-module-board-for-arduino-leonardo-r3-5v-i2c).
It's an "Arduino Leonardo" - aka an ATMega32U4 on a breakout board.

I'm sure this will work on DigiSpark-like boards, you just have to change the
keyboard handling function but I couldn't get my DigiSpark to work (they're
ATTiny85 with a software USB implementation).

`pio run --target=upload` to flash it on your board and you're set!

**NOTE**: The laptop should power the USB device while asleep or you
have to use an externaly powered USB home for this setup to work

Have fun!
