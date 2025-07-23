# Minishell 🐚

Minishell est une implémentation simplifiée d'un shell Unix en C. Ce projet vous plonge dans les mécanismes fondamentaux des systèmes d'exploitation et vous fait comprendre comment fonctionnent réellement les shells comme Bash.

### Pourquoi ce projet ?
- **Comprendre les processus** : fork, exec, wait
- **Maîtriser les descripteurs** : pipes, redirections, I/O
- **Gérer les signaux** : Ctrl-C, Ctrl-D, Ctrl-\
- **Parser des commandes** : lexing, parsing, expansion
- **Variables d'environnement** : PATH, exports, $?

## 🎯 Fonctionnalités

### ✅ Partie Obligatoire

#### Interface Utilisateur
- **Prompt interactif** : Affichage d'une invite de commande
- **Historique** : Navigation dans les commandes précédentes
- **Gestion des signaux** :
  - `Ctrl-C` : Nouvelle ligne avec prompt
  - `Ctrl-D` : Exit du shell
  - `Ctrl-\` : Aucune action

#### Parsing et Exécution
- **Recherche d'exécutables** : Via PATH ou chemins absolus/relatifs
- **Expansion des variables** : `$VAR`, `$?` (exit status)
- **Gestion des quotes** :
  - `'single quotes'` : Pas d'interprétation
  - `"double quotes"` : Expansion des $ seulement

#### Redirections
```bash
command < input.txt        # Redirection d'entrée
command > output.txt       # Redirection de sortie
command >> append.txt      # Redirection en mode append
command << EOF             # Heredoc
```

#### Pipes
```bash
command1 | command2 | command3  # Pipeline
```

#### Built-ins
- `echo [-n]` : Affichage avec option -n
- `cd [path]` : Changement de répertoire
- `pwd` : Répertoire courant
- `export [VAR=value]` : Variables d'environnement
- `unset [VAR]` : Suppression de variables
- `env` : Affichage de l'environnement
- `exit` : Sortie du shell


## 🚀 Installation et Compilation

```bash
# Cloner le repository
git clone [votre-repo] minishell
cd minishell

# Compiler le projet
make

# Nettoyer
make clean      # Supprime les .o
make fclean     # Supprime tout
make re         # Recompile tout
```

### Dépendances
Le projet utilise la bibliothèque **readline** :
```bash
# Sur Ubuntu/Debian
sudo apt-get install libreadline-dev

# Sur macOS
brew install readline
```

## 📖 Utilisation

### Lancement
```bash
./minishell
```

### Exemples d'Usage

```bash
# Commands basiques
minishell$ ls -la
minishell$ echo "Hello World"
minishell$ pwd

# Variables et expansion
minishell$ export MY_VAR="test"
minishell$ echo $MY_VAR
test
minishell$ echo $?
0

# Redirections
minishell$ echo "Hello" > file.txt
minishell$ cat < file.txt
Hello
minishell$ ls >> list.txt

# Pipes
minishell$ ls -l | grep minishell | wc -l
minishell$ cat file.txt | sort | uniq

# Heredoc
minishell$ cat << EOF
> Line 1
> Line 2
> EOF
Line 1
Line 2

# Built-ins
minishell$ cd /tmp
minishell$ pwd
/tmp
minishell$ export PATH="/new/path:$PATH"
minishell$ env | grep PATH
```

## 🏗️ Architecture Technique

### Structure du Projet
```
minishell/
├── src/
│   ├── main.c              # Point d'entrée
│   ├── parser/
│   │   ├── lexer.c         # Analyse lexicale
│   │   ├── parser.c        # Analyse syntaxique
│   │   └── expander.c      # Expansion des variables
│   ├── executor/
│   │   ├── executor.c      # Exécution des commandes
│   │   ├── builtins.c      # Commandes intégrées
│   │   └── redirections.c  # Gestion des redirections
│   ├── signals/
│   │   └── signals.c       # Gestion des signaux
│   └── utils/
│       ├── env.c           # Variables d'environnement
│       ├── utils.c         # Utilitaires divers
│       └── cleanup.c       # Libération mémoire
├── includes/
│   └── minishell.h         # Header principal
├── libft/                  # Votre libft
├── Makefile
└── README.md
```

### Structures de Données Types

```c
// Token pour le lexer
typedef enum s_mode
{
	WORD,
	PIPE,
	R_INPUT,
	R_OUTPUT,
	ECHO,
	CD,
	PWD,
	EEXPORT,
	EXIT,
	HERE_DOC,
	UNSET,
	ENV,
	DOUBLE_R,
}						t_mode;

typedef struct s_env_var
{
	char				*key;
	char				*value;
	char				*str;
	struct s_env_var	*next;
}						t_env_var;

typedef struct s_line
{
	char				*data;
	t_mode				mode;
	struct s_line		*next;
}						t_line;

typedef struct s_command
{
	t_mode				mode;
	char				*command;
	t_line				**args;
	char				*outfile;
	char				*infile;
	int					in_fd;
	int					out_fd;
	struct s_command	*next;
	int					here_doc;
}						t_command;
```

### Algorithme Principal

```c

int	main(int argc, char **argv, char **env)
{
	t_command			**list_command;
	char				*rl;
	struct sigaction	sa;
	t_env_var			**env_cpy;

	(void)argc;
	(void)argv;
	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, 0);
	env_cpy = load_environment(env);
	while (1)
	{
		rl = readline("-> minishell > ");
		if (!rl) // ctrl -D
			break ;
		if (ft_strlen(rl))
		{   // Parsing
			list_command = sort_arguments(rl, env_cpy);
			add_history(rl);
			ft_free_list_cmd(list_command); // Cleanup
		}
		free(rl);
	}
	ft_free_list_env(env_cpy);
	return (0);
}
```

### Concepts Théoriques
- **Processus et threads** : Différences et usage
- **Descripteurs de fichiers** : 0, 1, 2 et au-delà
- **Variables d'environnement** : Héritage et modification
- **Parsing** : Lexical analysis et syntax parsing

## 🏆 Critères d'Évaluation

### Partie Obligatoire
- ✅ Compilation sans warnings
- ✅ Conformité à la Norme 42
- ✅ Gestion propre de la mémoire
- ✅ Pas de fuites (sauf readline)
- ✅ Signaux gérés correctement
- ✅ Built-ins fonctionnels
- ✅ Redirections et pipes
- ✅ Variables d'environnement
