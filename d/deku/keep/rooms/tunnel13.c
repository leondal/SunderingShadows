#include <std.h>
#include "../keep.h"
inherit TUNNELU;
void create() {
    ::create();
	set_climb_exits((["climb":({ "/d/deku/forest/dforest10-4",20,30,100}),"descend":({KEEPR +"tunnel12",20,30,100})]));
 set_items(([
		({"wall","walls"}) : "The walls of this tunnel are made from solid rock, they are lined with ridges, the obvious sign of erosion from long ago.  You can either try to climb these walls or descend down them to whatever is below.%^RESET%^",
		({"root","roots"}) : "%^RED%^These roots jut out from the walls of the tunnel, they vary dramatically in size.%^RESET%^",
		({"darkness"}) : "%^BOLD%^%^BLACK%^You see only darkness below you and judging from the growls which echo out from it, you believe it's not uninhabited.%^RESET%^",
		({"earth","crack"}) : "%^BOLD%^%^YELLOW%^Above you the earth splits open, allowing for you to be able to climb out of the tunnel into what appears to be a forest.%^RESET%^",
		({"trees","tree","forest","shadowlord forest"}) : "%^BOLD%^%^GREEN%^These trees are visible outside of the tunnel through the crack in the earth.  If you could only make the %^BOLD%^%^WHITE%^climb%^BOLD%^%^GREEN%^ out.%^RESET%^",
	] ));

}

