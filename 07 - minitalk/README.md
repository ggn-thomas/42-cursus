# Minitalk 📡

Un programme de communication inter-processus utilisant les signaux UNIX.

## 📋 Description

Minitalk est un projet de l'école 42 qui consiste à créer un système de communication entre deux programmes (client et serveur) en utilisant uniquement les signaux UNIX `SIGUSR1` et `SIGUSR2`.

Le serveur reçoit des messages texte du client bit par bit via des signaux, puis affiche le message complet une fois la transmission terminée.

## 🔧 Fonctionnalités

### Partie Obligatoire
- **Serveur** : Lance le serveur et affiche son PID
- **Client** : Envoie un message au serveur via son PID
- **Communication** : Transmission bit par bit via signaux UNIX
- **Gestion multi-clients** : Le serveur peut recevoir des messages de plusieurs clients successivement
- **Performance** : Affichage rapide des messages (< 1 seconde pour 100 caractères)

### Partie Bonus
- ✅ **Confirmation de réception** : Le serveur confirme chaque message reçu
- ✅ **Support Unicode** : Transmission de caractères spéciaux et emojis

## 🚀 Installation et Compilation

```bash
# Cloner le repository
git clone [votre-repo] minitalk
cd minitalk

# Compiler le projet
make

# Compiler avec les bonus
make bonus
```

### Règles Makefile disponibles
- `make` ou `make all` : Compile les programmes principaux
- `make bonus` : Compile avec les fonctionnalités bonus
- `make clean` : Supprime les fichiers objets
- `make fclean` : Supprime tous les fichiers générés
- `make re` : Recompile entièrement le projet

## 📖 Utilisation

### 1. Lancer le serveur
```bash
./server
```
Le serveur affiche son PID et attend les messages.

**Exemple de sortie :**
```
Serveur lancé avec PID: 12345
En attente de messages...
```

### 2. Envoyer un message depuis le client
```bash
./client [PID_SERVEUR] "votre message"
```

**Exemple :**
```bash
./client 12345 "Hello, World!"
```

### Exemple complet
```bash
# Terminal 1 : Lancer le serveur
$ ./server
Serveur lancé avec PID: 12345
En attente de messages...

# Terminal 2 : Envoyer un message
$ ./client 12345 "Bonjour depuis 42!"

# Retour sur Terminal 1 :
Message reçu: Bonjour depuis 42!
```

## 🛠️ Architecture Technique

### Fonctions Utilisées
Le projet utilise uniquement les fonctions autorisées :
- `write`, `malloc`, `free`
- `signal`, `sigaction`, `sigemptyset`, `sigaddset`
- `kill`, `getpid`
- `pause`, `sleep`, `usleep`
- `exit`
- `ft_printf` (votre implémentation)

### Algorithme de Transmission
1. Le client convertit chaque caractère en bits
2. Pour chaque bit :
   - `SIGUSR1` = bit 0
   - `SIGUSR2` = bit 1
3. Le serveur reconstitue les caractères bit par bit
4. Affichage du message complet à la fin de transmission

## 📁 Structure du Projet

```
minitalk/
├── src/
│   ├── server.c          # Programme serveur
│   ├── client.c          # Programme client
│   ├── server_bonus.c    # Serveur avec bonus
│   └── client_bonus.c    # Client avec bonus
├── includes/
│   ├── minitalk.h.c         # Header principal
|   ├── minitalk_bonus.c 
├── libft/                # Votre libft (si utilisée)
├── Makefile
└── README.md
```

## ⚡ Optimisations

- **Délais ajustés** : Utilisation de `usleep()` pour synchroniser les transmissions
- **Gestion d'erreurs** : Vérification des PID et des signaux
- **Mémoire** : Allocation dynamique pour les messages de taille variable
- **Performance** : Transmission rapide grâce aux micro-délais optimisés

## 🐛 Gestion d'Erreurs

Le programme gère les cas d'erreur suivants :
- PID invalide ou processus inexistant
- Paramètres manquants ou incorrects
- Échecs d'allocation mémoire
- Signaux perdus ou non reçus

## 🧪 Tests

### Tests de Base
```bash
# Test simple
./client [PID] "Hello"

# Test avec caractères spéciaux
./client [PID] "Accents: àéèùç"

# Test message long
./client [PID] "Lorem ipsum dolor sit amet, consectetur adipiscing elit..."
```

### Tests Bonus
```bash
# Test Unicode
./client [PID] "Émojis: 🚀🎯✨"

# Test confirmation de réception
./client [PID] "Test confirmation" # Devrait afficher un message de confirmation
```

## 📚 Ressources Utiles

- [Signaux UNIX](https://man7.org/linux/man-pages/man7/signal.7.html)
- [sigaction()](https://man7.org/linux/man-pages/man2/sigaction.2.html)
- [kill()](https://man7.org/linux/man-pages/man2/kill.2.html)
- [Documentation Unicode](https://unicode.org/standard/WhatIsUnicode.html)

## 📝 Notes de Développement

### Défis Rencontrés
- **Synchronisation** : Gérer la vitesse de transmission des signaux
- **Perte de signaux** : Le système Linux ne met pas les signaux en file d'attente
- **Unicode** : Gestion des caractères multi-bytes

### Solutions Implémentées
- Délais de synchronisation avec `usleep()`
- Confirmation de réception pour éviter la perte
- Encodage UTF-8 pour le support Unicode

## 🏆 Critères d'Évaluation

- ✅ Compilation sans erreur avec les flags `-Wall -Wextra -Werror`
- ✅ Conformité à la Norme 42
- ✅ Gestion mémoire parfaite (pas de leaks)
- ✅ Fonctionnement stable sans segfault
- ✅ Performance : < 1s pour 100 caractères
- ✅ Support multi-clients
- ✅ Bonus fonctionnels (si implémentés)

---

*Projet réalisé dans le cadre du cursus de l'École 42*

> *"You can't take the sky from me."* - Firefly