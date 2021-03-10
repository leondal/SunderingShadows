#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_short("A branch of Aketon");
   set_long("%^GREEN%^A branch of Aketon%^RESET%^\n"+
   "This branch splits off from the main trunk, but the pathway comes to"+
   " an end here. There are several doors here that lead to the elven"+
   " houses. To the northwest is a golden door, to the west is a green"+
   " door, to the southwest is a door made of cedar wood, and to the"+
   " south is a pine door. Not all elves take kindly to strangers,"+
   " most consider it rude to intrude on their home without an"+
   " invitation.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city all around you.");
   set_items(([
   "golden door" : "%^YELLOW%^The door has been painted a beautiful golden"+
   " color, unlike some of the tackier human paints, this is truly beautiful."+
   " It is a pale gold and it sparkles in the light, as though there are"+
   " flecks of gold within it...which there probably are.%^RESET%^",
   "green door" : "%^GREEN%^The door to the west is painted a green that"+
   " exactly matches the surrounding leaves on the branches.%^RESET%^",
   "cedar door" : "The cedar door is to the southwest and it has been"+
   " varnished and darkly stained. The swirling colors of the wood stand"+
   " out magnificently.",
   "pine door" : "The door directly south is made of a solid piece of pine"+
   " wood that is of a very light color. It contrasts nicely with the color"+
   " of the branches and tends to stand out.",
   ]));
   set_door("golden door",RPATH3+"3one23","northwest",0);
   set_door("green door",RPATH3+"3one29","west",0);
   set_door("cedar door",RPATH3+"3one34","southwest",0);
   set_door("pine door",RPATH3+"3one35","south",0);
   set_exits( (["northeast":RPATH3+"3one1",
      "south":RPATH3+"3one35",
      "southwest":RPATH3+"3one34",
      "west":RPATH3+"3one29",
      "northwest":RPATH3+"3one23"]) );
}
