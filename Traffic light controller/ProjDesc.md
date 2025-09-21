# Traffic Light Controller for Emergency Vehicles
## ESP32 + IoT Project

### Project Overview
Developed an intelligent traffic light controller using an ESP32 microcontroller with IoT integration via the Blynk platform. The system executes a standard traffic light cycle under normal conditions, but when an emergency vehicle approaches, the controller can be overridden remotely through a mobile app command. The selected lane switches to green for 30 seconds with a 5-second buffer period, before automatically resuming normal traffic flow.

### Key Features
- **Standard Traffic Light Cycle** - Normal operation with timed red, yellow, and green phases
- **Emergency Override** - Remote control via mobile app for emergency vehicles
- **Intelligent Timing** - 30-second green phase with 5-second buffer for emergency priority
- **IoT Integration** - Real-time control through Blynk platform
- **Automatic Recovery** - Returns to normal cycle after emergency period
- **Wi-Fi Connectivity** - Wireless communication for remote control

### Hardware Components
- **ESP32 Microcontroller** - Main processing unit with Wi-Fi capability
- **LED Traffic Lights** - Red, yellow, and green LEDs for each direction
- **GPIO Control** - Direct LED control through GPIO pins
- **Wi-Fi Module** - Built-in ESP32 Wi-Fi for IoT connectivity

### Technologies Used
- ESP32
- Embedded C (Arduino framework)
- Blynk IoT platform
- Wi-Fi communication
- FSM logic
- GPIO control (LEDs)

### Technical Implementation
- **Finite State Machine** - Structured traffic light cycle logic
- **IoT Integration** - Blynk platform for mobile app control
- **Emergency Override** - Remote command processing and execution
- **Timing Control** - Precise timing for normal and emergency modes
- **Wi-Fi Communication** - Real-time data exchange with mobile app

### Demo Video
Watch the project demonstration: [Emergency Traffic Light Signal Demo](https://photos.app.goo.gl/HKu5qLT3mTzJa7Dz6)

### Applications
- Emergency vehicle priority systems
- Smart city traffic management
- IoT-based traffic control
- Emergency response infrastructure
