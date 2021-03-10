//forestberries.c - main, center of forest w/berries

#include <std.h>
#include "../../../newbie.h"
#include "../forest.h"

inherit ROOM;

int berry, make_mobs;

void create(){
berry = random(4);
   ::create();
   if(random(3))  make_mobs = 1;
   set_property("light",3);
   set_property("no teleport",1);
   set_short("%^GREEN%^Sparse forest%^RESET%^");
   set_terrain(LIGHT_FOREST);
   set_travel(GAME_TRACK);
   set_long( (: TO, "ldesc" :) );
   set_smell("default","You notice a sweet smell from the berries.");
   set_listen("default","You hear crickets and birds chirping.");
   set_items( ([ 
   	"pine trees":"The pine trees have a reddish brown flaky bark and tower over you.", 
	({"trails", "trail"}):"%^ORANGE%^Trails meander around, probably made by animals but none seems more travelled than others.%^RESET%^",
	({"bushes", "berries"}): ( (: TO, "bdesc" :) ),
	]) );
}

void init() {
    ::init();
    add_action("pick","pick");
}

void reset() {
	::reset();
  	berry = random(4);
	if(make_mobs) {
	  if( random(3) && !present("bear") )
     	    new(MONST"bear")->move(TO);
        }
}


int pick(string str) {
   	if(str != "berries") {
    	tell_object(TP,"Pick what?");
        return 1;
    }
    if(berry < 1) {
    	tell_object(TP,"The berries that aren't picked are so overripe they fall apart as you try to pick them.");
    	return 1;
    }
    else {
    	tell_object(TP,"You pick a nice handful of the %^MAGENTA%^plump berries.%^RESET%^");
 		tell_room(ETP,""+TP->query_cap_name()+" picks a nice handful of plump %^MAGENTA%^berries%^RESET%^.",TP);
        new(STUFF"berries")->move(TP);
        berry -= 1;
        return 1;
   	}
}

string ldesc(string str) {
   return("This area of the forest is somewhat sparse in vegetation.  "
  "%^CYAN%^Long-needled pine trees%^RESET%^ tower over scattered smaller "
  "evergreens and a few deciduous trees including oaks and sassafras.  Pine "
  "needles and fallen leaves litter the ground.  Various trails cross here and "
  "there, although the area is clear enough you can travel nearly any direction.  "
  "There is a small clump of bushes with %^MAGENTA%^berries %^RESET%^on it here.");
}

string bdesc(string str) {
  if(berry) {
    return("These bushes have several clumps of %^MAGENTA%^juicy berries "
      "%^RESET%^that look and smell like they might be edible and even tasty.  "
      "It looks like birds and animals have been eating them, so maybe they "
      "aren't poisonous.");
  } else {
    return("%^GREEN%^The berry bushes are bare.  There are clumps of rotted "
      "berries on the ground but all the good ones have apparently been picked "
      "or eaten by birds or animals.");
  }
}      
