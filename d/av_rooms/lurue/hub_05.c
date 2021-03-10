// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("hub_05");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^CYAN%^Lurue's Cloudy Skies%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This hall leads away from one of the many passages and down along a tapestry lined corridor.  Each tapestry is life like and filled with detail so clear that it seems you might be abl"
	"e to step through them and stand upon the part of the world they display. Above each tapestry, the bronze figure of a %^WHITE%^fl%^CYAN%^u%^WHITE%^ffy white cl%^CYAN%^o%^WHITE%^ud %^BLACK%^lurks.%^RES"
	"ET%^"
	);

    set_smell("default","
The air is faintly tinged with a hint of moss and earth.");
    set_listen("default","The room is silent except for the quiet ticking of your heartbeat.");


    set_exits(([ 
		"attaya" : "/d/av_rooms/lurue/attaya_03",
		"south" : "/d/av_rooms/lurue/hub_01",
		"rhall" : "/d/dagger/tonovi/temp/lurueroom1",
		"schooner" : "/d/av_rooms/lurue/schooner_m4",
		"klauth" : "/d/av_rooms/lurue/klauth_p1",
		"rtriangle" : "/d/dagger/tonovi/temp/upper1",
		"parmt" : "/d/av_rooms/lurue/parmt_r1",
		"ringroom" : "/d/avatars/nienne/party/home",
		"rpath" : "/d/underdark/upper/tonovitunnel/newtunnel1",
		"uzodo" : "/d/av_rooms/lurue/uzodo_d1",
		"masq" : "/d/av_rooms/lurue/masq_t1",
		"shore" : "/d/av_rooms/lurue/shore1",
		"seawreck" : "/d/av_rooms/lurue/seawreck_s1",
		"gencell" : "/d/av_rooms/lurue/cell_hall",
	]));

}