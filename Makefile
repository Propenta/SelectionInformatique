# Définition Compilateur
CC = gcc

# Nom de l'executable final
EXECUTABLE = main

# Liste des fichiers source
SOURCES = main.c etudiant.c

# Liste des fichiers objets générés
OBJETS = $(SOURCES:.c=.o)

# Règle par défaut
all: $(EXECUTABLE)

# Règle de compilation
$(EXECUTABLE): $(OBJETS)
	$(CC) $^ -o $@

# Règle de génération des fichiers objets
%.o: %.c
	$(CC) -c $< -o $@

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(OBJETS)