#include <std.h>
#include "../tormdefs.h"
inherit HEALER;
void create()
  {
  ::create();
   set_travel(DIRT_ROAD);
   set_terrain(WOOD_BUILDING);
    set_short("Torm's clinic");
  set_property("light",2);
  set_property("indoors",1);
  set_long(
    "Torm's clinic\n"+
    "%^BOLD%^%^WHITE%^The pristine white room here is well-cared "+
    "for, being kept spotless from dirt or grime.  %^YELLOW%^Beds"+
    "%^WHITE%^ are set up around the room, allowing patients to "+
    "recover with some comfort.  Pojo, the Master Healer of Torm, "+
    "and his crew work hard to keep the place clean and tending "+
    "to the injuries of anyone under their care.  %^GREEN%^Herbal "+
    "mixtures%^WHITE%^ and %^GREEN%^plants%^WHITE%^ are about the "+
    "room, always on hand for the next person who enters.  A few "+
    "soldiers from the Dagger army seem to occupy a couple of cots, "+
    "showing the reach that Pojo has in this area.\n"
  );
   set_smell("default","The clinic smells of astringents and herbs.");
    set_listen("default","You can hear the groans of some of the patients.");
   set_items(([
   "beds" : "There are several beds in this room, most of which are taken up by groaning soldiers. All the beds are cleanly dressed in white linen to help prevent transference of disease.",
   "floor" : "The floor is kept immaculately clean.",
   "herbs" : "There is a shelf of herbs in one corner of the room, it has many different types on it, some fresh and some dried.",
   ]));
  set_name("pojo");
  set_exits(([
  "west":TCITY+"c33",
  ]));
}
void reset(){
  ::reset();
  if(!present("pojo")) new(MON+"healer")->move(TO);
  set_name("pojo");
  if(!present("guard")) new(MON+"guardin")->move(TO);
}
