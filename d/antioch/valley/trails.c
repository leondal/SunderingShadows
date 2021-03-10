#include <std.h>
#include <daemons.h>
#include "valley.h"
inherit ROOM;

#define MON ({"ghost","ghoul","lich","wight","wraith","zombie","ghast"})
#define MON2 ({"skeleton","haunt","heucuva","hshade","wskeleton","mzombie"})

int i, j, g;
string str, type;

void create()
{
	::create();
   set_terrain(HEAVY_FOREST);
   set_travel(FOOT_PATH);
//updated travel and terrain to correct format ~Circe~ 4/8/13
}

void reset()
{
	j = random(7);
	g = random(6);
	str = MON[j];
	type = MON2[g];

	::reset();
	if(!present("monster")) {
		if(query_night() == 1) {
			switch(random(7)) {
				case 0:
					new(MONS+"MON")->move(TO);
					new(MONS+"MON")->move(TO);
					break;
				case 1:
					new(MONS+str)->move(TO);
					new(MONS+str)->move(TO);
					new(MONS+str)->move(TO);
					break;
				case 2:
					new(MONS+str)->move(TO);
					new(MONS+str)->move(TO);
					new(MONS+str)->move(TO);
					new(MONS+str)->move(TO);
					break;
				case 3:
					new(MONS+"lich")->move(TO);
					new(MONS+str)->move(TO);
					new(MONS+str)->move(TO);
					break;
				case 4:
					new(MONS+"zombie")->move(TO);
					new(MONS+str)->move(TO);
					new(MONS+str)->move(TO);
					new(MONS+str)->move(TO);
					break;
				case 5:
					new(MONS+"wskeleton")->move(TO);
					new(MONS+"wraith")->move(TO);
					new(MONS+"wraith")->move(TO);
					new(MONS+"wight")->move(TO);
					break;
				case 6:
					new(MONS+"ghoul")->move(TO);
					new(MONS+"ghast")->move(TO);
					new(MONS+"ghoul")->move(TO);
					new(MONS+"ghoul")->move(TO);
					new(MONS+"ghoul")->move(TO);
					break;
			}
		}

		else {
			switch(random(6)) {
				case 0:
					new(MONS+type)->move(TO);
					new(MONS+type)->move(TO);
					new(MONS+type)->move(TO);
					break;
				case 1:
					new(MONS+type)->move(TO);
					new(MONS+type)->move(TO);
					new(MONS+type)->move(TO);
					new(MONS+type)->move(TO);
					break;
				case 2:
					new(MONS+type)->move(TO);
					new(MONS+type)->move(TO);
					new(MONS+type)->move(TO);
					new(MONS+type)->move(TO);
					new(MONS+type)->move(TO);
					break;
				case 3:
					new(MONS+"hshade")->move(TO);
					new(MONS+type)->move(TO);
					new(MONS+type)->move(TO);
					break;
				case 4:
					new(MONS+"mzombie")->move(TO);
					new(MONS+"skeleton")->move(TO);
					new(MONS+"skeleton")->move(TO);
					new(MONS+"wskeleton")->move(TO);
					break;
				case 5:
					new(MONS+"wskeleton")->move(TO);
					new(MONS+"haunt")->move(TO);
					new(MONS+"heucuva")->move(TO);
					new(MONS+"skeleton")->move(TO);
					break;
			}
		}
	}
}
