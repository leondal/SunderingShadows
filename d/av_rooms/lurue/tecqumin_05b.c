// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("tecqumin_05b");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_terrain("built tunnel");
    set_travel("stairway");
    set_climate("temperate");

    set_short("%^RESET%^%^CYAN%^A narrow stairwell%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This chamber is barely more then a few feet wide.  The stained walls of %^RESET%^pale stone %^BOLD%^%^BLACK%^are over run by thick cobwebs of %^RESET%^%^ORANGE%^roots %^BOLD%^%^BLACK%"
	"^and %^RESET%^%^GREEN%^vine %^BOLD%^%^BLACK%^growth that make the already claustrophobic area, more so.  Central to this room is a large stone slab upon which a cloth wrapped %^RESET%^%^ORANGE%^figure"
	" %^BOLD%^%^BLACK%^lays.  The body is ancient, based on the preserved condition of the cloth wraps.  Oddly, %^RESET%^%^CYAN%^shackles %^BOLD%^%^BLACK%^of decaying vines have been placed around both han"
	"ds and feet, as though the body were being restrained at the time of its internment.  More %^RESET%^%^GREEN%^vines %^BOLD%^%^BLACK%^wrap around the body and slab, further pinning the body in place.  O"
	"ver the head, an ornate mask has of %^YELLOW%^gold%^BLACK%^, %^RESET%^%^ORANGE%^topaz %^BOLD%^%^BLACK%^and %^RESET%^%^GREEN%^jade %^BOLD%^%^BLACK%^has been set.  If this were not disturbing enough, a "
	"glassy shard of %^RESET%^%^BLUE%^obsidian %^BOLD%^%^BLACK%^has been driven through the ears of the mask, passed through the head and out the other side, locking the mask in place.  From each end a set"
	" of %^YELLOW%^golden charms %^BLACK%^has been hung, their light structures chiming in the slight breeze created from your movements.%^RESET%^"
	);

    set_smell("default","
The air is musty with the smell of damp earth.");
    set_listen("default","Fresh air whistles by as it finds its way into this narrow passage.");

    set_search("mask","%^BOLD%^%^WHITE%^As you peer into the eye slits of the mask you realize that there are a set of eyes looking back up at you.  Blood shot, the silvery orbs gleam with pure malice.  A haunting wail takes up throughout the room as the body shudders and attempts to rise, but it seems incapable of doing so, much to your relief.%^RESET%^");
    
set_items(([ 
	({ "figures", "faces", "symbols" }) : "%^RESET%^%^ORANGE%^You can only make out one set of figures under all the grime and roots.  What you can see of it appears to be of a ritual where a man lays bound upon an altar, cut open and being disemboweled while a priest chants a ritual over the body and holds a dark spear above his head.  The spear looks long and slender and glints with gold at either end.%^RESET%^",
	({ "slabs", "slab", "pale stone", "stone", "stains", "wall", "walls" }) : "%^RESET%^You look closely at the walls and see that the pale stone was originally very intricately carved with several figures, faces and objects.  The stone has darkened under the attack of the elements and roots have dug into and broken apart many of the slabs, making it difficult to make out much at all.%^RESET%^",
	({ "roots", "root", "cobwebs", "cobweb" }) : "%^RESET%^%^ORANGE%^Like a fine network of living cobwebs, the roots spill out of every crevice and crawl along the surface of the stones.  Some hang down from the ceiling, clinging to your head and getting in your way of seeing.  This chamber must be ancient for as thick as these roots are.%^RESET%^",
	({ "charms", "golden charms", "charm" }) : "%^YELLOW%^The golden charms appear to be very thin and fragile.  Each is made from golden places and are only about the size of a man's thumb nail.  Each one holds a different symbol, though what they mean is uncertain.  There are similar symbols throughout the chamber, but none give a clue as to what these mean or why they were hung from either end of the glassy shard of obsidian driven through the corpse's head.%^RESET%^",
	({ "shard", "spear" }) : "%^BOLD%^%^BLACK%^Looking at the shard it appears to be a crude spear of some type.  Pointed at each end, it would have been a very dangerous weapon.  That it has been driven through the head of this body is disturbing enough to make you wonder why such a thing was done.%^RESET%^",
	({ "mask", "gold mask", "jade", "topaz", "gold" }) : "%^YELLOW%^The golden mask is thick and blocky, representative of a serpent with an array of feathers all around its collar.  Wide eye slits open in the center, through which you can perhaps %^BLACK%^<peep>%^YELLOW%^ some part of the body below.  Strangely, this serpent has ears, large humanoid ones through which an obsidian spear has been shoved.%^RESET%^",
	({ "vines", "vine", "body", "corpse", "figure" }) : "%^RESET%^%^ORANGE%^The body appears to be wrapped in thick cords of fabric that have been dipped into some sort of mixture to help preserve them.  Wound around the body are vines that have long since decayed into little more then black bands that could easily be broken if they were handled too much.  In the past though, they likely would have done well to keep the body pinned in place, if that had been needed.  The shard of obsidian through its head though, probably meant that the body didn't need to be restrained.%^RESET%^",
	]));

    set_exits(([ 
		"up" : "/d/av_rooms/lurue/tecqumin_05a",
	]));

}