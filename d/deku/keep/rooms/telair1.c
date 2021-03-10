#include <std.h>
#include "../keep.h"

inherit ROOM;

int found, searched;

void create() 
{
	::create();
	set_property("no teleport",1);
	set_property("light",0);
    	set_property("indoors",1);
	set_name("Telair's Room");
    	set_short("%^BOLD%^%^WHITE%^Marble Chamber%^RESET%^");
    	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
    	set_long("%^BOLD%^%^WHITE%^This dull, %^BOLD%^%^BLACK%^marble"+
	"%^BOLD%^%^WHITE%^ chamber is approximately 20' square and extremely "+
	"filthy.  The only furniture, if it could "+
	"be called that, is a thick %^YELLOW%^bed of straw"+
	"%^BOLD%^%^WHITE%^ in the northeastern corner of the room.  "+
	"Pieces of bones, many still with flesh intact, "+
	"litter the floor of this room.  Whatever creature dwells "+
	"here obviously isn't very clean.  A %^BLUE%^cold wind%^BOLD%^%^WHITE%^ "+
	"blows in from an opening in the western "+
	"wall of this room, beyond the opening is a thick "+
	"%^BOLD%^%^BLACK%^darkness.%^RESET%^\n");

   	set_smell("default","The stench of decay lingers here.");
    	set_listen("default","Growls can be heard through the door.");
    	set_exits(([
		"opening": KEEPR + "dungeon4",
    	] ));
	set_items(([
		"bones" : "%^BOLD%^%^WHITE%^These bones are obviously the "+
		"remains of the meal or several meals of some type of beast.  "+
		"Some of them still have pieces of flesh attached, causing you "+
		"to believe that the meals were rather recent.%^RESET%^",
		({"bed","straw","straw bed","hay","hay bed"}) : "%^YELLOW%^This bed "+
		"of straw is strewn together in the northwestern corner of this room.  "+
		"It doesn't look very comfortable.  You hesitate to think of what "+
		"could be living in this bed.%^RESET%^",
		"floor" : "%^BOLD%^%^RED%^The floor of this room is littered "+
		"with various types of bones and other filth.  Some of the "+
		"bones still have pieces of meat intact.%^RESET%^",
		({"opening","wall"}) : "%^BOLD%^%^BLACK%^This opening leads "+
		"into a thick darkness, there is a cold wind coming from it.%^RESET%^",
		"flesh" : "%^RED%^Pieces of flesh remain on some of the bones that "+
		"lay here.%^RESET%^",
		"darkness" : "%^BOLD%^%^BLACK%^This thick darkness lingers "+
		"just outside of this chamber, beyond the opening.%^RESET%^",
		({"wind","cold wind"}) : "%^BOLD%^%^BLUE%^This cold wind blows "+
		"in from outside of the chamber, sending chills coarsing through your body.%^RESET%^",
	]));
	set_search("default","Search What?");
	set_search("bones",(:this_object(),"bone_search":));
	set_search("bed",(:this_object(),"bed_search":));
	
}

int bone_search(object ob)
{
	object ob1;
	int find;
	tell_room(TO,TP->query_cap_name() + "%^BOLD%^%^WHITE%^ searches "+
	"through a pile of bones.%^RESET%^",TP);
	if(searched == 1)
	{
		write("%^BOLD%^%^WHITE%^You search through the bones but "+
		"find nothing of value.%^RESET%^");
		return 1;
	}
	find = random(100);
	if(find >= 80)
	{
		ob1 = SEARCH_D->do_found_object();
		write("%^BOLD%^%^WHITE%^You search through the bones and find " + 
		ob1->query_short() +"%^BOLD%^%^WHITE%^!%^RESET%^");
		ob1->move(TO);
		searched = 1;
		return 1;
	}
	write("%^BOLD%^%^WHITE%^You search through the bones but find "+
	"nothing of value.%^RESET%^");
	searched = 1;
	return 1;
}

int bed_search()
{
	if(found == 0) 
	{
		write("%^BLUE%^You search through the thick bed of hay and "+
		"manage to find a key!%^RESET%^");
		new(KEEPO + "telairkey")->move(TO);
		found = 1;
		return 1;
	}
	else 
	{
		write("%^RED%^You search through the thick bed of hay but "+
		"find only flees and lice.%^RESET%^");
		return 1;
	}
}

void reset() 
{
	object myob;
	int x, trolls, flag;
  	::reset();
  	found = 0;
  	trolls = 1 + random(2);
	if(sizeof(children(KEEPM+"telair"))) 
	{
		myob = children(KEEPM+"telair")[0];
	}
	else myob = find_object(KEEPM+"telair");
	if(!objectp(myob)) flag = 1;		
	if(objectp(myob))
	{
		if(!objectp(environment(myob))) flag = 1;		
	}
	if(!flag) 
	{
 		if(!present("troll")) 
		{
			for(x = 0;x < trolls;x++) 
			{
				new(KEEPM + "troll_guard")->move(TO);
			}
		}
		return;
	}
		
	if(random(8) > 6) 
	{
		
		if(flag) 
		{
			if(!objectp(myob)) myob = new(KEEPM+"telair");
			myob->move(TO);		  
		}
		if(!present("troll")) 
		{
	   		for(x = 0;x < trolls;x++) 
			{
				new(KEEPM + "troll_guard")->move(TO);
			}
		}
	}		  
}
