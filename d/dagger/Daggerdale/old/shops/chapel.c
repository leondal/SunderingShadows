#include <std.h>
#include "/d/shadow/room/shadow.h"
inherit "/std/church";

void create() {
    ::create();
        set("short","Daggerdale Temple");
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set("long",
   "%^BOLD%^You are in the dark temple of Daggerdale.%^RESET%^\n"+
   "This temple is rather small and only tended by a few priests. It is meant"+
   " as a sanctuary for everyone, but most of the citizens do not come here,"+
   " instead choosing to worship and pay homage to the various gods and goddesses in their specific temples. The structure is very"+
    " sturdy however, with high vaulted ceilings and rows of benches where one"+
   " may pray to whatever god you follow. There is a layer of dust across the"+
   " granite floor, but someone keeps the incense fresh and lit.");
    set_exits( 
	      ([
"south" : "/d/dagger/Daggerdale/streets/street19",
                "west" : "/d/dagger/Daggerdale/streets/street26"
	]) );
    set_property("light", 2);
    set_property("indoors", 1);
    set_items(
        (["church" : "The home of the Daggerdale priests.", 
	  "chamber" : "People come here to pray for resurrection "
	    "when they die.", 
]));
    set_listen("default", "You hear the faint sounds of "
		      "chanting from the back of the temple.");
    set_listen("chants", "We serve an old man in a dry season"
      "\nA lighthouse keeper in the desert sun\n"
      "Dreamers of sleepers and white treason\n"
      "We dream of rain and the history of the gun\n");
    set_smell("default","You smell the odor of a sweet incense.");
}

