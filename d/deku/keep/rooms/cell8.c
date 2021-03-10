#include <std.h>
#include "../keep.h"

inherit CELL;

int found;

void create() {
    ::create();

	set_exits(([
		"out": KEEPR + "jail5",
    ] ));
		set_door("metal door",KEEPR + "jail5","out","blacktongue jail key","lock");
		set_locked("metal door",1,"lock");
		lock_difficulty("metal door",10,"lock");
		set_door_description("metal door",M_DOOR);
		room = KEEPR + "jail5";
		door = "metal door";
	
}


