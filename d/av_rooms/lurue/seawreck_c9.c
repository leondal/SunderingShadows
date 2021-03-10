// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit WATER;

void create()
{
    ::create();
    set_name("seawreck_c9");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLUE%^Entrance to a sunken structure%^RESET%^");

    set_long("%^CYAN%^Entry to the tower and way to reach the garden.  If you're here, you shouldn't be.  This part hasn't been fully developed yet.%^RESET%^");

    set_smell("default","
There is nothing to smell here.");
    set_listen("default","The bubbles escape from your lip and nose making a constant buzz against your ear.");


    set_exits(([ 
		"east" : "/d/av_rooms/lurue/seawreck_c7",
		"northwest" : "/d/av_rooms/lurue/seawreck_g1",
	]));

    set_door("main entrance","/d/av_rooms/lurue/seawreck_c7","east","void key","entry lock");
    add_lock("main entrance","void key","entry lock","Although covered in brass, the lock itself appears to be made of something else.  A dark swirling energy looks to be contained between the lock's face plates, making you wonder just what would be needed to unlock such a door.");
    set_locked("main entrance",1,"entry lock");
    lock_difficulty("main entrance",-1000,"entry lock");
    set_open("main entrance",0);
    set_string("main entrance","knock","pounds on the sodden wood of the ");
    set_string("main entrance","open","With a heave you pull the doors open, cracking the door frame and sending a thick cloud of dust and grime into the water.");
    set_string("main entrance","close","With all your effort, you push the door into its swollen frame.");
    set_door_description("main entrance","This heavy wooden door once made a grand entry.  Crafted from beautifully carved ironwood and set with ornate brass fixtures, the double doors are now thick and swollen by the water and wedged tightly into the door frame.  You're not sure you could ever pull them open, even if you could find a way to unlock them.");
}