// /d/guilds/raiders/hall/main.c

#include <std.h>

inherit VAULT;
//inherit ROOM;

void create(){
   	object ob;

   	::create();
   set_terrain(BUILT_CAVE);
   set_travel(PAVED_ROAD);
   	set_indoors(1);
   	set_light(1);
   	set_short("Meeting hall");
   	set_long(
@DESC
Shadows dance off the stone surfaces around you as the fire from the
fireplace dances behind its iron grate. A large bulletin board is mounted on
the north wall with various notes on it. The stone floor here is covered
with a diamond shaped carpet.  Several wooden chairs which look to have been
taken from the members room have been moved here and are scattered around
the board.
DESC
   	);
   	set_smell("default","The smell of damp mildew can be detected in the air.");
   	set_listen("default","Your footsteps echo around the room as your feet "+
   		"hit the cold hard floor.");

    	set_door("iron door","/d/guilds/raiders/hall/hallway.c","south","guild earring");
    	set_door_description("iron door","This is a heavy iron door barring passage into "+
    		"the southern exit.  The door looks relatively new, the whole thing is "+
    		"nice and shiny, the hinges are on this side.  There is one "+
    		"lock visible.");
    	set_string("iron door","open","The door swings open to the next room.");

   	set_exits(([
      	"south":"/d/guilds/raiders/hall/hallway.c",
   	]));
   	ob = new("std/bboard");
   	ob->set_name("board");
   	ob->set_id( ({ "board", "posting board", "raiders board" }) );
   	ob->set_board_id("raiders_board");
   	ob->set("short", "Posting board of the Raiders in Night's Cloak");
   	ob->set("long", "A board for the members of the Raiders to share news of "+
   		"the lands.\n");
   	ob->set_max_posts(30);
   	ob->set_location("/d/guilds/raiders/hall/main.c");
}
