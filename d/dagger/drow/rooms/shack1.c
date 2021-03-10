// searching added by *Styx*  5/26/06
#define RANDSTUFF "/d/common/daemon/randstuff_d"

#include "/d/dagger/drow/short.h"
#include <std.h>
inherit ROOM;

int searched;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("Slave compound");
    set_long(
       	"%^BLACK%^%^BLUE%^You stand within one of the elven slave "
	"shacks. The shack is used as sleeping quarters for the "
	"elven slaves but contains nothing more than a pile of straw "
	"in the center of the floor. There are numerous holes in the "
	"ceiling which let the rain drip through and "
	"numerous holes in the walls allowing the cold wind to blow "
	"in.%^RESET%^"
    );
    set_listen("default",
	"You hear the rain's patter as it pelts the roof of the shack."
    );
    set_smell("default",
	"The smell of old straw fills the room."
    );
    set_items(([
	"shack":"%^BOLD%^%^YELLOW%^The shack is made of wheat and has "
	"no door...just a hole in the side wall of it. It has many holes "
	"in it.%^RESET%^",
	(({"slaves","slave","elf","elves"})):"%^MAGENTA%^The poor slaves are "
	"dressed in dirty rags. The elf seems to be nothing more than a "
	"skeleton draped with thin skin as the slaves are very "
	"underfed.%^RESET%^",
	"mud":"There is mud all about.",
	"rain":"%^BLUE%^The rain drizzles down upon the compound. "
	"Amazing how there was no rain in any other part of the "
	"city...%^RESET%^",
	"straw":"The straw is piled in the center of the room covering "
	"the wooden floor.",
	"floor":"Some of the floor boards appear loose but it is hard to "
	"tell because of the pile of straw.",
    ]));
    set_exits(([
	"east": RPATH "slave1"
    ]));
    set_search("straw", (: TO, "search_pile" :) );
    set_search("pile", (: TO, "search_pile" :) );
}

void reset() {
    ::reset();
    if(!present("slave")) {
	new( MPATH "slv")->move(TO);
	new( MPATH "slv")->move(TO);
    }
    searched = 0;
}

void search_pile(string str) {
   if(searched) {
     write("It looks like someone searched here recently.");
     return;
   }
   if(!random(3)) {
      write("All you find this time is the wet and moldy straw.");
      tell_room(ETP,TPQCN+" searches the pile of straw and looks disappointed.", TP);
      searched = 1;
      return;
   }
   RANDSTUFF->find_stuff(TO,"random");
   write("You find stuff the slaves probably hid here somehow.\n");
   tell_room(ETP,TPQCN+" finds something in the pile of straw.", TP);
   searched = 1;
   return;
} 

