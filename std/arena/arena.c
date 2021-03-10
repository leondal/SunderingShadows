#include <std.h>
#include <arena.h>

inherit ROOM;

void create()
{
    ::create();
    set_property("arena", 1);
    set_property("no teleport", 1);
    set_travel(DIRT_ROAD);  // added to master for easier maint. *Styx*  12/15/02

    set_terrain(CITY);
}

void init()
{
    ::init();
    add_action("escape", "escape");
}

void set_deathmove(string str)
{
    set_property("deathmove", str);
}

int escape()
{
    if (TP->query_paralyzed()) {
        return 1;
    }
    if (TP->query_disable()) {
        return 1;
    }

    TP->move_player(TO->query_property("deathmove"));
    return 1;
}
