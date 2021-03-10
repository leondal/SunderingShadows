// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("brandospeakeasy");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("a dimly-lit halfling speakeasy");

    set_long("This is a dimly lit halfling speakeasy with swanky upscale furnishings. A well-stocked bar is in the back of the room, and small round tables dot the room in front of a low stage. A large sign hangs o"
	"n the wall: CLOSED FOR RENOVATIONS - COME BACK LATER!"
	);

    set_smell("default","
The faint scent of halfling pipe-weed smoke lingers in the air");
    set_listen("default","The dull roar of customers settles over the sound of smooth piano jazz");

    
set_items(([ 
	({ "tables", "table" }) : "There are two cushioned chairs to each of the small tables.",
	"stage" : "The stage is set low to the ground, yet wide enough to accomodate nearly any act. A piano sits in its back corner.",
	"bar" : "The long mahogany bar lines the entire back of the room, and numerous bottles of alcohol - some looking more legitimate-looking than others - are packed onto shelves against the wall.",
	"piano" : "A sleek black piano, with a comfortable looking stool.",
	]));

    set_exits(([ 
		"backroom" : "/d/av_rooms/brandobaris/speakeasyback",
	]));

    set_door("backroom door","/d/av_rooms/brandobaris/speakeasyback","backroom");
    set_open("backroom door",0);
    set_string("backroom door","knock","knocks cautiously on the");
    set_string("backroom door","open","The backroom door opens with a squeak of its hinges.");
    set_string("backroom door","close","The backroom door closes loudly.");
    set_door_description("backroom door","A shiny walnut door.");
}