//path18.c - Path from Koenig to Tabor.  Updated by Circe 11/28/03
#include <std.h>
#include "../koenig.h"
inherit PATH;

void create()
{
	::create();
	set_short("A rocky path leading to a gate");
	set_long(
	"This is a %^ORANGE%^ro%^BOLD%^c%^RESET%^%^ORANGE%^ky p%^BOLD%^a%^RESET%^%^ORANGE%^th %^WHITE%^that winds slowly through the %^GREEN%^foothills %^WHITE%^of the mountains. The path has been mostly cleared of the larger rocks, but smaller stones make for rough traveling. The surrounding area is also ro%^BOLD%^%^BLACK%^ck%^RESET%^y, not many %^BOLD%^%^GREEN%^p%^RESET%^%^GREEN%^l%^BOLD%^ant%^RESET%^%^GREEN%^s %^WHITE%^seem to like the mountain climate. A cool %^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^ind %^WHITE%^seems to be constantly blowing, and you can hear it whistling through the %^BOLD%^peaks %^RESET%^far above.\n\nThe %^ORANGE%^p%^BOLD%^a%^RESET%^%^ORANGE%^th %^WHITE%^here climbs steadily downward, leading right to a %^YELLOW%^gate%^RESET%^. A %^BOLD%^%^CYAN%^small city %^RESET%^looms just to the west, with a %^MAGENTA%^lonely tow%^BOLD%^e%^RESET%^%^MAGENTA%^r %^WHITE%^rising to the north. \n"
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
