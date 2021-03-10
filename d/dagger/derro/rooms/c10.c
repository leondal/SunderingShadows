#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_short( "%^RED%^Naturally formed lava cavern.%^RESET%^"  );
  set_long(
  "%^RED%^Naturally formed lava cavern.%^RESET%^\n"
  "  This cavern continues down to the east and up to the southwest where is might be blessedly cooler than this oven you're in."
  "  Pools of lava skirt a raised path that leads east but it's covered with the bodies of fire giants."
  "  You can see where the giants must have been fighting something and were driven back."
  "  Some of the massive corpses that must weigh in at 7500 pounds have been thrown clear across the room impacting with the west wall."
  "  You wonder if it's such a good idea to continue on to the east to see what they were fighting.\n"
  );
  set_smell("default", "Sulfur burns at your lungs."  );
  set_listen("default", "You can hear but the wind echoing far off."  );
  set_items(([
  "corpses":"The corpses of many fallen firegiants.  Broken limbs splay out at weird angles and the lips are pulled back in grimaces - battered, burned and chewed.",
  "floor":"The floor is natural obsidian, volcanic glass that is arrayed in natural swirls and patterns that are pleasing to the eye although hard on the footwear.  Blood flows everywhere on it, making the smooth glass treacherous.",
  "ceiling":"It curves over your head in almost a perfect semicircle.  It's all polished black volcanic glass.",

  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_exits(([
  "east":ROOMS"c15",
  "southwest":ROOMS"c6",
  ]));
}
