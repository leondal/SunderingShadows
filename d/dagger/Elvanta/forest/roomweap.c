#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors", 1);
    set_property("noattack",1);
set_short ("Elvanta's Weapon Shop");
    set_long(
"
%^BOLD%^This is Elvanta's Weapon Shop.%^RESET%^
Your standing in a large room with a counter on the south 
side. You can see many types of weapons scattered around the 
room. There is a clerk, behind a counter, watching you 
closely as he continues to repair a sword. 
"
      );

    set_smell("default","You smell hot metal, an burning brasiers.");
    set_listen("default","You hear the sounds work nearby.");

set_property("no attack", 1);
    set_exits( ([
"south" : "/d/dagger/Elvanta/forest/room118"
        ]) );
    set_items( ([
	"counter" : "A hardwood counter, with weapons on it.",
	"room" : "Large room, weapon parts scattered about the room",
	"armor" : "The weapons you see are in bad repair."
		]));		    	

}
void init(){
    ::init();
if(!present("kalamadea"))
new("/d/dagger/Elvanta/forest/mon/kalamadea")->move(TO);


}
