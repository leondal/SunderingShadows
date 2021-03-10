#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_short("Avenue of Magiciana");
   set_long("%^GREEN%^Avenue of Magiciana%^RESET%^\n"+
   "You are walking on one of the main broad avenues of the city of"+
   " Aketon. To the northwest the branch of this tree connects with"+
   " that of an adjacent tree. To the southeast the avenue continues"+
   " to the center of the residential section. To the west is a"+
   " chestnut door and to the northeast is a maple door.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city all around you.");
   set_door("chestnut door",RPATH3+"3one10","west",0);
   set_door("maple door",RPATH3+"3one5","northeast",0);
   set_exits( (["northeast":RPATH3+"3one5",
      "southeast":RPATH3+"3one17",
      "west":RPATH3+"3one10",
      "northwest":RPATH3+"3one4"]) );
}
