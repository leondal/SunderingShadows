#include <std.h>
#include "../keep.h"
#define POTIONS ({ "cure_poison","heal","paralyze","poison","hurt","extra_heal","invisible",\
	"det_invis","hurt","weaken", "cure_poison","heal","paralyze","poison","hurt","weaken","heal",\
 "poison","hurt","paralyze","poison","cure_poison","extra_heal","poison","hurt","raging_heal",\
"poison","hurt","paralyze","hurt","weaken","invisible" })

inherit ROOM;

int found, w_search;

void create()
{
    	::create();
	set_property("no teleport",1);
	set_property("light",0);
	set_name("Siere's Room");
	set_property("indoors",1);
    	set_short("%^BOLD%^%^WHITE%^BlackTongue Dungeon%^RESET%^");
	set_long("This %^YELLOW%^shiny%^RESET%^, %^BOLD%^%^BLACK%^"+
	"marble%^RESET%^ room is approximately 40' "+
	"square, it obviously serves as some type of living quarters, perhaps for a mage.  "+
	"A long %^MAGENTA%^table%^RESET%^ sits near the northern wall of the room and is "+
	"lined with rows of filled %^RED%^vials%^RESET%^ of different colours.  A massive "+
	"%^BLUE%^bookshelf%^RESET%^ filled with various sizes of %^BLUE%^tomes%^RESET%^ is "+
	"near the southern wall.  Another %^MAGENTA%^table%^RESET%^ sits up against the "+
	"eastern wall, it is almost entirely covered with %^YELLOW%^scrolls%^RESET%^ and "+
	"various spell %^YELLOW%^components%^RESET%^.  Directly in the center of the room is "+
	"an enormous %^BOLD%^%^GREEN%^oak canopy bed%^RESET%^.  An opening in the western "+
	"wall of this room leads into %^BOLD%^%^BLACK%^darkness%^RESET%^.  If not for the "+
	"stench of decay this room would almost be comfortable.%^RESET%^");
	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
    	set_smell("default","The stench of decay lingers here.");
    	set_listen("default","Growls can be heard through the door.");
    	set_exits(([
		"opening": KEEPR + "dungeon14",
   	] ));
	set_search("default","Search What?");
	set_search("bed",(:this_object(),"bed_search":));
	set_search("vials",(:this_object(),"vial_search":));
	set_search("scrolls",(:this_object(),"scroll_search":));
	set_search("components",(:this_object(),"comp_search":));
	set_items(([
		({"walls","wall"}) : "%^MAGENTA%^Tables%^RESET%^ line the northern "+
		"and eastern walls, a %^BLUE%^bookshelf%^RESET%^ rests near the "+
		"southern, and an %^BOLD%^%^BLACK%^opening%^RESET%^ on the western "+
		"wall wall leads into darkness.%^RESET%^",
		({"floor","Floor"}) : "The floor of this room is suprisingly well "+
		"kept.%^RESET%^",
		({"bed","canopy bed","canopy","oak bed","oak canopy"}) : "The frame of "+
		"this massive %^BOLD%^%^GREEN%^canopy bed%^RESET%^ is made completely "+
		"from %^RED%^red oak%^RESET%^.  The mattress of it is covered with "+
		"%^BOLD%^%^BLACK%^black satin%^RESET%^ sheets and thick quilts that "+
		"are lined with strands of %^YELLOW%^golden%^RESET%^ thread.%^RESET%^",
		({"table","tables"}) : "A %^MAGENTA%^table%^RESET%^ covered with "+
		"%^RED%^vials%^RESET%^ rests near the northern wall and against "+
		"the eastern wall is a %^MAGENTA%^table%^RESET%^ covered with "+
		"%^YELLOW%^scrolls%^RESET%^ and various spell %^YELLOW%^components"+
		"%^RESET%^, which one do you want to look at?%^RESET%^",
		({"north table","northern table"}) : "This sturdy %^MAGENTA%^"+
		"table%^RESET%^ is made from %^RED%^red oak%^RESET%^.  "+
		"Rows of %^RED%^vials%^RESET%^ filled with different colored "+
		"liquids line the top of it.%^RESET%^",
		({"east table","eastern table"}) : "This sturdy %^MAGENTA%^"+
		"table%^RESET%^ is made from %^RED%^red oak%^RESET%^.  The top of "+
		"it is almost completely covered with %^YELLOW%^scrolls%^RESET%^ "+
		"and various spell %^YELLOW%^components%^RESET%^.",
		({"bookshelf","shelf"}) : "This massive %^BLUE%^bookshelf%^RESET%^ "+
		"is very solid and made from %^RED%^red oak%^RESET%^.  Its shelves "+
		"are lined with %^BLUE%^tomes%^RESET%^ of all different sizes, most "+
		"of them appear very old.%^RESET%^",
		({"vials","vial"}) : "These %^RED%^vials%^RESET%^ are all filled with "+
		"colored liquids, most unknown to you.  Rows and rows of them line "+
		"the top of the northern %^MAGENTA%^table%^RESET%^.  If you searched "+
		"carefully enough you might be able to find some that are "+
		"familiar.%^RESET%^.%^RESET%^",
		"scrolls" : "These %^YELLOW%^scrolls%^RESET%^ are written in some "+
		"unknown language.  Most of them are old, the writing is fading "+
		"fast, and the paper is begginning to crumble.  You never know "+
		"though, there could be some useful ones hidden within them.%^RESET%^",
		({"components","component"}) : "These %^YELLOW%^components%^RESET%^ "+
		"cover the %^MAGENTA%^table%^RESET%^ near the eastern wall of this "+
		"room.  Most of them are of unknown origin, taken from creatures "+
		"that are not of this world.  They would probably serve no use "+
		"in the composition of most common magical spells, but you never "+
		"know, there might be some useful ones.%^RESET%^",
		({"tomes","tome"}) : "These %^BLUE%^tomes%^RESET%^ fill the shelves "+
		"of a massive %^BLUE%^bookshelf%^RESET%^.  They vary is size, but "+
		"most of them show degrees of age.%^RESET%^",
	]));	
}

