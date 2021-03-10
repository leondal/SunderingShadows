// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit WATER;

void create()
{
    ::create();
    set_name("seawreck_c3");
    set_property("indoors",1);
    set_property("light",-2);
    set_property("no teleport",1);
    set_terrain("ruins");
    set_travel("decayed floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^BLUE%^An underwater balcony%^RESET%^");

    set_long("%^RESET%^%^CYAN%^The open water stretches outward from this ruined balcony.  Long since collapsed under the weight and pressure of the %^ORANGE%^coral%^CYAN%^, what remains is but a few %^BOLD%^%^BLAC"
	"K%^stones %^RESET%^%^CYAN%^close to the structure's edge.  Balanced precariously along the small portion of remaining balcony, the %^ORANGE%^wooden masthead %^CYAN%^of a ship peers longingly at the do"
	"orway.  The single remaining arm reaching toward the entry while the bowspirt's netting twists away from her shoulders like braids of %^RESET%^webbed hair%^CYAN%^.  This netting extends over the only "
	"egress and prevents swimming further out into the water. %^RESET%^"
	);

    set_smell("default","
There is nothing to smell here.");
    set_listen("default","The bubbles escape from your lip and nose making a constant buzz against your ear.");

    set_search("line","%^BOLD%^%^WHITE%^You search about and discover a latch which causes the shell to open and reveal a small singing lobster!  %^RED%^Under the sea.  Under the sea.  Darling it's better, down where it's wetter.  Under the sea!%^WHITE%^   Well, you are under the sea after all!%^RESET%^");
    
set_items(([ 
	({ "net", "netting", "web", "hair" }) : "%^BOLD%^%^WHITE%^What appears to have been fine silk netting now lays encircling the balcony and is part of the reason why the masthead hasn't fallen away.  Like an extension of her white hair, the netting almost blends into the coral ledges where it has snagged.%^RESET%^",
	({ "coral", "stones" }) : "%^BOLD%^%^BLACK%^Only a small portion of the balcony remains intact after being struck by part of a large ship. Coral and stone are shorn away where the remainder of the ship struck and then brought the balcony down. Only a small portion of the bowspirit remains, that of the masthead.%^RESET%^",
	"egress" : "%^GREEN%^Beyond the netting you can see a kelp forest extending out into the dark waters.  The long strands waving back and forth with the current that flows endlessly through the ocean.  Parts of the ship can be seen hidden deep within it, but there's no way to reach it from here.%^RESET%^",
	"masthead" : "%^RESET%^%^ORANGE%^The masthead is a beautiful carving of a woman's upper torso, blending perfectly into what little of the ship's wood remains.  Her arms were once outstretched, though one has broken away and left the other to support the majority of the two hands and the clam shaped item they once held outward.  Painted, she appears lovely with soft skin and emerald green eyes.  White locks curl around her shoulders and flow back into the ship's wood, helping to disguise the joints.%^RESET%^",
	"clam" : "%^BOLD%^%^WHITE%^You peer closely at the clam shell held in the masthead's outstretched arms and notice that there is a thin %^CYAN%^line %^RESET%^that might mean it can be opened.  Perhaps if you searched around it you could find a way to open it.%^RESET%^",
	]));

    set_exits(([ 
		"southwest" : "/d/av_rooms/lurue/seawreck_c2",
	]));

}