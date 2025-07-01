
# SensorMonitor 📡🖥️  
*Qt 6 Widgets dashboard & MQTT sensor simulator*

## Overview
SensorMonitor is a small **desktop laboratory** showing how to :

* simulate temperature / humidity / pressure sensors with random data,
* publish these values to a **Mosquitto** broker (`sensors/#` topics),
* subscribe and display them live in a **Qt 6 Widgets** GUI,
* stay 100 % C++11 – no Qt Mqtt module, only `libmosquittopp`.

<p align="center">
  <img src="docs/screenshots/gui.png" width="480" alt="GUI screenshot">
</p>

---

## Features
| Component            | Tech / API                              | Notes |
|----------------------|-----------------------------------------|-------|
| **Simulator**        | `QCoreApplication`, `QTimer`, `mosquittopp` | Publishes every 2 s, QoS 1, retain flag |
| **Dashboard (GUI)**  | `QMainWindow`, `QLCDNumber`, `QProgressBar` | Auto-updates on message reception |
| **MQTT bridge**      | `MosqQtClient` wrapper                  | Thread-safe: callbacks → Qt signals |

---

## Directory layout

```text
common/     shared headers + MosqQtClient
simulator/  command-line publisher
gui/        Qt Widgets subscriber GUI
docs/       generated Doxygen → html/
build/      (ignored) out-of-tree build
````

---

## Requirements

| Package                   | Debian 12 name                     |
| ------------------------- | ---------------------------------- |
| **Compiler**              | `g++ (>= 12)`                      |
| **Qt 6 Core + Widgets**   | `qt6-base-dev`                     |
| **Mosquitto C++ wrapper** | `libmosquittopp-dev`               |
| **Build tools**           | `cmake (>= 3.19)` + `make`/`ninja` |
| *(optional)* Graphviz     | `graphviz` (for Doxygen graphs)    |

---

## Build & run

```bash
# Clone & build
git clone https://github.com/yourname/SensorMonitor.git
cd SensorMonitor
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release      # -G Ninja if you prefer
cmake --build . -j$(nproc)

# Start broker (service or foreground)
sudo systemctl start mosquitto           # or:  mosquitto -v

# Run simulator & GUI
./simulator/sensor_simulator &
./gui/sensor_gui
```

---

## Documentation

```bash
sudo apt install doxygen graphviz
doxygen                                      # uses Doxyfile at project root
xdg-open docs/html/index.html
```

---

## Contributing

1. Fork, create a feature branch.
2. Follow the **style** (4-space indent, braces on next line, `m_` members).
3. Document new code with Doxygen (`@brief`, `@param`, etc.).
4. Submit a pull-request – happy to review!

---

## License

### MIT License (2025)

```
MIT License

Copyright (c) 2025  SensorMonitor contributors

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
```
