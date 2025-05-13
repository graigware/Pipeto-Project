# 🔐 PIPETO - Reverse Engineering & Binary Exploitation

## 📘 Introduction

**PIPETO** is a cybersecurity project focused on auditing and exploiting a compiled binary. It simulates a real-world Purple Team operation — combining both offensive (Red Team) and defensive (Blue Team) strategies.

The project introduces students to the realities of binary analysis, vulnerability exploitation, and secure code remediation, under realistic constraints and high-stakes narrative pressure.

---

## 🎯 Mission Context

You are an **Application Security Engineer** at *The Stone Corporation*, an elite cybersecurity consultancy. Your team has been contracted by the government of **The Obsidian Republic** to secure the control software of a nuclear power facility.

The software is functionally robust, but lacks modern protections. Intelligence suggests that a digital assault is imminent, orchestrated by **G.O.L.E.M.** (Global Offensive for Logical Exploitation and Manipulation), a rogue AI-born organization specialized in cyber sabotage.

Your job is not just to review code — but to outthink, outmaneuver, and out-secure this advanced adversary. Every exploit found, every bug patched, is a step toward national stability.

> 🪨 *"Keep the stone in your pocket."*  
> It's more than a motto. It's your foundation — solid, steady, unbreakable.

---

## 🧠 Purple Team Mindset

| Role       | Objective                                                                 |
|------------|---------------------------------------------------------------------------|
| 🔴 **Red Team**  | Simulate attacks, find vulnerabilities, extract critical data          |
| 🔵 **Blue Team** | Fix vulnerabilities, validate corrections via unit tests and patches  |
| 🟣 **Purple Team** | Collaborate across both sides to ensure effective security coverage  |

---

## 📦 Project Objectives

- ✅ Perform a **Black Box Audit** with only a binary and dynamic library.
- ✅ Perform a **White Box Audit** with full access to the source code.
- ✅ **Identify, rank, and document** all discovered vulnerabilities.
- ✅ **Exploit** bugs without modifying the original code.
- ✅ **Fix** vulnerabilities with secure C code.
- ✅ Provide **unit tests** to validate each fix.
- ✅ Generate **`.patch` files** for all modifications.
- ✅ Write a **professional vulnerability report**.
- ✅ Defend the project in an oral presentation simulating a security committee.

---

## 🧰 Environment & Tools

- **Language Constraint:** C (Epitech Coding Style mandatory)
- **System:** Linux
- **Run Instructions:**
  ```bash
  chmod 655 ./pipeto
  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD
