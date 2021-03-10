// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("paint_r1");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^MAGENTA%^Trapped within a painting%^RESET%^");

    set_long("%^CYAN%^Chaos unfolds before you. It is as if a %^GREEN%^thousand scenes %^CYAN%^appear around you in painted form, ever changing and difficult to view for more than a moment. Even the most focused of"
	" minds would have trouble deciphering what goes on around them here. The consequence of trying is dizzying but if lucky, you might eventually find the %^BOLD%^true nature %^RESET%^%^CYAN%^of the room."
	"%^RESET%^"
	);

    set_smell("default","
%^BOLD%^%^CYAN%^Fresh paint and other oils scent the air%^RESET%^");
    set_listen("default","%^BOLD%^%^WHITE%^The deep silence here contradicts the neverending drama that unfolds%^RESET%^");

    set_search("wand","%^CYAN%^If you want out of here you could try to %^BOLD%^use %^RESET%^%^CYAN%^the %^BOLD%^wand %^RESET%^%^CYAN%^again.");
    
set_items(([ 
	"scene 2" : "%^MAGENTA%^A slender woman carves a flute out of an %^BOLD%^%^WHITE%^innocent looking stick",
	"true nature" : "%^BOLD%^%^GREEN%^A river of paint flows steadily along the ground, fed by a colorful waterfall. In the center of the river is a pedestal holding a %^YELLOW%^wand %^RESET%^%^GREEN%^of some kind",
	"scene 3" : "%^BOLD%^%^BLACK%^A shadowy figure sneaks towards a chest full of %^YELLOW%^treasure.",
	"wand" : "%^BOLD%^%^WHITE%^The wand has trouble holding its shape. It takes on many forms. It leads one to wonder what might happen if you search it",
	"scenes" : "%^GREEN%^There are thousands of scenes and more being created every second. Three of the scenes show themselves most clearly though.%^RESET%^",
	"scene 1" : "%^BOLD%^%^MAGENTA%^A young girl is in the middle of opening her presents at her birthday celebration%^RESET%^",
	]));

    set_exits(([ 
		"northeast" : "/d/av_rooms/hlal/paint_r3",
		"north" : "/d/av_rooms/hlal/paint_r4",
		"northwest" : "/d/av_rooms/hlal/paint_r2",
	]));



    set_invis_exits(({ "northwest", "northeast", "north" }));

}