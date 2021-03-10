#include <std.h>
//#include "../ruins.h"
#include "/d/antioch/ruins/ruins.h"
inherit "/d/common/obj/weapon/longsword.c";

void create()
{
  ::create();
  set_name("shining longsword");
  set_obvious_short("%^BOLD%^%^BLUE%^A %^WHITE%^shining%^BLUE%^ longsword%^RESET%^");
  set_short("%^BOLD%^%^BLUE%^St%^WHITE%^a%^BLUE%^rlight Sw%^WHITE%^o%^BLUE%^rd%^RESET%^");
  set_id(({"sword","starlight sword","Starlight Sword"}));
  set_long(
	   "This sword is almost enchanting, it is made out of some opaque alloy and"+
	   " has been forged with %^BOLD%^stardust%^RESET%^ that %^BOLD%^shimmers%^RESET%^ along the"+
	   " length of the blade. The hilt is made of gilded %^BOLD%^mithril%^RESET%^"+
	   " and has a %^BOLD%^%^BLUE%^star sapphire%^RESET%^ set into the pommel."
	   );
	set_lore("Seen as a holy blade in the church of banished goddess of magic, the Starlight "+
		"Sword is a deeply revered.  Often the favored weapon for knights"+
		" of the church, as well as many bards, rangers, and warriors, "+
		"the Starlight Sword is said to have been woven from the weave "+
		"itself.  Enchanted with celestial powers, the Starlight Sword "+
		"has served the followers of The Lady of Mysteries well.");
	set_property("lore",13);
  set_value(2000);
  set_property("enchantment",3);
  set_wield((:TO,"wieldme":));
  set_unwield((:TO,"removeme":));
  set_hit((:TO,"hitme":));
}

int wieldme()
{
  if(ETO->query_lowest_level() < 15) {
    tell_object(ETO,"You are not powerful enough to wield such a weapon.");
    return 0;
  }
  tell_object(ETO,"The sword %^BOLD%^shimmers%^RESET%^ for a moment as you"+
	      " grasp its hilt.");
  tell_room(environment(ETO),"The sword %^BOLD%^shimmers%^RESET%^ for a"+
	    " moment as "+ETO->QCN+" grasps the hilt.",ETO);
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
		//added to prevent occassional bugging with stab should return 0 if the target isn't
		//an object - apparently some problem with stab in general - Saide - 11/22/03
  if(!objectp(targ)) return 0;
  foes = ETO->query_attackers();

  if(!random(7)) {
    set_property("magic",1);
    tell_object(ETO,"%^BOLD%^The Starlight Sword slices through "+targ->QCN+"'s"+
		" armor!");
    tell_object(targ,"%^BOLD%^"+ETO->QCN+"'s Starlight Sword"+
		" slices through your armor!");
    tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+"'s Starlight Sword"+
	      " slices through "+targ->QCN+"'s armor!",({ETO,targ}));
    targ->do_damage("torso",random(5)+3);
    set_property("magic",-1);
    return 1;
  }
  if(!random(12)) {
    set_property("magic",1);
    tell_object(ETO,"%^BOLD%^%^RED%^Sparks fly from your Starlight Sword,"+
		" burning into "+targ->QCN+".");
    tell_object(targ,"%^BOLD%^%^RED%^Sparks fly from "+ETO->QCN+"'s"+
		" Starlight Sword, burning into you!");
    tell_room(environment(ETO),"%^BOLD%^%^RED%^Sparks fly from "+ETO->QCN+"'s"+
	      " Starlight Sword, burning into "+targ->QCN+".",({ETO,targ}));
    targ->do_damage("torso",random(6)+4);
    set_property("magic",-1);
    return 1;
  }
  if(!random(23)) {
    set_property("magic",1);
    tell_object(ETO,"%^BLUE%^The sword glows with %^BOLD%^%^WHITE%^starlight%^RESET%^%^BLUE%^"+
		" as it strikes "+targ->QCN+" with incredible power.");
    tell_object(targ,"%^BLUE%^"+ETO->QCN+"'s sword glows with"+
		" %^BOLD%^%^WHITE%^starlight%^RESET%^%^BLUE%^ as it strikes you with"+
		" incredible power.");
    tell_room(environment(ETO),"%^BLUE%^"+ETO->QCN+"'s sword"+
	      " glows with %^BOLD%^%^WHITE%^starlight%^RESET%^%^BLUE%^ as it strikes"+
	      " "+targ->QCN+" with incredible power.",({ETO,targ}));
    if(!targ->query_paralyzed()) {
      if(ETO->is_class("mage")) {
	  tell_object(ETO,"The sword plants the words of a spell into your mind"+
		    " and you begin to say them.");
        new("/cmds/spells/p/_prismatic_spray")->use_spell(ETO,targ,ETO->query_level(),100,"mage");
        ETO->set_casting(0);
      }
      else {
	  tell_object(ETO,"The sword overtakes you as you suddenly begin to say"+
		    " the words to a spell.");
        new("/cmds/spells/p/_prismatic_spray")->use_spell(ETO,targ,20,100,"mage");
        ETO->set_casting(0);
      }
    }
    targ->do_damage("torso",random(8)+6);
    set_property("magic",-1);
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
	tell_object(foes[i],"%^BOLD%^"+ETO->QCN+"'s Starlight"+
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
      tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+"'s"+
		" Starlight Sword lets out a piercing scream and"+
		" %^RED%^st%^YELLOW%^a%^RED%^rb%^YELLOW%^u%^RED%^rsts%^WHITE%^ begin"+
		" falling from the sky and pelting "+ETO->QP+""+
		" attackers!",({ETO})+ foes);
      set_property("magic",-1);
      return 1;
    }
    tell_object(ETO,"%^YELLOW%^The Starlight Sword %^WHITE%^shimmers%^YELLOW%^"+
		" with starlight as it slices "+targ->QCN+" deeply.");
    tell_object(targ,"%^YELLOW%^"+ETO->QCN+"'s Starlight Sword"+
		" %^WHITE%^shimmers%^YELLOW%^ with starlight as it slices you deeply.");
    tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+"'s"+
	      " Starlight Sword %^WHITE%^shimmers%^YELLOW%^ with starlight as it"+
	      " slices "+targ->QCN+" deeply.",({ETO,targ}));
    targ->do_damage("torso",random(5)+5);
    set_property("magic",-1);
    return 1;
  }
}
