// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("sunetemple_08");
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Passion's Alcove%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This alcove is the largest of the three and has been created in the causeway formed between two columns.  Sheer, alternating drapes of %^RESET%^ivory %^BOLD%^%^WHITE%^and %^YELLOW%^go"
	"ld %^WHITE%^toned silk hang from %^RESET%^%^CYAN%^platinum %^BOLD%^%^WHITE%^rings affixed to the ceiling's rim.  The diaphanous, billowing material encloses the small area giving it a semblance of int"
	"imate privacy.  Encircling the back half of the recess is a low marble wall.  Upon it rests a raised %^RESET%^%^ORANGE%^bronze plaque %^BOLD%^%^WHITE%^with a meditative prayer etched in fluid %^YELLOW"
	"%^gold scrollwork%^WHITE%^.  Before the wall stretches a white marble floor inlaid with a mosaic of colorful tiles that form a outward spiraling %^RED%^r%^YELLOW%^i%^RED%^b%^YELLOW%^b%^RED%^o%^YELLOW%"
	"^n %^WHITE%^of alternating %^YELLOW%^gold %^WHITE%^and %^RED%^red %^WHITE%^shades.  Situated above the spiraling tiles is a circular %^BLACK%^mahogany %^WHITE%^table with several %^RESET%^%^CYAN%^intr"
	"icately %^BOLD%^%^WHITE%^carved, high back chairs positioned around it. Above the table hanging from a similarly tiled ceiling as the floor, is a %^YELLOW%^golden %^WHITE%^chandelier.  Designed to loo"
	"k like a dozen long stem %^RED%^roses%^WHITE%^, each life-like %^RESET%^%^RED%^rosebud %^BOLD%^%^WHITE%^is crafted from a intricately cut %^RED%^ruby %^WHITE%^petals which are imbued with a soft, magi"
	"cal light that glows from their center.  The petals are shaped and set in such a way that the alcove is lit with a %^MAGENTA%^rosy glow%^WHITE%^, while the table is illuminated with a more natural %^R"
	"ESET%^white %^BOLD%^%^WHITE%^light, revealing the delicate etchings upon the polished wood.  It seems an inviting place to sit and engage others within.%^RESET%^"
	);

    set_smell("default","
The faint scent of roses fills your senses.");
    set_listen("default","You can hear the sounds of joyful laughter coming from the garden temple.");


    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/sunetemple_07",
		"northeast" : "/d/av_rooms/lurue/sunetemple_09",
		"east" : "/d/av_rooms/lurue/sunetemple_03",
	]));

}