#include <std.h>
#include "../../valley.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(GRASSLANDS);
   set_travel(GAME_TRACK);
	set_property("outdoors",3);
	set_property("light",2);
   set_short("%^CYAN%^A valley%^RESET%^");
	set_long(
	"%^GREEN%^You are at the northern edge of a valley. Now"+
	" you can see the %^BOLD%^%^CYAN%^waterfall%^RESET%^%^GREEN%^ that before you could"+
	" only hear. The %^BOLD%^%^CYAN%^waterfall%^RESET%^%^GREEN%^ is crashing into a"+
	" large %^BOLD%^%^BLUE%^lake%^RESET%^%^GREEN%^ which empties into a %^BLUE%^river%^GREEN%^. The"+
	" river winds its way down to the eastern end"+
	" of the valley and disappears into the %^BOLD%^woods%^RESET%^%^GREEN%^."+
	" Across the %^BLUE%^river%^GREEN%^ you can see more %^BOLD%^grasslands%^RESET%^%^GREEN%^,"+
	" but you see no way of getting across.\n"
	);
	set("night long",
	"%^GREEN%^You're standing inbetween %^BOLD%^grasslands%^RESET%^%^GREEN%^ and a"+
	" %^ORANGE%^sandy%^GREEN%^ shore at the northern edge of the valley."+
	" There is a large %^BOLD%^%^BLUE%^lake%^RESET%^%^GREEN%^ and a %^BOLD%^%^CYAN%^waterfall"+
        " %^RESET%^%^GREEN%^crashes"+
	" into it. In the %^BOLD%^%^WHITE%^moonlight%^RESET%^%^GREEN%^"+
        " the %^BLUE%^river%^GREEN%^ looks very"+
	" %^BOLD%^%^BLACK%^dark%^RESET%^%^GREEN%^ and the lake seems to perfectly reflect"+
	" the world, giving it a %^BOLD%^%^WHITE%^silver%^RESET%^%^GREEN%^ sheen. You can"+
	" see that the trees surround the rest of the"+
	" vale. The river that courses away from the lake"+
	" disappears into the %^BOLD%^%^BLACK%^dark woods%^RESET%^%^GREEN%^."
	);
	set_smell("default",
	"Wildflowers compete with the scent of wet sand."
	);
	set_listen("default",
	"The crashing of the waterfall is much louder now."
	);
	set_items( ([
	"river" : "%^BLUE%^The river pours down from the lake and"+
	" is lost in the woods at the eastern end of the"+
	" vale.",
	"lake" : "%^BOLD%^%^BLUE%^At the western end of the valley is a"+
	" large lake, a waterfall pours into it.",
	"waterfall" : "%^BOLD%^%^CYAN%^A waterfall cascades down a tall"+
	" cliff to crash noisily into the lake.",
	"valley" : "%^BOLD%^%^GREEN%^The rest of the valley stretches out"+
	" to the south, the Dark Forest marking its"+
	" boundaries.",
	"trees" : "%^GREEN%^There are several trees scattered"+
	" throughout the valley.",
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
					new(MONS+"dryad")->move(TO);
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
