// /d/guilds/alliance/stair2.c

#include <std.h>

inherit VAULT;

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
             "%^RED%^As you walk on the staircase you feel the moist air " +
             "coming from the dungeon chilling your skin. You concentrate " +
             "even more since a fall from this staircase would certainly " +
             "hurt if not kill you.\n");
    set_listen("default", "You hear your own footsteps and some strange sounds coming from the dungeon.");
    set_smell("default", "You smell a mixture of dirt and torches.");
    set_exits(([
                   "down" : "/d/guilds/alliance/hall/dungeon.c",
                   "up" : "/d/guilds/alliance/hall/stair1.c",
               ]));
    set_door("cell door", "/d/guilds/alliance/hall/dungeon", "down", "alliance ring");
    set_open("cell door", 0);
    set_locked("cell door", 1);
    lock_difficulty("cell door", "/daemon/player_housing"->get_phouse_lock_dc("epic"));
    set_door_description("cell door", "This is a door made of three inch thick "
                         "oaken boards.  It has a section cut out and replaced with a grid of one "
                         "inch diameter iron bars so that some air can still get to the prisoners.");
    //set_string("cell door", "open", "The cell door creaks slightly as it swings open.");
    //set_string("cell door", "close", "An ominous thud echoes off the walls as the heavy cell door shuts solidly.");
    //"/d/guilds/alliance/hall/stair2"->set_open("cell door", 0);
    //"/d/guilds/alliance/hall/stair2"->set_locked("cell door", 1);
}
