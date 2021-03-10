//Updated to CROOM and changed spawn mix to match intended level range - Octothorpe 12/26/09

#include <std.h>
#include "../../valley.h"
inherit CROOM;

#define MON ({"ghoul","wight","wraith","zombie","ghast"})
#define MON2 ({"skeleton","haunt","heucuva","mzombie","ghost"})

int i, j, g;
string str, type;

void create()
{
	j = random(2);
	g = random(2);
	str = MON[j];
	type = MON2[g];

	if(!present("monster")) {
		if(query_night() == 1) {
			switch(random(7)) {
				case 0:
					set_monsters(({MONS+str,MONS+type}),({1,1})); break;
				case 1:
					set_monsters(({MONS+str,MONS+type}),({1,1})); break;
				case 2:
					set_monsters(({MONS+"hshade",MONS+str}),({1,1})); break;
				case 3:
					set_monsters(({MONS+"ghost",MONS+str}),({1,1})); break;
				case 4:
					set_monsters(({MONS+"zombie",MONS+type}),({1,1,1})); break;
				case 5:
					set_monsters(({MONS+"wskeleton",MONS+"wraith"}),({1,1})); break;
				case 6:
					set_monsters(({MONS+"ghoul",MONS+"ghast"}),({1,1})); break;
			}
		}

		else {
			switch(random(6)) {
				case 0:
					set_monsters(({MONS+str,MONS+type}),({1,1})); break;
				case 1:
					set_monsters(({MONS+str,MONS+type}),({1,1})); break;
				case 2:
					set_monsters(({MONS+"wskeleton",MONS+str}),({1,1})); break;
				case 3:
					set_monsters(({MONS+"hshade",MONS+str}),({1,1})); break;
				case 4:
					set_monsters(({MONS+"mzombie",MONS+"wskeleton"}),({1,1})); break;
				case 5:
					set_monsters(({MONS+"wskeleton",MONS+"heucuva"}),({1,1})); break;
			}
		}
	}
	::create();
	set_repop(40);
	set_climate("mountain");
    set_terrain(HEAVY_FOREST);
    set_travel(DIRT_ROAD);
	set_property("outside",0);
	set_property("light", 1);
	set_short("%^BLUE%^Dark Trail%^RESET%^");
	set_long(
	"%^BLUE%^You are travelling along a dark wooded trail."+
	" The path is small but well worn, though it looks"+
	" as if it hasn't been used in some time. The trees"+
	" press in closely around and block out most of the"+
	" sky, giving the place a %^BOLD%^%^BLACK%^gloomy%^RESET%^%^BLUE%^ atmosphere.\n"
	);
	set("night long",
	"%^BLUE%^The trail in front of you is %^BOLD%^%^BLACK%^dark%^RESET%^%^BLUE%^"+
        " and %^RESET%^gloomy%^BLUE%^, the"+
	" trees block out even the %^BOLD%^%^WHITE%^starlight%^RESET%^%^BLUE%^ and seem to loom"+
	" over you. %^BOLD%^%^BLACK%^Evil%^RESET%^%^BLUE%^ seems to emanate from around you.\n"
	);
	set_smell("default",
	"You smell the strong scent of pine mingled with"+
	" a dank fungus aroma."
	);
	set_listen("default",
	"The wind whispers eerily through the trees."
	);
	set_items( ([
	"trees" : "%^BLUE%^The trees are tall and sinister, blocking"+
	" out most light, you can see why this is called the"+
	" Dark Forest.",
	({"path","trail"}) : "%^ORANGE%^This is an old trail that used to be"+
	" well used, but now leaves and moss litter the"+
	" ground and it looks as if no one has passed this"+
	" way in some time."
	]) );
}

void reset()
{
	j = random(2);
	g = random(2);
	str = MON[j];
	type = MON2[g];

	if(!present("monster")) {
		if(query_night() == 1) {
			switch(random(7)) {
				case 0:
					set_monsters(({MONS+str,MONS+type}),({1,1})); break;
				case 1:
					set_monsters(({MONS+str,MONS+type}),({1,1})); break;
				case 2:
					set_monsters(({MONS+"hshade",MONS+str}),({1,1})); break;
				case 3:
					set_monsters(({MONS+"ghost",MONS+str}),({1,1})); break;
				case 4:
					set_monsters(({MONS+"zombie",MONS+type}),({1,1})); break;
				case 5:
					set_monsters(({MONS+"wskeleton",MONS+"wraith"}),({1,1})); break;
				case 6:
					set_monsters(({MONS+"ghoul",MONS+"ghast"}),({1,1})); break;
			}
		}

		else {
			switch(random(6)) {
				case 0:
					set_monsters(({MONS+str,MONS+type}),({1,1})); break;
				case 1:
					set_monsters(({MONS+str,MONS+type}),({1,1})); break;
				case 2:
					set_monsters(({MONS+"wskeleton",MONS+str}),({1,1})); break;
				case 3:
					set_monsters(({MONS+"hshade",MONS+str}),({1,1})); break;
				case 4:
					set_monsters(({MONS+"mzombie",MONS+"wskeleton"}),({1,1})); break;
				case 5:
					set_monsters(({MONS+"haunt",MONS+"heucuva"}),({1,1})); break;
			}
		}
	}
	::reset();
}