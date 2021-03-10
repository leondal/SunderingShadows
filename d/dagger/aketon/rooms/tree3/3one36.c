#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_short("A branch of Aketon");
   set_long("%^GREEN%^A branch of Aketon%^RESET%^\n"+
   "You are traveling on a very large branch that has a smaller offshoot"+
   " to the southeast, where there is an elven home with a door."+
   " Straight south is a large pair of double doors that are the entrance"+
   " to another elven home. To the north is the start of the Avenue"+
   " Magiciana.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city all around you.");
   set_items(([
   ({"doors","double doors"}) : "There is a large pair of double doors"+
   " directly south of here that lead into an elven home.",
   "door" : "There is a door to the southeast that is made out of solid"+
   " oak. Carved into the wood is a large and detailed tree.",
   ]));
   set_door("double doors",RPATH3+"3one40","south",0);
   set_door("door",RPATH3+"3one41","southeast",0);
   set_exits( (["north":RPATH3+"3one31",
      "southeast":RPATH3+"3one41",
      "south":RPATH3+"3one40"]) );
}
