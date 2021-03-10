#include <std.h>
#include "../valley.h"
inherit PDRUID;

void create()
{
	::create();
	set_exits( ([
	"east" : ROOMS+"v43",
	"west" : ROOMS+"v41",
	"south" : ROOMS+"g84",
	"north" : ROOMS+"e2707",
	"northeast" : ROOMS+"v44",
	]) );
	set_invis_exits(({"north"}));
	set_short("%^CYAN%^A valley");
	set_long(
	"%^GREEN%^You are standing near the edge of a valley. The"+
	" %^BOLD%^%^BLACK%^Dark Forest%^RESET%^%^GREEN%^ stretches out to encompass the area,"+
	" but it doesn't seem quite as evil now, though"+
	" you wouldn't want to get lost in it. Thick%^BOLD%^ grass"+
	" %^RESET%^%^GREEN%^spreads out before you, stretching over the"+
	" entire valley. There is a sense of %^CYAN%^peace%^GREEN%^ of"+
	" through the area and you wonder if anyone"+
	" tends to this vale.\n"
	);
	set("night long",
	"%^GREEN%^You're standing near the edge of the valley. The"+
	" %^BOLD%^%^BLACK%^Dark Forest%^RESET%^%^GREEN%^ stretches out to enfold the vale"+
	" and it seems quite %^BLUE%^sinister%^GREEN%^ at night. You can"+
	" barely make out the trees on the edges, it just"+
	" seems to be a dark maw that swallows up any"+
	" light that dares to get near it. You can't"+
	" imagine trying to make your way through it"+
	" without a trail. The rest of the valley is"+
	" blanketed in thick %^BOLD%^grass%^RESET%^%^GREEN%^ that shines dimly with"+
	" %^BOLD%^%^WHITE%^moonlight%^RESET%^%^GREEN%^. There is a quiet"+
        " %^CYAN%^peace%^GREEN%^ here as you"+
	" look over the vale and you wonder if anyone"+
	" tends to this place.\n"
	);
	set_smell("default",
	"The scent of wildflowers drifts in the breeze."
	);
	set_listen("default",
	"The rush of a waterfall can barely be heard."
	);
	set_items( ([
	"valley" : "%^GREEN%^You're standing on the edge of it.",
	"waterfall" : "%^BOLD%^%^CYAN%^The waterfall pours down into a lake.",
	]) );
}
