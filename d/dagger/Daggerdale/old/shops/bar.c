#include <std.h>
#include "/d/shadow/room/city/melnmarn.h"
inherit ROOM;

void create() {
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The Ye Ole Drunken Warrior Bar");
    set("long",
@SIA
%^BOLD%^Welcome to the Ye Ole Drunken Warrior Bar!%^RESET%^
%^CYAN%^
There are 5 tables in the front room.  Servers enter and exit
through double swinging doors and quickly deliver food and ale.
The tap room is straight ahead.
SIA
    );
    set_smell("default","You smell the odor of beer and sweat.");
    set_listen("default","You hear the sounds of glasses clanging.");

    set_items( ([
	"bar" : "The Ye Ole Drunken Drow Bar",
]) );
set_exits( ([
"east" : "/d/dagger/Daggerdale/streets/street27",
"west" : "/d/dagger/Daggerdale/shops/tap",
]) );
    set_property("no castle", 1);
}

void reset() {
    ::reset();
//    if(!present("trigovia")) 
// new("/d/dagger/Daggerdale/shops/npcs/trigovia")->move(this_object());
  if(!present("belil"))   // removed semi-colon to fix overspawn 9/23/02 *Styx*
new("/d/dagger/Daggerdale/shops/npcs/belil")->move(this_object());
}
