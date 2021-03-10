// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("lotus1");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("deep water");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^O%^CYAN%^n%^BOLD%^%^MAGENTA%^b%^CYAN%^o%^RESET%^%^GREEN%^a%^MAGENTA%^r%^BOLD%^d %^RESET%^%^MAGENTA%^the %^CYAN%^L%^BOLD%^o%^RESET%^%^MAGENTA%^t%^BOLD%^u%^RESET%^%^GREEN%^s%^RESET%^");

    set_long("%^CYAN%^The %^GREEN%^ship %^CYAN%^is bustling with %^BOLD%^activity %^RESET%^%^CYAN%^as cargo is loaded as quickly as it is unloaded. The owners must be successful to afford a ship so %^BOLD%^%^GREEN%"
	"^highly prized%^RESET%^%^CYAN%^. Nothing appears out of order. Every person aboard has their job and does it with effeciency. Most of the ship is blocked from the eyes of the public and the %^MAGENTA%"
	"^security %^CYAN%^is unusually high.%^RESET%^"
	);

    set_smell("default","
%^BOLD%^%^CYAN%^You can smell the sea air.%^RESET%^");
    set_listen("default","%^WHITE%^Waves crash noisly against the ship.%^RESET%^");

    set_search("crate","%^ORANGE%^Behind the crate is a small set of steps leading %^RED%^down.");
    set_search("ship","%^ORANGE%^There is an opening to the %^RED%^left %^ORANGE%^of one of the large cargo crates.");

    set_exits(([ 
		"left" : "/d/av_rooms/hlal/lotus2",
	]));



    set_invis_exits(({ "left" }));

}