int vial_search()
{
	int i, how_many;
	
	tell_room(TO,TPQCN+" examines the vials carefully.",TP);
	if(w_search == 4) 
	{
		how_many = random(2) + 1;
		w_search = 0;
		tell_object(TP,"%^RED%^You sort through the vials and find " +
		how_many+ " that you might "+
		"be able to use!%^RESET%^");
		for(i = 0;i < how_many;i++) 
		{
			new("/d/common/obj/potion/" + POTIONS[random(sizeof(POTIONS))])->move(TO);
		}
		return 1;
	}
 	tell_object(TP,"%^RED%^You sort through the vials but find none of interest.%^RESET%^");
	return 1;

}

int scroll_search() 
{
	int i, how_many;
	object ob;
	tell_room(TO,TPQCN+" looks over the scrolls carefully.",TP);
	if(w_search == 7) 
	{
		how_many = random(2) + 1;
		w_search = 0;
		tell_object(TP,"%^YELLOW%^You carefully examine the scrolls and find " +
		how_many+ " of interest.%^RESET%^");
		for(i = 0;i < how_many;i++)
		{
			ob = new("/d/magic/scroll");
			ob->set_spell(random(3) + 1);
			ob->move(TO);
		}
		return 1;
	}
	tell_object(TP,"%^YELLOW%^You carefully examine the scrolls "+
	"but find none that merit closer inspection.%^RESET%^");
	return 1;
}

int comp_search() 
{
	int i, how_many;
	tell_room(TO,TPQCN+" digs through the various components.",TP);
	if(w_search == 9) 
	{
		how_many = random(4) + 2;
		w_search = 0;
		tell_object(TP,"%^YELLOW%^You dig through the components and find " +
		how_many+" that could be of use.%^RESET%^");
		for(i = 0;i < how_many;i++) 
		{
			"/d/common/daemon/randstuff_d"->find_stuff(TO,"component");
		}
		return 1;
	}
	tell_object(TP,"%^YELLOW%^You dig through the components but "+
	"find none of any use.%^RESET%^");
	return 1;
}


int bed_search() 
{
	tell_room(TO,TPQCN+" searches the bed carefully.",TP);
	if(found == 0) 
	{
		write("You search through the covers of the %^BOLD%^%^GREEN%^"+
		"canopy%^RESET%^ bed and find a key!%^RESET%^");
		new(KEEPO + "sierekey")->move(TO);
		found = 1;
		return 1;
	}
	write("You carefully search the %^BOLD%^%^GREEN%^canopy%^RESET%^ "+
	"bed, but find nothing.%^RESET%^");
	return 1;
}


void reset() 
{
	object myob;
	int x, flag;
  	::reset();
  
		if(random(5) > 3) 
		{
			found = 0;
			w_search = random(10);
		}

		if(random(6) > 4) 
		{
			if(sizeof(children(KEEPM+"siere"))) 
			{
				myob = children(KEEPM+"siere")[0];
			}
			else myob = find_object(KEEPM+"siere");
			if(!objectp(myob)) flag = 1;		
			if(objectp(myob))
			{
				if(!objectp(environment(myob))) flag = 1;		
			}
			if(flag)
			{
				if(!objectp(myob)) myob = new(KEEPM+"siere");
				myob->move(TO);
				for(x = 0;x < random(4)+1;x++) 
				{
					new(KEEPM+"massivewerewolf")->move(TO);
				}
			}
		}
}
