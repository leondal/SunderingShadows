#include <std.h>;
inherit ROOM;

void create() {
   ::create();
   set_name("Post office storage");
   set_short("Post office storage");
   set_long("Storage room for Darol'dralych post office.");
   remove_property("no teleport");
   set_property("no teleport", 1);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_no_clean(1);
   set_storage(1);
   restore_room();
}