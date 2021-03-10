#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "This room is rather bare, even compared to the one you just left."+
   " Most of the north wall has a large rectangular opening in it"+
   " to allow the breeze through, but there is no protective glass."+
   " The window is almost a foot thick and you notice an overhang of the"+
   " roof on the other side, so it probably prevents most of the rain"+
   " and other bad weather from getting in. There is a small oak desk"+
   " in the southeastern corner that has sketches for a few possible"+
   " metal work projects on it. In the northwest corner is hung a"+
   " large hammock that looks fairly comfortable.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","The wind rustles through the leaves oustide.");
   set_items(([
   ({"north wall","opening"}) : "There is a large rectangular opening"+
   " in the north wall. The wall there is almost a foot thick, and"+
   " while it lets the light and breeze in, the overhanging roof keeps"+
   " the bad weather out.",
   ({"desk","oak desk"}) : "There is a small oak desk tucked into the"+
   " southeastern corner. A simple wooden chair sits next to it and"+
   " there are several sketches of possible metal working projects"+
   " drawn on paper scattered about the top.",
   "chair" : "A simple wooden chair rests near the oak desk.",
   ({"sketches","paper"}) : "There are several sketches of possible"+
   " metal work projects done on paper and scattered about the top of"+
   " the desk. You see a sea horse, a frog, and a dragonfly as possible"+
   " works of art.",
   ({"hammock","large hammock"}) : "There is a large hammock made out"+
   " of strong hemp mixed with cotton for comfort. It could comfortably"+
   " fit two elves, but is probably just used by one. It is attached"+
   " to two walls and allows the person inside to sway back and forth.",
   ]));
   set_exits( (["south":RPATH3+"3one8"]) );
}
