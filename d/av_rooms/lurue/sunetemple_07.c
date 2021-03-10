// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sunetemple_07");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Library of Dedication%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This wide hallway stretches along the southwestern side of the temple grounds, connecting the alcoves of %^RED%^love %^WHITE%^and %^MAGENTA%^passion %^WHITE%^together.  Lining each si"
	"de of the marble corridor is a myriad of low %^RESET%^%^ORANGE%^wooden bookshelves%^BOLD%^%^WHITE%^.  Within each can be dozens of %^RESET%^%^CYAN%^books %^BOLD%^%^WHITE%^and %^BLACK%^scrolls %^WHITE%"
	"^that have been gathered over the years.  Each piece being dedicated to one of the facets of the %^RED%^Lady%^WHITE%^.  Reading %^RESET%^%^ORANGE%^pedestals %^BOLD%^%^WHITE%^have been placed between t"
	"he shelves, their simple, unadorned white wood polished to a %^CYAN%^lustrous shine %^WHITE%^and draped with soft %^RESET%^%^RED%^burgundy velvet%^BOLD%^%^WHITE%^.  Above each shelf, hanging within si"
	"mple, %^YELLOW%^gilded frames %^WHITE%^are paintings, drawn by the realms many artists and preserved here, as are the written works, for the enjoyment of all.%^RESET%^"
	);

    set_smell("default","
The scent of polish mixes with the faint hint of roses that drifts in from outside.");
    set_listen("default","The hallway is filled with the sound of pages being turned.");


    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/sunetemple_06",
		"northwest" : "/d/av_rooms/lurue/sunetemple_08",
	]));

}