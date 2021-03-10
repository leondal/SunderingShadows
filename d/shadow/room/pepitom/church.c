
#include "Pepitom.h"
inherit "/std/church";

void create() {
    ::create();
    set("short", "Pepitom Church");
    set("long",
@MELNMARN
%^BOLD%^You are in the dark church of Pepitom.%^RESET%^
In this huge open monastary run by a monk, the dead 
come to pray for resurrection. East Main Road is outside 
the monastary to the south. 
MELNMARN
);


    set_exits( 
	      ([
		"south" : ROOMS+"eroad28",
	]) );
    set_property("light", 2);
    set_property("indoors", 1);
    set_items(
        (["church" : "The home of the Pepitom monks.", 
          "sign":"You should read it.",
	  "chamber" : "People come here to pray for resurrection "
	    "when they die.", 
	  "road" : "East Main Road."]) );
    set_listen("default", "You hear the faint sounds of "
		      "chanting from the back of the church.");
set_smell("default","You smell the odor of a sweet incense.");
}


