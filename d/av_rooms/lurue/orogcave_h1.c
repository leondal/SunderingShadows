// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("orogcave_h1");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("slick floor");
    set_climate("mountain");

    set_short("%^RESET%^%^BLUE%^a %^BOLD%^%^BLACK%^gr%^BLUE%^a%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^te%^RESET%^%^BLUE%^ cave%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^An immense cavern opens here.  Naturally formed within the granite cliffs, it has been only slightly modified to serve its newest inhabitants, the Orog.  To either side of the entranc"
	"e %^RESET%^%^BLUE%^dark lanterns %^BOLD%^%^BLACK%^have been hung to blot out all light from the large opening that leads outside.  This casts the cave into perpetual darkness except for the %^RESET%^%"
	"^RED%^reddish glow %^BOLD%^%^BLACK%^that comes from the north end of this immense structure.  Wooden barriers have been set up throughout, partitioning the large cave into three distinct areas: a stor"
	"age area for the Orog's %^RESET%^%^ORANGE%^war-engines%^BOLD%^%^BLACK%^, an %^RESET%^%^RED%^armory %^BOLD%^%^BLACK%^with forge and a wide %^RESET%^staging area %^BOLD%^%^BLACK%^where you find yourself"
	" now.  A ramp leading deeper into stone of the cliff trails off to the southeast vanishing into a dark tunnel.%^RESET%^"
	);

    set_smell("default","
The deep scent of earth, metal and bodies permeates the air.");
    set_listen("default","The sounds of Orog can be heard echoing through the halls.");


    set_exits(([ 
		"west" : "/d/av_rooms/lurue/orogcave_s1",
		"north" : "/d/av_rooms/lurue/orogcave_a2",
		"east" : "/realms/lujke/tecqumin/tabaxi/rooms/orogs01",
		"southwest" : "/d/av_rooms/lurue/orogcave_h2",
	]));

}