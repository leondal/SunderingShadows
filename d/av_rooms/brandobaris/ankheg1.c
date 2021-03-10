// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("ankheg1");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("nat tunnel");
    set_travel("game track");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^a cramped, %^RESET%^%^ORANGE%^l%^WHITE%^o%^BOLD%^%^BLACK%^a%^RESET%^m%^ORANGE%^y %^BOLD%^%^BLACK%^t%^RESET%^u%^BOLD%^%^BLACK%^n%^RESET%^n%^BOLD%^e%^BLACK%^l%^RESET%^");

    set_long("%^ORANGE%^The s%^WHITE%^o%^ORANGE%^ft, %^WHITE%^a%^ORANGE%^i%^BOLD%^%^BLACK%^r%^RESET%^y l%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^a%^WHITE%^m %^ORANGE%^in this freshly-dug section of tunnel is deceptivel"
	"y deep - it looks as if there should barely be room to stand in here, yet you can sink far enough into the earth for a normal human to be up to their knees in %^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^o%^W"
	"HITE%^i%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^. A %^WHITE%^pile %^ORANGE%^of conspicuous %^BOLD%^shapes %^RESET%^%^ORANGE%^and %^CYAN%^figures %^ORANGE%^pokes out of the dirt near to the edge of one of "
	"the walls. The %^BOLD%^%^BLACK%^w%^RESET%^a%^ORANGE%^l%^WHITE%^l%^BOLD%^%^BLACK%^s %^RESET%^%^ORANGE%^themselves look quite soft and unstable, as if they might collapse at any moment.%^WHITE%^"
	);

    set_smell("default","
The smell of damp, loam, and a fresh dig permeates this space");
    set_listen("default","You can hear things clicking and moving about, from the other side of the dirt walls");

    set_search("loam","%^ORANGE%^A large heap of %^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^o%^WHITE%^a%^BOLD%^%^BLACK%^m %^RESET%^%^ORANGE%^lies at one end of the tunnel, looking to have recently collapsed. You can just make out some faint %^CYAN%^noises %^ORANGE%^from behind the pile...it would be a chore to do so, but one couple possibly dig through the %^BOLD%^loam %^RESET%^%^ORANGE%^and make their way to the other side.%^WHITE%^");
    set_search("soil","%^ORANGE%^Searching through all of the soft soil here causes you to make a mess of yourself, with the dirt more than happy to get everywhere on and around you. However, your attention is drawn to the strange %^BOLD%^%^WHITE%^objects %^RESET%^%^ORANGE%^sticking out of the dirt, and to a few oddities near the %^BOLD%^%^BLACK%^walls%^RESET%^%^ORANGE%^.%^WHITE%^");
    set_search("pile","%^ORANGE%^It takes a bit of digging, heaving, and pulling to see them clearly, but you have just discovered a large pile of %^WHITE%^s%^BOLD%^k%^RESET%^e%^BOLD%^l%^RESET%^e%^BOLD%^t%^RESET%^o%^BOLD%^n%^RESET%^s %^ORANGE%^and %^GREEN%^half-digested %^RED%^c%^BOLD%^o%^RESET%^%^GREEN%^r%^BOLD%^%^RED%^p%^RESET%^s%^BOLD%^e%^RESET%^%^RED%^s%^ORANGE%^. Most of them livestock such as cattle, whatever left them here was strong enough to have snapped their bones clean in two. The faint, %^BOLD%^%^GREEN%^acrid stench %^RESET%^%^ORANGE%^of some type of %^BOLD%^%^GREEN%^a%^WHITE%^c%^RESET%^i%^BOLD%^%^GREEN%^d %^RESET%^%^ORANGE%^clings to the remains.%^WHITE%^");
    
set_items(([ 
	({ "wall", "walls" }) : "%^ORANGE%^The %^BOLD%^%^BLACK%^walls %^RESET%^%^ORANGE%^are s%^WHITE%^o%^BOLD%^%^BLACK%^f%^RESET%^%^ORANGE%^t, and it looks as if any number of tunnels may have been dug in the soil, only to have collapsed again. A particularly large heap of %^BOLD%^loam %^RESET%^%^ORANGE%^lies at one end of the tunnel.%^WHITE%^",
	]));

    set_exits(([ 
		"up" : "/d/shadow/room/kildare/rooms/town/pad4",
		"loam" : "/d/av_rooms/brandobaris/ankheg2",
	]));



    set_invis_exits(({ "loam" }));

}