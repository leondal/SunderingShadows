#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_short("A branch of Aketon");
   set_long("%^GREEN%^A branch of Aketon%^RESET%^\n"+
   "This branch is an offshoot from the main trunk has curled around"+
   " to come to an end near here. There is a branch to the northeast"+
   " that leads to a balcony area. Directly north is a door with a"+
   " brightly colored humming bird painted on the front. To the"+
   " southeast is another door to an elven home. To the west the"+
   " branch curves around to eventually meet with the main trunk.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city all around you.");
   set_door("painted door",RPATH3+"3one8","north",0);
   set_door("door",RPATH3+"3one20","southeast",0);
   set_exits( (["north":RPATH3+"3one8",
      "northeast":RPATH3+"3one9",
      "southeast":RPATH3+"3one20",
      "west":RPATH3+"3one13"]) );
}
