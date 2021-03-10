//Tree for food on Deku

#include <std.h>

inherit ROOM;

int fruit;

void create(){
fruit = random(4);
   ::create();
   set_property("light",3);
   set_property("no teleport",1);
   set_short("%^GREEN%^Shadowlord forest%^RESET%^");
   set_terrain(HEAVY_FOREST);
   set_travel(FOOT_PATH);
   set_long("Just off the path is this small clearing where someone seems to have "
     "nurtured a peach tree to flourish in spite of the conditions on the rest "
     "of the island.  Some fruit lies rotten on the ground and has attracted "
     "various insects.  There is a small plaque on a post near the base of the "
     "tree.");
   set_smell("default","The air carries a hint of a peach smell.");
   set_listen("default","You hear insects buzzing around.");
   set_items( ([ 
     ({"fruit", "peaches", "peach"}): ( (: TO, "fruitdesc" :) ),
     "plaque" : "The plaque is inscribed:\n\nA small tribute to the Forest "
        "Father and new beginnings\n\nthanks to Schatten's devotion and service",
     ({"tree", "trees"}) : "The more gnarled, older trees have been carefully "
        "pruned to allow the peach tree to grow and even flourish here."
	]) );
    set_exits(([
       "west" : "/d/deku/open/dforest3-2",
    ] ));
}

void init() {
    ::init();
    add_action("pick","pick");
}

void reset() {
	::reset();
  	fruit = random(4);
}


int pick(string str) {
   	if(str != "peach" && str != "fruit") {
    	tell_object(TP,"Pick what?");
        return 1;
    }
    if(fruit < 1) {
    	tell_object(TP,"There doesn't seem to be any fruit on the tree just now.");
    	return 1;
    }
    else {
    	tell_object(TP,"You pick a nice, firm but ripe %^YELLOW%^peach %^RESET%^"
    	    "from a nearby branch.");
 		tell_room(ETP,""+TP->query_cap_name()+" picks a yummy looking %^YELLOW%^"
 		    "peach %^RESET%^from a nearby branch.",TP);
        new("/d/deku/misc/peach")->move(TP);
        fruit -= 1;
        return 1;
   	}
}

string fruitdesc(string str) {
  if(fruit) {
    return("The tree has a few %^YELLOW%^ripe looking peaches %^RESET%^within "
      "reach that other passersby have left unpicked.");
  } else {
    return("%^GREEN%^There is no fruit in sight on the tree.");
  }
}      
