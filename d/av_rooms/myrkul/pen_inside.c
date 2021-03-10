// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("pen_inside");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("desert");
    set_travel("foot path");
    set_climate("desert");

    set_short("%^RESET%^%^CYAN%^Inside the pen%^RESET%^");

    set_long("You stand in the enormous pen. All around you see the walls of the pen enclosing the sandy desert. The only way out appears to be the massive gate. A mystical trough is inside the pen that seems to re"
	"fill itself. Mammoth crap is scattered around the pen in gargantuan piles. You wonder who gets the job to clean up?"
	);

    set_smell("default","
It smells like mammoth crap.");
    set_listen("default","You here the steady rumble of the mammoth's breathing.");

    
set_items(([ 
	({ "crap", "piles" }) : "%^RESET%^%^ORANGE%^Oh that's a five foot pile of nasty!%^RESET%^",
	]));

    set_exits(([ 
		"out" : "/d/av_rooms/myrkul/pen",
	]));

    set_door("massive gate","/d/av_rooms/myrkul/pen","out","anhurs key","lock");
    add_lock("massive gate","anhurs key","lock","This is a heavy iron lock.");
    set_locked("massive gate",1,"lock");
    lock_difficulty("massive gate",-5,"lock");
    set_open("massive gate",0);
    set_string("massive gate","knock","pounds on the");
    set_string("massive gate","open","The gate rumbles open.");
    set_string("massive gate","close","The gate rumbles closed.");
    set_door_description("massive gate","This is a massive gate designed as much to keep things out as to keep this mammoth in.");
}