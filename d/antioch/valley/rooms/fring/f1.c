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
	set_short("%^YELLOW%^Fairy Ring");
	set_long(
	"%^GREEN%^%^BOLD%^You have entered a fairy ring.\n"+
        "%^RESET%^%^GREEN%^You're standing at the edge of the circle."+
	" %^YELLOW%^Toadstools%^RESET%^%^GREEN%^ mark the borders of it, but you"+
	" cannot cross over them. There is a small hill"+
	" in the center of the ring. You've heard rumors"+
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
	set_exits( ([
	"northwest" : FRING+"f2",
	"northeast" : FRING+"f24",
   "south" : ROOMS+"g96",
	]) );
   // set_pre_exit_functions(({"northwest"}),({"go_northwest"}));
}

int go_northwest()
{
   write("%^YELLOW%^The toadstolls seem to glow slightly.");
   return 1;
}
