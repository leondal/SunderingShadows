// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("carn_wrath_cage");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("village");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^BOLD%^%^CYAN%^I%^WHITE%^n%^CYAN%^side the %^WHITE%^C%^CYAN%^age!!%^RESET%^");

    set_long("%^RESET%^%^CYAN%^You stand in an %^RED%^octagon%^CYAN%^ surrounded by a mighty %^WHITE%^steel%^CYAN%^ cage. There is no %^BOLD%^%^BLACK%^escape%^RESET%^%^CYAN%^ except by way of %^BOLD%^%^BLACK%^death"
	"%^RESET%^%^CYAN%^ or%^YELLOW%^ victory%^RESET%^%^CYAN%^. The floor itself is metal and is coated with %^BOLD%^%^RED%^blood.%^RESET%^"
	);

    set_smell("default","
You smell the sweat of spectators and the blood of contestants.");
    set_listen("default","You hear the raucous crowd screaming for blood!");

    
set_items(([ 
	"cage" : "Yep no escape through that.",
	"floor" : "Yep no escape through that.",
	"blood" : "Oh that is looking sticky and nasty.",
	]));

    set_exits(([ 
		"out" : "/d/av_rooms/myrkul/carn_wrath",
	]));

    set_door("cage door","/d/av_rooms/myrkul/carn_wrath","out","cage key","lock");
    add_lock("cage door","cage key","lock","lock");
    set_locked("cage door",1,"lock");
    set_open("cage door",0);
    set_string("cage door","knock","pounds on the");
    set_string("cage door","open","The cage door squeals open.");
    set_string("cage door","close","The cage door squeals closed.");
    set_door_description("cage door","The cage door is a massive structure large enough to accomodate a giant and made of massive bars of steel.");
}