//Octothorpe (8/30/09)
//Laerad, Gythka

#include <std.h>
inherit "/d/common/obj/weapon/double_bladed_sword.c";

void create(){
   ::create();
   set_id(({"gythka","pike","polearm","double bladed"}));
   set_name("gythka");
   set_short("%^RESET%^%^RED%^gythka%^RESET%^");
   set_obvious_short("%^RESET%^%^RED%^A double-bl%^RESET%^a%^RED%^d"+
      "%^RESET%^e%^RED%^d pike made of petrified wood%^RESET%^");
   set_long("%^RED%^The staff of this pike is over eight feet in "+
      "length, and is surely an awkward weapon to wield. The staff "+
	  "has been wrought from petrified wood, which lends the weapon "+
	  "some heft.  At both ends of the weapon, two %^RESET%^st%^BOLD%^"+
	  "ee%^RESET%^l %^RED%^crescents are found. The crescents are "+
	  "tapered into three sharp points, as well as being %^RESET%^e"+
	  "%^RED%^dg%^RESET%^e%^RED%^d, like a sword. The metal lacks "+
	  "any elaborate decorative flourishes, but the high level of "+
	  "craftsmanship is not in doubt.%^RESET%^");
   set_lore("Gythkas are unique polearms, that are found only among the "+
      "thri-kreen. These unwieldly weapons are favored by the thri-"+
	  "kreen, although the mantis warriors are able to handle them with "+
	  "great effect with their four arms. The creation of the weapons "+
	  "remains somewhat of a mystery to scholars. A popular theory "+
	  "abounds that the petrified wood used for the pike are remnants "+
	  "of the greater Darkwood Forest. The greater Darkwood "+
	  "encompassed the current Darkwood, Yntala, Tharis forest, and "+
	  "the Gods Plains of Laerad, before the cursed isle was torn from "+
	  "the mainland during the Second Godswar in 0 SG. The only "+
	  "criticism of this theory is the fact that no petrified wood "+
	  "has been known to be found on Laerad."); 
   set_property("lore",10);
   set_property("enchantment",random(2)+3);
   set_property("lore difficulty",10);
   set_value(1000+random(700));
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));   
}

int wield_fun(){
   switch((int)TO->query_property("enchantment")){
      case 4:
         if((int)ETO->query_highest_level() < 20){
            tell_room(EETO,"%^RED%^"+ETOQCN+" cringes and clutches "+
               ""+ETO->QP+" forehead, as "+ETO->QS+" tries to "+
               "wield the pike.%^RESET%^",ETO);
            tell_object(ETO,"%^RED%^Your sinuses feel like they are "+
               "about to implode as you try to wield the "+
               "pike!%^RESET%^");
            ETO->do_damage("torso",random(10)+20);
            return 0;
         }
         break;
      default:
         if((int)ETO->query_highest_level() < 15){
            tell_room(EETO,"%^RED%^"+ETOQCN+" cringes and clutches "+
               ""+ETO->QP+" forehead, as "+ETO->QS+" tries to "+
               "wield the pike.%^RESET%^",ETO);
            tell_object(ETO,"%^RED%^Your sinuses feel like they are "+
               "about to implode as you try to wield the "+
               "pike!%^RESET%^");
            ETO->do_damage("torso",random(10)+20);
            return 0;
         }
         break;
   }
   if (!ETO->query_property("silent_wield")) {
	   tell_room(EETO, "%^BOLD%^A barely audible hum originates from the " +
		   "pike as " + ETOQCN + " wields it.%^RESET%^", ETO);
	   tell_object(ETO, "%^BOLD%^As you wield the pike, a barely audible " +
		   "hum becomes apparent.%^RESET%^");
   }
   return 1;
}

