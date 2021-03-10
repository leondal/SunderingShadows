#include <std.h>
#include "../keep.h"

inherit CELL;

void create() {
    ::create();
	set_exits(([
		"out": KEEPR + "jail6",
    ] ));
		set_door("iron door",KEEPR + "jail6","out","blacktongue jail key","lock");
		set_locked("iron door",1,"lock");
		lock_difficulty("iron door",10,"lock");
		set_door_description("iron door",I_DOOR);
		room = KEEPR + "jail6";
		door = "iron door";
}

