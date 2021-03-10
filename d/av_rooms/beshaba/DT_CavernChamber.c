// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("DT_CavernChamber");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("desert");

    set_short("%^YELLOW%^C%^RESET%^%^ORANGE%^avern %^BOLD%^C%^RESET%^%^ORANGE%^hamber%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^The tunnel ends here, and billows out into a large chamber. Pieces of %^RESET%^d%^RED%^eb%^RESET%^r%^BOLD%^%^BLACK%^i%^RESET%^s %^ORANGE%^litter the area, but otherwise the room pos"
	"sesses a distinct shape accompanied by smooth walls and a level floor. A large hexagonal %^RESET%^o%^BOLD%^%^BLACK%^bel%^WHITE%^i%^BLACK%^s%^RESET%^k %^ORANGE%^of %^RESET%^b%^BOLD%^%^BLACK%^la%^WHITE%"
	"^c%^RESET%^k o%^BOLD%^%^BLACK%^bs%^WHITE%^i%^BLACK%^d%^WHITE%^i%^BLACK%^a%^RESET%^n %^ORANGE%^looms in the center of the room, and strange %^CYAN%^g%^BOLD%^ly%^WHITE%^p%^CYAN%^h%^RESET%^%^CYAN%^s %^OR"
	"ANGE%^fade in and out of existence along its surface.%^RESET%^"
	);

    set_smell("default","
The unsettled dust makes breathing difficult.");
    set_listen("default","A few stonefalls echo in the distance.");

    
set_items(([ 
	"debris" : "%^RESET%^%^ORANGE%^Large rocks have fallen from the rough ceiling, though most of the piles seem to keep to the periphery of the room. On a closer look, brittle %^RESET%^b%^BOLD%^one%^RESET%^s %^ORANGE%^and scraps of cloth peek out from beneath the crumbling stones.%^RESET%^",
	"glyphs" : "%^RESET%^%^CYAN%^Icons and symbols %^BOLD%^b%^WHITE%^l%^CYAN%^ur %^RESET%^%^CYAN%^into focus momentarily before fading into obscurity. Whatever the meaning could be, they leave your stomach %^RED%^chu%^BOLD%^r%^RESET%^%^RED%^ning %^CYAN%^and force you to look away.%^RESET%^",
	"obelisk" : "%^RESET%^%^MAGENTA%^This towering structure is crafted of a single gigantic piece of %^BOLD%^%^BLACK%^ab%^RESET%^%^MAGENTA%^y%^BOLD%^%^BLACK%^ssal obs%^WHITE%^i%^BLACK%^d%^WHITE%^i%^BLACK%^an%^RESET%^%^MAGENTA%^. Light seems to seep into the surface, never to return, and the %^BOLD%^%^BLACK%^m%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^dni%^RESET%^%^BLUE%^g%^BOLD%^%^BLACK%^ht %^RESET%^%^MAGENTA%^facade is only broken by the whispery %^CYAN%^i%^BOLD%^ma%^WHITE%^g%^CYAN%^e%^RESET%^%^CYAN%^s %^MAGENTA%^that ghost into being. The volcanic glass feels warm to the touch, and you swear there's a %^RED%^pulse%^MAGENTA%^... a deep, throbbing vibration that rumbles just below your sense of hearing.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/beshaba/DT_Cavern1",
	]));

}