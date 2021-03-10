#include <std.h>
inherit "/std/room";

void create() {
   ::create();
   set_property("indoors", 0);
   set_property("light", 1);
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
   set("short", "A path through the forest");
   set("long",
      "%^RESET%^%^GREEN%^Green grass reaches up past your ankles and stretches through"+
      " every part of the path through this magnificent forest. There are several tall"+ 
      " oak trees running along the edge of the path. Wind blows through their branches,"+
      " making them sway. Rabbits and other small animals scamper about in the grass. Bright"+
      " colored butterflies float around in the wind. As you peer into the forest you"+
      " can see that nature is virtually untouched here.%^RESET%^"
   );
   set_smell("default","%^RESET%^%^ORANGE%^The scent of plants and tree bark surround you.%^RESET%^");
   set_listen("default","%^RESET%^%^CYAN%^You hear birds singing and fluttering of wings.%^RESET%^");
   set_items( ([
   "path":"The path here is quite narrow and covered in knee high grass.", 
   "grass":"The grass here is bright green and is rather high, perfect for small animals.", 
   "trees":"These magnificent oak trees are taller than average and stand firmly, with deep roots." 
   ]) );
}
