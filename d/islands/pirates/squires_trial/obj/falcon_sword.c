#include <std.h>
inherit "/d/common/obj/weapon/two_hand_sword";



void create() {

	::create();

	set_name("falcon sword");
	set_id( ({"sword","two-handed sword","two handed sword","falcon sword","sword of the falcon"}) );
	set_obvious_short("%^RESET%^%^CYAN%^winged two-handed sword%^RESET%^%^WHITE%^");
	set_short("%^RESET%^%^CYAN%^Segnor's %^RESET%^%^ORANGE%^Fa%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^co%^BOLD%^%^BLACK%^n S%^RESET%^%^ORANGE%^wo%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^d%^RESET%^%^WHITE%^");
	set_long(
	        "%^RESET%^%^CYAN%^"
          "This is a massive, wide bladed sword.  It is made of a quality " +
          "blued steel.  The tip is slightly flared like a narrow diamond " + 
          "shape.  There is a deep blood groove, the entire length of the " +
          "blade, and although the edge is honed very sharp, it is not " +
          "delicate like a razor, to prevent chipping and dulling in combat." +
          "  The " +
          "%^RESET%^%^ORANGE%^bronze " +
          "%^RESET%^%^CYAN%^crosspiece is modeled after a perfect pair of " +
          "%^RESET%^%^ORANGE%^fa%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^c" +
          "o%^BOLD%^%^BLACK%^n w%^RESET%^%^ORANGE%^i" +
          "n%^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^s " +
          "%^RESET%^%^CYAN%^spread as if for flight.  The hilt is shaped " +
          "like an elongated barrel providing a good grip area, and the " +
          "pommel flares to provide support for the off " +
          "hand.%^RESET%^%^WHITE%^\n"
	);
	set_lore( 
       "Segnor Tamalitrel was a name not associated with The Order of Ten " +
       "until recently.  Almost nothing is known of him, except that he was " +
       "not only a steadfast knight, but a skilled architect.  No legends " +
       "surround his blade, perhaps due to his more academic service to " +
       "the order."
	);
	set_property("enchantment",2);
	set_value(1000);
	//set_wield("");	
	//set_unwield("");
	set_hit((:TO,"special":));
  set_wield((:TO,"wieldsword":));
  set_unwield((:TO,"unwieldsword":));
	set_property("lore difficulty",19);
}




int wieldsword() 
{
   if((int)ETO->query_lowest_level() < 15 && ETO) 
   {
      tell_object(ETO,"The blade slips from your grasp!");
      tell_room(EETO, "The sword slips from "+ETO->QCN+"'s hand "
          "as "+ETO->QS+" tries to grasp it.",ETO);
      return 0;
   }
   tell_object(ETO,"%^RESET%^%^CYAN%^You take a firm grip and test the " +
       "sword's balance.%^RESET%^");
   tell_room(EETO,"%^RESET%^%^CYAN%^"+ETOQCN+" takes a firm grip and " +
       "tests the sword's balance.%^RESET%^",ETO);
   return 1;
}

int unwieldsword()
{
   tell_object(ETO,"%^RESET%^%^CYAN%^You relax your fingers as you release" +
       " the sword.%^RESET%^");
   tell_room(EETO,"%^RESET%^%^CYAN%^"+ETO->QCN+" releases the hilt of the " +
       "blade and relaxes "+ETO->QP+" fingers.%^RESET%^",ETO);
   return 1;
}


int special(object targ){

  if(!objectp(targ)) return 0;
	
	
	if(!random(5)){

		tell_object(ETO,"%^RESET%^%^RED%^A falcon's cry screams out as you strike "
		 + targ->query_cap_name() + "!%^RESET%^");

		tell_object(targ,"%^RESET%^%^RED%^" + ETO->query_cap_name() + " sinks " +
		ETO->query_possessive() + " sword into you and it sounds a shrill falcon's cry!%^RESET%^");

		tell_room(environment(ETO),"%^RESET%^%^RED%^" + ETO->query_cap_name() + 
		" strikes " + ETO->query_possessive() + 
		" sword into " + targ->query_cap_name() + 
		" and it emits a falcon's cry!%^RESET%^",({targ,ETO}));
		targ->do_damage("torso",roll_dice(3,6) + 3);
	}

	if(!random(10)){

		tell_object(ETO,"%^RESET%^%^CYAN%^You feel a burst of speed and strike "
		 + targ->query_cap_name() + " again!%^RESET%^");

		tell_object(targ,"%^RESET%^%^CYAN%^" + ETO->query_cap_name() + " sinks " +
		ETO->query_possessive() + " sword into you again with a burst of speed!%^RESET%^");

		tell_room(environment(ETO),"%^RESET%^%^CYAN%^" + ETO->query_cap_name() + 
		" strikes " + ETO->query_possessive() + 
		" sword into " + targ->query_cap_name() + 
		" again with a burst of speed!%^RESET%^",({targ,ETO}));
		ETO->execute_attack();
	}

	return 0;
}


