// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("uzodo_h1");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("hut");
    set_travel("dirt road");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^A dark hut%^RESET%^");

    set_long("%^RESET%^This dark hut is made from %^BOLD%^%^BLACK%^mud%^RESET%^ that has been layered over the walls to create thick, insolated walls.  The roof is created out of multiple layers of %^GREEN%^pine br"
	"anches %^RESET%^that keep all but the heaviest of %^BLUE%^rains%^RESET%^ out.  Sectioned into a few rooms, the hut is little more then %^ORANGE%^dirt floors %^RESET%^with a few basic pieces of furnitu"
	"re set about.  Pallets of %^GREEN%^fern %^RESET%^make beds in the back rooms and the main room has a dug out %^RED%^fire pit %^RESET%^for cooking and heating.%^RESET%^"
	);

    set_smell("default","
The heavy smell of humanity and poor living conditions lingers here.");
    set_listen("default","It is fairly quiet inside the hut.");

    
set_items(([ 
	({ "pit", "fire pit", "firepit" }) : "%^RED%^The fire pit is empty at the moment and cold.  Likely its used for cooking and for heating the house.  Located in a small alcove in the wall that has a high window, you imagine that it is a primitive form of a fireplace.%^RESET%^",
	({ "roof", "branches" }) : "%^GREEN%^The roof is constructed out of tightly woven pine branches that crisscross over one another to form a thick thatching to keep the rain out.%^RESET%^",
	({ "furniture", "mats", "furns", "pallets" }) : "%^GREEN%^There isn't much in the way of furniture.  It appears the people that live here use pine and fur branches for the majority of their needs, along with pelts of the creatures they kill to make most of their clothing and bedding needs.%^RESET%^",
	({ "walls", "mud", "building" }) : "%^BOLD%^%^BLACK%^The walls are made of muddle and daub construction and provide a thick insulation against the weather.  The walls are darkened by time and smoke, and appear to have been repaired several times.%^RESET%^",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/lurue/uzodo_v1",
	]));

    set_door("hut door","/d/av_rooms/lurue/uzodo_v1","north");
    set_open("hut door",0);
    set_string("hut door","knock","knock on the");
    set_string("hut door","open","You lift the fur pelt that covers the doorway and peer out from the gloom of the hut.");
    set_string("hut door","close","You drop the fur covered pelt back into place across the doorway.");
    set_door_description("hut door","The doorway is covered with a thick pelt of shaggy fur.");
}