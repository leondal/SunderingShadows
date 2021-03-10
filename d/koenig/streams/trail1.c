//trail1.c - Connecting Koenig to Tabor.  Updated by Circe 11/28/03
#include <std.h>
#include "../koenig.h"
inherit TRAIL;

void create()
{
	::create();
	set_exits(([
	"east" : VILSTREAM"path3",
	"northwest" : VILSTREAM"trail2",
	]));
}
