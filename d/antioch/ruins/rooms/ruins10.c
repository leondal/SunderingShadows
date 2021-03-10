#include <std.h>
#include "../ruins.h"
inherit ROOM;

void create()
{
	::create();
	set_property("indoors",0);
	set_property("light",1);
	set_short("%^BOLD%^%^BLACK%^Desolate Ruins%^RESET%^");
	set_long(
	"The house to the north has partially collapsed onto the street here."+
	" You can see the doorway is still relatively standing, but greyish"+
	" bricks from the second floor block any chances of getting inside."+
	" It must have been some earthquake to have collapsed this brick house."
	);
	set_smell("default","Dust hangs in the air.");
	set_listen("default","The ruins are eerily quiet.");
	set_items(([
	"doorway" : "The doorway is still mostly intact, but it is blocked off"+
	" by a ton of grey bricks that fell from the top story of the house.",
	"house" : "The house once was a sturdy structure made of grey bricks,"+
	" two stories in height. The earthquakes caused all but the very"+
	" foundations of the house to collapse they were so mighty.",
	]));
	set_exits(([
	"west" : ROOMS+"ruins9",
	]));
}

void reset()
{
	::reset();
	if(!present("monster")) {
		switch(random(5)) {
			case 0:
				new(MONS+"shadow")->move(TO);
				new(MONS+"shadow")->move(TO);
				break;
			case 1:
				new(MONS+"grimlock")->move(TO);
				new(MONS+"grimlock")->move(TO);
				new(MONS+"grimlock")->move(TO);
				break;
			case 2:
				new(MONS+"grimlock")->move(TO);
				new(MONS+"grimlock")->move(TO);
				new(MONS+"grimlock")->move(TO);
				new(MONS+"grimlock")->move(TO);
				break;
			case 3:
				new(MONS+"grimlock")->move(TO);
				new(MONS+"grimlock")->move(TO);
				new(MONS+"grimlock")->move(TO);
				new(MONS+"grimlock")->move(TO);
				new(MONS+"grimlock")->move(TO);
				break;
			case 4:
				new(MONS+"shadow")->move(TO);
				new(MONS+"shadow")->move(TO);
				new(MONS+"shadow")->move(TO);
				break;
		}
	}
}
