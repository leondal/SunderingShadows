// changing to inherit from /d/common while checking out & fixing encumbrance issue
// adjusted the light addition from +5 to +3 - too overpowering. N, 11/06.

//Updated by ~Circe~ 2/18/13 to use current code and slightly updated description, etc.
// removed references to old gods ~Circe~ 7/30/19

#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/scimitar";

object ob2;
string OWNER;
string wielder;

void init(){
    ::init();
    if(interactive(ETO) && !OWNER) OWNER = ETO->query_name();;
}

void create(){
   ::create();
   set_name("dark scimitar");
   set_id(({"scimitar","scimitar of the dark moon","sword","runed scimitar","rune-etched scimitar"}));
   set_obvious_short("%^BOLD%^%^BLACK%^gleaming %^BOLD%^%^MAGENTA%^r"
      "%^RESET%^%^MAGENTA%^u%^BOLD%^%^MAGENTA%^n%^RESET%^%^MAGENTA%^e"
      "%^BOLD%^%^MAGENTA%^-%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^t"
      "%^RESET%^%^MAGENTA%^c%^BOLD%^%^MAGENTA%^h%^RESET%^%^MAGENTA%^e"
      "%^BOLD%^%^MAGENTA%^d %^BOLD%^%^BLACK%^scimitar%^RESET%^");
   set_short("%^RESET%^%^CYAN%^Scimitar of the %^BOLD%^%^BLACK%^Dark "
      "%^RESET%^%^CYAN%^Moon%^RESET%^");
   set_long("%^RESET%^%^CYAN%^This beautiful blade is crafted from "
      "a darkened metal with a ceremonial %^RED%^blood groove %^CYAN%^"
      "that glows with a %^BOLD%^%^BLACK%^dark light%^RESET%^%^CYAN%^.  "
      "The hilt is crafted from %^BOLD%^%^BLACK%^black lacquered steel"
      "%^RESET%^%^CYAN%^, and the smooth, curved blade resembles the tiny "
      "sliver of a waning crescent moon.  Ancient %^RESET%^%^MAGENTA%^"
      "violet-colored runes %^RESET%^%^CYAN%^travel down the length of "
      "the blade, flashing to life and shifting in design as the sword "
      "tastes %^RED%^blood%^CYAN%^.%^RESET%^");
   set_lore("The Scimitar of the Dark Moon is in fact a corruption born "
      "of the hatred the Scion of Darkness feels toward Lysara.  The "
      "Scimitar of the Silver Moon is seen by many as a holy blade of "
      "Lady Graymantle, and her children hold it a great honor to wield the blade.  "
      "In recent years, the faithful of Lord Shadow have found a way to corrupt the "
      "blade and use it against their foes, all the while taunting the Lysarans.");
   set_read("%^RESET%^%^CYAN%^The runes read:\n"
      "%^RESET%^%^MAGENTA%^As the moon wanes, so shall the power of Lysara\n"
      "%^RESET%^%^MAGENTA%^The dark is a time to act\n"
      "%^RESET%^%^MAGENTA%^By this blade, may the stars of the Triple Goddess be snuffed");
    set_value(4000);
    set_property("enchantment",4);
    set_item_bonus("sight bonus",3);
    set_hit((: TO,"extra_hit" :));
    set_wield((:TO,"extra_wield" :));
    set_unwield((:TO,"extra_unwield" :));
}

