// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_b3");
    set_property("indoors",1);
    set_property("light",-1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("tropical");

    set_short("a basement room");

    set_long("Dug into the marshland of the swamp, this stone and mortar basement is part of the foundation for the manner above.  Time has begun to wear at the stones and evidence of moisture is evident on the wal"
	"ls and the way the three doors that lead from this hall are warped and cracked.  If anything is stored down here any more, it probably isn't checked very often.  Only the eastern door seems to be in r"
	"easonable condition."
	);

    set_smell("default","
A faint scent of mold clings to the air.");
    set_listen("default","All is silent but for your footfalls.");

    
set_items(([ 
	({ "stone", "walls", "wall" }) : "The walls of stone have stood up to the slow encroach of the swamp like conditions that this foundation was built in.  You're fairly certain you'll be safe, at least for a while longer, even if the mortar is crumbling.",
	"moisture" : "The swamp has begun the slow process of reclaiming this underground basement.  In a few more decades it will likely have won and brought the manner house above down into the swampy marsh.",
	]));

    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/dekumage_b2",
		"north" : "/d/av_rooms/lurue/dekumage_b1",
		"south" : "/d/av_rooms/lurue/dekumage_b6",
		"east" : "/d/av_rooms/lurue/dekumage_b4",
	]));

    set_door("east door","/d/av_rooms/lurue/dekumage_b4","east","manor key","storage");
    add_lock("east door","manor key","storage","A new looking padlock, it appears to be well made and strong.");
    set_locked("east door",1,"storage");
    lock_difficulty("east door",-50,"storage");
    set_open("east door",0);
    set_string("east door","knock","knock on the door");
    set_string("east door","open","The door swings open on its hinges.");
    set_string("east door","close","The door swings closed on its hinges.");
    set_door_description("east door","A fairly new wooden door, it looks in good repair and appears to have a new lock.");
    set_door("south door","/d/av_rooms/lurue/dekumage_b6","south");
    set_open("south door",0);
    set_string("south door","knock","knocks on the ");
    set_string("south door","open","The door creeks open.");
    set_string("south door","close","The door creeks closed.");
    set_door_description("south door","An old wooden door warped and swollen with moisture.");
    set_door("north door","/d/av_rooms/lurue/dekumage_b1","north");
    set_open("north door",0);
    set_string("north door","knock","knocks on the ");
    set_string("north door","open","The door creeks open.");
    set_string("north door","close","The door creeks closed.");
    set_door_description("north door","An old wooden door warped and swollen with moisture.");
}