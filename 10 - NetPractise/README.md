# NetPractice 🌐

NetPractice est un projet pratique qui vous permet d'apprendre les bases de la configuration réseau en résolvant des problèmes concrets sur des petits réseaux. Vous devrez comprendre et configurer des adressages IP, des masques de sous-réseau, des routages et bien plus encore !

### Objectifs Pédagogiques
- **Adressage IP** : Classes, sous-réseaux, masques
- **Routage** : Tables de routage, passerelles
- **Topology réseau** : Switches, routeurs, hôtes
- **Troubleshooting** : Diagnostic des problèmes réseau
- **Calculs réseau** : CIDR, plages d'adresses

## 🎯 Fonctionnalités

### Interface Web Interactive
- **10 niveaux progressifs** de difficulté croissante
- **Validation en temps réel** de vos configurations
- **Logs détaillés** pour comprendre les erreurs
- **Export des configurations** pour le rendu

### Types d'Exercices
- Configuration d'adresses IP et masques
- Configuration de tables de routage
- Résolution de conflits d'adressage
- Connectivité entre différents réseaux
- Topologies complexes avec multiples routeurs

## 🧠 Concepts Techniques Essentiels

### 1. Adressage IP et Masques

#### Classes d'Adresses IP
```
Classe A: 1.0.0.0    - 126.255.255.255  (/8  - 255.0.0.0)
Classe B: 128.0.0.0  - 191.255.255.255  (/16 - 255.255.0.0)
Classe C: 192.0.0.0  - 223.255.255.255  (/24 - 255.255.255.0)
```

#### Adresses Réservées
```
Privées:
- 10.0.0.0/8        (10.0.0.0 - 10.255.255.255)
- 172.16.0.0/12     (172.16.0.0 - 172.31.255.255)
- 192.168.0.0/16    (192.168.0.0 - 192.168.255.255)

Spéciales:
- 127.0.0.0/8       (Loopback)
- 169.254.0.0/16    (Link-local)
- 0.0.0.0           (Route par défaut)
```

### 2. Calculs de Sous-Réseaux

#### Notation CIDR
```bash
# Exemple: 192.168.1.0/24
IP: 192.168.1.0
Masque: /24 = 255.255.255.0
Réseau: 192.168.1.0
Broadcast: 192.168.1.255
Plage utilisable: 192.168.1.1 - 192.168.1.254
Nombre d'hôtes: 2^(32-24) - 2 = 254
```

#### Techniques de Calcul
```bash
# Calculer la plage d'un réseau
# Exemple: 192.168.10.50/28

# 1. Convertir /28 en décimal
/28 = 255.255.255.240

# 2. Faire un ET logique
192.168.10.50 & 255.255.255.240 = 192.168.10.48

# 3. Déterminer la plage
Réseau: 192.168.10.48
Broadcast: 192.168.10.63
Plage: 192.168.10.49 - 192.168.10.62
```

### 3. Tables de Routage

#### Structure d'une Route
```
Destination    Masque          Passerelle     Interface
0.0.0.0        0.0.0.0         192.168.1.1    eth0     # Route par défaut
192.168.1.0    255.255.255.0   0.0.0.0        eth0     # Route directe
10.0.0.0       255.255.255.0   192.168.1.254  eth0     # Route statique
```

#### Principe de Routage
1. **Route la plus spécifique** (masque le plus long)
2. **Route directement connectée** (passerelle 0.0.0.0)
3. **Route par défaut** (0.0.0.0/0) en dernier recours


## 📁 Structure du Rendu

```
netpractice/
├── level1.json         # Configuration niveau 1
├── level2.json         # Configuration niveau 2
├── level3.json         # Configuration niveau 3
├── level4.json         # Configuration niveau 4
├── level5.json         # Configuration niveau 5
├── level6.json         # Configuration niveau 6
├── level7.json         # Configuration niveau 7
├── level8.json         # Configuration niveau 8
├── level9.json         # Configuration niveau 9
├── level10.json        # Configuration niveau 10
└── README.md          # Ce fichier
```

### Export des Configurations
1. **Connectez-vous** avec votre login 42
2. **Validez** chaque niveau avec "Check again"
3. **Exportez** avec "Get my config"
4. **Renommez** les fichiers : level1.json, level2.json, etc.
5. **Placez** tous les fichiers à la racine de votre dépôt Git

## 🏆 Critères de Réussite

### Validation Technique
- ✅ **10 configurations valides** exportées
- ✅ **Nommage correct** des fichiers (level1.json - level10.json)
- ✅ **Login utilisé** lors de la génération
- ✅ **Tous les objectifs** atteints pour chaque niveau

### Compétences Évaluées
- ✅ **Compréhension** de l'adressage IP
- ✅ **Calculs de sous-réseaux** rapides et précis
- ✅ **Configuration** des tables de routage
- ✅ **Résolution** de problèmes réseau complexes
- ✅ **Optimisation** des configurations

## 🔍 Debugging et Dépannage

### Erreurs Courantes

#### 1. Conflit d'Adressage
```
Erreur: "IP conflict"
Cause: Deux interfaces ont la même IP
Solution: Vérifier l'unicité des adresses
```

#### 2. Mauvais Masque
```
Erreur: "Destination unreachable"
Cause: Masque incorrect, machines pas dans le même réseau
Solution: Recalculer le masque approprié
```

#### 3. Routage Manquant
```
Erreur: "No route to destination"
Cause: Table de routage incomplète
Solution: Ajouter les routes nécessaires
```

#### 4. Passerelle Incorrecte
```
Erreur: "Gateway not reachable"
Cause: Passerelle pas dans le même réseau
Solution: Vérifier la cohérence IP/masque/passerelle
```

### Méthode de Diagnostic
```bash
# 1. Vérifier la connectivité directe (même réseau)
# 2. Vérifier les passerelles par défaut
# 3. Vérifier les tables de routage
# 4. Tracer le chemin paquet par paquet
# 5. Utiliser les logs pour identifier l'erreur
```

## 💡 Tips Avancés

### Optimisation des Configurations
- **Utilisez des plages privées** cohérentes
- **Minimisez le nombre de sous-réseaux** différents
- **Centralisez le routage** quand possible
- **Documentez mentalement** votre logique

### Raccourcis de Calcul
```bash
# Masques courants en /notation
/30 = 4 adresses (2 utilisables)   - Liens point-à-point
/29 = 8 adresses (6 utilisables)   - Très petits réseaux
/28 = 16 adresses (14 utilisables) - Petits réseaux
/27 = 32 adresses (30 utilisables) - Réseaux moyens
/26 = 64 adresses (62 utilisables) - Réseaux moyens-grands
/25 = 128 adresses (126 utilisables) - Grands réseaux
/24 = 256 adresses (254 utilisables) - Réseau classique
```