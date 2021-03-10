//path12.c - Path from Koenig to Tabor.  Updated by Circe 11/28/03
#include <std.h>
#include "../koenig.h"
inherit PATH;

void create()
{
	::create();
	set_exits(([
	"north" : VILSTREAM"path11",
	"southwest" : VILSTREAM"path13",
	]));
}
