#include <std.h>
#include "../keep.h"
inherit TOWERI2;

void create() {
	::create();
	set_exits(([ "down" : KEEPR + "towerE1", "door" : KEEPR + "dungeon29" ] ));
	set_door("rusty door",KEEPR + "dungeon29", "door","blacktongue master key","lock");
	set_string("rusty door", "open", RD_OPEN_DESC);
	set_locked("rusty door",1,"lock");
	lock_difficulty("rusty door",1,"lock");
	set_door_description("rusty door",RD_DESC);
	
}


