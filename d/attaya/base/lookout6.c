#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create()
{
  ::create();
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("Main hall inside the South Wall Fortress.");
   set_long("
    The main passage continues to the west and east.  A few chains hang from the wall opposite the doorway.  Shackles grace the ends and you can invision the tormented here awaiting final verdict from someone in the room before you.
    The dust in the air here seems to move in ghostly waves, as if it had intelligence itself.

");
  set_listen("default", "Every sound carries on an echo and amplifies to sound menacing!");
  set_smell("default", "The air smells of mildew and decay.");
  set_items( ([
      "walls" : "The walls are falling apart.  Ancient bricks crack and strain under centuries of weight!",
      "mass" : "The rotting mass is all that remains of a once great carpet.",
      "carpet" : "The rotting mass is all that remains of a once great carpet.",
      "floor" : "The floor is filthy and a rotting black mass lies in fragments all over the place.",
        "doorway" : "The doorway is of standard size and height.  A darkened room lies beyond.",
       "fortress" : "The fortress has been built into the southern wall of the crystalline tower.",
]) );
   set_exits( ([
   "west" : "/d/attaya/base/lookout5",
     "east" : "/d/attaya/base/lookout7",
]) );
}

void reset()
{
  ::reset();
if(!present("knight"))
     new("/d/attaya/mon/knight")->move(TO);
if(!present("warrior"))
     new("/d/attaya/mon/uwarrior")->move(TO);
}
