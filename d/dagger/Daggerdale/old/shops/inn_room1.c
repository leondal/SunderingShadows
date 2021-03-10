#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
set_property("light", 2);
set_property("indoors",1);
set_short("Druid's Inn guest room.");
set_long(
  "%^CYAN%^You are in a plain room in the hotel.  In this room stands a simple dresser with a mirror over it, and a bed in the one corner.  You can see out to the square in town through the one window.  Against the one wall is a strange looking wardrobe.  It seems to be built into the wall.  You also think you can see some light coming through the crack between the two doors."
);
set_smell("default", "You smell the sweet scent of nature.");
set_listen("default", "You hear a soft tread in the hallway.");
  set_items(([
"mirror" : "You only see your reflection!",
"bed" : "The feather mattress is slightly lumpy but still very comfortable.",
"planks" : "Many weary travellors have walked these floors.",
"room" : "Dark wood paneling adorns the walls.",
"wardrobe" : "The small wardrobe is made from red oak, the door is trimmined with gold oak.",
"door" : "Engraved with vines and leaves around the edge, the door is not locked.",
]));

  set_exits(([
"hall" : "/d/dagger/Daggerdale/shops/inn_hall1",
     ]));
}
void init() {
:: init();
add_action("open","open"); }
int open(string str){
if ( (str == "door") || (str == "wardrobe") ) {
tell_object(this_player(), "The door opens silently.");
say(""+this_player()->query_cap_name()+"
opens the wardrobe door.");
add_exit("/d/dagger/Daggerdale/shops/inn_ward", "wardrobe");
}
return 1;
}
