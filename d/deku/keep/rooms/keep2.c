//this file has been changed quite dramatically by me - it was originally created by Kayla
//it now has a door and a unique function - Saide 10/02/03, 11/01/03
#include <std.h>
#include "../keep.h"
#define GAR_ITEMS ({"gargoyle","gargoyles","statue","statues"})
inherit VAULT;
int replaced;
void original_setup() 
{

	set_long("You are standing outside the hulking Tower of Hawk, "+
	"just inside Keep Blacktongue.  To the south are the %^BOLD%^"+
	"%^GREEN%^gates%^RESET%^ leading to the %^GREEN%^forest"+
    	"%^RESET%^ outside.  A massive metal door leads into the tower "+
	"and on either side of the door sits a stone statue, each an "+
	"exact replica of a %^MAGENTA%^gargoyle%^RESET%^.  "+
    	"The tower is four stories high and %^CYAN%^light%^RESET%^ streams "+
	"forth from a window near the top.%^RESET%^");
    	set_items(( [ 
    		({"gargoyle","gargoyles","statue",
		"statues"}) : "%^MAGENTA%^These massive statues are made "+
    		"from solid stone and each has been carved into the "+
		"perfect likeness of a gargoyle.  The "+
    		"gargoyle to the left of the door has two %^RED%^"+
		"ruby%^MAGENTA%^ eyes.  The gargoyle to "+
    		"the right of the door carries an oddly shaped skull "+
		"in one of its clawed hands.  It has "+
    		"one %^BOLD%^%^GREEN%^emerald%^RESET%^%^MAGENTA%^ eye, "+
		"the other is missing, you could "+
    		"probably %^BOLD%^%^GREEN%^replace%^RESET%^%^MAGENTA%^ "+
		"it with something.  Like faithful "+
    		"sentries these statues stand watch over the tower.%^RESET%^",
    		({"gate","gates"}) : "%^BOLD%^%^GREEN%^These gates are "+
		"slightly to the south of you, they "+
		"are massive and made from some type of heavy wood.%^RESET%^",
    		({"light"}) : "%^YELLOW%^This light is streaming forth from "+
		"a window near the top of this massive tower.%^RESET%^",
		({"tower"}) : "%^BOLD%^%^WHITE%^This tower shoots some "+
		"40' into the air, it is made from a "+
    		"%^BOLD%^%^BLACK%^black brick%^BOLD%^%^WHITE%^ and has "+
		"several windows inset into it on every story.%^RESET%^",
		({"window","windows"}) : "%^BOLD%^%^WHITE%^There are several "+
		"windows on each story of the tower, they vary in size and "+
		"shape and position on the tower.%^RESET%^",
		({"forest"}) : "%^GREEN%^This forest is south of you, it "+
		"stretches across the horizon as "+
		"far as the eye can see.%^RESET%^",
    	] ));
    	replaced = 0;
}

void create() 
{
	::create();
    	original_setup();
    	set_property("light",2);
    	set_property("indoors",0);
    	set_name("keep blacktongue");
    	set_short("%^YELLOW%^Keep Blacktongue%^RESET%^");
    	set_terrain(VILLAGE);
    	set_travel(PAVED_ROAD);
    	set_listen("default","An occassional shout echoes through the keep.");
    	set_smell("default","An odor of death hangs heavily in the air.");
    	set_exits(([
       "south" : KEEPR + "keep1",
       "north" : KEEPR + "tower1"
    	] ));
    	set_door("tower door",KEEPR + "tower1", "north");
    	set_door_description("tower door","This door is made from a "+
	"%^BOLD%^%^WHITE%^gray%^RESET%^metal.  An image of a "+
	"%^RED%^red hawk%^RESET%^ in front of a %^BOLD%^%^BLACK%^black"+
    	"%^RESET%^ background is set into the front of it.%^RESET%^");
}

void init() 
{
    ::init();
    add_action("function_1","replace");
}

