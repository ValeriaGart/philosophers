# Philosophers

A multithreaded C implementation of the classic Dining Philosophers problem, demonstrating process synchronization, mutexes, and thread management.

## Problem Statement

The Dining Philosophers problem, formulated by Edsger Dijkstra, is a classic example of a concurrency problem:

- N philosophers sit at a round table, each with a bowl of spaghetti and one chopstick to their right.
- There are as many chopsticks as philosophers.
- To eat, a philosopher needs both their own and their neighbor's chopstick.
- Philosophers alternate between thinking, eating, and sleeping.
- If a philosopher does not eat within a set time, they die.
- The simulation ends when a philosopher dies or (optionally) when each has eaten a set number of times.

## Features
- Threaded simulation of philosophers
- Mutex-based chopstick (fork) management
- Configurable timing and philosopher count
- Optional limit on number of times each philosopher must eat
- Detects and reports philosopher death

## How it Works
Each philosopher is a thread. Chopsticks are represented by mutexes. Philosophers attempt to pick up both chopsticks before eating, then sleep and think. The program ensures that no two philosophers use the same chopstick at the same time, preventing race conditions.

## Build Instructions

1. **Clone the repository** (if you haven't already):
   ```sh
   git clone <repo-url>
   cd philosophers/philo
   ```
2. **Build the project:**
   ```sh
   make
   ```
   This will produce an executable named `philo`.

## Run Instructions

```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- All times are in milliseconds.
- The last argument is optional. If omitted, the simulation runs until a philosopher dies.

### Example
```sh
./philo 5 800 200 200
```
This runs the simulation with 5 philosophers, each dying if they don't eat within 800ms, eating for 200ms, and sleeping for 200ms.

## Arguments
| Argument Position | Name                                 | Description                                      |
|-------------------|--------------------------------------|--------------------------------------------------|
| 1                 | number_of_philosophers               | Number of philosophers and chopsticks (>= 2)      |
| 2                 | time_to_die                          | Time (ms) before a philosopher dies without eating|
| 3                 | time_to_eat                          | Time (ms) a philosopher spends eating            |
| 4                 | time_to_sleep                        | Time (ms) a philosopher spends sleeping          |
| 5 (optional)      | number_of_times_each_philosopher_must_eat | Simulation ends when each philosopher has eaten this many times |

## Notes
- If a philosopher dies, the simulation stops and the event is printed.
- If the optional argument is provided, the simulation ends when all philosophers have eaten the required number of times.
- The program uses POSIX threads and mutexes; it should run on any Unix-like system with pthread support.

## License
This project is for educational purposes. Add a license if you wish to share or reuse the code.
