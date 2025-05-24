# 🔐 PIPETO - Reverse Engineering & Binary Exploitation

## 📘 Introduction

**PIPETO** is a comprehensive cybersecurity project focused on auditing and exploiting a compiled binary. It simulates a real-life Purple Team operation — combining both offensive (Red Team) and defensive (Blue Team) strategies.

This project immerses students in the realities of binary analysis, vulnerability exploitation, and secure code remediation, all within a high-pressure, realistic scenario.

---

## 🎯 Mission Context

You are an **Application Security Engineer** at **The Stone Corporation**, a top-tier cybersecurity company. Your team has been contracted by the government of the Republic of Obsidia to secure the control software of a nuclear power plant.

The software is functional but lacks modern security protections. Intelligence reports suggest an imminent cyberattack orchestrated by **G.O.L.E.M.** (Global Offensive for Logical Exploitation and Manipulation), a rogue AI organization specialized in cyber sabotage.

Your role goes beyond analysis: you must anticipate, counter, and secure the system against a formidable adversary. Every discovered bug and applied fix is a win for national stability.

---

## 🧠 Purple Team

| Role         | Objective                                                                 |
|--------------|---------------------------------------------------------------------------|
| 🔴 Red Team  | Simulate attacks, identify vulnerabilities, extract critical data         |
| 🔵 Blue Team | Fix vulnerabilities, validate patches with tests and hardening techniques |
| 🟣 Purple Team | Collaborate to ensure optimal security coverage                         |

---

## 📦 Project Objectives

- ✅ Perform a Black Box audit (binary + dynamic library only).
- ✅ Perform a White Box audit (full access to source code).
- ✅ Identify, classify, and document all discovered vulnerabilities.
- ✅ Exploit vulnerabilities **without modifying the original code**.
- ✅ Securely patch vulnerabilities in C.
- ✅ Write unit tests for each patch.
- ✅ Generate one `.patch` file per fix.
- ✅ Write a clear and professional vulnerability report.
- ✅ Defend the project in a simulated presentation before a security committee.

---

## 🧰 Environment & Tools

- **Language**: C  
- **System**: Linux  
- **Execution Command**:

```bash
chmod 655 ./pipeto
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD
```

## 📝 Report Template

### Vulnerability X — [Name of the vulnerable command]

- **Severity**: [low / medium / high / critical]  
- **Type**: [Buffer Overflow, Format String, Use-After-Free, etc.]  
- **File**: `src/[file_name].c`  
- **Function**: `[function_name]`  
- **Detected during**: [Black Box Audit / White Box Audit]  

**Demonstration:**  
[Detailed technical description of the vulnerability]

**Proof of Concept:**  
[Steps or script to reproduce the exploit]

**Impact:**  
[Remote Code Execution, Crash, Privilege Escalation, etc.]

**Summary of the Fix:**  
[Clear explanation of the implemented fix]  

- **Patch file**: `patch/[file_name].c.patch`  
- **Unit test**: Yes / No
- **Test coverage**: lines & branchs

## 📁 Pipeto Folder

Contains the complete source code of the project we exploited and patched.

## 📁 patch Folder

**Folder structure**
patch/
├── vulnerability1.patch
├── vulnerability2.patch
└── vulnerability3.patch

**Apply a patch**

```bash
git apply patch/[file_name].patch
```

## 📁 libpipeto Folder

This folder contains all the functions from the source code of the libpepito.so library.
They were recovered using the Ghidra tool 🐉.

## 📁 tests Folder

This folder contains all the unit tests I wrote for the project. Some of the test scores are lower than expected because I encrypted the flags, which affected the results.
