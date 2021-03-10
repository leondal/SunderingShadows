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
	set_short("%^BOLD%^%^WHITE%^A %^RED%^cherry%^WHITE%^ tree.");
	set_long(
	"%^GREEN%^A large %^RED%^%^BOLD%^cherry%^RESET%^%^GREEN%^ tree is growing here. It casts shade"+
	" onto the ground, creating an inviting spot to sit"+
	" and cool down for a moment. The tree is %^BOLD%^%^MAGENTA%^blooming"+
	" %^RESET%^%^GREEN%^and is covered with delicate %^BOLD%^%^MAGENTA%^light pink%^RESET%^%^GREEN%^ flowers."+
	" Their scent is brought down to you by the breeze"+
	" and you can see a few %^YELLOW%^honey bees%^RESET%^%^GREEN%^ buzzing around"+
	" the blossoms. The tree is growing straight and"+
	" tall and looks quite sturdy. Curiously, there are"+
	" no fallen blossoms on the ground and the %^BOLD%^grass%^RESET%^%^GREEN%^"+
	" near the base of the tree is even shorter, almost"+
	" as though this place is tended to.\n"
	);
	set("night long",
	"%^GREEN%^There is a sturdy %^BOLD%^%^RED%^cherry%^RESET%^%^GREEN%^ tree growing here. It"+
	" casts an even darker%^BOLD%^%^BLACK%^ shadow %^RESET%^%^GREEN%^on the ground around"+
	" you. In the %^BOLD%^%^WHITE%^moonlight%^RESET%^%^GREEN%^"+
        " the %^BOLD%^%^MAGENTA%^cherry blossoms%^RESET%^%^GREEN%^ look"+
	" like small %^BOLD%^%^WHITE%^silver%^RESET%^%^GREEN%^ flowers from an enchanted land."+
	" The %^BOLD%^grass%^RESET%^%^GREEN%^ around the base of the tree grows short"+
	" as if it is cared for. The tree itself seems quite"+
	" healthy, its thick trunk is growing straight and"+
	" tall.\n"
	);
	set_items( ([
	({"tree", "cherry", "cherry tree"}) : "%^RED%^%^BOLD%^This is a tall,"+
	" sturdy cherry tree. It looks like it would be fun to"+
	" climb.",
	"blossoms" : "%^BOLD%^%^MAGENTA%^These delicate little blossoms cover"+
	" the cherry tree.",
	"bees" : "%^YELLOW%^Honey bees are buzzing happily around the"+
	" cherry blossoms."
	]) );
	set_smell("default",
	"Cherry blossoms scent the air.",
	);
	set_listen("default",
	"The sound of honey bees buzzing merrily can be heard."
	);
	set_exits( ([
	"west" : ROOMS+"g29",
	"east" : ROOMS+"g30",
	"north" : ROOMS+"g114",
	"south" : ROOMS+"g17",
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
	if(str != "tree" && str != "cherry") {
		write("The only thing to climb here is a tree.");
		return 1;
	}
	else {
		write("%^BOLD%^You can smell the wonderful fragrance"+
		" of the cherry blossoms as you climb into the tree.");
		say(
		"%^BOLD%^"+TP->query_cap_name()+" climbs up the tree,"+
		" knocking a few blossoms loose as"+
		" "+TP->query_subjective()+" pulls "+TP->query_objective()+"self"+
		" into the tree.");
		this_player()->move_player(ROOMS+"cherry");
		return 1;
	}
}

void reset() {
   if(!present("statue"))
new("/realms/dinji/coolstuff/lliira.c")->move(TO);
}
