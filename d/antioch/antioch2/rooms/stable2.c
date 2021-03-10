//changed by Circe 4/23/04 to use hitching_post.c inherit
#include <std.h>
#include "../antioch.h"
inherit "/d/common/inherit/hitching_post";

void create()
{
	::create();
      set_terrain(WOOD_BUILDING);
      set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_long(
	"This room is lined with several posts to tether horses to. They"+
	" are spaced out just in case the horses want a little room. There"+
	" are two large water troughs that stretch for a good length of"+
	" the room, accessible to any horse that is tethered to one of"+
	" the posts. There is also fresh hay on the ground along the"+
	" length of each post and there are buckets against the walls"+
	" along with bags of grain. You can dip out grain in the buckets"+
	" and attach the buckets to the tethering post for your horse to"+
	" munch on. The room looks like it is kept fairly clean. Stable"+
	" hands probably run in and out of here to check on the horses"+
	" and get fresh water pretty often."
	);
	set_smell("default","There is a strong scent of hay here that"+
	" tickles your nose.");
	set_listen("default","You can hear the horses munching on grain"+
	" in their stalls and stomping around.");
	set_items(([
	"hay" : "%^YELLOW%^Hay is piled on the floor in front of the"+
	" tethering posts for any horses tethered there to reach.",
	({"trough","troughs","water trough","water troughs"}) : "%^BOLD%^%^BLUE%^Two"+
	" large watering troughs stretch almost the length of the room."+
	" They are positioned in front of the tethering posts for any"+
	" horses there to have access to.",
	({"ground","floor","dirt"}) : "The floor here is simply dirt so"+
	" that the horses won't hurt their feet.",
	"ceiling" : "The ceiling is high with an arched roof. Chains"+
	" hang down from it that hold light stones.",
	({"light","stone","enchanted stone","light stone","enchanted stones","light stones","stones"}) : "%^BOLD%^Stones that have been enchanted"+
	" with a continual light spell are hung from the ceiling. It gives"+
	" easy and constant light to the area without having to worry"+
	" about the possibilities of fires.",
	({"bucket","buckets"}) : "There are buckets hung on the walls"+
	" that can be filled with grain and attached to the tethering"+
	" posts for the horses to munch on while they are tied up.",
	({"grain","grain sacks","grain bags","bags"}) : "There are bags"+
	" of grain stacked up against the back walls.",
	({"post","posts","tethering post","tethering posts"}) : "There"+
	" are several posts set up here to tether horses to. They are"+
	" basically long wooden bars that are supported on either end"+
	" that you loop the reins of a horse around to keep them there."+
	" There are four posts all together, two set up next to eachother"+
	" on either side of the room.",
	]));
	set_exits(([
	"north" : ROOMS+"stables",
	]));
      set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}