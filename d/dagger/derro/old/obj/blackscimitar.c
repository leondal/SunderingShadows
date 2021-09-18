// changing to inherit from /d/common while checking out & fixing encumbrance issue
// adjusted the light addition from +5 to +3 - too overpowering. N, 11/06.

#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/scimitar";

int align;
int old;
int flag;
object ob2;
string OWNER;
string wielder;

void init(){
    ::init();
    if(interactive(ETO) && ETO==environment(TO)  && !OWNER) OWNER = ETO->query_name();;
}

void create(){
    ::create();
   set_id(({"scimitar","scimitar of the dark moon", "sword",
      }));
   set_name("dark scimitar");
   set_obvious_short("scimitar");
   set_short("%^RESET%^%^CYAN%^Scimitar of the %^BOLD%^%^BLACK%^Dark %^RESET%^%^CYAN%^Moon%^RESET%^");
    set_long(
   " %^RESET%^%^CYAN%^This beautiful blade glows with a dark light that seems"+
   " to be coming from within. The hilt is of black lacquered steel and the smooth"+
   " curved blade resembles the tiny sliver of a waning crescent moon."+
   " %^RESET%^%^MAGENTA%^Violet %^RESET%^%^CYAN%^colored runes travel down the length of the blade."
    );
   set_lore(
      "The Scimitar of the Dark Moon is in fact a corrupted holy blade of Selune."+
      " Long has the Mistress of the Night nursed a hatred for her sister. The"+
      " Scimitar of the Silver Moon is seen by many as a holy blade of the"+
      " Moonmaiden, and her children see it as a great honor to wield the blade."+
      " Though in recent years the faithful of Shar have found a way to corrupt the"+
      " blade and use it against their foes."
   );
   set("read",
      "%^RESET%^%^CYAN%^The runes read\n"+
      "%^RESET%^%^MAGENTA%^As the moon wanes, so shall the power of Selune\n"+
      "%^RESET%^%^MAGENTA%^The dark is a time to act\n"+
      "%^RESET%^%^MAGENTA%^By this blade, may the stars of the Moonmaiden be snuffed"
   );
    set("value",4000);
    set_property("enchantment",4);
/**** from /d/common now
*    set_weight(10);
*    set_size(2);
*    set_wc(1,8);
*    set_large_wc(1,10);
*    set_type("slashing");
*    set_prof_type("medium blades");
****/
    set_hit((: TO,"extra_hit" :));
    set_wield((:TO,"extra_wield" :));
    set_unwield((:TO,"extra_unwield" :));
}
int extra_hit(object ob){
    int dam;
    wielder=ETO;
    if(!objectp(ob)) return 1;
    if(!random(10)){
  dam=(random(5)+1);
	switch(random(29)){
	case  0..1:
            message("my_action","%^BOLD%^%^MAGENTA%^As you slice into "+ob->query_cap_name()+" you see an opening and drive your knee into an exposed area!%^RESET%^",ETO);
            message("other_action","%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" cuts into "+ob->query_cap_name()+" and then quickly drives a knee into an exposed area before "+ob->query_cap_name()+" recovers!%^RESET%^",environment(ob),(({ETO,ob})));
            message("my_action","%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" slices into you and before you can react drives a knee into your ribs!%^RESET%^",ob);
	    TO->set_property("magic",1);
	    ob->do_damage("torso",random(5)+1);
	    ob->set_paralyzed(random(5)+2,"You take a couple of deep breaths to get your balance again!");
	    TO->remove_property("magic");
	    return dam;
	    break;
	case 2:
            message("my_action","%^BOLD%^%^BLACK%^The dark blade turns pitch black, leaving a streak of darkness in its trail!%^RESET%^",ETO);
   message("other_action","%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+"'s sword darkens violently as it cuts into "+ob->query_cap_name()+" who staggers back rubbing "+ob->query_possessive()+" eyes!%^RESET%^",environment(ob),(({ETO,ob})));
   message("my_action","%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+"'s blade darkens violently as it swings towards you and you feel as if the light has been taken out of your eyes!%^RESET%^",ob);
	    if(!random(3)) ob->set_blind(1);
            else ob->set_paralyzed(4+random(4), "%^BOLD%^You're rubbing your eyes in an attempt to see again.");
	    break;
	case 3..6:
            tell_room(environment(ETO),"%^BOLD%^%^BLACK%^A huge raven swoops down at "+ob->query_cap_name()+"!%^RESET%^");
            ob2=new("/d/dagger/derro/mon/raven.c");
	    ob2->move(environment(ETO));
	    ob2->force_me("protect "+wielder->query_name());
	    wielder->add_follower(ob2);
	    break;
	case 7..8:
      message("my_action","%^RESET%^%^MAGENTA%^You slice the scimitar into "+ob->query_cap_name()+" and quickly bring the back around, slashing into them again!%^RESET%^",ETO);
            message("other_action","%^RESET%^%^MAGENTA%^"+ETO->query_cap_name()+" slices the scimitar into "+ob->query_cap_name()+" and then quickly brings the blade back across, slicing into "+ob->query_cap_name()+" again!%^RESET%^",environment(ob),(({ETO,ob})));
   message("my_action","%^RESET%^%^MAGENTA%^"+ETO->query_cap_name()+" sweeps "+ETO->query_possessive()+" scimitar across your chest and bring it back across for another devastating slash!%^RESET%^",ob);
	    ob->set_paralyzed(15,"%^BOLD%^%^CYAN%^You stagger dazed from the blow!");
	    return 10;
	    break;
	case 9..26:
      message("my_action","%^BOLD%^%^BLACK%^The blade fades into nothing as it passes through "+ob->query_cap_name()+"'s body, tearing at "+ob->query_possessive()+" soul!%^RESET%^",ETO);
            message("other_action","%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+"'s scimitar fades into nothing as it passes through "+ob->query_cap_name()+"!%^RESET%^",environment(ob),(({ETO,ob})));
      message("my_action","%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+"'s scimitar fades into nothing as it tears into your soul!%^RESET%^",ob);
	    TO->set_property("magic",1);
	    ob->do_damage("torso",random(5)+1);
	    TO->remove_property("magic");
	    return dam;
	    break;
	case 27:
      message("my_action","%^BOLD%^%^BLACK%^The blade fades into nothing as it passes through "+ob->query_cap_name()+"'s body, tearing at "+ob->query_possessive()+" soul!%^RESET%^",ETO);
            message("other_action","%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+"'s scimitar fades into nothing as it passes through "+ob->query_cap_name()+"!%^RESET%^",environment(ob),(({ETO,ob})));
      message("my_action","%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+"'s scimitar fades into nothing as it tears into your soul!%^RESET%^",ob);
	    TO->set_property("magic",1);
  ob->do_damage("torso",random(10)+1);
	    return random(10)+1;
	    break;
	case 28:
	    ETO->execute_attack();
	    ETO->execute_attack();
	    ETO->execute_attack();
            message("my_action","%^MAGENTA%^The sword suddenly blurs as it speeds your attacks!%^RESET%^",ETO);
      message("other_action","%^MAGENTA%^" +ETO->query_cap_name()+"'s blade suddenly blurs with speed as "+ETO->query_subjective()+" attacks!%^RESET%^",environment(ob),(({ETO,ob})));
      message("my_action","%^BLACK%^"+ETO->query_cap_name()+" suddenly blurs with speed as "+ETO->query_possessive()+" scimitar slashes at you!%^RESET%^",ob);
  if(!random(15)){
      tell_object(ETO,"%^BOLD%^%^MAGENTA%^You can't hold onto the scimitar as it speeds through the air and it falls to the ground, the brilliant black sapphire smash as it impacts!");
      tell_room(environment(ETO),"%^BOLD%^%^MAGENTA%^"+ETO->query_cap_name()+" can't keep a grasp on the scimitar, and its brilliant black sapphire smashes as it hits the ground!%^RESET%^",ETO);
		tell_room(environment(ETO),"The scimitar fades to grey.");
               new("/d/dagger/derro/obj/oldscimitar.c")->move(environment(ETO));
		TO->remove();
	    }
	    break;
	}
    }
  return (random(5)+1);
}
int extra_wield(){
  if(!interactive(TP)) return 1;
    if((string)ETO->query_name() !=OWNER){
         write("%^BOLD%^%^MAGENTA%^The scimitar does not know you!%^RESET%^");
	return 0;
    }
    if((int)ETO->query_highest_level()<20){
	write("The scimitar will not be wielded by such a weak hand as yours.");
	say(""+ETO->query_cap_name()+" seems to be having difficulty figuring out which end of the scimitar to use.");
	return 0;
    }
   if(((int)ETO->query_alignment() % 3)==0){
      write("%^BOLD%^%^BLACK%^The runes glow softly as you wrap your hand about the hilt.%^RESET%^");
      say("%^BOLD%^%^BLACK%^A set of runes etched upon the blade held by "+ETO->query_cap_name()+" glow softly.%^RESET%^");
   if(member_array(ETO->query_race(),PLAYER_D->night_races()) != -1) ETO->add_sight_bonus(-3);
   else ETO->add_sight_bonus(3);
   ETO->set_property("evil item",1);
	return 1;
  } else {
	write("%^BOLD%^%^RED%^The scimitar burns your hands as you try to wield it!");
     say("%^BOLD%^%^RED%^The scimitar flashes as "+ETO->query_cap_name()+" tries to wield it, burning "+ETO->query_objective()+"!");
   ETO->force_me("drop scimitar of the dark moon");
	ETO->do_damage("torso",random(50)+25);
	return 0;
    }
}
int extra_unwield(){
   if(member_array(ETO->query_race(),PLAYER_D->night_races()) != -1) ETO->add_sight_bonus(3);
   else ETO->add_sight_bonus(-3);
   say("%^BOLD%^%^BLACK%^The runes dim as "+ETO->query_cap_name()+" unwields the blade.%^RESET%^");
   tell_object(ETO,"The runes dim as you remove the blade from your grasp.%^RESET%^");
   ETO->set_property("evil item",-1);
    return 1;
}
