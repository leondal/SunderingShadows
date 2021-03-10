// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("druidgrove");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("heavy forest");
    set_travel("rutted track");
    set_climate("temperate");

    set_short("%^ORANGE%^an o%^GREEN%^v%^ORANGE%^e%^GREEN%^r%^ORANGE%^g%^GREEN%^r%^ORANGE%^o%^GREEN%^w%^ORANGE%^n f%^GREEN%^o%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^e%^GREEN%^s%^ORANGE%^t g%^GREEN%^r%^BOLD%^%^BLACK%^o%^RESET%^%^GREEN%^v%^ORANGE%^e%^WHITE%^");

    set_long("%^ORANGE%^This small %^GREEN%^grove %^ORANGE%^must have gone years since its last visit, heavily overgrown with %^GREEN%^v%^BOLD%^%^BLACK%^i%^RESET%^%^GREEN%^n%^WHITE%^e%^GREEN%^s%^ORANGE%^, %^GREEN%^"
	"b%^ORANGE%^u%^BOLD%^%^BLACK%^s%^RESET%^%^GREEN%^h%^ORANGE%^e%^GREEN%^s %^ORANGE%^and %^GREEN%^f%^BOLD%^l%^RED%^o%^MAGENTA%^w%^RESET%^%^GREEN%^e%^BOLD%^%^WHITE%^r%^RESET%^%^GREEN%^s%^ORANGE%^. A large "
	"%^BOLD%^%^GREEN%^tree %^RESET%^%^ORANGE%^with %^BOLD%^%^WHITE%^white bark %^RESET%^%^ORANGE%^towers upward into the sky here, its outstretched boughs casting the entirety of the grove into a %^CYAN%^c"
	"ool shade%^ORANGE%^. It almost looks as if this may have once been a place of gathering, as several %^WHITE%^sitting stones %^ORANGE%^are still visible in the earth, poking up through the foliage here"
	" and there, and a large, platform-like %^WHITE%^r%^BOLD%^%^BLACK%^o%^RESET%^ck %^ORANGE%^has been set before the tree.%^WHITE%^"
	);

    set_smell("default","
The fresh and floral scent of the wilds wafts through the air.");
    set_listen("default","You hear the sounds of the wilds all around you.");

    
set_items(([ 
	({ "stones", "rock" }) : "Buried almost entirely in the %^ORANGE%^dirt %^WHITE%^and %^GREEN%^foliage%^WHITE%^, it must have been at least centuries since this place has seen regular use.",
	({ "flowers", "bushes", "grass", "ground" }) : "%^GREEN%^The terrain here is difficult to navigate, so overgrown by the various %^BOLD%^vines%^RESET%^%^GREEN%^, %^ORANGE%^bushes%^GREEN%^, and %^BOLD%^f%^RED%^l%^GREEN%^o%^ORANGE%^w%^MAGENTA%^e%^GREEN%^rs%^RESET%^%^GREEN%^.",
	"tree" : "%^BOLD%^The l%^RESET%^a%^BOLD%^r%^RESET%^g%^BOLD%^e w%^RESET%^h%^BOLD%^i%^RESET%^t%^BOLD%^e t%^RESET%^r%^BOLD%^e%^RESET%^e %^BOLD%^here is easily forty feet tall, towering above you and high into the sky. Oddly, upon some thought it becomes apparent that despite its height and visibility, this tree cannot be seen from anywhere else within the forest.%^RESET%^",
	]));
}