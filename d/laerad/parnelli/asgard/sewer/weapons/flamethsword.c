//changed to inherit two_hand_sword.  Circe 5/9/04
#include <std.h>
inherit "/d/common/obj/weapon/two_hand_sword";
create() {
    ::create();
    set_id(({"two handed sword","sword","flamebite","flame","flameberge sword","flameberge two handed sword"}));
    set_name("flameberge two handed sword");
    set_obvious_short("%^RESET%^%^RED%^A flamberge two-handed sword%^RESET%^");
    set_short("%^RESET%^%^RED%^F%^BOLD%^l%^RESET%^%^RED%^a%^ORANGE%^m%^BOLD%^"+
      "%^RED%^e%^RESET%^%^RED%^b%^ORANGE%^i%^BOLD%^t%^RESET%^%^RED%^e%^RESET%^");
    set_long("%^RED%^Forged from fever iron, this two handed sword has a "+
             "%^BOLD%^%^WHITE%^brilliant %^RED%^red%^RESET%^%^RED%^ luster"+
             ".  The blade of this impressive sword is made in a wave-like"+
             " pattern, known as %^ORANGE%^flamberge%^RED%^.  Gilded with"+
             " %^BOLD%^%^WHITE%^mithril%^RESET%^%^RED%^, light ripples "+
             "off the blade.  %^BOLD%^%^BLUE%^Runes%^RESET%^%^RED%^ of "+
             "power are etched deep into the metal along the edge of the"+
             " sword, written in an ancient language that is has fallen "+
             "into antiquities.  The hilt and pommel of the blade is made"+
             " from fever iron as well.  Rippled textured %^BOLD%^%^WHITE%^"+
             "mithril%^RESET%^%^RED%^ wire wraps around to create a firm"+
             " handhold of the blade.  Twin %^ORANGE%^topazes%^RED%^ are set"+
             " into the cross pommel of the sword.  A %^BLUE%^b%^CYAN%^l%^BLUE%^"+
             "u%^BOLD%^i%^CYAN%^s%^RESET%^%^BLUE%^h%^RED%^ tinge radiates from"+
             " the blade, as if it was fresh from the forge.%^RESET%^"
             //"%^CYAN%^This sharp two handed sword glows with a "+
             //"bluish tinge as though it were just pulled from the "+
             //"blacksmith's forge.  Strangely, though, the metal is "+
             //"cool and smooth to the touch.  It is fitted into a "+
             //"wire-wrapped hilt that provides a firm grip."
             );
    set_lore("Forged with the heat of the fire and inscribed with ancient"+
            " runes of power, Flamebite was once a fiersome weapon used to "+
            "push back the trolls that thrived around the city of Asgard.  "+
            "The weaposn were commonly made to arm the guards and rangers "+
            "that patrolled the forests around Asgard.  Troll's weakness to"+
            " fire is well known, so it is no shock that these blades were "+ 
            "successful in quelling the large number of trolls.");
    set_property("lore",9);
    set_property("enchantment",2);
	set_item_bonus("sight bonus",2);
    set_value(1500);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((: TO,"hit_func" :));
}
int wield_func(string str) {
    if((int)ETO->query_level() < 14) {
        tell_object(ETO,"You may not wield such a fine weapon!");
        return 0;
    }
    tell_object(ETO,"%^BOLD%^%^RED%^You wield the sword and feel a "+
       "warmth course through your frame! \n Eldritch flames leap and "+
       "dance along the blade!%^RESET%^");
    tell_room(environment(ETO),"%^BOLD%^%^RED%^"+TPQCN+" wields the flamberge sword and "+
              "red and blue flames dance along the blade wildly.%^RESET%^",TP);
    return 1;
}
int unwield_func(string str) {
    tell_object(ETO,"%^RED%^You unwield the sword and feel the warmth recede "+
                "back into the metal!");
    tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" unwields the sword and red and "+
              "blue flames reluctantly disappear.%^RESET%^",ETO);
    return 1;
}
int hit_func(object victim) {
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(victim)) return 1;
   if(random(1000) < 150){
   	switch(random(40))
	{	
		default:
  		tell_object(ETO,"%^BOLD%^%^RED%^You watch grimly as flames leap from your "+
            	"sword and smash into "+victim->QCN+"!%^RESET%^");
        	tell_object(victim,"%^BOLD%^%^RED%^"+ETOQCN+" swings "+ETO->QP+" "+
            	"sword at you and flames leap out and engulf your body!%^RESET%^");
      	tell_room(environment(ETO),"%^BOLD%^%^RED%^" +ETOQCN+" shoots "+
            	"flames onto "+victim->QCN+"'s body with "+ETO->QP+" flaming "+
            	"sword!%^RESET%^",({ETO,victim}));
       			victim->do_damage(victim->return_target_limb(),random(4)+2);
	 	break;
		case 34..39:
      	tell_object(ETO,"%^RED%^You level your sword at "+victim->QCN+", "+
			"unleashing a %^B_RED%^%^YELLOW%^fiery%^RESET%^%^RED%^ blast at "+victim->QO+".");
      	tell_object(victim,"%^RED%^Leveling "+ETO->QP+" sword at you,"+
			" "+ETO->QCN+" unleashes a %^B_RED%^%^YELLOW%^fiery%^RESET%^%^RED%^blast at you!");
      	tell_room(environment(ETO),"%^RED%^Leveling "+ETO->QP+" sword at "+victim->QCN+","+
			" "+ETO->QCN+" unleashes a %^B_RED%^%^YELLOW%^fiery%^RESET%^%^RED%^ blast.",({ETO,victim}));
        			victim->do_damage(victim->return_target_limb(),random(6)+6);
		break;
	}
   	
    return 1;
   }
}
