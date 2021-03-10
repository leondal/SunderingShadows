#include <std.h>
#include "../keep.h"

inherit TUNNELBUR;

void load_assin()
{
	object assin, room;
	int num = 1;
	while(num <= 4)
	{
		if(objectp(room = find_object_or_load(KEEPR+"burial_chamber_"+num))) 
		{
			if(objectp(assin = present("deku_skel_assassin", room)))
			{
				return;
			}
		}
		num++;
		continue;
	}
	if(!objectp(assin)) 
	{
     		assin = new(KEEPM+"skeletal_assassin");
		assin->move(TO);
	}
}

void create() 
{
	::create();
	set_long(TO->query_long() + "%^BOLD%^%^RED%^  This massive chamber "+
	"opens up to another south of here.%^RESET%^");  
     	set_exits(([
		"south": KEEPR + "burial_chamber_1"
     	] ));
	load_assin();
}

void reset()
{
	::reset();
	load_assin();
}

