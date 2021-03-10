// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("lotus2");
    set_property("indoors",1);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("boats");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^CYAN%^O%^MAGENTA%^n%^GREEN%^b%^BOLD%^%^MAGENTA%^o%^CYAN%^a%^GREEN%^r%^RESET%^%^CYAN%^d the %^BOLD%^%^MAGENTA%^L%^RESET%^%^CYAN%^o%^BOLD%^t%^WHITE%^u%^RESET%^%^MAGENTA%^s%^CYAN%^- %^MAGENTA%^Guest Room%^RESET%^");

    set_long("%^CYAN%^These guest quarters are decorated %^GREEN%^l%^BOLD%^a%^RESET%^%^GREEN%^v%^BOLD%^i%^BLACK%^s%^RESET%^%^GREEN%^hly. %^CYAN%^Not a coin was spared in ensuring the comfort and %^BOLD%^entertainme"
	"nt %^RESET%^%^CYAN%^of the ship's guests%^BOLD%^%^WHITE%^. %^RESET%^%^CYAN%^It has a well-stocked %^MAGENTA%^bar %^CYAN%^with a great view of the %^BOLD%^o%^WHITE%^c%^GREEN%^e%^CYAN%^a%^RESET%^%^CYAN%"
	"^n from the one large %^BOLD%^%^MAGENTA%^window %^RESET%^%^CYAN%^behind it. A %^BOLD%^%^RED%^desk %^RESET%^%^CYAN%^of %^RED%^cherry wood %^CYAN%^sits near a over-sized bed. %^BOLD%^%^WHITE%^Papers %^R"
	"ESET%^%^CYAN%^are scattered along the desk.%^RESET%^"
	);

    set_smell("default","
%^RESET%^%^RED%^Scented candles leave the air strong with spices%^RESET%^");
    set_listen("default","%^BOLD%^%^RED%^An old music box plays a strange song%^RESET%^");

    set_search("journal","%^BOLD%^%^BLACK%^There doesn't appear to be any visible traps on it if you wish to take it.%^RESET%^");
    set_search("view","%^BOLD%^%^GREEN%^The view is spectacular!");
    set_search("papers","%^BOLD%^%^BLACK%^Random junk but under the papers is a journal%^RESET%^");
    set_search("window","%^MAGENTA%^Curtains decorated in poppy blossoms line the large window%^RESET%^");
    set_search("bar","%^ORANGE%^Stocked with any beverage you could imagine%^RESET%^");
    set_search("desk","%^BOLD%^%^BLACK%^Under the papers is a journal%^RESET%^");

    set_exits(([ 
		"out" : "/d/av_rooms/hlal/lotus1",
	]));

}