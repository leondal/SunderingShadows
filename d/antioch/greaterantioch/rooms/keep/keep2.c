#include <std.h>
#include "../../gantioch.h"
#include <daemons.h>

inherit VAULT;

void create()
{
    ::create();
    set_name("keep2");
    set_property("indoors",0);
    set_terrain(ROCKY);
    set_travel(DIRT_ROAD);
    set_property("light",3);
    set_property("no teleport",0);

    set_short("%^BOLD%^%^YELLOW%^Entrance to a Keep%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^The entrance of this massive structure stands before you. Made entirely out of"+
			" %^RESET%^%^ORANGE%^stone%^BOLD%^%^WHITE%^, the structure stands atop this small rise in the earth"+
			" giving the owner a fantastic view over the surrounding %^BOLD%^%^YELLOW%^land%^BOLD%^%^WHITE%^. The large"+
			" %^RESET%^%^ORANGE%^oak gate%^BOLD%^%^WHITE%^ is reinforced with steel."+
			" The walkway is made of compressed %^RESET%^%^ORANGE%^dirt %^BOLD%^%^WHITE%^and continues down to the"+
			" road below. On the left side of the large gate hangs a %^BOLD%^%^YELLOW%^banner"+
			" %^BOLD%^%^WHITE%^and on the right side, a %^BOLD%^%^RED%^second banner%^BOLD%^%^WHITE%^ which"+
			" hangs prominantly. A few %^RESET%^%^BLUE%^windows %^BOLD%^%^WHITE%^high up, with a balcony looking to the south."
			);

    set_smell("default","\n%^BOLD%^%^GREEN%^The smell of the forest is still strong here.%^RESET%^");
    set_listen("default","%^RESET%^%^CYAN%^You hear the chirping of birds in the background.%^RESET%^");

    set_items(([
      "stone"    : "%^BOLD%^%^WHITE%^The stones here are made of rough, though fine quality masonry.",
      "land" : "%^BOLD%^%^YELLOW%^From here you can view the vast lands of New Antioch, stretching west out of the mountains"+
      " and into a massive wooded valley below. Villages can be seen far off in the distance and you realize there is much to"+
      " explore ahead.",
      "dirt" : "%^RESET%^%^ORANGE%^The dirt here is hard packed here, from constant travel.",
      "windows"  : "%^BOLD%^%^CYAN%^The windows are far up the keep, offering what you would guess is an even better view then here.",
      "banner"  : "%^BOLD%^%^YELLOW%^This large banner depicts the herald of the %^BOLD%^%^WHITE%^King of New Antioch%^BOLD%^%^YELLOW%^.",
      "second banner"   : "%^BOLD%^%^RED%^This is a large symbol of %^BOLD%^%^YELLOW%^Jarmila%^BOLD%^%^RED%^.",
    ]) );


    set_exits(([
		"north" : KEEP"keep1",
		"enter"	: KEEP"keep3",
	]));
	set_door("gate","/realms/klieth/greaterantioch/rooms/keep/keep3","enter","somekey");
	set_open("gate",0);
	set_string("gate","open","%^RESET%^%^ORANGE%^The massive wooden door lifts up, allowing you entrance.");
    set_string("gate","close","%^RESET%^%^ORANGE%^The massive door shuts heavily as the chains release the strain.");
	set_lock_description("gate","lock","This is a huge bar across the giant
door.");
    set_door_description("gate","These are two huge solid wooden doors that
come together in the middle. They are bound together with giant dwarven
forged iron bands.");
    lock_difficulty("gate",-2000,"lock");
}
