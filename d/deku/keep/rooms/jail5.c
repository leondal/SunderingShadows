#include <std.h>
#include "../keep.h"

inherit JAIL;

void create()
{
    	::create();
	set_long(TO->query_long() + "%^YELLOW%^  Inset into the northern "+
	"and southern walls of this corridor are doors with barred "+
	"windows.  It continues into darkness to the east and meets a "+
	"sandstone wall to the west.%^RESET%^\n");

	add_item("walls","The walls of this corridor do not appear to be "+
	"very sturdy, as they are constructed entirely from %^YELLOW%^"+
	"sandstone%^RESET%^.  Inset directly into the center of the "+
	"northern and southern walls are doors with barred windows.%^RESET%^");
    	set_exits(([
		"east": KEEPR + "jail4",
		"north" : KEEPR + "cell7",
		"south" : KEEPR + "cell8"
    	] ));
	set_door("metal door",KEEPR + "cell8","south","blacktongue jail key","lock");
	set_locked("metal door",1,"lock");
	lock_difficulty("metal door",10,"lock");
	set_door("iron door",KEEPR + "cell7","north","blacktongue jail key","lock");
	set_locked("iron door",1,"lock");
	lock_difficulty("iron door",10,"lock");
	set_door_description("iron door",I_DOOR);
	set_door_description("metal door",M_DOOR);
	room = KEEPR + "cell8";
	door = "metal door";
	room2 = KEEPR + "cell7";
	door2 = "iron door";

}

