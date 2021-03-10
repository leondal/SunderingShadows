//      Clerics Calcs Daemon
//      Thorn@Shadowgate
//      1/22/95
//      Daemons for Wizard Class
//      cleric_calcs.c
// 		extended for hm use Tristan@Shadowgate
//      wisdom bonus added Grendel@Shadowgate
//      1/2000 Happy Newyear!
// added 3e style bonuses to all classes. Nienne, 08/09.

#include <std.h>
#include <clerics.h>

int *query_bonus_spells(int mywis);
int query_spell_limit(int spell_level, int mylevel, string myclass, int mywis);
int *query_max_spell_array(int mylevel, string myclass, int mywis);

inherit DAEMON;

void create() { seteuid(getuid()); }

int *query_max_spell_array(int mylevel, string myclass, int mywis)
{
    int *spells_allowed, *bonus, result;
    int i;

    spells_allowed = ({});
    if (myclass == "cleric")
    {
        if (mylevel < 41) { spells_allowed = CDLEVELS[mylevel]; }
        else { spells_allowed = ({ 15,15,15,15,15,15,15,15,15 }); }
    }

    if (myclass == "paladin" || myclass == "antipaladin")
    {
        if (mylevel < 41) { spells_allowed = PLEVELS[mylevel]; }
        else { spells_allowed = ({15,15,15,15,15,15,0,0,0}); }
    }

    if (myclass == "ranger")
    {
        if (mylevel < 41) { spells_allowed = RLEVELS[mylevel]; }
        else { spells_allowed = ({10,10,10,10,10,0,0,0,0}); }
    }

    if(mywis >= 12)
    {
        bonus = query_bonus_spells(mywis);
        for(i=0;i<sizeof(bonus);i++)
        {
            if(spells_allowed[i] == 0) { continue; }
            spells_allowed[i] = spells_allowed[i] + bonus[i];
        }
    }

    return spells_allowed;
}


int query_spell_limit(int spell_level, int mylevel, string myclass, int mywis) {
    int *x;

    if(!mywis)
        mywis = 10;

    x = query_max_spell_array(mylevel, myclass, mywis);
    return x[spell_level-1];
}


int *query_bonus_spells(int mywis){ //redone to mirror 3e standard spell bonuses
    int *bonus;

    bonus = allocate(8);
    bonus = ({0, 0, 0, 0, 0, 0, 0});

    switch(mywis){
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
