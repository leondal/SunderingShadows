#include <std.h>
inherit "/d/common/obj/weapon/warhammer.c";

string OWNER;

void init() {
    ::init();
    if(interactive(TP) && TP==environment(TO) && !OWNER) OWNER = TPQN;
}
create() {
    	::create();
   	set_id(({ "warhammer","hammer","war hammer","warhammer","runecarved warhammer"}));
   	set_name("adamantine warhammer");
   	set_obvious_short("%^YELLOW%^An %^BOLD%^%^BLACK%^adamantine%^YELLOW%^ warhammer%^RESET%^");
   	set_short("%^YELLOW%^Runecarved Warhammer%^RESET%^");
   	set_long("%^BOLD%^%^YELLOW%^This is an adamantine warhammer.%^RESET%^\n"+
    		"This warhammer is beautifully crafted of the rarest metal "+
    		"known to the realms  The adamantine surface is brightly "+
    		"polished and shines brightly.  Dwarven runes of power cover "+
    		"the face of the hammer and the shaft.  The hammer has a long, "+
    		"thick head on one side counterbalanced on the other by a heavy "+
    		"spike.  The head of the hammer is mounted onto a solid oak shaft.%^RESET%^");
   	set_lore("One of the finest examples of dwarven workmanship, the runes "+
                   "of power imbue the weapon with the force of a dwarven smith and "+
   		"in the hands of someone skilled with hammers it can knock "+
   		"opponents senseless.");
   	set_value(2000);
    	set_property("enchantment",3);
    	set_wield((:TO,"wield_func":));
    	set_unwield((:TO,"unwield_func":));
    	set_hit((: TO,"extra_hit" :));
}
int wield_func(string str){
	int align;

	align = ETO->query_alignment();

    	if((int)ETO->query_level() < 20) {
    		notify_fail("You may not wield such a fine weapon!");
    		return 0;
    	}
     	if(interactive(TP) && (string)TP->query_name() != OWNER){
		tell_object(TP,"%^BOLD%^%^CYAN%^The hammer does not recognize you "+
			"as its owner and explodes forcefully!");
    		set_property("magic",1);
    		ETO->do_damage("torso",random(56));
    		set_property("magic",-1);
		TO->remove();
		return 0;
    	}
	switch(align) {
		case 1: case 4: case 7:
			tell_object(ETO,"%^BOLD%^The dwarven runes of power "+
				"flash briefly with a bright white light.");
			tell_room(environment(ETO),"%^BOLD%^The runes "+
				"on "+ETO->QCN+"'s hammer flash with a "+
				"bright white light briefly.",ETO);
			set_item_bonus("magic resistance",1);
			return 1;

		case 2: case 5: case 8:
			tell_object(ETO,"%^BOLD%^%^YELLOW%^The dwarven runes of power "+
				"flash briefly with a yellow light.");
			tell_room(environment(ETO),"%^BOLD%^%^YELLOW%^The runes "+
				"on "+ETO->QCN+"'s hammer flash with a "+
				"yellow light briefly.",ETO);
			set_item_bonus("magic resistance",1);
			return 1;

		case 3: case 6: case 9:
			tell_object(ETO,"%^BOLD%^%^RED%^The dwarven runes of power "+
				"glow an ominous crimson.");
			tell_room(environment(ETO),"%^BOLD%^%^RED%^The runes "+
				"on "+ETO->QCN+"'s hammer glow an ominous "+
				"crimson.",ETO);
			set_item_bonus("magic resistance",-1);
			return 1;

		default:
			tell_object(ETO,"See a Wiz about this weapon.  Your alignment "+
				"is whacked.");
			return 0;
	}
}
int unwield_func(string str){
	tell_object(ETO,"%^BOLD%^You feel a jolt to your arm as you "+
		"unwield the hammer.");
	return 1;
}
int extra_hit(object victim){
    	if(!objectp(TO)) return 1;
    	if(!objectp(ETO)) return 1;
    	if(!objectp(victim)) return 1;
   	if(!random(11)){
     		tell_object(ETO,"%^BOLD%^%^YELLOW%^You stagger "+victim->QCN+" with "+
     			"a viscious swing of your hammer!%^RESET%^");
     		tell_object(victim,"%^BOLD%^%^RED%^"+ETO->QCN+" staggers "+
     			"you with a vicious swing "+
     			"of "+ETO->QP+" hammer!%^RESET%^");
     		tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+" "+
     			"staggers "+victim->QCN+" with a vicious swing of "+
     			""+ETO->QP+" hammer!%^RESET%^",({ETO,victim}));
			if(!"/daemon/saving_throw_d.c"->fort_save(victim,-20))
            victim->set_paralyzed(random(4)+2,"%^BOLD%^%^RED%^Your head still rings "+
        		"from the blow of the hammer!");
    		
  			return random(2)+1;
    	}else return 0;
}
