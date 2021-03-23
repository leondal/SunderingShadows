#include <std.h>

/*

  undead is superimposed

  innate in /std/innate
  sha stat bonus for hp in /std/living/body
  drain power in /cmds/mortal/_drain
  sunlight damage (for users only) is in /std/user
  resistances in /std/Object
  spells in their spell files
*/

string *races_allowed()
{
    return ({"human", "elf", "half-elf", "half-orc", "half-ogre", "ogre", "yuan-ti", "drow", "half-drow", "minotaur", "saurian"});
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
    return "/std/acquired_template/undead"->innate_spells() + ([
                "create spawn" : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
                "twilight shape" : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
                "domination" : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
                "gaseous form" : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
                "night swarm" : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
                "spider climb" : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
                "sleep" : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
                ]);
}

int apply_template(object ob)
{
    ob->set_acquired_template("vampire");
    ob->set_property("undead",1);
    ob->add_bloodlust(20000);
    return 1;
}

int remove_template(object ob)
{
    ob->remove_property("undead");
    ob->set_acquired_template(0);
    return 1;
}
