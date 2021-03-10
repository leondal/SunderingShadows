#include <std.h>
inherit ROOM;

void create()
{
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_property("indoors",1);
   set_property("no teleport",1);
   set_property("light",3);
   set_short("%^BOLD%^Paladin's Hall%^RESET%^");
   set_long(
   "You are standing in a shop within the guild hall of the paladins in the"+
   " palace of Antioch. Those paladins who have chosen to dedicate their"+ 
   " services to the city may come here and purchase the equipment of the"+
   " Antioch guards if they so choose. The shop itself is quite nice and"+
   " well kept, with a mahogany counter in the center of the room and the"+
   " equipment kept in neat racks along the back wall."
   );
   set_smell("default","The faint scent of vanilla is in the air.");
   set_listen("default","A respectful silence cloaks the room.");
   set_items(([
   "floor" : "The floor is covered in a fine rug that is %^BOLD%^%^BLUE%^"+
   " royal blue%^RESET%^ trimmed with %^BOLD%^white%^RESET%^.",
   ({"rug","blue rug","royal blue rug"}) : "%^BOLD%^%^BLUE%^The rug is a"+
   " rich royal blue with %^WHITE%^white%^BLUE%^ edges, it stretches down"+
   " the entire hallway.%^RESET%^",
   ({"wall","walls"}) : "Oil lamps line the walls here and there are racks"+
   " of equipment along the back wall.",
   ({"oil lamps","lamps"}) : "%^BOLD%^%^WHITE%^The oil lamps are gilded"+
   " in white gold, they give off a steady light and a faint scent of vanilla.%^RESET%^",
   "counter" : "There is a large mahogany counter in the center of the room.",
   ({"racks","neat racks"}) : "There are neatly ordered racks of equipment"+
   " along the back wall, displaying the armor of the Antioch guard.",
   ]));
   set_exits(([
   "west" : "/d/antioch/cguilds/paladin/hall3",
   ]));
}

void reset()
{
   ::reset();
   if(!present("liennor")) {
      new("/d/antioch/cguilds/paladin/liennor")->move(TO);
   }
}
