
#include "/d/shadow/room/shadow.h"
#include "/d/ptalkin/ptalkin.h"
inherit "/std/church";

void create() {
    ::create();
set_short("The Elven Church of Ptalkin");
    set("long",
@SVAHA
%^BOLD%^You are in the havens of the Elven Church of Ptalkin.%^RESET%^
In this huge open monastary run by a monk, the dead come to pray for 
resurrection. To the north you see a winding staircase into the belltower
where you can see and ring an Admin Bell. To the south you see the 
square of the little town with the Ptalkin board.
SVAHA
);
    set_exits( 
	      ([
"out" : PROOM+"room64.c",
"tower" : PROOM+"belltower1.c"
	]) );
    set_property("light", 2);
    set_property("indoors", 1);
    set_items(
(["church" : "The home of the Drow priest S'sverak.",
	  "chamber" : "People come here to pray for resurrection "
	    "when they die.", 
	"staircase" : "This winding staircase leads up into the belltower",
	"belltower" : "This belltower holds an Admin Bell",
	"square" : "The main square of the small town."]) );
    set_listen("default", "You hear the faint sounds of "
		      "chanting from the back of the church.");
    set_listen("chants", "We serve an old man in a dry season"
      "\nA lighthouse keeper in the desert sun\n"
      "Dreamers of sleepers and white treason\n"
      "We dream of rain and the history of the gun\n");
    set_smell("default","You smell the odor of a sweet incense.");
if(!present("s'sverak"))
new("/d/ptalkin/mon/s'sverak")->move(TO);
}

