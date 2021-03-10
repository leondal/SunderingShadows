#include <std.h>
#include "../../valley.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(SHORE);
   set_travel(GAME_TRACK);
	set_property("outdoors",3);
	set_property("light",2);
   set_short("%^BOLD%^%^BLUE%^River Bank%^RESET%^");
	set_long(
	"%^CYAN%^A %^BLUE%^river%^CYAN%^ slowly winds its way through the valley"+
	" and you are standing on the edge of the %^ORANGE%^sandy%^CYAN%^"+
	" bank. You can see the %^BOLD%^%^CYAN%^water%^RESET%^%^CYAN%^ rushing before you,"+
	" flowing from a %^BOLD%^%^BLUE%^lake%^RESET%^%^CYAN%^ and disappearing into the"+
	" woods. The water looks %^BOLD%^%^CYAN%^crystal%^RESET%^%^CYAN%^ clear and very"+
	" %^BOLD%^%^BLUE%^cold%^RESET%^%^CYAN%^. On the other side of the river you see"+
	" more %^BOLD%^%^GREEN%^grasslands%^RESET%^%^CYAN%^, but you don't see a bridge"+
	" around to cross over and you wouldn't want to"+
	" go swimming in the cold water.\n"
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
	" see more %^BOLD%^%^GREEN%^grasslands%^RESET%^%^CYAN%^, but you see no bridge to"+
	" cross over. Swimming through the cold water is"+
	" out of the question.\n"
	);
	set_smell("default",
	"You smell wet sand."
	);
	set_listen("default",
	"The rushing river is all you can hear."
	);
	set_items( ([
	"water" : "%^BOLD%^%^CYAN%^It looks very clear and cold.",
	"river" : "%^BOLD%^%^BLUE%^The river races past you.",
	"sand" : "%^ORANGE%^This is white, fine-grained sand.",
	"bank" : "%^ORANGE%^The bank here is made of tightly packed"+
	" sand that is still a bit damp from the river.",
	]) );
}
