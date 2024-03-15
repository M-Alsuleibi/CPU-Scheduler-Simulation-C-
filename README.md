# CPU Scheduler Simulation

This repository contains a CPU Scheduler Simulation program implemented in C++ using various scheduling algorithms such as First-Come First-Served (FCFS), Shortest Remaining Time (SRT), and Round-Robin (RR).

## Overview

The program reads a list of processes, their arrival times, and CPU bursts from a text file, simulates their execution using the specified scheduling algorithms, and generates various statistics including Gantt chart visualization, finish time, waiting time, turnaround time, and CPU utilization.

## Features

- First-Come First-Served (FCFS) scheduling algorithm
- Shortest Remaining Time (SRT) scheduling algorithm
- Round-Robin (RR) scheduling algorithm with a specified time quantum
- Visualization of Gantt chart illustrating the execution times of the processes

## Usage

To compile and run the project, follow these steps:

1. Open the project folder in Visual Studio Code.

2. Ensure that you have the C++ extension installed.

3. Set up your `tasks.json` file to define build and run tasks.

4. Press `F5` or click on the "Start Debugging" button to compile and run the program in debug mode.

5. Alternatively, you can press `Ctrl+Shift+D` to open the Debug view and select the appropriate configuration before starting debugging.

6. To run the program without debugging, press `Ctrl+F5` or click on the "Start Without Debugging" button.

7. You can also customize the build and run tasks in the `tasks.json` file to suit your specific requirements.

Note: Make sure your `launch.json` file is properly configured to specify the path to your executable and any additional debugging settings.



## Input File Format

The input file for the project will contain the following information:

- **Physical memory size (msize):** The total physical memory size, represented in bytes. It should be a power of 2. Example: 4096 bytes.

- **Page size (psize):** The size of each page or frame, also represented in bytes. It should be a power of 2. Example: 512 bytes.

- **Round Robin Quantum (Q):** The time quantum used for the Round Robin scheduling algorithm. Example: 10.

- **Context Switch (CS):** The time taken for a context switch, in milliseconds. Example: 1.

- **Process Information:** Each process in the input file is represented by the following information:
  - Process ID (PID)
  - Arrival Time (AT)
  - CPU Burst (CPUB)
  - Size in Bytes

**Sample file format processes.txt:**
```
32768
512
  10
  2
0 0 10 2048
1 10 15 2048
2 25  5 2048
3 30 25 2048
4 55 15 2028
 ```

In this sample, the first four lines represent the system parameters (msize, psize, Q, CS), and each subsequent line represents a process with its corresponding PID, AT, CPUB, and Size.
