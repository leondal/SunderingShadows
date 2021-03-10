#include <std.h>
#include "../defs.h"
inherit ROOM;
int FLAG;
void create()
{
  	::create();
   	set_terrain(BARREN);
   	set_travel(FOOT_PATH);
   	set_property("no teleport",1);
   	set_property("no scry",1);
  	set_property("indoors",1);
  	set_property("light",2);
  	set_short("%^BOLD%^%^BLUE%^Among the Dead%^RESET%^");
  	set_long("%^BLUE%^%^BOLD%^You open your eyes and look around..."+
		"only to shut them just as fast.  As they slowly open again, you "+
		"find yourself standing on %^RED%^bloody%^BLUE%^, deformed"+
		" bodies.  As far as you "
		"can see, bodies are writhing, twisting in agony.  They cry out "+
		"for help.  You look down at your feet, and it seems as if they "+
		"have been melded into one, solid mass.  As you scan the area "+
		"around you, you are startled to find out you recognize some of "+
		"the faces.  A girl you once knew as a child calls out your name.  "+
		"Her voice somehow stands out over the din of the moaning souls.  "+
		"The back of her head has melted into the shoulder of an elderly "+
		"man.  He seems to notice her excitement, and jerks his body so "+
   		"that it snaps the girl's head back and forth, shaking her violently.  "+
		"A %^BLACK%^shadow%^BLUE%^ quickly descends upon the girl as"+
		" she screams out your "+
		"name again, begging you to free her.  The shadow's %^RED%^glowing red "+
		"eyes %^BLUE%^suddenly flare, and the girl writhes in agony.  "+
		"Her once pretty face begins to melt, the flesh dripping down her "+
		"cheek.  The shadow quickly lifts off, and hovers over the bodies, "+
		"keeping close eyes upon them.  Tears stream down the girl's horribly "+
		"scarred face, but despite her pain she does not make a sound...her lips "+
		"have melted together, sealing her mouth shut.  But her tear filled "+
		"eyes seem to fix on yours, begging you to free her.  Suddenly you "+
		"recognize the girl as a child who had tormented you with cruel "+
		"remarks.  Surely it was just childish teasing, but you feel a "+
		"twinge of anger towards the poor girl.  Do you %^CYAN%^free the "+
		"girl%^BLUE%^ or %^CYAN%^ignore the girl%^BLUE%^?\n");
  	set_smell("default","%^BOLD%^%^GREEN%^Putrid, rotting flesh makes your stomach turn.");
  	set_listen("default","%^YELLOW%^The tortured souls wail in a chorus of agony.");
  	set_property("no sticks",1);
  	set_items(([
    		"girl" : "%^MAGENTA%^The girl has fixed her tear filled eyes upon yours.  "+
			"Her deformed face has turned a light shade of pink.  Oddly, "+
			"there is not really any blood.  She notices you staring at her, "+
			"and a helpless, pleading look crosses whats left of her face.  "+
			"There must be something you can do to free her.",
    		"portal" : "%^YELLOW%^A yellow portal shimmers a few inches above the "+
    			"ground.  It stretches up about 7 feet, and stands a few "+
			"feet wide."
	]));
  	set_exits( (["yellow" : ROOMS+"pedestal.c"]));
}

int found = 0;

void init()
{
  	::init();
  		add_action("free","free");
  		add_action("ignore","ignore");
}

void free(string str)
{
    if(!str)
    {
        tell_room(TP,"And what exactly are you trying to free?");
        return 1;
    }
    if(FLAG)
    { 
        tell_object(TP,"%^YELLOW%^You have already made your choice"); 
	    return 1; 
    }

    if(str != "the girl" && str != "girl")
    {
        tell_room(TP,"You don't think you could free anything like that.");
        return 1;
    }
    
    if((str == "girl" && found == 0) || (str == "the girl" && found == 0))
    {
  	    tell_room(TP,"%^CYAN%^As you move towards the poor girl, a shadow's gaze "+
   		    "fixes upon you.  Its %^RED%^eyes flare%^CYAN%^ brightly, "+
		    "and a sudden force knocks you back a few steps.  In a flash, "+
   		    "the shadow seizes the young girl's head.  It rips her from the "+
		    "moving mass, causing her eyes to bulge, and those poor souls "+
		    "that were connected with her to scream in agony.  The shadow's "+
   		    "gaze again falls upon you, as it rips the girl's mutated body "+
		    "apart.  It drops the %^BOLD%^%^RED%^bloody, torn body%^RESET%^ "+
		    "%^CYAN%^to the ground, and rushes towards you.");
    	tell_room(ETP,"%^CYAN%^"+TPQCN+" heads towards a little girl, but is suddenly "+
		    "knocked back a few steps by some invisible force.  A shadow swoops "+
		    "down from above, and rips the little girl from the mass of bodies.  "+
		    "Those who where melded with the little girl scream in agony, as "+
   		    "their flesh is ripped away.  The young girl's eyes bulge in terror "+
		    "and pain.  The shadow seems to stare at "+TPQCN+" while it rips "+
   		    "the girl's body apart.  It drops what is left of the %^BOLD%^%^RED%^"+
		    "bloody, torn body%^RESET%^%^CYAN%^ to the ground, and then rushes"+
		    " towards "+TPQCN+".",TP);
        TO->set_long("%^BLUE%^%^BOLD%^You open your eyes and look around..."+
	        "only to shut them just as fast.  As they slowly open again, you "+
	        "find yourself standing on bloody, deformed bodies.  As far as you "
	        "can see, bodies are writhing, twisting in agony.  They cry out "+
	        "for help.  You look down at your feet, and it seems as if they "+
	        "have been melded into one, solid mass.  The corpse of a young, "+
	        "mutated girl lies atop several of the bodies.  %^RED%^Blood%^BLUE%^ "+
	        "leaks from her torn body, dripping down the wailing faces.  You "+
	        "shake your head in disgust at the scene before you.");
        add_item(({"girl"}),"%^MAGENTA%^Not much you can do for her now that she is dead.");
		found = 1; 
    	new(MON+"sbeast.c")->move(this_object());
    	present("shadow beast")->force_me("kill "+TP->query_name()+"");
    	TP->add_align_adjust(10);
    	tell_room(TP,"%^YELLOW%^%^BOLD%^Your actions have affected your "+
			"alignment!");
	    FLAG=1;
    	return 1;
    }
    if((str == "girl" && found == 1) || (str == "the girl" && found == 1))
    {
        tell_room(TP,"There is nothing you can do for the poor girl now.");
        return 1;
    }
}

