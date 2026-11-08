# DoubleLcd
I connected two LCD displays, but I tried to use fewer pins.

## What I learned

LCD pins:
- VSS is GND, VDD is +5 V (the order is easy to mix up, especially when moving from Tinkercad, where it is mirrored)
- V0 sets the contrast: the potentiometer works as a voltage divider
- RS: 0 is a command, 1 is a character
- RW: 0 is write, 1 is read. The library only writes, so RW goes to GND
- E is the "read now" pulse, data is captured on its falling edge
- D0–D3 are not used: in 4-bit mode a byte is sent in two halves over D4–D7. This saves 4 pins
- A and K are the backlight, its power is separate, so it doesn't prove that the controller works

Two displays on one data bus:
- Shared: RS, D4–D7, VCC, GND
- Each display has its own E, and it decides who "listens"
- The displays don't talk to each other, only the Arduino is in control

Custom characters:
- A character is a 5×8 pixel grid, which means 8 bytes
- `createChar` gives 8 slots per display, and they are displayed with `write(byte(n))`

Analog In as digital:
- On the Arduino Uno, pins A0–A5 are general-purpose pins that can also work as digital ones
Be more careful with the wires when connecting, because I mixed up a lot of things

<img width="960" height="1280" alt="image" src="https://github.com/user-attachments/assets/acc6661c-078b-45a5-9933-ba6824795c5a" />
<img width="960" height="1280" alt="image" src="https://github.com/user-attachments/assets/204cc426-ead9-4042-be81-687b07035c50" />
<img width="960" height="1280" alt="image" src="https://github.com/user-attachments/assets/058c19d4-b471-4bc5-a87c-66b5d363d1f5" />
<img width="960" height="1280" alt="image" src="https://github.com/user-attachments/assets/8fec9ee0-d873-4867-8900-fa42555b8a69" />
<img width="960" height="1280" alt="image" src="https://github.com/user-attachments/assets/bb4b3b0b-b378-4b99-acae-8048ba8eadb8" />
