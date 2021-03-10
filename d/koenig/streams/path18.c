//path18.c - Path from Koenig to Tabor.  Updated by Circe 11/28/03
#include <std.h>
#include "../koenig.h"
inherit PATH;

void create()
{
	::create();
	set_short("A rocky path leading to a gate");
	set_long(
	"This is a rocky path that winds slowly through the foothills of the"+
	" mountains. The path has been mostly cleared of the larger rocks,"+
	" but smaller stones make for rough traveling. The surrounding area is"+
	" also rocky, not many plants seem to like the mountain climate. A cool"+
	" wind seems to be constantly blowing, and you can hear it whistling through"+
	" the peaks far above. The path here climbs steadily downward, leading right "+
      "to a gate.  A small city looms just to the west, with a lonely tower rising "+
      "to the north.\n"
	);
      add_item("tower","The tower looms high above you, reaching towards the "+
         "dark clouds that loom over it.  The tower is made out of fine white "+
         "marble blocks, and shimmers with ancient energy.");
      add_item("gate","A narrow gate opens into a wall around the town to the northwest.  "+
         "The gate stands open, but it seems seldom used, much like the path itself.");
	set_exits(([
	"east" : VILSTREAM"path17",
	"northwest" : "/d/darkwood/tabor/room/gwy1",
	]));
}
