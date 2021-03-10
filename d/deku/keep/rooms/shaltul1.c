#include <std.h>
#include "../keep.h"
inherit ROOM;
int opened,found;
string *failed_lift;
string *passed;
string pos, pos2;

void original_setup(string position, string position2) 
{
	set_long("%^BOLD%^%^WHITE%^This shiny, %^BOLD%^%^BLACK%^marble%^BOLD%^"+
	"%^WHITE%^ room is approximately twenty feet square and suprisingly "+
	"bare.  Every wall except for the western wall of this room is inscribed "+
	"with numerous %^CYAN%^hieroglyphics%^BOLD%^%^WHITE%^.  "+
	"A %^RED%^red stone sarcophagus%^BOLD%^%^WHITE%^ is inset into the "+
	"center of the floor of this chamber.  Only the very top of it is "+
	"visible, obviously it is set deep into the "+
	"floor"+position+"  You can only guess as to what could be contained "+
	"within, but your thoughts are interupted as the %^BOLD%^%^BLACK%^"+
	"darkness%^BOLD%^%^WHITE%^ that lingers here begins to "+
	"permeate your very %^RED%^being.  %^BOLD%^%^WHITE%^An "+
	"%^RED%^opening%^BOLD%^%^WHITE%^ on the western wall of this room "+
	"leads into thicker %^BOLD%^%^BLACK%^darkness.%^RESET%^");
	set_items(([
		({"hieroglyphics","symbols"}) : "%^CYAN%^Which hieroglyphics do you "+
		"want to look at?  They cover every wall except for the west.%^RESET%^",
		({"walls","wall"}) : "%^CYAN%^Every wall of this room is covered "+
		"with hieroglyphic symbols, except for the western wall.  "+
		"An opening on the western wall of this room leads into darkness.%^RESET%^",
		({"floor","Floor"}) : "%^CYAN%^The floor of this room is suprisingly "+
		"well kept.  Inset directly in the center of it is a small, "+
		"%^YELLOW%^golden%^CYAN%^ chest.%^RESET%^",
	 	({"south","southern hieroglyphics","southern symbols","south hieroglyphics",
		"south hieroglyphic","south symbol","south symbols"}) : "%^BOLD%^%^BLACK%^"+
		"The hieroglyphics on this wall potray a disturbing scene.  A man "+
		"stands in darkness and suddenly grabs his chest.  As the scene "+
		"continues a dagger tip is visible peaking through his %^RED%^"+
		"blood soaked%^BOLD%^%^BLACK%^ hands.%^RESET%^",
		({"northern symbols","north","northern hieroglyphics",
		"north hieroglyphics","north hieroglyphic","north symbol",
		"north symbols"}) : "%^BOLD%^%^BLACK%^These hieroglyphics show "+
		"a dark room.  In the next instance %^RED%^red eyes%^BOLD%^"+
		"%^BLACK%^ can be seen peering out from within the darkness.%^RESET%^",
		({"east","eastern symbols","eastern hieroglyphics","east hieroglyphics",
		"east hieroglyphic","east symbol","east symbols"}) : "%^BOLD%^%^BLACK%^"+
		"The hieroglyphics on this wall depict a %^RED%^dark skinned elven"+
		"%^BOLD%^%^BLACK%^ figure, holding two daggers crisscrossed in "+
		"front of his face.  In the next instance he is gone and only "+
		"a dark background remains.%^RESET%^",
		"thick darkness" : "%^BOLD%^%^BLACK%^This thick darkness lingers "+
		"just beyond the opening.  You fear what maybe concealed by it "+
		"as growls echo from deep within.%^RESET%^",
		"opening" : "%^RED%^This opening exits the chamber into thick "+
		"%^BOLD%^%^BLACK%^darkness%^RESET%^%^RED%^.%^RESET%^",
		"darkness" : "%^BOLD%^%^BLACK%^This darkness permeates your being, "+
		"soaking into you, and "+
		"sending chills through your body.%^RESET%^",
		"being" : "%^RED%^Your very being is assaulted by this "+
		"%^BOLD%^%^BLACK%^darkness%^RESET%^%^RED%^.%^RESET%^",
		({"sarcophagus","stone sarcophagus"}) : "%^BOLD%^%^WHITE%^This sarcophagus "+
		"is sealed with a heavy slab.  A %^BOLD%^%^BLACK%^dark skinned"+
		"%^BOLD%^%^WHITE%^ elf has been painted on "+
		"the front of it in exquisite detail"+position2+"  The entire "+
		"sarcophagus is made from a %^RED%^red stone%^BOLD%^%^WHITE%^ "+
		"that has faded over the course of time.%^RESET%^"
	]));
	
}

void create() 
{
	::create();
	set_property("no teleport",1);
	set_property("light",0);
    	set_property("indoors",1);
	set_name("Shaltul's Room");
    	set_short("%^BOLD%^%^WHITE%^Marble Chamber%^RESET%^");
    	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
    	set_smell("default","The stench of decay lingers here.");
    	set_listen("default","Growls can be heard through the door.");
    	set_exits(([
		"opening": KEEPR + "dungeon22",
    	] ));
	set_search("default","Search What?");
	set_search("sarcophagus",(:this_object(),"sarcophagus_search":));
}

