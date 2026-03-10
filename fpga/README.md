# Resources for FPGA Development

This folder contains (1) how-to guides and (2) code samples for FPGAs the IDEAs
Clinic owns.

_This documentation up-to-date as of March 10, 2026_

The boards are:

1. The Cyclone V GX Evaluation board
2. The DE-10 Lite Board

## What is a FPGA?

A FPGA (field-programmable gate array) is a digital circuit (think NAND gates)
formed from a grid of LookUp Tables (LUTs) connected to each other through
configurable switches (a _routing network_). The routing network is configurable
such that every LookUp Table may connect to every other lookup table, and the
lookup table itself maps a set of $k$ input bits to 1 output bit.

For instance:

```
0,0 -> 0
0,1 -> 0
1,0 -> 0
1,1 -> 1
```

As a 2-bit input lookup table would be the equivalent of a "AND" gate.
As they enumerate all the possible outputs from the input states it is easy to
see that with enough LookUp Tables and with no timing constraint, any digital
circuit (classical computer) may be implemented using a FPGA configured in this
way. 

## Sample Workflow for Your Consideration

### Is the FPGA the right tool for the job?

We are given a problem to solve.
To apply FPGAs to solving this problem, we should first determine if it truly
is the right tool for the job. To do this, we create a prototype using an FPGA,
which demonstrates that an FPGA is most well-suited for a particular part of
the problem, that which is the most important or unique distinguishing part.

Here are some properties of FPGAs to keep in mind:

1. FPGAs are great for prototyping digital circuits  


