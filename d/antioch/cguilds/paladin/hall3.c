#include <std.h>
inherit ROOM;

void create()
{
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("no teleport",1);
   set_property("light",3);
   set_short("%^BOLD%^Paladin's Hall%^RESET%^");
   set_long(
   "You are standing within the paladin guild hall in the Antioch palace."+
   " A %^BOLD%^%^BLUE%^royal blue%^RESET%^ rug stretches down the hallway."+
   " Oil lamps gilded with %^BOLD%^white gold%^RESET%^ line the walls,"+
   " shedding light on the area. There are several %^BOLD%^cushioned chairs%^RESET%^ here"+
   " and a %^BLUE%^large couch%^RESET%^ along the west wall. "+
   "To the east appears to be a"+
   " shop, and to the north you see an altar. Just north of the "+
   "couch along the west wall is an open doorway that leads to the "+
   "paladin stables. "
   );
   set_smell("default","The faint scent of vanilla is in the air.");
   set_listen("default","A respectful silence cloaks the room.");
   set_items(([
   "floor" : "The floor is covered in a fine rug that is %^BOLD%^%^BLUE%^"+
   " royal blue%^RESET%^ trimmed with %^BOLD%^white%^RESET%^.",
   ({"rug","blue rug","royal blue rug"}) : "%^BOLD%^%^BLUE%^The rug is a"+
   " rich royal blue with %^WHITE%^white%^BLUE%^ edges, it stretches down"+
   " the entire hallway.%^RESET%^",
   ({"wall","walls"}) : "Oil lamps line the walls here.",
   ({"oil lamps","lamps"}) : "%^BOLD%^%^WHITE%^The oil lamps are gilded"+
   " in white gold, they give off a steady light and a faint scent of vanilla.%^RESET%^",
   ({"chairs","cushioned chairs"}) : "There are two cushioned chairs on"+
   " either side of the eastern doorway. They are quite large and look"+
   " very comfortable. They are %^BOLD%^silver%^RESET%^ in color with"+
   " %^BOLD%^%^BLUE%^blue%^RESET%^ pin stripes.",
   ({"couch","large couch"}) : "%^BLUE%^There is a large couch along the"+
   " west wall that is a dark shade of blue. The wood is made of a darkly"+
   " stained chestnut that has been ornately worked into intricate patterns."+
   " It looks like it could seat four people comfortably, three if they were"+
   " all in full armor.",
   ]));
   set_exits(([
   "south" : "/d/antioch/cguilds/paladin/hall2",
     "west": "/d/antioch/cguilds/paladin/stable",
   "north" : "/d/antioch/cguilds/paladin/hall5",
   "east" : "/d/antioch/cguilds/paladin/hall4",
   ]));
}
