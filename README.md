## 🏛️ **42 Philosophers**
![image](https://github.com/user-attachments/assets/fee737d1-8ca7-4496-b11b-7848ea14ab60)

## 🔍 Overview

42 Philosophers is an implementation of the Dining Philosophers Problem, a classical problem in concurrency and synchronization. The problem demonstrates the challenges of resource sharing, deadlock avoidance, and thread synchronization using multiple philosophers who must alternate between eating, sleeping and thinking while sharing limited forks (resources).
The goal is to efficiently manage concurrency, ensuring that all philosophers get a chance to eat without deadlock or starvation.

## 🛠 Features

- Multithreading – Implements parallel execution to simulate multiple philosophers dining simultaneously.
- Mutex – Uses mutexes (for protecting forks) to prevent race conditions.
- Deadlock Prevention – Implements techniques like ordered resource allocation and even/odd philosopher strategies to avoid deadlocks.
- Starvation Prevention – Ensures all philosophers get a chance to eat by managing access timing and prioritization.
- Configurable Parameters – Allows setting the number of philosophers, time to eat, time to think, and time to die through command-line arguments.
- Performance Optimization – Efficiently manages context switching to ensure minimal CPU overhead and smooth execution.

## ⚙️ Functionality

- Initialize Philosophers – Creates a number of philosopher threads based on input parameters.
- Fork Management – Each philosopher must pick up two forks (mutexes) to eat, ensuring safe access to shared resources.
- Thinking, Eating, Sleeping Cycle
- Synchronization Mechanism – Uses mutexes to lock forks and prevent multiple philosophers from accessing the same fork simultaneously.
- Death Detection – If a philosopher does not eat within a defined time, the simulation detects and reports a dead philosopher.
