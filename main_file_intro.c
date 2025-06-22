#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "rpg.h"
#include <SFML/Window.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

void displaying(Variable *variable) 
{
    sfRenderWindow_clear(variable->window, sfBlack);
    sfRenderWindow_drawSprite(variable->window, variable->background, NULL);
    sfRenderWindow_drawSprite(variable->window, variable->box_sprite, NULL);
    sfRenderWindow_drawText(variable->window, variable->introText, NULL);
    sfRenderWindow_drawSprite(variable->window, variable->pauseButton, NULL);
    sfRenderWindow_drawSprite(variable->window, variable->nextButton, NULL);
    sfRenderWindow_display(variable->window);
}

int textures(Variable *variable)
{
    variable->bgTexture = sfTexture_createFromFile("./assert/map.jpeg", NULL);
    variable->personnageTexture = sfTexture_createFromFile("./assert/personnage2.jpg", NULL);
    variable->nextBtnTexture = sfTexture_createFromFile("./assert/fleche2.png", NULL);
    variable->pauseBtnTexture = sfTexture_createFromFile("./assert/boutonpause.jpg", NULL);
    variable->box_texture = sfTexture_createFromFile("./assert/box_dialog(1).png", NULL);
    if (!variable->bgTexture || !variable->personnageTexture
    || !variable->nextBtnTexture || !variable->pauseBtnTexture) {
        return 1;
    }
    return 0;
}

int call_functions(Variable *variable)
{
    variable->background = sfSprite_create();
    sfSprite_setTexture(variable->background, variable->bgTexture, sfTrue);
    sfSprite_setScale(variable->background, (sfVector2f){1.5, 1.3});
    create_sprite_personnage(variable);
    create_box_dialog(variable);
    create_button(variable);
    variable->clock = sfClock_create();
    variable->typingSpeed = 0.1f;
    variable->currentChar = 0;
    return 0;
}

int main() 
{
    Variable variable = {0};
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};

    variable.window = sfRenderWindow_create(mode, "Window", sfResize | sfClose, NULL);
    if (create_text(&variable) == 1)
        return 1;
    if (textures(&variable) == 1)
        return 1;
    call_functions(&variable);
    while (sfRenderWindow_isOpen(variable.window)) {
        handle_events(&variable);
        if (!variable.paused)
            update_text(&variable);
        displaying(&variable);
    }
    destroying(&variable);
    return 0;
}
