// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    set_name("masq_t1");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^A %^MAGENTA%^C%^RESET%^%^GREEN%^o%^MAGENTA%^l%^BOLD%^%^WHITE%^or%^RESET%^%^MAGENTA%^f%^GREEN%^u%^BOLD%^%^MAGENTA%^l %^WHITE%^Tent%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^Guarding the entryway is a costumed performer.  Her delicate frame draped in %^MAGENTA%^silks %^WHITE%^and %^RESET%^gauze %^BOLD%^%^WHITE%^as she collects the donations and hands out "
	"the costumer's ring and pouch for holding all of ones things while in costume.  Around her, like a fairy wonderland, the ribbons of %^MAGENTA%^pink%^WHITE%^, %^RESET%^%^MAGENTA%^purple%^BOLD%^%^WHITE%"
	"^, %^RESET%^%^GREEN%^green %^BOLD%^%^WHITE%^and %^RESET%^white %^BOLD%^%^WHITE%^can be seen cascading down the interior and exterior walls.  Potted %^RESET%^%^ORANGE%^trees%^BOLD%^%^WHITE%^, webs of d"
	"ripping %^RESET%^%^GREEN%^ivy %^BOLD%^%^WHITE%^and %^RESET%^%^CYAN%^moss %^BOLD%^%^WHITE%^blend together with the illusion magic that supplies a %^CYAN%^waterfall %^BOLD%^%^WHITE%^in the next room and"
	" the little %^MAGENTA%^sprites %^WHITE%^which flit amongst the branches and tent poles.  Throughout, a %^RESET%^fine mist %^BOLD%^%^WHITE%^spills across the floor, rolling over your ankles, and hiding"
	" the expensive rugs that keep the earthen floor from becoming trodden and muddy.%^RESET%^"
	);

    set_smell("default","
%^RESET%^%^ORANGE%^A %^BOLD%^%^WHITE%^sweet%^RESET%^%^ORANGE%^, %^RESET%^%^MAGENTA%^delicate %^ORANGE%^fragrance graces the air.%^RESET%^");
    set_listen("default","Laughter and merriment echo through the tent.");

    
set_items(([ 
	({ "sprite", "sprites" }) : "%^BOLD%^%^MAGENTA%^Little colorful %^CYAN%^sprites%^MAGENTA%^ and darting %^WHITE%^will-o-wisps%^MAGENTA%^ flit through the limbs of the trees and decorations within the tent.  Their playful movements drawing the eye and adding a bit of enchantment to the already %^RESET%^%^GREEN%^s%^MAGENTA%^u%^BOLD%^r%^WHITE%^r%^RESET%^%^MAGENTA%^e%^GREEN%^a%^BOLD%^l %^MAGENTA%^setting.%^RESET%^",
	({ "forest", "plants", "ivy", "moss" }) : "%^RESET%^%^GREEN%^Designed to look like a fairyland forest, the interior of the tent is decorated in carefully arranged plants.  Tall %^ORANGE%^trees%^GREEN%^, climbing %^BOLD%^ivy%^RESET%^%^GREEN%^, leafy %^CYAN%^ferns%^GREEN%^, %^MAGENTA%^fl%^BOLD%^ow%^WHITE%^e%^RESET%^%^MAGENTA%^ri%^BOLD%^n%^RESET%^%^MAGENTA%^g %^GREEN%^trestles are arranged all the way around the room, encircling it and all but blocking the colorful tent panels.%^RESET%^",
	({ "archways", "branches", "branch", "flaps" }) : "%^BOLD%^%^WHITE%^Tucked under the %^RESET%^%^ORANGE%^branches %^BOLD%^%^WHITE%^of the trees, you can make out several solid colored tent flaps that lead into the changing rooms.  Every so often a newly costumed attendee appears from one of the many dressing rooms, adding to the %^RESET%^%^GREEN%^s%^MAGENTA%^u%^BOLD%^r%^WHITE%^r%^RESET%^%^MAGENTA%^e%^GREEN%^a%^BOLD%^l %^WHITE%^environment.%^RESET%^",
	({ "mist", "floor", "carpet" }) : "%^RESET%^A thick blanket of fog obscures the floor, hiding the cushioning carpets and giving the feeling of walking through a mist shrouded forest.%^RESET%^",
	({ "waterfall", "misty waterfall", "fall", "falls" }) : "%^BOLD%^%^WHITE%^A glistening %^CYAN%^waterfall %^WHITE%^made of magic spills from the top of the western wall where a few shelves of %^BLACK%^stone %^WHITE%^can be seen.  The %^CYAN%^water %^WHITE%^falls down to either side of a glass walkway at the end of which, a %^RESET%^%^MAGENTA%^mystical portal %^BOLD%^%^WHITE%^can be seen, leading to the lands of %^RESET%^Mist%^BOLD%^%^WHITE%^ and %^CYAN%^Dreams%^WHITE%^.%^RESET%^",
	({ "walkway", "glass walkway" }) : "%^RESET%^%^CYAN%^What appears to be a walkway made of clear glass rises out of the mists and up toward a %^RESET%^%^MAGENTA%^mystical portal %^CYAN%^that awaits your entry.%^RESET%^",
	({ "portal", "mystical portal" }) : "%^RESET%^%^MAGENTA%^Half way up the western wall, suspended between two shimmering curtains of %^BOLD%^%^CYAN%^water%^RESET%^%^MAGENTA%^, a mystical portal swirls with glowing lights and mist.  A walkway made of %^CYAN%^glass %^MAGENTA%^rises from the mists toward this portal that waits to take you to the lands of %^RESET%^Mist%^MAGENTA%^ and %^BOLD%^%^CYAN%^Dreams%^RESET%^%^MAGENTA%^.%^RESET%^",
	]));

    set_exits(([ 
		"west" : "/d/av_rooms/lurue/masq_t2",
		"east" : "/d/darkwood/room/road7",
	]));

}

void reset(){
   ::reset();
   if(!present("fey doorkeeper")) new("/d/avatars/nienne/party/baglady")->move(TO);
}