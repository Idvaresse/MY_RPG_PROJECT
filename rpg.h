/*
** EPITECH PROJECT, 2024
** My_Hunter
** File description:
** all prototypes of funtion
*/

#ifndef MY_H
    #define MY_H
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <math.h>
    #include <stdio.h>

typedef struct {
    sfRenderWindow *window;
    sfFont *font;
    sfText *introText;
    sfSprite *pauseButton;
    sfSprite *nextButton;
    bool paused;
    int introStep;
    int currentChar;
    sfClock *clock;
    float typingSpeed;
    sfSprite *background;
    sfSprite *sprite_personnage;
    sfTexture *bgTexture;
    sfTexture *personnageTexture;
    sfTexture *nextBtnTexture;
    sfTexture *pauseBtnTexture;
    sfTexture *box_texture;
    sfSprite *box_sprite;
} Variable;

char **tab_text();
void handle_events(Variable *variable);
void destroying(Variable *variable);
void update_text(Variable *variable);
int create_text(Variable *variable);
void create_button(Variable *variable);
void create_sprite_personnage(Variable *variable);
void create_box_dialog(Variable *variable);
#endif
