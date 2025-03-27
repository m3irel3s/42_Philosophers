## 🏛️ **42 Philosophers**
## 🔍 Overview

42 Philosophers is an implementation of the Dining Philosophers Problem, a classical problem in concurrency and synchronization. The problem demonstrates the challenges of resource sharing, deadlock avoidance, and thread synchronization using multiple philosophers who must alternate between eating, sleeping and thinking while sharing limited forks (resources).
The goal is to efficiently manage concurrency, ensuring that all philosophers get a chance to eat without deadlock or starvation.

## 🛠 Features

- Multithreading – Implements parallel execution to simulate multiple philosophers dining simultaneously.
- Mutex & Semaphores – Uses mutexes (for protecting forks) and semaphores (for limiting access) to prevent race conditions.
- Deadlock Prevention – Implements techniques like ordered resource allocation and even/odd philosopher strategies to avoid deadlocks.
- Starvation Prevention – Ensures all philosophers get a chance to eat by managing access timing and prioritization.
- Configurable Parameters – Allows setting the number of philosophers, time to eat, time to think, and time to die through command-line arguments.
- Performance Optimization – Efficiently manages context switching to ensure minimal CPU overhead and smooth execution.

## ⚙️ Functionality

1️⃣ Initialize Philosophers – Creates a number of philosopher threads based on input parameters.

2️⃣ Fork Management – Each philosopher must pick up two forks (mutexes) to eat, ensuring safe access to shared resources.

3️⃣ Thinking, Eating, Sleeping Cycle – Each philosopher continuously:

    Thinks (waiting for forks to be available).

    Eats (grabs forks, eats for a set duration).

    Sleeps (releases forks and waits before thinking again).

4️⃣ Synchronization Mechanism – Uses mutexes to lock forks and prevent multiple philosophers from accessing the same fork simultaneously.

5️⃣ Death Detection – If a philosopher does not eat within a defined time, the simulation detects and reports a dead philosopher.
