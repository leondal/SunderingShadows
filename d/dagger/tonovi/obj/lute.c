#include <std.h>
#include <daemons.h>

inherit OBJECT;

void init(){
    ::init();
    add_action("calm", "calm");
}

void create(){
    ::create();
    set_name("Bard's lute");
    set_id( ({"lute", "bard's lute", "wooden lute", "instrument"}) );
    set_short("wooden lute");
    set_long(
      "This lute was crafted by the master craftsmen of the bards guild.  Made for bards, it is of a family of instruments that are said to have special powers.  This one is said to be able to calm the most savage beast."
    );
    set_value(300);
    set_weight(5);
}


int calm(string str){
    object targ, *inv;
    int i, num, align;

    if(!TP->is_class("bard"))
	return notify_fail("Only bards may calm people.\n");

    if(!str)
	return notify_fail("Syntax: calm <what>\n");

    if(!(targ = present(str,ETP)))
	return notify_fail("That is not here!\n");

    if(!living(targ))
	return notify_fail("You may only calm living objects.\n");

    align = TP->query_alignment();
    if(align==1 || align==3 || align==7 || align==9){
	notify_fail("You cannot use your bard skills unless you are of a neutral alignment!\n");
	return 0;
    }
    if(targ == TP)
	return notify_fail("That's cheating.\n");

    if((object *)targ->query_attackers()==({}))
	return notify_fail("That does not need calming!\n");

    if(pointerp(targ->query_property("calmed") )&& member_array(TP,targ->query_property("calmed")) != -1){
	tell_object(targ,"%^BOLD%^"+TPQCN+" is trying to calm you again.");
	write("You can't try to calm a creature you have failed upon.");
	if(!interactive(targ))
	    targ->kill_ob(TP,1);
	return 1;

    }

    tell_object(TP, "%^BOLD%^You begin to play your lute in an attempt to calm "+targ->query_cap_name()+".\n");
    tell_object(targ,"%^BOLD%^You feel a sense of strangeness come over you as "+TPQCN+" looks at you.\n");
    num = (int)(targ->query_level()) - (int)(TP->query_level());
    num -= 3;
    TP->set_paralyzed(8,"You are still calming "+targ->query_cap_name());
    if(!SAVING_D->saving_throw(targ, "paralyzation_poison_death",num)){
	tell_object(TP,"%^BOLD%^%^GREEN%^You see a transformation take place in "+targ->query_cap_name()+" as "+targ->query_subjective()+" calms down.\n");
	tell_object(targ,"%^BOLD%^%^GREEN%^You suddenly feel calm as you cease your fighting.\n");
	targ->cease_all_attacks();
	inv = all_inventory(environment(targ));
	for(i = 0;i<sizeof(inv);i++){
	    if(!living(inv[i])) continue;
	      if(targ == inv[i]) continue;
		inv[i]->remove_attacker(targ);
	    }
	      targ->set("aggressive",0);
	  }
	    else{
		tell_object(TP,"%^BOLD%^%^BLUE%^You fail to calm "+targ->query_cap_name()+" and "+targ->query_subjective()+" rushes at you angrily!\n");
		tell_object(targ,"%^BOLD%^%^BLUE%^You feel more like yourself again and glare at "+TPQCN+" angrily as you attack "+targ->query_objective()+"!\n");
		targ->set_property("calmed",({TP}));
		if(!interactive(targ) && !targ->query_paralyzed()){
		    targ->kill_ob(TP);
		    tell_room(ETP,"%^BOLD%^%^BLUE%^You see "+targ->query_cap_name()+" start to berserk.");
		    targ->execute_attack();
		    targ->execute_attack();
		}

	    }

	    return 1;
	}

int is_instrument(){return 1;}