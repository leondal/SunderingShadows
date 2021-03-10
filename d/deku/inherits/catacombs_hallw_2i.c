//Hallway inherit for the hallways on the first 
//level of the catacombs of the dead area - Saide - 3/09
#include <std.h>
#include <daemons.h>
#include "forest.h"
inherit CROOM;
int mob_type;
string where_to;
void fix_exits();
void create() 
{
	if(!mob_type) mob_type = 1;
	if(!random(2)) 
	{ 
		if(base_name(TO) != CAT_HW_S)
	  	{
			if(mob_type == 1) 
			{
				set_monsters(({DEKU_MON"tomb_guardian"}), ({1}));
				set_monsters(({DEKU_MON"tomb_spirit"}), ({1 + random(2)}));
				set_repop(50);
			}
			if(mob_type == 2)
			{
				set_monsters(({DEKU_MON"tomb_guardian"}), ({1}));
				set_monsters(({DEKU_MON"tomb_spirit"}), ({1 + random(2)}));
				set_repop(50);
			}
		}
	}
    	::create();
    	set_short("%^YELLOW%^An ancient brick hallway%^RESET%^");
    	set_name("An ancient brick hallway");
    	set_property("light",0);
    	set_property("indoors",1);
    	set_terrain(ROCKY);
    	set_travel(PAVED_ROAD);
    	set_property("no teleport",1);
	//an ancient catacombs littered with all kinds of junk
	//making it possible that there are sticks sometimes
	if(!random(2)) 
	{
    		set_property("no sticks",1);
	}
	set_long("%^BOLD%^%^YELLOW%^The tunnel that you find yourself "+
	"in is old, perhaps ancient.  It is composed entirely of "+
	"%^RESET%^%^RED%^dark red bricks%^BOLD%^%^YELLOW%^ "+
	"which, though they are aged, appear in mostly good "+
	"shape.  They are a testament to the craftmanship of "+
	"whoever, or whatever, built them.  This tunnel "+
	"is much narrower than the ones you were in, "+
	"and though it has aged well, you cannot help but "+
	"to feel trapped and a bit apprehensive of being "+
	"so far underground.  The walls, floor, and "+
	"ceiling here have become caked with %^BOLD%^"+
	"%^MAGENTA%^dust%^BOLD%^%^YELLOW%^, probably "+
	"from this place setting for so long.  "+
	"Unfortunately, from the look of the "+
	"%^BOLD%^%^BLACK%^trails%^BOLD%^%^YELLOW%^"+
	" in the %^BOLD%^%^MAGENTA%^dust "+
	"%^BOLD%^%^YELLOW%^on the floor, something has been moving "+
	"about down here, quite frequently.%^BOLD%^%^YELLOW%^");
  
     	set_listen("default","%^BOLD%^%^GREEN%^Eerie howls and moans "+
	"float about down here constantly, lowering from a defeaning roar "+
	"to barely audible.%^RESET%^");
    	set_smell("default","The air is heavy with dust and decay, making "+
	"it hard to breath.");    
    	set_items(( [
		({"brick", "bricks", "dark red bricks"}) : "%^RED%^"+
		"The bricks that create this hallway look ancient, "+
		"however, they are in mostly good condition.  "+
		"A testament to the craftsmanship of whoever, or "+
		"whatever, created them.%^RESET%^",
		({"floor", "ceiling", "wall", "walls", "dust"}) : 
		"%^MAGENTA%^The walls, ceiling, and floor of this "+
		"tunnel are caked with a thick layer of dust.  It has "+
		"seemingly grown as this place sat.  Unfortunately, "+
		"there are %^BOLD%^%^BLACK%^trails%^RESET%^"+
		"%^MAGENTA%^ in the dust that has settled on the "+
		"floor.%^RESET%^", 		
		({"trail", "trails"}) : "%^BOLD%^%^BLACK%^These "+
		"trails closely resemble footprints, but "+
		"upon closer inspection they seem to be more the "+
		"result of some heavy object being dragged across "+
		"the floor.%^RESET%^",
     	] ));
      set_search("default", "%^MAGENTA%^There is only a layer of "+
	"dust here.  It isn't quite thick enough to conceal anything.%^RESET%^");
}

void fix_exits()
{
	int i;
	int rnum;
	string *room_name;
    	string *exits, *num, safe_exit;
    	exits = ({}) + TO->query_exits();
	if(!sizeof(exits)) return;
    	num = ({});
	room_name = explode(base_name(TO), "_");
	if(sizeof(room_name) != 4) return;
	rnum = to_int(room_name[3]);
	if(rnum > 15) return;
	switch(rnum)
	{
		case 1..6:
			if(rnum == 1) safe_exit = "north";
			where_to = CAT_ROOMS"cat_hw_sec_7";
			break;
		case 7..9:
			if(rnum == 7) safe_exit = "east";
			if(rnum == 9) safe_exit = "west";
			where_to = CAT_ROOMS"cat_hw_sec_10";
			break;
		case 10..15:
			if(rnum == 10) safe_exit = "south";
			where_to = CAT_ROOMS"cat_hw_sec_1";
			break;
		default:
			where_to = CAT_ROOMS"cat_hw_sec_1";
			break;
	}
	if(safe_exit) exits = exits - ({safe_exit});	
    	for(i = 0;i < sizeof(exits);i++) 
	{
      	if(num == ({})) 
		{
         		num = ({"GoThroughDoor"});
         		continue;
      	}
         	num += ({"GoThroughDoor"});
    	}
    	if(sizeof(exits) > 0) 
	{
      	set_pre_exit_functions(exits,num);
    	}   
}

int GoThroughDoor() 
{
	object tor;
	int flag;
	if(!objectp(TP)) return 1;
	if(TP->query_true_invis()) return 1;
	tor = present("catacombs_torch_key", TP);
	if(!objectp(tor)) flag = 1;
	else if(objectp(tor)) 
	{
		if(!tor->query_lit()) flag = 1;
	}
	if(flag)
	{
		tell_object(TP, "%^BOLD%^%^BLACK%^You suddenly feel reality "+
		"%^BOLD%^%^RED%^bend%^BOLD%^%^BLACK%^ around you, as you "+
		"find yourself somewhere else!%^RESET%^");

		tell_room(TO, "%^BOLD%^%^BLACK%^Reality seems to "+
		"%^BOLD%^%^RED%^bend%^BOLD%^%^BLACK%^ around "+
		TPQCN+"%^BOLD%^%^BLACK%^ and "+TP->QS+
		" fades away!%^RESET%^", TP);
		if(!where_to)
		{
			tell_object(TP, "%^BOLD%^%^WHITE%^ALERT - Something "+
			"bugged, let Saide know immediately!%^RESET%^");
			return 1;
		}
		TP->move(where_to);
		return 0;
	}
   	return 1;
}
