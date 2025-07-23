# Philosophers 🍝

Une implémentation du classique problème du dîner des philosophes en C, utilisant les threads et les mutex/sémaphores.

## 📋 Description

Le projet Philosophers est une introduction aux concepts fondamentaux du threading et de la synchronisation. Il simule le fameux problème du dîner des philosophes d'Edsger Dijkstra, où plusieurs philosophes sont assis autour d'une table et alternent entre manger, penser et dormir.

### Le Problème
- **N philosophes** assis autour d'une table ronde
- **N fourchettes** (une entre chaque paire de philosophes)
- Les philosophes ne peuvent **manger qu'avec 2 fourchettes**
- Ils alternent entre **manger**, **penser** et **dormir**
- **Objectif** : éviter la famine et les deadlocks

## 🎯 Objectifs Pédagogiques

- **Threading** : Créer et gérer des threads
- **Synchronisation** : Utiliser des mutex/sémaphores
- **Race conditions** : Éviter les conditions de course
- **Deadlocks** : Comprendre et prévenir les interblocages
- **Performance** : Optimiser la communication inter-threads

## 🏗️ Architecture

### Partie Obligatoire (`philo/`)
- **Threads** : Chaque philosophe = un thread
- **Mutex** : Une fourchette = un mutex
- **Synchronisation** : Gestion des états partagés

## 🚀 Installation et Compilation

```bash
# Cloner le repository
git clone [votre-repo] philosophers
cd philosophers

# Partie obligatoire
cd philo
make

# Partie bonus
cd ../philo_bonus
make bonus
```

## 📖 Utilisation

### Syntaxe
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Arguments
- **number_of_philosophers** : Nombre de philosophes et de fourchettes
- **time_to_die** (ms) : Temps max sans manger avant de mourir
- **time_to_eat** (ms) : Temps passé à manger (avec 2 fourchettes)
- **time_to_sleep** (ms) : Temps passé à dormir
- **[optional]** : Nombre de repas par philosophe avant arrêt

### Exemples

```bash
# Test basique - ne devrait pas mourir
./philo 4 410 200 200

# Test avec limite de repas
./philo 5 800 200 200 7

# Test critique - détection de mort
./philo 4 310 200 100

# Test avec 1 philosophe (cas limite)
./philo 1 800 200 200
```

## 📊 Format de Sortie

Chaque changement d'état est affiché avec un timestamp :

```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

**Exemple de sortie :**
```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 3 has taken a fork
0 3 has taken a fork
0 3 is eating
200 1 is sleeping
200 3 is sleeping
```

## 🧠 Concepts Techniques

### Gestion des Deadlocks

**Problème :** Tous les philosophes prennent leur fourchette gauche simultanément
```c
// ❌ Deadlock possible
pthread_mutex_lock(&left_fork);
pthread_mutex_lock(&right_fork);
```

**Solutions :**
1. **Ordre des fourchettes** : Faire manger les philosophes paires d'abord
2. **Philosophe gaucher** : Un philosophe prend d'abord la fourchette droite
3. **Limite de philosophes** : Maximum N-1 philosophes peuvent manger simultanément

### Structure de Données

```c
typedef struct s_data
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_think;
	int				time_to_sleep;
	long int		start;
	int				nb_philo;
	int				someone_died;
	int				meal_required;
	int				ready;
	pthread_mutex_t	*mutex_death;
	pthread_mutex_t	*mutex_print;
	pthread_mutex_t	*fork;
}					t_data;

typedef struct s_philo
{
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	int				id;
	int				nb_meal;
	long int		last_meal;
	long int		thread_start;
	int				dead;
	t_data			*dt;
	pthread_t		tid;
}					t_philo;
```

### Algorithme de Base

```c
void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->dt->ready)
		continue ;
	if (philo->dt->nb_philo == 1)
	{
		printf("%d %d %s\n", 0, philo->id, "has taken a fork");
		return (NULL);
	}
	if (philo->id % 2 != 0)
		ft_usleep(philo->dt->time_to_eat * 0.9, philo->dt);
	while (!philo->dt->someone_died)
	{
		is_eating(philo);
		is_sleeping_thinking(philo);
	}
	return (NULL);
}
```

## 📁 Structure du Projet

```
philosophers/
├── philo/                    # Partie obligatoire
│   ├── main.c
│   ├── philo_init.c
│   ├── routine.c
│   ├── utils.c
│   └── philo.h
└── Makefile
└── README.md
```