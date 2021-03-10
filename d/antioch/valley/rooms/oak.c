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
	set_short("%^BOLD%^Branches of an oak tree");
	set_long(
	"%^GREEN%^You are standing in the branches of a"+
	" very old %^RESET%^silver oak%^GREEN%^ tree. Even though it has stood here for"+
	" centuries, it is still strong and its branches easily"+
	" hold your weight. This is a very easy tree to climb,"+
	" you could probably go higher, but there wouldn't be much"+
	" point, you can see from here that the upper branches"+
	" hold nothing of interest. The %^RESET%^%^BOLD%^leaves%^RESET%^%^GREEN%^ are blocking out"+
	" most of the light, making this a cool little haven."+
	" Sitting up here in these branches it is unlikely that"+
	" someone would find you. This is a nice spot to just kick"+
	" back and relax. The branches are thick enough for you"+
	" to lay down on without having to worry about falling out"+
	" of the tree. The wind isn't blowing very hard, and it"+
   " would have to be some storm to move this majestic tree.\n"
	);
	set("night long",
	"%^GREEN%^This is an ancient %^BOLD%^%^WHITE%^silverleaf oak%^RESET%^%^GREEN%^, and you are"+
	" standing on its sturdy branches. The tree reaches far up"+
	" into the distance, but with the leaves blocking out the"+
	" %^BOLD%^%^WHITE%^moonlight%^RESET%^%^GREEN%^, you can't even see the top, there's just a"+
	" thick %^BOLD%^%^BLACK%^blackness%^RESET%^%^GREEN%^. What you can see of the tree is truly"+
	" magnificent, thick branches twist around to support the"+
	" leafy frame. The leaves appear even more %^BOLD%^%^WHITE%^silverish%^RESET%^%^GREEN%^ in the"+
	" moonlight, %^RESET%^glittering%^GREEN%^ as the wind blows gently against"+
	" them. You have an even greater sense of how incredibly"+
	" spelndid this oak is now, what with the thickness and"+
	" strength of the branches, it has most definitely"+
	" withstood centuries in this valley and shall likely stand"+
	" for centuries longer, well after you're dead and long"+	
	" forgotten.\n"
	);
	set_smell("default",
	"The smell of oak leaves is all around you."
	);
	set_listen("default",
	"The rustling of the leaves is soothing."
	);
	set_items( ([
	"branches" : "%^BOLD%^The branches are incredibly thick, they twist"+
	" up into the distance, building the framework for the"+
	" leaves and making it very easy to climb.",
	"leaves" : "%^BOLD%^These leaves have a silverish sheen to them"+
	" and they block the light from coming in, enclosing you"+
	" in this spot from the rest of the world. The wind blows"+
	" them slightly, causing them to rustle.",
	"ground" : "%^GREEN%^You can easily see the ground from here, it"+
	" isn't that far away. Someone down there would have to"+
	" be standing directly below you to see you in this tree.",
	"trunk" : "The trunk of the tree is very thick and gnarled,"+
	" it divides out into the branches that you're standing on.",
	]) );
	set_exits( ([
	"down" : ROOMS+"dryad6",
	]) );
}

void reset()
{
	::reset();
	if(!present("dryad")) {
		new(MONS+"oak_dryad")->move(TO);
	}
}
