 <h1 align="center">So_Long | 42 Cursus</h1>


<div align="center">

  <h3>Creating a 2D game using the MinilibX, a simple graphic library provided by 42</h3>

</div>


<div align="center">
  <a href="https://github.com/joaopedrogiancolidev/42_so_long/stargazers">
  <img src="https://img.shields.io/github/stars/joaopedrogiancolidev/42_so_long?style=flat&color=purple" alt="Stars">
  </a>
  <a href="https://github.com/joaopedrogiancolidev/42_so_long/network/members">
  <img src="https://img.shields.io/github/forks/joaopedrogiancolidev/42_so_long?style=flat&color=87CEEB" alt="Forks">
  </a>
  <img src="https://img.shields.io/github/languages/top/joaopedrogiancolidev/42_so_long?style=flat&color=4c1" alt="Top Language">
  <img src="https://img.shields.io/github/languages/count/joaopedrogiancolidev/42_so_long?style=flat&color=yellow" alt="Language Count">
  <img src="https://img.shields.io/github/last-commit/joaopedrogiancolidev/42_so_long?style=flat&color=e05d44" alt="Last Commit">
  <a href="https://www.linkedin.com/in/jpgusp/">
  <img src="https://img.shields.io/badge/LinkedIn-João%20Pedro-blue?style=flat&logo=linkedin" alt="LinkedIn">
  </a>

</div>

---

## 📚 Table of Contents
* [🚀 Getting Started](#-getting-started)
* [💡 About Push_swap](#-about-push_swap)
* [✨ Algorithm](#-algorithm)
* [📄 Evaluation](#-evaluation)
* [📞 Contact](#-contact)

---

## Introduction

This project is focused on developing a 2D game that can be interacted with using your keyboard. The task is divided into two parts: the mandatory and the bonus. Each of these parts is compiled and executed separately. The bonus section includes the same features as the mandatory part, along with some additional enhancements.

(Colocar imagem do jogo)

---

## Getting Started

1. Makefile will compile your source files. It must include 'all' and 'bonus' rules for the Mandatory and Bonus parts, respectively. It should not relink.
2. You are required to use MiniLibX for this project.
3. The program should be compiled using the following commands:

```bash
> ./so_long map.ber
> ./so_long_bonus map.ber
```

---

## Mandatory

The number of movements must be displayed in the shell.
Pressing ESC or closing the window should result in quitting the program.

The map must be constructed using five components: walls, collectibles (at least one), empty spaces, exits (at least one), and the player (only one). These five characters compose the map:

0 for an empty space;

1 for a wall;

C for a collectible;

E for a map exit;

P for the player’s starting position.

To move the main character, use the W A S D keys:

W to move up ↑;

S to move down ↓;

D to move right ➞;

A to move left ←.

---

## Bonus instructions

1. Add X to the map for spawn patrols
2. Make the player lose when they touch an enemy patrol
3. Add some sprite animation.
4. Display the movement count directly on screen instead of writing it in the shell.

---

## 📄 Evaluation

The project is successful if it meets the following 42 standards:

    [x] All integers are correctly sorted in ascending order.

    [x] Total operations stay within the efficiency thresholds (e.g., < 700 for 100 numbers).

    [x] Code is written in accordance with the Norm (42 coding standard).

    [x] No memory leaks (checked via Valgrind).

---

## 📞 Contact

João Pedro Giancoli - [LinkedIn Profile](https://www.linkedin.com/in/jpgusp/)

---
