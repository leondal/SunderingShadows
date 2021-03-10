//removed references to old gods ~Circe~ 7/30/19
#include <std.h>
#include <magic.h>

inherit "/d/common/obj/weapon/flail.c";


void create(){
	::create();
   	set_name("Flail of Needles");
   	set_short("%^RESET%^%^GREEN%^Flail of %^BOLD%^N%^RESET%^%^GREEN%^e%^BOLD%^e%^RESET%^%^GREEN%^d%^BOLD%^l%^RESET%^%^GREEN%^e%^BOLD%^s%^RESET%^");
   	set_obvious_short("%^RESET%^%^GREEN%^An aged copper flail%^RESET%^");
	set_id(({"flail","flail of needles","copper flail","pine flail"}));
   	set_long("%^GREEN%^The handle of this flail is made of a light colored %^YELLOW%^pine%^RESET%^%^GREEN%^ wood that is very sturdy. Delicately carved into the handle is a myraid of trees, creating the image of a grand forest. Three thick chains of %^ORANGE%^copper%^GREEN%^ links are attached to the pine handle.  The weathered copper in many places takes on a %^BOLD%^%^WHITE%^silvery %^GREEN%^green %^RESET%^%^GREEN%^color.  At the end of each copper chain is a weighted orb of pine.  The three pine orbs have been polished with oils, brining out the light tone of the wood.  Imbedded into each orb are a multitude of %^BOLD%^pine needles%^RESET%^%^GREEN%^.%^RESET%^");
	set_lore("The Flail of Needles seems to come from the clerics that worshipped a forgotten nature deity back when the Darkwood Forest used to stretch all the way up to Old Antioch, and when what is Laerad now use to be attached to the main continent.  The Needles of the Forest, as the clerics called themselves, wandered the Darkwood Forest to explore the hidden beauty.  While within the forest, the Needles came often under attack from the forces of the Lords of Fury, more deities whose names have been lost to the times.  Fighting to protect their beloved forest, the Needles found a way to use nature against their foes, thus the Flail of Needles was born.  Though the clerics named their own order, they clearly assumed that none would ever forget the deities' names, for those have gone unrecorded.");
	set_property("lore",13); 
	set_value(2000);
      set_hit((:TO,"hitme":));
   	set_property("enchantment",4);
   	set_wield((:TO,"wieldme":));
   	set_unwield((:TO,"removeme":));
}

int wieldme(){
     if((int)ETO->query_lowest_level() < 30) {
      	tell_object(ETO,"%^GREEN%^The flail refuses you!");
     	return 0;
	}
	if((string)ETO->query_diety() == "nimnavanon") {
         tell_object(ETO,"%^BOLD%^The smooth pine handle is light and cool.");
         return 1;
      }else{
      tell_object(ETO,"%^GREEN%^The flail seems rather heavy and awkward.");
      return 1;
	}
}
int removeme()
{
      tell_object(ETO,"You release your hold of the flail, for now.");
      return 1;
}

int hitme(object targ){
int i;
object *weapons;
object obj;
string ids;

	if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(targ)) return 1;

      if(!random(8)) {
      tell_object(targ,"%^GREEN%^You feel a wave of piercing pain as"+
      	" "+ETO->QCN+"'s flail bashes into you, pine needles"+
      	" embedding themselves in your skin.");
      tell_object(ETO,"%^GREEN%^You slam the flail into "+targ->QCN+""+
      	" and pine needles pierce "+targ->QP+" skin!");
      tell_room(environment(ETO),"%^GREEN%^As "+ETO->QCN+"'s"+
      	" flail bashes into "+targ->QCN+", pine needles spray"+
		" into "+targ->QP+" skin!",({ETO,targ}));
      		targ->do_damage("torso",random(5)+4);
      return 1;
   	}
   	if(!random(17)) {
     	tell_object(targ,"%^ORANGE%^"+ETO->QCN+" wraps the copper "+
		"chains of "+ETO->QP+" flail around your legs and pulls"+
		" you off balance!");
	tell_object(ETO,"%^ORANGE%^You the copper chains of your flail"+
		" around "+targ->QCN+"'s legs and pull "+targ->QO+" "+
		"off balance!");
     	tell_room(environment(ETO),"%^ORANGE%^"+ETO->QCN+""+
     		" wraps the copper chains of "+ETO->QP+" flail around"+
		" "+targ->QCN+"'s feet, pulling "+targ->QO+" off"+
		" balance!",({ETO,targ}));
     			targ->do_damage("torso",random(10)+6);
     			targ->set_tripped(2,"You're still recovering from that last hit!");
     	return 1;
   	}
if(!random(45)){
      weapons = targ->query_wielded();
      if(sizeof(weapons)){
         if((int)weapons[0]->query_property("enchantment") < 0){
            return 1;
         }
         tell_object(ETO,"%^GREEN%^With a solid aim, you wrap one of the "+
              "copper chains around "+targ->QCN+"'s weapon.  Giving"+
              " a firm tug, you pry the weapon loose from "+targ->QP+" hand.");
         tell_object(targ,"%^GREEN%^"+ETOQCN+" loops one of the copper chains"+
              " on "+ETO->QP+" flail around your weapon.  With a tug "+ETO->QO+" "+
              "manages to pry it out of your hands!");
         tell_room(EETO,"%^GREEN%^"+ETOQCN+" loops one of the copper chains of"+
              " "+ETO->QP+" flail around "+targ->QCN+"'s weapon.  With a firm "+
              "tug, "+ETOQCN+" disarms "+targ->QCN+".",({ETO,targ}));
         ids = weapons[0]->query_id();
         targ->force_me("unwield "+ids[0]+"");
         //targ->force_me("drop "+ids[0]+"");
		 targ->remove_property("disarm time");
		 targ->set_property("disarm time",time()+(ROUND_LENGTH*roll_dice(1,4)));
         return 1;
      }
   }
   return 1;
}
