# 📚 RTU Full-Stack C++ Library Management App

An advanced, modern full-stack web application that transforms a core C++ object-oriented backend into a live, interactive web application dashboard using asynchronous network routing. 

---

## 🖥️ Application Dashboard Preview

![RTU Library Dashboard Panel](./dashboard.png)

---

## 🚀 Core Architectural Features
* **Live Asynchronous REST API Engine:** Utilizes modern C++ networking channels to map and handle asynchronous browser requests over TCP sockets.
* **Header-Only Microframework Integration:** Embedded cleanly without bloated build chains, keeping the master repository optimized and production-ready.
* **Modern Material UI Frontend Dashboard:** Formulated with a clean, responsive layout featuring real-time state feedback logs and runtime input dialog processing.
* **Object-Oriented Controller Domain Model:** Uses smart pointers (`std::shared_ptr`) and secure memory mapping (`std::unordered_map`) to safely catalog books and cross-reference active student transaction streams.

---

## 🛠️ Third-Party Dependencies
To preserve professional repository standards, external library code assets are decoupled from this source repository. To run this project locally, ensure you place the following header-only prerequisites into your root folder:
1. **Crow C++ Framework (`crow_all.h`)** — Lightweight, ultra-fast web micro-routing mechanism.
2. **Asio Engine (`asio.hpp`)** — Native low-level platform cross-compilation socket engine.

---

## 💻 Local Quickstart Installation & Build Guide

### 1. Project Directory Architecture
Ensure your local project directory structure matches this standard pattern before executing compilers:
```text
student-library-program/
│
├── crow_all.h               # Required Local Dependency (Ignored by Git)
├── asio.hpp                 # Required Local Dependency (Ignored by Git)
├── main.cpp                 # Main Event Routing Entry Loop
├── index.html               # Frontend Interface Panel Dashboard
├── LibrarySystem.cpp        # Internal System Objects Definitions
├── LibrarySystem.hpp        # Core System Header Schematics
├── LibraryController.cpp    # Map Management Logic Controller
├── LibraryController.hpp    # Data Engine Header Interfacing
└── README.md                # Project Documentation Landing Profile




#### 🔍 Troubleshooting: "g++ is not recognized" Error

If you run the compile command and see a Windows error saying **"The term 'g++' is not recognized as the name of a cmdlet..."**, it means the compiler is installed but Windows doesn't know where to look for it.

### How to Fix It:
1. **Quick Build Path:** Instead of typing `g++`, point directly to your MSYS2 toolchain folder:
   ```powershell
   C:\msys64\ucrt64\bin\g++ -O3 main.cpp -o main.exe -lws2_32