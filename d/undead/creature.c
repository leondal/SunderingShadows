#include <std.h>
#include "undead.h"
#include <daemons.h>

inherit MONSTER;

void create()
{
    //designed for level ~25+
    set_max_level(30);
	::create();
    add_attack_bonus(2);
    add_damage_bonus(5);
    if(TO->query_level())
    {
        set_guild_level("cleric",(int)TO->query_level());
        set_guild_level("mage",(int)TO->query_level());
    }
    if(!TO->query_property("magic resistance"))
    {
        TO->set_mob_magic_resistance("average");
    }
}

int is_target(object obj)
{ 
    if(obj->query_true_invis()) return 0;
    if(obj->is_player()) return 1;
    if(obj->id("summoned monster")) return 1;
    if((string)obj->query_race() == "undead") return 0;
    else return 0;
}

int is_fodder(object obj)
{ 
    if(obj->is_player()) return 0;
    if(obj->id("summoned monster")) return 1;
    else return 0;
}

void nogo(string str)
{
    if(!str) return;

    if(str == "one")
    {
        set_nogo(({ TOWN"room24",
                    TOWN"room26",
                    OBJ"chamber",
                    OBJ"chamber2",
                    OBJ"chamber3",
                    OBJ"chamber4",
                    OBJ"chamber5",
                    OBJ"chamber6",
                    OBJ"chamber7",
                    OBJ"chamber8",
                    MTS"lair",
                    MAZ"mint"
                 }));
    }

    return;
}


    
