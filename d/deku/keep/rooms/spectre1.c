#include <std.h>
#include "../keep.h"

inherit VAULT;

int searched;

void do_original()
{
	set_long("This %^BOLD%^%^BLACK%^marble%^RESET%^ chamber is small, "+
	"only around eight feet square.  The floor of the chamber is "+
	"littered with the %^BOLD%^%^WHITE%^bones%^RESET%^ "+
	"of various creatures.  In the center of the chamber there "+
	"is a %^BOLD%^%^GREEN%^spear%^RESET%^ stuck in the floor at an "+
	"angle, obviously placed there by something of "+
	"great power.  The %^RED%^walls%^RESET%^ of this room "+
	"are covered with %^RED%^blood"+
	"%^RESET%^, as if some type of horrific slaughter took "+
	"place here and they bare witness "+
	"of it.  Inset directly into the center of the northern wall "+
	"is a massive %^BOLD%^%^BLACK%^marble door%^RESET%^.%^RESET%^");
 	set_items(([
		({"bones","Bones"}) : "%^BOLD%^%^WHITE%^These bones are "+
		"the remains of various creatures, some of them still have "+
		"pieces of flesh attached.%^RESET%^",
		({"floor","Floor"}) : "%^BOLD%^%^BLACK%^The marble floor of this "+
		"chamber is littered with the %^BOLD%^%^WHITE%^bones%^BOLD%^"+
		"%^BLACK%^ of various creatures.  A %^BOLD%^%^GREEN%^spear"+
		"%^BOLD%^%^BLACK%^ is stuck in the center of the floor at an "+
		"angle, obviously something of great power placed it there.%^RESET%^",
		({"walls","wall"}) : "%^RED%^The walls of this chamber are stained "+
		"with blood.  They are perhaps the only witness to some "+
		"horrific slaughter that once took place here.%^RESET%^",
		({"blood"}) : "%^RED%^Blood stains the walls of this chamber, "+
		"perhaps the only evidence of some great slaughter "+
		"that took place here.%^RESET%^",
		({"spear"}) : "%^BOLD%^%^GREEN%^This spear is embedded "+
		"almost entirely in the floor.  Maybe you could pull it out?%^RESET%^",
	] ));
	if(random(3) == 2) 
	{
  		searched = 0;
	}
}

void create()
{
	::create();
	set_property("no teleport",1);
	do_original();
    	set_property("light",1);
    	set_property("indoors",1);
	set_name("Spectre's Room");
    	set_short("%^BOLD%^%^WHITE%^BlackTongue Dungeon%^RESET%^");
    	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
    	set_smell("default","A heavy stench of decomposition saturates the air.");
    	set_listen("default","A strange silence sits in this room...");
    	set_exits(([
		"north" : KEEPR + "dungeon5"
    	] ));
	set_door("marble door",KEEPR + "dungeon5","north","shaltul key","lock");
	set_string("marble door", "open", "%^RED%^The door opens easily and "+
	"you're sense of smell is slightly relieved.%^RESET%^");
	set_locked("marble door",1,"lock");
	set_lock_description("marble door","lock","This is a complex "+
	"lock with odd engravings on it.");
	add_lock("marble door","siere key","lock2","This is a complex lock "+
	"with odd engravings on it.");
	add_lock("marble door","telair key","lock3","This is a complex lock "+
	"with odd engravings on it.");
	lock_difficulty("marble door",-101,"lock");
	lock_difficulty("marble door",-101,"lock2");
	lock_difficulty("marble door",-101,"lock3");
	set_door_description("marble door","%^BOLD%^%^BLACK%^This heavy marble "+
	"door is inset directly in the center of the northern wall.  "+
	"A handle is formed from the marble on one side of it.  There "+
	"are three keyholes inset into one side of it.  Its impossible to "+
	"determine how thick it is.%^RESET%^");
	set_search("default","Maybe you should try searching the bones?");
	set_search("bones",(:this_object(),"bone_search":));
}

void init() 
{
	::init();
	add_action("pull_function","pull");	
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
	write("%^BOLD%^%^WHITE%^You search through the bones but "+
	"find nothing of value.%^RESET%^");
	searched = 1;
	return 1;
}

int pull_function(string str) 
{
	if(!str) return 0;
	if(str == "spear" || str == "Spear") 
	{
		write("The spear is embedded far too deep for you to remove it!");
		return 1;
	}
	return 0;

}

void reset() 
{
	::reset();

	if(!present("human spectre")) 
	{
		new(KEEPM + "spectre")->move(TO);
		do_original();
	}
}