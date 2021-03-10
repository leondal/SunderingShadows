// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("carn_bigtop");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("village");
    set_travel("foot path");
    set_climate("temperate");

    set_short("%^YELLOW%^B%^RED%^i%^BLUE%^g%^WHITE%^ T%^CYAN%^o%^GREEN%^p%^MAGENTA%^ T%^BLACK%^e%^RED%^n%^YELLOW%^t%^RESET%^");

    set_long("%^YELLOW%^This is it! The %^WHITE%^largest%^YELLOW%^ most fabulous %^CYAN%^circus%^YELLOW%^ tent on the continent! %^RESET%^%^ORANGE%^Enormous wooden bleachers%^YELLOW%^ are capable of seating thousan"
	"ds. Great %^WHITE%^lights%^YELLOW%^ shine down on the center %^RED%^ring%^YELLOW%^ where the %^BLUE%^R%^BLACK%^i%^RED%^n%^WHITE%^g%^CYAN%^M%^WHITE%^a%^CYAN%^ster%^YELLOW%^ will work his magic. A short"
	" wall separates the main ring from the seating. %^BLACK%^Trapeze apparatus%^YELLOW%^ have been set up from tall poles, and empty cages for %^GREEN%^wild beasts%^YELLOW%^ can be seen in the corners. Fo"
	"r now the tent is empty as the major events will be shown at the end of the carnival.%^RESET%^"
	);

    set_smell("default","
It smells of sweat and alcohol from the crowd.");
    set_listen("default","You hear the roar of the crowds!");


    set_exits(([ 
		"out" : "/d/av_rooms/myrkul/carn_main",
	]));

}