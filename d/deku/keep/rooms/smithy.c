#include <std.h>
#include "../keep.h"  
inherit ROOM;

int csearched, searched;

void create() 
{
    ::create();
    set_light(2);
    set_indoors(1);
    set_name("ruined smithy");
    set_short("%^YELLOW%^Blacktongue's Smithy%^RESET%^");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_long("This was once the blacktongue smithy but that reality has "+
    "been forcefully shattered.  A gruesome scene plays out inside of "+
    "this building.  Held to the back wall, by a battle axe through the "+
    "torso, is the %^RED%^smith%^RESET%^ who once used this great "+
    "%^RED%^forge%^RESET%^.  The %^RED%^forge%^RESET%^ lies dormant "+
    "in the center of this building and has long since grown cold.  "+
    "Scraps of %^BOLD%^%^BLACK%^metal%^RESET%^ and various other "+
    "%^BOLD%^%^BLACK%^debris%^RESET%^ litter the %^BOLD%^%^WHITE%^floor%^RESET%^ "+
    "of this building.");
    set_smell("default","A strong odor of decay lingers here.");
    set_listen("default","It is deathly quiet here..");
    set_exits((["north": KEEPR + "keepE7"])); 
    set_items(([
        ({"smith","Smith","Corpse","corpse"}) : "%^RED%^This is the "+
        "half-orc corpse of the smith who once forged weapons here.  "+
        "He now remains held to the back wall of the building by a "+
        "battle axe through the torso.%^RESET%^",
        ({"floor","Floor"}) : "The floor of this building is littered "+
        "with debris ranging from scraps of metals to pieces of broken weapons.",
        ({"Debris","debris"}) : "Piles of debris litter the floor of this building.",
        ({"scraps","Scraps","metal","metal scraps"}) : "Scraps of metal "+
        "mingle with other various debris that litter the floor of this building.",
        ({"pieces","Pieces"}) : "The broken pieces of various weapons "+
        "mingle with other various debris that litter the floor of this building.",
        ({"Forge","forge"}) : "%^RED%^This great forge rests dormant "+
        "in the center of this building, it has long since grown cold.%^RESET%^",
        ] ));
    set_search("default","Perhaps you should search through the debris?");
    set_search("debris",(:this_object(),"debris_search":));
    set_search("scraps",(:this_object(),"debris_search":));
    set_search("floor",(:this_object(),"debris_search":));
    set_search("pieces",(:this_object(),"debris_search":));
    set_search("smith",(:this_object(),"corpse_search":));
    set_search("corpse",(:this_object(),"corpse_search":));
    set_search("Smith",(:this_object(),"corpse_search":));	
}

int debris_search(object ob) 
{
	object ob1;
	int find;
	tell_room(TO,TP->query_cap_name() + 
	"%^RED%^ searches through the debris.%^RESET%^",TP);
	if(searched == 1) 
	{
		write("%^RED%^Your search through the debris "+
		"but find nothing of interest.%^RESET%^");
		return 1;
	}
	
	find = random(100);
	if(find > 65) 
	{
		ob1 = SEARCH_D->do_found_object();
		write("%^RED%^You search through the debris and find " +
		ob1->query_short()+ "%^RED%^!%^RESET%^");
		searched = 1;
		ob1->move(TO);
		return 1;
	}
	write("%^RED%^You search through the debris but find nothing of interest.%^RESET%^");
	searched = 1;
	return 1;

}	

int corpse_search() 
{	
	tell_room(TO,TPQCN+" searches the rotting corpse of the smith.",TP);
	if(csearched == 1) 
	{
		write("You search the corpse of the smith and find nothing...");
		return 1;
	}
	else 
	{
		write("You search through the corpse of the smith and an "+
		"oddly shaped %^BOLD%^%^GREEN%^emerald%^RESET%^ falls from "+
		"somewhere on it....%^RESET%^");
		new(KEEPO + "emeraldeye")->move(TO);
		csearched = 1;
		return 1;
	}	
}

void reset() 
{
	::reset();
	csearched = 0;
	searched = 0;    
}