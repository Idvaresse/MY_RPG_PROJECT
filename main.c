/*
** EPITECH PROJECT, 2024
** My_rpg
** File description:
** Principal file to build rpg game
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 23
#define MAP_HEIGHT 23

#include "rpg.h"
/*
int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfMusic *music;
    sfEvent event;

    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    texture = sfTexture_createFromFile("asset/menu.jpg", NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    music = sfMusic_createFromFile("nice_music.ogg");
    sfMusic_play(music);

    while (sfRenderWindow_isOpen(window))
    {
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfMusic_destroy(music);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return 0;
}

// Génère une carte avec un chemin horizontal et quelques arbres
char **generate_map(void) {
    char **map = malloc(sizeof(char *) * MAP_HEIGHT);
    if (!map) return NULL;

    // Initialise le générateur de nombres aléatoires
    srand(time(NULL));

    for (int y = 0; y < MAP_HEIGHT; y++) {
        map[y] = malloc(MAP_WIDTH + 1); // +1 pour le '\0' de fin de ligne
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = '#'; // Par défaut : sol
        }
        map[y][MAP_WIDTH] = '\0';
    }

    // Créer un chemin horizontal au centre
    int path_y = MAP_HEIGHT / 2;
    for (int x = 0; x < MAP_WIDTH; x++) {
        map[path_y][x] = '@';
    }

    // Ajouter aléatoirement quelques arbres
    for (int i = 0; i < 50; i++) {
        int tree_x = rand() % MAP_WIDTH;
        int tree_y = rand() % MAP_HEIGHT;
        if (map[tree_y][tree_x] == '#') {
            map[tree_y][tree_x] = '+';
        }
    }

    return map;
}

// Affiche la map dans le terminal
void print_map(char **map) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        printf("%s\n", map[y]);
    }
}

// Libère la mémoire de la carte
void free_map(char **map) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        free(map[i]);
    }
    free(map);
}

int main(void) {
    char **map = generate_map();

    if (!map) {
        fprintf(stderr, "Erreur d'allocation mémoire.\n");
        return 84;
    }

    print_map(map);
    free_map(map);

    return 0;
}
*/
