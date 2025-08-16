# 📟 AVR Keypad & LCD Number Entry System  

This project demonstrates how to use an **ATmega32 microcontroller**, a **4x4 keypad**, and an **LCD display** to enter and validate numbers.  

The user is prompted to enter a number using the keypad. When the **`#`** key is pressed:  
- If the number entered is **11 digits** and starts with **"01"** → it is accepted and marked as **Saved**.  
- Otherwise → it shows **Invalid**.  

---

## ⚡ Features  
- LCD initialization and message display  
- Keypad scanning and number input handling  
- Validation of phone number format (11 digits, starting with "01")  
- Displays **Saved** or **Invalid** feedback  
- Automatically clears the LCD after validation  

---

## 🛠 Hardware Requirements  
- ATmega32 (or similar AVR microcontroller)  
- 16x2 LCD display  
- 4x4 Keypad  
- Resistors, wires, and breadboard (for connections)  
- Power supply (5V recommended)  

---

## 🔧 Software Requirements  
- **AVR-GCC** compiler  
- **AVRDUDE** (for flashing the MCU)  
- Any AVR IDE (e.g., Atmel Studio, PlatformIO, or VS Code with AVR plugin)  

---

## 🚀 How It Works  
1. The LCD displays:  
2. The user enters digits from the keypad.  
3. Press **`#`** to submit.  
- If the number = `11 digits` and starts with `"01"` → LCD shows **Saved**.  
- Otherwise → LCD shows **Invalid**.  
4. LCD clears and waits for the next input. 



## 📂 Project Structure  
├── main.c # Main program
├── LCD.h / LCD.c # LCD driver
├── KeyPad.h / KeyPad.c # Keypad driver
└── README.md # Documentation




## 🔮 Future Improvements  
- Support for backspace (`*` key).  
- Store multiple valid numbers in EEPROM.  
- Add buzzer feedback for keypresses.  
- Extend to act as a **mini phonebook system**.
