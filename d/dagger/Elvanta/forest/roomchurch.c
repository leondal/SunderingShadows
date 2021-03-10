
#include "/d/shadow/room/shadow.h"
inherit "/std/church";

void create() {
    ::create();
set_short("The Church of Elvanta");
    set("long",
"%^BOLD%^You are in the havens of the church of Elvanta.%^RESET%^
In this huge open monastary run by a monk, the dead 
come to pray for resurrection.  The main walkway is outside
" );
    set_exits( 
	      ([
"north" : "/d/dagger/Elvanta/forest/room115"
	]) );
    set_property("light", 2);
    set_property("indoors", 1);
    set_items(
        (["church" : "The home of the Shadow monks.", 
	  "chamber" : "People come here to pray for resurrection "
	    "when they die.", 
	  "road" : "West Road."]) );
    set_listen("default", "You hear the faint sounds of "
		      "chanting from the back of the church.");
    set_listen("chants", "We serve an old man in a dry season"
      "\nA lighthouse keeper in the desert sun\n"
      "Dreamers of sleepers and white treason\n"
      "We dream of rain and the history of the gun\n");
    set_smell("default","You smell the odor of a sweet incense.");
}

