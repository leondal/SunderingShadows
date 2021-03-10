// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("shadowplane");
    set_property("indoors",0);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("light forest");
    set_travel("foot path");
    set_climate("mountain");

    set_short("%^BOLD%^%^BLACK%^within a s%^RESET%^h%^BOLD%^%^BLACK%^a%^RESET%^d%^BOLD%^o%^BLACK%^w%^RESET%^e%^BOLD%^%^BLACK%^d c%^RESET%^l%^BOLD%^%^BLACK%^e%^RESET%^a%^BOLD%^r%^BLACK%^i%^RESET%^n%^BOLD%^%^BLACK%^g%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This is a %^RESET%^d%^BOLD%^r%^RESET%^%^CYAN%^e%^WHITE%^a%^CYAN%^r%^WHITE%^y %^BOLD%^%^BLACK%^and %^RESET%^%^ORANGE%^d%^WHITE%^i%^BOLD%^%^BLACK%^s%^RESET%^m%^BOLD%^%^BLACK%^a%^RESET%^"
	"%^ORANGE%^l %^BOLD%^%^BLACK%^clearing within a dark and twisted forest. Even with the %^RESET%^g%^ORANGE%^r%^WHITE%^ay s%^ORANGE%^k%^WHITE%^y %^BOLD%^%^BLACK%^clearly visible, it is difficult to make "
	"up the time of day, and a perpetual %^RESET%^%^CYAN%^t%^WHITE%^w%^BOLD%^%^BLACK%^i%^RESET%^l%^CYAN%^i%^BOLD%^%^BLACK%^g%^RESET%^h%^CYAN%^t %^BOLD%^%^BLACK%^seems to settle over the whole area. Breathi"
	"ng here quickly grows to be a chore, the air takes on a heavy and viscous texture, and brings with it a cold and damp clamminess. The %^RESET%^%^GREEN%^d%^BOLD%^%^BLACK%^a%^RESET%^%^GREEN%^rk%^BOLD%^%"
	"^BLACK%^e%^RESET%^%^GREEN%^n%^CYAN%^e%^GREEN%^d ve%^CYAN%^g%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^ta%^BOLD%^%^BLACK%^t%^RESET%^%^GREEN%^i%^CYAN%^o%^GREEN%^n %^BOLD%^%^BLACK%^here seems slightly wrong, so"
	"mehow, as if existing in some state other than life.%^RESET%^"
	);

    set_smell("default","
Your sense of smell seems oddly dulled, here.");
    set_listen("default","Mournful groans from the surrounding wilds occasionally pierce the silence.");

    
set_items(([ 
	({ "grass", "ground", "vegetation" }) : "%^BOLD%^%^BLACK%^None of the %^RESET%^%^GREEN%^plants %^BOLD%^%^BLACK%^here seems to be growing as you would expect, and the trees and grasses before you seems to be more a %^MAGENTA%^m%^RED%^o%^MAGENTA%^c%^CYAN%^k%^MAGENTA%^e%^RED%^r%^MAGENTA%^y %^BLACK%^of a forest than anything. Utterly %^RESET%^%^CYAN%^c%^WHITE%^o%^CYAN%^ld %^BOLD%^%^BLACK%^to the touch and %^RESET%^%^ORANGE%^sluggish %^BOLD%^%^BLACK%^in the way they sway in the clammy breeze, these wilds are clearly not of the natural world.%^RESET%^",
	({ "forest", "trees" }) : "%^BOLD%^%^BLACK%^The tall and twisted %^RESET%^%^GREEN%^t%^CYAN%^r%^GREEN%^e%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^s %^BOLD%^%^BLACK%^encircle you on all sides, causing all within them to vanish into an impenetrable d%^BLUE%^a%^BLACK%^r%^BLUE%^k%^BLACK%^ne%^BLUE%^s%^BLACK%^s.%^RESET%^",
	]));
}