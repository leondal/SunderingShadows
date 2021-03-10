// special storage room for the Tabor post office
// by Circe, 1/2/2005

#include <std.h>;

inherit ROOM;

void create() {
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_name("message service storage");
   set_short("Tabor Message Service storage");
   set_long("A storage room and you shouldn't be here.");
   remove_property("no teleport");
   set_property("no teleport", 1);
   set_no_clean(1);
   set_storage(1);
   restore_room();
}