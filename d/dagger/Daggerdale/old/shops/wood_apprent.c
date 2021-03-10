#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
set_property("light", 2);
set_property("indoors",1);
set_short("Woodwright's");
  set("long",
@SIA
%^ORANGE%^This is a small and sparsely furnished apprentice's room.
The only furniture is a bed, an old woven rug, and a single hanging
lamp. The plain red-oak walls, scarcely show any hairline cracks where
the boards join. The polished red-oak floors, display the same 
care and crafting.
SIA
);
set_smell("default", "You smell sawdust and varnish.");
set_listen("default", "You hear the sound of a saw cutting wood.");
  set_items(([
"bed" : "Made from red-oak, a hand made quilt is folded neatly on the end.",
"rug" : "It's quite colorfull being made from scrapes of material.",
"lamp" : "Old and tarnished, the lamp is of dwarven design.",
]));

  set_exits(([
"stairs" : "/d/dagger/Daggerdale/shops/wood_back",
     ]));
}
