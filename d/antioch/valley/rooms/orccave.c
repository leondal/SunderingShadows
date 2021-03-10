#include <std.h>
#include "../valley.h"
inherit ROOM;

int SEARCHED;

void create()
{
	::create();
   set_terrain(NAT_CAVE);
   set_travel(FOOT_PATH);
	set_property("indoors", 1);
	set_property("light", 1);
	set_short("Orc Cave");
	set_long(
	"It appears that a band of orcs have been living"+
	" in this small cave. There is a fire pit near the"+
	" entrance that must have been used for cooking."+
	" Dirty furs litter the back corner where the orcs"+
	" have obviously been sleeping. The place is"+
	" absolutely filthy."
	);
	set_smell("default","The stench of orcs almost makes you gag.");
	set_listen("default","There is only silence.");
	set_items( ([
	"fire" : "The pit is filled with ashes and the"+
	" remains of a burnt meal.",
	"furs" : "The furs are very grimy, they look like"+
	" wolf skin, and they're piled together in heaps. One of them"+
   " is raised up rather high and looks like there might be something"+
   " under it.",
	]) );
	set_exits( ([
	"south" : ROOMS+"dt25",
	]) );
   set_search("furs",(:TO,"search_furs":));
}

void reset()
{
	::reset();
   SEARCHED = 0;
   add_item("furs","The furs are very grimy, they look like"+
	" wolf skin, and they're piled together in heaps. It almost"+
   " looks as though someone has searched through them recently.");
	if(!present("orc")) {
		switch(random(4)) {
			case 0:
				new(MONS+"orc")->move(TO);
				new(MONS+"orc")->move(TO);
				new(MONS+"orc")->move(TO);
				break;
			case 1:
				new(MONS+"orc")->move(TO);
				new(MONS+"orc")->move(TO);
				new(MONS+"orc")->move(TO);
				new(MONS+"orc")->move(TO);
				break;
			case 2:
				new(MONS+"orc")->move(TO);
				new(MONS+"orc")->move(TO);
				new(MONS+"orc")->move(TO);
				new(MONS+"orc")->move(TO);
				new(MONS+"orc")->move(TO);
				break;
			case 3:
				new(MONS+"orc")->move(TO);
				new(MONS+"orc")->move(TO);
				new(MONS+"orc")->move(TO);
				new(MONS+"orc")->move(TO);
				new(MONS+"orc")->move(TO);
				new(MONS+"orc")->move(TO);
				break;
		}
	}
}

int search_furs()
{
   object obj, money;

   if(present("monster")) {
      tell_object(TP,"You don't think the orcs are going to let you"+
      " search through their things.");
      return 1;
   }
   if(SEARCHED == 1) {
      tell_object(TP,"You search the furs but find nothing other than lice.");
      tell_room(ETP,""+TPQCN+" searches through the furs but finds nothing.",TP);
      return 1;
   }
   tell_object(TP,"You find a small chest hidden under the furs!");
   tell_room(ETP,""+TPQCN+" finds a small chest beneath the furs!",TP);
   add_item("furs","The furs are very grimy, they look like"+
	" wolf skin, and they're piled together in heaps. It almost looks"+
   " as though someone has searched through them recently.");
   SEARCHED = 1;
   obj = new("/d/shadow/obj/misc/schest");
   obj->move(TO);
   obj->set_key("chestkey");
   money = new("/std/obj/coins");
   money->set_money("gold",random(200)+100);
   money->set_money("electrum",random(300)+50);
   money->set_money("copper",random(2000)+500);
   money->set_money("silver",random(200)+25);
   money->move(obj);
   obj->toggle_closed();
   obj->set_lock("locked");
   obj->set_lock_difficulty(50);
   return 1;
}
