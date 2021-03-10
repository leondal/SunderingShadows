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
	"%^GREEN%^You are standing near the edge of a valley. The"+
	" %^BOLD%^%^BLACK%^Dark Forest%^RESET%^%^GREEN%^ stretches out to encompass the area,"+
	" but it doesn't seem quite as evil now, though"+
	" you wouldn't want to get lost in it. Thick %^BOLD%^%^GREEN%^grass"+
	" %^RESET%^%^GREEN%^spreads out before you, stretching over the"+
	" entire valley. There is a sense of peace of"+
	" through the area and you wonder if anyone"+
	" tends to this vale.\n"
	);
	set("night long",
	"%^GREEN%^You're standing near the edge of the valley. The"+
	" %^BOLD%^%^BLACK%^Dark Forest%^RESET%^%^GREEN%^ stretches out to enfold the vale"+
	" and it seems quite %^BLUE%^sinister%^GREEN%^ at night. You can"+
	" barely make out the trees on the edges, it just"+
	" seems to be a dark maw that swallows up any"+
	" light that dares to get near it. You can't"+
	" imagine trying to make your way through it"+
	" without a trail. The rest of the valley is"+
	" blanketed in thick %^BOLD%^%^GREEN%^grass"+
        " %^RESET%^%^GREEN%^that shines dimly with"+
	" %^BOLD%^%^WHITE%^moonlight%^RESET%^%^GREEN%^. There is a quiet peace here as you"+
	" look over the vale and you wonder if anyone"+
	" tends to this place.\n"
	);
	set_smell("default",
	"The scent of wildflowers drifts in the breeze."
	);
	set_listen("default",
	"The rush of a waterfall can barely be heard."
	);
	set_items( ([
	"valley" : "%^GREEN%^You're standing on the edge of it.",
	"waterfall" : "%^BOLD%^%^CYAN%^The waterfall pours down into a lake.",
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
