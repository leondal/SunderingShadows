//Added level 10 to wield and Mask bonuses - Octothorpe 12/26/09
//Added lore and inherit shortsword.c Cythera 4/05\\

#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/weapon/shortsword.c";

int x;

void create()
{
   ::create();
   set_name("%^BOLD%^%^BLACK%^Shadow Blade");
   set_id(({"sword","blade","short sword","shadow blade"}));
   set_short("%^BOLD%^%^BLACK%^Shadow Blade%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^A dark short sword%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Once a normal short sword, this blade "+
      "has been warped and twisted by the stuff of shadows. There is "+
	  "a dark sheen to the blade that almost seems to flicker with "+
	  "some pulse of life.");
   set_lore("The blade of the shades is tainted by the shadows "+
      "itself.  The Shadow Blade, as it is named is a weapon"+
	  " that none will ever forget when they feel its sting."+
	  "  The blade is said to be infused with negative energy,"+
	  " giving it is gruesome abilities.  The blade has since"+
	  " gone on to become a favorite weapon for many of the "+
	  "rogues in the church of shadow.");
   set_property("lore",9);
   set_hit((:TO, "hitme":));
   set_value(50);
   set_wield((:TO, "wieldme":));
   set_unwield((:TO, "removeme":));
   set_property("enchantment",2);
   x = query_property("enchantment");
}

int wieldme()
{
   int align;
   align = ETO->query_alignment();
   if((int)ETO->query_highest_level() < 10){
      tell_object(ETO,"%^BOLD%^%^BLACK%^%^The blade rejects your touch!%^RESET%^");
	  return 0;
   }
   switch(align) {
      case 3: case 6: case 9:
      tell_object(ETO,"%^BOLD%^%^BLACK%^The blade seems to"+
	     " fit itself to your grasp, its heart beat pulsing in"+
		 " time to your own.");
	  tell_room(environment(ETO),"%^BOLD%^%^BLACK%^As"+
		 " "+ETO->query_cap_name()+" wields the Shadow Blade"+
		 " a slight smile spreads across "+ETO->query_possessive()+" face.",ETO);
		 set_ac(0);
		 if((string)ETO->query_diety() == "lord shadow"){
            	set_item_bonus("attack bonus",2);
         }			
            else set_item_bonus("attack bonus",0);
		 if((int)ETO->query_highest_level() > 15 && (int)TO->query_property("enchantment") > 0) {
			while((int)TO->query_property("enchantment") < 3){
				TO->remove_property("enchantment");
			    	TO->set_property("enchantment",3);
			}
		 }		
         ETO->set_property("evil item",1);
			set_item_bonus("armor bonus",0);
			return 1;
		
		case 2: case 5: case 8:
			tell_object(ETO,"%^RED%^The blade is cool to your"+
			" touch at first, but slowly warms.");
			tell_room(environment(ETO),"%^RED%^"+ETO->query_cap_name()+""+
			" wields the Shadow Blade.",ETO);
			while(query_property("enchantment") != x-1) {
				remove_property("enchantment");
				set_property("enchantment",x-1);
			}
			set_item_bonus("armor bonus",0);
         ETO->set_property("evil item",1);
			return 1;
		
		case 1: case 4: case 7:
			tell_object(ETO,"%^YELLOW%^The sword seems to recoil"+
			" from your touch and you get a feeling of wrongness.");
			tell_room(environment(ETO),"%^YELLOW%^"+ETO->query_cap_name()+""+
			" frowns slightly as "+ETO->query_objective()+""+
			" wields the %^BOLD%^%^BLACK%^Shadow Blade.%^RESET%^",ETO);
			while(query_property("enchantment") != x-2) {
				remove_property("enchantment");
				set_property("enchantment",x-2);
			}
			set_item_bonus("armor bonus",-2);
         ETO->set_property("evil item",1);
			return 1;
		
	}
}

