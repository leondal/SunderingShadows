#include <std.h>
#include "../keep.h"

inherit STAIRWELL;

void create() 
{
    	int x;
    	::create();
    	set_long(TO->query_long() + "%^BOLD%^%^WHITE%^  The stairwell ends here, "+
	"exiting into a larger chamber.  You may either exit the stairwell "+
	"or ascend the stairs, regardless, you must brave the unknown danger of "+
	"the thick darkness.%^RESET%^\n");
   	for(x = 0;x < sizeof(LITEMS);x++) 
	{
      	add_item(LITEMS[x],"%^BOLD%^%^BLACK%^These symbols show a "+
		"massive upright wolf-like beast sitting on a %^YELLOW%^"+
		"golden %^BOLD%^%^BLACK%^ throne.  Numerous "+
        	"other upright wolf-like creatures are bowing before the "+
		"throne in awe and worship.  A chill runs up your spine.%^RESET%^");
    	}
   	set_exits(([
      	"up": KEEPR + "blacktonguelair4","exit" : KEEPR + "blacktonguelair6"
    	] ));
}

