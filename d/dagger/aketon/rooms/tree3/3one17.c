#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_short("Avenue of Magiciana");
   set_long("%^GREEN%^Avenue of Magiciana%^RESET%^\n"+
   "You are walking on one of the main broad avenues of the city of"+
   " Aketon. This branch stretches out to the northwest, which leads"+
   " to another tree, and to the southeast, which leads further into"+
   " the residential section of Aketon. To the west you can see a"+
   " balcony of sorts and to the north is someone's home.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city all around you.");
   set_door("door",RPATH3+"3one12","north",0);
   set_exits( (["north":RPATH3+"3one12",
      "southeast":RPATH3+"3one1",
      "west":RPATH3+"3one16",
      "northwest":RPATH3+"3one11"]) );
}
