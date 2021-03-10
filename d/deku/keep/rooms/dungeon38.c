#include <std.h>
#include "../keep.h"

inherit DUNGEON;

void create() 
{
	int x;
    	::create();
	set_property("no teleport",-1);
    	set_long(TO->query_long() + "  %^BOLD%^%^WHITE%^This corridor slopes downward "+
	"to the northeast and meets a narrow stairwell at the base of the "+
	"southern wall.  You may enter the "+
	"stairwell or travel northward, regardless, you must brave the "+
	"unknown danger of the thick %^BOLD%^%^BLACK%^darkness%^BOLD%^"+
	"%^WHITE%^.%^RESET%^\n");

    	set_exits(([
		"stairs": KEEPR + "dungeon39","northeast" : KEEPR + "dungeon37"
    	] ));
	for(x = 0;x < sizeof(LITEMS);x++) 
	{
		add_item(LITEMS[x],"%^BOLD%^%^BLACK%^These %^CYAN%^symbols%^BLACK%^ "+
		"depict the begginning of the %^RED%^transformation%^BLACK%^ "+
		"of what appears to be a %^RED%^human"+
		"%^BLACK%^.  You are unable to determine what the outcome of "+
		"the transformation was as "+
		"half way through the process the hieroglyphics change "+
		"to depict a very different "+
		"picture.  The picture becomes what appears to be a tall "+
		"man draped in %^RED%^tattered "+
		"robes%^BOLD%^%^BLACK%^ surrounded by upright wolf like "+
		"creatures.  A %^YELLOW%^light "+
		"bursts%^BOLD%^%^BLACK%^ forth from the man and goes "+
		"through the creatures striking an "+
		"invisible %^WHITE%^barrier%^BOLD%^%^BLACK%^ near the walls.  "+
		"In the next "+
		"instance the man has vanished and a ball of "+
		"%^YELLOW%^light%^BOLD%^%^BLACK%^ remains "+
		"in his place.%^RESET%^");
	}
}