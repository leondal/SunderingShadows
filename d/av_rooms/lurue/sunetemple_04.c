// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sunetemple_04");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("garden");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Shade Garden%^RESET%^");

    set_long("%^RESET%^%^GREEN%^Dominating this part of the temple garden is a mature %^ORANGE%^fig tree%^GREEN%^, ripe with blossoms and succulent, honey-sweet %^MAGENTA%^fruit%^GREEN%^.  The thick canopy of the l"
	"arge frond like %^BOLD%^leaves %^RESET%^%^GREEN%^casts a cooling %^CYAN%^shadow %^GREEN%^on the thick exposed %^ORANGE%^roots%^GREEN%^.  Between the niches formed by the tree's roots grow, soft, spong"
	"y nests of %^BOLD%^pale green moss %^RESET%^%^GREEN%^that look inviting for resting upon.  Outside of the tree's shadow, tiny wide-petal primrose grows, scattered upon the extending lawn.  Their delic"
	"ate %^BOLD%^%^MAGENTA%^pink %^RESET%^%^GREEN%^and %^BOLD%^%^WHITE%^white%^RESET%^%^GREEN%^ petal faces turned upward to catch the light through the many limbed branches above. Surrounding the garden i"
	"s a palisade created of statuesque columns and %^BOLD%^%^WHITE%^white marble %^RESET%^%^GREEN%^walls broken only by the billowing waves of an occasional silk curtain.  A sloping %^BOLD%^%^WHITE%^white"
	" gravel %^RESET%^%^GREEN%^walkway curves away from one of these billowing decorations, making its way down to join the wide gravel path that travels around the central %^BOLD%^%^BLUE%^pool%^RESET%^%^G"
	"REEN%^.  The quartz within the marble like granite stones catching and reflecting the light like a million tiny %^YELLOW%^suns%^RESET%^%^GREEN%^.%^RESET%^"
	);

    set_smell("default","
The delicate scent of primrose caresses your senses");
    set_listen("default","Calls from fire doves echo to you from the branches above.");


    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/sunetemple_01",
		"north" : "/d/av_rooms/lurue/sunetemple_10",
		"southwest" : "/d/av_rooms/lurue/sunetemple_03",
	]));

}