# Dynamic I2C LCD Text Streaming Engine 🚀

A real-time embedded system built using Arduino and I2C LCD to stream and display dynamic scrolling text with precise timing control.

This project focuses on creating a smooth UI/UX-like experience on a low-resource embedded system by implementing custom text scrolling logic and optimized I2C communication.

---

## 📌 Features

- Real-time text streaming on 16x2 LCD
- Smooth scrolling algorithm for long strings
- I2C communication (only 2 wires: SDA & SCL)
- Optimized refresh timing for stable output (~380ms delay tuning)
- Lightweight firmware design for Arduino platforms

---

## 🛠️ Hardware Requirements

- Arduino UNO / Nano / Mega
- 16x2 LCD Display
- I2C Module (PCF8574 or equivalent)
- Jumper wires
- Power supply (5V)

---

## 💻 Software Requirements

- Arduino IDE
- LiquidCrystal_I2C library
- Wire library

---

## ⚙️ Working Principle

The system splits long text strings into dynamic substrings using index shifting. These substrings are updated in a timed loop, creating a smooth scrolling effect across the LCD screen.

The I2C module reduces pin usage and simplifies hardware wiring, making the system efficient and scalable.

---

## 🔧 Core Logic (Simplified)

```cpp
for (int i = 0; i < textLength; i++) {
    lcd.setCursor(0, 1);
    lcd.print(text.substring(i, i + 16));
    delay(380);
}
