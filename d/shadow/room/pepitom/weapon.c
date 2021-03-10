#include "Pepitom.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors", 1);
    set_property("noattack",1);
    set_short("Pepitom's Weapon Shop.");
    set_long(
@MELNMARN
%^BOLD%^This is the Pepitom Weapon Shop.%^RESET%^
You're standing in a large room with a counter on the south 
side. You can see many types of weapons scattered around the 
room. There is a clerk, behind a counter, watching you 
closely as she continues to repair a sword. 
MELNMARN
);

    set_smell("default","You smell hot metal, an burning brasiers.");
    set_listen("default","You hear the sounds work nearby.");

    set_exits( ([
    "east" : ROOMS+"wroad11"
        ]) );
    set_items( ([
	"counter" : "A hardwood counter, with weapons on it.",
	"room" : "Large room, weapon parts scattered about the room",
	"armor" : "The weapons you see are in bad repair."
		]));		    	

}
void init(){
  ::init();
   if(!present("stella")){
	if((hour(time()) >= 17) && (hour(time()) <= 18)) {
		new(ROOMS+"stella")->move(ROOMS+"bar.c");
set_long(
@MELNMARN
%^BOLD%^This is the Pepitom Weapon Shop.%^RESET%^
You're standing in a large room with a counter on the south 
side. You can see many types of weapons scattered around the 
room. You notice a sign on the wall, saying that the shop is 
%^BOLD%^ CLOSED.%^RESET%^
MELNMARN
);

	}
	if((hour(time()) >= 19) || (hour(time()) <= 5)) {
		new(ROOMS+"stella")->move(ROOMS+"weaponhome.c");
set_long(
@MELNMARN
%^BOLD%^This is the Pepitom Weapon Shop.%^RESET%^
You're standing in a large room with a counter on the south 
side. You can see many types of weapons scattered around the 
room. You notice a sign on the wall, saying that the shop is 
%^BOLD%^ CLOSED.%^RESET%^
MELNMARN
);

	}
	if((hour(time()) >= 6) && (hour(time()) <=16)) {
		new(ROOMS+"stella")->move(TO);   
set_long(
@MELNMARN
%^BOLD%^This is the Pepitom Weapon Shop.%^RESET%^
You're standing in a large room with a counter on the south 
side. You can see many types of weapons scattered around the 
room. There is a clerk, behind a counter, watching you 
closely as she continues to repair a sword. 
MELNMARN
);
	}
   }
}

