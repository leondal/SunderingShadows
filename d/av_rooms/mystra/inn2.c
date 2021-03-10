// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("inn2");
    set_property("indoors",1);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Castwater Dining Hall%^RESET%^");

    set_long("This is the dining room of the Castwater Inn.  The walls, except for the eastern wall, have been painted in a %^BOLD%^%^MAGENTA%^warm rose %^RESET%^color and decorated with several scenic %^MAGENTA%^m"
	"urals%^RESET%^.  Between each mural, a set of %^BOLD%^%^YELLOW%^gold-plated sconces %^RESET%^illuminate the room at it's edges.  In the center of the room, a large %^BOLD%^%^YELLOW%^chandelier%^RESET%"
	"^ hangs down to take care of the lighting.  Several small tables randomly placed about give comfort and support to weary travelers as they wait for a meal.  The tables are each lined with a nice, %^BO"
	"LD%^%^WHITE%^white tablecloth.  %^RESET%^On the north wall, a %^ORANGE%^bar %^RESET%^sits awaiting those looking for a drink or two.  A doorway to the west leads to the kitchen."
	);

    set_smell("default","
%^CYAN%^Warm pies, fresh entrees, and malts to please the nose%^RESET%^");
    set_listen("default","%^BOLD%^%^YELLOW%^You can make out quiet chatter and the clink of dishware%^RESET%^");


    set_exits(([ 
		"south" : "/d/av_rooms/mystra/inn1",
	]));

}