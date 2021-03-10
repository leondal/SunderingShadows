#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_short("A branch of Aketon");
   set_long("%^GREEN%^A branch of Aketon%^RESET%^\n"+
   "This branch has split off from the main trunk and has a tendency"+
   " to curl around instead of remain straight. It leads further into"+
   " the residential section of Aketon and the first house on this path"+
   " is directly to the north. You see a large oak door that typically"+
   " remains shut against intruders. To the southwest this branch"+
   " meets back with the main part of the tree, and to the east it"+
   " continues further into the elven homes.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city all around you.");
   set_door("door",RPATH3+"3one7","north",0);
   set_exits( (["north":RPATH3+"3one7",
      "east":RPATH3+"3one14",
      "southwest":RPATH3+"3one18"]) );
}
