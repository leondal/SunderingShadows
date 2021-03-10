// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("dekumage_u1");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("decayed floor");
    set_climate("tropical");

    set_short("%^BOLD%^%^WHITE%^An old manor house%^RESET%^");

    set_long("%^RESET%^Much like the downstairs, this hallway has seen better days.  The threadbare %^RED%^carpet %^RESET%^continues on down the hallway to a set of wide %^YELLOW%^double doors%^RESET%^.  Though the"
	" walls are unadorned, there is a sense of style and agelessness in the architecture that was missing from the lower floors.%^RESET%^"
	);

    set_smell("default","
The scent of mold and ruin isn't as strong up here.");
    set_listen("default","Its quiet here except for the occasional groan of the floorboards. ");


    set_exits(([ 
		"stairs" : "/d/av_rooms/lurue/dekumage_m3",
		"north" : "/d/av_rooms/lurue/dekumage_u2",
	]));

    set_door("double doors","/d/av_rooms/lurue/dekumage_u2","north","manor key","metal lock");
    add_lock("double doors","manor key","metal lock","This lock looks reasonably simple as though it was meant simply to keep people from bothering the occupant rather then preventing thieves. ");
    set_locked("double doors",1,"metal lock");
    lock_difficulty("double doors",-20,"metal lock");
    set_open("double doors",0);
    set_string("double doors","knock","knock on the ");
    set_string("double doors","open","The double doors swing open silently.");
    set_string("double doors","close","The double doors swing closed silently.");
    set_door_description("double doors","These double doors are made from thick beams of oak and are held together with simple metal facets that give them a stately appearance despite their simplicity.");
}