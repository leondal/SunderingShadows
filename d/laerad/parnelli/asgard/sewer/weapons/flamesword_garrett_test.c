#include <std.h>
inherit "/std/weapon";
create(){
    	::create();
    	set_id(({"blade","flametongue","sword","longsword","long sword","flame"}));
    	set_name("flaming long sword");
    	set_short("%^RESET%^%^RED%^Flametongue%^RESET%^");
    	set_long("This longsword is extremely sharp looking, the metal has a bluish "+
            "tinge as would any metal pulled freshly from the blacksmith's forge.  "+
            "Staring at the blade long enough you can see what appears to be waves "+
            "of heat emanating from the metal.");
    	set_wc(1,8);
    	set_large_wc(1,12);
    	set_property("enchantment",2);
    	set_weight(4);
    	set_weapon_speed(5);
    	set_size(2);
    	set("value",1500);
    	set_type("slashing");
    	set_wield((:TO,"wield_func":));
    	set_unwield((:TO,"unwield_func":));
    	set_hit((: TO,"extra_hit" :));
    	set_prof_type("medium blades");
}
int wield_func(string str){
    	if((int)ETO->query_level() < 15) {
    		notify_fail("You may not wield such a fine weapon!");
    	return 0;
    	}
    	tell_object(TP,"%^BOLD%^%^RED%^You wield the long sword and feel a warmth "+
    		"course through your frame!  Eldritch flames leap and dance along "+
    		"your blade!%^RESET%^");
    	tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" wields the blade and red and blue "+
    		"flames dance along the blade.%^RESET%^",TP);
    	ETO->add_sight_bonus(2);
    	return 1;
}
int unwield_func(string str){
    	tell_object(TP,"%^RED%^You unwield the weapon and feel the warmth recede "+
    		"back into the metal!");
    	tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" unwields the sword and red and "+
    		"blue flames flicker reluctantly and then disappear.%^RESET%^",TP);
    	ETO->add_sight_bonus(-2);
    	return 1;
}
int extra_hit(object victem){
        if(!objectp(TP)) return 1;
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(victem)) return 1;
    	if(!random(6)){
     	tell_object(ETO,"%^BOLD%^%^RED%^You watch grimly as flames leap from your "+
     		"blade and smash into your foe!%^RESET%^");
     	tell_object(victem,"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" swings "+
     		""+ETO->query_possessive()+" blade at you and flames leap out and "+
     		"engulf your body!%^RESET%^");
     	message("other_action","%^BOLD%^%^RED%^" +TPQCN+" shoots flames "+
     		"onto "+victem->query_cap_name()+"'s body "+
     		"with "+ETO->query_possessive()+" flaming "+
		"weapon!%^RESET%^",environment(victem),(({ETO,victem})));
     	victem->do_damage("torso",random(4)+4);
  	return 0;
    	}else return 0;
}
