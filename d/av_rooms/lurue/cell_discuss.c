// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("cell_discuss");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("A holding room");

    set_long("%^CYAN%^This large square room is void of any decoration or interest except for the %^RED%^iron door %^CYAN%^leading out and the %^ORANGE%^table %^CYAN%^and %^ORANGE%^chairs %^CYAN%^in the middle of t"
	"he room.  Otherwise the entire stone chamber is bare and uninteresting.  The use of this room is clear though, an interrogation room where prisoners can be questioned.  A set of %^BOLD%^%^BLACK%^shack"
	"les %^RESET%^%^CYAN%^on the southern wall provide a way to secure particularly cumbersome prisoners, although there are chairs arranged all around the table, suggesting these are rarely used.%^RESET%^"
	);

    set_smell("default","The room smells of something clean and bitter.");
    set_listen("default","Just your breathing echoes back to you in this chamber.");

    
set_items(([ 
	({ "table", "table and chair", "table and chairs", "chairs", "chair" }) : "The table is made of thick planks of wood that have been smoothed and polished.  Likewise the four chairs around it are simple and undecorated.  A fifth chair is across the room facing the door out, as though someone might be stationed there to keep watch on the door.",
	"shackles" : "The shackles are in very good repair and you're certain you wouldn't want to be secured by them.  They must be there for the very troublesome prisoners.  Surely you're not one of those!",
	]));

    set_exits(([ 
		"north" : "/d/av_rooms/lurue/cell_hall",
	]));

    set_door("steel door","/d/av_rooms/lurue/cell_hall.c","north","jail key","steel lock");
    add_lock("steel door","jail key","steel lock","This lock is small and complex, you're sure you need a key for it.");
    set_locked("steel door",1,"steel lock");
    lock_difficulty("steel door",-70,"steel lock");
    set_open("steel door",0);
    set_string("steel door","knock","knocks on the ");
    set_string("steel door","open","The door clangs against the wall as it is opened.");
    set_string("steel door","close","The door clangs shut.");
    set_door_description("steel door","This door is made from two solid sheets of steel.  A small glass window allows one to see into the next room.");
}