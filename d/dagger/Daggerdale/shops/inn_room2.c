#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
set_property("light", 2);
set_property("indoors",1);
set_short("Druid's Inn guest room.");
  set("long",
@SIA
%^CYAN%^This is one of the many rooms the Inn boasts. There is a double
bed, a low three-drawer red-oak dresser topped with an oak-framed mirror,
a washbasin table with towels and a wardrobe. A braided rag rug covers
the wide and polished gold-oak planks from next to the bed to just before.
the dresser. The single window is closed, flanked by cheerful green
checkered curtains which are tied back with white cords. A lamp over
the low headboard lights the room. The bed is covered with a handmade green
quilt showing a pattern of green and white snowflakes.
SIA
);
set_smell("default", "You smell the sweet scent of nature.");
set_listen("default", "You hear a soft tread in the hallway.");
  set_items(([
"mirror" : "You only see your reflection!",
"bed" : "The feather mattress is slightly lumpy but still very comfortable.",
"planks" : "Many weary travellors have walked these floors.",
"room" : "Dark wood paneling adorns the walls.",
"wardrobe" : "Small but adequate to hold one pack.",
]));

  set_exits(([
"hall" : "/d/dagger/Daggerdale/shops/inn_hall2",
     ]));
}
