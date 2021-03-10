#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_UFT;
string original_long;
void create() 
{
	new(RA_MON+"valshiiir")->move(TO);
    	::create();
	set_exits((["north" : MRS"139"]));
	//secret exit from this place - need to make code to allow the portal to 
	//open - perhaps a special mob is here and if it dies then it opens the portal??
	original_long = TO->query_long();
}

void reset()
{
	::reset();
	if(!random(10)) 
	{
		if(present("valshiiir", TO)) return;
		new(RA_MON+"valshiiir")->move(TO);
		if(member_array("portal", TO->query_exits()) == -1) return;
		TO->remove_exit("portal");
		TO->remove_item(({"portal", "dark portal"}));
		TO->set_long(original_long);
	}
}

void activate_freedom()
{
	if(!objectp(TO)) return;
	if(member_array("portal", TO->query_exits()) != -1) return;
	tell_room(TO, "%^BOLD%^%^BLUE%^A dark portal suddenly "+
	"springs to life in the center of the room!%^RESET%^");
	TO->add_exit("/d/tharis/barrow/rooms/bd10", "portal");
	TO->add_item(({"portal", "dark portal"}), "%^BOLD%^%^BLUE%^"+
	"This mysterious dark portal has burst into life here "+
	"and appears to lead to safety.%^RESET%^");
	TO->set_long(original_long + "  %^BOLD%^%^BLACK%^A "+
	"%^BOLD%^%^BLUE%^dark portal%^BOLD%^%^BLACK%^ rests "+
	"in the center of this room.%^RESET%^");
}