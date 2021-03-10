#include <std.h>
#include "../theater.h"
inherit CROOM;

	void make_creatures();
	void create(){
   	::create();
      make_creatures();
      set_repop(55);
   	set_property("indoors",1);
   	set_property("light",1);
	set_property("no sticks",1);
	set_property("no teleport",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
   	set_name("%^RED%^Desert Sun Theater - Understage");
   	set_short("%^RED%^Desert Sun Theater - Understage");
   	set_long("%^ORANGE%^Smooth sandstone blocks form the walls of the "+
		"understage area of the theater.  Carved from the foundation"+
		" of the theater, the understage area is where the real work of"+
		" the theater is done.  The wide spacious corridors allow for"+
		" plenty of room to move large objects to the stage.  Wooden "+
		"support beams transverse the ceiling of this area, granting "+
		"support to the theater above.  Large amounts of %^RESET%^dust"+
		"%^ORANGE%^ covers the walls and beams, giving the illusion that"+
		" this part of the theater has not been in use for decades.\n");
   	set_smell("default","%^RED%^A musty stale scent hangs in the air.");
   	set_listen("default","%^YELLOW%^There is a creepy stillness down here.");
  	set_items(([
      	({"walls","wall","sandstone"}) : "%^YELLOW%^Smooth blocks of"+
	" sandstone are stacked on top of each other to create the solid "+
	"foundation for the theater.  Sandwiched in between the sandstone"+
	" blocks is a thick yellowish mortar, adding to the strength of "+
	"the stone.",
      	({"beams","ceiling"}) : "%^BOLD%^%^ORANGE%^The wooden planks of"+
	" the theater above you can be seen from  here.  Under the flooring,"+
	" thick wooden beams offer stability and strength to the theater above."+
	"  The beams are covered with large amounts of dust.",
	]));
	make_creatures();
}
void make_creatures()
{       
        int monsters;
        monsters = has_mobs();
        if(!monsters) {
                if(mons) { mons = ([]); }
                        switch(random(60)){
			case 0..20:
			break;
			case 21..24:
			set_monsters(({MOB"marion_fighter"}),({1}));
			break;
			case 25..30:
			set_monsters(({MOB"marion_cleric"}),({1}));
			break;
			case 31..34:
			set_monsters(({MOB"marion_thief"}),({1}));
			break;
			case 35..39:
			set_monsters(({MOB"marion_cavalier"}),({1}));
			break;
			case 40..42:
			set_monsters(({MOB"marion_fighter"}),({1}));
			set_monsters(({MOB"marion_thief"}),({1}));
			break;
			case 43..45:
			set_monsters(({MOB"marion_fighter"}),({1}));
			set_monsters(({MOB"marion_cleric"}),({1}));
			break;
			case 46..50:
			set_monsters(({MOB"marion_fighter"}),({1}));
			set_monsters(({MOB"marion_cavalier"}),({1}));
			break;
			case 51..55:
			set_monsters(({MOB"marion_cleric"}),({1}));
			set_monsters(({MOB"marion_cavalier"}),({1}));
			break;
			case 56..59:
			set_monsters(({MOB"marion_thief"}),({1}));
			set_monsters(({MOB"marion_cleric"}),({1}));
			break;
 				 }
        }
        return;
}
void reset() 
	{ ::reset(); 
		make_creatures();
		return; 
	}