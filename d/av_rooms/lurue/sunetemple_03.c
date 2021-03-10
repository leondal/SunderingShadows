// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sunetemple_03");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("garden");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Rose Garden%^RESET%^");

    set_long("%^RESET%^%^GREEN%^A %^BOLD%^%^WHITE%^white marble %^RESET%^%^GREEN%^palisade encircles the temple garden.  Billowing silk drapes of %^RED%^crimson%^GREEN%^, %^YELLOW%^gold %^RESET%^%^GREEN%^and %^BOLD"
	"%^%^WHITE%^ivory %^RESET%^%^GREEN%^hang between eloquently carved, statuesque columns, breaking up the marble's sheerness with their opaque diaphanous weave.  Situated between the palisade and the mar"
	"ble %^BOLD%^%^BLUE%^pool %^RESET%^%^GREEN%^at the center of the garden is a lush, %^BOLD%^deep green %^RESET%^%^GREEN%^lawn that slopes delicately downward along a meandering %^BOLD%^%^WHITE%^white gr"
	"avel %^RESET%^%^GREEN%^path.  The quartz within the marble like granite stones catching and reflecting the light like a million tiny %^YELLOW%^suns%^RESET%^%^GREEN%^. %^BOLD%^%^RED%^Rose bushes%^RESET"
	"%^%^GREEN%^ of every color flourish here, but none so well as the %^RED%^deep crimson %^RESET%^%^GREEN%^blooms favored by the Goddess herself.  From the most delicate of new %^MAGENTA%^buds %^RESET%^%"
	"^GREEN%^to the full flung glory of the %^BOLD%^%^RED%^open bloom%^RESET%^%^GREEN%^, they lift their faces upward awaiting admiration of their delicate perfection.%^RESET%^"
	);

    set_smell("default","
The heavy scent of the rose garden adorns the air with a riot of wondrous perfume.");
    set_listen("default","A light breeze carries the sound of murmuring voices from nearby.");


    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/sunetemple_04",
		"southeast" : "/d/av_rooms/lurue/sunetemple_02",
		"west" : "/d/av_rooms/lurue/sunetemple_08",
		"east" : "/d/av_rooms/lurue/sunetemple_05",
	]));

}