# Microcontrollers

**Table of Contents:**

1. [Introduction](#Introduction)
2. [Using PlatformIO](#Using-PlatformIO)

## Introduction

A microcontroller unit (MCU) is any small computer on a single integrated circuit (IC).

A MCU begins with a general-purpose CPU which accepts instructions encoded into binary and sequentially evaluates them to produce outputs.
These outputs go through layers of input-output devices, arranged like onion rings around the CPU, first on the same silicon die, then moving onto other discrete components on the board, which gradually increase the CPU's ability to interact with the outside world.

TBD: flowchart: ic to pcb to outside world

When we pick a MCU for a project, the first thing we consider is how it may be integrated into the wider system.
What is its purpose?
To do so, we consider the final outputs provided by the MCU as documented in its datasheet.
These usually take the form of general pins, input-output (GPIOs) and hard "ports" mounted on the board like USB-C and gigabit Ethernet.
