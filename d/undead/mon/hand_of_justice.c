//Coded by the one and only master of monsters...BANE//
#include <std.h>
#include <daemons.h>
#include "../undead.h"

inherit CREATURE;

void create()
{
    ::create();
    set_id(({"hand", "justice", "hand of justice", "corrupted","corrupt"}));
    set_name("%^BOLD%^Corrupted Hand of Justice%^RESET%^");
    set_short("%^BOLD%^Corrupted Hand of Justice%^RESET%^");
    set_long("%^ORANGE%^This large humanoid creature is made completely out of earth, once it was a proud symbol "+
	"of %^BOLD%^Tyr %^RESET%^%^ORANGE%^and one of his most loyal and trusted subjects. But something has corrupted "+
	"this hand into a horrid and terrifying version of itself.It stands just over 16 feet tall stares blankly at you "+
	"with its beady golden eyes where only %^BOLD%^%^RED%^feral instincts %^RESET%^%^ORANGE%^seem to exist.%^WHITE%^.");
    set_body_type("human");
    set_race("planar creature");
    set_gender("neuter");
    set_property("magic",1);
    set_size(3);
    set_hd(35,8);
	set_class("cleric");
    set_mlevel("cleric",30);
	set_guild_level("cleric",30);
    set_hp(1300);
    set_exp(30000);
    set_new_exp(25,"boss");
    set_alignment(5);
    set_overall_ac(-5);
    set("aggressive",22);
    set_speed(25);
    nogo("one");
    set_mob_magic_resistance("average");
    set_attack_limbs(({"right hand"}));
    set_attacks_num(3);
    set_base_damage_type("bludgeoning");
    set_damage(4,12);
    set_stats("strength",22);
    set_stats("dexterity",14);
    set_funcs(({"crushall", "grabs"}));
    set_func_chance(20);
    set_spells(({"flame strike", "call lightning", "call lightning", "mass cause critical wounds"}));
	set_spell_chance(15);
	set_speed(30);
}

void crushall() 
{
    object *vars;
    int i;
    vars = all_living(ETO);
    for(i=0;i<sizeof(vars);i++)
    {
	    if(vars[i] == TO) continue;
        tell_object(vars[i],"%^BOLD%^The Corrupted Hand of Justice curls its fingers into a giant fist and smashes it into the ground!");
	        if(!ROLLSAVE(vars[i],PPD))
            {
                tell_object(vars[i],"%^RED%^You are thrown across the room by the force of the blow as it hits the ground!");
                vars[i]->do_damage(vars[i]->return_target_limb(),roll_dice(6,6)+20);
                vars[i]->set_paralyzed(20,"You are dazed by blow dealt to you by the Hand of Justice.");
	        } 
            else 
            {
                tell_object(vars[i],"%^BOLD%^%^RED%^You are thrown off your feet, but you quickly regain your position!");
	            vars[i]->do_damage(vars[i]->return_target_limb(),roll_dice(3,6)+10);
				
	        }
    }
}

void grabs() {
	
	int k,squeezed;
	object targi;
	targi = TO->query_current_attacker();
	
	
	
	tell_object(targi,"The Corrupted Hand of Justice tries to catch you with it's massive hand!");
	if(!"daemon/saving_throw_d"->reflex_save(targi,-25)) {
		tell_object(targi,"You have been caught in the Corrupted Hand's massive fist!");
		tell_room(ETO,targi->QCN+" has been caught in the massive fist of the Corrupted Hand",({targi}));
		squeezed = roll_dice(1,10)+5;
		for(k=0;k < squeezed;k++){
			tell_object(TO,"squeezy squeezy squeezy!!");
			tell_object(targi,"You are having the life squeezed out of you!");
			tell_room(ETO,"The Corrupted Hand of Justice is queezing the life out of "+targi->QCN,({targi}));
			targi->do_damage("torso",roll_dice(2,10)+10);
						
		}
	}
	else
	{	
	tell_object(targi,"You barely manage to dodge away from the Corrupted Hands graps, but are still grazed!");
	tell_room(ETO,targi->QCN+" barely dodged away from the Corrupted Hands grasp!");
	targi->do_damage(targi->return_target_limb(),roll_dice(3,10)+20);
	}
	
}



void die(object ob) {
   //object lewts;
   tell_room(ETO,"%^ORANGE%^The Corrupted Hand of Justice snarls a final mockery to Tyr, before collapsing into a heap of earth and gemstones  %^RESET%^");
   new(OBJS"wolfhammer.c")->move(TO);
   

   
:: die(ob);
}