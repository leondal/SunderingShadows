// adding chances to find some useful/survival stuff *Styx* 5/26/06
// making this an inherit for the others too to

#define RANDSTUFF "/d/common/daemon/randstuff_d"

#include <std.h>
#include "/d/dagger/drow/short.h"

inherit ROOM;

int searched;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("Drow soldier barrack");
    set_long(
	"%^BLACK%^%^BLUE%^This is a standard drow barrack. It is quite "
	"bare of furnishings as soldiers of the Drow Regime own very few "
	"possessions, and those few possessions they do own are usually "
	"kept with them. Other than four cots and foot lockers, "
	"the only other notable items in the room are some scattered "
	"broken weapons.%^RESET%^"
    );
    set_listen("default",
 	"You hear the occasional drow shout from a distance."
    );
    set_smell("default",
	"It smells foul here."
    );
    set_items(([
	"cot":"This is one of four cots in the room.",
	"cots":"The cots are covered with animal skins and furs.",
	"skins":"Various skins from slain animals, used to provide warmth.",
	"furs":"The furs are from various animals and are used to provide "
	"warmth.",
	({"foot locker", "foot lockers", "locker" }):"The foot locker might contain about anything, think you want to look closer?",
	"weapons":"All broken and useless.",
	"wafers":"A standard drow bisquit ration...very horrible tasting and "
	"most likely poisonious to non-drow races."
    ]));
    set_search("foot locker", (: TO, "search_pile" :) );
    set_search("lockers", (: TO, "search_pile" :) );
    set_search("default", "There's probably a chance of finding something "
	"useful in one of the foot lockers.");	
    set_exits(([
	"west": RPATH "city10"
    ]));
}

void reset() {
    ::reset();
    if(!present("drow") && !random(3)) {
	new( MPATH "drows" )->move(TO);
	new( MPATH "drows" )->move(TO);
	new( MPATH "drows" )->move(TO);
	new( MPATH "drowcap" )->move(TO);
	searched = 0;
    }
}

void search_pile(string str) {
   if(present("drowmon", TO)) {
	write("The drow certainly aren't going to stand there and watch you search.");
        return;
   }
   if(searched) {
     write("It looks like someone searched here recently.");
     return;
   }
   if(!random(3)) {
      write("All you find this time are some of those wafers and useless junk.");
      tell_room(ETP,TPQCN+" searches the foot lockers and looks disappointed.", TP);
      searched = 1;
      return;
   }
   RANDSTUFF->find_stuff(TO,"random");
   write("You do indeed find something useful in one of the foot lockers.\n");
   tell_room(ETP,TPQCN+" finds something in one of the foot lockers.", TP);
   searched = 1;
   return;
} 

