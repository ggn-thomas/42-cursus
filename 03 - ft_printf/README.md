# ft_printf - Réimplémentation de printf()

## 📋 Description

ft_printf est un projet du cursus de l'École 42 qui consiste à recoder la fonction `printf()` de la libc. Ce projet permet d'apprendre les **fonctions variadiques** en C et de comprendre le fonctionnement interne d'une des fonctions les plus utilisées en programmation.

## 🎯 Objectifs d'apprentissage

- Découvrir les **fonctions variadiques** (`va_start`, `va_arg`, `va_copy`, `va_end`)
- Comprendre le parsing et l'analyse de chaînes de format
- Maîtriser la conversion entre différentes bases numériques
- Apprendre la gestion des formats et spécificateurs
- Créer un code modulaire et extensible

## ⚙️ Fonctionnement

La fonction `ft_printf()` analyse une chaîne de format et affiche les arguments correspondants selon les spécificateurs rencontrés.

### Prototype
```c
int ft_printf(const char *format, ...);
```

### Valeur de retour
- **Nombre de caractères affichés** (comme le printf original)
- **-1** en cas d'erreur

### Exemple d'utilisation
```c
#include "ft_printf.h"

int main()
{
    int count;
    
    count = ft_printf("Hello %s! You have %d messages.\n", "Alice", 42);
    ft_printf("Characters printed: %d\n", count);
    
    return (0);
}
```

## 🛠️ Compilation

### Makefile inclus avec les règles :
```bash
make        # Compile la bibliothèque libftprintf.a
make clean  # Supprime les fichiers objets
make fclean # Supprime les fichiers objets et libftprintf.a
make re     # Recompile entièrement
```

### Utilisation dans un projet :
```bash
gcc -Wall -Wextra -Werror main.c libftprintf.a
```

## 📁 Structure du projet

```
ft_printf/
├── Makefile
├── ft_printf.h
├── ft_printf.c
├── ft_printf_utils.c
└── README.md
```

## 🔧 Conversions implémentées

### Partie obligatoire

| Spécificateur | Description | Exemple |
|:-------------:|-------------|---------|
| `%c` | Caractère unique | `ft_printf("%c", 'A')` → `A` |
| `%s` | Chaîne de caractères | `ft_printf("%s", "Hello")` → `Hello` |
| `%p` | Pointeur (hexadécimal) | `ft_printf("%p", ptr)` → `0x7fff5fbff710` |
| `%d` | Entier décimal | `ft_printf("%d", 42)` → `42` |
| `%i` | Entier (base 10) | `ft_printf("%i", -42)` → `-42` |
| `%u` | Entier non signé | `ft_printf("%u", 42U)` → `42` |
| `%x` | Hexadécimal minuscule | `ft_printf("%x", 255)` → `ff` |
| `%X` | Hexadécimal majuscule | `ft_printf("%X", 255)` → `FF` |
| `%%` | Symbole pourcentage | `ft_printf("%%")` → `%` |

### Exemples d'utilisation
```c
ft_printf("Character: %c\n", 'A');                    // Character: A
ft_printf("String: %s\n", "Hello World");             // String: Hello World
ft_printf("Pointer: %p\n", &variable);                // Pointer: 0x7fff5fbff710
ft_printf("Decimal: %d\n", 42);                       // Decimal: 42
ft_printf("Integer: %i\n", -42);                      // Integer: -42
ft_printf("Unsigned: %u\n", 4294967295U);             // Unsigned: 4294967295
ft_printf("Hex lower: %x\n", 255);                    // Hex lower: ff
ft_printf("Hex upper: %X\n", 255);                    // Hex upper: FF
ft_printf("Percent: %%\n");                           // Percent: %
```

## 🎖️ Partie Bonus

### Flags supportés

| Flag | Description | Exemple |
|:----:|-------------|---------|
| `-` | Alignement à gauche | `ft_printf("%-10s", "Hello")` → `Hello     ` |
| `0` | Padding avec zéros | `ft_printf("%05d", 42)` → `00042` |
| `.` | Précision | `ft_printf("%.2f", 3.14159)` → `3.14` |
| `#` | Forme alternative | `ft_printf("%#x", 255)` → `0xff` |
| `+` | Affiche toujours le signe | `ft_printf("%+d", 42)` → `+42` |
| ` ` | Espace pour les positifs | `ft_printf("% d", 42)` → ` 42` |

### Largeur de champ
```c
ft_printf("%10s", "Hello");      // "     Hello"
ft_printf("%-10s", "Hello");     // "Hello     "
ft_printf("%010d", 42);          // "0000000042"
```

## ⚠️ Contraintes techniques

### ✅ Autorisé
- `malloc()`, `free()`, `write()`
- `va_start()`, `va_arg()`, `va_copy()`, `va_end()`
- Utilisation de libft (si disponible)

### ❌ Interdit
- Gestion du buffer original de printf
- Fonctions de la famille printf (printf, sprintf, etc.)

### ⚠️ Important
- Pas de gestion du buffer comme le printf original
- Comportement identique au printf de référence
- Gestion des cas d'erreur

## 📚 Fonctions utilitaires

### Parsing et gestion
- `ft_check()` - Analyse la chaîne de format
- `handle_conversion()` - Gère chaque conversion
- `ft_putstr()`, `ft_putchar()` - Fonctions d'affichage

### Conversions numériques
- `ft_putnbr()` - Conversion nombre vers chaîne (base quelconque)
- `ft_uputnbr_base()` - Affichage direct en base
- `ft_putnbr_address()` - Pour les nombres non signés affichage de l'adresse mémoire


### Gestion des arguments variadiques
```c
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    
    va_start(args, format);
    // Traitement...
    va_end(args);
    
    return (count);
}
```