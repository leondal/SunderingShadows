#include <std.h>
#include <daemons.h>
#include "valley.h"
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
	" on the ground."
	]) );
// removed a comma after the last item to see if it will fix illegal index on items::id bug  *Styx* 7/18/05
	set_search("default",(:TO,"search_here":));
	set_search("here",(:TO,"search_here":));
	set_search("forest",(:TO,"search_here":));
	set_search("exits",(:TO,"search_here":));
	set_property("distant_follow",1);
//This property will allow followers and fodder to stay with the leader ~Circe~ 4/12/13
}

void init()
{
	::init();
	add_action("ride","ride");
	add_action("observe_em","observe");
}

int search_here(string str){
	int skill = TP->query_skill("survival");
	if(skill < 10 && !avatarp(TP)){
         tell_object(TP,"%^BOLD%^You do not have the survival skills "
            "necessary to find the exits through this forest with any "
		"accuracy. Best just try to press ahead.");
	   return 1;
	}
	tell_object(TP,"%^GREEN%^Using your innate knowledge of the forest, you "
		"find the following ways through the dense brush: "+ETP->query_exits_string(1)+"%^RESET%^");
	if(!TP->query_invis()){
		tell_room(TO,"%^GREEN%^"+TPQCN+" studies the brush around you intensely.%^RESET%^",TP);
	}
	return 1;
}

int ride(string str)
{
	write("You can't ride a horse through this dense forest!");
   return 1;
}

void reset()
{
	::reset();
	if(!present("monster")) {
		if(query_night() == 1) {
			switch(random(9)) {
				case 0:
					new(MONS+"gfeyr")->move(TO);
					break;
				case 1:
					new(MONS+"jackalw")->move(TO);
					new(MONS+"jackalw")->move(TO);
					break;
				case 2:
					new(MONS+"neogi")->move(TO);
					new(MONS+"neogi")->move(TO);
					new(MONS+"neogi")->move(TO);
					break;
				case 3:
					new(MONS+"owlbear")->move(TO);
					new(MONS+"owlbear")->move(TO);
					break;
				case 4:
					new(MONS+"wolfwere")->move(TO);
					new(MONS+"wolfwere")->move(TO);
					new(MONS+"wolfwere")->move(TO);
					new(MONS+"wolfwere")->move(TO);
					break;
				case 5:
					new(MONS+"direwolf")->move(TO);
					new(MONS+"direwolf")->move(TO);
					new(MONS+"direwolf")->move(TO);
					new(MONS+"direwolf")->move(TO);
					break;
				case 6:
					new(MONS+"gbear")->move(TO);
					new(MONS+"gbear")->move(TO);
					break;
				case 7:
					new(MONS+"whipweed")->move(TO);
					break;
				case 8:
					new(MONS+"bloodthorn")->move(TO);
					break;
			}
		}
		else {
			switch(random(9)) {
				case 0:
					new(MONS+"sbeetle")->move(TO);
					break;
				case 1:
					new(MONS+"mcenti")->move(TO);
					break;
				case 2:
					new(MONS+"tworm")->move(TO);
					new(MONS+"tworm")->move(TO);
					break;
				case 3:
					new(MONS+"gorgon")->move(TO);
					new(MONS+"gorgon")->move(TO);
					break;
				case 4:
					new(MONS+"kirre")->move(TO);
					break;
				case 5:
					new(MONS+"wserpent")->move(TO);
					new(MONS+"wserpent")->move(TO);
					break;
				case 6:
					new(MONS+"gbear")->move(TO);
					new(MONS+"gbear")->move(TO);
					new(MONS+"gbear")->move(TO);
					break;
				case 7:
					new(MONS+"whipweed")->move(TO);
					break;
				case 8:
					new(MONS+"bloodthorn")->move(TO);
					break;
			}
		}
	}
}
