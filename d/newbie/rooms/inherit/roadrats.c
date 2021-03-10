// inherit for rats & bats for roads near town

#include <std.h>
inherit ROOM;

object ob;

void create() {
   ::create();
   set_exits(([
   ]));
}

void reset() {
	::reset();
   if( !present("bat") && !present("rat") && (query_night() == 1) && (random(10) < 3) ) {
	    switch(random(13)) {
			case 0..2:       
				new("/d/newbie/mon/bat")->move(TO);
				break;
			case 3..4:       
				new("/d/newbie/mon/rat")->move(TO);
				break;
			case 5..6:       
				new("/d/newbie/mon/rat")->move(TO);
				new("/d/newbie/mon/bat")->move(TO);
				break;
			case 7..8:
				new("/d/newbie/mon/bat")->move(TO);
				new("/d/newbie/mon/bat")->move(TO);
				break;
			case 9:
				new("/d/newbie/mon/rat")->move(TO);
				new("/d/newbie/mon/bat")->move(TO);
				new("/d/newbie/mon/snake")->move(TO);
				break;				
			case 10:
				new("/d/newbie/mon/bat")->move(TO);
				new("/d/newbie/mon/snake")->move(TO);
				break;	
			case 11:
				new("/d/newbie/mon/rat")->move(TO);
				new("/d/newbie/mon/snake")->move(TO);
				break;	
			case 12:
			  	ob = new("/std/obj/coins");
				ob->set_money("gold", random(20)+2);
				ob->set_money("silver", random(50)+10);
				ob->set_money("copper", random(200)+50);
				ob->move(TO);
				break;
		}
	}
	if( !present("rat") && !present("bat") && (query_night() == 0) && (random(10) < 3) ) {
	    switch(random(11)) {
			case 0..3:       
				new("/d/newbie/mon/rat")->move(TO);
				break;
			case 4..5:       
				new("/d/newbie/mon/rat")->move(TO);
				new("/d/newbie/mon/rat")->move(TO);
				break;
			case 6..7:       
				new("/d/newbie/mon/snake")->move(TO);
				break;
			case 8:
				new("/d/newbie/mon/rat")->move(TO);
				new("/d/newbie/mon/rat")->move(TO);
				new("/d/newbie/mon/snake")->move(TO);
				break;
			case 9:
				ob = new("/std/obj/coins");
				ob->set_money("gold", random(10)+2);
				ob->set_money("silver", random(20)+5);
				ob->set_money("copper", random(100)+20);
				ob->move(TO);
			case 10:
				new("/d/newbie/mon/snake")->move(TO);
				new("/d/newbie/mon/rat")->move(TO);
				break;				
		}
	}
}

