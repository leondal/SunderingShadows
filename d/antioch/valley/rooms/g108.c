#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_long(::query_long()+"%^GREEN%^There is a large tree to the south.  A path "+
      "lined with low sandstone walls leads to a small "+
      "building here."
	);
	set("night long",query("night long")+"%^GREEN%^There is a large tree to the south.  A path "+
      "lined with low sandstone walls leads to a small "+
      "building here.\n"
	);
      add_item("path","A path through the grass leads to "+
         "an elegant sandstone building.  The path has been "+
         "laid with irregular stepping stones.  The walls of the "+
         "path are low and rise steadily as they approach "+
         "the building, finally meeting with the roof.");
      add_item("building","A simple sandstone building "+
         "surrounded by scattered leafy trees.  The building "+
         "looks open and inviting.");
	set_exits( ([
	"south" : ROOMS+"dryad3",
	"north" : ROOMS+"g110",
	"west" : ROOMS+"g107",
	"east" : ROOMS+"m21",
      "shrine" : ROOMS+"selune_shrine"
	]) );
}