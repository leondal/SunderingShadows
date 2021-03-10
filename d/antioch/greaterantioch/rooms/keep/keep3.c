#include <std.h>
#include "../../gantioch.h"
#include <daemons.h>

inherit VAULT;

void create()
{
    ::create();
    set_name("keep1");
    set_property("indoors",1);
    set_property("light",3);
    set_property("no teleport",0);

    set_short("%^BOLD%^%^YELLOW%^Foyer of a Keep%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^The foyer of this massive structure is wide open as you enter. The walls here are"+
			" covered in fine %^BOLD%^%^MAGENTA%^tapestries %^BOLD%^%^WHITE%^and the floor, made of marble,"+
			" shines. A long %^RESET%^%^RED%^red carpet %^BOLD%^%^WHITE%^extends"+
			" the length of this room, from the door to the hallway ahead. On either side of the room you see archways to"+
			" other chambers. The ceiling of this room his vaulted with large wooden beams accenting"+
			" and supporting the structure above. Next to the door is a pedestal with a suit of %^BOLD%^%^CYAN%^armor%^BOLD%^%^WHITE%^ which"+
			" seems to stand protectively of this room. A large %^BOLD%^%^RED%^polearm %^BOLD%^%^WHITE%^rests next to it, balanced perfectly. \n\n"+
			"%^RESET%^%^ORANGE%^A massive door stands locked tight, obviously not allowing passage to the south.");

    set_smell("default","\n%^BOLD%^%^MAGENTA%^The smell of incense fills the air.%^RESET%^");
    set_listen("default","%^BOLD%^%^YELLOW%^You hear praying coming from the east and talking to the north.%^RESET%^");

    set_items(([
      "tapestries"    : "%^BOLD%^%^GREEN%^The beautiful tapestries are well made, however, they seem to be flipped upside down and you cannot see what's on them. Perhaps the owner will reveal them in time.",
      "red carpet" : "%^BOLD%^%^YELLOW%^The beautiful carpet here is plush underneath your feet and looks extremely well made.",
      "armor"   : "%^BOLD%^%^CYAN%^This armor is decorative in nature, seemingly to stand eternally in protection of this place.",
      "polearm" : "%^BOLD%^%^WHITE%^This well crafted, decorative polearm has a holy symbol of %^BOLD%^%^YELLOW%^Jarmila %^BOLD%^%^WHITE%^engraved into it's head.",
    ]) );

    set_exits(([
		"east"	: KEEP"keep5",
		"west"	: KEEP"keep6",
		"out"	: KEEP"keep2",
	]));
	set_door("gate","/realms/klieth/greaterantioch/rooms/keep/keep2","out","somekey");
	set_open("gate",0);
	set_string("gate","open","%^RESET%^%^ORANGE%^The massive wooden door lifts up, allowing you entrance.");
    set_lock_description("gate","lock","This is a huge bar across the giant
door.");
    set_door_description("gate","These are two huge solid wooden doors that
come together in the middle. They are bound together with giant dwarven
forged iron bands.");
    lock_difficulty("gate",-2000,"lock");
	}

