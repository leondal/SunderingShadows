#include <std.h>
#include "../../gantioch.h"

inherit ROOM;

void create()
{
    ::create();
    set_name("teepee1");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",0);

    set_short("%^BOLD%^%^GREEN%^Within a tee-pee%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^The inside of the tent is adorned with items "+
			"representing the power of this %^BOLD%^%^RED%^criminal%^RESET%^ORANGE%^. The"+ 
			"most noticable item is a massive locked %^BOLD%^%^YELLOW%^chest%^RESET%^%^ORANGE%^"+
			"that is next to a heavy bed-down of thick %^RESET%^%^GREEN%^grasses %^RESET%^%^ORANGE%^"+
			"and %^BOLD%^%^WHITE%^furs%^RESET%^%^ORANGE%^.%^RESET%^"
	);

    set_smell("default","
		%^RESET%^%^ORANGE%^The smell of leathers and sweat assault you.%^RESET%^");
    set_listen("default","%^RESET%^%^CYAN%^You hear the buzzing of insects.%^RESET%^");


    set_exits(([ 
		"out" : GRASSLAND"grassland9",
	]));
}

