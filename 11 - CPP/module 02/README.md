# C++ Module 02 🧠

Le Module 02 introduit le **polymorphisme ad-hoc**, la **surcharge d'opérateurs** et la **forme canonique de Coplien**. Ce module explore les nombres à virgule fixe comme alternative aux types flottants standard, tout en approfondissant les concepts fondamentaux de la programmation orientée objet en C++.

### Objectifs Pédagogiques

- **Forme canonique de Coplien** : Les quatre fonctions membres essentielles
- **Surcharge d'opérateurs** : Redéfinir le comportement des opérateurs pour vos classes
- **Nombres à virgule fixe** : Alternative aux flottants pour plus de précision
- **Polymorphisme ad-hoc** : Surcharge de fonctions et d'opérateurs
- **Gestion de la précision** : Contrôle fin des calculs numériques

## 🎯 Exercices du Module

### Exercice 00 : Mon premier canon 🎯
**Fichiers :** `Makefile`, `main.cpp`, `Fixed.{h,hpp}`, `Fixed.cpp`

**Objectif :** Créer une classe `Fixed` sous forme canonique pour représenter des nombres à virgule fixe

**Concepts clés :**
- Forme canonique de Coplien (constructeur par défaut, constructeur de recopie, opérateur d'affectation, destructeur)
- Stockage interne avec un entier et 8 bits fractionnaires
- Fonctions `getRawBits()` et `setRawBits()`

### Exercice 01 : Premiers pas vers une classe utile 🔧
**Fichiers :** `Makefile`, `main.cpp`, `Fixed.{h,hpp}`, `Fixed.cpp`
**Fonctions autorisées :** `roundf` (from `<cmath>`)

**Objectif :** Ajouter des constructeurs et conversions pour rendre la classe `Fixed` utilisable

**Nouveautés :**
- Constructeur prenant un entier constant
- Constructeur prenant un flottant constant
- Fonctions de conversion `toFloat()` et `toInt()`
- Surcharge de l'opérateur d'insertion (`<<`)

### Exercice 02 : Maintenant, on peut parler 💬
**Fichiers :** `Makefile`, `main.cpp`, `Fixed.{h,hpp}`, `Fixed.cpp`
**Fonctions autorisées :** `roundf` (from `<cmath>`)

**Objectif :** Implémenter une classe `Fixed` complète avec tous les opérateurs

**Opérateurs à implémenter :**
- **Comparaison :** `>`, `<`, `>=`, `<=`, `==`, `!=`
- **Arithmétiques :** `+`, `-`, `*`, `/`
- **Incrémentation/Décrémentation :** `++` (pré/post), `--` (pré/post)
- **Fonctions statiques :** `min()` et `max()` (versions const et non-const)

## 🚀 Compilation et Standards

### Flags de Compilation
```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o programme
```

### Structure des Dossiers
```
cpp_module_02/
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   ├── Fixed.hpp
│   └── Fixed.cpp
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── Fixed.hpp
│   └── Fixed.cpp
├── ex02/
│   ├── Makefile
│   ├── main.cpp
│   ├── Fixed.hpp
│   └── Fixed.cpp
└── README.md
```

## 📋 Forme Canonique de Coplien

À partir de ce module, toutes vos classes doivent respecter la forme canonique :

1. **Constructeur par défaut**
2. **Constructeur de recopie** 
3. **Opérateur d'affectation**
4. **Destructeur**
