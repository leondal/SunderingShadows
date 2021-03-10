// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("carn_wrath");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("village");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLACK%^A %^RESET%^%^RED%^B%^BOLD%^lo%^RESET%^%^RED%^od %^BOLD%^S%^RESET%^%^RED%^p%^BOLD%^att%^RESET%^%^RED%^er%^BOLD%^ed %^BLACK%^A%^WHITE%^r%^BLACK%^ena%^RESET%^");

    set_long("%^RESET%^%^RED%^This mighty tent soars above a mighty %^BOLD%^%^CYAN%^s%^WHITE%^t%^CYAN%^eel %^BLACK%^c%^WHITE%^a%^BLACK%^ge%^RESET%^%^RED%^ on a platform, surrounded by giant %^ORANGE%^wooden bleache"
	"rs%^RED%^. A thousand spectators or more could fit on the bleachers, and two smaller tents have been set up on either side of the cage. %^BOLD%^Blood%^RESET%^%^RED%^ spatters the floor of the platform"
	". It is clear that this is a mighty %^BOLD%^%^BLACK%^G%^WHITE%^l%^BLACK%^ad%^RED%^i%^BLACK%^at%^CYAN%^o%^BLACK%^r A%^WHITE%^r%^BLACK%^ena%^RESET%^%^RED%^, where the crowded masses witness the spectacl"
	"e of %^BOLD%^%^BLUE%^m%^RESET%^%^BLUE%^o%^BOLD%^rt%^RESET%^%^BLUE%^a%^BOLD%^l %^RESET%^%^RED%^combat. An enormous %^CYAN%^m%^WHITE%^i%^CYAN%^rror%^RED%^ has been hoisted high above the cage to allow t"
	"he spectators to observe every blow in spectacular detail.%^RESET%^"
	);

    set_smell("default","
You smell the sweat of spectators and the blood of contestants.");
    set_listen("default","You hear the raucous crowd screaming for blood!");

    
set_items(([ 
	"cage" : "It is an enormous steel cage on a platform. The only exit from that cage is death or victory.",
	"bleachers" : "The bleachers are very sturdy and can bear the weight of a thousand or more spectators.",
	"arena" : "This is a very impressive arena, with magical lighting, an enormous tent, bleachers, and a cage match!",
	"mirror" : "The mirror must be hugely expensive to have been made as it looks to weigh about a ton and must be at least two firbolgs long!",
	]));

    set_exits(([ 
		"cage" : "/d/av_rooms/myrkul/carn_wrath_cage",
		"east" : "/d/av_rooms/myrkul/carn_main_w",
	]));

    set_door("cage door","/d/av_rooms/myrkul/carn_wrath_cage","cage","cage key","lock");
    add_lock("cage door","cage key","lock","A heavy steel lock.");
    set_locked("cage door",0,"lock");
    set_string("cage door","knock","pounds on the");
    set_string("cage door","open","The cage door squeals open.");
    set_string("cage door","close","The cage door squeals closed.");
    set_door_description("cage door","The cage door is a massive structure large enough to accomodate a giant and made of massive bars of steel.");
}

void reset() {
  ::reset();
  if(!present("fine mirror")) new("/d/magic/obj/mirror")->move(TO);
}
