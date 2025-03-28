# GeezaFlick - Open Source Geyser Automation  

## Prototype: GeezaFlick (a.k.a. GeyserFlick)  
GeezaFlick is a **home automation prototype** designed for DIY enthusiasts who want to **remotely control their geyser**, like myself. It leverages **ESP32, Arduino UNO and an MG90S/MG996R servo** to physically flick a switch, enabling users to turn their geyser on or off from anywhere. The system is integrated with **Google Firebase** for cloud-based control.  

### ⚠ Status: **Intermediary Design Phase**  
This is an early-stage prototype, open-source for anyone who wants to **build and improve upon it**. The design is subject to change as optimisations are made.  

---

## Hardware Components  
- **ESP32** – Handles WiFi and Firebase communication  
- **Arduino UNO** – Provides stable 5V power and acts as an intermediary controller  
- **MG90S / MG996R Servo** – Flicks the geyser switch  
- **3D-Printed Servo Mount** – Holds the servo in place on the DB board (see [`/3D_models/`](./3D_models/))  
- **Double-sided Tape** – Used for mounting  

---

## Cloud Integration (Google Firebase)  
The system syncs with **Google Firebase** to remotely control the geyser switch.  
- **Firebase Realtime Database** stores the ON/OFF state  
- **ESP32 reads/writes switch states to Firebase**  
- **Arduino listens for state changes and triggers the servo**  

**[Firebase Database Link](https://console.firebase.google.com/u/0/project/geezaflick/database/geezaflick-default-rtdb/data)**  

---

## Why GeezaFlick?  
This project was born out of personal necessity. **As a student spending late nights on campus, I constantly faced the dilemma**:  
- Should I **leave early to turn on the geyser** and wait an hour for it to heat?  
- Or **thug it out** stay late and sacrifice sleep, waiting for the geyser to heat up when I got home at midnight?  

GeezaFlick was my solution. **I saw a gap in the market and there is potential**. For now, it's an **open-source project, from me to you**.  

---

## 📜 License  
This project is open-source under the **MIT License** – free to use, modify and share!  
