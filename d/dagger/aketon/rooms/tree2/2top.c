#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Watch tower");
   set_long("%^GREEN%^Watch tower%^RESET%^
You are on top of the huge tree now. You can see another even larger "
      "tree to the northeast. A steel cable extends from here up to the "
      "top of that tree. Another two towering trees can be seen to the "
      "east and north. They are about the same height as the one you are "
      "currently standing on. The Kilkean forest occupies a large part of the "
      "surrounding area. Mountain caves are northwest from here. Some strange "
      "dark fog covers the whole boggy marsh area at the west. The dwarven "
       "town of Kinaro is towards the southeast. Daggerdale occupies a "
       "large area in the southwest. The great Saakrune sea is to "
      "the east.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","Birds are singing.");
   set_exits( (["down":RPATH2+"2three1"]) );
}

void reset() {
   ::reset();
   if(!present("steel rack")) new(OPATH+"steel_rackx")->move(TO);
   if(!present("blue cable")) new(OPATH+"cable_swx")->move(TO);
   if(!present("standing guard")) {
      new(MPATH+"guardD")->move(TO);
      new(MPATH+"guardD")->move(TO);
   }
   if(!present("standing guard 2")) new(MPATH+"guardD")->move(TO);
}
