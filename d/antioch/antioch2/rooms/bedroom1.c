#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_property("no sticks",1);
	set_short("A little bedroom");
	set_long(
	"The bedroom is done in a %^BOLD%^%^CYAN%^cornflower blue%^RESET%^ color"+
	" with %^BOLD%^white%^RESET%^ trim. The bed itself is tucked into"+
	" the left hand corner with a little nightstand next to it. There"+
	" is a window on the far wall that looks out onto the back yard."+
	" %^BOLD%^White%^RESET%^ curtains with daisies on them frame the"+
	" window. On the right hand side of the room is a large closet. An"+
	" oak dresser rests along the north wall. A %^BOLD%^%^BLUE%^sapphire%^RESET%^"+
	" carpet covers the floor. This room is small, but homey."
	);
	set_smell("default","The room is scented with lilacs.");
	set_listen("default","The house is quiet.");
	set_items(([
	({"floor","carpet","sapphire carpet"}) : "%^BOLD%^%^BLUE%^A thick"+
	" sapphire carpet covers the floor here. It looks a tad worn, but"+
	" still much better than the cold floor.",
	"ceiling" : "%^BOLD%^%^CYAN%^Even the ceiling has been painted"+
	" a pretty cornflower blue.",
	({"wall","walls"}) : "The walls are painted %^BOLD%^%^CYAN%^cornflower"+
	" blue%^RESET%^ with %^BOLD%^white%^RESET%^ trimmings.",
	"bed" : "There is a large four poster bed tucked into the left"+
	" hand corner of the room. The woolen bed spread matches the"+
	" rest of the room perfectly. The bed has been carefully made by"+
	" someone.",
	"closet" : "A long oak closet takes up the right hand side of the"+
	" room. A good sized ward robe could be hung within it.",
	({"dresser","oak dresser"}) : "Against the north wall is a large"+
	" oak dresser. Acorns and oak leaves are artistically engraved"+
	" onto the drawers. On top of the dresser an incense stick burns"+
	" in its holder, giving off a lovely scent of lilacs.",
	"window" : "There is a window on the south side of the room, it"+
	" over looks the large back yard.",
	({"curtains","white curtains","daisy curtains"}) : "%^BOLD%^White"+
	" curtains with a pretty %^YELLOW%^daisy%^WHITE%^ pattern on them"+
	" frame the little window.",
	"nightstand" : "An oak nightstand is next to the bed. It matches"+
	" the rest of the furniture in the room and is useful for setting"+
	" things down on as you go to bed.",
	"bed spread" : "%^BOLD%^%^CYAN%^A heavy woolen bed spread is"+
	" laid out across the bed. It is cornflower blue, matching the"+
	" rest of the room.",
	({"incense","incense stick"}) : "A stick of lilac incense burns"+
	" in an incense holder on top of the dresser. The scent it gives"+
	" off fills the room.",
	"incense holder" : "A pewter incense holder is situated on top"+
	" of the dresser. It is rather plain and it holds a burning stick"+
	" of lilac incense.",
	]));
	set_exits(([
	"house" : ROOMS+"house2",
	]));
}
