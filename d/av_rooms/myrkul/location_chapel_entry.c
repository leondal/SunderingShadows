// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("location_chapel_entry");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^Chapel Entry%^RESET%^");

    set_long("%^RESET%^%^CYAN%^The entry to the chapel is a short room where the %^BOLD%^%^BLACK%^vicar%^RESET%^%^CYAN%^ traditionally greets his parishioners. Oddly, the front doors of this chapel opens into the g"
	"raveyard itself. The room has a high-arched ceiling and marble floors. An inner set of doors once kept the cold out of the rest of the building, but they have since been removed. All that remains are "
	"iron hinges. %^YELLOW%^Light%^RESET%^%^CYAN%^ flows in from stained-glass windows. The remains of a cork announcement board lies in ruins.%^RESET%^"
	);

    set_smell("default","
%^RESET%^The scent of fetid %^RED%^death%^RESET%^ wafts in from the outside. Or inside?%^RESET%^");
    set_listen("default","%^RESET%^Distant clanking of metal and the heavy tread of many feet reaches your ears.%^RESET%^");

    
set_items(([ 
	({ "glass", "window", "stained glass", "stained glass window" }) : "%^BOLD%^%^BLACK%^A skeletal figure holding a scythe stands in the graveyard. The image looks %^MAGENTA%^eery%^BLACK%^ in the light.%^RESET%^",
	"floor" : "The floor is made of solid marble and looks entirely seemless.",
	"ceiling" : "The ceiling soars above you in a high-arch. The entire chapel is made of marble.",
	"walls" : "The sturdy walls are marble and reveal nothing but timeless age.",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/myrkul/boneyard_east_chapel",
		"north" : "/d/av_rooms/myrkul/location_chapel_coat",
		"east" : "/d/av_rooms/myrkul/location_chapel_back",
	]));

    set_door("chapel doors","/d/av_rooms/myrkul/boneyard_east_chapel","west","skeleton key","large iron lock");
    add_lock("chapel doors","skeleton key","large iron lock","The door looks to be large so that a mischevious child could unlock it.");
    set_locked("chapel doors",0,"large iron lock");
    set_open("chapel doors",0);
    set_string("chapel doors","knock","pounds on the");
    set_string("chapel doors","open","The door opens with a groan");
    set_string("chapel doors","close","The door shuts with a shudder.");
    set_door_description("chapel doors","The chapel doors are made of iron-bound oak. ");
}