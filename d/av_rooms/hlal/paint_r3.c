// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("paint_r3");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^MAGENTA%^Trapped within a painting %^WHITE%^- %^BOLD%^Music Room%^RESET%^");

    set_long("%^CYAN%^Heavy, %^BOLD%^pale blue %^RESET%^%^CYAN%^fabric panels line each of the walls of this small space. Each corner of the room is sectioned off with a %^BOLD%^%^BLUE%^wooden screen. %^RESET%^%^CY"
	"AN%^Behind each screen seems to be where the %^WHITE%^instruments %^CYAN%^and other supplies are kept. There are %^ORANGE%^benches %^CYAN%^and stools strategically placed in the center of the room wit"
	"h %^GREEN%^music stands %^CYAN%^in front of each. The ceiling is covered in %^BOLD%^mirrors %^RESET%^%^CYAN%^that reflect down upon those in the room and the plush dark blue %^BLUE%^carpet %^CYAN%^ben"
	"eath them.%^RESET%^"
	);

    set_smell("default","
%^ORANGE%^It smells of wood polish and old paper here.");
    set_listen("default","%^YELLOW%^The sound of people practicing their instruments invades the senses.");

    
set_items(([ 
	"1" : "%^BOLD%^%^WHITE%^This screen has been painted with silvery musical notes. Hiding behind it are a few old boxes full of sheet music.",
	"2" : "%^MAGENTA%^This one has the keys of a paino painted onto it. Hidden behind it are a few stacked chairs and a lonely broken flute.",
	"screen" : "%^CYAN%^Which one? Your choices are 1,2,3, or 4.",
	"3" : "%^GREEN%^Here someone painted a lush meadow in vivid detail. Behind the screen are a few empty boxes. It appears as if someone or something has tore right through them and kept whatever was inside to themselves.",
	"benches" : "%^ORANGE%^They look hard and uncomfortable.",
	"4" : "%^CYAN%^A tiny blue pixie sits upon a dying %^WHITE%^white rose. %^CYAN%^It almost seems to point towards the %^BOLD%^west.",
	"mirrors" : "%^BOLD%^%^CYAN%^They are hard to focus on for some reason...",
	"instruments" : "%^BLUE%^Almost any instrument you could imagine.",
	"flute" : "%^ORANGE%^It isn't worth fixing. Probably why it has been discarded.",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/hlal/paint_r5",
	]));



    set_invis_exits(({ "west" }));

}