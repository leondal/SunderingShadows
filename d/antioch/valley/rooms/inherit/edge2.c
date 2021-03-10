#include <std.h>
#include "../../valley.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(HEAVY_FOREST);
   set_travel(FRESH_BLAZE);
	set_property("indoors",0);
	set_property("light",1);
   set_property("no multi-charge",1);
   set_mcharge_message("The trees are far too close to maneuver for a long charge.");
   set_property("no peer",1);
   set_peer_message("The trees are too dark and thick to see anything.");
  set_short("%^GREEN%^Dark Forest%^RESET%^");
	set_long(
	"%^GREEN%^You are near the edge of the %^BOLD%^%^BLACK%^"+
        "Dark Forest%^RESET%^%^GREEN%^, but the"+
	" trees seem to close in around you, blocking your"+
	" view of the outside world. It is very %^BLUE%^dark%^GREEN%^ here and"+
	" you don't know what could be %^RED%^creeping%^GREEN%^ in the bushes."+
	" As you move through the forest you can't seem to"+
	" tell which way you've been walking. You have no"+
	" sense of direction beneath the %^BOLD%^%^BLACK%^darkness%^RESET%^%^GREEN%^ of the"+
	" trees and are quite lost. You hope you can find"+
	" your way out soon.\n"
	);
	set("night long",
	"%^GREEN%^You are on the edges of the %^BOLD%^%^BLACK%^"+
        "Dark Forest%^RESET%^%^GREEN%^. The"+
	" trees almost seemed to close in behind you as"+
	" you entered, blocking any view of the outside"+
	" world. The %^BLUE%^darkness%^GREEN%^ is oppressive here and you"+
	" can hear things %^RED%^creeping%^GREEN%^ in the bushes around"+
	" you. When you move through the forest you can't"+
	" even tell which way you've been walking. No"+
	" trail is left at all behind you. You can't"+
	" even tell which direction you're facing. The"+
	" trees are succesfully blocking out any light"+
	" that might be trying to get through. You hope"+
	" you can find your way out soon, who knows what"+
	" may be lurking in this %^BOLD%^%^BLACK%^evil%^RESET%^%^GREEN%^ wood.\n"
	);
	set_smell("default",
	"You can smell rotting fungus."
	);
	set_listen("default",
	"A rustling can be heard from the bushes around"+
	" you."
	);
	set_items( ([
	"trees" : "%^GREEN%^The trees crowd around you.",
	"bushes" : "%^GREEN%^The bushes seem to be rustling in"+
	" the distance, you can't tell what causes it.",
	"trail" : "%^ORANGE%^There doesn't seem to be one here.",
	"fungus" : "%^YELLOW%^Several types of fungus can be found"+
	" on the ground.",
	]) );
}

void init()
{
	::init();
	add_action("ride","ride");
}

int ride(string str)
{
	write("You can't ride a horse through this dense forest!");
	return 0;
}
