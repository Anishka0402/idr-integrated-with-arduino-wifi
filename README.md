# IDR (LDR) Integrated with Arduino + WiFi

A minimal Arduino project that reads a Light-Dependent Resistor (LDR) on analog pin A0 and prints the raw value and a mapped light percentage to the serial console. The repository is organized for use with PlatformIO (the project already contains a `platformio.ini`).

## Features

- Read LDR value from analog pin A0
- Map raw ADC value (0–1023) to a user-friendly light percentage
- Print raw value and percentage over serial at 9600 baud

## Hardware Required

- Arduino-compatible board (Uno, Nano, ESP8266, ESP32, etc.)
- LDR (photoresistor)
- Fixed resistor for voltage divider (10 kΩ recommended)
- Breadboard and jumper wires

## Wiring

Use a voltage divider: one leg of the LDR to 5V (or 3.3V for 3.3V boards), the other leg to the analog pin (A0). Place the fixed resistor between the analog pin and GND.

Typical wiring (text diagram):

- 5V (or 3.3V) -> LDR -> A0 -> 10kΩ resistor -> GND

This produces an analog voltage at A0 which varies with light. If using an ESP32/ESP8266, use the board's ADC input and 3.3V.

## Software / Build

This project is prepared for PlatformIO. You can open this folder in VS Code with the PlatformIO extension, or use the PlatformIO CLI.

PlatformIO (VS Code):
- Install PlatformIO extension
- Open this project folder
- Connect your board and choose the correct environment (if multiple in `platformio.ini`)
- Click Upload

PlatformIO CLI example (run from project root):

```powershell
# Build and upload (PlatformIO must be installed)
platformio run -t upload

# To open a serial monitor at 9600 baud (change port as needed)
platformio device monitor --baud 9600
```

If you prefer the Arduino IDE: open `src/main.cpp` in the Arduino IDE, select the board and port, and upload.

## Usage

1. Upload the firmware to your board.
2. Open the Serial Monitor (9600 baud).
3. You should see output similar to:

```
LDR value: 600
Light percentage: 41%
```

(Values will vary depending on wiring, resistor, and ambient light.)

## Code notes

- The main code lives in `src/main.cpp` and uses `analogRead(A0)` to read the sensor.
- The sketch maps the ADC range 0–1023 to 100–0 (so 0 = dark -> 100%, 1023 = bright -> 0%). Adjust mapping if you prefer the opposite direction or different scaling.
- Consider adding smoothing (moving average), calibration, or using non-blocking timing if you extend the project to use WiFi or other sensors.

## Calibration tips

- Swap the map() arguments if you want 0% to mean dark and 100% bright: map(ldrValue, 0, 1023, 0, 100)
- If readings are noisy, add a small capacitor (0.1uF) across the LDR or implement software averaging.

## Troubleshooting

- No serial output: check the correct Serial port and baud rate (9600). Verify USB cable/data connection.
- Constant values: check wiring and resistor values. Make sure the analog pin is connected to the divider midpoint.
- Values out of expected range: verify board voltage (5V vs 3.3V) and adjust resistor value.

## Contributing

Small fixes and improvements are welcome. Please open an issue or a pull request with a clear description of changes.

## License

This project is provided under the MIT License. See `LICENSE` if included, or add one if you intend to share or reuse this code.

## Acknowledgements

Simple educational example created to demonstrate reading an LDR with Arduino/PlatformIO.
