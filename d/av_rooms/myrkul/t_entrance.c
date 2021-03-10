// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("t_entrance");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("grasslands");
    set_travel("game track");
    set_climate("temperate");

    set_short("%^YELLOW%^Before an %^RED%^Armed Camp%^RESET%^");

    set_long("You stand before a hastily constructed pallisade. Walls made of wooden logs stand a good 8 feet tall with sharpened spikes at the top. They are bound together with thick ropes and watchtowers have bee"
	"n erected along the edges. The camp looks very temporary and doubtless it will be moved again in the future. A word dirt path leads north to a gate and south back where you came from. To the northwest"
	" and northeast are two other dirt tracks that lead around the walls to the sides. "
	);

    set_smell("default","
You can smell latrines to the northwest.");
    set_listen("default","You can here camp sounds of people laughing, cursing, and drinking to the north.");

    
set_items(([ 
	({ "path", "paths", "dirt path", "dirt tracks", "tracks" }) : "The dirt paths are exactly what they seem.",
	"gate" : "The large gate is made out of heavy wooden logs, and is doubtless a very defensible construction.",
	"camp" : "This seems like a large encampment of soldiers or, worse, bandits.",
	]));

    set_exits(([ 
		"northeast" : "/d/av_rooms/myrkul/t_spring",
		"north" : "/d/av_rooms/myrkul/t_camp",
		"northwest" : "/d/av_rooms/myrkul/t_latrine",
	]));

    set_door("Gate","/d/av_rooms/myrkul/t_camp","north");
    set_open("Gate",0);
    set_string("Gate","knock","pounds on the");
    set_string("Gate","open","The gate swings open.");
    set_string("Gate","close","The gate swings closed");
    set_door_description("Gate","This gate is very large and bound with rope. It is hastily constructed.");
}