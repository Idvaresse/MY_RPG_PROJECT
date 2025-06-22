#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "rpg.h"
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

int create_text(Variable *variable)
{
     variable->font = sfFont_createFromFile("./assert/Menlo-BoldItalic.ttf");
    if (!variable->font)
        return 1;
    variable->introText = sfText_create();
    sfText_setFont(variable->introText, variable->font);
    sfText_setCharacterSize(variable->introText, 20);
    sfText_setPosition(variable->introText, (sfVector2f){30, 850});
    sfText_setColor(variable->introText, sfWhite);
    sfText_setOutlineThickness(variable->introText, 2);
    sfText_setOutlineColor(variable->introText, sfColor_fromRGB(0, 0, 0));
    return 0;
}

char **tab_text()
{
    static char *intro_text[] = {
    "Autrefois, un royaume prospérait sous la bénédiction des anciens dieux.\n",
    "Les vents chantaient dans les vallées, les cités brillaient d’or et de savoir.\n",
    "Mais les hommes oublièrent les pactes sacrés...\n",
    "Et des profondeurs oubliées, un mal ancien se réveilla.\n",
    "La guerre éclata. Rois tombèrent. Des nations entières furent réduites en cendres.\n",
    "Dans ce chaos, un être se leva...\n",
    "Ni héros, ni monstre. Juste un groupe de survivant, hanté par le passé.\n",
    "leurs destin ? Écrit dans le sang, gravé dans les cieux...\n",
    "Et vous, aventurier... Oserez-vous marcher sur leurs traces\n"
   };
   return (intro_text);

}

void update_text(Variable *variable)
{
    char **steps = tab_text();
    char textToShow[variable->currentChar + 1];
    const char *currentText;

    if (variable->introStep < 3) {
        currentText = steps[variable->introStep];
        if (sfTime_asSeconds(sfClock_getElapsedTime(variable->clock)) >= variable->typingSpeed) {
            variable->currentChar++;
            sfClock_restart(variable->clock);
        }
        strncpy(textToShow, currentText, variable->currentChar);
        textToShow[variable->currentChar] = '\0';
        sfText_setString(variable->introText, textToShow);
    } else
        sfText_setString(variable->introText, "Appuyez sur Entrée pour commencer...");
}