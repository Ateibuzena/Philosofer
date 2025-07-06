# 🍽️ Philosophers - Advanced Concurrent Programming

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://42.fr/)
[![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Threads](https://img.shields.io/badge/Threads-Concurrent-green?style=flat)](#)
[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

> *"One cannot think well, love well, sleep well, if one has not dined well."* - Virginia Woolf

A sophisticated implementation of the classic **Dining Philosophers Problem** featuring advanced threading, precise timing, adaptive monitoring, and elegant deadlock prevention.

## 🧠 The Problem

The Dining Philosophers Problem is a classical synchronization problem in computer science, designed to illustrate the challenges of avoiding deadlock and resource starvation in concurrent programming.

**The scenario:** Five philosophers sit around a circular table with a bowl of spaghetti. Between each pair of philosophers lies a single fork. Each philosopher alternates between thinking and eating, but needs **both adjacent forks** to eat.

## ✨ Features

### 🚀 **Core Implementation**
- **Multi-threaded simulation** with precise pthread management
- **Deadlock prevention** using intelligent fork ordering
- **Race condition elimination** with strategic mutex placement
- **Adaptive timing system** with proportional delays
- **Memory-safe operations** with comprehensive cleanup

### 🎯 **Advanced Optimizations**
- **Dynamic monitoring frequency** based on death timer
- **Proportional thinking time** for odd-numbered philosophers
- **Intelligent sleep intervals** with adaptive precision
- **Real-time death detection** with microsecond accuracy
- **Colorized output** for enhanced visualization

### 🛡️ **Robust Error Handling**
- **Comprehensive input validation** with detailed error messages
- **Resource allocation checking** with proper error recovery
- **Thread creation monitoring** with cleanup on failure
- **Graceful termination** handling for all edge cases

## 🏗️ Architecture

```
📦 Philosofer/
├── 📁 src/
│   ├── 🧠 philo_lifecycle.c    # Core philosopher behavior
│   ├── 👁️ philo_monitor.c      # Death detection & meal counting
│   ├── 🧵 philo_threads.c      # Thread management
│   ├── ⚙️ philo_init.c         # Environment initialization
│   ├── 🧹 philo_clean.c        # Memory cleanup
│   ├── 🛠️ philo_utils.c        # Utilities & timing
│   ├── 🖨️ philo_prints.c       # Debug output functions
│   ├── � ft_atoi.c           # String to integer conversion
│   └── 📝 ft_strtol.c         # Advanced string parsing
├── 📋 philoft.h               # Header with all definitions
├── ⚡ Makefile                # Optimized build system
├── 🍽️ philo                   # Compiled executable
└── 📖 README.md              # This file
└── main.c
```

## 🛠️ Requirements

- **Compiler:** GCC with C99 standard support
- **OS:** Unix-like system (Linux, macOS)
- **Libraries:** pthread, standard C library
- **Build tool:** GNU Make

## 🚀 Quick Start

### 1. Clone & Build
```bash
git clone https://github.com/yourusername/Philosofer.git
cd Philosopher
make
```

### 2. Run Simulation
```bash
./philo <philosophers> <die_time> <eat_time> <sleep_time> [meal_limit]
```

**Parameters:**
- `philosophers`: Number of philosophers (1-200)
- `die_time`: Time in ms before a philosopher dies without eating
- `eat_time`: Time in ms a philosopher spends eating
- `sleep_time`: Time in ms a philosopher spends sleeping
- `meal_limit`: *(optional)* Number of meals before simulation ends

### 3. Example Scenarios

```bash
# Classic 5 philosophers
./philo 5 800 200 200

# Single philosopher (will die - impossible scenario)
./philo 1 800 200 200

# Limited meals scenario
./philo 4 410 200 200 3

# Stress test
./philo 200 800 200 200
```

## 🎨 Sample Output

```
0 2 has taken a fork
0 2 has taken a fork
0 2 is eating
0 4 has taken a fork
0 4 has taken a fork
0 4 is eating
200 2 is sleeping
200 4 is sleeping
200 1 has taken a fork
200 1 has taken a fork
200 1 is eating
...
```

*Each line shows: `[timestamp] [philosopher_id] [action]` with color coding for easy visualization.*

## 🧬 Technical Deep Dive

### 🔒 **Deadlock Prevention Strategy**
```c
// Even philosophers: left fork first, then right
// Odd philosophers: right fork first, then left
if (philo->id % 2 == 0) {
    first = left_fork;
    second = right_fork;
} else {
    first = right_fork;
    second = left_fork;
}
```

### ⏱️ **Adaptive Timing System**
```c
// Dynamic monitoring frequency
check_interval = env->time_to_die / 10;
if (check_interval < 100) check_interval = 100;
if (check_interval > 1000) check_interval = 1000;

// Proportional thinking time for odd philosophers
if (philo->env->num_philos % 2 != 0)
    ft_msleep(philo->env->time_to_eat * 2 - philo->env->time_to_sleep);
```

### 🎯 **Precision Sleep Implementation**
```c
void ft_msleep(time_t time) {
    time_t current_time = ft_get_time();
    time_t sleep_interval = time / 100;
    
    if (sleep_interval < 100) sleep_interval = 100;
    if (sleep_interval > 1000) sleep_interval = 1000;
    
    while (ft_get_time() - current_time < time)
        usleep(sleep_interval);
}
```

## 🧪 Testing Scenarios

| Scenario | Command | Expected Result |
|----------|---------|-----------------|
| **Normal operation** | `./philo 5 800 200 200` | Continuous simulation |
| **Death detection** | `./philo 4 310 200 200` | Philosopher dies |
| **Single philosopher** | `./philo 1 800 200 200` | Dies after time_to_die |
| **Meal limit** | `./philo 5 800 200 200 3` | Stops after 3 meals each |
| **Stress test** | `./philo 200 800 200 200` | 200 philosophers |

## 🏆 Algorithm Efficiency

- **Time Complexity:** O(n) where n = number of philosophers
- **Space Complexity:** O(n) for philosophers and forks
- **Thread Safety:** 100% race condition free
- **Deadlock Prevention:** Guaranteed through fork ordering
- **Memory Leaks:** Zero (verified with Valgrind)
- **CPU Usage:** Optimized with adaptive monitoring

## 🎯 Key Learnings

This project demonstrates mastery of:

- **Advanced Threading:** pthread creation, joining, and synchronization
- **Mutex Management:** Proper locking/unlocking strategies
- **Resource Allocation:** Dynamic memory management with cleanup
- **Algorithm Design:** Deadlock prevention and optimization
- **Systems Programming:** Low-level timing and process control
- **Code Architecture:** Modular design with clear separation of concerns

## 🔍 Code Quality Features

- ✅ **Norminette compliant** (42 School coding standard)
- ✅ **Memory leak free** (Valgrind verified)
- ✅ **No race conditions** (Thread sanitizer clean)
- ✅ **Comprehensive error handling**
- ✅ **Modular architecture**
- ✅ **Self-documenting code**

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you would like to change.

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## �‍💻 Author

**Ana Zubieta**
- 🎓 42 Málaga - Fundación Telefónica
- 📧 Email: azubieta@student.42malaga.com
- 💻 GitHub: [@Ateibuzena](https://github.com/Ateibuzena)

---

*"In the depth of winter, I finally learned that there was in me an invincible summer."* - Albert Camus

<div align="center">
  <sub>Built with ❤️ for the 42 Network</sub>
</div>

