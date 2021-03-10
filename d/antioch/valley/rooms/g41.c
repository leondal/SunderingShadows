#include <std.h>
#include "../valley.h"
inherit PDRUID;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"g42",
	"east" : ROOMS+"v81",
	"north" : ROOMS+"g45",
	"south" : ROOMS+"v83",
	]) );
	set_short("%^BOLD%^%^GREEN%^Grasslands%^RESET%^");
	set_long(
	"%^BOLD%^%^GREEN%^Green grass%^RESET%^%^GREEN%^ reaches up past your ankles and"+
	" stretches for as far as the eye can see. There"+
	" are several tall trees scattered throughout"+
	" the valley and the wind blows through their"+
	" %^ORANGE%^branches%^GREEN%^, making them sway. %^BOLD%^%^WHITE%^"+
        "Rabbits%^RESET%^%^GREEN%^ and other"+
	" small animals scamper about in the %^BOLD%^grass%^RESET%^%^GREEN%^ and you"+
	" can even see %^ORANGE%^deer%^GREEN%^ grazing in the distance. Bright"+
	" colored %^MAGENTA%^b%^BOLD%^u%^RESET%^%^MAGENTA%^tt%^WHITE%^%^BOLD%^e"+
        "%^RESET%^%^MAGENTA%^rf%^BOLD%^l%^RESET%^%^MAGENTA%^ies%^GREEN%^ float around in the wind and"+
	" some %^BOLD%^%^BLUE%^birds%^RESET%^%^GREEN%^ are perched in the trees, singing"+
	" happily.\n"
	);
	set("night long",
	"%^BOLD%^%^WHITE%^Starlight%^RESET%^%^GREEN%^ is spread over the valley, bathing it"+
	" in %^RESET%^%^BOLD%^silver%^RESET%^%^GREEN%^. The trees look mystical, their leaves"+
	" reflect the moonlight and seem almost to %^BOLD%^%^CYAN%^glow%^RESET%^%^GREEN%^."+
	" As the wind blows them they almost seem to be"+
	" following some sacred, ancient dance. Even the"+
	" grass at your feet reflects some of the %^BOLD%^%^WHITE%^silver%^RESET%^%^GREEN%^."+
	" You can see %^YELLOW%^fireflies%^RESET%^%^GREEN%^ in the distance as bright"+
	" pinpoints of %^YELLOW%^yellow%^RESET%^%^GREEN%^ light. Some %^MAGENTA%^nightingales"+
	" %^GREEN%^are singing a beautiful melody in the distance."+
	" All the other animals seem to have gone to sleep.\n"
	);
	set_smell("default",
	"You can smell the grass beneath your feet."
	);
	set_listen("default",
	"Bird song echoes throughout the vale."
	);
	set_items( ([
	"grass" : "%^GREEN%^%^BOLD%^The grass is lush and green.",
	"birds" : "%^BOLD%^%^BLUE%^You can see some birds perched in"+
	" distant trees.",
	"butterflies" : "%^BOLD%^%^MAGENTA%^Brightly colored butterflies"+
	" float on the wind.",
	"rabbits" : "%^BOLD%^They scamper quickly away from you.",
	"deer" : "%^ORANGE%^The deer are grazing peacefully.",
	"fireflies" : "%^YELLOW%^In the distance they are seen as"+
	" a bright spot of light, bobbing up and down and"+
	" darting all over the valley.",
	]) );
}
