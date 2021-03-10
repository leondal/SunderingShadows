// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("acidlakecavity");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^MAGENTA%^F%^RESET%^%^MAGENTA%^a%^BOLD%^e%^RESET%^%^MAGENTA%^z%^BOLD%^r%^RESET%^%^MAGENTA%^e%^BOLD%^s%^RESET%^%^MAGENTA%^s %^CYAN%^C%^BOLD%^r%^RESET%^%^CYAN%^y%^BOLD%^s%^WHITE%^ta%^CYAN%^l%^RESET%^%^CYAN%^ C%^BOLD%^a%^WHITE%^v%^BOLD%^%^CYAN%^e%^RESET%^");

    set_long("%^RESET%^You find yourself in a glittering cave of solid %^BOLD%^%^MAGENTA%^Faezress %^CYAN%^Crystal%^RESET%^. The %^BOLD%^%^GREEN%^acid%^RESET%^ of the lake has eaten away at the minerals deep in the"
	" mountain until this cave was carved out of the solid crystal deposit. The cave is bright with the magical light from the %^YELLOW%^luminous%^RESET%^ Faezress. The entrance to the cave is a large crac"
	"k at the roof of the cave. A treacherous %^BLUE%^jelly%^RESET%^ like substance of emulsified crystals and acid has created a giant plug that keeps this room relatively dry. An opening at the eastern s"
	"ide of the cave opens into the %^BOLD%^%^RED%^central shaft%^RESET%^ of the mountain that runs from the volcanic roots to its very peak."
	);

    set_smell("default","
The faint acrid smell of acid lingers in the cave.");
    set_listen("default","You can hear a drip of acid from the ceiling.");

}