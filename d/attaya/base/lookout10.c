#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create()
{
  ::create();
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("Main hall inside the South Wall Fortress.");
   set_long("
    The dust hangs heavy in the air in here.  The dark, gloomy, undecorated tunnel better fits the Kinnesaruda than the magnificent tower!
    The cobwebs in here form natural tapestries.  The bricks are old, cracked, and worn, and there is a shriveled black mass of rot and decay on the floor at your feet...  It used to be a carpet!
    A rusty metal gate stands here.  Beyond it, the great hall stretches as far away as all outdoors.

");
  set_listen("default", "Every sound carries on an echo and amplifies to sound menacing!");
  set_smell("default", "The air smells of mildew and decay.");
  set_items( ([
      "walls" : "The walls are falling apart.  Ancient bricks crack and strain under centuries of weight!",
      "mass" : "The rotting mass is all that remains of a once great carpet.",
      "carpet" : "The rotting mass is all that remains of a once great carpet.",
      "floor" : "The floor is filthy and a rotting black mass lies in fragments all over the place.",
       "outposts" : "They are small shacks with pointy wooden roofs.",
       "fortress" : "The fortress has been built into the southern wall of the crystalline tower.",
      "gate" : "The large metal gate is a remnant of the old fortress.",
]) );
  set_exits( ([
     "north" : "/d/attaya/base/lookout3",
     "west" : "/d/attaya/base/lookout9",
     "east" : "/d/attaya/base/lookout11",
]) );
set_pre_exit_functions( ({"north"}), ({"go_north"}) );
}
int go_north() {
if(present("knight")) {
write("The knight pushes you back!");
return 0;
}
else return 1;
}
void reset()
{
  ::reset();
if(!present("knight"))
     new("/d/attaya/mon/knight")->move(TO);
}
