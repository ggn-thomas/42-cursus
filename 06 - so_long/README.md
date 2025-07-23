# So Long - Jeu 2D avec MiniLibX

## 📋 Description

So Long est le **premier projet graphique** à l'École 42 ! Ce projet consiste à créer un **jeu 2D simple** utilisant des textures, sprites et éléments de gameplay basiques. L'objectif est de collecter tous les objets sur une carte et s'échapper par la sortie en utilisant le chemin le plus court possible.

## 🎯 Objectifs d'apprentissage

- Découvrir la programmation graphique avec la bibliothèque graphique de l'école : La **MiniLibX**
- Maîtriser la **gestion de fenêtre** et des événements
- Apprendre à utiliser **textures et sprites**
- Comprendre les bases du **game design** et gameplay
- Implémenter le **parsing de cartes** et validation
- Gérer les **interactions utilisateur** (clavier/souris)

## 🎮 Gameplay

### Concept du jeu
Un **dauphin** (ou personnage de votre choix) doit collecter tous les **poissons** (objets) présents sur la carte puis s'échapper par la **sortie** en empruntant le chemin le plus court possible.

### Contrôles
- **W** : Déplacement vers le haut
- **A** : Déplacement vers la gauche  
- **S** : Déplacement vers le bas
- **D** : Déplacement vers la droite
- **ESC** : Quitter le jeu
- **Croix de la fenêtre** : Fermer le jeu

### Règles
- Collecter **tous les objets** avant de pouvoir sortir
- Impossible de traverser les **murs**
- Affichage du **nombre de mouvements** dans le terminal
- Vue **2D** (de haut ou de profil)
- Jeu **au tour par tour** (pas de temps réel)

## 🗺️ Format des cartes

### Structure d'une carte (.ber)
Les cartes utilisent **5 caractères** différents :

| Caractère | Signification |
|:---------:|---------------|
| `0` | Espace vide (déplacement autorisé) |
| `1` | Mur (obstacle infranchissable) |
| `C` | Collectible (objet à ramasser) |
| `E` | Exit (sortie du niveau) |
| `P` | Player (position de départ du joueur) |

### Exemple de carte simple
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

### Exemple de carte complexe
```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```

### Règles de validation
- **1 sortie** exactement
- **Au moins 1 collectible**
- **1 position de départ** exactement
- Carte de forme **rectangulaire**
- Carte **fermée par des murs** sur tous les bords
- **Chemin valide** existant pour atteindre tous les objets et la sortie

## 🖼️ Ressources graphiques

### Textures nécessaires
- **Mur** (walls) - obstacles du terrain
- **Sol** (floor) - zones de déplacement
- **Collectibles** - objets à ramasser
- **Sortie** - point d'arrivée
- **Personnage** - sprite du joueur

## 🛠️ Installation et compilation

### Prérequis
- **MiniLibX** (fournie par l'école ou à installer)
- **Bibliothèque mathématique** (flag `-lm`)
- Compilateur **gcc** avec flags stricts

### Compilation
```bash
make                    # Compile so_long
make bonus             # Compile avec fonctionnalités bonus
make clean             # Supprime les .o
make fclean            # Supprime les .o et exécutable
make re                # Recompile tout
```

### Exécution
```bash
./so_long maps/map.ber
```

## 📁 Structure du projet

```
so_long/
├── Makefile
├── srcs/
│   ├── main.c              # Point d'entrée
│   ├── window_init.c       # Initialisation de la fenêtre
│   ├── player_moves.c      # Gestion des mouvements
│   ├── map_init.c          # Initialiser la map
│   ├── so_long_utils2.c
│   ├── so_long_utils.c     
│   ├── window_draw.c       # Rendu graphique
│   └── free.c              # Libération mémoire
├── parsing/                # Parsing
|   ├── check_valid_map.c   # Vérifie si la map est dans le bon format
|   ├── flood_fill.c        # Vérifie si un chemin est possible
|   ├── utils_parsing.c
├── includes/
|   ├── so_long.h
├── minilibx-linux/         # Bibliothèque graphique
├── libft/
├── gnl/
├── ft_printf/
├── sprites/                # Fichiers d'images (.xpm)
│   ├── wall.xpm
│   ├── floor.xpm
│   ├── collectible.xpm
│   ├── exit.xpm
│   └── player.xpm
├── maps/                   # Cartes de test (.ber)
└── README.md
```

## 🔧 Fonctions MiniLibX utilisées

### Gestion de fenêtre
```c
mlx_init()              // Initialisation de MiniLibX
mlx_new_window()        // Création d'une fenêtre
mlx_destroy_window()    // Destruction de fenêtre
```

### Gestion d'images
```c
mlx_new_image()         // Création d'image
mlx_xpm_file_to_image() // Chargement de fichier XPM
mlx_put_image_to_window() // Affichage d'image
mlx_destroy_image()     // Liberation d'image
```

### Gestion d'événements
```c
mlx_hook()              // Gestion des événements
mlx_key_hook()          // Gestion du clavier
mlx_loop()              // Boucle d'événements
```

## 🎖️ Partie Bonus

### Fonctionnalités bonus proposées
- **Ennemis/patrouilles** - Le joueur peut perdre
- **Animations de sprites** - Personnages animés
- **Compteur à l'écran** - Mouvements affichés dans la fenêtre
- **Collectibles animés** - Objets qui bougent
- **Sons** - Effets sonores et musique
- **Niveaux multiples** - Progression entre cartes
