#include <std.h>
#include "../valley.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(BRANCHES);
   set_travel(FRESH_BLAZE);
   set_property("no charge",1);
   set_charge_message("You can't charge something in a tree!");
	set_property("indoors",2);
	set_property("light",3);
	set_short("%^BOLD%^Branches of an ash tree");
	set_long(
	"%^GREEN%^You are standing in the branches of the%^BOLD%^%^BLUE%^blue ash%^RESET%^%^GREEN%^ tree."+
	" Although the branches do not appear to be very thick,"+
	" they seem to easily support your weight. From here you"+
	" can see a network of branches extending upwards, almost"+
	" like a ladder. You can not see much through the %^BOLD%^%^BLUE%^leaves"+
	" %^RESET%^%^GREEN%^because they are so thickly crowded together. This tree"+
	" does appear to be in quite good health, you can't imagine"+
	" anything felling it.\n"
	);
	set("night long",
	"%^GREEN%^You're in the branches of a great %^BOLD%^%^BLUE%^blue ash%^RESET%^%^GREEN%^. Everything is"+
	" very %^BOLD%^%^BLACK%^dark%^RESET%^%^GREEN%^ in here, only a little"+
        " %^BOLD%^%^WHITE%^moonlight%^RESET%^%^GREEN%^ pours in"+
	" through the thick leaves. The branches wind away into the"+
	" darkness. The wind whistles through the leaves, but"+
	" fortunately the tree does not sway much. The outside"+
	" world is blocked off and you are enclosed in this little"+
	" section that has a surreal feeling.\n"
	);
	set_smell("default",
	"The scent of ash is all around you."
	);
	set_listen("default",
	"The leaves flutter in the wind."
	);
	set_items( ([
	"leaves" : "%^BOLD%^%^BLUE%^The leaves are clustered together, blocking"+
	" any view of the rest of the world and allowing only a"+
	" little light to pass through.",
	"branches" : "The branches spiral upwards, almost like a"+
	" ladder, reaching the top of the tree. The ones that you"+
	" are standing on aren't very big, but they support you."+
	" As they go higher, they look more inclined to break if"+
	" much weight was put on them.",
	"trunk" : "The trunk is short and a beautifully light"+
	" color as most ash are.",
	]) );
	set_exits( ([
	"down" : ROOMS+"dryad1",
	]) );
	set_pre_exit_functions(({"down"}),({"go_down"}));
}

int go_down()
{
	write("You climb down the short distance to the ground.");
	return 1;
}

void reset()
{
	::reset();
	if(!present("dryad")) {
		new(MONS+"ash_dryad")->move(TO);
	}
}
