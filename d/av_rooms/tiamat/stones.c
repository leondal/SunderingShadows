// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("stones");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("cemetery");
    set_travel("game track");
    set_climate("temperate");

    set_short("%^ORANGE%^The Standing %^BOLD%^%^BLACK%^Stones%^RESET%^");

    set_long("%^RESET%^%^GREEN%^You have appeared in a large clearing nestled atop a lightly wooded hill.  Down and in the distance, the ancient %^BOLD%^%^BLACK%^black trees%^RESET%^%^GREEN%^ are densely packed. Th"
	"e cleared hill is host to enormous %^RESET%^stone monoliths%^GREEN%^, formed into a ring about two dozen feet in diameter.  Most of the monoliths are single standing slabs of granite rising over a sto"
	"ry into the sky.  Each one is weathered with age, ivy and a worn-looking circular %^ORANGE%^script%^GREEN%^.  In each of the cardinal directions stands a primitive %^RESET%^gate%^GREEN%^ made of three"
	" monolithic stones-two standing side by side and a third crossing the tops.  The native grasses within the stone formations have been worn down through traffic, although the monoliths themselves do no"
	"t look maintained.  There is a primal energy in the air neither benign nor malevolent.%^RESET%^"
	);

    set_smell("default","
%^ORANGE%^You smell herd animals and vegetation.");
    set_listen("default","%^GREEN%^You hear birds of prey high above.");

    
set_items(([ 
	({ "monolith", "monoliths" }) : "The free standing monoliths are huge slabs of granite.  They are each approximately 3 feet by 3 feet and a story high.  As indicated by the ivy and weathered %^ORANGE%^script%^RESET%^, they are very old indeed.",
	"gate" : "Three large stones make up a gate.  Two shorter monoliths stand parallel about three feet apart, and a third tops the other two.  There is no %^ORANGE%^script%^RESET%^ on the monoliths used in the gates.",
	"script" : "%^ORANGE%^The writing on the slabs is very unusual.  The patterns are distinct enough that you can guess it is a language, but none that you recognize.  To a casual observation, it looks very much like intricate swirly loops carved into the monoliths.%^RESET%^",
	"trees" : "%^BOLD%^%^BLACK%^The trees surrounding the hill are dark in color, ancient and almost hostile looking.  It is no surprise that this place remains so well hidden.%^RESET%^",
	]));
}