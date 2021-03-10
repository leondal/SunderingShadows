//changed to inherit standard longsword.  Circe 5/9/04
#include <std.h>
inherit "/d/common/obj/weapon/shortsword";
create() {
    ::create();
set_id(({"blade","flametooth","sword","shortsword","short sword","flamberge shortsword","flame"}));
set_name("flaming short sword");
set_obvious_short("%^RESET%^%^RED%^A flamberge shortsword%^RESET%^");
    set_short("%^RESET%^%^RED%^F%^BOLD%^l%^RESET%^%^RED%^a%^ORANGE%^m%^BOLD%^"+
"%^RED%^e%^RESET%^%^RED%^t%^ORANGE%^o%^BOLD%^o%^RESET%^%^RED%^t%^BOLD%^"+
"h%^RESET%^");
 set_long("%^RED%^Forged from fever iron, this short sword has a "+
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
             );
    set_lore("Forged with the heat of the fire and inscribed with ancient"+
" runes of power, Flametooth was once a fiersome weapon used to "+
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
    if((int)ETO->query_level() < 12) {
        tell_object(ETO,"You may not wield such a fine weapon!");
        return 0;
    }
    tell_object(ETO,"%^BOLD%^%^RED%^You wield the sword and feel a "+
       "warmth course through your frame! \n Eldritch flames leap and "+
       "dance along the blade!%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" wields the blade and "+
       "red and %^BLUE%^blue %^RED%^flames dance along the blade.%^RESET%^",TP);
    return 1;
}
int unwield_func(string str) {
    tell_object(ETO,"%^RED%^You unwield the weapon and feel the "+
       "warmth recede back into the metal!");
    tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" unwields the sword "+
       "and red and blue flames flicker reluctantly and then "+
       "disappear.%^RESET%^",ETO);
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
			" "+ETO->QCN+" unleashes a %^B_RED%^%^YELLOW%^fiery%^RESET%^%^RED%^ blast at you!");
      	tell_room(environment(ETO),"%^RED%^Leveling "+ETO->QP+" sword at "+victim->QCN+","+
			" "+ETO->QCN+" unleashes a %^B_RED%^%^YELLOW%^fiery%^RESET%^%^RED%^ blast.",({ETO,victim}));
        			victim->do_damage(victim->return_target_limb(),random(6)+6);
		break;
	}
    return 1;
   }
}
