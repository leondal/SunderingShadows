// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("a_tomb4");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^A %^BLUE%^c%^RESET%^%^CYAN%^o%^BOLD%^%^BLUE%^ld, %^RESET%^%^MAGENTA%^d%^CYAN%^a%^MAGENTA%^rk%^BOLD%^%^BLACK%^ t%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^mb%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This is a steeply sloped %^BLUE%^s%^GREEN%^h%^BLUE%^a%^GREEN%^f%^BLUE%^t%^BOLD%^%^BLACK%^ that leads further into the %^BLUE%^d%^GREEN%^e%^BLUE%^pths%^BLACK%^ of the tomb. It is not v"
	"ery big and the %^BLUE%^c%^RESET%^%^CYAN%^o%^BOLD%^%^BLUE%^ld%^RESET%^%^ORANGE%^ g%^CYAN%^r%^ORANGE%^ani%^CYAN%^t%^ORANGE%^e%^BOLD%^%^BLACK%^ of the walls seem to close in around you, almost as if it "
	"were a living being trying to %^YELLOW%^strangle%^BLACK%^ the last bits of %^WHITE%^life%^BLACK%^ from your body. The %^RESET%^%^MAGENTA%^g%^CYAN%^l%^MAGENTA%^oom%^BOLD%^%^BLACK%^ closes around you an"
	"d the air here seems tight.%^RESET%^"
	);

    set_smell("default","
The faint aroma of mold and decay permeates the ruins.");
    set_listen("default","%^YELLOW%^A%^WHITE%^n%^YELLOW%^gel%^WHITE%^i%^YELLOW%^c %^RESET%^%^CYAN%^hymns voiced in a %^GREEN%^forgotten language%^CYAN%^ reverberate from the walls, without %^WHITE%^source%^CYAN%^ and without %^BOLD%^%^BLACK%^end.%^RESET%^");

    
set_items(([ 
	"floor" : "%^RESET%^%^CYAN%^The floor is chipped and warn from many footsteps, age, and water. It has not seen use in many years, and regular repair in much longer.%^RESET%^",
	"darkness" : "%^RESET%^%^CYAN%^The darkness here is more than just absence of light -- some %^YELLOW%^presence%^RESET%^%^CYAN%^ is here, you can feel it in your bones.%^RESET%^",
	"ceiling" : "%^RESET%^%^CYAN%^The ceiling is a patchwork of cracks, and water drips down in places. Perhaps this is not the safest of places, yet the tomb has withstood the test of time nonetheless.%^RESET%^",
	"walls" : "%^RESET%^%^CYAN%^The walls are old, very old and cut roughly out of %^ORANGE%^granite%^CYAN%^. Rivulets of condensed water drip down the sides and %^GREEN%^mold%^CYAN%^ can be seen in many places.%^RESET%^",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/asmodeus/a_tomb5",
		"west" : "/d/av_rooms/asmodeus/a_tomb3",
	]));

}