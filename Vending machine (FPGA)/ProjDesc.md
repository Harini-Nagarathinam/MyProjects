# Vending Machine Controller
## FPGA + Verilog Project

**Note:** This was a group project. The codes included in this repository represent my contribution to the project.

### Project Overview
Designed and implemented a vending machine controller using finite state machine (FSM) logic in Verilog HDL, targeting FPGA deployment. The system handled coin input, product selection, and output control, with real-time feedback via a seven-segment display. Developed multiple testbenches (including for the vending machine logic, seven-segment controller, and top module) to verify functionality and validate state transitions before synthesis.

### Key Features
- **Finite State Machine Design** - Structured control logic for vending operations
- **Coin Input Processing** - Handles various coin denominations and validation
- **Product Selection** - User interface for product choice and availability checking
- **Output Control** - Manages product dispensing and change calculation
- **Real-time Display** - Seven-segment display for user feedback and status
- **Comprehensive Testing** - Multiple testbenches for thorough verification

### Hardware Components
- **FPGA Development Board** - Target platform for implementation
- **Seven-Segment Display** - User interface and status display
- **Input Switches** - Coin input and product selection
- **Output Indicators** - Product dispensing and system status

### Technologies Used
- Verilog HDL
- FSM design
- FPGA development
- Testbench-based verification
- ModelSim/Quartus Prime

### Technical Implementation
- **State Machine Logic** - Verilog-based FSM for vending machine control
- **Coin Processing** - Input validation and accumulation logic
- **Product Management** - Inventory tracking and selection logic
- **Display Controller** - Seven-segment display driver implementation
- **Testbench Development** - Comprehensive verification suite

### Project Files
- `seven_segment_display_controller.v` - Display controller module
- `SSDController_tb.v` - Seven-segment display testbench
- `TopModule_tb.v` - Top-level module testbench
- `VendingMachin_tb.v` - Main vending machine testbench

### Applications
- Automated vending systems
- FPGA-based embedded controllers
- Digital system design education
- State machine implementation examples
