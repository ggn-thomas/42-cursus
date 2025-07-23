# Push_swap - Algorithme de tri optimisé

## 📋 Description

Push_swap est un projet d'algorithmie de l'École 42 qui consiste à **trier des données dans une pile** en utilisant un set d'instructions limité, avec le **moins d'opérations possibles**. Ce projet vous initie aux **algorithmes de tri** et à la notion de **complexité algorithmique**.

## 🎯 Objectifs d'apprentissage

- Comprendre et implémenter différents **algorithmes de tri**
- Analyser la **complexité algorithmique** 
- Optimiser les performances selon le contexte
- Manipuler les **structures de données** (piles)
- Choisir la solution la plus appropriée selon la configuration des données

## 🎮 Règles du jeu

### Les piles
- **Pile A** : contient les entiers à trier (désordonnés au départ)
- **Pile B** : vide au départ, utilisée comme pile auxiliaire

### Objectif
Trier la pile A par **ordre croissant** (plus petit nombre au sommet)

## 🛠️ Instructions disponibles

### Opérations de swap (échange)
- `sa` - Swap A : échange les 2 premiers éléments de la pile A
- `sb` - Swap B : échange les 2 premiers éléments de la pile B  
- `ss` - Swap simultané : `sa` et `sb` en même temps

### Opérations de push (transfert)
- `pa` - Push A : prend le sommet de B et le place sur A
- `pb` - Push B : prend le sommet de A et le place sur B

### Opérations de rotate (rotation vers le haut)
- `ra` - Rotate A : décale tous les éléments vers le haut (premier → dernier)
- `rb` - Rotate B : décale tous les éléments vers le haut  
- `rr` - Rotate simultané : `ra` et `rb` en même temps

### Opérations de reverse rotate (rotation vers le bas)
- `rra` - Reverse Rotate A : décale tous les éléments vers le bas (dernier → premier)
- `rrb` - Reverse Rotate B : décale tous les éléments vers le bas
- `rrr` - Reverse Rotate simultané : `rra` et `rrb` en même temps

## 📊 Exemple pratique

```
État initial:     Après sa:        Après pb pb pb:
2                 1                 6  3
1                 2                 5  2  
3                 3                 8  1
6                 6                 _  _
5                 5                 a  b
8                 8
_                 _
a                 b
```

## 🚀 Utilisation

### Compilation
```bash
make                    # Compile push_swap
make bonus             # Compile push_swap + checker (bonus)
make clean             # Supprime les .o
make fclean            # Supprime les .o et exécutables
make re                # Recompile tout
```

### Exécution
```bash
# Trier une liste d'entiers
./push_swap 4 67 3 87 23

# Exemple de sortie
pb
ra
pb
ra
sa
pa
pa

# Vérifier avec le checker (bonus)
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
OK
```

## 📈 Critères de performance

### Validation minimale (note de 80)
- **100 nombres** : maximum **700 opérations**
- Cible moyenne mais ne jamais dépasser 700

### Validation optimale (accès aux bonus)
- **100 nombres** : maximum **700 opérations** 
- **500 nombres** : maximum **5500 opérations**

### Tests de performance
```bash
# Générer 100 nombres aléatoires et compter les opérations
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l

# Vérifier que le tri fonctionne
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | ./checker $ARG
```

## 🧠 Stratégies d'algorithmes

### Pour petites listes (2-5 éléments)
- **Algorithme manuel** optimisé
- Toutes les configurations possibles traitées

### Pour moyennes listes (6-100 éléments)
- **Turcs sort** aux contraintes des piles

### Pour grandes listes (100-500 éléments)
- **Turcs sort** aux contraintes des piles

## 📁 Structure du projet

```
push_swap/
├── Makefile
├── push_swap.h
├── push_swap.c
├── commands/        # Implémentation des opérations
│   ├── push_command.c
│   ├── reverse_rotate_command.c
│   ├── rotate_command.c
│   └── swap_command.c
├── algorithms/          # Algorithmes de tri
│   ├── small_sort.c     # 2-5 éléments
│   ├── start_sort.c
│   └── stack_moves.c
├── utils/
|   ├── error_free.c
|   ├── stack_init.c
|   ├── ft_push_swap_utils.c
├── libft/
└── README.md
```
