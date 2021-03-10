// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("cell_cell");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("A secure jail cell");

    set_long("%^CYAN%^This cell is sparse and undecorated. %^RESET%^Stone walls%^CYAN%^ surround the room and a %^RESET%^stone slab%^CYAN%^ about three feet off hte floor provides a place to sit and rest.  A networ"
	"k of %^RED%^iron bars%^CYAN%^ creates a door leading out, but the pair of locks on the door keep it tightly sealed.%^RESET%^"
	);

    set_smell("default","The scent of shame and depression hang in the air here.");
    set_listen("default","You can just hear the sound of freedom coming from the hall beyond.");

    
set_items(([ 
	"slab" : "The slab is about three feet off the ground and is made of stone.  Featureless, there is nothing there for padding or comfort, but you imagine you could probably lay down and rest if you really were tired.",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/lurue/cell_hall",
	]));

    set_door("iron door","/d/av_rooms/lurue/cell_hall","west","jail key","cell lock");
    add_lock("iron door","jail key","cell lock","This lock is large and complex, requiring a key or a very clever locksmith to get through.");
    set_locked("iron door",1,"cell lock");
    lock_difficulty("iron door",-90,"cell lock");
    set_open("iron door",0);
    set_string("iron door","knock","rattles the bars on the ");
    set_string("iron door","open","The bars rattle as the door is swung open.");
    set_string("iron door","close","The bars rattle as the door is swung closed.");
    set_door_description("iron door","A frame of thick iron slabs provide holes into which the iron bars are fitted.  The bars make a mesh pattern that allows you to see through them into the next room.");
}