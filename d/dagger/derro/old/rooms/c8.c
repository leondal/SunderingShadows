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
  set_short(   "%^RED%^Fire giant king's room%^RESET%^"  );
  set_long(
   "%^RED%^Fire giant king's room.%^RESET%^\n"
   "  This room is richly decorated in filth.  Everything here is caked with grime from the furnishings to the walls."
   "  A massive bed lies past a curtain and there is a throne here as well as weapon racks and trophies from old conquests."
   "  Much of the contents have been destroyed in some creature's fit of rage."
  "\n"
  );
  set_smell("default",  "You smell death."  );
  set_listen("default",
  "You can hear nothing here but the sound of the warm wind as it swirls about."
  );
  set_items(([
  "floor":"The floor looks carved from the bedrock of the mountains.",
  "walls":"Carved from the roots of the world with a careful eye and a strong arm.",

  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
   "bed":"25 feet long and covered with hides and ragged cloth.  It's crawling with lice and other pests and smells as if something is dead and rotting between its covers.",
  "throne":"Crudely carved of stone it can hardly be called a throne except when the massive king himself sits on it.",
  "weapon racks":"Empty and dusty from disuse.  Seems he carries all his weapons with him.",
  "racks":"Empty and dusty from disuse.  Seems he carries all his weapons with him.",
  "trophies":"Skeletal heads and those limbs that still hold a little rotting flesh adorn the walls beside battered armor and weapons from fallen foes.",
  "weapons":"Battered to uselessness",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_exits(([
  "northeast":ROOMS"c7",
  ]));
}
void reset(){
  ::reset();
  if(!present("king")){
  new(MON"fireking.c")->move(this_object());
  }
}
