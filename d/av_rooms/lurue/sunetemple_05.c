// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sunetemple_05");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("shallow water");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Pool of Devotion%^RESET%^");

    set_long("%^BOLD%^%^BLUE%^From the deepest waters at the center of the pool to the shallows at the sculpted %^WHITE%^marbled %^BLUE%^edge, %^RED%^rose petals %^BLUE%^float upon the %^CYAN%^crystal blue %^BLUE%^"
	"surface of the %^WHITE%^Pool of Devotions%^BLUE%^, their sweet perfume clinging to every drop and leaving their trace upon the %^RESET%^%^ORANGE%^skin %^BOLD%^%^BLUE%^of all who anoint themselves.  Ri"
	"sing above these petal strewn waters, with her head lifted in joyous %^MAGENTA%^rapture %^BLUE%^and her hands held outward in a %^YELLOW%^welcoming %^BLUE%^gesture, %^RED%^Sune Firehair's%^BLUE%^ stat"
	"ue stands upon a %^YELLOW%^golden platform%^BLUE%^.  Around her, their hands and faces upraised in %^RED%^praise%^BLUE%^, stand statues of comely men and women of all races.  At the edge of the pool, "
	"%^RESET%^%^ORANGE%^bronze statues %^BOLD%^%^BLUE%^of centaurs stand with their heads and forelegs raised, lifting %^YELLOW%^golden trumpets %^BLUE%^in tribute to the %^RED%^Lady of Love%^BLUE%^.  Casc"
	"ades of %^CYAN%^clear water %^BLUE%^falls from the trumpets in %^WHITE%^br%^CYAN%^i%^WHITE%^ll%^CYAN%^i%^WHITE%^ant %^BLUE%^waterfalls, though the surface of the pool seems oddly calm and inviting.   "
	"Rose bushes with %^RESET%^%^RED%^scarlet petals %^BOLD%^%^BLUE%^are strategically placed about the centaur's feet to hide the wide bases that support them.  The blooms lending their fragrance to the a"
	"ir.%^RESET%^"
	);

    set_smell("default","
The sweet scent of roses mixes with the cool essence of water.");
    set_listen("default","The splash of water mixes with the sound of laughter coming from the garden temple.");


    set_exits(([ 
		"dive" : "/d/av_rooms/lurue/sunetemple_11",
		"west" : "/d/av_rooms/lurue/sunetemple_03",
	]));



    set_invis_exits(({ "dive" }));

}