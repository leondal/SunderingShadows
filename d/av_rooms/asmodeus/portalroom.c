// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("portalroom");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("desert");

    set_short("%^CYAN%^portal room%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^You have entered the %^CYAN%^portal%^BOLD%^%^BLACK%^ room. A gigantic %^BOLD%^%^WHITE%^w%^BLACK%^h%^RESET%^%^WHITE%^i%^BOLD%^%^CYAN%^r%^BLACK%^l%^WHITE%^i%^CYAN%^n%^BLACK%^g %^BOLD%^%"
	"^BLACK%^p%^CYAN%^o%^RESET%^%^WHITE%^o%^BOLD%^%^WHITE%^l%^BLACK%^ of %^CYAN%^e%^BOLD%^%^BLACK%^n%^CYAN%^e%^BOLD%^%^BLACK%^r%^CYAN%^g%^BOLD%^%^BLACK%^y is set into a big frame to hold the %^CYAN%^portal"
	"%^BOLD%^%^BLACK%^. The %^CYAN%^portal%^BOLD%^%^BLACK%^ stands ona raised %^RESET%^%^MAGENTA%^dais%^BOLD%^%^BLACK%^ in the middle of the room, and the %^RESET%^%^MAGENTA%^dais%^BOLD%^%^BLACK%^ itself i"
	"s made of thousand of %^RESET%^%^WHITE%^skulls%^BOLD%^%^BLACK%^. %^RESET%^%^WHITE%^Skulls%^BOLD%^%^BLACK%^ from every race and beast. A wide %^RESET%^%^CYAN%^staircase%^BOLD%^%^BLACK%^ goes from the t"
	"he %^CYAN%^portal%^BOLD%^%^BLACK%^ and ends into a paved %^MAGENTA%^road%^BOLD%^%^BLACK%^, made by more %^RESET%^%^WHITE%^skulls%^BOLD%^%^BLACK%^. On both sides of the road, %^YELLOW%^torches%^BOLD%^%"
	"^BLACK%^ held by %^RESET%^%^WHITE%^skeletal%^BOLD%^%^BLACK%^ arms light the area and cast the room in a %^GREEN%^e%^BLACK%^i%^MAGENTA%^r%^GREEN%^i%^BLACK%^e light. Two large %^RED%^p%^RESET%^%^RED%^oo"
	"%^BOLD%^%^RED%^ls%^BOLD%^%^BLACK%^ of %^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^d%^BOLD%^%^BLACK%^ fills the cavern on each side of the road and %^RESET%^%^CYAN%^mutters%^BOLD%^%^BLACK%^ and %^RESET%^"
	"%^MAGENTA%^words%^BOLD%^%^BLACK%^ is constantly %^RESET%^%^WHITE%^whispered %^BOLD%^%^BLACK%^from the d%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^rkness. You can see sh%^WHITE%^a%^BOLD%^%^BLACK%^pes in the d"
	"%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^rkness, f%^CYAN%^o%^BOLD%^%^BLACK%^rms not entirely %^WHITE%^real%^BOLD%^%^BLACK%^, nor anything you can say what is. The large paved road runs for a %^CYAN%^mile%^"
	"BOLD%^%^BLACK%^ or more before it widens into a large hall"
	);

    set_smell("default","
%^BOLD%^%^RED%^burning flesh and sulfur");
    set_listen("default","you hear the sounds of screaming and cackling off in the distance");


    set_exits(([ 
		"north" : "/d/av_rooms/asmodeus/Devilhall",
	]));

}