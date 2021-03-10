#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Bedroom upon the tree");
   set_long("%^GREEN%^Bedroom upon the tree%^RESET%^
This is a large bedroom with just a few ordinary decorations. Only a few pieces of "
      "furniture are here. A bed made from maple wood sits quietly in "
      "the center of the room. A large mirror is near the window. Some "
      "stools are randomly placed in the room. A multi-drawer cabinet is "
       "at the far end of the room. The floor in front of the "
       "bed is covered with a sheet of tiger skin.");
   set_items( (["room":"A large room with ordinary decorations.",
      "furnitures":"Some wooden furnitures.",
      "bed":"A large bed made of maple wood.",
      "mirror":"You see your own reflection in it.",
      "cabinet":"Looks like the occupant of this room use it to store "
      "things.",
      "floor":"There is a sheet of tiger skin.",
      "stools":"Ordinary stools placed orderlessly around the room.",
      ({"skin","sheet"}):"A large sheet of tiger skin."]) );
   set_smell("default","You smell incense within the room.");
   set_listen("default","It is quiet here.");
   set_exits( (["north":RPATH1+"1three17",
      "west":RPATH1+"1three20"]) );
}

void reset() {
   ::reset();
   if(sizeof(children(MPATH+"shawdor")) > 1)
      return;
   new(MPATH+"shawdor")->move(TO);
}
