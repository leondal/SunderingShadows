// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("cavecache");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("ledge");
    set_climate("mountain");

    set_short("%^RESET%^%^ORANGE%^an u%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^d%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^d %^BOLD%^%^BLACK%^c%^RESET%^a%^BOLD%^c%^RESET%^h%^BOLD%^%^BLACK%^e%^RESET%^");

    set_long("%^ORANGE%^This cramped, natural c%^WHITE%^a%^BOLD%^%^BLACK%^v%^RESET%^%^ORANGE%^e can't be more than twenty feet wide, and the highest point on the ceiling is no more than ten feet above you. The grou"
	"nd is bone dry, with its %^WHITE%^j%^BOLD%^%^BLACK%^a%^RESET%^g%^BOLD%^g%^BLACK%^e%^RESET%^d%^ORANGE%^, uneven surface making footing difficult. Against one wall, numerous %^BOLD%^crates%^RESET%^%^ORA"
	"NGE%^, %^RED%^chests%^ORANGE%^, and %^BOLD%^%^BLACK%^sacks %^RESET%^%^ORANGE%^have been piled up, and look to be filled with a number of old and spoiled supplies. Behind the supplies is a short, narro"
	"w tunnel that leads to a square w%^WHITE%^oo%^ORANGE%^d%^WHITE%^e%^ORANGE%^n d%^WHITE%^o%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^r in the cave wall.%^WHITE%^"
	);

    set_smell("default","
The scent of old sewage intermingles with the scent of something fouler");
    set_listen("default","Water trickles quietly past, and your splashing footsteps echo off the walls");

}