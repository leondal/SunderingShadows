#include <std.h>
#include "../defs.h"
inherit ROOM;
int FLAG;
void create()
{
	::create();
   	set_terrain(WOOD_BUILDING);
   	set_travel(PAVED_ROAD);
  	set_property("indoors",1);
   	set_property("no scry",1);
   	set_property("no teleport",1);
  	set_property("light",2);
  	set_short("%^BOLD%^%^RED%^An Inferno%^RESET%^");
  	set_long("%^BOLD%^%^RED%^As you come out of the portal "+
   		"you are immediately blasted by intense heat.  Flames "+
		"dance madly all around you, and a thick cloud of "+
		"%^BLACK%^smoke%^RED%^ is hovering just overhead."+
		"  The roof looks as "+
		"if it is about to give any moment now.  Your only "+
		"escape is through the red portal.  "+
		"As you begin to turn back to the portal, the sharp "+
		"cry of a baby rings out over the crackling flames.  "+
		"You see a %^BLUE%^small baby%^RED%^ laying in a crib is dangerously"+
		" close to the flames.  As you look around, you also notice a "+
   		"jewel encrusted %^YELLOW%^scepter%^RED%^ housed in a "+
		" broken glass case.  It hums "+
		"softly as you stare at it, radiating sheer power.  "+
		"Suddenly the roof shifts, and you realize you only "+
		"have moments before the roof collapses on top of you.  "+
		"You only have time to grab one thing before you jump "+
		"out the window.  Do you %^CYAN%^rescue the baby "+
   		"%^RED%^or %^CYAN%^grab the scepter%^RED%^?%^RESET%^\n");
    	set_smell("default","%^BOLD%^%^BLACK%^You choke as smoke fills your lungs.");
  	set_listen("default","%^RED%^The fire crackles and roars all around "+
		"you.");
  	set_items(
    	([
   	    "scepter" : "%^YELLOW%^Several gems adorn the hilt of this golden "+
   		"scepter.  Each one looks expensive on their own, put "+
		"together they make this item priceless, even without "+
		"the powerful magics it must hold.  It is humming "+
		"loudly, its power almost bursting out.",
    	"baby" : "%^BOLD%^%^CYAN%^A poor child lays in a bundle of blankets.  "+
		"Smoke rises off the wooden crib, as if ready to burst into "+
		"flames at any moment.",
    	"portal" : "%^RED%^A red portal shimmers a few inches above the "+
    		"ground.  It stretches up about 7 feet, and stands a few "+
		"feet wide."
	]));
  	set_exits( 
    	([
       "red" : ROOMS+"pedestal.c"
    	]));
}
   

void init()
{
  	::init();
  	add_action("rescue","rescue");
	add_action("grab","grab");
}

int rescue(string str)
{
    if(str != "baby" && str != "the baby")
    {
        return notify_fail("Try rescue baby\n");
    }
	if(FLAG)
    {   tell_object(TP,"%^YELLOW%^You have already"+
		    " made your choice."); 
	    return 1; 
    }
    tell_object(TP,"%^YELLOW%^As you move to grab the baby,"+
	    " the fire around you parts as an efreeti steps forward.");
    tell_room(ETP,"%^YELLOW%^"+TPQCN+" moves towards the baby, but"+
		" the fire around you suddenly parts as an efreeti emerges!",TP);
	TO->set_long("%^BOLD%^%^RED%^As you come out of the portal "+
   	    "you are immediately blasted by intense heat.  Flames "+
		"dance madly all around you, and a thick cloud of "+
		"%^BLACK%^smoke%^RED%^ is hovering just overhead."+
		"  The roof looks as "+
		"if it is about to give any moment now.  Your only "+
		"escape is through the red portal.\n");
    TP->add_align_adjust(10);
    tell_object(TP,"%^YELLOW%^%^BOLD%^Your actions have "+
		"affected your alignment!");
    new(MON+"efreeti")->move(TO);
    present("efreeti")->force_me("kill "+TP->query_name()+"");
    FLAG=1;
	return 1; 
}

int grab(string str)
{
	if(str == "scepter" && str == "the scepter")
    {
	    return notify_fail("%^BOLD%^%^CYAN%^Try grab scepter\n");
    }
	if(FLAG)
    { 
        tell_object(TP,"%^YELLOW%^You already have made your"+
		    " choice."); 
	    return 1; 
    }
	tell_object(TP,"%^YELLOW%^As you move to grab the scepter, the "+
		"fire around you seems part as an efreeti steps forward!");
	tell_room(ETP,"%^YELLOW%^"+TPQCN+" moves towards the scepter, but the fire "+
		"around you suddenly parts and an efreeti emerges!",TP);
	TO->set_long("%^BOLD%^%^RED%^As you come out of the portal "+
   		"you are immediately blasted by intense heat.  Flames "+
		"dance madly all around you, and a thick cloud of "+
		"%^BLACK%^smoke%^RED%^ is hovering just overhead."+
		"  The roof looks as "+
		"if it is about to give any moment now.  Your only "+
		"escape is through the red portal.\n");
    TP->add_align_adjust(-10);
    tell_object(TP,"%^RED%^%^BOLD%^Your actions have affected your "+
		"alignment!");
    new(MON+"efreeti")->move(TO);
    present("efreeti")->force_me("kill "+TP->query_name()+"");
    FLAG=1;
	return 1;
}

void reset() 
{ 
    ::reset(); 
    if(FLAG) { FLAG=0; }
	return; 
}
