# 🔐 PIPETO - Reverse Engineering & Binary Exploitation

## 📘 Introduction

<<<<<<< HEAD
**PIPETO** est un projet de cybersécurité complet centré sur l’audit et l’exploitation d’un binaire compilé. Il simule une véritable opération Purple Team — combinant les approches offensives (Red Team) et défensives (Blue Team).

Ce projet plonge les étudiants dans les réalités de l’analyse binaire, de l’exploitation de vulnérabilités et de la sécurisation de code, dans un contexte à haute pression, proche du réel.
=======
**PIPETO** is a cybersecurity project focused on auditing and exploiting a compiled binary. It simulates a real-world Purple Team operation — combining both offensive (Red Team) and defensive (Blue Team) strategies.

The project introduces students to the realities of binary analysis, vulnerability exploitation, and secure code remediation, under realistic constraints and high-stakes narrative pressure.
>>>>>>> 69918a68465856a97b9f46ab7c7e8ca76d19ca3f

---

## 🎯 Mission Context

<<<<<<< HEAD
Vous êtes **Application Security Engineer** chez **The Stone Corporation**, une société de cybersécurité de haut niveau. Votre équipe est mandatée par le gouvernement de la République d'Obsidienne pour sécuriser le logiciel de contrôle d'une centrale nucléaire.

Le logiciel est fonctionnel, mais dépourvu de protections modernes. Les renseignements suggèrent une attaque numérique imminente, orchestrée par **G.O.L.E.M.** (Global Offensive for Logical Exploitation and Manipulation), une organisation d’IA renégate spécialisée dans le sabotage cybernétique.

Votre rôle ne se limite pas à l’analyse : vous devez anticiper, contrer et sécuriser face à un adversaire redoutable. Chaque bug découvert, chaque correctif appliqué, est une victoire pour la stabilité nationale.

---

## 🧠 Purple Team

| Rôle         | Objectif                                                              |
|--------------|-----------------------------------------------------------------------|
| 🔴 Red Team  | Simuler les attaques, identifier les vulnérabilités, extraire des données critiques |
| 🔵 Blue Team | Corriger les vulnérabilités, valider les corrections avec tests et patchs |
| 🟣 Purple Team | Travailler en synergie pour assurer une couverture sécuritaire optimale |

---

## 📦 Objectifs du Projet

- ✅ Réaliser un audit Black Box (binaire + librairie dynamique uniquement).
- ✅ Réaliser un audit White Box (accès complet au code source).
- ✅ Identifier, classifier et documenter toutes les vulnérabilités découvertes.
- ✅ Exploiter les failles **sans modifier le code original**.
- ✅ Corriger les vulnérabilités en C, de façon sécurisée.
- ✅ Écrire des tests unitaires pour valider chaque correctif.
- ✅ Générer un fichier `.patch` par correction.
- ✅ Rédiger un rapport de vulnérabilités clair et professionnel.
- ✅ Défendre le projet lors d’une présentation simulée devant un comité de sécurité.

---

## 🧰 Environnement & Outils

- **Langage** : C
- **Système** : Linux
- **Commande d’exécution** :

```bash
chmod 655 ./pipeto
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD
```

## 📝 Template du Rapport

### Faille X, [Nom de la commande vulnérable]
- **Gravité** : [faible / moyenne / élevée / critique]
- **Type** : [Buffer Overflow, Format String, Use-After-Free, etc.]
- **Fichier** : `src/[nom_du_fichier].c`
- **Fonction** : `[nom_de_la_fonction]`
- **Détectée lors de** : [Audit Black Box / Audit White Box]

**Demonstration :**  
[Description technique détaillée de la faille]

**Proof of Concept :**  
[Étapes ou script permettant de reproduire l'exploitation]

**Impact :**  
[Exécution de code à distance, crash, élévation de privilège, etc.]

**Résumé de la correction :**
- [Explication claire de la solution implémentée]
- Fichier patch : `patch/[nom_du_fichier].c.patch`
- Test unitaire : Oui / Non
- Couverture de test : 100% / Partielle

## 📁 Dossier Patch

**Structure du dossier**
patch/
├── faille1.patch
├── faille2.patch
└── faille3.patch

**git apply**

```bash
git apply patch/[nom_fichier].patch
```

## 📁 Dossier libpipeto

Ce dossier contient toutes les fonctions du code source de la librairie **libpepito.so**.
Elles ont été récupérées grâce à l'outil **ghidra** 🐉.
=======
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
>>>>>>> 69918a68465856a97b9f46ab7c7e8ca76d19ca3f
