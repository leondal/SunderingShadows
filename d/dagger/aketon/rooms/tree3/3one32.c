#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_short("A branch of Aketon");
   set_long("%^GREEN%^A branch of Aketon%^RESET%^\n"+
   "You are traveling on a fair sized branch that is the offshoot of"+
   " a larger branch that makes up the Avenue Magiciana to the west."+
   " This branch splits off to the northeast where there is a wooden"+
   " door, as well as to the southeast where there hangs a mottled"+
   " green curtain.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city all around you.");
   set_items(([
   ({"wooden door","door"}) : "There is a large door to the northeast"+
   " that leads into an elven home.",
   ({"curtain","green curtain","mottled curtain","mottled green curtain"}) : "%^GREEN%^There"+
   " is a curtain that hangs over the southeast doorway. It is a mottled"+
   " green and blends in well with the leaves.",
   ]));
   set_door("door",RPATH3+"3one25","northeast",0);
   set_exits( (["northeast":RPATH3+"3one25",
      "southeast":RPATH3+"3one37",
      "west":RPATH3+"3one31"]) );
}
