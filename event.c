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

void handle_click_left(sfEvent event, Variable *variable)
{
    sfVector2i mousePos;
    sfFloatRect pauseButtonRect;
    sfFloatRect nextButtonRect;

    if (event.mouseButton.button == sfMouseLeft) {
        mousePos = sfMouse_getPositionRenderWindow(variable->window);
        pauseButtonRect = sfSprite_getGlobalBounds(variable->pauseButton);
        if (sfFloatRect_contains(&pauseButtonRect, mousePos.x, mousePos.y))
            variable->paused = !variable->paused;
        nextButtonRect = sfSprite_getGlobalBounds(variable->nextButton);
        if (sfFloatRect_contains(&nextButtonRect, mousePos.x, mousePos.y)) {
            variable->introStep++;
            variable->currentChar = 0;
        }
    }
}

void handle_click(sfEvent event, Variable *variable)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.button == sfMouseRight) {
            variable->introStep++;
            variable->currentChar = 0;
        }
        handle_click_left(event, variable);
    }
}

void handle_events(Variable *variable)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(variable->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(variable->window);
        handle_click(event, variable);
    }
}
