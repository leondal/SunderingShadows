#include <std.h>
#include "../../newbie.h"
inherit INH"townmove.c";

void create()
{
	::create();
	set_property("light",2);
	set_terrain(GARDEN);
	set_travel(FOOT_PATH);
	set_short("A path through a beautiful park");
	set_long(
	"You are walking along a path through the Offestry park. It is quite pretty here,"+
	" with wildflowers growing along the edges of the dirt path. The path continues on"+
	" to the west, and you can see a bridge that stretches over a little pond. To the"+
	" south you can see beautiful roses, and there appear to be daffodils and daisies to"+
	" the north. To the east is the entrance of the park."
	);
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly and lights your way.");
	set_smell("default","There is the scent of roses coming from the south.");
	set_listen("default","You can hear birds chirping in the park.");
	set_items(([
	"grass" : "%^GREEN%^%^BOLD%^The grass beneath your feet is lush and green, it is"+
	" almost like a carpet it is so thick and well cared for.",
	"path" : "This is a small dirt path that is lined on either side by wildflowers.",
	({"flowers","wildflowers"}) : "Wildflowers of all different colors and shapes line"+
	" the path on either side here.",
	]));
	set_exits(([
	"east" : MAINTOWN"park1",
	"west" : MAINTOWN"park5",
	"north" : MAINTOWN"park4",
	"south" : MAINTOWN"park3",
	]));
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