int function_1(string str) 
{
	object ob;
    	int x;
    	if(replaced == 1) { return 0; }
    	if(!str) 
	{
      	write("Try replacing the eye?\n");
        	return 1;
	}
    	if(str != "eye") 
	{
      	write("Try replacing the eye?\n");
        	return 1;
    	}
    	if(!present("emerald eye",TP)) 
	{
      	write("You having nothing that fits the socket.\n");
        	return 1;
    	}
    	if((ob = present("emerald eye",TP))) 
	{
      	ob->remove();
        	replaced = 1;
        	tell_object(TP,"%^RED%^You carefully replace the "+
		"%^BOLD%^%^GREEN%^emerald%^RESET%^%^RED%^ "+
        	"eye of the right gargoyle.%^RESET%^");
        	if(!TP->query_invis()) 
		{
            	tell_room(ETP,TPQCN + "%^RED%^ replaces the "+
			"%^BOLD%^%^GREEN%^emerald%^RESET%^"+
            	"%^RED%^ eye of the right gargoyle.%^RESET%^",TP);
        	}
        	for(x = 0;x < sizeof(GAR_ITEMS);x++) 
		{
            	add_item(GAR_ITEMS[x],"%^MAGENTA%^These massive statues "+
			"are made from solid stone and each "+
            	"has been carved into the perfect likeness of "+
			"a gargoyle.  The gargoyle to the left of the "+
            	"door has two %^RED%^ruby%^MAGENTA%^ eyes.  The "+
			"gargoyle to the right of the door carries "+
            	"an oddly shaped skull in one of its clawed hands.  "+
			"It has two %^BOLD%^%^GREEN%^"+
            	"emerald%^RESET%^%^MAGENTA%^ eyes.  Like faithful "+
			"sentries these statues stand watch over "+
            	"the tower.%^RESET%^");
        	}

        	remove_action("function_1","replace");
        	call_out("do_living_gargoyle",0,TP,0);  
        	return 1;
    	}
    	return 1;
}

void do_living_gargoyle(object tp,int timer) 
{
	int x;
    	switch(timer) 
	{
      	case(1):
            	tell_room(ETP,"%^BOLD%^%^WHITE%^The gargoyle to the "+
			"right of the door begins to move!%^RESET%^");
            	break;
        	case(3):
            	tell_room(ETP,"%^RED%^The gargoyle comes completely to life!%^RESET%^");
            	set_long("You are standing outside the hulking "+
			"Tower of Hawk, just inside Keep Blacktongue.  "+
            	"To the south are the %^BOLD%^%^GREEN%^gates%^RESET%^ "+
			"leading to the %^GREEN%^forest"+
            	"%^RESET%^ outside.  A massive metal door leads into the "+
			"tower and a stone statue, an exact "+
            	"replica of a %^MAGENTA%^gargoyle%^RESET%^, sits to the "+
			"left of the door.  The tower is "+
            	"four stories high and %^CYAN%^light%^RESET%^ streams "+
			"forth from a window near the "+
            	"top.%^RESET%^");
	        	for(x = 0;x < sizeof(GAR_ITEMS);x++) 
			{
                		add_item(GAR_ITEMS[x],"%^MAGENTA%^This massive "+
				"statue rests to the left of the door and is "+
                		"made from solid stone and has been carved into "+
				"the perfect likeness of a gargoyle.  It has "+
                		"two %^RED%^ruby%^MAGENTA%^ eyes.  Like a faithful "+
				"sentry this statue stands watch over "+
                		"the tower.%^RESET%^");
	        	}	
		    	new(KEEPM + "gargoyle")->move(TO);
		    	break;
	}
    	if(timer < 4) 
	{
      	timer++;
        	call_out("do_living_gargoyle",0,TP,timer);
        	return;
    	}
    	return;
}

void reset() 
{
	int x;
    	::reset();
    	if(!present("gargoyle")) 
	{
      	original_setup();
	}
    	if(!present("klieutenant") && random(3) != 2) 
	{
      	new(KEEPM + "keep_lieu")->move(TO);
    	}
    	if(!present("kguard") && random(3) != 2) 
	{
      	for(x = 0; x < random(2) + 1;x++) 
		{
            	new(KEEPM + "keep_guard")->move(TO);
        	}
    	}
}
