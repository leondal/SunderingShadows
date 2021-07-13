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
	"%^BOLD%^%^WHITE%^You are traveling along a %^RESET%^%^ORANGE%^ro%^BOLD%^c%^RESET%^%^ORANGE%^ky mou%^BOLD%^nt%^RESET%^%^ORANGE%^a%^BOLD%^i%^RESET%^%^ORANGE%^n p%^BOLD%^a%^RESET%^%^ORANGE%^th%^BOLD%^%^WHITE%^. It leads through the %^RESET%^%^GREEN%^foothills %^BOLD%^%^WHITE%^of the mountains, and the area isn't very inhabited.  A band of %^RESET%^%^ORANGE%^orcs %^BOLD%^%^WHITE%^and other creatures have made a home in some of the surrounding %^RESET%^%^ORANGE%^caves %^BOLD%^%^WHITE%^to the north, but they do not dare cross the %^CYAN%^s%^RESET%^%^CYAN%^t%^BOLD%^re%^RESET%^%^CYAN%^a%^BOLD%^m%^WHITE%^.  These surrounding foothills aren't very attractive to most people - the area is simply too %^RESET%^de%^BOLD%^%^BLACK%^s%^RESET%^o%^BOLD%^l%^BLACK%^a%^RESET%^t%^BOLD%^e %^RESET%^a%^BOLD%^n%^BLACK%^d %^WHITE%^r%^RESET%^o%^BOLD%^c%^BLACK%^k%^WHITE%^y.%^RESET%^\n"
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
