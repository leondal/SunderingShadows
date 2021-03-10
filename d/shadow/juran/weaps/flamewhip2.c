#include <std.h>
inherit "/d/common/obj/weapon/whip";

string OWNER;

void init() {
    	::init();
    	if(interactive(TP) && TP==environment(TO) && !OWNER) OWNER = TPQN;
}

void create(){
	::create();
	set_name("whip");
	set_id(({ "whip","flame whip" }));
	set_short("%^BOLD%^%^RED%^Flame Whip%^RESET%^");
	set_obvious_short("whip");
	set_long("%^BOLD%^%^RED%^A garnet encrusted handle holds a curling lash of fire in "
"place.  The handle made from molten %^YELLOW%^gold%^RED%^ that has been cooled into its "
"current shape.  Three bands of garnet are set in place at the crown of the golden handle.  "
"Within the garnets you can see sparks of flames.  Curling out about 8 feet in length, the "
"flames lick and move about in a chaotic dance.%^RESET%^");
	set_value(800);
	set_lore("The Flame Whip is a favored weapon by Balrogs usually, but has found acceptance "
"in the faith of Loviatar and Kossuth as well.");
	set_property("enchantment",4);
	set_item_bonus("attack bonus",2);
	set_item_bonus("damage bonus",2);
	set_wield((:TO,"wield_func":));
      set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
    	if((int)ETO->query_level() < 25) {
    		notify_fail("The whip thrashes angrily and burns you as you try to wield it!");
    		TP->do_damage("torso",random(10)+10);
    		return 0;
    	}
     	if(interactive(TP) && (string)TP->query_name() != OWNER){
			tell_object(TP,"%^BOLD%^%^RED%^The whip does not recognize you "+
				"as its owner and with a painful flash it disappears!");
    		TP->do_damage("torso",random(10)+10);
			TO->remove();
			return 0;
    	}
		tell_room(ETP,"%^BOLD%^%^RED%^The garnet rings start to glow "+
			"as an eight foot lash of dancing flames takes shape "+
			"when "+TPQCN+" wields their whip.",TP);
		tell_object(TP,"%^BOLD%^%^RED%^The garnet rings start to glow "+
			"and an eight foot lash of dancing flames takes shape as you wield the whip.");
		return 1;
}
int unwield_func(){
		tell_room(environment(ETO),"%^BOLD%^%^RED%^The lash of fire recedes "+
			"back into the garnet rings.",ETO);
		tell_object(ETO,"%^BOLD%^%^RED%^The lash of fire recedes back into the garnet rings.");
		return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(random(1000) < 215){
		switch(random(3)){
			case 0:
				tell_room(ETO,"%^ORANGE%^The lash of the "+
					"whip in "+ETO->query_cap_name()+" %^ORANGE%^'s hand "+
					"splits in two, snapping into "+targ->query_cap_name()+" "+
					"%^ORANGE%^twice!",targ);
				tell_object(targ,"%^ORANGE%^The whip in "+ETO->query_cap_name()+""+
					"%^ORANGE%^'s hand splits in two, charring your flesh twice, damn it!");
				return roll_dice(1,4)+1;
			case 1:
   	    	tell_object(targ,"%^RED%^The whip lashes out and entwines you in its flames.\n");
	    		tell_room(ETO,"%^RED%^You feel the heat from the flames as the whip "+
	    			"wraps around "+targ->query_cap_name()+"'s body.\n",targ);
	    		targ->do_damage("torso",roll_dice(2,4));
	    		call_out("burn",5,targ,1);
	    		return random(2);
	    	case 2:
	    		tell_object(targ,"%^RED%^The whip flares wildy washing painful "+
	    			"heat over your exposed flesh!\n");
	    		tell_room(environment(query_wielded()),"%^RED%^The whip flares and fire "+
	    			"washes over "+targ->query_cap_name()+"'s exposed flesh.\n",targ);
				return roll_dice(1,4)+1;
			default:
				return 1;
      }
			
	}
}
void burn(object targ, int time){
 	if(!objectp(targ)) return;
   switch (time) {
   	case 1:
      	tell_object(targ,"%^RED%^The flaming whip has wrapped about you "+
      		"and you feel it burning into you!\n");
      	tell_room(environment(targ),"%^RED%^You see "+targ->query_cap_name()+" "+
      		"writhe in pain as the whip wraps around "+targ->query_possessive()+" "+
      		"body.",targ);
      	targ->do_damage("torso",roll_dice(1,4));
      	if(objectp(targ)) targ->add_attacker(TO);
      	if(objectp(targ)) targ->continue_attack();
      	if(!objectp(targ)) return;
      	call_out("burn",5,targ,2);
      	break;
   	case 2:
      	tell_object(targ,"%^RED%^You feel the fire from the whip burning your flesh.\n");
      	tell_room(environment(targ),"%^RED%^You see "+targ->query_cap_name()+" "+
      		"writhe in pain as the whip burns "+targ->query_possessive()+" body.",targ);
      	targ->do_damage("torso",roll_dice(1,4));
      	if(objectp(targ)) targ->add_attacker(TO);
      	if(objectp(targ)) targ->continue_attack();
      	if(!objectp(targ)) return;
      	call_out("burn",5,targ,3);
      	break;
   	case 3:
      	tell_object(targ,"%^RED%^You feel the fire from the whip burning your flesh.\n");
      	tell_room(environment(targ),"%^RED%^You see "+targ->query_cap_name()+" "+
      		"writhe in pain as the whip burns "+targ->query_possessive()+" body.",targ);
      	targ->do_damage("torso",roll_dice(1,4));
   		if(!objectp(targ)) return;
      	targ->add_attacker(TO);
   		if(!objectp(targ)) return;   
      	targ->continue_attack();
      	break;
   }
}
