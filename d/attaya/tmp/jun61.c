
#include <std.h>

inherit ROOM;

void create(){
	::create();
	set_name("Lost graveyard.");
	set_short("Lost graveyard.");
	set_property("indoors",0);
	set_property("light",1);
set_long("
    You stand before a huge stone statue in the center of a circle of marble columns.  Several of the columns have fallen into the jungle after their eons of existance.  A cobblestone path is barely visible running north and east.
");
       set_exits(([
          "north":"/d/attaya/jun65",
          "west":"/d/attaya/jun60",
         "east":"/d/attaya/jun62"
]));
	
      set_smell("default", "The air smells of rain and humidity");
      set_listen("default", "It is strangely quiet.  The animals have all been %^RED%^silenced!");
set_items(([
    "markers": "They are too old to read, but many bear the insignea of the Kinnesaruda or 'Black Dawn'.",
    "plaque" : "It is a fairly large metal plaque that has been set into the base of the statue.  The writing upon it is bold and well defined.",
    "canopy": "It completely blocks out the light.",
    "mud": "It is sloppy and brown, and looks like...  wet soil.",
    "graves": "They are overgrown and have been long forgotten.",
    "wall": "It has been reduced to mere rubble in places.  It is hardly discernible",
    "bones": "A few bones peek out from low lying areas where the soil around them has been eroded away."
]));
	}

void reset(){
	::reset();
    if(!present("statue"))
     new("d/attaya/statue")->move(this_object());
	
	
}
