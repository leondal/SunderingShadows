#include <std.h>

string* races_allowed()
{
    return ({"human", "half-elf", "half-drow", "half-orc", "elf", "drow"});
}

int is_rollable() { return 1; } // rollable in creation

mapping innate_spells()
{
    return ([
                "replay tracks" : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
                "darkvision" : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
                "heart of the wild" : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
                "weretiger shape" : (["type" : "spell", "daily uses" : -1, "level required" : 0, ]),
                ]);
}

int apply_template(object ob)
{
    ob->set_acquired_template("weretiger");
    return 1;
}

int remove_template(object ob)
{
    ob->set_acquired_template(0);
    return 1;
}
