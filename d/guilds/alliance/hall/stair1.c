// /d/guilds/alliance/stair1.c

#include <std.h>

inherit ROOM;

void create()
{
    object ob;
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    //set_property("no teleport",1);
    set_property("teleport proof", "/daemon/player_housing"->get_phouse_tp_proof("legendary"));
    set_indoors(1);
    set_light(2);
    set_short("Staircase");
    set_long("%^CYAN%^Staircase\n " +
             "%^RED%^You are at the staircase that leads down to the castle " +
             "dungeon. The staircase is carved out of the rock and the dim " +
             "light of a few magical torches reflects in the moisture on the " +
             "steps. You feel a small lump in your throat as you concentrate " +
             "on not slipping.\n");
    set_listen("default", "You hear your own footsteps and some strange sounds coming from the dungeon.");
    set_smell("default", "You smell a mixture of dirt and torches.");
    set_exits(([
                   "down" : "/d/guilds/alliance/hall/stair2.c",
                   "south" : "/d/guilds/alliance/hall/main.c",
               ]));
}
