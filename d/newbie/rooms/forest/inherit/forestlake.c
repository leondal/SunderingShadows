//forestlake.c to inherit to the lakeside rooms


#include <std.h>
#include "../../../newbie.h"
#include "../forest.h"

inherit "/std/pier";
int make_mobs;

void create() {
   ::create();
   make_mobs = random(3);
   set_property("light",3);
   set_property("indoors",0);
   set_short("%^BLUE%^A large lake%^RESET%^");
   set_terrain(SHORE);
   set_travel(GAME_TRACK);
   set_long( (: TO, "ldesc" :) );
   set("night long", (: TO, "ndesc" :) );
   set_smell("default","The water gives the air a moist, fresh smell.");
   if(query_night() == 1) {
       set_listen("default","Waves lap quietly against the shore and frogs can be heard croaking.");
   }
   else {
      set_listen("default","Fish splash and birds swoosh down across the lake.");
   }
   set_items(([
   "lake":"The water looks fairly clear around the edges but you can tell it deepens quickly.  It's dark and quite murky further out from the bank.  Now and then you catch a glimpse of fish swimming around or jumping at insects.",
   ({"moss", "patches"}):"%^GREEN%^Moss grows along the edge of the lake.  You can also see patches of aquatic moss on the rocks and floating in the shallow areas.",
   ({"bank","edge"}):"The bank is eroded and mossy in places, but there are several areas where the grass is quite healthy and you can easily approach the edge.",
   ]));
   set_max_fishing(3);
   set_chance(20);
   set_max_catch(8);
   set_fish((["Big Kahuna" : 10, "Issaquah Trout" : 3 ]));
}

void reset() {
   ::reset();
   if(!make_mobs)   return;
   if(random(3) && (!present("frog"))) {	
    	switch(random(4)) {
    		case 0: 
   	  	   new(MONST"gfrog")->move(TO);
   		   break;
   		case 1:
    		   new(MONST"gfrog")->move(TO);
		   new(MONST"gfrog")->move(TO);
		   break;
    		case 2:	
    		   new(MONST"gfrog")->move(TO);
		   new(MONST"gfrog")->move(TO);
		   new(MONST"gfrog")->move(TO);
		   break;
		case 3:
		   new(CMISC"fishing_pole")->move(TO);
		   break;
	}
   }
}

string ldesc(string str) {
  return("The forest thins and comes to an end along the bank of a large "
    "%^BLUE%^lake %^RESET%^here.  Oak and maple trees are most common but there "
    "are a few long-needled pine trees and various other varieties of trees and "
    "bushes.  There are numerous trails leading to the lake bank and the grass "
    "seems to be kept short by the traffic and wildlife.  The grass thins at the "
    "lake edge and gives way to %^GREEN%^moss %^RESET%^in patches.  Birds swoop "
    "down to the water's surface which also often ripples from the wind or fish "
    "surfacing for bugs.  Fishing might be good here if you had something to fish "
    "with.");
}

string ndesc(string str) {
   return("%^BLUE%^The forest borders along a large lake here.  The trees make "
     "it a little eerie as you look around, especially when the moonlight shines "
     "through them and casts shadows across the dark rippling water.  In the "
     "darkness, its harder to tell what variety they are but you catch a whiff "
     "of pine and nutty smells now and then.%^RESET%^");
}
