#include <std.h>
#include "../keep.h"

inherit STAIRWELL;

int revealed;
string original_long;

int original_configuration() 
{
	int x;
	set_long(original_long + "%^BOLD%^%^WHITE%^  The stairwell continues "+
	"sharply upward and downward here.  You may go either direction, "+
	"but you must brave the unknown danger "+
	"of the thick darkness.%^RESET%^");
 	for(x = 0;x < sizeof(LITEMS);x++) 
	{
		add_item(LITEMS[x], "%^BOLD%^%^BLACK%^These symbols depict the "+
		"transformation of what appears to be a %^RED%^dark skinned "+
		"elf%^BOLD%^%^BLACK%^ into an upright wolf-like "+
		"creature.  The various stages of its transformation look "+
		"quite painful as both bone and flesh are manipulated in a "+
		"very unnatural manner.  The author of these symbols paid "+
		"special attention to detail.  An uneasy feeling stirs "+
		"within you.%^RESET%^");
	}
	add_item("walls","%^BOLD%^%^BLACK%^The walls of the stairwell are "+
	"covered with numerous %^CYAN%^hieroglyphic symbols%^BOLD%^%^BLACK%^.  "+
	"The symbols are in strikingly vivid detail.%^RESET%^");
	if(member_array("opening",query_exits())) remove_exit("opening"); 
}

void hide_door() 
{
	revealed = 0;
	tell_room(TO,"%^CYAN%^At the completion of the phrase the missing "+
	"segment of the hieroglyphics appear and conceal the opening!%^RESET%^");
	original_configuration();
}

void do_door() 
{
	int x;
	set_long(TO->query_long() + "  %^BOLD%^%^WHITE%^A segment of the %^CYAN%^"+
	"hieroglyphics%^BOLD%^%^WHITE%^ is missing, revealing an opening to another "+
	"chamber.%^RESET%^");
	tell_room(TO,"%^CYAN%^At the completion of the phrase a section of "+
	"the hieroglyphics vanish, revealing an opening!%^RESET%^");
	revealed = 1;
	add_exit(KEEPR + "shaltul1","opening");
	add_item("walls","%^CYAN%^The walls of the stairwell are covered "+
	"with hieroglyphics, except for a section which host an %^BOLD%^"+
	"%^BLACK%^opening%^CYAN%^ to another chamber.%^RESET%^");
	for(x = 0;x < sizeof(LITEMS);x++) 
	{
 		add_item(LITEMS[x],"%^BOLD%^%^BLACK%^These symbols depict the "+
		"transformation of what appears to be a %^RED%^dark skinned "+
		"elf%^BOLD%^%^BLACK%^ into an upright "+
		"wolf-like creature.  The various stages of its transformation "+
		"look quite painful as both bone and flesh are manipulated "+
		"in a very unnatural manner.  The author of these symbols paid "+
		"special attention to detail.  One of the stages of transformation "+
		"is missing as an opening into another chamber now takes its "+
		"place.  An uneasy feeling stirs within you.%^RESET%^");
	}
	return 1;
}

void create() 
{
	::create();
	original_long = TO->query_long();
	original_configuration();
    	set_exits(([
		"up": KEEPR + "dungeon23","down" : KEEPR + "dungeon21"
    	] ));	
}

void init() 
{
	::init();
	add_action("say_function","say");
}

int say_function(string str) 
{
	int i;
	object *stuff;
	if((string)TP->query("last say") == str) 
	{
		return 0;
	}
	if(strsrch(str,"shaltul eldire") != -1) 
	{
		stuff = TP->all_armour();
		for(i=0;i<sizeof(stuff);i++)
		{
			if(!objectp(stuff[i])) continue;
			if((string)stuff[i]->query_type() == "ring")
			{
				if(member_array("shaltul's ring",stuff[i]->query_id()) != -1)
				{
					if(revealed == 0) 
					{
						call_out("do_door",0,TO);
						return 0;
					}
					call_out("hide_door",0,TO);
					return 0;
					break;
				}
			}
		}
	}
	return 0;
}

void reset() 
{
	::reset();
  	original_configuration();
  	revealed = 0;
}
