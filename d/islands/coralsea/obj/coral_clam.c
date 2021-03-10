#include <std.h>
#include "../defs.h"
inherit OBJECT;

// Coral Sea Area - Created January 2009 by Ari

void init(){
	::init();
		add_action("pry_shell","pry");
}

void create(){
    ::create();
		set_name("clam");
        set_id(({"clam","large clam"}));
		set_short("%^BOLD%^%^WHITE%^a large clam%^RESET%^");
        set_long("%^BOLD%^%^WHITE%^This white clam is about the "+
			"size of a child's hand, making it fairly large as far "+
			"as shellfish go.  It's white exterior is pocked from "+
			"exposure to external elements like the rubble found "+
			"around it.  A faint ridging can be seen along each "+
			"half shell, marking the creature's life cycle.  "+
			"Between the two half shells, the thin ridge of the "+
			"juncture can be seen.  If one had care and tools "+
			"they could probably pry the shell open.");
        set_weight(1000);   
}

int pry_shell(string str){
	object newshell,newpearl,newfood;
	
	if(str != "shell" && str != "clam"){
		tell_object("%^BOLD%^%^WHITE%^Why are you trying to pry "+
			"that open? Maybe you should focus on the "+
			"clam.%^RESET%^");
	return 1;
	}
	
	if(!TP->is_class("thief")){
		newshell = new(OBJ"coral_shell");
			newshell->move(ETP);
		newfood = new(OBJ"coral_meat");
			newfood->move(ETP);;		
		tell_object(ETO,"%^BOLD%^%^WHITE%^You pry open the "+
			"shell scattering what's inside all over the "+
			"place.%^RESET%^");
		TO->move("/d/shadowgate/void");
			TO->remove();
	return 1;
	}
	
	else{
		newshell = new(OBJ"coral_shell");
			newshell->move(ETP);
		newfood = new(OBJ"coral_meat");
			newfood->move(ETP);	
		newpearl = new(OBJ"coral_pearl");
			newpearl->move(ETP);
		tell_object(ETO,"%^BOLD%^%^WHITE%^You take out a few "+
			"tools and carefully pry open the clam shell "+
			"revealing a pearl inside!%^RESET%^");
		tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" takes out "+
			"a few small tools and carefully wedges the shell "+
			"open.%^RESET%^",ETO);
		TO->move("/d/shadowgate/void");
			TO->remove();
	return 1;
	}
}
