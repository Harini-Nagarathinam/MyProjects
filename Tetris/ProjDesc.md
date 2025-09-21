# Tetris Game with Audio Integration
## ARM Cortex-A9 on DE1-SoC

**Note:** This was a group project. The codes included in this repository represent my contribution to the project.

### Project Overview
Implemented a Tetris game on the ARM Cortex-A9 processor within the DE1-SoC development board. Designed the game logic using finite state machines for block generation, movement, rotation, collision detection, line clearing, and scoring. Developed an audio subsystem in C to provide background music and event-based effects (start, pause, score, game over), interfaced with the WM8731 audio codec via I²C. Integrated user input through push buttons and switches, displayed graphics on the LT24 TFT module, and managed score output using the seven-segment display.

### Key Features
- **Complete Tetris Game Logic** - Block generation, movement, rotation, and collision detection
- **Audio Integration** - Background music and event-based sound effects
- **Visual Display** - Graphics rendered on LT24 TFT module
- **User Interface** - Push buttons and switches for game control
- **Score Management** - Seven-segment display for score output
- **Finite State Machine Design** - Structured game logic implementation

### Hardware Components
- **ARM Cortex-A9 Processor** - Main processing unit on DE1-SoC board
- **LT24 TFT Module** - Graphics display
- **WM8731 Audio Codec** - Audio processing and output
- **Seven-Segment Display** - Score display
- **Push Buttons & Switches** - User input interface

### Technologies Used
- ARM Cortex-A9 (DE1-SoC)
- Embedded C
- FSM design
- LT24 TFT display
- WM8731 audio codec
- I²C communication
- GPIO interfacing
- Seven-Segment Display

### Technical Implementation
- **Game Logic** - Finite state machines for all game mechanics
- **Audio Subsystem** - C-based audio processing with I²C interface

