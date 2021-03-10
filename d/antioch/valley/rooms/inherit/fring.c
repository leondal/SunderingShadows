#include <std.h>
#include "../../valley.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(MEADOWLANDS);
   set_travel(FOOT_PATH);
	set_property("outside",3);
	set_property("light",3);
   set_short("%^YELLOW%^Fairy Ring%^RESET%^");
	set_long(
	"%^GREEN%^You're standing at the edge of a fairy ring."+
	" %^YELLOW%^Toadstools%^RESET%^%^GREEN%^ mark the borders of it, but you"+
	" cannot cross over them. There is a small %^BOLD%^hill"+
	" %^RESET%^%^GREEN%^in the center of the ring. You've heard rumors"+
	" that the hillside is supposed to open into the"+
	" realm of the %^BOLD%^%^MAGENTA%^fairies%^RESET%^%^GREEN%^, but only fairies know how"+
	" to make that happen.\n"
	);
	set_smell("default",
	"Your nose tingles from a funny smell, but you"+
	" can't place what it is."
	);
	set_listen("default",
	"Birds are chirping in the distance."
	);
	set_items( ([
	"hill" : "%^GREEN%^There is a mound in the center of a ring"+
	" covered in grass.",
	"toadstools" : "%^YELLOW%^These are tiny toadstools growing in"+
	" equal intervals in a perfect circle around the"+
	" hill.",
	]) );
}

