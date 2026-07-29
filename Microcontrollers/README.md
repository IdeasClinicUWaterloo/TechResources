# Microcontrollers

**Table of Contents:**

1. [Introduction](#Introduction)
2. [Using PlatformIO](#Using-PlatformIO)
3. [Arduino Setup Guide](./Arduino/README.md)
4. [Sensors Guide](./Sensors/README.md)

## Introduction

A microcontroller unit (MCU) is any small computer on a single integrated circuit (IC).

A MCU begins with a general-purpose CPU which accepts instructions encoded into binary and sequentially evaluates them to produce outputs.
These outputs go through layers of input-output devices, arranged like onion rings around the CPU, first on the same silicon die, then moving onto other discrete components on the board, which gradually increase the CPU's ability to interact with the outside world.

TBD: flowchart: ic to pcb to outside world

When we pick a MCU for a project, the first thing we consider is how it may be integrated into the wider system.
What is its purpose?
To do so, we consider the final outputs provided by the MCU as documented in its datasheet.
These usually take the form of general pins, input-output (GPIOs) and hard "ports" mounted on the board like USB-C and gigabit Ethernet.

## Using PlatformIO

PlatformIO is a Visual Studio Code extension which automatically downloads libraries from MCU vendors like STM and Arduino.
More than this, it provides a build tool, [PlatformIO Core](https://docs.platformio.org/en/latest/core/index.html), which does two very important things:

1. Assigns each [board it supports](https://registry.platformio.org/search?t=platform) a single name so that it can track what needs to be downloaded to support that board.
2. Configures your project with a single source of truth, `platformio.ini`, which specifies your project's complete build process for its build tool.

This means that to collaborate with other people on your project, each person having PlatformIO IDE installed and sharing your project folder is enough for everyone's builds to work.

### Installing PlatformIO

1. Install Visual Studio Code using the instructions here
2. Install PlatformIO using [the PlatformIO installation instructions](https://platformio.org/install/ide?install=vscode)
