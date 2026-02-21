# 🐭 Micro Mouse Robot – NRC Project

This repository contains the design files, firmware, and documentation for a **Micro Mouse robot** developed for **NRC competition standards**. The robot was designed to fit within a maximum size constraint of **7 × 7 × 7 cm** and uses multiple sensors for wall detection, motion tracking, and stability.

---

## 📌 Project Overview

The Micro Mouse robot integrates **mechanical design**, **embedded systems**, and **sensor-based navigation**. It uses Time-of-Flight sensors for wall detection, encoders for motion feedback, and an IMU for orientation correction during movement in a maze environment.

---

## 🛠️ Mechanical Design

- Custom chassis designed using **Fusion 360**
- Chassis fabricated via **3D printing using Bambu Studio**
- Compact, lightweight structure optimized for NRC size constraints

---

## ⚙️ Hardware Components

- 🧠 Arduino Microcontroller  
- 📏 VL53L4CD Time-of-Flight (ToF) sensors  
- 🔌 Motor driver  
- ⚙️ DC motors with wheel encoders  
- 🧭 IMU (Inertial Measurement Unit)  
- 🔋 Battery and power management  

---

## 💻 Software

- Custom Arduino firmware for:
  - Motor control
  - Sensor integration
  - Wall alert detection
- Dedicated code for VL53L4CD ToF sensors
- Encoder and IMU feedback used for improved motion accuracy and correction

---

## 📚 Libraries Used

- `Arduino.h` – Core Arduino functions  
- `Wire.h` – I2C communication  
- `VL53L4CD.h` – Time-of-Flight sensor library  
- `Encoder.h` – Wheel encoder handling  
- `DFRobot_I2C_Multiplexer.h` – DFRobot I2C multiplexer library   

---

## 📋 Features

- 🚧 Real-time wall detection  
- 📐 Encoder-based motion tracking  
- 🧭 IMU-assisted orientation stabilization  
- 🖨️ Fully custom 3D-printed chassis  
- 📏 Competition-compliant micro-size design  

---

## 📦 Hardware Requirements

- Arduino-compatible microcontroller  
- VL53L4CD ToF sensors  
- DC motors with encoders  
- Motor driver module  
- IMU sensor  
- Battery, wiring, and connectors  
- 3D-printed chassis  

---

## 🖥️ Software Requirements

- Arduino IDE  
- Required Arduino libraries (listed above)  
- Fusion 360 (for CAD modifications)  
- Bambu Studio (for 3D printing)  

---

## 🚀 Future Improvements

- Implement maze-solving algorithms (e.g., Flood Fill)  
- Improve PID tuning for smoother motion  
- Optimize sensor placement for better accuracy  
- Add wireless debugging or telemetry  

---

## 🙏 Acknowledgements

- NRC organizers for competition guidelines and inspiration  
- Arduino open-source community  
- Sensor and library developers for documentation and support  
- Team members and mentors who contributed to design and testing  

---

## ✍️ Authors

Developed as part of an **NRC Micro Mouse Project**.
