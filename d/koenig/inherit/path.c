//path.c - inherit for path from Koenig to Tabor.  Updated by Circe 11/28/03
#include <std.h>
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
	"This is a %^ORANGE%^ro%^BOLD%^c%^RESET%^%^ORANGE%^ky p%^BOLD%^a%^RESET%^%^ORANGE%^th %^WHITE%^that winds slowly through the %^GREEN%^foothills %^WHITE%^of the mountains. The path has been mostly cleared of the larger rocks, but smaller stones make for rough traveling. The surrounding area is also ro%^BOLD%^%^BLACK%^ck%^RESET%^y, not many %^BOLD%^%^GREEN%^p%^RESET%^%^GREEN%^l%^BOLD%^ant%^RESET%^%^GREEN%^s %^WHITE%^seem to like the mountain climate. A cool %^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^ind %^WHITE%^seems to be constantly blowing, and you can hear it whistling through the %^BOLD%^peaks %^RESET%^far above. The path here isn't very steep, and it stays relatively close to the s%^BOLD%^%^BLACK%^he%^RESET%^er %^BOLD%^%^BLACK%^m%^RESET%^o%^BOLD%^%^BLACK%^u%^RESET%^n%^BOLD%^%^BLACK%^t%^RESET%^a%^BOLD%^%^BLACK%^i%^RESET%^n cl%^BOLD%^%^BLACK%^if%^RESET%^f.\n"
	);
	set_search("default","There are a lot of rocks and dust on the trail, but"+
	   " not much else.");
	set_smell("default","The mountain air is crisp and cool.");
	set_listen("default","The wind whistles through the mountains.");
	set_items(([
	({"mountains","mountain"}) : "The mountain range rising to the south and "+
         "east separates this land from the Tsarven empire to the south.  Rising "+
         "far to the north are the Echoes Mountains, and these foothills form the "+
         "majority of the land in between the two ranges.",
	({"path","rocky path"}) : "This path has really just been picked clear"+
	   " of the larger rocks. It is still littered with pebbles and isn't very"+
	   " smooth. It looks like it may once have gotten a fair bit of use, but"+
	   " not for a while.",
	({"cliff","sheer cliff","cliff face","mountain cliff"}) : "To the east"+
	   " is the sheer cliff face of the mountains. It is tall and steep,"+
	   " not even the most expert climber could climb that. It reaches high"+
	   " into the air, disappearing far above the clouds.",
	]));
}