void ignore(string str)
{
    if(!str)
    {
        tell_room(TP,"And who exactly are you trying to ignore?");
        return 1;
    }
    if(str != "the girl" && str != "girl")
    {
        return;
    }
	if(FLAG)
    { 
        tell_object(TP,"%^YELLOW%^You have already made your choice"); 
	    return 1; 
    }
    if((str == "girl" && found == 0) || (str == "the girl" && found == 0))
    {

    	tell_room(TP,"As you look away from poor girl, she begins to "+
		    "squirm about in the living mass.  A %^BOLD%^%^BLACK%^shadow's"+
		    "%^RESET%^ gaze "+
   		    "fixes upon you.  Its %^RED%^eyes flare%^RESET%^ brightly, "+
		    "and a sudden force knocks you back a few steps.  In a flash, "+
   		    "the %^BOLD%^%^BLACK%^shadow%^RESET%^ seizes the young girl's"+
		    " head.  It rips her from the "+
		    "moving mass, causing her eyes to bulge, and those poor souls "+
		    "that were connected with her to scream in agony.  The "+
		    "%^BOLD%^%^BLACK%^shadow's%^RESET%^ "+
   		    "gaze again falls upon you, as it rips the girl's mutated body "+
		    "apart.  It drops the %^BOLD%^%^RED%^bloody%^RESET%^, torn body "+
		    "to the ground, and rushes towards you.");
        tell_room(ETP,"%^GREEN%^"+TPQCN+" looks away from a little girl, who begins to "+
		    "writhe about in the living mass, drawing the attention of a "+
		    "huge shadow.  The shadow swoops "+
		    "down from above, and rips the little girl from the mass of bodies.  "+
		    "Those who where melded with the little girl scream in agony, as "+
   		    "their flesh is ripped away.  The young girl's eyes bulge in terror "+
		    "and pain.  The shadow seems to stare at "+TPQCN+" while it rips "+
   		    "the girl's body apart.  It drops what is left of the %^BOLD%^%^RED%^"+
		    "bloody, torn body%^RESET%^%^GREEN%^ to the ground, and then "+
		    "rushes towards "+TPQCN+".",TP);
    	TO->set_long("%^BLUE%^%^BOLD%^You open your eyes and look around..."+
		    "only to shut them just as fast.  As they slowly open again, you "+
		    "find yourself standing on bloody, deformed bodies.  As far as you "
		    "can see, bodies are writhing, twisting in agony.  They cry out "+
		    "for help.  You look down at your feet, and it seems as if they "+
		    "have been melded into one, solid mass.  The corpse of a young, "+
		    "mutated girl lies atop several of the bodies.  %^RED%^Blood%^BLUE%^ "+
		    "leaks from her torn body, dripping down the wailing faces.  You "+
		    "shake your head in disgust at the scene before you.");
    	found = 1;
        remove_item("girl");
		add_item(({"girl"}),"%^MAGENTA%^Not much you can do for her "+
			"now that she is dead."); 
    	new(MON+"sbeast.c")->move(this_object());
    	present("shadow beast")->force_me("kill "+TP->query_name()+"");
    	TP->add_align_adjust(-10);
    	tell_room(TP,"%^RED%^%^BOLD%^Your actions have affected your "+
			"alignment!");
	    FLAG=1;
    	return 1;
    }
    if((str == "girl" && found == 1) || (str == "the girl" && found == 1))
    {
        tell_room(TP,"Is there really a point in ignoring a dead girl?");
        return 1;
    }
}

void reset() 
{ 
	::reset(); 
	FLAG=0; 
	return; 
}
