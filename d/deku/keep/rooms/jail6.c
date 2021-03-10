#include <std.h>
#include "../keep.h"

inherit JAIL;

void create()
{
    	::create();
	set_long(TO->query_long() + "%^YELLOW%^  Inset into the eastern "+
	"and western walls of this corridor are doors with barred windows.  "+
	"It continues into darkness to the north and to the south.%^RESET%^\n");

	add_item("walls","The walls of this corridor do not appear to be "+
	"very sturdy, as they are constructed entirely from %^YELLOW%^"+
	"sandstone%^RESET%^.  Inset directly into the center of the eastern "+
	"and western walls are doors with barred windows.%^RESET%^");
    	set_exits(([
		"north": KEEPR + "jail1",
		"south" : KEEPR + "jail7",
		"west" : KEEPR + "cell9",
		"east" : KEEPR + "cell10"
    	] ));

	set_door("iron door",KEEPR + "cell10","east","blacktongue jail key","lock");
	set_locked("iron door",1,"lock");
	lock_difficulty("iron door",10,"lock");
	set_door("metal door",KEEPR + "cell9","west","blacktongue jail key","lock");
	set_locked("metal door",1,"lock");
	lock_difficulty("metal door",10,"lock");
	set_door_description("iron door",I_DOOR);
	set_door_description("metal door",M_DOOR);
	room = KEEPR + "cell9";
	door = "metal door";
	room2 = KEEPR + "cell10";
	door2 = "iron door";

}

