#include "../../undead.h"

inherit VAULT;

void create() 
{
    ::create();

    set_name("Tomb Hallway");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_property("no teleport", 1);

    set_short("%^RED%^You are inside the Tomb Kartakass");

    set_long("%^RED%^You are inside a dark hallway.%^RESET%^\n"
        "%^BOLD%^BLUE%^To the north you see that the hallway continues "
        "into the darkness.  South of you is the tomb door "
        "and Along the walls you notice large patches of strange, glowing, "
        "moss.  You've never seen anything like it, you can only hope that "
        "it is not harmfull.");
 
    set_exits(([
        "north" :HALL+"hall2",
        "gate"  :HALL+"gate"
             ]));

    set_smell("default","The scent of death is over powering.");
    set_listen("default","You hear bodies shuffling in the dark.");

    set_door("gate",HALL+"gate","gate",0);

    set_locked("gate",0);
    set_open("gate",0);
    set_string("gate","open","The massive gates squeak and grind as "
        "they slowly open.");
    set_string("gate","close","The gates slowly close, the thundering "
        "reverberations sending trickles of sand off the walls.");

}
