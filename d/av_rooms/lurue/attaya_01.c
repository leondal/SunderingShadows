// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("attaya_01");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^a comfortable room%^RESET%^");

    set_long("%^RESET%^This comfortable room is lined with %^RED%^red carpets %^RESET%^and %^ORANGE%^golden accents%^RESET%^, making it warm and comfortable.  In a recessed wall, a soft feather-down bed has been se"
	"t.  The %^BOLD%^%^BLACK%^rich wood paneling %^RESET%^of the foot and headboards a contrast to the %^ORANGE%^deep cream %^RESET%^of the walls.  To either side of the bed, %^BOLD%^%^BLACK%^mahogany nigh"
	"tstands %^RESET%^have been set.  Each features a small drawer and some intricate latticework along the sides and front.  At the foot of the bed, a large, square chest serves as a place to tuck away a "
	"few personal items.  Like the rest the furniture this too is formed out of %^BOLD%^%^BLACK%^mahogany %^RESET%^and is decorated in latticework that gives it an intricate, formal appearance.  A large %^"
	"YELLOW%^brass lock %^RESET%^prevents it from being opened. Across from the bed, a large fireplace occupies the majority of a wall.  %^ORANGE%^G%^YELLOW%^o%^BLACK%^l%^RESET%^%^ORANGE%^d%^BOLD%^%^BLACK%"
	"^e%^RESET%^%^ORANGE%^n m%^YELLOW%^a%^BLACK%^r%^RESET%^%^ORANGE%^b%^YELLOW%^l%^RESET%^%^ORANGE%^e %^RESET%^has provided a mantle that tapers down the wall and then falls in a carved sheet toward the gr"
	"ound, opening in a dome shaped arch to allow for a fire to be built.  A %^BOLD%^%^BLACK%^black metal grate %^RESET%^covers the front, stopping any %^RED%^e%^BOLD%^%^BLACK%^m%^RESET%^%^RED%^b%^BOLD%^%^"
	"BLACK%^er%^RESET%^%^RED%^s%^RESET%^ from escaping onto the plush %^RED%^red carpets%^RESET%^.  Set beside the fireplace in a %^YELLOW%^brass basket %^RESET%^are several neatly arranged logs and a smal"
	"l box of tinder.  This would be a cozy spot to rest and tune out the horrors of the Attaya landscape.%^RESET%^"
	);

    set_smell("default","
A soft breeze carries through the room the scent of Hibiscus flowers.");
    set_listen("default","The faint sound of the ocean shore drifts through a window.");

    set_search("chest","%^BOLD%^%^BLACK%^Try as you might, you can't get that %^YELLOW%^brass lock%^BLACK%^ to let go.  Maybe its enchanted against theft.  That would explain why this home was left as open as it is.%^RESET%^");
    set_search("nightstands","%^BOLD%^%^BLACK%^You open the drawers of both nightstands but discover nothing of particular interest.  Just personal items of whomever lives here.%^RESET%^");
    set_search("fireplace","%^RESET%^%^ORANGE%^You search around the fireplace and realize it is a lot larger then a fireplace really needs to be.  Especially in such a mild climate as Attaya has.  Someone could even stand up inside there.%^RESET%^");
    
set_items(([ 
	({ "basket", "wood", "tinder" }) : "%^RESET%^%^ORANGE%^Arranged in a neat pile the stacked wood is set into a pretty open sided %^YELLOW%^brass basket%^RESET%^%^ORANGE%^.  Set on top is a little box of tinder ready to help start the fire.%^RESET%^",
	({ "fireplace", "marble", "grate", "mantle" }) : "%^RESET%^%^ORANGE%^The large fireplace is elegantly simple.  Carved from a rich golden marble, the smooth surface of the mantle tapers down on the underside to smooth out along the wall, opening in the center to provide a dome shaped opening for the fireplace.  Covering this a metal grate has been stretched.  If there was a fire burning, the grate would keep any sparks or coals from tumbling out into the carpets and starting a fire.%^RESET%^",
	({ "nightstands", "night stands", "stands" }) : "%^BOLD%^%^BLACK%^Covered in contrasting gold latticework, the mahogany wood gleams almost black underneath. A set of drawers allow a few small things to be tucked away in them, but nothing of interest.",
	({ "wall", "walls", "accents", "gold accents", "golden accents" }) : "%^RESET%^%^ORANGE%^The walls are a rich cream color, nearly golden in color.  This coloring is made deeper by the use of the red carpets and dark furniture.%^RESET%^",
	({ "carpets", "red carpets", "carpet" }) : "%^BOLD%^%^RED%^Even though they're throw rugs, they've been fitted in such a way as to cover every square inch of the cold floor below making them wall-to-wall and very plush for walking on.%^RESET%^",
	"chest" : "%^BOLD%^%^BLACK%^This %^YELLOW%^brass locked%^BLACK%^ chest is sturdy and could hold a good number of personal items.  Like the nightstands, it is covered in a contrasting gold latticework that makes the deep red almost black in color.%^RESET%^",
	]));

    set_exits(([ 
		"south" : "/d/attaya/seneca4",
		"fireplace" : "/d/av_rooms/lurue/attaya_02",
	]));



    set_invis_exits(({ "fireplace" }));

}