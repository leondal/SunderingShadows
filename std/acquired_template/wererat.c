#include <std.h>

string *races_allowed()
{
    return ({"human", "ratkin"});
}

int is_rollable() { return 0; } // rollable in creation

/*
  Bostly homebrew, some things are based on rules in Lords of the wild
  Wererat plague lycanthropy powers are in wererat shapes
*/

mapping innate_spells()
{
    return ([
                "darkvision" : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
                "stinking cloud" : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
                "wererat shape" : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
                "contagion" : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
                "remove disease" : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
                ]);
}

int apply_template(object ob)
{
    ob->set_acquired_template("wererat");
    return 1;
}

int remove_template(object ob)
{
    ob->set_acquired_template(0);
    return 1;
}
