// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("test_1");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("arctic");

    set_short("%^BOLD%^%^WHITE%^A stone chamber%^RESET%^ ");

    set_long("%^RESET%^This chamber is made from carved stones that have been carefully fit together. Some form of %^BOLD%^%^BLACK%^pale gray mixture %^RESET%^has been applied between the stones in order to keep th"
	"em together. The floor is similarly made, though the ceiling appears to be constructed out of %^ORANGE%^wood %^RESET%^and %^YELLOW%^thatch.%^RESET%^ "
	);

    set_smell("default","
The air is stuffy and closed.");
    set_listen("default","The beating of your heart pounds in your ears. ");

    set_search("walls","%^BOLD%^%^WHITE%^You look the walls over and see that someone has carved their initials here. They must have been trapped here too.%^RESET%^ ");
    
set_items(([ 
	({ "chair", "chairs" }) : "What are you looking at? There are no chairs in this room. It's empty, didn't you read the description? ",
	]));

    set_exits(([ 
		"north" : "/d/dagger/avalounge",
	]));

}