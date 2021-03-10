#include <std.h>
#include <area_stuff.h>
#include <daemons.h>

inherit CVAULT;
void create() 
{
	if(base_name(TO) != RA_MR_UFT && 
	base_name(TO) != RA_UFT_BH &&
	base_name(TO) != RA_UFT_FH && 
	base_name(TO) != RA_UFT_CH && 
	member_array(base_name(TO), MySafeRooms) == -1) 
	{ 
		if(!random(1000))
		{
			set_monsters(({RA_MON+"flesh_beast"}), ({1}));
		}
		else 
		{
	     		switch(random(11)) 
			{
				case 0..8:
					break;
				case 9..10:
					set_monsters(({RA_MON+"horrid_phantasm"}), ({1 + random(2)}));
					break;      			
			}
		}
      	set_repop(30);
 	}

 	::create();
   	set_property("no teleport",1);
    	set_property("light",0);
    	set_property("indoors",1);
	set_property("no sticks", 1);
    	set_name("an unfinished tunnel");
    	set_short("%^BOLD%^%^BLACK%^An unfinished tunnel%^RESET%^");
    	set_terrain(BUILT_TUNNEL);
    	set_travel(PAVED_ROAD);

	set_long("%^BOLD%^%^BLACK%^This tunnel is some obviously unfinished "+
	"portion of the %^BOLD%^%^RED%^ancient keep%^BOLD%^%^BLACK%^ "+
	"that you find yourself in.  While it is composed of the "+
	"same %^BOLD%^%^RED%^bright red bricks%^BOLD%^%^BLACK%^ and "+
	"the craftmanship speaks of the same %^RESET%^%^MAGENTA%^m"+
	"%^BOLD%^e%^RESET%^%^MAGENTA%^t%^BOLD%^i%^RESET%^%^MAGENTA%^"+
	"c%^BOLD%^u%^RESET%^%^MAGENTA%^l%^BOLD%^o%^RESET%^%^MAGENTA%^"+
	"u%^BOLD%^s%^BOLD%^%^BLACK%^ hand, it has obviously not seen "+
	"much upkeep.  Large %^BOLD%^%^YELLOW%^cracks%^BOLD%^%^BLACK%^"+
	" have formed quite blatantly between many of the %^BOLD%^%^RED%^"+
	"bricks%^BOLD%^%^BLACK%^ and %^MAGENTA%^dirt%^RESET%^%^BOLD%^%^BLACK%^"+
	" has spilled out onto much of the "+
	"floor.  What is left exposed of the %^RESET%^%^RED%^floor%^BOLD%^"+
	"%^BLACK%^ reveals it to be made from slightly %^RESET%^%^RED%^darker "+
	"red%^BOLD%^%^BLACK%^ bricks, "+
	"that are fragmented quite heavily.  The %^BOLD%^%^WHITE%^"+
	"ceiling %^BOLD%^%^BLACK%^here is much lower, apparently "+
	"composed from the same %^RESET%^%^RED%^bricks%^BOLD%^%^BLACK%^ "+
	"as the floor.%^RESET%^");


     	set_smell("default","The smell of moist earth hangs heavily here.");
    	set_listen("default","Eerie howls and moans float around down here, seemingly "+
	"from nowhere.");

	set_search("default", "What do you want to search?");

	set_items(([ ({"brick", "bricks", "bright red brick", 
	"bright red bricks", 
	"wall", "walls"}) : "%^BOLD%^%^RED%^The walls of "+
	"this tunnel are composed entirely of these "+
	"bricks.  There are large cracks between alot of "+
	"them and dirt from behind them has spilled out onto "+
	"the floor.%^RESET%^", 
	({"dark brick", "floor", "darker brick", 
	"dark brick", "dark red bricks",
	 "dark red brick", "ceiling"})  : "%^RED%^The floor and "+
	"ceiling here are composed of darker red bricks.  "+
	"The floor is lined with cracks and many of the "+
	"bricks that create it have broken apart into "+
	"fragments.  The ceiling is composed of the same "+
	"bricks and doesn't appear to be in much better "+
	"shape.%^RESET%^",
	({"cracks", "large cracks", "crack"}) : 	"%^YELLOW%^"+
	"The walls and floor of this place are littered with "+
	"cracks of varying degrees.  Dirt has spilled out "+
	"onto the floor from most of them and some of them "+
	"are large enough that you could stick your hand "+
	"into them.%^RESET%^",
	({"dirt", "earth"}) : "%^MAGENTA%^The dirt that "+
	"has spilled out from the cracks in this room "+
	"is slightly moist and clumps together.%^RESET%^",
   	] ));

	set_search("brick", (:TO, "brick_search":));
	set_search("bricks", (:TO, "brick_search":));
	set_search("light red bricks", (:TO, "brick_search":));
	set_search("dark red bricks", (:TO, "floor_search":));
	set_search("dark bricks", (:TO, "floor_search":));
	set_search("floor", (:TO, "floor_search":));
	set_search("crack", (:TO, "crack_search":));
	set_search("cracks", (:TO, "crack_search":));
	set_search("large crack", (:TO, "crack_search":));
	set_search("large cracks", (:TO, "crack_search":));
	set_property("traps_known_to_monsters", ({RA_MON, "/d/common/mons/"}));
	set_property("random traps", "epic");
}

int brick_search(string ob)
{
	if(!objectp(TP)) return 0;
	if(!objectp(TO)) return 0;
	tell_room(TO, TPQCN +"%^BOLD%^%^RED%^ searches carefully over "+
	"the bricks.%^RESET%^", TP);
	tell_object(TP, "%^BOLD%^%^RED%^You carefully search the bricks "+
	"that remain here - you find nothing that seems "+
	"hidden or out of place.%^RESET%^");
	return 1;
}

int floor_search(string ob)
{
	if(!objectp(TP)) return 0;
	if(!objectp(TO)) return 0;
	tell_room(TO, TPQCN + " %^RED%^searches carefully along the "+
	"floor.%^RESET%^", TP);
	tell_object(TP, "%^RED%^You search the floor carefully but "+
	"manage to find nothing of consequence.%^RESET%^");
	return 1;
}

int crack_search(string ob)
{
	if(!objectp(TP)) return 0;
	if(!objectp(TO)) return 0;
	tell_room(TO, TPQCN + "%^BOLD%^%^YELLOW%^ sticks "+TP->QP+
	" hand into one of the large cracks and feels around.%^RESET%^", TP);
	tell_object(TP, "%^BOLD%^%^YELLOW%^You stick your hand into one "+
	"of the larger cracks and feel around, but find nothing of interest.%^RESET%^");
	return 1;
}

void reset()
{
	::reset();
	if(!present("chest", TO)) 
	{
		if(!random(15)) 
		{
			new(RA_MON+"mimic")->move(TO);
		}
	}
}	
