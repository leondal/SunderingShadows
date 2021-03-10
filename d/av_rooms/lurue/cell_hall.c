// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("cell_hall");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("A barren stone hallway");

    set_long("%^RESET%^%^CYAN%^This stone hallway offers little in the way of comfort.  The walls are made from thick %^RESET%^slabs of stone%^CYAN%^ that bounce every sound made back at you, cutting you off from t"
	"he rest of the world.  The floor is likewise made of stone as is the ceiling.  A small %^BOLD%^window %^RESET%^%^CYAN%^can be seen in the roof, heavy metal bars form a grid across it preventing anythi"
	"ng smaller then a bug from coming through.  Looking up through the grid you realize you must be underground for all you can see is sky high above.  A similar network of %^RED%^iron bars%^CYAN%^ forms "
	"the door to a jail cell in the east wall.  Other then this, there are the stairs that lead up and out, and a %^BLACK%^%^BOLD%^steel door %^RESET%^%^CYAN%^to the south. %^RESET%^"
	);

    set_smell("default","Something clean and fresh attempts to disguise the smell of suffering humanity.");
    set_listen("default","The sounds of a city outside reach your ears and remind you how far from freedom you really are.");


    set_exits(([ 
		"stairs" : "/d/av_rooms/lurue/cell_exit",
		"south" : "/d/av_rooms/lurue/cell_discuss",
		"east" : "/d/av_rooms/lurue/cell_cell",
	]));

    set_door("steel door","/d/av_rooms/lurue/cell_discuss","south","jail key","steel lock");
    add_lock("steel door","jail key","steel lock","This lock is small and complex, you're sure you need a key for it.");
    set_locked("steel door",1,"steel lock");
    lock_difficulty("steel door",-70,"steel lock");
    set_open("steel door",0);
    set_string("steel door","knock","knocks on the");
    set_string("steel door","open","The door clangs against the wall as it is opened.");
    set_string("steel door","close","The door clangs shut.");
    set_door_description("steel door","This door is made from two solid sheets of steel.  A small glass window allows one to see into the next room.");
    set_door("iron door","/d/av_rooms/lurue/cell_cell","east","jail key","cell lock");
    add_lock("iron door","jail key","cell lock","This lock is large and complex, requiring a key or a very clever locksmith to get through.");
    set_locked("iron door",1,"cell lock");
    lock_difficulty("iron door",-90,"cell lock");
    set_open("iron door",0);
    set_string("iron door","knock","rattles the bars on the ");
    set_string("iron door","open","The bars rattle as the door is swung open.");
    set_string("iron door","close","The bars rattle as the door is swung closed.");
    set_door_description("iron door","A frame of thick iron slabs provide holes into which the iron bars are fitted.  The bars make a mesh pattern that allows you to see through them into the next room.");
}