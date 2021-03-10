//trail3.c - Connecting Koenig to Tabor.  Updated by Circe 11/28/03
#include <std.h>
#include "../koenig.h"
inherit TRAIL;

void create()
{
	::create();
	set_exits(([
	"east" : VILSTREAM"trail2",
	"southwest" : VILSTREAM"trail4",
	]));
}
