#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_CHAM;

void create() 
{
    	::create();
	wwall = "western";
	sexit = "west";
	hidden_room = MRS"54";	
}

void reset()
{
	object MyMon, MyKey;
	::reset();
	if(!objectp(TO)) return;
	if(!present("guardian of the sanctum", TO)) 
	{
		MyMon = new(RA_MON+"sanctum_guardian");
		MyMon->set_myblock_exit("west");
		MyMon->move(TO);
		MyKey = new(RA_OB+"guardian_key");
		MyKey->set_my_key_type(3);
		MyKey->move(MyMon);
	}
}