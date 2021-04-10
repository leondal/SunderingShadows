//Updated Azure Plate - Chainmail now - Cythera 11/05
#include <std.h>
inherit "/d/common/obj/armour/chain";

void create() {
	::create();
    	set_name("azure armor");
    	set_id(({ "azure armor", "armour", "armor", "azure chain", "chain", "azure", "azure mail", "azure chainmail", "azure armour", "chainmail", "mail", "chain of the azure seas" }));
    	set_short("%^RESET%^%^CYAN%^Chainmail of the %^BOLD%^%^BLUE%^A%^RESET%^%^CYAN%^"+
		"z%^BOLD%^%^BLUE%^u%^RESET%^%^CYAN%^r%^BOLD%^"+
		"%^BLUE%^e%^RESET%^%^CYAN%^ Seas%^RESET%^");
    	set_obvious_short("%^RESET%^%^CYAN%^A suit of a%^BOLD%^%^BLUE%^"+
		"z%^RESET%^%^CYAN%^u%^BOLD%^%^BLUE%^r%^RESET%^"+
		"%^CYAN%^e blue chainmail%^RESET%^");
    	set_long("%^CYAN%^This %^BOLD%^r%^BLUE%^i%^WHITE%^p%^RESET%^"+
		"%^CYAN%^p%^BLUE%^l%^BOLD%^i%^CYAN%^n%^BLUE%^g%^RESET%^"+
		"%^CYAN%^ blue suit of chainmail almost seems to be made"+
		" entirely out of a fluid %^BOLD%^liquid%^RESET%^%^CYAN%^.  The full"+
		" suit of chainmail includes a long sleeved shirt and a pair"+
		" of chainmail leggings, creating a suit that looks quite "+
		"protective.  The pieces of armor are not padded, leaving "+
		"one to wonder about how comfortable such a suit might be.  "+
		"Each link in the armor %^BOLD%^%^BLUE%^r%^CYAN%^i%^BLUE%^p"+
		"%^CYAN%^p%^BLUE%^l%^CYAN%^e%^BLUE%^s%^RESET%^%^CYAN%^ in a "+
		"fashion that seems as if the liquid used to craft it is "+
		"constantly in motion.  Light bounces off of the surface of"+
		" the chainmail, creating bright %^WHITE%^%^BOLD%^shimmers"+
		"%^RESET%^%^CYAN%^.\n%^RESET%^");
	set_lore("This mystical armor was created from a liquid that is "+
		"rumored to exist beneath the Crystalline Tower of the Black"+
		" Dawn on Attaya Island.  The armor has extremely lustrous "+
		"qualities, and is very durable.  In only a process that "+
		"those of the Black Dawn Tower know, the liquid is enchanted "+
		"in a way that creates a suit of armor that fits the form of "+
		"it's owner perfectly.  So perfectly in fact that padding "+
		"underneath the armor is not even need.  The chainmail stays "+
		"cool even in a blazing inferno, making for a comfortable suit "+
		"that many warriors would pay a high price for.");
    set_property("enchantment",5);
    set_item_bonus("constitution",2);
    set_value(5000);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    set_struck((:TO,"struck":));
}
int wear_func(){
        if((int)ETO->query_level()<31){
                        tell_object(ETO,"The armor is too fine for you to wear yet.");
                        return 0;
                }
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^The full suit of "+
		"chainmail ripples as it adjusts itself to fit "+ETOQCN+".",ETO);
     	tell_object(ETO,"%^BOLD%^%^CYAN%^You feel the cooling sensation"+
		" of the chainmail as it starts to ripple, adjusting "+
		"to fit your body.");
      return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+"'s chainmail "+
		"ripples and expands, allowing "+ETO->QO+" to slip out of the "+
		"full suit of armor.",ETO);
     	tell_object(ETO,"%^BOLD%^%^CYAN%^The chainmail ripples and expands,"+
		" allowing you to slip out of the leggings and shirt.");
     	return 1;
}

int struck(int damage, object what, object who){
    
    object owner;
    
    owner = environment(this_object());
    
    if(!random(5) && owner){
      tell_room(environment(owner),"%^RESET%^%^CYAN%^"+owner->QCN+"'s chainmail"+
		", ripples against the blow as if asorbing the force!%^RESET%^",({who,owner}));
	  tell_object(who,"%^RESET%^%^CYAN%^As you hit "+owner->QCN+", the armor ripples "+
		"under your blow, asorbing the damage!");
	  tell_object(owner,"%^RESET%^%^CYAN%^The chainmail ripples under the weight of the "+
		"blow, asorbing the damage!%^RESET%^");
   	  return 0;
    }
    
    return damage;
}
