//trail.c - inherit for trail from Koenig to road to Tabor.  Updated by Circe 11/28/03
#include <std.h>
inherit ROOM;

void create()
{
	::create();
      set_terrain(ROCKY);
      set_travel(DIRT_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("A dirt trail");
	set_long(
	"%^BOLD%^%^GREEN%^This is a %^ORANGE%^di%^RESET%^%^ORANGE%^r%^BOLD%^t %^RESET%^%^ORANGE%^p%^BOLD%^ath %^GREEN%^that winds its way through %^RESET%^%^GREEN%^the lower foothills %^BOLD%^of the mountains. It has been fairly well defined. The larger %^RESET%^sto%^BOLD%^ne%^RESET%^s %^BOLD%^%^GREEN%^have been removed completely, the smaller ones have been set on the sides to help define it more clearly. The dirt of the path is fine, as though it has gotten %^RESET%^%^GREEN%^much use %^BOLD%^in its day. Your footsteps stir up the %^BLACK%^d%^RESET%^us%^BOLD%^%^BLACK%^t %^GREEN%^as you move along the %^ORANGE%^tra%^RESET%^%^ORANGE%^i%^BOLD%^l%^GREEN%^. A fine %^RESET%^%^RED%^red %^BOLD%^%^GREEN%^film of dust has settled itself over your belongings already.%^RESET%^\n" 
	);
	set_smell("default","The dust from the trail fills your nose.");
	set_listen("default","The wind whispers along the trail.");
	set_items(([
	({"path","trail","dirt path","dirt trail"}) : "A well worn dirt path"+
	" has been carefully created by someone long ago. Large stones have been"+
	" moved off to the side of the path, the smaller ones have even been"+
	" cleared away. Simply walking along the path kicks up a layer of dust"+
	" that settles over you and your belongings.",
	({"dirt","dust","red dust","red dirt"}) : "%^BOLD%^%^RED%^The dust that"+
	" covers the trail and surrounding area is a red color that comes from"+
	" the surrounding mountains.",
	({"stones","large stones"}) : "Large stones have been placed along the"+
	" sides of the path. In certain places the boulders were too large to"+
	" be moved, and the trail simply curves around them.",
	"small stones" : "Smaller stones have been carefully moved off the trail"+
	" and placed along the edges to help carefully define it.",
	({"mountains","mountain"}) : "The mountain range rising to the south and "+
         "east separates this land from the Tsarven empire to the south.  Rising "+
         "far to the north are the Echoes Mountains, and these foothills form the "+
         "majority of the land in between the two ranges.",
	]));
}
