#include <std.h>
#include <daemons.h>
#include "valley.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(SHORE);
   set_travel(RUTTED_TRACK);
}

void reset()
{
	::reset();
	if(!present("monster")) {
		if(query_night() == 1) {
			switch(random(6)) {
				case 0:
					new(MONS+"sirine")->move(TO);
					break;
				case 1:
					new(MONS+"sandling")->move(TO);
					new(MONS+"sandling")->move(TO);
					new(MONS+"sandling")->move(TO);
					break;
				case 2:
					new(MONS+"sandman")->move(TO);
					break;
				case 3:
					new(MONS+"sirine")->move(TO);
					new(MONS+"sirine")->move(TO);
					break;
				case 4:
					new(MONS+"sandling")->move(TO);
					new(MONS+"sandling")->move(TO);
					new(MONS+"sandling")->move(TO);
					break;
				case 5:
					new(MONS+"sandman")->move(TO);
					new(MONS+"sandman")->move(TO);
					break;
			}
		}
		else {
			switch(random(7)) {
				case 0:
					new(MONS+"sea_sprite")->move(TO);
					new(MONS+"sea_sprite")->move(TO);
					break;
				case 1:
					new(MONS+"nixie")->move(TO);
					new(MONS+"nixie")->move(TO);
					new(MONS+"nixie")->move(TO);
					break;
				case 2:
					new(MONS+"swanmay")->move(TO);
					break;
				case 3:
					new(MONS+"sirine")->move(TO);
					break;
				case 4:
					new(MONS+"sandling")->move(TO);
					new(MONS+"sandling")->move(TO);
					new(MONS+"sandling")->move(TO);
					break;
				case 5:
					new(MONS+"sandman")->move(TO);
					break;
				case 6:
					new(MONS+"sea_sprite")->move(TO);
					new(MONS+"sea_sprite")->move(TO);
					new(MONS+"sea_sprite")->move(TO);
					break;
			}
		}
	}
}
