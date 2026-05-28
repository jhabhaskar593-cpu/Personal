#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int random(int a, int b, int c, int range, int add);

int main(void)
{
    //All universal variables
    char start = get_char("Do you want to play?(y/n): ");
    char command;
    int food_inven = 0;
    int cave_res = 0;
    int sideways = 20;
    int updown = 10;
    int turns = 1;
    int tree_side = 0;
    int tree_up = 0;
    int treeX[800] = {0};
    int treeY[800] = {0};
    int treestate[800] = {0};
    int tree = 0;
    int tree_inven = 0;
    int cave_side = 0;
    int cave_up = 0;
    int caveX[800] = {0};
    int caveY[800] = {0};
    int cavestate[800] = {0};
    int cave = 0;
    int animalX = 0;
    int animalY = 0;
    int energy = 100;
    int food = 100;
    int morale = 100;
    int d = 0;
    bool map = true;
    bool inventory = false;
    bool action_tab = false;
    bool animal_crossing = true;
    if (start == 'y' || start == 'Y')
    {
        do
        {
        //Chopper
        bool chop = false;
        int tree_loc;
        for (int i = 0; i < tree; i++)
        {
            if (sideways == treeX[i] && updown == treeY[i] && treestate[i] == 1)
            {
                sideways--;
                if (sideways < 1)
                {
                    sideways = sideways + 2;
                }
                tree_loc = i;
                chop = true;
                break;
            }
        }
            //Cave Explorer
        bool caving = false;
        int cave_loc;
        for (int i = 0; i < cave; i++)
        {
            if (sideways == caveX[i] && updown == caveY[i] && cavestate[i] == 1)
            {
                sideways = sideways + 1;
                if (sideways > 40)
                {
                    sideways = sideways + 2;
                }
                cave_loc = i;
                caving = true;
                break;
            }
        }
        //hunting
        bool animal = false;
        int edge_case = true;
        for (int i = 0; i < cave; i++)
        {
            if (sideways == animalX && updown == animalY)
            {
                sideways--;
                if (sideways < 1)
                {
                    sideways = sideways + 2;
                }
                animal = true;
                edge_case = false;
                break;
            }
        }
        //Cave Spawner
        if (turns % 5 == 0)
        {
            cave_side = random(turns - food, sideways, cave * cave, 37, 1);
            cave_up = random(updown, morale + cave, sideways * updown, 17, 1);
            //Looped checker cave edition
            bool loop_for_cave = true;
            for (int i = 0; i < 800 && caveX[i] != 0 && caveY[i] != 0 && cavestate[i] != 0; i++)
            {
                if (caveX[i] == cave_side && caveY[i] == cave_side && cavestate[i] == 0)
                {
                    cavestate[i] = 1;
                    loop_for_cave = false;
                    break;
                }
            }
            if (loop_for_cave)
            {
            caveX[cave] = cave_side;
            caveY[cave] = cave_up;
            cavestate[cave] = 1;
            cave++;
            }
        }
        //Tree spawner
        if (turns % 2 == 0)
        {
            tree_side = random(turns, sideways, tree, 37, 1);
            tree_up = random(updown, turns + tree, sideways, 17, 1);
            //Looped checker
            bool loop_for_tree = true;
            for (int i = 0; i < 800 && treeX[i] != 0 && treeY[i] != 0 && treestate[i] != 0; i++)
            {
                if (treeX[i] == tree_side && treeY[i] == tree_up && treestate[i] == 0)
                {
                    treestate[i] = 1;
                    loop_for_tree = false;
                    break;
                }
            }
            if (loop_for_tree)
            {
            treeX[tree] = tree_side;
            treeY[tree] = tree_up;
            treestate[tree] = 1;
            tree++;
            }
        }
        //animal spawner
        if (animal_crossing && turns % 2 == 0 && edge_case)
        {
        animalX =  random(updown, morale + cave, sideways * updown, 17, 1);
        animalY = random(turns, sideways + food_inven, tree, 37, 1);
        animal_crossing = false;
        }
        if (turns % 3 == 0 && edge_case)
        {
        animalX = (animalX + 1) % 40;
        }
        //Array copy tree
        int printed_treeX[tree];
        int printed_treeY[tree];
        int printed_treeState[tree];
        for (int i = 0; i < tree; i++)
        {
            if (treeX[i] != animalX || treeY[i] != animalY)
            {
            printed_treeX[i] = treeX[i];
            printed_treeY[i] = treeY[i];
            printed_treeState[i] = treestate[i];
            }
        }
        //Array copy cave
        int printed_caveX[cave];
        int printed_caveY[cave];
        int printed_caveState[cave];
        for (int i = 0; i < cave; i++)
        {
            printed_caveX[i] = caveX[i];
            printed_caveY[i] = caveY[i];
            printed_caveState[i] = cavestate[i];
        }
        //Printer Of map
        if (map)
        {
        for (int i = 0; i < 40; i++)
        {
            printf("_");
        }

        printf("\n");

        for (int i = 1; i < 20;i++)
        {
            printf("|");
            for (int j = 1; j < 40;j++)
            {
                bool space = true;
                if (i == updown && j == sideways)
                {
                    printf("P");
                    space = false;
                }
                else if (space && j == animalX && i == animalY)
                {
                    printf("X");
                    space = false;
                }
                for (int k = 0; k < tree && space; k++)
                {
                    if ( (treeX[k] != sideways || treeY[k] != updown) && printed_treeX[k] == j && printed_treeY[k] == i && printed_treeState[k] == 1)
                    {
                        printf("T");
                        printed_treeX[k] = 0;
                        printed_treeY[k] = 0;
                        printed_treeState[k] = 0;
                        space = false;
                    }
                }
                for (int k = 0; k < tree && space; k++)
                {
                    if ( (caveX[k] != sideways || caveY[k] != updown) && printed_caveX[k] == j && printed_caveY[k] == i && printed_caveState[k] == 1)
                    {
                        printf("C");
                        printed_caveX[k] = 0;
                        printed_caveY[k] = 0;
                        printed_caveState[k] = 0;
                        space = false;
                    }
                }
                if (space)
                {
                    printf(" ");
                }
            }
            printf("|\n");
        }

            printf("|_");
            for (int j = 0; j < 36;j++)
            {
                printf("_");
            }
            printf("__|\n");
        }
        //Action Tab
        else if (action_tab)
        {
            for (int i = 0; i < 20; i++)
        {
            printf("_");
        }

        printf("\n");

        for (int i = 1; i < 10;i++)
        {
            printf("|");
            for (int j = 1; j < 20;j++)
            {
                if ( i == 2 && j == 2)
                {
                    printf("1.  SLEEP");
                    j = j + 8;
                }
                else if (i == 5 && j == 2)
                {
                    printf("2.  EAT");
                    j = j + 6;
                }
                else if (i == 8 && j == 2)
                {
                    printf("3.  PARTY");
                    j = j + 8;
                }
                else
                {
                    printf(" ");
                }
            }
            printf("|\n");
        }

            printf("|_");
            for (int j = 0; j < 16;j++)
            {
                printf("_");
            }
            printf("__|\n");
        }
        //Inventory
        else if (inventory)
        {
            for (int i = 0; i < 20; i++)
        {
            printf("_");
        }

        printf("\n");

        for (int i = 1; i < 10;i++)
        {
            printf("|");
            for (int j = 1; j < 20;j++)
            {
                if ( i == 2 && j == 2)
                {
                    bool gaurd = true;
                    d = 0;
                    int copyofcaveres = cave_res;
                    for (int k = 0; gaurd; k++)
                    {
                        copyofcaveres = copyofcaveres / 10;
                        d++;
                        if (copyofcaveres == 0)
                        {
                            gaurd = false;
                        }
                    }
                    printf("1.  Resources: %i", cave_res);
                    j = j + 14 + d;
                }
                else if (i == 5 && j == 2)
                {
                    bool gaurd = true;
                    d = 0;
                    int copyoftree_inven = tree_inven;
                    for (int k = 0; gaurd; k++)
                    {
                        copyoftree_inven = copyoftree_inven / 10;
                        d++;
                        if (copyoftree_inven == 0)
                        {
                            gaurd = false;
                        }
                    }
                    printf("2.  Wood: %i", tree_inven);
                    j = j + 9 + d;
                }
                else if (i == 8 && j == 2)
                {
                    bool gaurd = true;
                    d = 0;
                    int copyoffood_inven = food_inven;
                    for (int k = 0; gaurd; k++)
                    {
                        copyoffood_inven = copyoffood_inven / 10;
                        d++;
                        if (copyoffood_inven == 0)
                        {
                            gaurd = false;
                        }
                    }
                    printf("3.  Food: %i", food_inven);
                    j = j + 9 + d;
                }
                else
                {
                    printf(" ");
                }
            }
            printf("|\n");
        }

            printf("|_");
            for (int j = 0; j < 16;j++)
            {
                printf("_");
            }
            printf("__|\n");
        }
            //Input
            if (chop)
            {
                printf("Do you want CHOP CHOP?");
            }
            if (caving)
            {
                printf("Do you want CAVE DIVE for no reason?");
            }
            if (animal)
            {
                printf("There's a wild BOAR , today's dinner, do you want to starve?");
            }
            command = get_char("");
            command = toupper(command);

            if (command == 'D' && sideways < 39 && map)
            {
                sideways++;
                food = food - 1;
                energy =  energy - 1;
            }
            else if (command == 'A' && sideways > 1 && map)
            {
                sideways--;
                food = food - 1;
                energy =  energy - 1;
            }
            else if (command == 'W' && updown > 1 && map)
            {
                updown--;
                food = food - 1;
                energy =  energy - 1;
            }
            else if (command == 'S' && updown < 19 && map)
            {
                updown++;
                food = food - 1;
                energy =  energy - 1;
            }
            else if (command == 'C' && chop)
            {
                treestate[tree_loc] = 0;
                tree_inven = tree_inven + 5;
                food = food - 5;
                energy =  energy - 2;
            }
            else if (command == 'H' && caving)
            {
                cavestate[cave_loc] = 0;
                cave_res = cave_res + 2;
                food = food - 10;
                energy =  energy - 5;
            }
            else if (command == 'N' && animal)
            {
                animal_crossing = true;
                food_inven = food_inven + 5;
                food = food - 10;
                energy =  energy - 20;
                morale = morale + 5;
            }
            else if (command == 'X')
            {
                action_tab = true;
                map = false;
                inventory = false;
            }
            else if (command == 'M')
            {
                action_tab = false;
                map = true;
                inventory = false;
            }
            else if (command == 'I')
            {
                action_tab = false;
                map = false;
                inventory = true;
            }
            else if (command == '1' && action_tab)
            {
                action_tab = false;
                map = true;
                inventory = false;
                energy = energy + 2;
                morale = morale - 2;
            }
            else if (command == '2' && action_tab && food_inven > 2)
            {
                food = food + 5;
                food_inven = food_inven - 2;
                energy = energy + 7;
            }
            else if (command == '3' && action_tab && food_inven > 10)
            {
                action_tab = false;
                map = true;
                inventory = false;
                food_inven = food_inven - 10;
                energy = energy + 2;
                morale = morale + 20;
            }
            turns++;
    } while(command != 'E' && (food > 0 || energy > 0 || morale > 0));
    printf("Game Over!!!\n");
    }
}

int random(int a, int b, int c, int range, int add)
{
    int x = ((a * 137) + (b * 149) + (c * 163));

    x = (x * x) + (a * b) + (b * c);

    if (x < 0)
    {
        x = -x;
    }

    return (x % range) + add;
}
