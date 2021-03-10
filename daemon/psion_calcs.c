//      Psion Daemon, adapted from the cleric one
//      Clerics Calcs Daemon
//      Thorn@Shadowgate
//      1/22/95
//      Daemons for Wizard Class
//      cleric_calcs.c
// 		extended for hm use Tristan@Shadowgate
//      wisdom bonus added Grendel@Shadowgate
//      1/2000 Happy Newyear!


#include <std.h>
#include <psions.h>

int *query_bonus_spells(int myint);
int query_spell_limit(int spell_level, int mylevel, string myclass, int myint);
int *query_max_spell_array(int mylevel, string myclass, int myint);

inherit DAEMON;

void create() {
    seteuid(getuid());
}

int *query_max_spell_array(int mylevel, string myclass, int myint) {
    int *spells_allowed, *bonus;
    int i;

    spells_allowed = allocate(10);
    if (myclass == "psion") {
        if (mylevel < 41){
            spells_allowed = PSIONLEVELS[mylevel];
        }else{
            spells_allowed = ({ 9,9,9,9,9,9,9,8,8});

            for (i=41;i<mylevel;i++) {
                spells_allowed[mylevel%9] = spells_allowed[mylevel%9] + (1 + (mylevel-40)/9);
                spells_allowed[(mylevel+5)%9] = spells_allowed[(mylevel+5)%9] + (1 + (mylevel-40)/9);
            }
        }

        if(myint >= 13){
            bonus = query_bonus_spells(myint);
            for(i=0;i<sizeof(bonus);i++){
                if(spells_allowed[i] == 0)
                    continue;
                spells_allowed[i] = spells_allowed[i] + bonus[i];
            }
        }
    }
    return spells_allowed;
}


int query_spell_limit(int spell_level, int mylevel, string myclass, int myint) {
    int *x;

    if(!myint)
        myint = 10;
    
    x = query_max_spell_array(mylevel, myclass, myint);
    return x[spell_level-1];
}


int *query_bonus_spells(int myint){
    int *bonus;

    bonus = allocate(10);
    bonus = ({0, 0, 0, 0, 0, 0, 0, 0, 0});
//they'll never get bonus 8th or 9th, but they're set up anyway (most 
//won't get above a 19 int either)
   switch(myint){
    case 24..25:
        bonus[2] = bonus[2] + 1;
        bonus[6] = bonus[6] + 1;
    case 22..23:
        bonus[1] = bonus[1] + 1;
        bonus[5] = bonus[5] + 1;
    case 20..21:
        bonus[0] = bonus[0] + 1;
        bonus[4] = bonus[4] + 1;
    case 18..19:
        bonus[3] = bonus[3] + 1;
    case 16..17:
        bonus[2] = bonus[2] + 1;
    case 14..15:
        bonus[1] = bonus[1] + 1;
    case 12..13:
        bonus[0] = bonus[0] + 1;
    }

    return bonus;
}
