# C++ Module 04 🧠

Le Module 04 approfondit le **polymorphisme par sous-typage**, introduit les **classes abstraites** et explore le concept d'**interfaces** en C++. Ce module vous fait découvrir les fonctions virtuelles, les destructeurs virtuels, et la conception d'architectures orientées objet robustes avec un système de magie RPG.

### Objectifs Pédagogiques

- **Polymorphisme par sous-typage** : Fonctions virtuelles et liaison dynamique
- **Classes abstraites** : Classes non-instanciables avec fonctions virtuelles pures
- **Interfaces** : Conception avec classes purement abstraites
- **Destructeurs virtuels** : Gestion correcte de la destruction polymorphe
- **Copies profondes** : Gestion de la mémoire avec pointeurs et objets alloués

## 🎯 Exercices du Module

### Exercice 00 : Polymorphisme 🐾
**Fichiers :** `Makefile`, `main.cpp`, `*.cpp`, `*.{h,hpp}`

**Objectif :** Comprendre le polymorphisme avec une hiérarchie d'animaux

**Classes à implémenter :**
- **`Animal`** (classe de base)
  - Attribut protégé : `std::string type`
  - Fonction virtuelle : `makeSound()`
- **`Dog`** : hérite d'Animal (type = "Dog")
- **`Cat`** : hérite d'Animal (type = "Cat")

**Démonstration du polymorphisme :**
```cpp
const Animal* j = new Dog();
const Animal* i = new Cat();
j->makeSound(); // Son de chien
i->makeSound(); // Son de chat
```

**Contre-exemple (WrongAnimal/WrongCat) :** Sans fonctions virtuelles, illustre l'absence de polymorphisme.

### Exercice 01 : Je ne veux pas brûler le monde 🧠
**Fichiers :** Exercice précédent + `*.cpp`, `*.{h,hpp}`

**Objectif :** Gestion de la mémoire et copies profondes avec des objets complexes

**Nouvelles classes :**
- **`Brain`** : contient un tableau de 100 `std::string` appelé `ideas`
- **`Dog`** et **`Cat`** : possèdent un attribut `Brain*`

**Points clés :**
- Construction : `new Brain()` dans Dog/Cat
- Destruction : `delete brain` dans les destructeurs
- **Copies profondes** : Le constructeur de copie et l'opérateur d'affectation doivent dupliquer le Brain
- **Destructeur virtuel** : Essential pour éviter les fuites mémoire lors de destruction polymorphe

**Test de gestion mémoire :**
```cpp
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j; // Ne doit pas créer de fuite
delete i;
```

### Exercice 02 : Classe abstraite 🚫
**Fichiers :** Exercice précédent + `*.cpp`, `*.{h,hpp}`

**Objectif :** Rendre la classe Animal non-instanciable

**Modification :** Transformer Animal en classe abstraite avec au moins une fonction virtuelle pure.

**Résultat :** `Animal` ne peut plus être instanciée directement, mais Dog et Cat fonctionnent toujours.

**Optionnel :** Préfixer le nom avec 'A' → `AAnimal`

## 🚀 Compilation et Standards

### Flags de Compilation
```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o programme
```

### Structure des Dossiers
```
cpp_module_04/
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   ├── Animal.hpp
│   ├── Animal.cpp
│   ├── Dog.hpp
│   ├── Dog.cpp
│   ├── Cat.hpp
│   ├── Cat.cpp
│   ├── WrongAnimal.hpp
│   ├── WrongAnimal.cpp
│   ├── WrongCat.hpp
│   └── WrongCat.cpp
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── Animal.hpp
│   ├── Animal.cpp
│   ├── Dog.hpp
│   ├── Dog.cpp
│   ├── Cat.hpp
│   ├── Cat.cpp
│   ├── Brain.hpp
│   └── Brain.cpp
├── ex02/
│   ├── Makefile
│   ├── main.cpp
│   ├── AAnimal.hpp (ou Animal.hpp)
│   ├── AAnimal.cpp (ou Animal.cpp)
│   ├── Dog.hpp
│   ├── Dog.cpp
│   ├── Cat.hpp
│   ├── Cat.cpp
│   ├── Brain.hpp
│   └── Brain.cpp
└── README.md
```
