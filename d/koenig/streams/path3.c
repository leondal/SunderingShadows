//path3.c - Path from Koenig to Tabor.  Updated by Circe 11/28/03
#include <std.h>
#include "../koenig.h"
inherit ROOM;

void create()
{
	::create();
      set_terrain(ROCKY);
      set_travel(DIRT_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("A rocky path");
	set_long(
	"You have come to a fork in the road. The rocky path continues from the"+
	" north and leads to the southeast. A trail that appears to be a bit"+
	" better cleared of rocks leads away to the southwest. You can see"+
	" mountains rising in the distance to the southeast, looming high into the"+
	" air.\n"
	);
	set_smell("default","The mountain air is crisp and cool.");
	set_listen("default","You can hear a stream in the northern distance.");
	set_items(([
	({"path","rocky path"}) : "A rocky path runs down from the north to the"+
   	" southeast.",
	({"mountains","mountain"}) : "The mountain range rising to the south and "+
         "east separates this land from the Tsarven empire to the south.  Rising "+
         "far to the north are the Echoes Mountains, and these foothills form the "+
         "majority of the land in between the two ranges.",
	"trail" : "A cleared and worn dirt trail splits off of the rocky path,"+
	" leading to the west.",
	]));
	set_exits(([
	"north" : VILSTREAM"path2",
	"west" : VILSTREAM"trail1",
	"southeast" : VILSTREAM"path4",
	]));
}