int extra_hit(object ob){
    int dam;
    if(!objectp(ob)) return 1;
    if(!objectp(ETO)) return 1;
    if(!random(7)){
       dam=(random(4)+3);
	 switch(random(29)){
	    case 0..1:
             tell_object(ETO,"%^BOLD%^%^MAGENTA%^As you slice into "+ob->QCN+", "
                "you see an opening and drive your knee into an exposed area!%^RESET%^");
             tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" cuts into "+ob->QCN+" "
                "and then quickly drives a knee into an exposed area before "
                ""+ob->QCN+" recovers!%^RESET%^",({ETO,ob}));
             tell_object(ob,"%^BOLD%^%^BLACK%^"+ETOQCN+" slices into you, "
                "and drives a knee into your ribsbefore you can react!%^RESET%^");
	       TO->set_property("magic",1);
	       ob->do_damage("torso",random(5)+3);
	       ob->set_paralyzed(random(5)+2,"You take a couple of deep "
                "breaths to get your balance again!");
	       TO->remove_property("magic");
	       return dam;
	       break;
	    case 2:
             tell_object(ETO,"%^BOLD%^%^BLACK%^The dark blade turns pitch "
                "black, leaving a streak of darkness in its trail as it cuts "
                "into "+ob->QCN+"!%^RESET%^");
             tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s sword darkens "
                "violently as it cuts into "+ob->QCN+", who staggers back "
                "rubbing "+ob->QP+" eyes!%^RESET%^",({ETO,ob}));
             tell_object(ob,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s blade darkens "
                "violently as it swings towards you and you feel as if "
                "the light has been taken out of your eyes!%^RESET%^");
	       if(!random(3)) ob->set_blind(1);
             else ob->set_paralyzed(4+random(4),"%^BOLD%^You're rubbing "
                "your eyes in an attempt to see again.");
             return dam;
	       break;
	    case 3..6:
             tell_room(EETO,"%^BOLD%^%^BLACK%^A huge raven swoops down "
                "at "+ob->QCN+"!%^RESET%^");
             ob2=new("/d/dagger/derro/mon/raven.c");
	       ob2->move(EETO);
	       ob2->force_me("protect "+ETO->query_name());
	       ETO->add_follower(ob2);
	       break;
	    case 7..8:
             tell_object(ETO,"%^RESET%^%^MAGENTA%^You slice the scimitar "
                "into "+ob->QCN+" and quickly bring the back around, "
                "slashing into "+ob->QO+" again!%^RESET%^");
             tell_room(EETO,"%^RESET%^%^MAGENTA%^"+ETOQCN+" slices the "
                "scimitar into "+ob->QCN+" and then quickly brings the "
                "blade back across, slicing into "+ob->QO+" again!%^RESET%^",({ETO,ob}));
             tell_object(ob,"%^RESET%^%^MAGENTA%^"+ETOQCN+" sweeps "+ETO->QP+" "
                "scimitar across your chest and brings it back across for "
                "another devastating slash!%^RESET%^");
	       ob->set_paralyzed(15,"%^BOLD%^%^CYAN%^You stagger dazed from the blow!");
	       return 10;
             break;
          case 9..26:
             tell_object(ETO,"%^BOLD%^%^BLACK%^The blade fades into nothing "
                "as it passes through "+ob->QCN+"'s body, tearing at "
                ""+ob->QP+" soul!%^RESET%^");
             tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s scimitar fades "
                "into nothing as it passes through "+ob->QCN+"!%^RESET%^",({ETO,ob}));
             tell_object(ob,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s scimitar fades "
                "into nothing as it tears into your soul!%^RESET%^");
	       TO->set_property("magic",1);
	       ob->do_damage("torso",random(15)+5);
	       TO->remove_property("magic");
	       return dam;
	       break;
	    case 27:
             tell_object(ETO,"%^BOLD%^%^BLACK%^The blade fades into nothing "
                "as it passes through "+ob->QCN+"'s body, tearing at "+ob->QP+" "
                "soul!%^RESET%^");
             tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s scimitar fades "
                "into nothing as it passes through "+ob->QCN+"!%^RESET%^",({ETO,ob}));
             tell_object(ob,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s scimitar fades "
                "into nothing as it tears into your soul!%^RESET%^");
             TO->set_property("magic",1);
             ob->do_damage("torso",random(25)+10);
	       TO->remove_property("magic");
	       return random(10)+3;
	       break;
	    default:
	       ETO->execute_attack();
	       ETO->execute_attack();
	       ETO->execute_attack();
             tell_object(ETO,"%^MAGENTA%^The sword suddenly blurs as it "
                "speeds your attacks!%^RESET%^");
             tell_room(EETO,"%^MAGENTA%^" +ETOQCN+"'s blade suddenly "
                "blurs with speed as "+ETO->QS+" attacks!%^RESET%^",({ETO,ob}));
             tell_object(ob,"%^BLACK%^"+ETOQCN+" suddenly blurs with speed as "
                ""+ETO->QP+" scimitar slashes at you!%^RESET%^");
             if(!random(25)){
                tell_object(ETO,"%^BOLD%^%^MAGENTA%^You can't hold onto "
                   "the scimitar as it speeds through the air! It falls "
                   "to the ground, and the brilliant black sapphire "
                   "smashes on impact!%^RESET%^");
                tell_room(EETO,"%^BOLD%^%^MAGENTA%^"+ETOQCN+" can't keep a "
                   "grasp on the scimitar, and its brilliant black sapphire "
                   "smashes as it hits the ground!%^RESET%^",ETO);
		    tell_room(EETO,"The scimitar fades to gray.");
                new("/d/dagger/derro/obj/oldscimitar.c")->move(EETO);
                TO->remove();
	       }
	       break;
         }
      }
   return (random(5)+1);
}

int extra_wield(){
   if(!interactive(ETO)) return 1;
   if((string)ETO->query_name() !=OWNER){
      tell_object(ETO,"%^BOLD%^%^MAGENTA%^The scimitar does not know you!%^RESET%^");
      return 0;
   }
   if((int)ETO->query_highest_level()<20){
      tell_object(ETO,"The scimitar will not be wielded by such a weak hand as yours.");
      tell_room(EETO,""+ETOQCN+" seems to be having difficulty figuring out which end "
         "of the scimitar to use.",ETO);
      return 0;
   }
   if(ALIGN->is_good(ETO)){
      tell_object(ETO,"%^BOLD%^%^RED%^The scimitar burns your hands as you try to wield it!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^RED%^The scimitar flashes as "+ETOQCN+" tries to wield "
         "it, burning "+ETO->QO+"!%^RESET%^",ETO);
      ETO->do_damage("torso",random(50)+25);
      ETO->force_me("drop scimitar of the dark moon");
      return 0;
   }
   tell_object(ETO,"%^BOLD%^%^BLACK%^The runes glow softly as you wrap your hand about the hilt.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^Runes etched upon the blade held by "+ETOQCN+" glow softly.%^RESET%^",ETO);
   ETO->set_property("evil item",1);
   return 1;
}

int extra_unwield(){
   tell_room(EETO,"%^BOLD%^%^BLACK%^The runes dim as "+ETOQCN+" unwields the blade.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^The runes dim as you remove the blade from your grasp.%^RESET%^");
   ETO->set_property("evil item",-1);
   return 1;
}
