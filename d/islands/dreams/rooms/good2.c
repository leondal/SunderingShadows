#include <std.h>
#include "../defs.h"
inherit ROOM;

int FLAG;
void create()
{
  	::create();
   	set_property("no scry",1);
   	set_property("no teleport",1);
   	set_terrain(STONE_BUILDING);
   	set_travel(PAVED_ROAD);
  	set_property("indoors",1);
  	set_property("light",1);
  	set_short("%^BOLD%^%^YELLOW%^A Torture Chamber%^RESET%^");
  	set_long("%^BOLD%^%^BLACK%^As you step out of the portal, you find "+
		"yourself standing in a grimy, dank dungeon.  Shackles line "+
		"the walls, many of them restraining gaunt and weak looking "+
		"humans.  In the center of the room is a stone slab held about "+
		"four feet off the ground.  The slab is covered in %^RESET%^"+
		"%^RED%^dried blood%^BOLD%^%^BLACK%^, giving it a dark red"+
		" color.  Strapped down across the slab is an %^RESET%^elderly"+
		" man%^BOLD%^%^BLACK%^.  You can see his ribs moving, so you"+
		" assume he must have fainted "+
		"from the pain.  The skin covering his torso has been sliced "+
		"down the middle and "+
		"pulled apart, held open by small hooks on the edge of the slab.  "+
		"His rib cage shows, and it looks as if much of the "+
		"muscles covering his stomach have been sliced apart.  Intestines "+
		"have been pulled out, and rest upon his own body.  A few of "+
		"the prisoners notice your sudden appearance, and beg you to "+
		"release them.%^RESET%^");
  	set_smell("default","%^RED%^The metallic smell of fresh blood fills this room.");
  	set_listen("default","%^BOLD%^%^WHITE%^The links of the chain shackles rattle together.");
  	set_property("no sticks",1);
  	set_items(([
    	({"slab","stone slab"}) : "%^RED%^A blood covered stone slab rests "+
		"upon a stone a base.  Small tracks run down along the edges, "+
		"providing a path for the blood to flow down.  A small drain "+
		"is built into the floor at the bottom of the slab.",
    	({"shackles","chains"}) : "%^BOLD%^%^WHITE%^Chain shackles are "+
		"mounted into the stone walls.",
    	"portal" : "%^BLUE%^A blue portal shimmers a few inches above the "+
    	"ground.  It stretches up about 7 feet, and stands a few "+
		"feet wide."
	]));
  	set_exits(([ "blue" : ROOMS+"pedestal.c"]));
}


void init()
{
  	::init();
  		add_action("kill","kill");
}

void kill(string str)
{
	if(FLAG)
    { 
        tell_object(TP,"%^YELLOW%^You have already made your choice.");
	    return 1;
	}
  	if(!str)
    {
        tell_room(TP,"%^BOLD%^%^CYAN%^Will you kill the devil,"+
		    " and free the prisoners, or "+
			"shall you kill the loud mouthed prisoner,"+
			" and get that "+
			"powerful looking glaive?");
    	return 1;
  	}
  	if(str != "prisoner" && str != "devil" && str != "abishai")
    {
    	return;
  	}
  	if(str == "prisoner")
    {
	  //Made it so a new prisoner is cloned if this one is missing 
	  //to prevent bugs - Saide
        if(!present("devil",TO)) { new(MON+"abishai.c")->move(TO); }
        if(!present("prisoner", TO)) { new(MON+"prisoner.c")->move(this_object()); }
		tell_room(TP,"%^RED%^It takes little effort for you to silence the "+
			"annoyingly talkative chained up prisoner for good.");
    		tell_room(ETP,"%^RED%^"+TPQCN+" walks over and easily kills the "+
			"chained up prisoner.",TP);
		TO->set_long("%^BOLD%^%^BLACK%^As you step out of the portal, you find "+
		    "yourself standing in a grimy, dank dungeon.  Shackles line "+
		    "the walls, many of them restraining gaunt and weak looking "+
		    "humans.  In the center of the room is a stone slab held about "+
		    "four feet off the ground.  The slab is covered in %^RESET%^"+
		    "%^RED%^dried blood%^BOLD%^%^BLACK%^, giving it a dark red"+
		    " color. A blue portal shines within the room.\n");
    	remove_action("kill","kill");
    	present("prisoner")->die(TO);
    	TP->add_align_adjust(-10);
    	tell_room(TP,"%^RED%^%^BOLD%^Your actions have"+
			" affected your alignment!");
    	present("black abishai")->force_me("cackle");
    	present("black abishai")->force_me("say %^BOLD%^"+
			"%^RED%^The master "+
			"only said I couldn't kill "+
			"the fool.  He never said I had to protect"+
			" him!  I must thank "+
			"you for your good work, but alas, I grow"+
			" tired of your "+
			"presence.%^RESET%^");
    	present("black abishai")->force_me("kill "+TP->query_name()+"");
   	    FLAG=1;
    	return 1;
    }  
	if(str == "abishai" || str = "devil")
    {
	  //I'm adding this to prevent bugs - who coded this area?  - Saide
	  if(!present("devil",TO)) { new(MON+"abishai.c")->move(TO); }
	  if(!present("prisoner", TO)) { new(MON+"prisoner.c")->move(this_object()); }

		tell_room(TP,"%^BOLD%^%^BLUE%^As you move over to attack the devil, "+
			"the prisoner manages to snatch the keys to the chains"+
			" away, and sets about freeing himself and the others.");
    		tell_room(ETP,"%^BLUE%^%^BOLD%^As "+TPQCN+" moves over to attack the "+
			"devil, the prisoner manages to snatch the keys to the"+
			" chains away"+
			", and sets about freeing himself and the others.",TP);
		TO->set_long("%^BOLD%^%^BLACK%^As you step out of the portal, you find "+
		    "yourself standing in a grimy, dank dungeon.  Shackles line "+
		    "the walls, many of them restraining gaunt and weak looking "+
		    "humans.  In the center of the room is a stone slab held about "+
		    "four feet off the ground.  The slab is covered in %^RESET%^"+
		    "%^RED%^dried blood%^BOLD%^%^BLACK%^, giving it a dark red"+
		    " color. A blue portal shines within the room.\n");
    	present("prisoner")->force_me("cheer");
    	present("prisoner")->force_me("say %^BOLD%^%^CYAN%^"+
			"I shall never forget you "+
			"my friend.  May whatever God you worship"+
		    " bless your soul!");
    	remove_action("kill","kill");
    	TP->add_align_adjust(10);
    	tell_room(TP,"%^YELLOW%^%^BOLD%^Your actions have"+
			" affected your alignment!");
		present("prisoner")->remove(TO);
    	present("black abishai")->force_me("say %^BOLD%^"+
			"%^RED%^YOU FOOL!!!  "+
			"You shall pay for letting them get "+
			"away!%^RESET%^");
    	present("black abishai")->force_me("kill "+TP->query_name()+"");    				
	    FLAG=1; 
 	    return 1;
    }
}

void reset()
{
    ::reset();
	FLAG=0; 
    if(!present("prisoner") && FLAG == 0)
    {
        new(MON+"prisoner.c")->move(this_object());
    }
	return; 
}
