#include <std.h>
#include "../keep.h"

inherit CELL;

void create() {
    ::create();
	set_exits(([
		"out": KEEPR + "jail6",
    ] ));
		set_door("metal door",KEEPR + "jail6","out","blacktongue jail key","lock");
		set_locked("metal door",1,"lock");
		lock_difficulty("metal door",10,"lock");
		set_door_description("metal door",M_DOOR);
		room = KEEPR + "jail6";
		door = "metal door";	
}

