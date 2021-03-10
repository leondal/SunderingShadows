#include <std.h>
#include "../../newbie.h"
inherit INH"townmove.c";

void create()
{
	::create();
	set_property("light",2);
	set_terrain(GARDEN);
	set_travel(FOOT_PATH);
	set_short("A path through the park");
	set_long(
	"The path in the garden splits off to the north and the south, you can see the"+
	" bridge back to the east. On this side of the pond the path is lined by zinnias and"+
	" golden feather. They tend to spread out for a few feet on either side of the"+
	" path, covering up most of the grass. Red yarrow is growing strong and tall on west"+
	" side of the path here. It tends to grow rather quickly, but it appears to be kept"+
	" well cut back in orderly bushes. To the north you can see that there are some"+
	" hanging plants, to the south are a couple of benches and statues."
	);
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly and lights your way.");
	set_smell("default","A sweet scent drifts in from the north.");
	set_listen("default","You can hear birds chirping in the park.");
	set_items(([
	"grass" : "%^GREEN%^%^BOLD%^The grass beneath your feet is lush and green, it is"+
	" almost like a carpet it is so thick and well cared for.",
	"zinnias" : "There are two types of zinnias growing in the park here. One has"+
	" bright orange petals that surround an orange-yellow center. The other has brilliant"+
	" white petals with a golden center. They are both shaped like daisies, but are"+
	" slightly smaller. They grow clustered together along the edge of the path here.",
	"red yarrow" : "%^RED%^The flowers of the red yarrow range from dark red to light"+
	" pink, though red seems to be the predominant color here. They are disk-shaped and"+
	" their flowers crowd out the leaves of the plant. It is kept well cut back, one"+
	" of the local bars is probably harvesting it to make ale.",
	"golden feather" : "%^YELLOW%^These golden, fern-like leaves are striking in appearance."+
	" Tiny white daisy flowers grows along the stems, and they are breath-taking.",
	]));
	set_exits(([
	"east" : MAINTOWN"park5",
	"south" : MAINTOWN"park7",
	"north" : MAINTOWN"park9",
	]));
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
