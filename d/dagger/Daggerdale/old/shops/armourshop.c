#include <std.h>
inherit ROOM;
void create() {
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
    set_property("light",2);
    set_property("indoors",1);
    set_property("noattack",1);
set_short("Daggerdale's Armor Shop");
    set_long(
@MELNMARN
%^BOLD%^This is the Daggerdale Armor Shop.%^RESET%^
You're standing in a large room with a counter on the south
side. You can see many types of armor scattered around the
room. There is a clerk, behind a counter, watching you
closely as he continues to repair a suit of armor.
MELNMARN
);
    set_smell("default","You smell the cool fresh air.");
    set_listen("default","You hear the sounds of people moving around the city.");
    set_exits( ([
"west" : "/d/dagger/Daggerdale/streets/street10"
        ]) );
    set_items( ([
	"counter" : "A hardwood counter, with bits of armor on it.",
"room" : "This is a large room, with various armor parts scattered about.",
		]));
}
void init(){
    ::init();
if(!present("beldor"))
   find_object_or_load("/d/dagger/Daggerdale/shops/npcs/beldor")->move(TO);
}
