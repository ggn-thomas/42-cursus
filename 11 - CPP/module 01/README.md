# C++ Module 01 🧠

Le Module 01 approfondit vos connaissances C++ en introduisant des concepts cruciaux : allocation dynamique avec `new`/`delete`, références comme alternative aux pointeurs, pointeurs sur fonctions membres, et manipulation de fichiers. Ce module pose les bases pour une programmation C++ plus sophistiquée.

### Objectifs Pédagogiques
- **Gestion mémoire dynamique** : `new`/`delete`, prévention des memory leaks
- **Références** : Alternative moderne aux pointeurs
- **Pointeurs sur membres** : Fonctions membres comme variables
- **Manipulation de fichiers** : Streams et traitement de texte
- **Switch statements** : Structures de contrôle avancées

## 🎯 Exercices du Module

### Exercice 00 : BraiiiiiiinnnzzzZ 🧟
**Fichiers :** `Makefile`, `main.cpp`, `Zombie.{h,hpp}`, `Zombie.cpp`, `newZombie.cpp`, `randomChump.cpp`  
**Objectif :** Comprendre stack vs heap allocation avec des zombies

### Exercice 01 : Moar brainz! 🧟‍♂️
**Fichiers :** `Makefile`, `main.cpp`, `Zombie.{h,hpp}`, `Zombie.cpp`, `zombieHorde.cpp`  
**Objectif :** Allocation d'arrays d'objets avec `new[]`

### Exercice 02 : HI THIS IS BRAIN 🧠
**Fichiers :** `Makefile`, `main.cpp`  
**Objectif :** Démystifier les références C++

### Exercice 03 : Unnecessary violence ⚔️
**Fichiers :** `Makefile`, `main.cpp`, `Weapon.{h,hpp}`, `Weapon.cpp`, `HumanA.{h,hpp}`, `HumanA.cpp`, `HumanB.{h,hpp}`, `HumanB.cpp`  
**Objectif :** Références vs pointeurs dans la conception de classes

### Exercice 04 : Sed is for losers 📝
**Fichiers :** `Makefile`, `main.cpp`, `*.cpp`, `*.{h,hpp}`  
**Objectif :** Manipulation de fichiers et remplacement de texte

### Exercice 05 : Harl 2.0 😤
**Fichiers :** `Makefile`, `main.cpp`, `Harl.{h,hpp}`, `Harl.cpp`  
**Objectif :** Pointeurs sur fonctions membres


## 🚀 Compilation et Standards

### Flags de Compilation
```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o programme
```

### Structure des Dossiers
```
cpp_module_01/
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   ├── Zombie.hpp
│   ├── Zombie.cpp
│   ├── newZombie.cpp
│   └── randomChump.cpp
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── Zombie.hpp
│   ├── Zombie.cpp
│   └── zombieHorde.cpp
├── ex02/
│   ├── Makefile
│   └── main.cpp
├── ex03/
│   ├── Makefile
│   ├── main.cpp
│   ├── Weapon.hpp
│   ├── Weapon.cpp
│   ├── HumanA.hpp
│   ├── HumanA.cpp
│   ├── HumanB.hpp
│   └── HumanB.cpp
├── ex04/
│   ├── Makefile
│   ├── main.cpp
│   └── [autres fichiers selon implémentation]
├── ex05/
│   ├── Makefile
│   ├── main.cpp
│   ├── Harl.hpp
│   └── Harl.cpp
├── ex06/
│   ├── Makefile
│   ├── main.cpp
│   ├── Harl.hpp
│   └── Harl.cpp
└── README.md
```