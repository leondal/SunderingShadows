//path1.c - Path from Koenig to Tabor.  Updated by Circe 11/28/03
#include <std.h>
#include "../koenig.h"
inherit ROOM;

void create()
{
	::create();
      set_terrain(SHORE);
      set_travel(DIRT_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("A rocky path");
	set_long(
	   "%^CYAN%^This is a %^WHITE%^r%^ORANGE%^o%^WHITE%^ck%^ORANGE%^y %^WHITE%^pa%^ORANGE%^t%^WHITE%^h %^CYAN%^that comes to a stop in front of the %^BOLD%^stream%^RESET%^%^CYAN%^. There is a %^BOLD%^fo%^RESET%^%^CYAN%^r%^BOLD%^d %^RESET%^%^CYAN%^in the middle of the %^BOLD%^w%^RESET%^%^CYAN%^a%^BOLD%^ter %^RESET%^%^CYAN%^to the northwest, it looks like the stream is %^WHITE%^sh%^BOLD%^allo%^RESET%^w %^CYAN%^enough here to make it across to the other bank. The %^WHITE%^pa%^ORANGE%^t%^WHITE%^h %^CYAN%^continues on to the south.%^WHITE%^\n"
	);
	set_smell("default","You smell the fresh stream water.");
	set_listen("default","You hear the sounds of rushing water.");
	set_items(([
	   "stream" : "%^BOLD%^%^BLUE%^A rapidly flowing stream runs to the"+
	      " northwest. It looks like there's a ford in the center of it here and"+
	      " it appears shallow enough to get across to the other bank.",
	   ({"path","rocky path"}) : "A rocky path comes to a stop in front of the"+
	      " stream. It continues on to the south.",
	]));
	set_exits(([
	"northwest" : VILSTREAM"stream14",
	"south" : VILSTREAM"path2",
	"southwest" : VILSTREAM"stream15",
	]));
}
