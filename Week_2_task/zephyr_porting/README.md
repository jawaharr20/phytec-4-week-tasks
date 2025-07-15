# Zephyr Porting on BGM220P

This project documents my journey of porting the Zephyr RTOS to the **BGM220P** board from Silicon Labs. The base reference was taken from the **SLTB010A** (official Silabs dev board) Zephyr support. The goal was to bring up basic Zephyr functionality on BGM220P and later extend to BLE stack integration.


---

## 📦 Repo Structure

    Week_2_task/
     └── zephyr_porting/
     ├── boards/ # Custom BGM220P board definition
     ├── dts/ # Device Tree files for BGM220P
     ├── drivers/ # (Optional) Any custom drivers added
     ├── samples/
     │ └── blinky/
     └── CMakeLists.txt, Kconfig, etc.

---

## 🧠 What I Did

### ✅ Board Bring-Up
- **Reference Board**: `sltb010a` (from official Zephyr and Silabs support)
- **Target Board**: `BGM220P`
- Ported necessary DTS (Device Tree Source), pinctrl, and Kconfig files to define the board.
- Set up the board folder under `boards/arm/`.

### ✅ Basic Applications
- **Hello World**: Verified console output over UART.
- **LED Blinky**: Verified GPIO pin toggle (adapted to BGM220P pin mapping).

### 🚧 Next Steps (WIP)
- BLE stack integration (controller + host stack setup)
- GATT server sample
- Power management optimization

---

## 🔧 Tools Used

- **Zephyr SDK**
- **west** (Zephyr meta-tool for managing repos and builds)
---

## 🧭 How to Build & Flash

Make sure west is initialized and Zephyr SDK is set up.

          west build -b sltb010a --pristine

run this in the zephyrproject/zephyr 

<img width="1920" height="1080" alt="Screenshot from 2025-07-15 17-00-16" src="https://github.com/user-attachments/assets/7ae48633-68f1-445d-bd53-900c6777026b" />


# Flash the binary (adjust to your flashing tool)
           west flash

 # Notes         
BGM220P is not officially supported in upstream Zephyr, so board support is manually added.

LED and UART pins were mapped manually using BGM220P datasheet + schematic.
