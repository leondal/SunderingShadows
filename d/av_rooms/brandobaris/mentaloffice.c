// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("mentaloffice");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^a %^GREEN%^s%^WHITE%^t%^GREEN%^r%^WHITE%^a%^GREEN%^n%^WHITE%^g%^GREEN%^e%^WHITE%^, o%^RESET%^f%^BOLD%^f%^RESET%^i%^BOLD%^ce-l%^RESET%^i%^BOLD%^ke room%^RESET%^");

    set_long("%^BOLD%^This small %^RESET%^office %^BOLD%^can't be more than ten feet across, either way, yet the space between its walls feels as it it might be %^RESET%^%^MAGENTA%^infinite %^BOLD%^%^WHITE%^in dist"
	"ance - no amount of steps you take in any direction seems to bring you nearer to the edges of the room. The walls of the room are smooth, and %^RESET%^stark white%^BOLD%^, while the floor is covered b"
	"y a %^RESET%^%^RED%^p%^WHITE%^l%^BOLD%^%^BLACK%^u%^RESET%^s%^RED%^h r%^WHITE%^e%^RED%^d c%^BOLD%^%^BLACK%^a%^RESET%^r%^BOLD%^%^BLACK%^p%^RESET%^e%^RED%^t%^BOLD%^%^WHITE%^. A number of odd %^RESET%^%^C"
	"YAN%^p%^BOLD%^a%^RESET%^%^CYAN%^i%^BOLD%^%^GREEN%^n%^RESET%^%^CYAN%^ti%^BOLD%^n%^RESET%^%^CYAN%^gs %^BOLD%^%^WHITE%^and %^BLUE%^p%^RESET%^o%^BOLD%^r%^BLUE%^t%^CYAN%^r%^BLUE%^a%^WHITE%^i%^RESET%^t%^BOL"
	"D%^%^BLUE%^s %^WHITE%^line the walls, each of them portraying some important image from your memory, or some familiar face. A simple %^RESET%^%^ORANGE%^wooden door %^BOLD%^%^WHITE%^presumably leads ou"
	"t of this place, but even if you could reach it, it always seems to be set into the wall furthest from you. A single small %^RESET%^%^ORANGE%^desk%^BOLD%^%^WHITE%^, its surface clear, sits in the cent"
	"er of the room, and two %^RESET%^%^ORANGE%^chairs %^BOLD%^%^WHITE%^sit facing it on either side.%^RESET%^"
	);

    set_smell("default","
You smell your fondest scent from your childhood.");
    set_listen("default","The room is deathly quiet, but for a familiar tune that echoes in your ears.");

}