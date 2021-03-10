//Updated with tp proof querying, and minor code updates - Octothorpe 12/15/09

#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("%^BOLD%^%^GREEN%^Sphere of the Cosmos%^RESET%^");
    set_id(({"sphere","sphere of the cosmos","cosmos sphere"}));
    set_short("%^RESET%^%^GREEN%^Sphere of the Cosmos%^RESET%^");
    set_obvious_short("%^RESET%^%^GREEN%^glass sphere%^RESET%^");
    set_long("%^RESET%^%^GREEN%^This is a perfectly smooth glass-like "+
	   "sphere.  It appears to contain a %^MAGENTA%^purplish %^GREEN%^"+
	   "smokey substance. Although it is made of a very strong "+
	   "substance, it may be possible to smash it against a hard "+
	   "enough surface.%^RESET%^");
    set_weight(1);
    set_value(1000);
}

void init() {
    ::init();
    add_action("break_func","smash");
}
int break_func(string str) {
    if( !str || str != "sphere") {
	   tell_object(ETO,"%^BOLD%^Smash what?%^RESET%^");
       return 0;
    }
    if(TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }
    if(TP->query_paralyzed()) {
	   return notify_fail(TP->query_paralyze_message()+"\n");
	}
    if(ETP->query_property("no teleport")) {
       tell_object(TP,"%^MAGENTA%^You smash the sphere and become "+
		  "enveloped in an alluring fog...and...nothing happens.  "+
		  "%^RED%^Shit.%^RESET%^");
	   tell_room(ETP,"%^BOLD%^"+TP->QCN+" smashes a sphere on the "+
		  "ground, and looks foolish as "+TP->QS+" remains standing "+
		  "in a cloud of %^RESET%^%^MAGENTA%^purple %^BOLD%^"+
		  "%^WHITE%^smoke!%^RESET%^",TP);	 
       TO->remove();		  
       return 1;
    }
    if(ETP->query_property("teleport proof")){
	   if((int)ETP->query_property("teleport proof") > (random(10)+60)){
	      tell_object(TP,"%^MAGENTA%^You smash the sphere and become "+
		     "enveloped in an alluring fog...and...nothing happens.  "+
			 "%^RED%^Shit.%^RESET%^");
		  tell_room(ETP,"%^BOLD%^"+TP->QCN+" smashes a sphere on the "+
		     "ground, and looks foolish as "+TP->QS+" remains standing "+
			 "in a cloud of %^RESET%^%^MAGENTA%^purple %^BOLD%^"+
			 "%^WHITE%^smoke!%^RESET%^",TP);
		  TO->remove();
          return 1;
	   }
	}	   
    tell_object(TP,"%^MAGENTA%^You smash the sphere and become "+
	   "enveloped in an alluring fog!\nAs the fog dissipates you "+
	   "realize have been magically teleported elsewhere!%^RESET%^");
    tell_room(ETP,"%^BOLD%^"+TP->QCN+" smashes a sphere on the ground "+
	   "and vanishes in a cloud of %^RESET%^%^MAGENTA%^purple %^BOLD%^"+
	   "%^WHITE%^smoke!%^RESET%^",TP);
    TP->move_player("/d/tharis/barrow/rooms/bd10.c");
    if((string)TPQN != "grazzt") TO->remove();
    return 1;
}

int isMagic(){ return 1; }
