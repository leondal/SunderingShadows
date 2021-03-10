#include <std.h>;
#include "../piratedefs.h"
inherit ROOM;

void create() {
   ::create();
   set_name("The Treasure Chest repair storage");
   set_short("The Treasure Chest repair shop storage");
   set_long("Storage room for The Treasure Chest.");
   remove_property("no teleport");
   set_property("no teleport", 1);
   set_no_clean(1);
   set_storage(1);
   restore_room();
}