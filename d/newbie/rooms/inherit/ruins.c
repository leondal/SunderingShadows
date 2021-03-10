//ruins.c - inherited room for ruins w/gnolls

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){
   ::create();
   set_property("no teleport",1);
}

void reset() {
	::reset();
   if( !present("gnoll") && !present("bat") && (query_night() == 1) && (random(10) < 3) ) {
	    switch(random(13)) {
			case 0..2:       
				new(MON"gnoll")->move(TO);
				break;
			case 3..4:       
				new(MON"gnoll")->move(TO);
				new(MON"bat")->move(TO);
				break;
			case 5..6:       
				new(MON"rat")->move(TO);
				new(MON"gnoll")->move(TO);
				break;
			case 7..8:
				new(MON"bat")->move(TO);
				new(MON"bat")->move(TO);
				new(MON"bat")->move(TO);
				break;
			case 9:
				new(MON"snake")->move(TO);
				new(MON"bat")->move(TO);
				new(MON"gnoll")->move(TO);
				break;				
			case 10:
				new(MON"bat")->move(TO);
				new(MON"bat")->move(TO);
				break;	
			case 11:
				new(MON"bat")->move(TO);
				break;	
			case 12:
				new(MON"bat")->move(TO);
				new(MON"gnoll")->move(TO);
				new(MON"gnoll")->move(TO);
				break;
		}
	}
	if( !present("rat") && !present("gnoll") && (query_night() == 0) && (random(10) < 3) ) {
	    switch(random(11)) {
			case 0..3:       
				new("/d/newbie/mon/gnoll")->move(TO);
				break;
			case 4..5:       
				new("/d/newbie/mon/rat")->move(TO);
				new("/d/newbie/mon/gnoll")->move(TO);
				break;
			case 6..7:       
				new("/d/newbie/mon/snake")->move(TO);
				break;
			case 8:
				new("/d/newbie/mon/gnoll")->move(TO);
				new("/d/newbie/mon/rat")->move(TO);
				new("/d/newbie/mon/snake")->move(TO);
				break;
			case 9:
				new("/d/newbie/mon/gnoll")->move(TO);
				new("/d/newbie/mon/snake")->move(TO);
				break;
			case 10:
				new("/d/newbie/mon/snake")->move(TO);
				new("/d/newbie/mon/rat")->move(TO);
				break;				
		}
	}
}
