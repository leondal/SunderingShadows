#include <std.h>
#include "../keep.h"

inherit DUNGEON;

void create()
{
	int x;
    	::create();
   	set_long(TO->query_long() + "%^BOLD%^%^WHITE%^  The corridor extends to "+
	"the north and to the south.  You may travel in either direction but "+
	"you must brave the unknown danger of the thick darkness.%^RESET%^");

	for(x = 0;x < sizeof(LITEMS);x++) 
	{
		add_item(LITEMS[x], "%^BOLD%^%^BLACK%^These symbols depict "+
		"numerous wolf-like creatures kneeled before a massive wolf-like "+
		"creature seated on a %^YELLOW%^golden"+
		"%^BOLD%^%^BLACK%^ throne and garbed with an "+
		"%^BLUE%^obsidian%^BOLD%^%^BLACK%^ robe.  "+
		"An uneasy feeling stirs within you.%^RESET%^");
	}
	set_exits(([
		"south": KEEPR + "blacktonguelair7","north" : KEEPR + "blacktonguelair9",
    	] ));	
}
