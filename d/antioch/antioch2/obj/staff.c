#include <std.h>
#include "../antioch.h"
//Updated for weapon feats Octothorpe 5/11/09
inherit "/d/common/obj/weapon/mstaff.c";

void create()
{
	::create();
	set_name("staff");
	set_short("A fine staff");
	set_id(({"staff","fine staff"}));
	set_long(
	"This is a fine staff of normal size. It is meant mostly for defending"+
	" oneself, or to be used as a cane. It is moderately effective in battle,"+
	" but not as good as many other weapons unless you are a master with it."
	);
        //set_wc(1,4);
        //set_large_wc(1,6);
        //set_type("bludgeoning");
        //set_weight(4);
        //set_value(2);
        //set_size(2);
        //set_weapon_speed(2);
        //set_prof_type("staff");
}
