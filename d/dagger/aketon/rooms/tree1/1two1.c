#include "/d/dagger/aketon/short.h"

inherit DAEMONROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Wide platform on the giant tree");
   set_long("%^GREEN%^Wide platform on the giant tree%^RESET%^
You are now on a higher level then the city below you. This place is "
      "obviously of higher importance then the lower level area from "
      "where you came. The platform is formed by the branching of the "
      "tree you are stepping on. There are broad ways leading into all "
      "different directions. As you peers around, you noticed that there "
      "are guards and archers everywhere on this level. This is the very "
      "center of the military of Aketon. Steps continue leading up and "
      "down the tree and there are guards patroling the whole level.");
   set_items( (["level":"This is the second level of this giant tree.",
      "brach":"This large branches of tree is where the city is built on.",
      "tree":"This is the tree beneath your feet and where the city of "
      "Aketon is.",
      "guards":"You can see guards everywhere at every direction.",
      "archers":"These guards are equipped with bows and arrows.",
      "steps":"There are more levels above and below is down town area.",
      "ways":"These broad ways leading into all directions."]) );
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear soldiers yelling from barracks nearby.");
   set_exits( (["up":RPATH1+"1step5",
      "down":RPATH1+"1step4",
      "north":RPATH1+"1two17",
      "northeast":RPATH1+"1two18",
      "east":RPATH1+"1two24",
      "southeast":RPATH1+"1two31",
      "south":RPATH1+"1two30",
      "southwest":RPATH1+"1two29",
      "west":RPATH1+"1two23",
      "northwest":RPATH1+"1two16"]) );
}

void reset() {
   ::reset();
   if(!present("standing guard")) {
      new(MPATH+"guardD")->move(TO);
      new(MPATH+"guardD")->move(TO);
   }
   else if(!present("standing guard 2"))
      new(MPATH+"guardD")->move(TO);
   else
      return;
}
