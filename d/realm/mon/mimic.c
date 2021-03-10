#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit "/d/common/mons/mimic_chest";

void create() 
{
	::create();
	setMyMimicLevel(45, 35);
	set_my_treasure((["gold" : 3000 + random(3000)]));
}


