# C++ Module 03 🧠

Le Module 03 introduit l'**héritage**, un concept fondamental de la programmation orientée objet. Ce module explore la création de hiérarchies de classes, l'héritage simple et multiple, ainsi que les défis liés au problème du diamant. Vous découvrirez comment créer des robots de combat avec différentes capacités héritées.

### Objectifs Pédagogiques

- **Héritage simple** : Créer des classes dérivées et comprendre la relation parent-enfant
- **Chaînage des constructeurs/destructeurs** : Ordre d'appel dans les hiérarchies
- **Héritage multiple** : Gérer l'héritage de plusieurs classes parentes
- **Problème du diamant** : Comprendre et résoudre les ambiguïtés d'héritage
- **Forme canonique orthodoxe** : Maintenir la forme canonique dans l'héritage

## 🎯 Exercices du Module

### Exercice 00 : Aaaaand... OPEN! 🤖
**Fichiers :** `Makefile`, `main.cpp`, `ClapTrap.{h,hpp}`, `ClapTrap.cpp`

**Objectif :** Créer une classe de base `ClapTrap` représentant un robot de combat

**Caractéristiques :**
- **Attributs privés :**
  - `Name` (paramètre du constructeur)
  - `Hit points` (10) - santé du robot
  - `Energy points` (10) - énergie pour les actions
  - `Attack damage` (0) - dégâts d'attaque

**Fonctions membres publiques :**
- `void attack(const std::string& target)` - attaque une cible
- `void takeDamage(unsigned int amount)` - reçoit des dégâts
- `void beRepaired(unsigned int amount)` - se répare

**Règles :** Attaquer et se réparer coûte 1 point d'énergie. Aucune action possible sans hit points ou energy points.

### Exercice 01 : Serena, my love! 💚
**Fichiers :** Exercice précédent + `ScavTrap.{h,hpp}`, `ScavTrap.cpp`

**Objectif :** Créer une classe dérivée `ScavTrap` héritant de `ClapTrap`

**Caractéristiques modifiées :**
- `Hit points` : 100
- `Energy points` : 50  
- `Attack damage` : 20
- Messages différents pour constructeurs/destructeur et `attack()`

**Capacité spéciale :**
- `void guardGate()` - active le mode gardien de porte

**Point clé :** Démonstration du chaînage construction/destruction (ClapTrap → ScavTrap à la création, inverse à la destruction)

### Exercice 02 : Repetitive work 🔄
**Fichiers :** Exercices précédents + `FragTrap.{h,hpp}`, `FragTrap.cpp`

**Objectif :** Créer une seconde classe dérivée `FragTrap` héritant de `ClapTrap`

**Caractéristiques modifiées :**
- `Hit points` : 100
- `Energy points` : 100
- `Attack damage` : 30
- Messages de construction/destruction différents de ScavTrap

**Capacité spéciale :**
- `void highFivesGuys(void)` - demande un high-five positif


## 🚀 Compilation et Standards

### Flags de Compilation
```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o programme
```

### Structure des Dossiers
```
cpp_module_03/
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   ├── ClapTrap.hpp
│   └── ClapTrap.cpp
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── ClapTrap.hpp
│   ├── ClapTrap.cpp
│   ├── ScavTrap.hpp
│   └── ScavTrap.cpp
├── ex02/
│   ├── Makefile
│   ├── main.cpp
│   ├── ClapTrap.hpp
│   ├── ClapTrap.cpp
│   ├── ScavTrap.hpp
│   ├── ScavTrap.cpp
│   ├── FragTrap.hpp
│   └── FragTrap.cpp
└── README.md
```
