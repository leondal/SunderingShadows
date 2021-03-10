// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    set_name("masq_t2");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^A %^MAGENTA%^C%^RESET%^%^GREEN%^o%^MAGENTA%^l%^BOLD%^%^WHITE%^or%^RESET%^%^MAGENTA%^f%^GREEN%^u%^BOLD%^%^MAGENTA%^l %^WHITE%^Tent%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^Continuing the theme of a fairy wonderland, a magnificent %^RESET%^%^GREEN%^forest %^BOLD%^%^WHITE%^of potted %^RESET%^%^ORANGE%^plants %^BOLD%^%^WHITE%^draped in %^RESET%^%^CYAN%^mos"
	"s %^BOLD%^%^WHITE%^and %^RESET%^%^GREEN%^ivy %^BOLD%^%^WHITE%^are arranged around this part of the tent.  Several archways formed by the tree branches can be seen, through them, cleverly hidden, are d"
	"raped dressing rooms, allowing guests a private area to transform themselves.  %^RESET%^Mist %^BOLD%^%^WHITE%^rolls over the floor, obscuring the finely made carpets that cover the ground.  The source"
	" of the mist is easily apparent as the whole western wall of the room is decorated with a misty %^CYAN%^waterfall %^WHITE%^that parts in center to reveal a %^RESET%^%^MAGENTA%^mystical portal%^WHITE%^"
	"%^BOLD%^, beckoning you to enter the lands of %^RESET%^Mist %^BOLD%^%^WHITE%^and %^CYAN%^Dreams%^WHITE%^.%^RESET%^"
	);

    set_smell("default","
%^RESET%^%^ORANGE%^A %^BOLD%^%^WHITE%^sweet%^RESET%^%^ORANGE%^, %^RESET%^%^MAGENTA%^delicate %^ORANGE%^fragrance graces the air.%^RESET%^");
    set_listen("default","Laughter and merriment echo through the tent.");

    
set_items(([ 
	({ "portal", "mystical portal" }) : "%^RESET%^%^MAGENTA%^Half way up the western wall, suspended between two shimmering curtains of %^BOLD%^%^CYAN%^water%^RESET%^%^MAGENTA%^, a mystical portal swirls with glowing lights and mist.  A walkway made of %^CYAN%^glass %^MAGENTA%^rises from the mists toward this portal that waits to take you to the lands of %^RESET%^Mist%^MAGENTA%^ and %^BOLD%^%^CYAN%^Dreams%^RESET%^%^MAGENTA%^.%^RESET%^",
	({ "walkway", "glass walkway" }) : "%^RESET%^%^CYAN%^What appears to be a walkway made of clear glass rises out of the mists and up toward a %^RESET%^%^MAGENTA%^mystical portal %^CYAN%^that awaits your entry.%^RESET%^",
	({ "waterfall", "misty waterfall", "fall", "falls" }) : "%^BOLD%^%^WHITE%^A glistening %^CYAN%^waterfall %^WHITE%^made of magic spills from the top of the western wall where a few shelves of %^BLACK%^stone %^WHITE%^can be seen.  The %^CYAN%^water %^WHITE%^falls down to either side of a glass walkway at the end of which, a %^RESET%^%^MAGENTA%^mystical portal %^BOLD%^%^WHITE%^can be seen, leading to the lands of %^RESET%^Mist%^BOLD%^%^WHITE%^ and %^CYAN%^Dreams%^WHITE%^.%^RESET%^",
	({ "mist", "floor", "carpet" }) : "%^RESET%^A thick blanket of fog obscures the floor, hiding the cushioning carpets and giving the feeling of walking through a mist shrouded forest.%^RESET%^",
	({ "archways", "branches", "branch", "flaps" }) : "%^BOLD%^%^WHITE%^Tucked under the %^RESET%^%^ORANGE%^branches %^BOLD%^%^WHITE%^of the trees, you can make out several solid colored tent flaps that lead into the changing rooms.  Every so often a newly costumed attendee appears from one of the many dressing rooms, adding to the %^RESET%^%^GREEN%^s%^MAGENTA%^u%^BOLD%^r%^WHITE%^r%^RESET%^%^MAGENTA%^e%^GREEN%^a%^BOLD%^l %^WHITE%^environment.%^RESET%^",
	({ "forest", "plants", "ivy", "moss" }) : "%^RESET%^%^GREEN%^Designed to look like a fairyland forest, the interior of the tent is decorated in carefully arranged plants.  Tall %^ORANGE%^trees%^GREEN%^, climbing %^BOLD%^ivy%^RESET%^%^GREEN%^, leafy %^CYAN%^ferns%^GREEN%^, %^MAGENTA%^fl%^BOLD%^ow%^WHITE%^e%^RESET%^%^MAGENTA%^ri%^BOLD%^n%^RESET%^%^MAGENTA%^g %^GREEN%^trestles are arranged all the way around the room, encircling it and all but blocking the colorful tent panels.%^RESET%^",
	]));

    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/masq_t4a",
		"southeast" : "/d/av_rooms/lurue/masq_t5a",
		"east" : "/d/av_rooms/lurue/masq_t1",
		"portal" : "/d/av_rooms/lurue/masq_m1",
		"southwest" : "/d/av_rooms/lurue/masq_t6a",
		"northwest" : "/d/av_rooms/lurue/masq_t3a",
	]));
}

void reset() {
   if(!present("sign")) new("/d/av_rooms/lurue/masq/sign")->move(TO);
}
