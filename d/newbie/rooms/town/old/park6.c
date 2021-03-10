#include <std.h>
#include "../../newbie.h"
inherit INH"townmove.c";

void create()
{
	::create();
	set_property("light",2);
	set_terrain(GARDEN);
	set_travel(FOOT_PATH);
	set_short("A beautiful park");
	set_long(
	"This section of the park dead-ends into a haven of hedges and taller flowers."+
	" Bougainvillea grows in carefully crafted arches in the back. In front of it are"+
        " oleander bushes, tall verbena, and columbine. Some dragon's head is growing in the"+
	" back, and hibiscus plants are scattered about the area. Borages and blue woodruffs"+
	" have been planted in two rows in a half-circle around the area. There is a large"+
	" section of cleared grass in the very center, and you realize this place is probably"+
	" used for picnics. The taller hedges provide privacy from the rest of the park and"+
	" shelter you from whatever winds might be blowing. This is a quiet, peaceful little"+
	" section."
	);
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly and lights your way.");
	set_smell("default","The dragon's head flowers smell deliciously sweet.");
	set_listen("default","You can hear birds chirping in the park.");
	set_items(([
	"grass" : "%^GREEN%^%^BOLD%^The grass beneath your feet is lush and green, it is"+
	" almost like a carpet it is so thick and well cared for. In the very center of"+
	" this haven is a large area of cleared grass that looks like it is often used"+
	" for picnics.",
	"blue woodruffs" : "%^BOLD%^%^CYAN%^These little flowers are a pretty cornflower"+
	" blue. They have five delicate petals that are in a star-shaped pattern and are"+
	" easily tossed about by the slightest breeze. Their leaves are narrow and are"+
	" light green, complimenting the dainty petals perfectly.",
	"borages" : "%^BOLD%^%^CYAN%^These are sky-blue, star-shaped flowers that grow in"+
	" clusters. They are quite tiny, but it is believed that they have the power to"+
	" gladden one's heart.",
	({"verbena","tall verbena"}) : "%^BOLD%^These larger plants are covered in"+
	" clusters of %^MAGENTA%^light pink%^WHITE%^ lilac shaped flowers. %^RESET%^%^GREEN%^Dark green leaves%^BOLD%^%^MAGENTA%^"+
	" contrast nicely with the pretty blooms.",
	"dragon's head" : "%^BOLD%^%^BLUE%^These flowers are a deep lavender-blue color with"+
	" spikes that rise above their leaves, like the spines on a dragon's head. They are"+
	" growing in a far corner of the garden, but they give off a wonderful fragarance.",
        "hibiscus" : "A hibiscus plant has been positioned at the end of each oleander hedge."+
	" There are several colors, you can see yellow, red, pink, white, and orange ones."+
        " They all have very large flowers on them and stand out next to the oleander.",
	"bougainvillea" : "Tall arches of bougainvillea have been carefully crafted at the"+
	" back of the garden. There is an %^ORANGE%^orange%^RESET%^ a %^BOLD%^%^MAGENTA%^pink%^RESET%^"+
	" a %^BOLD%^%^RED%^bright red%^RESET%^ and a %^MAGENTA%^dark purple%^RESET%^ arch."+
	" You can't imagine the time and dedication to get them to grow in such a manner,"+
	" there must be a hidden trellis or metal framework in the center of each arch that"+
	" you simply can't see.",
        "oleander" : "%^BOLD%^White and %^MAGENTA%^pink%^WHITE%^ oleander hedges are kept"+
	" trimmed in front of the bougainvillea arches. There are several separate hedges"+
	" planted in a semi-circle about the area, alternating %^MAGENTA%^pink%^WHITE%^ and"+
	" white. At the end of each hedge a hibiscus plant of varying colors has been planted.",
	]));
	set_exits(([
	"west" : MAINTOWN"park7",
	]));
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
