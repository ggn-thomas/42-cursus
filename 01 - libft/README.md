# Libft - Ma première bibliothèque C

## 📋 Description

Libft est le premier projet de l'École 42 qui consiste à recoder une partie de la libc ainsi qu'd'autres fonctions utiles qui serviront tout au long du cursus. Ce projet permet de bien comprendre le fonctionnement des fonctions de base du C et de créer sa propre bibliothèque de fonctions.

## 🎯 Objectifs d'apprentissage

- Comprendre le fonctionnement interne des fonctions de la libc
- Apprendre la gestion de la mémoire en C
- Maîtriser les pointeurs et l'allocation dynamique
- Découvrir les listes chaînées
- Créer une bibliothèque statique (.a)

## 🛠️ Compilation

### Makefile inclus avec les règles suivantes :

```bash
make        # Compile la bibliothèque libft.a
make clean  # Supprime les fichiers objets
make fclean # Supprime les fichiers objets et libft.a
make re     # Recompile entièrement
make bonus  # Compile avec les fonctions bonus
```

### Compilation manuelle :
```bash
gcc -Wall -Wextra -Werror -c *.c
ar rcs libft.a *.o
```

## 📦 Fonctions implémentées

### Partie 1 - Fonctions de la Libc

#### Fonctions de vérification de caractères
- `ft_isalpha` - vérifie si le caractère est alphabétique
- `ft_isdigit` - vérifie si le caractère est un chiffre
- `ft_isalnum` - vérifie si le caractère est alphanumérique
- `ft_isascii` - vérifie si le caractère est ASCII
- `ft_isprint` - vérifie si le caractère est imprimable

#### Fonctions de manipulation de chaînes
- `ft_strlen` - calcule la longueur d'une chaîne
- `ft_strchr` - trouve la première occurrence d'un caractère
- `ft_strrchr` - trouve la dernière occurrence d'un caractère
- `ft_strncmp` - compare deux chaînes
- `ft_strlcpy` - copie une chaîne de manière sécurisée
- `ft_strlcat` - concatène une chaîne de manière sécurisée
- `ft_strnstr` - trouve une sous-chaîne

#### Fonctions de manipulation de mémoire
- `ft_memset` - remplit la mémoire avec un octet
- `ft_bzero` - met des zéros dans la mémoire
- `ft_memcpy` - copie la mémoire
- `ft_memmove` - copie la mémoire (zones qui se chevauchent)
- `ft_memchr` - trouve un octet dans la mémoire
- `ft_memcmp` - compare deux zones de mémoire

#### Fonctions de conversion
- `ft_toupper` - convertit en majuscule
- `ft_tolower` - convertit en minuscule
- `ft_atoi` - convertit une chaîne en entier

#### Fonctions d'allocation
- `ft_calloc` - alloue et initialise la mémoire
- `ft_strdup` - duplique une chaîne

### Partie 2 - Fonctions supplémentaires

#### Manipulation de chaînes avancée
- `ft_substr` - extrait une sous-chaîne
- `ft_strjoin` - joint deux chaînes
- `ft_strtrim` - supprime les caractères indésirables au début/fin
- `ft_split` - divise une chaîne selon un délimiteur
- `ft_itoa` - convertit un entier en chaîne

#### Fonctions d'application
- `ft_strmapi` - applique une fonction à chaque caractère (avec index)
- `ft_striteri` - applique une fonction à chaque caractère (modification)

#### Fonctions d'écriture
- `ft_putchar_fd` - écrit un caractère sur un fd
- `ft_putstr_fd` - écrit une chaîne sur un fd
- `ft_putendl_fd` - écrit une chaîne + newline sur un fd
- `ft_putnbr_fd` - écrit un nombre sur un fd

### Partie Bonus - Listes chaînées

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```

#### Fonctions de gestion des listes
- `ft_lstnew` - crée un nouveau nœud
- `ft_lstadd_front` - ajoute un nœud au début
- `ft_lstadd_back` - ajoute un nœud à la fin
- `ft_lstsize` - compte le nombre de nœuds
- `ft_lstlast` - retourne le dernier nœud
- `ft_lstdelone` - supprime un nœud
- `ft_lstclear` - supprime toute la liste
- `ft_lstiter` - applique une fonction à chaque nœud
- `ft_lstmap` - applique une fonction et crée une nouvelle liste


### Compilation avec votre projet :

```bash
gcc -Wall -Wextra -Werror main.c libft.a
```

## 📁 Structure du projet

```
libft/
├── Makefile
├── libft.h
├── ft_*.c          # Fonctions obligatoires
├── ft_*_bonus.c    # Fonctions bonus
└── README.md
```

## ⚠️ Points importants

- **Norminette** : Le code respecte la norme de 42
- **Gestion mémoire** : Pas de leaks, tous les malloc sont protégés
- **Compilation** : Utilise les flags `-Wall -Wextra -Werror`
- **Portabilité** : Fonctionne sur les systèmes Unix

## 🔧 Spécifications techniques

- **Langage** : C
- **Norme** : Norme 42
- **Compilation** : cc avec flags stricts
- **Type de bibliothèque** : Statique (.a)
- **Fonctions autorisées** : malloc, free, write (selon les fonctions)