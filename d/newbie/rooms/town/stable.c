#include <std.h>
#include "../../newbie.h"
inherit STABLE;

void create() {
	::create();
	set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
	set_short("Offestry Stables");
	set_long(
	"You are standing in the Offestry stables. There are rows of stalls on"+
	" your right and left, with horses in several of them. There is a large"+
	" center aisle that leads to a tethering post and water trough. The stable"+
	" doors are high, impossible for a horse to escape from. They are also"+
	" made of strong wood and appear to have withstood several beatings from"+
	" angry horses over time. Some horses appear restless, but they have all"+
	" been well cared for and fed. You may purchase a mount here for a"+
	" reasonable price.  A %^BOLD%^%^GREEN%^sign on the wall %^RESET%^lists"
	" what mounts are available with prices and"
	" includes the following warning:\n'%^YELLOW%^War horses are specially trained to"
 	" serve paladins only.  Horses require some degree of riding skill,"
	" so novice riders should begin with donkeys.  No refunds given if you"
	" cannot handle the animal you purchase.%^RESET%^'\n"
	);
	set_smell("default","The room smells strongly of horses.");
	set_listen("default","You can hear the animals stamping about in their stalls.");
	set_items(([
	"horses" : "There appear to be several fine horses in the stalls today."+
	" Some are stamping about restlessly, anxious to hit the road. Others"+
	" appear quite content to just munch on oats and hay all day long.",
	"stalls" : "The stalls are quite tall, and made of sturdy wood. They have"+
	" a top and bottom door, so that one can remain open during the day while"+
	" the horse still can't escape. The upper doors to the feistiest, most vicious"+
	" horses are closed so that they will not bite anyone passing by.",
	"floor" : "The floor is made of cobblestones, and littered with straw"+
	" from the horses. The floor of each stall, however, appears to be soft"+
	" dirt that has been covered by straw, to be easiest on the horses' hooves.",
	"tack" : "In the back of the room is tack for grooming your horses, which"+
	" is always a good idea.",
	]));
	set_exits(([
	"south" : MAINTOWN"tether",
    "north" : MAINTOWN"estreet2",
	]));
        set_animal( ({"horse", "war horse", "donkey"}),
	   ({"/d/shadow/mon/horse", "/d/shadow/room/city/cguild/paladin/war_horse",
		 "/d/shadow/mon/donkey" })
	);
	set_animal_price(({"horse", "war horse", "donkey"}),({75, 250, 25}));
	set_stalls(20);
	::fill_stalls();
}
