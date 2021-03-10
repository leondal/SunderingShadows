#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_short("A branch of Aketon");
   set_long("%^GREEN%^A branch of Aketon%^RESET%^\n"+
   "This large branch is an offshoot of the main trunk of the tree,"+
   " which is straight west of here. This is a fairly wide avenue"+
   " that has many leaves along the edges, concealing exactly how"+
   " high up you truly are. This path ends in front of two elven"+
   " homes. There is a door to the northeast with a sunburst carved"+
   " into the center of it. Directly east is a plain oak door.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city in the distance.");
   set_door("sunburst door",RPATH3+"3two8","northeast",0);
   set_door("oak door",RPATH3+"3two11","east","aketon key");
   set_locked("oak door",1);
   set_exits( (["northeast":RPATH3+"3two8",
      "east":RPATH3+"3two11",
      "west":RPATH3+"3two1"]) );
}
