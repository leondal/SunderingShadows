#include <std.h>
#include "../valley.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(BRANCHES);
   set_travel(FRESH_BLAZE);
   set_property("no charge",1);
   set_charge_message("You can't charge something in a tree!");
	set_property("indoors",2);
	set_property("light",3);
	set_short("%^BOLD%^Branches of a walnut tree");
	set_long(
	"%^GREEN%^You're standing on the sturdy branches of a %^BOLD%^%^BLACK%^walnut tree%^RESET%^%^GREEN%^."+
	" Two thick branches divide here and grow upwards, with"+
	" smaller branches dividing off from them. The %^BOLD%^%^BLACK%^leaves"+
	" %^RESET%^%^GREEN%^create a dome, blocking out the rest of the world, but"+
	" they are only on the outer edges, which leaves the"+
	" center of the tree free except for the branches. The trunk"+
	" is a %^ORANGE%^rich brown%^RESET%^%^GREEN%^ color and there are several different"+
	" shades that appear throughout the tree. It is easy to"+
	" glance down at the ground below, it's not that far away"+
	" but a fall would hurt.\n"
	);
	set("night long",
	"%^GREEN%^You have climbed into a %^BOLD%^%^BLACK%^walnut tree%^RESET%^%^GREEN%^. Two sturdy"+
	" branches support your weight, dividing upwards to split"+
	" out and form the rest of the tree. There are several"+
	" branches above you, all protected from the outside by a"+
	" thick layer of leaves. No prying eyes could find their"+
	" way in here! The wind blows the leaves slightly, and"+
	" a chilly breeze drifts through. You can see the ground"+
	" below you, though it's covered in %^BOLD%^%^BLACK%^darkness%^RESET%^%^GREEN%^ from the tree's"+
	" shadow. A fall from here would definitely hurt.\n"
	);
	set_smell("default",
	"The smell of walnuts is very strong."
	);
	set_listen("default",
	"The wind is whistling through the leaves."
	);
	set_items( ([
	"leaves" : "%^BOLD%^%^BLACK%^The leaves ring the edges of the branches,"+
	" blocking out the outside world. The wind is blowing"+
	" through them, causing them to flutter.",
	"branches" : "There are two main branches here that come"+
	" up from the trunk and divide out to form the rest of the"+
	" tree. The split out more to form other branches.",
	"ground" : "%^GREEN%^The ground isn't that far away, but it would"+
	" be best to climb down safely than to take a fall.",
	"trunk" : "The thick trunk divides into two main branches.",
	]) );
	set_exits( ([
	"down" : ROOMS+"dryad2",
	]) );
}

void reset()
{
	::reset();
	if(!present("dryad")) {
		new(MONS+"walnut_dryad")->move(TO);
	}
}
