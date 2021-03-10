//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
    set_name("Asgard's central park");
    set_short("Asgard's central park");
    set_long(
	"%^BOLD%^Asgard's central park%^RESET%^
You have walked into a large park.  Massive redwood trees line the dirt "+
	"road you stand on.  Bushes and flower grow plentifully everywhere.  "+
   "A massive statue of Asgard's beloved King stands tall above a fountain "+
	"of crystal clear water.  Birds swoop around through the air cheerfully.  "+
	"To the west is the entrance to the park."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The fragrance of the many flowers here is wonderful.");
    set_listen("default","You hear the chirping of a few birds.");
*/
   set_long(::query_long()+"\nWhat was once Asgard's park has become buried "
      "beneath the rubble of the rest of the city.  Many of the redwoods "
      "have been uprooted, though a few stand tall.  The remnants of the king's "
      "statue has been trampled and partially buried beneath the mud.\n");
    set_exits( ([
	"west":"/d/laerad/parnelli/asgard/as09"
    ]) );
}
/*
void reset(){
    if(!present("statue")){
	new("/d/laerad/obj/kstatue")->move(this_object());
    }
}
*/