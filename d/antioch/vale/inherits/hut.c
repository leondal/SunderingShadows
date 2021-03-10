#include <std.h>
#include "../vale.h"
inherit VAULT;

void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",1);
    set_travel(FOOT_PATH);
    set_terrain(MEADOWLANDS);
	set_short("A simple hut");
	set_long(
	"%^ORANGE%^This is a rather simple hut. The walls are made of wood, but"+
	" strangely appear to be all one piece of wood, joined together"+
	" with no flaws. The roof is supported by a few wooden beams and"+
	" covered with thatch. The floor is simply packed dirt and there"+
	" is a little %^YELLOW%^straw%^RESET%^%^ORANGE%^ mat with a "+
        "%^GREEN%^blanket%^ORANGE%^ and %^GREEN%^pillow%^ORANGE%^ that must serve"+
	" as a bed. There is a %^RESET%^chest%^ORANGE%^ that is filled with a few simple"+
	" %^BOLD%^%^GREEN%^robes%^RESET%^%^ORANGE%^, %^BOLD%^%^WHITE%^woven belts"+
        "%^RESET%^%^ORANGE%^, and some unidentified %^GREEN%^herbs%^ORANGE%^. There is a"+
	" %^RESET%^stone %^RED%^firepit%^ORANGE%^ across from the mat that doesn't appear to have"+
	" had too much use. Whoever lives here seems to have a simple life.\n"
	);
	set_smell("default","You smell the straw from the mat.");
	set_listen("default","The calls of the birds are muffled in here.");
	set_items(([
	({"bed","mat","straw mat"}) : "%^YELLOW%^A simple straw mat is positioned"+
	" in one corner of the room. It has a sheet over the straw and"+
	" a blanket and pillow on top.",
	"sheet" : "%^GREEN%^The sheet covers the straw, helping to prevent the"+
	" person laying there from getting poked and scratched.",
	"blanket" : "%^GREEN%^The blanket is made of soft wool, it is incredibly"+
	" soft to the touch and will keep the user quite warm.",
	"pillow" : "%^GREEN%^There is a pillow on the straw mat, it appears to"+
	" be rather crude but it stuffed with soft goose feathers and"+
	" is probably rather comfortable.",
	"floor" : "%^ORANGE%^The floor is merely hard packed dirt.",
	"roof" : "%^YELLOW%^The roof is simply constructed of a few supporting"+
	" wooden beams and covered with thatch.",
	({"beams","wooden beams"}) : "%^ORANGE%^A few wooden beams are above your"+
	" head, holding the roof in place.",
	({"wall","walls","wood"}) : "%^ORANGE%^The walls are very strange, they're"+
	" obviously made of wood but are somehow one solid piece of wood."+
	" You see no places where it doesn't join together seamlessly, which"+
	" is supposed to be impossible.",
	"chest" : "There is a large chest at the far end of the room that"+
	" has been left open. It contains a few robes and belts, along"+
	" with pouches of dried herbs.",
	({"clothing","clothes","robes","belts"}) : "%^BOLD%^The robes are shades"+
	" of green and brown, and are absolutely worthless. The belts are"+
	" made of woven cloth and dyed to match the robes, and are equally"+
	" worthless.",
	"herbs" : "%^GREEN%^The herbs have been dried and placed into pouches. It's"+
	" almost impossible to tell what they once were now, and since they"+
	" haven't yet been mixed together to create anything, are of no"+
	" use to you.",
	({"fire pit","firepit","stone firepit"}) : "%^RED%^There is a stone firepit"+
	" across from the bed. It doesn't appear as though it has gotten"+
	" much use, though.",
	"door" : "%^ORANGE%^The door is made of simple wood with a metal latch. It"+
	" also seems to be from one solid piece of wood, but is separate"+
	" from the rest of the walls.",
	]));
}
