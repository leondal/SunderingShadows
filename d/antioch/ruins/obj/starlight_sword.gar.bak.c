#include <std.h>
//#include "../ruins.h"
#include "/d/antioch/ruins/ruins.h"
inherit WEAPON;

void create()
{
  ::create();
  set_name("Starlight Sword");
  set_short("%^BOLD%^%^BLUE%^St%^WHITE%^a%^BLUE%^rlight Sw%^WHITE%^o%^BLUE%^rd%^RESET%^");
  set_id(({"sword","starlight sword","Starlight Sword"}));
  set_long(
	   "This sword is almost enchanting, it is made out of some opaque alloy and"+
	   " has been forged with %^BOLD%^stardust%^RESET%^ that %^BOLD%^shimmers%^RESET%^ along the"+
	   " length of the blade. The hilt is made of gilded %^BOLD%^mithril%^RESET%^"+
	   " and has a %^BOLD%^%^BLUE%^star sapphire%^RESET%^ set into the pommel."
	   );
  set_weight(5);
  set_wc(1,10);
  set_large_wc(1,12);
  set_type("slashing");
  set_prof_type("starlight sword");
  set_value(2000);
  set_size(2);
  set_weapon_speed(4);
  set_property("enchantment",3);
  set_wield((:TO,"wieldme":));
  set_unwield((:TO,"removeme":));
  set_hit((:TO,"hitme":));
}

int wieldme()
{
  if(ETO->query_lowest_level() < 20) {
    tell_object(ETO,"You are not powerful enough to wield such a weapon.");
    return 0;
  }
  tell_object(ETO,"The sword %^BOLD%^shimmers%^RESET%^ for a moment as you"+
	      " grasp its hilt.");
  tell_room(environment(ETO),"The sword %^BOLD%^shimmers%^RESET%^ for a"+
	    " moment as "+ETO->query_cap_name()+" grasps the hilt.",ETO);
  return 1;
}

int removeme()
{
  tell_object(ETO,"%^BOLD%^%^BLUE%^You feel mundane again as you release"+
	      " the incredible sword.");
  return 1;
}

int hitme(object targ)
{
  object *foes;
  int damage, i, j;
  
  foes = ETO->query_attackers();

  if(!random(7)) {
    set_property("magic",1);
    tell_object(ETO,"%^BOLD%^The Starlight Sword slices through "+targ->query_cap_name()+"'s"+
		" armor!");
    tell_object(targ,"%^BOLD%^"+ETO->query_cap_name()+"'s Starlight Sword"+
		" slices through your armor!");
    tell_room(environment(ETO),"%^BOLD%^"+ETO->query_cap_name()+"'s Starlight Sword"+
	      " slices through "+targ->query_cap_name()+"'s armor!",({ETO,targ}));
    targ->do_damage("torso",random(5)+3);
    remove_property("magic");
    return 1;
  }
  if(!random(12)) {
    set_property("magic",1);
    tell_object(ETO,"%^BOLD%^%^RED%^Sparks fly from your Starlight Sword,"+
		" burning into "+targ->query_cap_name()+".");
    tell_object(targ,"%^BOLD%^%^RED%^Sparks fly from "+ETO->query_cap_name()+"'s"+
		" Starlight Sword, burning into you!");
    tell_room(environment(ETO),"%^BOLD%^%^RED%^Sparks fly from "+ETO->query_cap_name()+"'s"+
	      " Starlight Sword, burning into "+targ->query_cap_name()+".",({ETO,targ}));
    targ->do_damage("torso",random(6)+4);
    remove_property("magic");
    return 1;
  }
  if(!random(23)) {
    set_property("magic",1);
    tell_object(ETO,"%^BLUE%^The sword glows with %^BOLD%^%^WHITE%^starlight%^RESET%^%^BLUE%^"+
		" as it strikes "+targ->query_cap_name()+" with incredible power.");
    tell_object(targ,"%^BLUE%^"+ETO->query_cap_name()+"'s sword glows with"+
		" %^BOLD%^%^WHITE%^starlight%^RESET%^%^BLUE%^ as it strikes you with"+
		" incredible power.");
    tell_room(environment(ETO),"%^BLUE%^"+ETO->query_cap_name()+"'s sword"+
	      " glows with %^BOLD%^%^WHITE%^starlight%^RESET%^%^BLUE%^ as it strikes"+
	      " "+targ->query_cap_name()+" with incredible power.",({ETO,targ}));
    if(!targ->query_paralyzed()) {
      if(ETO->is_class("mage")) {
	tell_object(ETO,"The sword plants the words of a spell into your mind"+
		    " and you begin to say them.");
	new("/cmds/wizard/_prismatic_spray")->use_spell(ETO,targ->query_name(),25);
      }
      else {
	tell_object(ETO,"The sword overtakes you as you suddenly begin to say"+
		    " the words to a spell.");
	new("/cmds/wizard/_prismatic_spray")->use_spell(ETO,targ->query_name(),ETO->query_lowest_level());
      }
    }
    targ->do_damage("torso",random(8)+6);
    remove_property("magic");
    return 1;
  }
  if(!random(30)) {
    set_property("magic",1);
    if(query_night() == 1 && environment(ETO)->query_property("indoors")) {
      tell_object(ETO,"%^BOLD%^The Starlight Sword lets out a piercing"+
		  " scream, sending your opponents to their knees as they're pelted"+
		  " with falling %^RED%^st%^YELLOW%^a%^RED%^rb%^YELLOW%^u%^RED%^rsts%^WHITE%^!");
      j = sizeof(foes);
      for(i=0;i<j;i++) {
	tell_object(foes[i],"%^BOLD%^"+ETO->query_cap_name()+"'s Starlight"+
		    " Sword lets out a shrill scream.\n"+
		    "%^BOLD%^%^RED%^St%^YELLOW%^a%^RED%^rb%^YELLOW%^u%^RED%^rsts%^WHITE%^"+
		    " begin falling from the sky and hitting you!");
	if(!"daemon/saving_d"->saving_throw(foes[i],"spell",-3)) {
	  foes[i]->do_damage("torso",random(8)+10);
	}
	else {
	  foes[i]->do_damage("torso",(random(8)+10)/2);
	}
      }
      tell_room(environment(ETO),"%^BOLD%^"+ETO->query_cap_name()+"'s"+
		" Starlight Sword lets out a piercing scream and"+
		" %^RED%^st%^YELLOW%^a%^RED%^rb%^YELLOW%^u%^RED%^rsts%^WHITE%^ begin"+
		" falling from the sky and pelting "+ETO->query_possessive()+""+
		" attackers!",({ETO})+ foes);
      remove_property("magic");
      return 1;
    }
    tell_object(ETO,"%^YELLOW%^The Starlight Sword %^WHITE%^shimmers%^YELLOW%^"+
		" with starlight as it slices "+targ->query_cap_name()+" deeply.");
    tell_object(targ,"%^YELLOW%^"+ETO->query_cap_name()+"'s Starlight Sword"+
		" %^WHITE%^shimmers%^YELLOW%^ with starlight as it slices you deeply.");
    tell_room(environment(ETO),"%^YELLOW%^"+ETO->query_cap_name()+"'s"+
	      " Starlight Sword %^WHITE%^shimmers%^YELLOW%^ with starlight as it"+
	      " slices "+targ->query_cap_name()+" deeply.",({ETO,targ}));
    targ->do_damage("torso",random(5)+5);
    remove_property("magic");
    return 1;
  }
}
