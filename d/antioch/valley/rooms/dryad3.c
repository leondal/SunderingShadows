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
	set_short("%^BOLD%^%^WHITE%^A %^YELLOW%^golden%^WHITE%^ chestnut tree");
	set_long(
	"%^RESET%^%^BOLD%^%^BLACK%^The chestnut tree has wilted away, its dead leaves scattered across the ground. Some rotten pieces of fruit still cling to the tree's skeleton-like branches. A trail of blood leads up to the tree and is smeared across one side of the trunk, leading further up into its ghostly remains.%^RESET%^\n"
//	"%^GREEN%^An ancient %^YELLOW%^golden chestnut%^RESET%^%^GREEN%^ tree is here. It reaches"+
//	" about sixty feet into the air, with a %^ORANGE%^trunk%^GREEN%^ that"+
//	" spans at least twelve feet before %^ORANGE%^branches%^GREEN%^ and leaves"+
//	" start. From the underside the tree is quite beautiful"+
//	" for the underside of the leaves look as though they've"+
//	" been brushed in %^YELLOW%^gold%^RESET%^%^GREEN%^, quite obviously the reason this"+
//	" tree got its name. The top side of the leaves are a"+
//	" normal %^BOLD%^green%^RESET%^%^GREEN%^ color and they're clustered together"+
//	" along the stems. They're a smooth %^ORANGE%^oval%^GREEN%^ shape, unlike"+
//	" most of the chestnut family. In the branches you can"+
//	" see some %^YELLOW%^pale yellow%^RESET%^%^GREEN%^ flowers and also some%^BOLD%^ bright"+
//	" green%^RESET%^%^GREEN%^ pieces of fruit that are quite prickly. A few"+
//	" of the fruits have turned a %^ORANGE%^browner%^GREEN%^ shade and are"+
//	" probably ready to have the nuts picked out of them."+
//	" The wind doesn't move this tree very much, probably"+
//	" because the branches and leaves are relatively"+
//	" clustered together, it being a type of evergreen.\n"
	);
	set("night long",
	"%^RESET%^%^BOLD%^%^BLACK%^The chestnut tree has wilted away, its dead leaves scattered across the ground. Some rotten pieces of fruit still cling to the tree's skeleton-like branches. A trail of blood leads up to the tree and is smeared across one side of the trunk, leading further up into its ghostly remains.%^RESET%^\n"
//	"%^GREEN%^An incredible looking tree is standing here. From a"+
//	" distance the leaves are reflecting the %^BOLD%^%^WHITE%^silver%^RESET%^%^GREEN%^ of the"+
//	" %^BOLD%^%^WHITE%^moonlight%^RESET%^%^GREEN%^, but from underneath you can see their"+
//	" %^YELLOW%^golden%^RESET%^%^GREEN%^ shade. With the bark being a "+
//	"%^RESET%^pale gray%^GREEN%^ this"+
//	" tree almost appears to be made entirely of %^BOLD%^%^WHITE%^silver"+
//	" %^RESET%^%^GREEN%^and %^YELLOW%^gold%^RESET%^%^GREEN%^. It is"+
//	" a %^YELLOW%^golden chestnut %^RESET%^%^GREEN%^and has obviously"+
//	" been here for some years. The trunk stretches up into"+
//	" the air, and it is at least ten feet before the"+
//	" branches began to form. Even then, the branches do"+
//	" not spread out very far, giving the tree a close,"+
//	" slender shape. There are several of the%^BOLD%^ brilliant"+
//	" green%^RESET%^%^GREEN%^, prickly fruit for which the chestnut is known"+
//	" on this tree. Some of them are a %^ORANGE%^darker brown%^GREEN%^ and"+
//	" are probably ready to be eaten. Strangely, there are"+
//	" no fallen nuts anywhere around. The wind doesn't"+
//	" sway this tree at all, and it almost seems untouched"+
//	" by time here in this valley.\n"
	);
	set_smell("default",
	"The scent of chestnuts wafts in the air."
	);
	set_listen("default",
	"Birds can be heard chirping in the distance."
	);
	set_items( ([
	({"chestnut","tree","golden chestnut"}) : "%^YELLOW%^This tree is"+
	" a type of evergreen, its leaves are a deep green from"+
	" the top, but golden underneath, giving it its name. It"+
	" stands tall, and the branches don't begin until a ways"+
	" up the trunk. Not even the wind ruffles this tree.",
	"trunk" : "%^RESET%^The trunk of the tree is a pale gray and is"+
	" thick around for a chestnut, but not really that"+
	" large although it looks strong. It spans about twelve"+
	" feet before the branches begin.",
	"branches" : "%^ORANGE%^The branches are mainly hidden beneath"+
	" the thick foliage of the tree.",
	"leaves" : "%^BOLD%^%^GREEN%^The leaves are green from the top, and"+
	" smooth, unlike most chestnuts, clustering along the"+
	" stems. The underside is a golden shade and quite"+
	" lovely.",
	"flowers" : "%^YELLOW%^There are a few pale yellow flowers"+
	" scattered throughout the branches of the tree.",
	"fruit" : "%^ORANGE%^Most of the fruit is a bright green and"+
	" very prickly, though some have turned a brown shade"+
	" that means they're getting ripe. The chestnuts are"+
	" found in the center of the fruit.",
	]) );
	set_exits( ([
	"north" : ROOMS+"g108",
	"south" : ROOMS+"g100",
	"west" : ROOMS+"g104",
	"east" : ROOMS+"g103",
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
	if(str != "tree" && str != "chestnut") {
		write("The only thing to climb here is a tree.");
		return 1;
	}
	else {
		write("%^BOLD%^You easily climb up the distance of"+
		" the trunk and find several large branches that will"+
		" easily support you, and you pull yourself up onto them.");
		say(
		"%^BOLD%^"+TP->query_cap_name()+" climbs up the long"+
		" trunk and pulls "+TP->query_objective()+"self up into"+
		" the tree.");
		this_player()->move_player(ROOMS+"chestnut");
		return 1;
	}
}
