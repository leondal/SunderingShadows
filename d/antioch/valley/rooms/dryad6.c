#include <std.h>
#include "../valley.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(GRASSLANDS);
   set_travel(FOOT_PATH);
	set_property("outdoors",3);
	set_property("light",3);
	set_short("%^BOLD%^A %^RESET%^silverleaf %^BOLD%^oak");
	set_long(
	"%^GREEN%^A large %^BOLD%^%^WHITE%^silverleaf oak%^RESET%^%^GREEN%^ stands here. It looks to be"+
	" quite old, as though it has been here for some time."+
	" The %^RESET%^trunk%^GREEN%^ of the tree is very big around, even an"+
	" ogre would have trouble getting his arms all the way"+
	" around it. The trunk shortly separates into large"+
	" %^ORANGE%^branches%^GREEN%^ that disappear beneath the leaves. The"+
	" leaves themselves are different from those of normal"+
	" oaks. They're longer and thinner with a slight tint"+
	" of %^BOLD%^%^WHITE%^silver%^RESET%^%^GREEN%^. The branches are covered in thick leaves"+
	" and a few %^ORANGE%^acorns%^GREEN%^ can be seen nestled in the foliage.\n"
	);
	set("night long",
	"%^GREEN%^The branches of the large %^BOLD%^%^WHITE%^silverleaf%^RESET%^%^GREEN%^ oak block out"+
	" much of the light from the %^BOLD%^%^WHITE%^moon%^RESET%^%^GREEN%^. The leaves seem"+
	" even more %^BOLD%^%^WHITE%^silver%^RESET%^%^GREEN%^ in the moonlight and the %^ORANGE%^acorns"+
	" %^RESET%^%^GREEN%^reflect a %^RESET%^metallic%^GREEN%^ glint as well. This tree must have"+
	" been here for a very long time judging by the"+
	" thickness of the trunk. A dark %^BOLD%^%^BLACK%^shadow%^RESET%^%^GREEN%^ is cast on the"+
	" ground from the oak and it seems to dance as the wind"+
	" blows through the branches of the tree.\n"
	);
	set_items( ([
   ({"oak", "tree", "silverleaf"}) : "%^BOLD%^This majestic tree"+
	" looks as though it has stood here proudly for centuries.",
	"leaves" : "These leaves are longer and thinner than"+
	" that of other oaks, they also have a silver sheen"+
	" to them.",
	"acorns" : "%^ORANGE%^There are several acorns nestled in the"+
	" branches of the tree.",
	"trunk" : "%^RESET%^The trunk is a pale color and very thick"+
	" around, it separates into several large branches.",
	"branches" : "%^ORANGE%^The branches look very sturdy, splitting off"+
	" from the trunk and growing up to great heights.",
	]) );
	set_smell("default",
	"The breeze carries a faint scent of wildflowers mixed"+
	" with oak."
	);
	set_listen("default",
   "The wind rustles the leaves of this majestic oak."
	);
	set_exits( ([
	"north" : ROOMS+"g50",
	"south" : ROOMS+"g45",
	"west" : ROOMS+"g52",
	"east" : ROOMS+"g48",
	]) );
}

void init()
{
	::init();
	add_action("climb", "climb");
}

int climb(string str)
{
	if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}
	if(!str) {
		write("Climb what?");
		return 1;
	}
	if(str != "tree" && str != "oak") {
		write("The only thing to climb here is a tree.");
		return 1;
	}
	else {
		write("%^BOLD%^You easily climb up the oak, grasping"+
		" the thick branches that effortlessly support your"+
		" weight.");
		say(
		"%^BOLD%^"+TP->query_cap_name()+" easily climbs the"+
		" oak, grabbing onto the large branches and pulling"+
		" "+TP->query_objective()+"self into the tree.");
		this_player()->move_player(ROOMS+"oak");
		return 1;
	}
}