int removeme()
{
	int align;

	align = ETO->query_alignment();
	switch(align) {
		case 3: case 6: case 9:
			tell_object(ETO,"%^BOLD%^%^BLACK%^As you unwield the"+
			" sword you feel as though you're removing a limb.");
			tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" unwields the Shadow Blade reluctantly,"+
			" "+ETO->query_subjective()+" looks sad to release"+
			" it.",ETO);
		    if((string)ETO->query_diety() == "mask"){
               ETO->add_attack_bonus(-2);
            }				
            ETO->set_property("evil item",-1);
			return 1;

		case 2: case 5: case 8:
			tell_object(ETO,"%^RED%^The sword seems almost"+
			" reluctant to leave your hand.");
			tell_room(environment(ETO),"%^RED%^"+ETO->query_cap_name()+""+
			" unwields the Shadow Blade.",ETO);
			while(query_property("enchantment") != x) {
				remove_property("enchantment");
				set_property("enchantment",x);
			}
            ETO->set_property("evil item",-1);
			return 1;

		case 1: case 4: case 7:
			tell_object(ETO,"%^YELLOW%^You feel relieved as you"+
			" release the blade.");
			tell_room(environment(ETO),"%^YELLOW%^"+ETO->query_cap_name()+""+
			" looks happier as "+ETO->query_subjective()+""+
			" unwields the Shadow Blade.",ETO);
			while(query_property("enchantment") != x) {
				remove_property("enchantment");
				set_property("enchantment",x);
			}
            ETO->set_property("evil item",-1);
			return 1;
		
		default: 
			tell_object(ETO,"There appears to be something wrong here.");
			return 0;
	}
}

