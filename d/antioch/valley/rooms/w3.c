#include <std.h>
#include "../valley.h"
inherit WFLOWERS;

void create()
{
	::create();
	set_exits( ([
	"west" : ROOMS+"w2",
	"east" : ROOMS+"w4",
	"north" : ROOMS+"w5",
	"south" : ROOMS+"w1",
	]) );
}

void reset()
{
	::reset();
	if(!present("monster")) {
		if(query_night() == 1) {
			switch(random(9)) {
				case 0:
					new(MONS+"brownie")->move(TO);
					new(MONS+"brownie")->move(TO);
					new(MONS+"brownie")->move(TO);
					break;
				case 1:
					new(MONS+"pixie")->move(TO);
					new(MONS+"pixie")->move(TO);
					break;
				case 2:
					new(MONS+"atomie")->move(TO);
					new(MONS+"atomie")->move(TO);
					new(MONS+"atomie")->move(TO);
					break;
				case 3:
					new(MONS+"dryad")->move(TO);
					break;
				case 4:
					new(MONS+"satyr")->move(TO);
					break;
				case 5:
					new(MONS+"wstag")->move(TO);
					break;
				case 6:
					new(MONS+"sylph")->move(TO);
					new(MONS+"sylph")->move(TO);
					new(MONS+"sylph")->move(TO);
					break;
				case 7:
					new(MONS+"nymph")->move(TO);
					break;
				case 8:
					new(MONS+"pixie")->move(TO);
					new(MONS+"pixie")->move(TO);
					new(MONS+"pixie")->move(TO);
					new(MONS+"pixie")->move(TO);
					break;
			}
		}
		else {
			switch(random(9)) {
				case 0:
					new(MONS+"sprite")->move(TO);
					new(MONS+"sprite")->move(TO);
					new(MONS+"sprite")->move(TO);
					new(MONS+"sprite")->move(TO);
					break;
				case 1:
					new(MONS+"nymph")->move(TO);
					break;
				case 2:
					new(MONS+"dragonet")->move(TO);
					break;
				case 3:
					new(MONS+"wdog")->move(TO);
					new(MONS+"wdog")->move(TO);
					new(MONS+"wdog")->move(TO);
					break;
				case 4:
					new(MONS+"almiraj")->move(TO);
					break;
				case 5:
					new(MONS+"dryad")->move(TO);
					break;
				case 6:
					new(MONS+"satyr")->move(TO);
					break;
				case 7:
					new(MONS+"wstag")->move(TO);
					break;
				case 8:
					new(MONS+"sylph")->move(TO);
					new(MONS+"sylph")->move(TO);
					new(MONS+"sylph")->move(TO);
					new(MONS+"sylph")->move(TO);
					break;
			}
		}
	}
}
