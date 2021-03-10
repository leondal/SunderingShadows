#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_short("The porch of an elven home");
   set_long("%^GREEN%^The porch of an elven home%^RESET%^\n"+
   "You have walked out onto the porch high in the tree tops of"+
   " Aketon. There are several branches above and to the sides of"+
   " you that provide a lot of shade and some protection against"+
   " the weather. The branches block the view of everywhere but"+
   " to the east, making this a nice and secluded spot. This is a"+
   " perfect place for watching the sun rise above the mountains."+
   " There are no railings here, and if you look over the edge it is"+
   " quite a long ways down to the ground! There is a rocking chair"+
   " near the door that appears well worn.");
   set("night long",
   "You have walked out onto the porch high in the tree tops of"+
   " Aketon. There are several branches above and to the sides of"+
   " you that give the place a nice sense of seclusion and provide"+
   " some protection against the weather. The branches block the view"+
   " of everywhere but to the east, and you can make out a mountain"+
   " range in the distance past the tree tops. You can barely see"+
   " the moon and stars above through the thick canopy. There are no"+
   " railings here, and if you look over the edge it is quite a long"+
   " ways down to the ground! There is a rocking chair near the door"+
   " that appears well worn.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","The wind whispers through the leaves.");
   set_items(([
   ({"branches","leaves"}) : "The branches and leaves surround this"+
   " spot, blocking out the view to the north and south and providing"+
   " protection from the elements from above. The only clear direction"+
   " is east.",
   ({"chair","rocking chair"}) : "There is a rocking chair that is"+
   " back near the door. It looks fairly comfortable and  you can"+
   " see that the arms are well worn.",
   ]));
   set_door("door",RPATH3+"3two8","west",0);
   set_exits( (["west":RPATH3+"3two8"]) );
}
