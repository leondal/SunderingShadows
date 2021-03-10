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
	set_short("%^BOLD%^A %^BLUE%^blue%^WHITE%^ ash tree");
	set_long(
	"%^GREEN%^The tree here is a %^BOLD%^striking green%^RESET%^%^GREEN%^ color, so bright and full"+
	" of life, even though it must have withstood centuries."+
	" This %^BOLD%^%^BLUE%^blue ash%^RESET%^%^GREEN%^ tree grows straight and tall, not"+
	" branching out very much at all. The branches start"+
	" close to the base of the trunk and are covered in"+
	" thick %^BOLD%^%^BLUE%^leaves%^RESET%^. The leaves have"+
        " a slightly %^BLUE%^b%^BOLD%^l%^CYAN%^u%^RESET%^%^BLUE%^i"+
        "%^BOLD%^s%^CYAN%^h%^RESET%^%^GREEN%^ cast"+
	" to them and are oblong in shape, spinning down to a"+
	" slender point. The stems are slight and easily blown"+
	" by the wind, but they don't have far to move on their"+
	" short branches.\n"
	);
	set("night long",
	"%^GREEN%^Even in the %^BOLD%^%^WHITE%^moonlight%^RESET%^%^GREEN%^ the leaves are still a %^BOLD%^bright"+
	" green%^RESET%^%^GREEN%^. They've got a slight %^BOLD%^%^BLUE%^blue%^RESET%^%^GREEN%^ sheen to them but"+
	" look full of life. The %^BOLD%^%^BLUE%^blue ash %^RESET%^%^GREEN%^tree is quite tall"+
	" but not very wide. The leaves are thick, preventing"+
	" anyone from seeing much into the tree. The branches"+
	" start low, perhaps only three feet from the ground."+
	" The %^RESET%^wind%^GREEN%^ dances through the branches, making the"+
	" leaves flutter. Only a slight %^BOLD%^%^BLACK%^shadow%^RESET%^%^GREEN%^ is cast on the"+
	" ground from this tree, and it looks almost comical"+
	" because it's so skinny and sways back in forth in the"+
	" wind like a dancer.\n"
	);
	set_smell("default",
	"The smell of the blue ash is unusual, almost like an evergreen."
	);
	set_listen("default",
	"The fluttering of the leaves has a nice melodic tone."
	);
	set_items( ([
	({"tree","ash","blue ash"}) : "%^BOLD%^%^BLUE%^This is a very tall blue"+
	" ash tree. The leaves are a lovely green and cluster"+
	" around the tree to conceal it from prying eyes. The"+
	" trunk is very long, but quickly gives way to smaller"+
	" branches that the leaves cling to.",
	"trunk" : "%^BLUE%^%^BOLD%^You can't see much of the actual trunk"+
	" because the foliage quickly covers it. The blue ash"+
	" got its name from the dye that is made from the inner"+
	" bark of the tree that is a gorgeous blue.",
	"branches" : "%^BOLD%^The branches are rather slender, though"+
	" they could probably hold a good deal of weight. They"+
	" are thickly covered in leaves.",
	"leaves" : "%^BOLD%^%^GREEN%^The leaves are a bright green with just a"+
	" slight hint of blue to them. They are plentiful and"+
	" sleek, clustering together along slender stems.",
	]) );
	set_exits( ([
	"north" : ROOMS+"v41",
	"south" : ROOMS+"g86",
	"west" : ROOMS+"g85",
	"east" : ROOMS+"g84",
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
	if(str != "tree" && str != "ash") {
		write("The only thing to climb here is a tree.");
		return 1;
	}
	else {
		write("%^BOLD%^You walk to the base of the ash and"+
		" begin to climb up the tree.");
		say("%^BOLD%^"+TP->query_cap_name()+" walks to the"+
		" base of the ash tree and disappears beneath the"+
		" leaves as "+TP->query_subjective()+" begins to climb.");
		this_player()->move_player(ROOMS+"ash");
		return 1;
	}
}
