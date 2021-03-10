// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("paint_r5");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^MAGENTA%^Trapped within a painting %^WHITE%^- %^BOLD%^Stay or Go?");

    set_long("%^MAGENTA%^You have a choice to make here. Choose well, it may decide your future. The stone walls almost feel as if they are closing in on you and the air is charged with dark energy. You can %^BOLD%"
	"^escape %^RESET%^%^MAGENTA%^now or move %^BOLD%^deeper %^RESET%^%^MAGENTA%^into the painting. Will you allow your choice to come back to haunt you later? The curse is almost broken.%^RESET%^"
	);

    set_smell("default","
%^BOLD%^%^CYAN%^Fresh paint and other oils scent the air%^RESET%^");
    set_listen("default","%^BOLD%^%^WHITE%^The deep silence here contradicts the neverending drama that unfolds%^RESET%^");


    set_exits(([ 
		"deeper" : "/d/av_rooms/hlal/paint_r6",
		"escape" : "/d/darkwood/room/backstage",
	]));



    set_invis_exits(({ "escape", "deeper" }));

}