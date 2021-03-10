#include <std.h>
#include "../valley.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(GRASSLANDS);
   set_travel(FOOT_PATH);
	set_property("outdoors",3);
	set_property("light",3);
	set_short("%^BOLD%^A %^BLACK%^black%^WHITE%^ walnut");
	set_long(
	"%^GREEN%^There is a large %^BOLD%^%^BLACK%^black walnut%^RESET%^%^GREEN%^ tree growing here. It"+
	" reaches high into the sky, branching out from the trunk"+
	" into a V shape. The trunk itself is has a wide girth"+
	" and it's at least six feet before other branches"+
	" begin. Two thick branches divide and spread out, each"+
	" having their own smaller branches which are still"+
	" a decent width. Higher up the branches are lost"+
	" beneath the leaves. The walnut's leaves are almost"+
	" like a %^BOLD%^fern%^RESET%^%^GREEN%^ in the way they cluster along a stem and"+
	" stick together, making for good coverage. They are"+
	" darker than most other walnut's, having a %^BOLD%^%^BLACK%^blacker"+
	" %^RESET%^%^GREEN%^shade to them. The nuts on the tree have a %^BOLD%^brighter"+
	" green %^RESET%^%^GREEN%^husk, however, and you can see several nuts"+
	" on this tree. The walnut casts a cool %^BOLD%^%^BLACK%^shadow"+
        " %^RESET%^%^GREEN%^of shade"+
	" that would be nice to rest in. You notice that the"+
	" grass around the base of the tree is lower here, as"+
	" though this is a common resting spot.\n"
	);
	set("night long",
	"%^GREEN%^A %^BOLD%^%^BLACK%^black walnut%^RESET%^%^GREEN%^ tree looms in the night."+
        " The %^BLUE%^dark leaves%^GREEN%^"+
	" simply seem to absorb the %^BOLD%^%^WHITE%^moonlight%^RESET%^%^GREEN%^ and the tree"+
	" blocks out much of the %^RESET%^starlight%^GREEN%^, casting a huge"+
	" %^BOLD%^%^BLACK%^shadow%^RESET%^%^GREEN%^ over the surrounding area. The wind harasses"+
	" the leaves and every now and then you'd swear that a"+
	" %^BLUE%^dark%^GREEN%^ and %^MAGENTA%^sinister%^GREEN%^ face appears, but you know it's"+
	" just the %^BOLD%^%^BLACK%^darkness%^RESET%^%^GREEN%^ playing tricks on you. The tree"+
	" itself is very dark, and the trunk stretches for a"+
	" ways before splitting into branches. The leaves"+
	" don't hang down low here, but there are plenty of them"+
	" and they make a %^CYAN%^strange noise%^GREEN%^ when they rustle"+
	" together.\n"
	);
	set_smell("default",
	"The sap from the black walnut is strong."
	);
	set_listen("default",
	"The rustling of the leaves is rather loud."
	);
	set_items( ([
	({"tree","walnut","walnut tree","black walnut"}) : "%^BOLD%^%^BLACK%^This"+
	" is an old black walnut tree that still looks very sturdy.",
	"leaves" : "The leaves are clustered around slender"+
	" stems, almost like a fern, there's a leaf on either"+
	" side of the stem. They get progressively smaller"+
	" until they end. There's a dark tint to them, which"+
	" is part of the reason the black walnut got its name.",
	({"nut","nuts","husk"}) : "%^BOLD%^%^GREEN%^The nuts on the tree have"+
	" a bright green husk, they're roundly shaped and"+
	" look about ready to eat.",
	"grass" : "%^GREEN%^The grass around the tree is shorter than"+
	" the rest of the valley, as though this place is"+
	" frequently used as a resting area.",
	"trunk" : "The trunk of the walnut is a deep brown"+
	" and quite thick around. It stretches up for at least"+
	" six feet before branching out.",
	"branches" : "There are two main branches that fork out"+
	" from the trunk in a V shape, further branching out"+
	" from there. They quickly get covered in leaves and"+
	" you can't see higher up in the tree at all.",
	]) );
	set_exits( ([
	"north" : ROOMS+"g25",
	"south" : ROOMS+"g1",
	"west" : ROOMS+"g22",
	"east" : ROOMS+"g21",
	]) );
}

void init()
{
	::init();
	add_action("climb", "climb");
}

int climb(string str)
{
	if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped()) {
		TP->send_paralyzed_message("info",TP);
		return 1;
	}
	if(!str) {
		write("Climb what?");
		return 1;
	}
	if(str != "tree" && str != "walnut") {
		write("The only thing to climb here is a tree.");
		return 1;
	}
	else {
		write("%^BOLD%^You climb up the trunk of the"+
		" walnut until you can reach the lower branches"+
		" and pull yourself into the tree.");
		say("%^BOLD%^"+TP->query_cap_name()+" climbs up"+
		" the trunk of the walnut until "+TP->query_subjective()+""+
		" can pull "+TP->query_objective()+"self into the tree.");
		this_player()->move_player(ROOMS+"walnut");
		return 1;
	}
}
