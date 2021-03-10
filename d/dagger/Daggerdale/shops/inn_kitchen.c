#include <std.h>
inherit VAULT;

void init() {
::init();
add_action("pet","pet");
}
void create(){
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
set_door("door", "/d/dagger/Daggerdale/shops/inn_dining", "door", "silver key");
set_locked("door", 0);
set_open("door", 1);
set_string("door","close", "The din of pots and pans banging together lessens.");
set_string("door","open", "The door opens with a creak.");
set_property("light", 2);
set_property("indoors",1);
set_short("Druid's Inn kitchen.");
  set("long",
@SIA
%^CYAN%^Tantalizing smells waft up from the pots simmering on
the wooden stove. The table in the center of the room has
all kinds of vegetables, waiting to be cooked. Pots and pans
hang from hooks in the ceiling, a hutch to the right holds
cutlery and crockery. A tabby cat waits patiently under the table
for food scraps.
SIA
);
set_smell("default", "You smell the faint aroma of lamb stew.");
set_listen("default", "You hear the stairs creaking softly.");
  set_items(([
"pots" : "They are covered in dents and have black bases from being used on the wooden stove.",
"table" : "It has scratch marks where the cook has been chopping things.",
"hutch" : "It has two doors with drawers at the bottom and shelves at the top.",
"cat" : "He is very fat and he loves anyone who pets him.",
]));

  set_exits(([
"door" : "/d/dagger/Daggerdale/shops/inn_dining",
     ]));
}
int pet(string str) {
if (str != "cat") {
notify_fail("Pet who?\n");
return 0;
}
write("%^YELLOW%^The tabby purrs as you pet him.");
say("%^YELLOW%^The tabby purrs as you pet him.");
return 1;
}
