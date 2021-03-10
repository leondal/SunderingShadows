#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_short("A branch of Aketon");
   set_long("%^GREEN%^A branch of Aketon%^RESET%^\n"+
   "This large branch is an offshoot of the main trunk of the tree,"+
   " which is directly south of here. This is a fairly wide avenue"+
   " that has many leaves along the edges, concealing exactly how"+
   " high up you truly are. This path comes to an end in front of"+
   " three elven homes. On the northwest is a door that has been"+
   " painted yellow, directly north is a hickory door, and on the"+
   " northeast is an ash wood door.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city in the distance.");
   set_door("yellow door",RPATH3+"3two2","northwest",0);
   set_door("hickory door",RPATH3+"3two3","north",0);
   set_door("ash door",RPATH3+"3two4","northeast",0);
   set_exits( (["north":RPATH3+"3two3",
      "northeast":RPATH3+"3two4",
      "south":RPATH3+"3two1",
      "northwest":RPATH3+"3two2"]) );
}
