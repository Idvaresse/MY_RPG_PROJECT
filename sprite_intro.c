#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "rpg.h"
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

void create_sprite_personnage(Variable *variable)
{
    variable->sprite_personnage = sfSprite_create();
    sfSprite_setTexture(variable->sprite_personnage, variable->personnageTexture, sfTrue);
    sfSprite_setPosition(variable->sprite_personnage, (sfVector2f){0, 100});
    sfSprite_setScale(variable->sprite_personnage, (sfVector2f){0.7, 0.6});
}

void create_box_dialog(Variable *variable)
{
    variable->box_sprite = sfSprite_create();
    sfSprite_setTexture(variable->box_sprite, variable->box_texture, sfTrue);
    sfSprite_setScale(variable->box_sprite, (sfVector2f){0.5, 0.3});
    sfSprite_setPosition(variable->box_sprite, (sfVector2f){0, 780});
}

void create_button(Variable *variable)
{
    variable->pauseButton = sfSprite_create();
    sfSprite_setPosition(variable->pauseButton, (sfVector2f){850, 500});
    sfSprite_setTexture(variable->pauseButton, variable->pauseBtnTexture, sfTrue);
    sfSprite_setScale(variable->pauseButton, (sfVector2f){0.1, 0.1});
    variable->nextButton = sfSprite_create();
    sfSprite_setPosition(variable->nextButton, (sfVector2f){1720, 450});
    sfSprite_setTexture(variable->nextButton, variable->nextBtnTexture, sfTrue);
    sfSprite_setScale(variable->nextButton, (sfVector2f){0.2, 0.3});
}

void destroying(Variable *variable)
{
    sfText_destroy(variable->introText);
    sfFont_destroy(variable->font);
    sfRenderWindow_destroy(variable->window);
    sfSprite_destroy(variable->pauseButton);
    sfSprite_destroy(variable->nextButton);
    sfSprite_destroy(variable->background);
    sfSprite_destroy(variable->sprite_personnage);
    sfTexture_destroy(variable->bgTexture);
    sfTexture_destroy(variable->personnageTexture);
    sfTexture_destroy(variable->nextBtnTexture);
    sfTexture_destroy(variable->pauseBtnTexture);
    sfClock_destroy(variable->clock);
}
