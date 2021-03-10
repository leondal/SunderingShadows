// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("beshaba_lair");
    set_property("indoors",0);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^RED%^B%^RESET%^%^MAGENTA%^esh%^RED%^a%^MAGENTA%^ba%^RED%^'%^MAGENTA%^s %^BOLD%^%^RED%^L%^RESET%^%^MAGENTA%^air%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This seems to be the focal point of the ruins in the area, %^RESET%^%^ORANGE%^de%^GREEN%^c%^ORANGE%^ay%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d %^BOLD%^%^BLACK%^and half-buried under the"
	" glistening black vines growing here.  The vines twist and curl around everything, their vicious thorns exposed and dripping with all manner of %^RESET%^%^GREEN%^ven%^YELLOW%^o%^RESET%^%^GREEN%^m %^BO"
	"LD%^%^BLACK%^and %^RESET%^%^BLUE%^po%^MAGENTA%^i%^BLUE%^son%^BOLD%^%^BLACK%^.  There is a central dais rising among the toppled pillars and vegetation, supporting a %^RESET%^st%^BOLD%^o%^RESET%^ne thr"
	"%^BOLD%^on%^RESET%^e%^BOLD%^%^BLACK%^.%^RESET%^"
	);

    set_smell("default","
The acrid stench of venom mixes with the earthy aroma of rot.");
    set_listen("default","The sounds of skittering and crawling insects catches your ear.");

    
set_items(([ 
	"throne" : "%^BOLD%^%^BLACK%^This stone throne is surrounded by detritus and rubble.  The back of the throne is engraved with the image of a large sinister eye, and a pair of stag horns has been attached above it.%^RESET%^",
	"vines" : "%^BOLD%^%^BLACK%^The vines are black and devoid of color.  They are covered in sinister thorns which seem to seep a noxious green ichor.%^RESET%^",
	]));
}
