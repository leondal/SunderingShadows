// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("torturechamber");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("desert");

    set_short("a %^RESET%^%^CYAN%^immense%^BOLD%^%^BLACK%^ cavern");

    set_long("%^RESET%^%^MAGENTA%^Screams%^BOLD%^%^BLACK%^ from the sh%^CYAN%^a%^BLACK%^dow meets you as you enter this d%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^rk room. A huge %^RED%^firepit%^BLACK%^ is set in the cen"
	"ter of the room and a %^YELLOW%^roaring %^RED%^fire%^BLACK%^ casts the rooms in fl%^WHITE%^i%^BLACK%^cker%^WHITE%^i%^BLACK%^ng sh%^CYAN%^a%^BLACK%^dows. Large %^RED%^cages%^BLACK%^ with humans and elv"
	"es and dwarves line the ceiling both %^RESET%^%^MAGENTA%^dead%^BOLD%^%^BLACK%^ and %^RESET%^%^CYAN%^alive%^BOLD%^%^BLACK%^. The smell of %^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^ an"
	"d %^GREEN%^decay%^BLACK%^ and %^RESET%^%^RED%^burned %^WHITE%^fl%^RED%^esh%^BOLD%^%^BLACK%^ is prominent in here and %^RESET%^%^MAGENTA%^screams%^BOLD%^%^BLACK%^ of p%^RED%^a%^BLACK%^in is %^CYAN%^tra"
	"nsfixed%^BLACK%^ in time. %^RED%^Tortural %^RESET%^%^ORANGE%^instruments%^BOLD%^%^BLACK%^ of every type is in here. A %^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^dy%^BOLD%^%^BLACK%^ ir%^RESET%^%^MAGENTA"
	"%^o%^BOLD%^%^BLACK%^nma%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^den sits in a corner and a drow is fixed in r%^RESET%^%^MAGENTA%^i%^BOLD%^%^BLACK%^gor m%^GREEN%^o%^BLACK%^rtis, while a %^RESET%^%^CYAN%^r"
	"ack%^BOLD%^%^BLACK%^ stand near the %^RED%^firepit%^BLACK%^ and a dwarf have been stretched to his limit and his %^WHITE%^bones%^BLACK%^ are clearly out of place, and %^RED%^bl%^RESET%^%^RED%^oo%^BOLD"
	"%^%^RED%^d%^BOLD%^%^BLACK%^ runs from several wounds on his body. Chains hangs from the ceiling and several shapes hangs motionlessly from the %^RESET%^%^WHITE%^shackles%^BOLD%^%^BLACK%^, with %^RED%^"
	"bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d%^BLACK%^ running from wounds around their wrists. The room is searing hot and the floor is slick with %^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^ "
	"and gore. Baskets stands around the firepit with entrails and organs, that glisters %^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^ red in the flickering light."
	);

    set_smell("default","
%^BOLD%^%^RED%^burning flesh and sulfur");
    set_listen("default","you hear the sounds of screaming and cackling off in the distance");


    set_exits(([ 
		"south" : "/d/av_rooms/asmodeus/Devilhall",
		"east" : "/d/av_rooms/asmodeus/lastroom",
	]));

}