int hitme(object targ)
{
	int align, talign;

	if(!objectp(targ)) return 1;

	align = query_wielded()->query_alignment();
	talign = targ->query_alignment();
	switch(align) {
		case 3: case 6: case 9:{
			if(ETO->query_level() < 15) return 1;
                    if(!random(10)) {
				tell_object(ETO,"%^RED%^As you slice your blade"+
				" into "+targ->query_cap_name()+"'s flesh you"+
				" can feel the sword pulse, draining"+
				" "+targ->query_possessive()+" life force.");
				tell_room(environment(ETO),"%^RED%^"+ETO->query_cap_name()+""+
				" slices "+ETO->query_possessive()+" blade into"+
				" "+targ->query_cap_name()+"'s flesh, grinning"+
				" evilly as "+ETO->query_subjective()+" drains"+
				" "+targ->query_possessive()+" life away.",({ETO,targ}));
				tell_object(targ,"%^RED%^"+ETO->query_cap_name()+""+
				" slices "+ETO->query_possessive()+" blade into"+
				" your flesh. The evil blade seems to suck away"+
				" your life force!");
				targ->do_damage("torso",random(6)+3);
				query_wielded()->add_hp(random(6));
				return 1;
			}
                    if(!random(20)) {
				tell_object(ETO,"%^MAGENTA%^As you crash your"+
				" blade into "+targ->query_cap_name()+" a gray"+
				" light extends from the sword.");
				tell_room(environment(ETO),"%^MAGENTA%^As"+
				" "+ETO->query_cap_name()+" crashes "+ETO->query_possessive()+""+
				" blade into "+targ->query_cap_name()+" a gray"+
				" light extends from the sword.",({ETO,targ}));
				tell_object(targ,"%^MAGENTA%^"+ETO->query_cap_name()+""+
				" crashes "+ETO->query_possessive()+" blade into"+
				" you and a gray light extends from the sword.");
				targ->set_paralyzed(4,"You can't move!");
					if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
						tell_object(targ,"%^BOLD%^%^BLACK%^The light holds you in place!");
						tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+targ->query_cap_name()+""+
						" is paralyzed by the light.",({ETO,targ}));
						tell_object(ETO,"%^BOLD%^%^BLACK%^The light"+
						" from your sword holds "+targ->query_cap_name()+""+
						" in place.");
					targ->set_paralyzed(25,"You cannot move!");
					return 1;
				}
				else {
					tell_object(targ,"%^YELLOW%^The light does not seem to"+
					" affect you.");
					tell_room(environment(ETO),"%^YELLOW%^The light doesn't"+
					" seem to affect "+targ->query_cap_name()+".",({ETO,targ}));
					tell_object(ETO,"%^YELLOW%^"+targ->query_cap_name()+""+
					" seems to resist the light of the sword.");
				}
				targ->do_damage("torso",random(5)+5);
				return 1;
			}

			if(!random(25)) {
				tell_object(ETO,"%^BOLD%^%^BLACK%^You slip your"+
				" blade deep into "+targ->query_cap_name()+","+
				" letting your sword feed on "+targ->query_possessive()+""+
				" soul.");
				tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+
				""+ETO->query_cap_name()+" slips "+ETO->query_possessive()+""+
				" blade deep into "+targ->query_cap_name()+","+
				" the sword seems to glow as it drains the life"+
				" out of "+targ->query_objective()+".",({ETO,targ}));
				tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+""+
				" sinks "+ETO->query_possessive()+" blade deep"+
				" into you, it feels as though the sword is"+
				" sucking the life out of you!");
				targ->do_damage("torso",random(10)+3);
				return 1;
			}
			break;
		}

		case 2: case 5: case 8:{
			if(ETO->query_level() < 15) return 1;
			if(!random(12)) {
				tell_object(ETO,"%^BOLD%^%^RED%^The sword grows"+
				" hot as it slices into "+targ->query_cap_name()+"'s"+
				" skin and drinks "+targ->query_possessive()+""+
				" blood.");
				tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+"'s"+
				" sword glows a faint red as it drains "+targ->query_cap_name()+""+
				" of blood.",({ETO,targ}));
				tell_object(targ,"%^BOLD%^%^RED%^"+ETO->query_cap_name()+"'s"+
				" sword slices into your flesh, turning a faint"+
				" red as it quickly drains your blood.");
				targ->do_damage("torso",random(10)+3);
				return 1;
			}
			if(!random(45)) {
				tell_object(ETO,"%^BLUE%^The %^BOLD%^%^BLACK%^Shadow Blade%^RESET%^%^BLUE%^"+
				" lunges out at "+targ->query_cap_name()+","+
				" tearing through "+targ->query_possessive()+""+
				" armor to land a deadly blow!");
				tell_room(environment(ETO),"%^BLUE%^"+ETO->query_cap_name()+""+
				" lunges out with "+ETO->query_possessive()+""+
				" sword, cutting through "+targ->query_cap_name()+"'s"+
				" armor to land a deadly blow!",({ETO,targ}));
				tell_object(targ,"%^BLUE%^"+ETO->query_cap_name()+""+
				" lunges at you, cutting through your armor and"+
				" landing a deadly blow against you!");
				targ->do_damage("torso",random(12)+4);
				return 1;
			}
			break;
		}

		case 1: case 4: case 7:{
			if(!random(20)) {
				switch(talign) {
					case 2: case 5: case 8:
						tell_object(ETO,"%^RED%^The sword"+
						" burns against your skin in anger as"+
						" you attempt to use it!");
						tell_room(environment(ETO),"%^RED%^"+ETO->query_cap_name()+"'s"+
						" sword seems to burn "+ETO->query_objective()+"!",({ETO,targ}));
						tell_object(targ,"%^RED%^The"+
						" %^BOLD%^%^BLACK%^Shadow Blade%^RESET%^%^RED%^"+
						" seems to burn "+ETO->query_cap_name()+"'s"+
						" flesh in anger as "+ETO->query_subjective()+""+
						" tries to use it against you!");
 						query_wielded()->do_damage(random(5)+2);
						return 1;

					case 3: case 6: case 9:
						tell_object(ETO,"%^CYAN%^The sword fights"+
						" against your control, it reaches out and"+
						" seems to HEAL "+targ->query_cap_name()+"!"); 
						tell_room(environment(ETO),"%^CYAN%^The "+
						"%^BOLD%^%^BLACK%^Shadow Blade%^RESET%^"+
						" %^CYAN%^appears to be fighting against"+
						" "+ETO->query_cap_name()+", it reaches out"+
						" and bathes "+targ->query_cap_name()+" in"+
						" a bluish light, healing"+
						" "+targ->query_objective()+"!",({ETO,targ}));
						tell_object(targ,"%^RED%^The Shadow Blade"+
						" whispers in your mind: %^RESET%^Take me"+
						" from this fool! We could be great"+
						" together, you and I...\n\n %^CYAN%^The sword"+
						" bathes you in a refreshing bluish light,"+
						" healing some of your wounds.");
						targ->do_damage("torso",-(random(6)+1));
						return 1;

					case 1: case 4: case 7:
						tell_object(ETO,"%^ORANGE%^The sword ceases its"+
						" struggle against you for a moment to drive"+
						" itself into "+targ->query_cap_name()+","+
						" greedily drinking "+targ->query_possessive()+""+
						" life energy away.");
						tell_room(environment(ETO),"%^ORANGE%^The "+
						"%^BOLD%^%^BLACK%^Shadow Blade%^RESET%^%^ORANGE%^"+
						" ceases its struggle against "+ETO->query_cap_name()+""+
						" for a moment to plunge deeply into "+targ->query_cap_name()+""+
						" and suck "+targ->query_possessive()+" life"+
						" energy away.",({ETO,targ}));
						tell_object(targ,"%^ORANGE%^"+ETO->query_cap_name()+"'s"+
						" sword stops struggling against "+ETO->query_objective()+""+
						" for a moment, apparently deciding that you look"+
						" just as appetizing, and sinks itself deeply"+
						" into you, draining your life energies away.");
						targ->do_damage("torso",random(8)+3);
						return 1;

				}
			}			
			else {
				return 1;
			}
			break;
		}
	}
}
