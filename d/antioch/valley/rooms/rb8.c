#include <std.h>
#include "../valley.h"
inherit RIVER;

void create()
{
	::create();
   set_exits( ([
	"west" : ROOMS+"rb7",
	"southeast" : ROOMS+"rb10",
	"south" : ROOMS+"rb9",
	]) );
}
