# 8051-Based Traffic Signal Control System

A four-road traffic signal controller simulated using an **AT89C51
(8051) microcontroller**, **Embedded C**, **Keil µVision**, and
**Proteus**. Five push buttons are used as input commands to select a
road or activate emergency mode.

> **Important:** In this prototype, push buttons simulate the gesture
> commands. It does not perform camera-based or computer-vision gesture
> recognition.

## Project Overview

The controller operates traffic lights for four directions:

-   North
-   South
-   East
-   West

When a direction button is pressed, that direction is set to green and
the other three directions are set to red. The fifth button activates
emergency mode, in which all four directions are set to red.

## Hardware / Simulation Components

-   AT89C51 8051 microcontroller
-   12 LEDs representing four traffic signals (red, yellow, and green
    per direction)
-   Five push buttons
-   330 Ω LED current-limiting resistors
-   Crystal oscillator and two 33 pF capacitors
-   Reset circuit with a 10 kΩ resistor
-   Proteus schematic and simulation
-   Keil µVision with the `REGX51.H` header

## Input Mapping

  Button   Input pin   Function
  -------- ----------- ------------------------------------
  B1       P3.0        North green; other directions red
  B2       P3.1        South green; other directions red
  B3       P3.2        East green; other directions red
  B4       P3.3        West green; other directions red
  B5       P3.4        Emergency mode: all directions red

The buttons are read as active-low inputs in the supplied code
(`if (B1 == 0)`, etc.).

## Output Pin Mapping

  Direction   Red LED   Yellow LED   Green LED
  ----------- --------- ------------ -----------
  North       P1.0      P1.1         P1.2
  South       P1.3      P1.4         P1.5
  East        P2.0      P2.1         P2.2
  West        P2.3      P2.4         P2.5

## Circuit Diagram

![Proteus circuit diagram](assets/circuit-diagram.png)

## Simulation Results

The following screenshots were captured from the Proteus simulation.
They show example states as the input buttons are activated.

  Simulation result   Screenshot
  ------------------- ----------------------------------------------
  Result 1            ![Simulation result 1](assets/result-01.png)
  Result 2            ![Simulation result 2](assets/result-02.png)
  Result 3            ![Simulation result 3](assets/result-03.png)
  Result 4            ![Simulation result 4](assets/result-04.png)
  Result 5            ![Simulation result 5](assets/result-05.png)

## Software Used

-   **Keil µVision** --- writing and compiling the 8051 Embedded C
    program
-   **Proteus 8 Professional** --- circuit design and simulation

## How It Works

1.  The microcontroller initializes ports P1, P2, and P3.
2.  The system starts in all-red mode.
3.  The program continuously checks buttons B1--B5.
4.  Pressing B1--B4 selects the corresponding direction.
5.  Pressing B5 turns all four directions red.

## Repository Structure

``` text
8051-Traffic-Signal-Control-System/
├── README.md
├── src/
│   └── traffic_control.c
├── assets/
│   ├── circuit-diagram.png
│   ├── result-01.png
│   ├── result-02.png
│   ├── result-03.png
│   ├── result-04.png
│   └── result-05.png
├── simulation/
│   └── (add the Proteus project files here)
└── docs/
    └── (add the project report PDF here, if approved for public sharing)
```

## Current Limitations

-   Push buttons are used to represent gesture commands; no camera or
    gesture-recognition algorithm is implemented.
-   The supplied program switches directly between signal states.
    Yellow-light timing and interlocking delays are not implemented in
    the current code.
-   This is a Proteus simulation. Do not describe it as a physically
    built or field-tested traffic system unless hardware testing has
    actually been completed.
-   This educational prototype is not intended for real-road traffic
    control.

## Possible Future Improvements

-   Add timed yellow transitions and a safe all-red interval between
    directions.
-   Add a real gesture-recognition input module and clearly document its
    interface.
-   Test the controller on physical hardware.
-   Add simulation video and compiler/build instructions.

## Author / Contributors

Add the actual author and team member names here, and confirm that
everyone agrees before publishing their names or the full report.

## License

No license has been selected yet. Until a license is added, others
should not assume they have permission to reuse or redistribute this
repository's code or documents.
