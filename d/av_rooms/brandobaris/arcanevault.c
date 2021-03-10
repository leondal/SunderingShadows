// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("arcanevault");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^a m%^RESET%^%^MAGENTA%^y%^BOLD%^s%^BLACK%^t%^RESET%^%^MAGENTA%^e%^BOLD%^r%^BLACK%^i%^RESET%^%^MAGENTA%^o%^BOLD%^u%^BLACK%^s m%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^r%^MAGENTA%^b%^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^e v%^RESET%^%^MAGENTA%^a%^BOLD%^u%^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^t%^RESET%^");

    set_long("%^MAGENTA%^It seems to have been ages since this room last saw any use. A large and %^BOLD%^ele%^WHITE%^g%^MAGENTA%^ant %^RESET%^%^MAGENTA%^room, this sweeping chamber is nearly fifty yards from one e"
	"nd to the other and nearly twice that long. Underfoot lies a floor of smooth tiles of %^BOLD%^%^BLACK%^bl%^RESET%^a%^BOLD%^%^BLACK%^ck m%^RESET%^a%^BOLD%^r%^BLACK%^b%^RESET%^l%^BOLD%^%^BLACK%^e%^RESET"
	"%^%^MAGENTA%^, covered in a thin layer of %^ORANGE%^d%^WHITE%^u%^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^t%^MAGENTA%^, while ornate columns of %^WHITE%^dull white %^MAGENTA%^stone protrude from the floor, "
	"rising up to support a vaulted ceiling of %^BOLD%^%^BLUE%^d%^BLACK%^a%^BLUE%^rk sa%^BLACK%^p%^RESET%^%^CYAN%^p%^BOLD%^%^BLUE%^h%^CYAN%^i%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^e%^RESET%^%^MAGENTA%^. At the "
	"far end of the room lies a number of short %^BOLD%^%^WHITE%^display tables%^RESET%^%^MAGENTA%^, and against the far wall, a large ornate %^BOLD%^%^BLACK%^door %^RESET%^%^MAGENTA%^of %^WHITE%^m%^BOLD%^"
	"ar%^RESET%^b%^BOLD%^%^BLACK%^l%^RESET%^e%^MAGENTA%^.%^WHITE%^"
	);

    set_smell("default","
All you can smell is dust, with the occasional hint of old books");
    set_listen("default","Only your own noises echo off the walls of this place");

    
set_items(([ 
	"table 1" : "%^BOLD%^%^BLACK%^Within the dusty glass of the first display table is a large vase, wrought of masterfully worked o%^RESET%^b%^BOLD%^s%^BLACK%^idi%^RESET%^a%^BOLD%^%^BLACK%^n. With no gaps or imperfections to be seen upon its elegant contours, surely magic had a hand in its shaping. Its lip looks to be dangerously sharp, narrowing to a blade-like edge, and several ancient %^RESET%^%^RED%^bloodstains %^BOLD%^%^BLACK%^running down its neck seem to drive home the importance of handling it with care. Upon the vase is a prominent symbol - a circle of b%^RESET%^l%^BOLD%^%^BLACK%^a%^RESET%^c%^BOLD%^%^BLACK%^k j%^RESET%^e%^BOLD%^%^BLACK%^t eclipsing another of rich %^RESET%^%^MAGENTA%^a%^WHITE%^m%^BOLD%^e%^MAGENTA%^t%^RESET%^%^MAGENTA%^h%^BOLD%^y%^RESET%^%^MAGENTA%^st%^BOLD%^%^BLACK%^.",
	"table 2" : "%^BOLD%^%^BLACK%^You are quite sure that breaking the glass of this second display table would be a grave mistake. L%^RESET%^iv%^BOLD%^%^BLACK%^i%^RESET%^n%^BOLD%^%^BLACK%^g s%^RESET%^ha%^BOLD%^%^BLACK%^d%^RESET%^ow%^BOLD%^%^BLACK%^s are trapped within, filling the entirety of its volume with s%^RESET%^w%^BOLD%^i%^RESET%^r%^BOLD%^%^BLACK%^l%^RESET%^%^CYAN%^i%^BOLD%^%^BLACK%^ng and s%^RESET%^%^CYAN%^h%^WHITE%^ift%^BOLD%^%^BLACK%^i%^RESET%^n%^BOLD%^%^BLACK%^g blackness. Utterly formless, they still seem to give the impression that their gaze is fixed upon you.",
	"table 3" : "%^MAGENTA%^A large %^CYAN%^painting %^MAGENTA%^occupies much of the third display table. It depicts a %^GREEN%^d%^ORANGE%^e%^GREEN%^n%^ORANGE%^s%^GREEN%^e%^ORANGE%^l%^GREEN%^y w%^ORANGE%^oo%^GREEN%^d%^ORANGE%^e%^GREEN%^d %^ORANGE%^work site %^MAGENTA%^in the dead of night, with the willowy form of a %^BOLD%^%^BLACK%^raven-haired goddess %^RESET%^%^MAGENTA%^wrapped up in the %^BOLD%^%^BLACK%^darkness %^RESET%^%^MAGENTA%^of the %^CYAN%^e%^BOLD%^%^BLACK%^m%^RESET%^%^CYAN%^p%^BOLD%^%^BLACK%^t%^RESET%^%^CYAN%^y s%^BOLD%^%^BLACK%^k%^RESET%^%^CYAN%^y%^MAGENTA%^. She looks down upon a number of her followers as they toil under her direction, a pleased smirk upon her face. Within the woods labor a number of carpenters and masons, while some %^BOLD%^%^BLACK%^darkly robed magi %^RESET%^%^MAGENTA%^chant on, infusing the materials themselves with the stuff of %^BOLD%^%^BLACK%^s%^RESET%^h%^BOLD%^%^BLACK%^ad%^RESET%^o%^BOLD%^%^BLACK%^w%^RESET%^%^MAGENTA%^.",
	"door" : "%^BOLD%^%^BLACK%^This ornate door is about fifteen feet in height, and wrought of black m%^RESET%^a%^BOLD%^r%^BLACK%^b%^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^e, with veins of oddly %^MAGENTA%^vibrant %^RESET%^%^MAGENTA%^p%^BOLD%^u%^RESET%^%^MAGENTA%^r%^BOLD%^p%^RESET%^l%^MAGENTA%^e %^BOLD%^%^BLACK%^running throughout. Three %^BLUE%^dull sapphires %^BLACK%^are set into the top of the door's rounded frame, too conspicuous for mere decoration, but their purpose not apparent. A large %^RESET%^keyhole %^BOLD%^%^BLACK%^is set into the center of the door, next to a small, carved alcove to serve as a handle on the large door. An inscription is engraved into its center around a circle of gemstone: %^WHITE%^SACRIFICE%^BLACK%^. Within that circle lie a number of %^RESET%^%^RED%^bloody handprints%^BOLD%^%^BLACK%^.",
	"tables" : "%^MAGENTA%^There are three tables here, each looking to hold some kind of artifact.",
	]));
}