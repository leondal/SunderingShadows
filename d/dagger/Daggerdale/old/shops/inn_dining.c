#include <std.h>
inherit VAULT;

void create(){
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
set_door("door", "/d/dagger/Daggerdale/shops/inn_kitchen", "door", "silver key");
set_locked("door", 0);
set_open("door",1);
set_string("door","close", "The din of pots and pans banging together lessens.");
set_string("door","open", "The aromas of cooking assault your nostrils.");
set_property("light", 2);
set_property("indoors",1);
set_short("Druid's Inn dining room.");
  set("long",
@SIA
%^CYAN%^The dining room has a series of tables with green checked
cloths and four chairs drawn up to each table. The fireplace is laid with
tinder. A small door to the north leads to the kitchen.
SIA
);
set_smell("default", "You smell the faint aroma of lamb stew.");
set_listen("default", "You hear the stairs creaking softly.");
  set_items(([
"tables" : "There are eight over all, made from oak with vines and leaves engraved on the table legs.",
"door" : "It has grease marks over it.",
"chairs" : "Smooth polished wood with a high back which has a tree engraved in the center.",
"fireplace" : "Many weary travellors have warmed themselves while leaning against the bricks.",
"bricks" : "Earthy brown in color, they have a light covering of soot.",
"window" : "Frosted glass allows a soft light to enter.",
"room" : "Dark wood paneling adorns the walls.",
]));

  set_exits(([
"west" : "/d/dagger/Daggerdale/shops/inn",
"door" : "/d/dagger/Daggerdale/shops/inn_kitchen",
     ]));
}
