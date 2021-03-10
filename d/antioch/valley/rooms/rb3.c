#include <std.h>
#include "../valley.h"
inherit RIVER1;

void create(){
	::create();
	set_long(
	"%^CYAN%^A %^BLUE%^river%^CYAN%^ slowly winds its way through the valley"+
	" and you are standing on the edge of the %^ORANGE%^sandy%^CYAN%^"+
	" bank. You can see the %^BOLD%^%^CYAN%^water%^RESET%^%^CYAN%^ rushing before you,"+
	" flowing from a %^BOLD%^%^BLUE%^lake%^RESET%^%^CYAN%^ and disappearing into the"+
	" woods. The water looks %^BOLD%^%^CYAN%^crystal%^RESET%^%^CYAN%^ clear and very"+
	" %^BOLD%^%^BLUE%^cold%^RESET%^%^CYAN%^. On the other side of the river you see"+
	" more %^BOLD%^%^GREEN%^grasslands%^RESET%^%^CYAN%^, with a %^GREEN%^moss%^CYAN%^"+
       " covered bridge connection the two shores.\n"
	);
	set("night long",
	"%^CYAN%^A %^BLUE%^river%^CYAN%^ winds its way through this valley,"+
	" occasionally crashing against the bank when it"+
	" makes a sharp turn. You can see the water"+
	" raging before you, spilling from the %^BOLD%^%^BLUE%^lake%^RESET%^%^CYAN%^ to"+
	" follow its own path into the woods. The %^BOLD%^water%^RESET%^%^CYAN%^"+
	" looks almost %^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^ at night and you get the"+
	" feeling that it's icy cold. The bank you're"+
	" standing on is slightly damp, the river must"+
	" have climbed up a bit higher earlier to wash"+
	" against the %^ORANGE%^sand%^CYAN%^. On the opposite bank you can"+
	" see more %^BOLD%^%^GREEN%^grasslands%^RESET%^%^CYAN%^, with a "+
        "%^GREEN%^moss%^CYAN%^ covered bridge connecting the two shores.\n"
	);
	set_exits( ([
	"west" : ROOMS+"rb2",
	"southwest" : ROOMS+"v61",
	"south" : ROOMS+"rb4",
	"southeast" : ROOMS+"rb5",
        "bridge" : "/d/antioch/vale/rooms/rbank1",
	]) );
}
