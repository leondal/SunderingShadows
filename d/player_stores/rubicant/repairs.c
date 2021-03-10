#include <std.h>;

inherit ROOM;

void create() {
   ::create();
   set_name("Rubicant repair storage");
   set_short("Rubicant's repair storage");
   set_long("Storage room for items to repair.");
   remove_property("no teleport");
   set_property("no teleport", 1);
   set_no_clean(1);
   set_storage(1);
   restore_room();
}
