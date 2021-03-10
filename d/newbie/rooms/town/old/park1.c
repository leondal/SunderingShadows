#include <std.h>
#include "../../newbie.h"
inherit INH"townmove.c";

void create()
{
	::create();
	set_property("light",2);
	set_short("Entrance to the park");
	set_terrain(GARDEN);
	set_travel(FOOT_PATH);
	set_long(
	"You are standing in the entrance of the Offestry park. To the east you can see"+
	" North Street, to the west is the park itself. There are two statues here, the"+
	" one on the south side is of a unicorn grazing on the grass. The one to the north"+
	" is a large oak tree surrounded by many small forest animals. There is a tranquil"+
	" feeling to this place."
	);
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly and lights your way.");
	set_smell("default","There is a faint scent of roses in the air.");
	set_listen("default","You can hear birds chirping in the park.");
	set_items(([
	({"statue 1","statue","unicorn","unicorn statue","south statue"}) : "%^BOLD%^The statue on"+
	" the south side has been carved from white marble and shaped into the image of a"+
	" unicorn bent over to graze on the %^GREEN%^grass%^WHITE%^. The image is smaller than life, but still"+
	" strikingly realistic. You can see the muscles in the great animals neck, and the"+
	" mane seems to be ruffled by a breeze. Its eyes are closed in peaceful content."+
	" The horn on the statue is spiraled, and there is a milky white swirl that spirals"+
	" with it, creating a beautiful effect.",
	({"statue 2","oak tree","oak","oak statue","north statue"}) : "The statue to the"+
	" north depicts a forest scene of a tall oak tree surrounded by several woodland"+
	" animals. The oak tree has large branches spread out, as though protecting them."+
	" The scene is made from terracotta, but the oak leaves have been fastened on"+
	" afterwards and are made of %^GREEN%^malachite%^RESET%^. There are several different"+
	" types of animals all gathered together. An owl is perched on a lower branch of the"+
	" oak, and there is a bunny rabbit huddled next to a fox, a great bear is lounging"+
	" on the other side, along with a wolf and a raccoon. It is a peaceful image, despite"+
	" the strange combination of animals.",
	"grass" : "%^GREEN%^%^BOLD%^The grass beneath your feet is lush and green, it is"+
	" almost like a carpet it is so thick and well cared for.",
	]));
	set_exits(([
	"east" : MAINTOWN"nstreet2",
	"west" : MAINTOWN"park2",
	]));
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
