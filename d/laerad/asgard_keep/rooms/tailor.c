// Coded by ~Circe~ for Asgard Keep 8/14/15

#include <std.h>
#include "/d/laerad/laerad.h"

inherit ROOM;

void create(){
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_property("light", 3);
   set_name("The Golden Needle East");
   set_short("The Golden Needle East");
   set_long("%^YELLOW%^The Golden Needle East%^RESET%^\n"+
      "This will be the tailor - run by a halfling named Philomena, who "
      "looks strangely like Mina in Antioch. They have a business arrangement. Possibly.\n");
   set_smell("default","The scent of sulfur is masked here by the fragrant "
      "flowers in vases placed around the room.");
   set_listen("default","The snip of scissors and the chatter of customers provides "
      "a soft backdrop to the occasional clang from the forge.");
   set_items(([
      "stuff" : "This will be stuff."
   ]));
   set_exits(([
      "south" : KEEP"hallway2"
   ]));
}
