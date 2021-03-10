// adding chances to find some useful/survival stuff *Styx* 5/26/06
#define RANDSTUFF "/d/common/daemon/randstuff_d"

#include "/d/dagger/drow/short.h"
#include <std.h>
inherit ROOM;

int searched;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("Elite warrior's training hall");
    set_long(
	"%^BLACK%^%^BLUE%^You clamber up the ladder to the second level "
	"of the %^MAGENTA%^regal building%^BLUE%^ and come into a training "
	"hall of some kind. Weapons and various piles of odds and ends are "
	"strewn about the room, splattered with %^RED%^dried blood%^BLUE%^ "
	"which is also quite prominently spread all over the walls and floor. "
	"A large mural of Lloth is painted on one of the walls "
	"here.%^RESET%^"
    );
    set_listen("default",
	"The sound of slain slaves seems to echo from the dried blood."
    );
    set_smell("default",
	"A musty smell fills the room."
    );
    set_items(([
	"ladder":"%^BOLD%^%^GREEN%^The ladder leads to the first level "
	"of the building.%^RESET%^",
	"weapons":"%^MAGENTA%^The weapons are useless and broken and most "
	"likely are granted to slaves to use when fighting the elite drow "
	"in training sessions.",
	"blood":"The blood of slaves killed in training sessions.",
	"mural":"%^RED%^The mural depicts the demonqueen Lloth in "
	  "spider form. It's numerous eyes seem to follow your every "
	  "move.%^RESET%^",
	({"pile", "piles" }): "There's probably a chance some of the piles "
	  "contain something useful.",
    ]));
    set_search("piles", (: TO, "search_pile" :) );
    set_search("pile", (: TO, "search_pile" :) );
    set_search("default", "There's probably a small chance of finding something "
	"useful in one of the piles.");	
    set_exits(([
	"down": RPATH "elite5"
    ]));
}
void reset() {
    ::reset();
    if(!present("drow")) {
	new( MPATH "elite")->move(TO);
	new( MPATH "elite")->move(TO);
	new( MPATH "elite")->move(TO);
	new( MPATH "elite")->move(TO);
    }
    searched = 0;
}

void search_pile(string str) {
   if(searched) {
     write("It looks like someone searched here recently.");
     return;
   }
   if(!random(3)) {
      write("All you find this time are broken weapons and useless junk.");
      tell_room(ETP,TPQCN+" searches the piles of stuff and looks disappointed.", TP);
      searched = 1;
      return;
   }
   RANDSTUFF->find_stuff(TO,"random");
   write("You find something useful, albeit blood-stained, that the guards tossed aside.\n");
   tell_room(ETP,TPQCN+" finds something in one of the piles of stuff.", TP);
   searched = 1;
   return;
} 
