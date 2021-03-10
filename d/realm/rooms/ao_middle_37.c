#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_CHAM;

void create() 
{
    	::create();
	wwall = "eastern";
	sexit = "east";
	hidden_room = MRS"36";	
}

void reset()
{
	object MyMon, MyKey;
	::reset();
	if(!objectp(TO)) return;
	if(!present("guardian of the sanctum", TO)) 
	{
		MyMon = new(RA_MON+"sanctum_guardian");
		MyMon->set_myblock_exit("east");
		MyMon->move(TO);
		MyKey = new(RA_OB+"guardian_key");
		MyKey->set_my_key_type(2);
		MyKey->move(MyMon);
	}
}