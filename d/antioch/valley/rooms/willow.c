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
	set_short("%^BOLD%^Branches of a willow");
	set_long(
	"%^GREEN%^You're in the branches of a %^BLUE%^willow%^GREEN%^ tree. It's"+
	" very spacious here, all the leaves fall far away, creating a"+
	" veil of privacy from the outside world. Even the ground"+
	" beneath the tree is protected by this veil, the leaves"+
	" reach all the way to the %^BOLD%^ground%^RESET%^%^GREEN%^, brushing against it as"+
	" they're blown by the wind. The wood is very smooth and"+
	" a %^ORANGE%^light brown%^RESET%^%^GREEN%^ color, incredibly strong. There aren't that"+
	" many branches, but they do make it easy to climb this"+
	" tree. The very top looks a little flimsy though, judging"+
	" by the ease with which the wind is blowing it.\n"
	);
	set("night long",
	"%^GREEN%^Little %^YELLOW%^fireflies%^RESET%^%^GREEN%^ are buzzing all around. You're in the"+
	" branches of a %^BLUE%^willow%^GREEN%^ tree, but it almost seems to be a"+
	" gathering place for %^YELLOW%^fireflies%^RESET%^%^GREEN%^ there are so many of them."+
	" They're pretty, though, little dancing flecks of %^RESET%^%^BOLD%^light%^RESET%^%^GREEN%^"+
	" in the %^BOLD%^%^BLACK%^darkness%^RESET%^%^GREEN%^. The leaves of the tree fall around away"+
	" from the tree, draping to the ground and blocking out"+
	" much of the light from the %^BOLD%^%^WHITE%^moon%^RESET%^%^GREEN%^ and the%^RESET%^ stars%^GREEN%^, but the"+
	" %^YELLOW%^fireflies%^RESET%^%^GREEN%^ give off a nice %^BOLD%^%^WHITE%^g%^YELLOW%^"+
        "l%^WHITE%^o%^YELLOW%^w%^RESET%^%^GREEN%^ that makes it easier to"+
	" see. The tree stretches up a ways into the night. The"+
	" top of the tree is easily blown by the wind, as well"+
	" as the leaves and several of the other branches. The"+
	" section you're in right now seems pretty sturdy, but"+
	" climbing higher might be too dangerous.\n"
	);
	set_smell("default",
	"A faint scent of wildflowers is blown to you on the wind."
	);
	set_listen("default",
	"The ruffling of the leaves almost has a melodic quality."
	);
	set_items( ([
	"leaves" : "%^BLUE%^The leaves fall around the tree, almost like"+
	" a huge umbrella, keeping it safe from everything and"+
	" drifting all the way to the ground.",
	"fireflies" : "%^YELLOW%^The fireflies buzz merrily, dancing specks"+
	" of light. There are a lot of them here and they give"+
	" off a gentle glow.",
	"branches" : "%^ORANGE%^The branches are a rich brown color, very"+
	" smooth and strong. The ascend high into the sky, growing"+
	" smaller and weaker as they get higher.",
	"ground" : "%^GREEN%^The ground below you looks as though it has"+
	" been cleared away for a resting area and the grass is"+
	" shorter there.",
	]) );
	set_exits( ([
	"down" : ROOMS+"dryad4",
	]) );
}

void reset()
{
	::reset();
	if(!present("dryad")) {
		new(MONS+"willow_dryad")->move(TO);
	}
}
