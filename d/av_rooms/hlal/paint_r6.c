// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("paint_r6");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^MAGENTA%^Trapped within a painting %^WHITE%^- %^BOLD%^Breaking the Curse");

    set_long("%^CYAN%^Chaos unfolds before you. It is as if a %^GREEN%^thousand scenes %^CYAN%^appear around you in painted form, ever changing and difficult to view for more than a moment. Even the most focused of"
	" minds would have trouble deciphering what goes on around them here. The consequence of trying is dizzying but if lucky, you might eventually find the %^BOLD%^true nature %^RESET%^%^CYAN%^of the room."
	"%^RESET%^"
	);

    set_smell("default","
%^BOLD%^%^CYAN%^Fresh paint and other oils scent the air%^RESET%^");
    set_listen("default","%^BOLD%^%^WHITE%^The deep silence here contradicts the neverending drama that unfolds%^RESET%^");


    set_exits(([ 
		"freedom" : "/d/darkwood/room/backstage",
	]));



    set_invis_exits(({ "freedom", "freedom" }));

}