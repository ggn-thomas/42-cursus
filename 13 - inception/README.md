# Inception 🐳

Inception vous fait plonger dans l'univers de Docker en créant une infrastructure complète de services web. Vous apprendrez à orchestrer plusieurs conteneurs pour créer un environnement de production robuste avec NGINX, WordPress, et MariaDB.

### Objectifs Pédagogiques

- **Conteneurisation** : Maîtrise de Docker et Docker Compose
- **Administration système** : Configuration de services web
- **Sécurité** : Gestion des certificats TLS, variables d'environnement
- **Networking** : Communication entre conteneurs
- **Volumes persistants** : Gestion des données

## 🏗️ Architecture

```
                    WWW
                     |
                   :443
                     |
              Computer HOST
                     |
              Docker network
          ┌──────────┼──────────┐
          │    :3306 │ :9000    │
    ┌─────────┐ ┌─────────┐ ┌─────────┐
    │Container│ │Container│ │Container│
    │   DB    │ │WordPress│ │  NGINX  │
    │         │ │ +PHP    │ │         │
    └─────────┘ └─────────┘ └─────────┘
          │           │           │
      ┌───▼───┐   ┌───▼───┐       │
      │  DB   │   │WordPress      │
      │Volume │   │ Volume│       │
      └───────┘   └───────┘       │
```

## 🚀 Partie Obligatoire

### Services Requis

#### 🌐 NGINX Container
- **Fonction :** Reverse proxy et serveur web
- **Configuration :** TLSv1.2 ou TLSv1.3 uniquement
- **Port :** 443 (HTTPS uniquement)
- **Base :** Alpine/Debian (avant-dernière version stable)

#### 📝 WordPress + PHP-FPM Container
- **Fonction :** Site web WordPress
- **Configuration :** PHP-FPM installé et configuré
- **Restriction :** SANS NGINX
- **Base :** Alpine/Debian (avant-dernière version stable)

#### 🗄️ MariaDB Container
- **Fonction :** Base de données
- **Configuration :** Installation et configuration MariaDB
- **Restriction :** SANS NGINX
- **Base :** Alpine/Debian (avant-dernière version stable)

### Volumes et Networking

#### 📦 Volumes Persistants
- **Volume DB :** Base de données WordPress (`/home/login/data`)
- **Volume WordPress :** Fichiers du site WordPress (`/home/login/data`)

#### 🔗 Docker Network
- Réseau personnalisé reliant tous les conteneurs
- Communication inter-conteneurs sécurisée
- **Interdictions :** `network: host`, `--link`, `links:`

### Configuration et Sécurité

#### 🔐 Exigences de Sécurité
- **Domaine :** `login.42.fr` pointant vers IP locale
- **Certificats TLS :** Configuration HTTPS obligatoire
- **Variables d'environnement :** Fichier `.env` requis
- **Secrets :** Docker secrets recommandés
- **Utilisateurs :** 2 utilisateurs WordPress (dont 1 admin sans "admin" dans le nom)

#### 🚫 Restrictions Importantes
- **Images :** Pas d'images toutes faites (sauf Alpine/Debian)
- **Mots de passe :** Aucun mot de passe dans les Dockerfiles
- **Hacky patches :** Interdiction de `tail -f`, `sleep infinity`, `while true`
- **Tag latest :** Interdit
- **DockerHub :** Interdit (sauf Alpine/Debian)

## 🛠️ Structure du Projet

```
inception/
├── Makefile                              # Orchestration du projet
├── secrets/                              # Données sensibles (local)
│   ├── credentials.txt
│   ├── db_password.txt
│   └── db_root_password.txt
└── srcs/
    ├── docker-compose.yml               # Configuration des services
    ├── .env                             # Variables d'environnement
    └── requirements/
        ├── mariadb/
        │   ├── Dockerfile
        │   ├── conf/
        │   └── tools/
        ├── nginx/
        │   ├── Dockerfile
        │   ├── conf/
        │   └── tools/
        └── wordpress/
            ├── Dockerfile
            ├── conf/
            └── tools/
```

### Fichier .env Example
```bash
DOMAIN_NAME=login.42.fr

# MYSQL SETUP
MYSQL_USER=wordpress_user
MYSQL_PASSWORD=secure_password
MYSQL_ROOT_PASSWORD=root_password
MYSQL_DATABASE=wordpress

# WORDPRESS SETUP
WP_ADMIN_USER=admin_user
WP_ADMIN_PASSWORD=admin_password
WP_ADMIN_EMAIL=admin@login.42.fr
WP_USER=wp_user
WP_USER_PASSWORD=user_password
WP_USER_EMAIL=user@login.42.fr
```

## 📋 Instructions d'Installation

### Prérequis
- Machine virtuelle (obligatoire)
- Docker et Docker Compose installés
- Accès root pour configuration réseau

### Installation
```bash
# Cloner le repository
git clone <votre-repo> inception
cd inception

# Configurer le domaine local
sudo echo "127.0.0.1 login.42.fr" >> /etc/hosts

# Créer les dossiers de volumes
sudo mkdir -p /home/login/data

# Configurer les variables d'environnement
cp srcs/.env.example srcs/.env
# Éditer srcs/.env avec vos valeurs

# Lancer l'infrastructure
make
```

### Commandes Makefile
```bash
make        # Lance tous les services
make build  # Build les images Docker
make up     # Démarre les conteneurs
make down   # Arrête les conteneurs
make clean  # Nettoie les images et volumes
make fclean # Nettoyage complet
make re     # Rebuild complet
```

## 🔍 Tests et Validation

### Vérifications Essentielles
```bash
# Vérifier les conteneurs actifs
docker ps

# Vérifier les réseaux
docker network ls

# Vérifier les volumes
docker volume ls

# Tester la connectivité
curl -k https://login.42.fr

# Vérifier les logs
docker-compose logs [service]
```

