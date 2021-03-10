//Recoded to fix any bugs and to make it more special
//Cythera 6/06
#include <std.h>
inherit ARMOUR;
//string OWNER;//
//void init() {
  //  ::init();
  // if(interactive(TP) && TP==environment(TO) && !OWNER) OWNER = TPQN;
// }
int FLAG;
void create() {
    ::create();
    set_name("robe of frost");
    set_id(({"frost","robe","frost robe","robe of frost"}));
    set_short("%^BOLD%^%^WHITE%^Robe of %^CYAN%^F%^WHITE%^ro%^CYAN%^s%^WHITE%^t%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^A robe made of fr%^CYAN%^o%^WHITE%^st%^RESET%^");
    set_long("%^BOLD%^%^BLUE%^This thin robe appears to be made entirely out of"+
		" %^BOLD%^%^WHITE%^fr%^CYAN%^o%^WHITE%^st%^BLUE%^, making it seem to"+
		" %^WHITE%^glisten%^BLUE%^ in the light.  The thin cloth radiates a "+
		"%^CYAN%^chill%^BLUE%^, causing %^RESET%^misty %^CYAN%^v%^RESET%^a%^BLUE%^"+
		"p%^RESET%^o%^CYAN%^r%^RESET%^s%^BOLD%^%^BLUE%^ to rise off the surface "+
		"of it.  No matter the heat or temperature though, the robe always holds "+
		"its shape.  The silhouette of the robe is rather simple in form, with "+
		"wide sleeves and a shapeless body.  As the robe moves, the slight "+
		"%^CYAN%^cracking%^BLUE%^ of the %^WHITE%^fr%^CYAN%^o%^WHITE%^st%^BLUE%^"+
		" can be heard, though there are no obvious signs of any damage done to"+
		" the garment.\n%^RESET%^");
    set_ac(0);
    set_weight(5);
    set_value(2500);
    set_property("enchantment",2);
    set_type("clothing");
    set_limbs(({"torso"}));
    set_wear((:TO,"put_on":));
    set_remove((:TO,"take_off":));
    set_struck((:TO,"strike_func":));
FLAG = 0;
}
int put_on(){
	if((int)ETO->query_highest_level() <20){
		tell_object(ETO,"%^BOLD%^%^BLUE%^The robe freezes your hands"+
			" to show you how weak you are!%^RESET%^");
		tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->QCN+"'s "+
			"hands freeze as the robe shows how weak "+ETO->QS+" "+
			"is!%^RESET%^",ETO);
       		ETO->do_damage("torso",(random(20)+15));
       	return 0;
	}
	if((string)ETO->query_diety() == "auril") {
        	tell_object(ETO,"%^BOLD%^%^CYAN%^The soothing chill of the robe"+
			" leaves you feeling blessed.");
            tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->QCN+" a prideful"+
			" grin as "+ETO->QS+" pulls on the robe.",ETO);
			set_size(ETO->query_size());
			FLAG=1;
        return 1;
      }
	if((string)ETO->query_diety() == "kossuth") {
        	tell_object(ETO,"%^BOLD%^%^WHITE%^You can't even bring yourself to wear"+
			" such a befouled robe!");
            tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+""+
                        " glares at the robe with an fiery scowl.",ETO);
	  return 0;			
     	}else{
    		tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETOQCN+" wraps "+
			"the robe around "+ETO->QP+"self and shivers from the"+
			" sudden blast of cold!",ETO);
    		tell_object(ETO,"%^BOLD%^%^BLUE%^As you wrap the robe around "+
			"yourself you are blasted by cold air causing you to "+
			"shiver violently!");
			set_size(TP->query_size());
        return 1;
	}
   // if((string)TP->query_name() != OWNER) {
   // write("%^BOLD%^%^BLUE%^You are not the chosen one.");
    //TO->remove();
    //return 0;
//}
}
int take_off(){
  	tell_object(ETO,"%^BOLD%^%^CYAN%^A sudden warmth comes over you as"+
		" you remove the robe.");
   	tell_room(environment(ETO),""+ETOQCN+" appears to warm up.",ETO);
		FLAG=0;
  return 1;
}
int strike_func(int damage, object what, object who){
        if(random(1000) < 175){
		if(FLAG == 1){
			tell_room(environment(query_worn()),"%^BOLD%^%^WHITE%^The frost on"+
				" "+ETOQCN+"'s intensify with a cracking sound.  Out of the "+
				"robes an orb of pure frost speeds through the air heading for"+
				" "+who->QCN+"!",({ETO,who}));
        		tell_object(ETO,"%^BOLD%^%^WHITE%^The blessed chill of the robes"+
				" intensifies.  Out of the robes an orb of pure frost speeds"+
				" throught he air heading for "+who->QCN+"!");
        		tell_object(who,"%^BOLD%^%^WHITE%^An orb of pure frost flys out"+
				" of "+ETOQCN+"'s robe and speeds through the air towards you!");
					new("/cmds/spells/f/_frost_orb")->use_spell(ETO,who,13,100,"mage");
		return 1;
		}else{
			tell_room(environment(query_worn()),"%^BOLD%^%^WHITE%^A ray of frost"+
				" shoots out of "+ETOQCN+"'s robe, freezing"+
				" "+who->QCN+"!",({ETO,who}));
        		tell_object(ETO,"%^BOLD%^%^WHITE%^You feel a chill deep in your "+
				"bones as a ray of frost shoots out of your robes, "+
				"freezing "+who->QCN+"!");
                        tell_object(who,"%^BOLD%^%^WHITE%^A ray of frost shoots out of "+
                                ""+ETOQCN+"'s robe and freezes you!");
					who->do_damage("torso",random(8)+2);
		return 1;
		}
       }
}