int sarcophagus_search()
{
	if(opened == 0) 
	{
		write("The heavy slab covers the sarcophagus, you'll have to first move it!");
		return 1;
	}
	if(found == 0) 
	{
		write("You search the sarcophagus and find a key!");
		new(KEEPO + "shaltulkey")->move(TO);
		found = 1;
		return 1;
	}
	write("You search the sarcophagus but find nothing.");
	return 1;
}

void init() 
{
	::init();
	add_action("lift_fun","lift");
	add_action("lift_fun","slide");
	add_action("seal_function","seal");
}

void do_failure() 
{
	tell_object(TP,"%^RED%^You try to move the heavy slab but "+
	"it is simply too heavy!%^RESET%^");
	if(random(5) == 2) 
	{
		tell_object(TP,"%^RED%^You tried too hard and pull something!%^RESET%^");
		TP->do_damage("torso",roll_dice(1,10));
	}
	if(!TP->query_invis()) 
	{
		tell_room(ETP,TP->query_cap_name() + "%^RED%^ shoves on "+
		"the heavy slab but seems unable to even budge it.%^RESET%^");
	}
}

int seal_function(string str) 
{
	if(!sizeof(passed)) passed = ({});
	if(!sizeof(failed_lift)) failed_lift = ({});
	if(str == "slab" || str == "sarcophagus") 
	{
		if(opened == 0) 
		{
			write("The sarcophagus is already sealed!");
			return 1;
		}
		if(member_array((string)TPQN, failed_lift) != -1)
		{
			do_failure();
			return 1;
		}
		if((int)TP->query_stats("strength") + 1 > random(26) || 
		member_array((string)TPQN, passed) != -1) 
		{
			tell_object(TP,"%^RED%^You shove the heavy slab with all "+
			"your might and manage to seal "+
			"the sarcophagus once again!");
			if(!TP->query_invis()) 
			{
				tell_room(ETP,TP->query_cap_name() + 
				"%^RED%^ seals the sarcophagus!%^RESET%^",TP);
			}
			else 
			{
				tell_room(ETP,"%^RED%^A loud sound echoes through "+
				"the room as the slab covering the "+
				"sarcophagus is slid back into place!%^RESET%^",TP);
			}
			if(member_array((string)TPQN, passed) == -1) 
			{
				passed += ({TPQN});				
			}
			pos = ".";
			pos2 = ", you could try to %^RED%^"+
			"lift%^BOLD%^%^WHITE%^ or %^RED%^shove%^BOLD%^%^WHITE%^ it"+
			".";
			original_setup(pos,pos2);	
			return 1;
		}
		if(member_array((string)TPQN, failed_lift) == -1)
		{
			failed_lift += ({TPQN});
		}
		do_failure();
		return 1;
	}
	return 0;
}

int lift_fun(string str)
{
	if(!sizeof(passed)) passed = ({});
	if(!sizeof(failed_lift)) failed_lift = ({});
	if(str == "slab") 
	{
		if(opened == 1) 
		{
			write("The slab has already been moved!");
			return 1;
		}
		if(member_array((string)TPQN, failed_lift) != -1)
		{
			do_failure();
			return 1;
		}
		if((int)TP->query_stats("strength") + 1 > random(26) 
		|| member_array((string)TPQN, passed) != -1)
		{
			tell_object(TP,"%^RED%^You shove the heavy slab with all "+
			"your might and manage to move it "+
			"enough to see into the sarcophagus.%^RESET%^");
			opened = 1;
			if(member_array((string)TPQN, passed) == -1)
			{
				passed += ({TPQN});
			}
			pos = ", the slab covering it has been shoved slightly to the side.";
			pos2 = ", it has been shoved slightly to the side, revealing "+
			"the inside, you could try to "+
			"%^RED%^seal%^BOLD%^%^WHITE%^ it or maybe even %^RED%^"+
			"search%^BOLD%^%^WHITE%^ it.";
			original_setup(pos,pos2);
			if(!TP->query_invis()) 
			{
				tell_room(ETP,TP->query_cap_name() + 
				"%^RED%^ shoves the slab on the sarcophagus over a "+
				"little.%^RESET%^",TP);
			}	
			else 
			{
				tell_room(ETP,"%^RED%^A loud sound echoes "+
				"through the room as the slab covering the "+
				"sarcophagus is slid slightly out of place!%^RESET%^",TP);
			}
			return 1;
		}
		if(member_array(TPQN, failed_lift) == -1)
		{
			failed_lift += ({TPQN});
		}
		do_failure();
		return 1;
	}
	return 0;	
}


void reset() 
{
	::reset();
  	found = 0;
	opened = 0;
	passed = ({});
	failed_lift = ({});
	pos = ".";
	pos2 = ", you could try to %^RED%^lift%^BOLD%^%^WHITE%^ "+
	"or %^RED%^shove%^BOLD%^%^WHITE%^ it.";
  	original_setup(pos,pos2);    
}
