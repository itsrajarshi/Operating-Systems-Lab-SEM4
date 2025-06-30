
# 🖥️ Operating Systems Lab Programs – GITAM University

## 📚 About

This repository contains **C programs** implementing core **Operating System concepts and algorithms**, suitable for lab work, projects, and exam preparation.

---

## 👨‍🏫 Faculty Reference

This repository was created as part of the **Operating Systems Lab (Semester 4)** under the guidance of [**Dr. Pujasuman Tripathy**](https://www.linkedin.com/in/pujasuman-tripathy-221888b6/), Faculty at **GITAM University**.


---

## 🗂️ Directory Structure

```
.
├── Additionals/
│   ├── Priority-NP.c
│   ├── Priority-P.c
│   ├── Round-Robin.c
│   ├── SJF-NP.c
│   └── SJF-P.c
│
├── Bankers-Algorithm/
│   └── main.c
│
├── CPU-Scheduling-Algorithms/
│   ├── FCFS.c
│   └── SJF.c
│
├── Disk-Scheduling-Algorithms/
│   ├── C-SCAN.c
│   ├── FCFS.c
│   └── SCAN.c
│
├── File-Organization-Techniques/
│   ├── Hierarchical.c
│   ├── single-level.c
│   └── two-level.c
│
├── Page-Replacement-Algorithms/
│   ├── FIFO.c
│   ├── LRU.c
│   └── optimal.c
│
├── Paging/
│   ├── address-translation.c
│   └── paging.c
│
├── Producer-Consumer/
│   └── main.c
│
├── System-Calls/
│   └── main.c
│
└── README.md
```

---

## ✅ Contents by Topic:

### 1. CPU Scheduling Algorithms (Non-preemptive & Preemptive)
- FCFS (First Come First Serve)
- SJF (Shortest Job First - both NP & Preemptive)
- Priority Scheduling (NP & Preemptive)
- Round Robin Scheduling (RR)

### 2. Paging
- Basic Paging with Address Translation
- Simple Paging Mechanism

### 3. Page Replacement Algorithms
- FIFO (First-In-First-Out)
- LRU (Least Recently Used)
- Optimal Page Replacement

### 4. Disk Scheduling Algorithms
- FCFS Disk Scheduling
- SCAN (Elevator Algorithm)
- C-SCAN (Circular SCAN)

### 5. System Calls Simulation
- Process Management: `fork()`, `exec()`, `wait()`, `sleep()`
- File Management: `open()`, `read()`, `write()`, `close()`

### 6. Banker's Algorithm
- Deadlock Avoidance using Banker's Algorithm

### 7. Producer-Consumer Problem
- Classic synchronization problem using Shared Memory and Semaphores/Mutex (simplified with C)

### 8. File Organization Techniques
- Single-Level Directory
- Two-Level Directory
- Hierarchical Directory Structure

---

## ⚙️ Compilation & Running

**For each program (example FCFS):**

```bash
gcc FCFS.c -o fcfs
./fcfs
```

You can repeat similarly for each `.c` file under respective folders.

---

## 📝 Author

- **Rajarshi Ghosh**,  
GITAM University  
B.Tech CSE'27

---

## ⭐ Useful For:

- Operating Systems Lab Submissions ✅  
- Viva Preparation ✅  
- Semester Exams ✅  
- Personal Projects ✅  
