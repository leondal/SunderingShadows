#include <std.h>
inherit OBJECT;
void create() {
    ::create();
    set_name("manuscript");
    set("id",({"manuscript","ancient manuscript"}));
    set("short",
      "Ancient Manuscript"
    );
    set_long(
      "It is an ancient manuscript, bound by a wax seal.  It bears the symbol of Armageddon!"
    );
    set_value(100);
    set_weight(10);
    set_property("enchantment",1);
}
void init(){
    ::init();
    add_action("break_func","break");
}
int break_func(string str) {
    object here,targ,*players;
    object ob;
    int x,num_p,dam;
    if(!str) {
	notify_fail("Break what?\n");
	return 0;
    }
    if(str != "seal") {
	notify_fail("Break what?\n");
	return 0;
    }
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
    if((int)TP->query_level() < 25) {
	notify_fail("You think better of it\n");
	return 0;
    }
    write("%^BOLD%^%^BLUE%^You snap the wax seal and the manuscript flies open!\n"
      "%^CYAN%^The wind picks up and becomes violent!\n"
      "%^BOLD%^%^RED%^The skies above you darken, and begin to glow with the fiery fury of the ancient forces of supreme evil!\n"
      "%^RESET%^%^BOLD%^A horrible flash of white light, and a fireball of immense power rip through the room!\n"
      "%^RESET%^%^MAGENTA%^The sounds of those poor souls screaming around you makes you shudder, but you seem safe amidst the gruesome scene!"
    );
    say(
      "%^BLUE%^"+TPQCN+" pulls out an ancient manuscript bound by a wax seal.\n"
      "%^BOLD%^%^BLUE%^They snap the seal in two!\n"
      "%^CYAN%^The wind picks up and becomes violent!\n"
      "%^BOLD%^%^RED%^The skies above you darken, and begin to glow with the fiery fury of the ancient forces of supreme evil!\n"
      "%^RESET%^%^BOLD%^A horrible flash of white light, and a fireball of immense power rip through the room!\n"
      ,TP);
    message("broadcast","%^BOLD%^%^BLUE%^The Reaper of Death rips past you heeding "+TPQCN+" as a weapon of awesome destructive power is released upon the world.",users());
    if(!(userp(environment(TO)))) {
	return 0;
    }
    here=environment(environment(TO));
    players=all_inventory(here);
    num_p=sizeof(players);
    for (x=0;x<num_p;x++) {
	targ=players[x];
	ob=targ;
	if((living(targ)) && targ !=this_player()) {
	    if ("daemon/saving_d"->saving_throw(ob,"rod_staff_wand")){
		dam=250+random((int)TP->query_level()/2);
		ob->do_damage("head",(dam));
	    } else {
		dam=500+random((int)TP->query_level());
		ob->do_damage("head",(dam));
	    }
	    if(!ob->kill_ob(TP,0)) TP->kill_ob(ob,0);
	    tell_object(TP,
	      "%^RED%^The flesh is torn away from "
	      +ob->query_cap_name()+"'s body!%^RESET%^"
	    );
	    tell_object(ob,
	      "%^BOLD%^%^RED%^You feel tremendous pain as the flesh is torn from your body!%^RESET%^"
	    );
	    ob->set_paralyzed(dam,"%^MAGENTA%^You look down upon your burning corpse from above.  A silvery thread still binds your soul to your shattered body!"
	      "%^RESET%^");
	}
    }
    TO->remove();
    return 1;
}
