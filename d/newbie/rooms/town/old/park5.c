#include <std.h>
#include "../../newbie.h"
inherit INH"townmove.c";

void create()
{
	::create();
	set_property("light",2);
	set_terrain(GARDEN);
	set_travel(FOOT_PATH);
	set_short("A bridge in the park");
	set_long(
	"You are walking over a tiny stone bridge that has been constructed across a pond"+
	" in the center of the park. There really was not a need for the bridge, but it"+
	" has ornately worked railings in the shapes of flowers and butterflies, and is"+
	" quite pretty. You can see the clear pond below you, which even appears to have a"+
	" few rather large fish in it. There are a couple water lillies and lilly pads in"+
	" the center of the pond, with a frog or two hopping about. On the edges of the"+
	" pond are white lillies and a couple of blue bells."
	);
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly and lights your way.");
	set_smell("default","There is a faint scent of roses in the air.");
	set_listen("default","You can hear the water of the pond rippling lightly.");
	set_items(([
	"lilly pads" : "%^BOLD%^%^GREEN%^There are a couple of lilly pads down in the pond."+
	" The frogs seem to be especially fond of them, hopping from one pad to another and"+
	" occassionally falling into the water.",
	"water lillies" : "%^BOLD%^A couple of large water lillies can be seen in the pond."+
	" The white flowers rise up out of the water with delicate %^YELLOW%^yellow%^WHITE%^"+
	" centers.",
	"lillies" : "%^BOLD%^Some white lillies have been planted along the edges of the"+
	" pond. They help to give the place a more enclosed atmosphere, and they brighten"+
	" the mood as well.",
	"blue bells" : "%^BOLD%^%^BLUE%^Several blue bells help to line the pond. They are"+
	" almost like small willow trees in their appearance, with drooping leaves that"+
	" sway in the breeze. They have strands of pretty blue flowers that hang down to"+
	" flutter in the wind.",
	"pond" : "%^BOLD%^%^CYAN%^Below you are the clear waters of a cool pond. It has"+
	" a couple of lilly pads and water lillies in it, as well as some rather large fish"+
	" swimming slowly about.",
	"bridge" : "The bridge is made of gray slate bricks that have been placed over the"+
	" concrete which holds the bridge together. The railings are made of wrought iron"+
	" and depict many flowers and butterflies across its length. It seems quite sturdy.",
	"frogs" : "%^GREEN%^A few tiny frogs are hopping about on the lilly pads in the"+
	" pond, occassionally causing the water to ripple when the jump in.",
	"fish" : "There are several rather large fish, probably fresh water bass, swimming"+
	" around in the pond down there.",
	]));
	set_exits(([
	"east" : MAINTOWN"park2",
	"west" : MAINTOWN"park8",
	]));
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
