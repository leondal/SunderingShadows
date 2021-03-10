// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    set_name("aash_trail3");
    set_property("indoors",0);
    set_property("light",0);
    set_terrain(BRANCHES);
    set_travel(RUTTED_TRACK);
    set_climate("temperate");

    set_short("%^BOLD%^%^GREEN%^B%^RESET%^%^CYAN%^e%^BOLD%^%^GREEN%^ne%^RESET%^%^CYAN%^a%^BOLD%^%^GREEN%^th %^RESET%^%^CYAN%^A%^BOLD%^%^GREEN%^rched %^RESET%^%^ORANGE%^T%^YELLOW%^r%^RESET%^%^ORANGE%^ees%^RESET%^");

    set_long("%^RESET%^%^CYAN%^You stand beneath the limbs of %^BOLD%^%^GREEN%^mighty trees%^RESET%^%^CYAN%^ which almost seem to bend together to form a kind of %^RESET%^%^ORANGE%^o%^YELLOW%^u%^RESET%^%^ORANGE%^td"
	"o%^YELLOW%^o%^RESET%^%^ORANGE%^r h%^YELLOW%^a%^RESET%^%^ORANGE%^ll%^YELLOW%^w%^RESET%^%^ORANGE%^ay%^CYAN%^. The heavy underbrush prevents any kind of passage but the way ahead on a blanket of %^BLUE%^"
	"p%^GREEN%^i%^BLUE%^n%^GREEN%^e%^CYAN%^ needles. The veiled sky above casts %^BOLD%^%^BLACK%^s%^RESET%^h%^BOLD%^%^BLACK%^a%^RESET%^d%^BOLD%^%^BLACK%^o%^RESET%^w%^BOLD%^%^BLACK%^y%^RESET%^%^CYAN%^ bands"
	" of %^YELLOW%^light%^RESET%^%^CYAN%^ and %^MAGENTA%^dark%^CYAN%^ obscuring the view. There are gaps here and there, which look out upon a %^RED%^terrifying wood%^CYAN%^, with dark moving shapes. Yet h"
	"ere, animals seem strangely absent, and it seems you are on a kind of %^MAGENTA%^f%^BOLD%^o%^RESET%^%^MAGENTA%^r%^BOLD%^g%^RESET%^%^MAGENTA%^o%^BOLD%^t%^RESET%^%^MAGENTA%^t%^BOLD%^e%^RESET%^%^MAGENTA%"
	"^n%^ORANGE%^ p%^YELLOW%^a%^RESET%^%^ORANGE%^th%^RESET%^. "
	);

    set_smell("default","
You smell pine needles.");
    set_listen("default","%^BOLD%^%^BLACK%^It is strangely quiet. Muffled beyond the safety of the trees you can hear the %^RED%^t%^RESET%^%^RED%^e%^BOLD%^%^RED%^r%^RESET%^%^RED%^r%^BOLD%^%^RED%^i%^RESET%^%^RED%^f%^BOLD%^y%^RESET%^%^RED%^i%^BOLD%^%^RED%^n%^RESET%^%^RED%^g%^BOLD%^%^BLACK%^ sounds of deathly creatures %^RESET%^%^GREEN%^h%^BOLD%^u%^RESET%^%^GREEN%^n%^BOLD%^t%^RESET%^%^GREEN%^i%^BOLD%^n%^RESET%^%^GREEN%^g.%^RESET%^");

    set_search("needles","You find little in the trees or underbrush. A quick search of the pine needles reveal little but the earth and roots.");
    set_search("path","A search of the path reveals that it seems no one has walked this way in a very long time. Somehow the creatures beyond have not been able to find this place.");
    set_search("animals","There are no animals around.");
    set_search("underbrush","You find little in the trees or underbrush. A quick search of the pine needles reveal little but the earth and roots.");
    set_search("trees","You find little in the trees or underbrush. A quick search of the pine needles reveal little but the earth and roots.");
    
set_items(([ 
	"darkness" : "The light is gritty and its hard to see much of anything.",
	"light" : "The light is gritty and its hard to see much of anything.",
	"branches" : "The branches overhead for an incomplete arch that shields the path from view.",
	"shadows" : "The light is gritty and its hard to see much of anything.",
	"path" : "The path seems to wind between the gaps in the towering trees.",
	"limbs" : "The branches overhead for an incomplete arch that shields the path from view.",
	"trees" : "The trees seem ancient, almost timeless. They are extremely large and it would take five or six human men to link arms to be able to complete surround one.",
	]));

    set_exits(([ 
		"southeast" : "/d/antioch/vale/forest/aash_trail2",
		"north" : "/d/antioch/vale/forest/aash_trail5",
	]));

}