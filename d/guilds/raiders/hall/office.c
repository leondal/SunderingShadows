// /d/guilds/raiders/hall/office.c

#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_terrain(BUILT_CAVE);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_light(0);
   set_short("Leader's Office");
   set_long(
@DESC
The light in this room is almost non-existant. The stone walls
here are covered with various thieves tools, valuable paintings, 
and weapons. In the center of the room there is a small oak desk 
with cut gems and papers scattered on its surface. A painting 
hangs over the desk. Pushed against the west wall is a bookcase 
full of dusty antique volumes. A wine rack full of Underdark wine 
sits against the bare stone wall to the north.
DESC
   );
   set_smell("default","The smell of damp mildew can be detected in the air.");
   set_listen("default","Your footsteps echo around the room as your feet hit the cold hard floor.");
   set_exits(([
      "east":"/d/guilds/raiders/hall/members.c",
   ]));
   set_items(([
   ]));
}
