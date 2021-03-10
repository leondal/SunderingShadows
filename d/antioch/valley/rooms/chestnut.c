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
	set_short("%^BOLD%^Branches of a chestnut tree");
	set_long(
	"%^RESET%^%^BOLD%^%^BLACK%^The tree is wilted and dead. Some dead leaves and pieces of rotten fruit still cling to the tree's skeleton-like branches. Blood coats its limbs and the dryad that usually resides here is nowhere to be seen.%^RESET%^\n"
//	"%^GREEN%^You've climbed up into the branches of a %^ORANGE%^chestnut%^GREEN%^ tree."+
//	" Peering down you can see that the ground is a very long"+
//	" ways from here and you better hold on tightly to the"+
//	" branches. It's a little crowded in here, the branches"+
//	" don't spread out much and tend to crowd you in. The"+
//	" inside of the tree looks incredible, however, for it"+
//	" appears that the edges are lined with %^YELLOW%^golden%^RESET%^%^GREEN%^ leaves. It"+
//	" really is quite lovely. The tree continues on upwards,"+
//	" but you can't safely climb much higher. It's peaceful"+
//	" here, though, not even the wind disturbs the leaves.\n"
	);
	set("night long",
	"%^RESET%^%^BOLD%^%^BLACK%^The tree is wilted and dead. Some dead leaves and pieces of rotten fruit still cling to the tree's skeleton-like branches. Blood coats its limbs and the dryad that usually resides here is nowhere to be seen.%^RESET%^\n"
//	"%^GREEN%^This is the %^ORANGE%^chestnut%^RESET%^%^GREEN%^ tree that you have climbed into."+
//	" You're standing on some thick branches, high above the"+
//	" ground. The leaves are blocking out most of the %^BOLD%^%^WHITE%^moonlight%^RESET%^%^GREEN%^,"+
//	" giving the place a %^BOLD%^%^BLACK%^dark%^RESET%^%^GREEN%^ atmosphere. The glimmer of"+
//	" %^YELLOW%^gold%^RESET%^%^GREEN%^"+
//	" on the underside of the leaves can barely be seen. It's"+
//	" a little crowded in here with all the branches, the tree"+
//	" isn't very wide. The branches beneath your feet are nice"+
//	" and thick, but they get more supple further up the tree.\n"
	);
	set_smell("default",
	"The ripe chestnuts smell delicious."
	);
	set_listen("default",
	"Some birds can be heard in the far distance."
	);
	set_items( ([
	"leaves" : "%^YELLOW%^All you can see from here are the undersides"+
	" of the leaves, and they're a beautiful golden shade,"+
	" encasing the tree completely.",
	"branches" : "%^ORANGE%^The branches that you're standing on look"+
	" very sturdy, but further up the tree they get smaller."+
	" They tend to crowd you in since the tree isn't that wide.",
	"ground" : "%^GREEN%^It looks like quite a fall to the ground from"+
	" here.",
	]) );
	set_exits( ([
	"down" : ROOMS+"dryad3",
	]) );
}

//void reset()
//{
//	::reset();
//	if(!present("dryad")) {
//		new(MONS+"chestnut_dryad")->move(TO);
//	}
//}
