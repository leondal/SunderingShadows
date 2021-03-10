#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_short("A branch of Aketon");
   set_long("%^GREEN%^A branch of Aketon%^RESET%^\n"+
   "This large branch is an offshoot of the main trunk of the tree,"+
   " which is straight north of here. This is a fairly wide avenue"+
   " that has many leaves along the edges, concealing exactly how"+
   " high up you truly are. This path ends in front of two elven"+
   " homes. There is a door to the southwest that has a rainbow"+
   " painted on the front of it. Directly south is a redwood door.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city in the distance.");
   set_door("rainbow door",RPATH3+"3two18","southwest",0);
   set_door("redwood door",RPATH3+"3two19","south","kaarells_key");
   set_locked("redwood door",1);
   set_exits( (["north":RPATH3+"3two1",
      "south":RPATH3+"3two19",
      "southwest":RPATH3+"3two18"]) );
}
