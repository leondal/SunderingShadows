#include <std.h>
inherit ROOM;

void create()
{
	::create();
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
	set_property("indoors",0);
	set_property("light",2);
	set_short("%^BOLD%^%^GREEN%^The Garden");
	set_long(
	"A huge bee hive is hanging from the branch of a maple tree. The bees"+
	" are buzzing about rather busily, bringing pollen to the hive and working"+
	" to create honey. The ground around the maple tree is covered by a large"+
	" patch of clovers. Several %^BOLD%^white blossoms%^RESET%^ can be seen"+
	" peeking up through the darker leaves of the clover. The bees don't"+
	" have very far to go to collect pollen. If they should want a little"+
	" variety, on the other side of the path there are patches of a variety"+
	" of flowers. There are daisies, tulips, pansies, snap dragons, posies,"+
	" violets, daffodils, marigolds, and many other flowers. Bees must lead"+
	" a relatively peaceful life."
	);
	set_listen("default","The bees are buzzing merrily.");
	set_smell("default","The sweet scent of honey fills your nostrils.");
	set_smell("flowers","The flowers smell simply divine.");
	set_smell("blossom","The blossoms have a light but sweet fragarance.");
	set_items(([
	"flowers" : "A plethora of flowers covers the ground across from the"+
	" maple tree. The majority are different types of wildflowers, but"+
	" you also recognize daisies, tulips, pansies, snap dragons, posies,"+
	" violets, daffodils, and marigolds. The bees have a large menu from"+
	" which to choose here.",
	({"blossoms","white blossoms"}) : "%^BOLD%^White clover blossoms peek"+
	" up through the darker leaves of the large clover patch.",
	({"clover","clover patch"}) : "%^GREEN%^A vast patch of dark green covers"+
	" the ground around the maple tree. The clover leaves are heart-shaped"+
	" and three of them join together on each stem. It looks like a few"+
	" little bunnies may have been in here and nibbled on the patch somewhat.",
	"bee hive" : "A large bee hive is hanging from the branch of a maple tree"+
	" that's on the east side of the path. Bees are busily swarming around it"+
	" and collecting pollen for their queen.",
	({"tree","maple tree"}) : "A maple tree is on the east side of the path."+
	" A large bee hive is attached to one of its lower branches. There is"+
	" a little hole that has been corked in the trunk of the tree that maple"+
	" sap can be drained from. Draining a little sap won't hurt the tree,"+
	" but whoever does it should be careful.",
	"bees" : "%^YELLOW%^Hundreds of bees are busily buzzing around their hive,"+
	" collecting pollen for their queen.",
	]));
	set_exits(([
	"southwest" : "/d/guilds/kindred/rooms/atree",
        "northwest" : "/d/guilds/kindred/rooms/pond",
        "east" : "/d/player_houses/drille/rooms/path1",
        ]));
}
