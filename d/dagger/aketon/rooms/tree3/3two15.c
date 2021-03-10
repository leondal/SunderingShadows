#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("A branch of Aketon");
   set_long("%^GREEN%^A branch of Aketon%^RESET%^\n"+
   "This large branch is an offshoot of the main trunk of the tree,"+
   " which is just to the northwest. It is a fairly wide avenue"+
   " that has many leaves along the edges, concealing exactly how"+
   " high up you truly are. To the southeast appears to be a balcony"+
   " and gathering place of the elves.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city in the distance.");
   set_exits( (["southeast":RPATH3+"3two20",
      "northwest":RPATH3+"3two1"]) );
}
