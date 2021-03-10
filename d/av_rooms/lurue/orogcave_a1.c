// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("orogcave_a1");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("slick floor");
    set_climate("mountain");

    set_short("%^RESET%^%^BLUE%^a %^BOLD%^%^BLACK%^gr%^BLUE%^a%^BLACK%^n%^RESET%^i%^BOLD%^%^BLACK%^te%^RESET%^%^BLUE%^ cave%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^Wooden dummies are neatly organized in several rows here.  Their forms built with wide chests and exceptional height.  Draped over these forms are suits of %^RESET%^polished armor%^BO"
	"LD%^%^BLACK%^, designed by the Orog metalsmiths for the army.  Headless, these forms have large holes drilled into their cores, into which many have swords or other similar weapons driven.  Temporary "
	"sheaths for the weapons that accompany the suits of armor.   On the top portion of the walls, large shields have been hung, while below, neatly stacked in precise order, are %^RESET%^billets of metal "
	"%^BOLD%^%^BLACK%^waiting for the forge.%^RESET%^"
	);

    set_smell("default","
The deep scent of earth, metal and bodies permeates the air.");
    set_listen("default","The sounds of Orog can be heard echoing through the halls.");


    set_exits(([ 
		"east" : "/d/av_rooms/lurue/orogcave_a2",
	]));

}