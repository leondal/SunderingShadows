//path9.c - Path from Koenig to Tabor.  Updated by Circe 11/28/03
#include <std.h>
#include "../koenig.h"
inherit PATH;

void create()
{
	::create();
	set_exits(([
	"northwest" : VILSTREAM"path8",
	"east" : VILSTREAM"path10",
	]));
}