int unwield_fun(){
	if (!ETO->query_property("silent_wield")) {
		tell_room(EETO, "%^BOLD%^%^CYAN%^" + ETOQCN + " sways and blinks " +
			"" + ETO->QP + " eyes as the pike leaves " + ETO->QP + " hands." +
			"%^RESET%^", ETO);
		tell_object(ETO, "%^BOLD%^%^CYAN%^As you unwield the pike, you " +
			"become lightheaded and nearly fall to the ground.%^RESET%^");
	}
	return 1;
}

int hit_fun(object targ){
   if(!objectp(targ)) return 0;
   if(random(1000) > 750){ 

      switch(random(4)){
	     case 0:
		    if(random(25) > targ->query_stats("intelligence")){
               tell_room(EETO,"%^BOLD%^"+ETOQCN+" finds an opening in "+
			      ""+targ->QCN+"'s defense, and exploits the opportunity "+
			      "with a well-placed %^RESET%^%^RED%^thrust %^RESET%^"+
			      "%^BOLD%^of the pike!%^RESET%^",ETO);
               tell_object(ETO,"%^BOLD%^You quickly capitalize on an "+
			      "opening in "+targ->QCN+"'s defense with a well-placed "+
			      "%^RESET%^%^RED%^thrust %^RESET%^%^BOLD%^of the "+
			      "pike!%^RESET%^");
               targ->do_damage("torso", random(15)+10);
			}
            break;  
		 case 1:
		    if(random(25) > targ->query_stats("intelligence")){
               tell_room(EETO,"%^YELLOW%^"+targ->QCN+" appears to get "+
			      "distracted by something, during which "+ETOQCN+" makes "+
			      "an extra attack!%^RESET%^",ETO);
               tell_object(ETO,"%^YELLOW%^"+targ->QCN+" appears to pause "+
			      "in mid-attack, giving you the perfect chance to strike "+
			      "again!%^RESET%^");
               ETO->execute_attack();
               if(random(5)){
                  ETO->execute_attack();
               }	
            }			   
            break;
         case 2:
		    if(random(25) > targ->query_stats("intelligence")){
               tell_room(EETO,"%^BOLD%^Static %^YELLOW%^e%^WHITE%^l"+
			      "%^YELLOW%^e%^WHITE%^ctr%^YELLOW%^i%^WHITE%^c%^YELLOW%^"+
			      "i%^WHITE%^ty begins crackling up and down "+ETOQCN+"'s "+
			      "pike, and then suddenly leaps off the weapon to strike "+
			   ""+targ->QCN+" in the chest!",ETO);
               tell_object(ETO,"%^BOLD%^Static %^YELLOW%^e%^WHITE%^l"+
			      "%^YELLOW%^e%^WHITE%^ctr%^YELLOW%^i%^WHITE%^c%^YELLOW%^"+
			      "i%^WHITE%^ty begins crackling up and down your pike, "+
			      "and then suddenly leaps off the weapon and strikes "+
			      ""+targ->QCN+" in the chest!%^RESET%^");
               TO->set_property("magic", 1);			   
               targ->do_damage("torso", random(15)+20);
			   TO->set_property("magic", -1);
			   if(!random(3)){
			      targ->set_tripped(random(3)+1, "%^YELLOW%^You are "+
			         "stunned from the blast!%^RESET%^");
			   }
			}
            break;  
         case 3:
		    if(random(25) < targ->query_stats("intelligence")){
		       if(!random(4)){
			      tell_room(EETO,"%^BOLD%^"+ETOQCN+" looks surprised as "+
			         "a magical spell is released from  "+ETO->QP+" "+
				     "pike.%^RESET%^",ETO);
			      tell_object(ETO,"%^BOLD%^The pike shudders in your "+
			         "hand as it releases a magical outburst against "+
				     ""+targ->QCN+"!%^RESET%^");
			      new("/cmds/spells/g/_greater_dispel_magic.c")->use_spell(ETO,targ,25+random(20),100,"mage");
			   }
			}
            break;
		}
	}
	return 1;
}