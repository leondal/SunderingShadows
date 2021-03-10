// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("attaya_11");
    set_property("indoors",0);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("garden");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^GREEN%^Center of the City of Seneca%^RESET%^");

    set_long("%^RESET%^%^GREEN%^This garden has all the markings of a lush and enjoyable city park, with its %^CYAN%^ornate benches%^GREEN%^, thickly leafed %^ORANGE%^trees %^GREEN%^and lush %^BOLD%^grass%^RESET%^%"
	"^GREEN%^, and yet everything is insubstantial, you can see but not touch this heavenly paradise.  Designed with a focal point of a beautifully carved %^BOLD%^%^WHITE%^statue%^RESET%^%^GREEN%^, this pa"
	"rt of the park features fruitless %^ORANGE%^orange trees %^GREEN%^and a cobblestone walkway ringed with %^RED%^fl%^WHITE%^ow%^MAGENTA%^er%^WHITE%^be%^RED%^ds%^GREEN%^.%^RESET%^"
	);

    set_smell("default","
The clean scent of the ocean rises on the breeze.");
    set_listen("default","You can faintly hear the crashing of waves on the shore.");

    
set_items(([ 
	({ "flowers", "flower", "flower", "flower bed", "flowerbed", "bed" }) : "%^RESET%^%^ORANGE%^Most of the flowers in these beds have long gone to seed, but a few tiny %^MAGENTA%^%^BOLD%^pink%^RESET%^%^ORANGE%^ flowers here and there, speaking of the bed's former glory.%^RESET%^",
	({ "green grass", "grass" }) : "%^GREEN%^Soft looking grass grows across the lawn of the park.  Long and overgrown, it still beckons for you to rest and relax.  Offering to cradle you within its thick blades.%^RESET%^",
	({ "trees", "oranges", "orange trees", "tree" }) : "%^RESET%^%^ORANGE%^The orange trees have small trunks that reach high into the air, their flourishing boughs are empty of oranges, however, and you imagine it has been sometime since they produced fruit.%^RESET%^",
	({ "bench", "benches" }) : "%^RESET%^%^CYAN%^In each of the ordinal corners, a curved stone bench has been placed.  Each bench has smooth decorative edges and would comfortably hold two people, though the curve would make their knees touch, making it quite cozy indeed.%^RESET%^",
	"plaque" : "%^RESET%^%^ORANGE%^You dust and rub at the plaque trying to reveal what it says.  Someone has obliterated the name and much of what is written, though there are a few words you can make out: %^BOLD%^%^WHITE%^first war %^GREEN%^uncovered%^CYAN%^ enfeeblement %^RED%^nemesis %^RESET%^%^MAGENTA%^assassin%^RESET%^",
	"statue" : "%^BOLD%^%^WHITE%^This beautiful statue looks to have been carved by a master, though it has been severely defaced.  The woman depicted is slender, and the stone used to create her was supple and smooth.  One delicate arm is broken off, though you can imagine it extending outward, beckoning toward the horizon.  Her other arm curls around a pockmarked square that may have been a book at one time.  Her face is completely missing, hacked away by acid and chisel.  Though it is difficult to make out what she's wearing it appears skin tight and comely against her youthful body.  A plaque at her feet has been scratched and tarnished to the point it is unreadable, causing you to wonder who hated this being so much as to intentionally disfigure her image so.%^RESET%^",
	]));

    set_exits(([ 
		"southwest" : "/d/av_rooms/lurue/attaya_10",
	]));

}