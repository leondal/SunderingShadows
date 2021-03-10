#include <std.h>
#include "../../valley.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(MEADOWLANDS);
   set_travel(FOOT_PATH);
	set_property("outdoors",3);
	set_property("light",2);
   set_short("%^MAGENTA%^Meadows%^RESET%^");
	set_long(
	"%^GREEN%^You are in a %^CYAN%^peaceful%^GREEN%^ meadow. The %^BOLD%^grass%^RESET%^%^GREEN%^ is"+
	" shorter here and numerous %^MAGENTA%^f%^BOLD%^l%^YELLOW%^"+
        "o%^WHITE%^w%^YELLOW%^e%^MAGENTA%^r%^RESET%^%^MAGENTA%^s%^GREEN%^ are growing"+
	" along the ground. They come in all different"+
	" varieties and are flourishing here in the meadow."+
	" You see some %^RESET%^field mice%^GREEN%^ scatter"+
	" away from you, trying to find a hiding place."+
	" The meadow has a %^CYAN%^tranquil%^GREEN%^ feeling and you think"+
	" you could spend hours relaxing here.\n"
	);
	set("night long",
	"%^GREEN%^You're standing in the middle of a meadow. The"+
	" %^BOLD%^grass%^RESET%^%^GREEN%^ is shorter here and there are numerous"+
	" %^MAGENTA%^f%^BOLD%^l%^YELLOW%^"+
        "o%^WHITE%^w%^YELLOW%^e%^MAGENTA%^r%^RESET%^%^MAGENTA%^s%^GREEN%^"+
        " growing all over the place. There"+
	" are all sorts of varieties here, they seem to"+
	" flourish in this place. You can still hear some"+
	" %^RESET%^field mice%^GREEN%^ scampering about, trying to find"+
	" their dinner. Even though it is %^BLUE%^night%^GREEN%^, this"+
	" place is no less %^CYAN%^peaceful%^GREEN%^. You'd feel quite"+
	" safe spending the night here.\n"
	);
	set_smell("default",
	"The sweet scent of wildflowers is in the air."
	);
	set_listen("default",
	"You hear the scampering of field mice."
	);
	set_items( ([
	"mice" : "%^BOLD%^Cute little field mice are running from you.",
	"flowers" : "%^MAGENTA%^There are many flowers of all"+
	" different types growing here. It would be easy to"+
	" pick a boquet of them.",
	"grass" : "%^GREEN%^This is lush green grass that looks like"+
	" it has been cut short.",
	]) );
}