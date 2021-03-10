// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("Devilhall");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("desert");

    set_short("a %^RESET%^%^CYAN%^immense%^BOLD%^%^BLACK%^ cavern");

    set_long("%^BOLD%^%^BLACK%^You enter a large %^RESET%^%^RED%^hallway%^BOLD%^%^BLACK%^. The hall is 15 feet wide and 15 feet high. %^YELLOW%^Torches%^BLACK%^ held by %^RESET%^%^WHITE%^skeletal%^BOLD%^%^BLACK%^ a"
	"rms lights the side of the hall keeping the middle in d%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^rkness. The walls is g%^GREEN%^l%^BLACK%^i%^GREEN%^s%^BLACK%^t%^GREEN%^e%^BLACK%^n%^GREEN%^i%^BLACK%^n%^GREEN"
	"%^g%^BLACK%^ in the light and %^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^ runs down the walls, and keep giving off a %^RED%^drip drip%^BLACK%^ sound when it hits the floor. The floor "
	"is sticky by %^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^, and your %^CYAN%^footprints%^BLACK%^ is shown by each step but is quickly filled by %^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%"
	"^d%^BOLD%^%^BLACK%^ again. A %^RESET%^%^GREEN%^smell%^BOLD%^%^BLACK%^ of i%^RESET%^%^ORANGE%^ron%^BOLD%^%^BLACK%^ and d%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^c%^RESET%^%^GREEN%^ay%^BOLD%^%^BLACK%^ is the"
	" dominant smells and you feel a bit %^RESET%^%^MAGENTA%^nauseated%^BOLD%^%^BLACK%^. The ceiling is hidden in d%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^rkness, and you wonder what the sh%^CYAN%^a%^BLACK%^do"
	"ws could hide. Sh%^CYAN%^a%^BLACK%^dows and sh%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^pes keeps moving around you, no substance to the f%^CYAN%^o%^BLACK%^rms, but you can clearly see %^RESET%^%^ORANGE%^"
	"claws%^BOLD%^%^BLACK%^ and a %^RED%^wings%^BLACK%^ from several of the sh%^CYAN%^a%^BLACK%^pes. A continuous %^RESET%^%^MAGENTA%^w%^WHITE%^a%^MAGENTA%^iw%^WHITE%^l%^MAGENTA%^iw%^WHITE%^n%^MAGENTA%^g%^"
	"BOLD%^%^BLACK%^ is constantly heard from the sh%^CYAN%^a%^BLACK%^pes and they sound like they are in a%^RED%^g%^BLACK%^ony and p%^RED%^a%^BLACK%^in. Several doors made of %^RESET%^%^GREEN%^moss%^BOLD%"
	"^%^BLACK%^ and %^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^ covered wood is set into the wall at intervals all the way down the hall, that seems to never end."
	);

    set_smell("default","
%^BOLD%^%^RED%^burning flesh and sulfur");
    set_listen("default","you hear the sounds of screaming and cackling off in the distance");


    set_exits(([ 
		"north" : "/d/av_rooms/asmodeus/torturechamber",
		"south" : "/d/av_rooms/asmodeus/portalroom",
	]));

}