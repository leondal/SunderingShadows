#include <std.h>
#include "../juran.h"
inherit VAULT;

void create(){
  	::create();
      set_property("indoors",1);
    	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
      set_short("Training Area, Juran");
      set_long(
@DIEGO
%^CYAN%^BOLD%^Training Arena, Juran%^RESET%^
You are in the training arena in Juran.  This is where adventurers
come to be trained in the weapons that they have chosen to try and use. 
The %^CYAN%^walls%^RESET%^ are padded, but not sufficiently, to help prevent injuries 
and even the %^CYAN%^floor%^RESET%^ seems rather soft in most places.  There are 
practice %^RED%^bodies%^RESET%^ around the room, and racks of weapons for the %^CYAN%^trainees%^RESET%^.  You can see a few young would-be fighters practicing even now.

To the north, you can see the archery range where you could train with
bows and other ranged weapons.
DIEGO
        );
        set_property("light",-2);
        set_smell("default","There is a strong smell of sweat and blood "+
        	"that permeats the room.");
        set_listen("default","You can hear the clang of weapons as the trainees"+
        	" practice about the room.");
        set_items(([
        ({"wall","walls"}) : "The walls here are padded to help prevent injuries"+
        	" during practice.",
        "floor" : "The floor is somehow softer than normal, it has a certain give"+
        	" to it that would help to lessen the impact.",
        "trainees" : "There are a few young would-be fighters practicing with"+
        	" wooden dummies at the edges of the room.",
        "dummies" : "There are several practice dummies lined up about the room "+
        	"and even some bodies of victims to help young fighters get the feel "+
        	"of their weapons.",
        ]));
        set_exits(([
            "north" : JROOMS+"archery",
        	"west" : JROOMS+"r35",
        ]));
}

void reset(){
   	::reset();
   	if(!present("grinder")) new(JMONS+"grinder")->move(TO);
}
