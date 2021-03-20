#include <std.h>

/*
  innate in /std/innate
  negative energy reversal in /std/magic/spell
  exhaustion in /std/living
  con stat in /std/living/body

  bonus damage in individual spells
*/

string *races_allowed()
{
    return ({ "human", "elf", "half-elf", "half-orc", "half-ogre", "ogre", "yuan-ti", "drow", "half-drow", "minotaur", "saurian", "goblin", "gnoll", "bugbear", "orc", "firbolg", "halfling", "dwarf", "beastkin", "troll" });
}

int is_rollable() { return 0; } // rollable in creation

int query_unbound_age()
{
    return 1;
}

mapping* stat_requirements()
{
    return (["constitution" : 18]);
}

mapping innate_spells()
{
    return ([
                "darkvision" : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
                "animate dead" : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
                ]);
}

int apply_template(object ob)
{
    ob->set_property("undead",1);
    ob->set_acquired_template("undead");
    return 1;
}

int remove_template(object ob)
{
    ob->remove_property("undead");
    ob->set_acquired_template(0);
    return 1;
}
