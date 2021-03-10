// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("Throne_of_Blood2");
    set_property("indoors",0);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("barren");
    set_travel("foot path");
    set_climate("desert");

    set_short("%^BOLD%^%^WHITE%^B%^RESET%^r%^BOLD%^%^BLACK%^i%^WHITE%^d%^RESET%^g%^BOLD%^%^BLACK%^e %^WHITE%^O%^RESET%^f %^BOLD%^%^BLACK%^B%^WHITE%^o%^RESET%^n%^BOLD%^%^BLACK%^e%^WHITE%^s%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^You stand on a bridge made from countless %^WHITE%^b%^RESET%^o%^BOLD%^n%^RESET%^e%^BOLD%^s %^BLACK%^of an u%^MAGENTA%^n%^BLACK%^kn%^MAGENTA%^o%^BLACK%^wn origin. Below you is a moat c"
	"ontaining a thick and dark %^RESET%^%^RED%^red %^BOLD%^%^BLACK%^substance. Across the bridge you can see seamless obs%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^d%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^an wal"
	"ls towering over one-hundred stories into the sky above you. Carved into these walls are numerous grotesque and devilish faces. Each face has a seemingly infinite amount of the dark red liquid pouring"
	" from it's mouth, Endlessly filling the moat below you. Across the bridge you can see a set of doors made from the same obsidian as the walls themselves. %^RED%^Red%^BLACK%^, %^ORANGE%^glowing %^BLACK"
	"%^runes have been carved into these doors and put off an eerie light.%^RESET%^"
	);

    set_smell("default","
%^BOLD%^%^BLACK%^You smell the sharply metallic scent of %^RED%^blood%^RESET%^");
    set_listen("default","%^BOLD%^%^BLACK%^The tortured screams of countless %^WHITE%^souls%^BLACK%^ can be heard%^RESET%^");


    set_exits(([ 
		"south" : "/d/av_rooms/bhaal/Throne_of_Blood",
	]));

}