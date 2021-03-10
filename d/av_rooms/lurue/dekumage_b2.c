// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_b2");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("a basement room");

    set_long("%^RESET%^Dug into the marshland of the swamp, this stone and mortar basement is part of the foundation for the manner above.  Thick slabs of stone create a narrow hallway and small chambers ahead, pro"
	"viding for storage as well as structural soundness.  Despite the well laid stone work, time has begun to erode the mortar and evidence of moisture leakage stains the walls. A short flight of stairs le"
	"ads up to a doorway under the main stairs of the house.%^RESET%^"
	);

    set_smell("default","
A faint scent of mold clings to the air.");
    set_listen("default","All is silent but for your footfalls.");

    
set_items(([ 
	({ "walls", "moisture", "wall" }) : "It appears the moisture from the swamp has begun to leak through, rotting away the mortar that keeps the stones in place.",
	]));

    set_exits(([ 
		"closet" : "/d/av_rooms/lurue/dekumage_m3",
		"southwest" : "/d/av_rooms/lurue/dekumage_b3",
	]));

    set_door("closet door","/d/av_rooms/lurue/dekumage_m3","closet");
    set_open("closet door",0);
    set_string("closet door","knock","knock on the door");
    set_string("closet door","open","The door swings open with a soft groan of sound.");
    set_string("closet door","close","The door swings closed with a soft groan of sound.");
    set_door_description("closet door","The door is simply made from a panel of wood under the stairs.  Narrow, it offers just enough room to squeeze through with perhaps a few small bundles of items.");
}