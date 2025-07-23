# Born2beRoot - Administration Système

## 📋 Description

Born2beRoot est un projet d'administration système de l'École 42 qui vous initie au **monde de la virtualisation**. L'objectif est de créer et configurer votre première machine virtuelle en suivant des règles strictes de sécurité et d'administration.

## 🎯 Objectifs d'apprentissage

- Découvrir la **virtualisation** avec VirtualBox/UTM
- Apprendre l'**administration système Linux**
- Maîtriser la **configuration de sécurité** (pare-feu, SSH, sudo)
- Comprendre le **partitionnement LVM** et le **chiffrement**
- Gérer les **politiques de mots de passe**
- Automatiser la **surveillance système** avec des scripts

## 🖥️ Configuration requise

### Hyperviseur
- **VirtualBox** (recommandé)

### Système d'exploitation
- **Debian** (latest stable)

## ⚙️ Architecture système

### Partitionnement obligatoire
- **Minimum 2 partitions chiffrées** avec LVM
- Structure de partitions sécurisée
- Chiffrement complet du disque

### Exemple de structure LVM :
```
sda                     8:0    0   30.8G  0 disk
├─sda1                  8:1    0    487M  0 part  /boot
├─sda2                  8:2    0      1K  0 part
└─sda5                  8:5    0   30.3G  0 part
  └─sda5_crypt        254:0    0   30.3G  0 crypt
    ├─LVMGroup-root   254:1    0    2.8G  0 lvm   /
    ├─LVMGroup-swap   254:2    0    976M  0 lvm   [SWAP]
    └─LVMGroup-home   254:3    0    3.6G  0 lvm   /home
```

## 🔒 Configuration de sécurité

### Service SSH
- **Port personnalisé** : 4242
- **Connexion root interdite**
- Authentification par clé recommandée

### Pare-feu
- **UFW** (Debian)
- Seul le port 4242 ouvert
- Activation automatique au démarrage

### Configuration utilisateurs
- **Hostname** : `[votre_login]42` (ex: `thgaugai42`)
- **Utilisateur principal** : votre login
- **Groupes** : `user42` et `sudo`

## 🔐 Politique de mots de passe

### Paramètres obligatoires
- **Expiration** : 30 jours
- **Délai minimum** : 2 jours avant modification
- **Avertissement** : 7 jours avant expiration

### Complexité requise
- **Longueur minimum** : 10 caractères
- **Contenu obligatoire** :
  - Au moins 1 majuscule
  - Au moins 1 minuscule  
  - Au moins 1 chiffre
- **Restrictions** :
  - Maximum 3 caractères identiques consécutifs
  - Ne doit pas contenir le nom d'utilisateur
  - Minimum 7 caractères différents de l'ancien mot de passe

## ⚡ Configuration Sudo

### Restrictions de sécurité
- **Maximum 3 tentatives** de mot de passe
- **Archivage complet** des commandes (input/output)
- **Logs** dans `/var/log/sudo/`
- **Mode TTY** activé
- **PATH sécurisé** :
  ```
  /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin
  ```

### Exemple de configuration sudo
```bash
# Message d'erreur personnalisé
Defaults badpass_message="Mot de passe incorrect, essayez encore."

# Limitation des tentatives
Defaults passwd_tries=3

# Archivage des commandes
Defaults log_input,log_output
Defaults logfile="/var/log/sudo/sudo.log"

# Mode TTY obligatoire
Defaults requiretty

# PATH sécurisé
Defaults secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
```

## 📊 Script de monitoring

### Fonctionnalités du script `monitoring.sh`
Le script affiche toutes les 10 minutes via `wall` :

- **Architecture système** et version kernel
- **CPU physiques** et **virtuels**
- **Utilisation RAM** (pourcentage)
- **Utilisation disque** (pourcentage)
- **Charge CPU** (pourcentage)
- **Dernier redémarrage**
- **Statut LVM** (actif/inactif)
- **Connexions TCP** actives
- **Utilisateurs connectés**
- **Adresse IP** et **MAC**
- **Commandes sudo** exécutées


### Configuration cron
```bash
# Exécution toutes les 10 minutes
*/10 * * * * /usr/local/bin/monitoring.sh | wall
```

## 🎖️ Partie Bonus

### Structure de partitionnement avancée
Configuration avec partitions séparées pour `/var`, `/srv`, `/tmp`, etc.

### Services web
- **WordPress** fonctionnel
- **Lighttpd** comme serveur web
- **MariaDB** comme base de données
- **PHP** pour l'exécution

### Service personnalisé
Mise en place d'un service utile au choix (NGINX/Apache2 exclus)

## 🛠️ Commandes utiles

### Vérification du système
```bash
# Informations système
hostnamectl
uname -a

# Partitionnement
lsblk
df -h

# Services
systemctl status ssh
systemctl status ufw

# Utilisateurs et groupes
getent passwd [username]
groups [username]

# Logs sudo
cat /var/log/sudo/sudo.log
```

### Gestion des utilisateurs
```bash
# Créer un utilisateur
sudo adduser [username]

# Ajouter aux groupes
sudo usermod -aG user42,sudo [username]

# Vérifier les groupes
id [username]

# Politique de mot de passe
sudo chage -l [username]
```

### Gestion du pare-feu
```bash
# Debian (UFW)
sudo ufw status
sudo ufw allow 4242

# Rocky (Firewalld)
sudo firewall-cmd --list-all
sudo firewall-cmd --add-port=4242/tcp --permanent
```

### Fichier à rendre
**Uniquement** `signature.txt` contenant la signature SHA1 du disque virtuel :

```bash
# Exemples de commandes pour générer la signature
# Windows
certUtil -hashfile [vm_name].vdi sha1

# Linux/Mac
sha1sum [vm_name].vdi
shasum [vm_name].vdi

# UTM (Mac M1)
shasum [vm_name].utm/Images/disk-0.qcow2
```

### Soutenance
- Connaître la **différence entre `apt` et `aptitude`**
- Comprendre **SELinux** (Rocky) ou **AppArmor** (Debian)
- Expliquer le **fonctionnement de SSH**
- Savoir **créer un utilisateur** en direct
- Pouvoir **expliquer et arrêter** le script monitoring