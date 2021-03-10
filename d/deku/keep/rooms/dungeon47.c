#include <std.h>
#include "../keep.h"

inherit STAIRWELL;

void create() 
{
    	::create();
	set_long(TO->query_long() + "  %^BOLD%^%^WHITE%^The stairwell ends suddenly "+
	"here, leaving you with two options.  You may either descend into the "+
	"depths of the darkness or find a way to open the %^RED%^rusty "+
	"door%^BOLD%^%^WHITE%^ inset into the ceiling of the stairwell.%^RESET%^\n");

	add_item("ceiling","%^BOLD%^%^RED%^The ceiling of this stairwell is very "+
	"low and inset directly into the center of it is a rusty metal door.%^RESET%^");

    	set_exits(([
		"down" : KEEPR + "dungeon46", "up" : KEEPR + "towerW2",
    	] ));
	set_door("rusty door",KEEPR + "towerW2","up","blacktongue master key","lock");
	set_string("rusty door", "open", RD_OPEN_DESC);
	set_locked("rusty door",1,"lock");
	lock_difficulty("rusty door",1,"lock");
	set_door_description("rusty door","%^RED%^This door is roughly 3' "+
	"square and made from a solid metal that has rusted over the "+
	"course of time.%^RESET%^");	
}
