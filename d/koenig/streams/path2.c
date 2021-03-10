//path2.c - Path from Koenig to Tabor.  Updated by Circe 11/28/03
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
	"You are traveling along a rocky mountain path. It leads through the"+
	" foothills of the mountains, and the area isn't very inhabited.  A band "+
      "of orcs and other creatures have made a home in some of the surrounding "+
      "caves to the north, but they do not dare cross the stream.  These"+
	" surrounding foothills aren't very attractive to most people - the area"+
	" is simply too desolate and rocky.\n"
 	);
	set_smell("default","The mountain air is crisp and cool.");
	set_listen("default","A stream rushes by to the north.");
	set_items(([
	({"mountains","mountain"}) : "The mountain range rising to the south and "+
         "east separates this land from the Tsarven empire to the south.  Rising "+
         "far to the north are the Echoes Mountains, and these foothills form the "+
         "majority of the land in between the two ranges.",
	({"path","rocky path"}) : "This path has really just been picked clear"+
	   " of the larger rocks. It is still littered with pebbles and isn't very"+
	   " smooth. It looks like it may once have gotten a fair bit of use, but"+
	   " not for a while.",
	]));
	set_exits(([
	"north" : VILSTREAM"path1",
	"south" : VILSTREAM"path3",
	]));
}
