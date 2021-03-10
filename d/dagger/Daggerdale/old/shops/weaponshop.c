#include <std.h>
#include "/d/shadow/room/city/melnmarn.h"

inherit ROOM;

void create() {
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light",2);
    set_property("indoors", 1);
    set_property("noattack",1);
    set_short("Daggerdales Weapon Shop.");
    set_long(
@MELNMARN
%^BOLD%^This is the Daggerdale Weapon Shop.%^RESET%^
You're standing in a large room with a counter on the south 
side. You can see many types of weapons scattered around the 
room. There is a clerk, behind a counter, watching you 
closely as he continues to repair a sword. 
MELNMARN
      );

    set_smell("default","You smell hot metal, an burning brasiers.");
    set_listen("default","You hear the sounds work nearby.");

    set_exits( ([
"north" : "/d/dagger/Daggerdale/streets/street19",
        ]) );
    set_items( ([
	"counter" : "A hardwood counter, with weapons on it.",
	"room" : "Large room, weapon parts scattered about the room",
	"weapons" : "The weapons you see are in bad repair."
		]));		    	

}
void init(){
    ::init();
if(!present("erling"))
new("/d/dagger/Daggerdale/shops/npcs/erling")->move(this_object());


}
