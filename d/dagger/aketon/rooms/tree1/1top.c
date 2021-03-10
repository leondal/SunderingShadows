#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("On top of the giant tree");
   set_long("%^GREEN%^On top of the giant tree%^RESET%^
As you step through the last portion of the long steps leading you up to "
      "the city, you have finally reached the top of this giant tree. The "
      "view here is great and you can see the whole Dagger area. Four "
      "other shorter trees surrounds you. The dwarven town of Kinaro is "
       "towards the southeast. Daggerdale occupies a large area in the "
       "southwestern area. Mountain caves are northwest from here. Some "
      "strange dark fog covers the whole boggy marsh area to the west. "
      "Some cables extends down to the four surrounding trees from here.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","It is quiet here.");
   set_exits( (["down":RPATH1+"1five1"]) );
}

void reset() {
   ::reset();
   if(!present("steel rack")) new(OPATH+"steel_rack")->move(TO);
   if(!present("red cable")) new(OPATH+"cable_ne")->move(TO);
   if(!present("white cable")) new(OPATH+"cable_nw")->move(TO);
   if(!present("green cable")) new(OPATH+"cable_se")->move(TO);
   if(!present("blue cable")) new(OPATH+"cable_sw")->move(TO);
   if(!present("standing guard")) {
      new(MPATH+"guardD")->move(TO);
      new(MPATH+"guardD")->move(TO);
   }
   if(!present("standing guard 2")) new(MPATH+"guardD")->move(TO);
}
