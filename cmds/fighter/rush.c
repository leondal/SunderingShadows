//_rush.c
/*
 *This cmd is a fighter command designed around the fighter
 *Throwing all his/her weight behind a all out rush toward an enemy
 *its success depends totally on surprising the victim. So can only 
 *be used every now and then. 
 */
 
#include <std.h>

inherit DAEMON;


void cmd_rush(string str){
	
	object ob, *weapon;
	int damage;
	
	if(!str)
		return notify_fail("You need to specify a target!\n");
	
	if((string)TP->query_class() != "fighter")
		return notify_fail("You haven't the skill to try this attack!\n");
	

  	
	if(!(ob = present(str,ETP)))
		return notify_fail("Your target is not in range!\n");
	
	
 	if(!this_player()->ok_to_kill(ob)) {     

		notify_fail("Supernatural forces prevent your attack.\n");
		return 0;
	}
	
  	if(ETP->query_property("no kill")){
      	notify_fail("Supernatural forces prevent your attack.\n");
		return 0;
  	}
  	
    if(ob->query_property("no rush")) {
    notify_fail("This being would never let it's defense down enough for you to do that!\n");
        return 0;
}
  	if(pointerp(TP->query_property("rushed")))
		if(member_array(ob,TP->query_property("rushed") ) != -1)
			return notify_fail("Your target may still be ready for that attack!\n");
	weapon = TP->query_wielded();
	if((weapon == ({})))
		return notify_fail("This attack is useless without weapons!\n");
	
	write("%^BOLD%^You break from combat and then rush weapon first into "+
		ob->query_cap_name()+"!");
	
	tell_room(ETP,"%^BOLD%^You see "+TPQCN+" break from combat and suddenly "+
		"rushes madly into "+ob->query_cap_name()+"!",({TP,ob}));
	
	tell_object(ob,"%^BOLD%^You see "+TPQCN+" break from combat and suddenly "+
		"rushes madly into you!\n");
	
	TP->set_property("rushed",({ob}));
	ob->kill_ob(TP,1);
	TP->kill_ob(ob,1);
	if((int)TP->Thaco(0,ob,weapon[0]) <= roll_dice(1,20)){
		
		if((int)ob->query_size() <3)
	    	damage = weapon[0]->query_damage(); 
	 	else
	    	damage = weapon[0]->query_large_damage();
	    		
	  	damage += TP->get_damage(weapon[0]);
	  	
	  	damage += "/daemon/bonus_d"->damage_bonus(TP->query_stats("strength"));
	  	
	  	damage = damage * (((int)TP->query_level()/6)+1);

	  	write("%^BOLD%^You successfully slam your weapon with all your weight behind it into "+ob->query_cap_name()+"!");
	  	tell_room(ETP,"%^BOLD%^"+TPQCN+" slams full force into "+ob->query_cap_name()+"!",({ob,TP}));
	  	tell_object(ob,"%^BOLD%^"+TPQCN+" slams full force into you dealing damage and knocking the wind out of you!\n");
		ob->cause_typed_damage(ob, ob->return_target_limb(), damage, weapon[0]->query_damage_type());
	  	ob->set_paralyzed(8,"Your recovering from that last hit");
	  	return 1;
	}
		tell_room(ETP,"%^BOLD%^"+TPQCN+" rushes at "+ob->query_cap_name()+" but "+ob->query_subjective()+" side steps the attack!",({ob,TP}));
		tell_object(ob,"%^BOLD%^"+TPQCN+" rushes at you but you side step the attack!\n");
		write("%^BOLD%^You rush at "+ob->query_cap_name()+" but "+ob->query_subjective()+" side steps the attack!");
		TP->set_paralyzed(10,"Your recovering from your missed rush!");
		return 1;
}


void help(){
	write(
@OLI
	
This cmd is a fighter command designed around the fighter
Throwing all his/her weight behind a all out rush toward an enemy
its success depends totally on surprising the victim. So can only 
be used every now and then. (approximately every 60 seconds) 
You must wield a weapon to be effective. The damage is in proportion
to your level. The shock of the attack may paralyse your target 
for a short period of time.

rush <target>
OLI
	);
}
