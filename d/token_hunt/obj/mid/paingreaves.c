#include <std.h>
inherit "/d/common/obj/armour/leather_greaves.c";

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^S%^RESET%^p%^BOLD%^ik%^RESET%^e%^BOLD%^%^BLACK%^d gr%^RESET%^e%^BOLD%^a%^RESET%^v%^BOLD%^%^BLACK%^es%^RESET%^");
	set_id(({ "greaves", "spiked greaves" }));
	set_short("%^BOLD%^%^BLACK%^greaves of a %^RESET%^%^RED%^to%^BOLD%^rm%^RESET%^%^RED%^e%^BOLD%^%^RED%^nt%^RESET%^%^RED%^ed %^BOLD%^%^BLACK%^soul%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^s%^RESET%^p%^BOLD%^ik%^RESET%^e%^BOLD%^%^BLACK%^d gr%^RESET%^e%^BOLD%^a%^RESET%^v%^BOLD%^%^BLACK%^es%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^Made to protect the shins and knees, these greaves are crafted from leather dyed jet black. Small but sharp "
"%^BOLD%^%^BLACK%^si%^RESET%^lv%^BOLD%^er sp%^RESET%^ik%^BOLD%^%^BLACK%^es%^BOLD%^%^BLACK%^ protrude from the surface. The %^RESET%^%^RED%^t"
"%^BOLD%^%^BLACK%^ip%^RESET%^%^RED%^s%^BOLD%^%^BLACK%^ of the shining spikes have been dyed a deep shade of %^RESET%^%^RED%^crim%^BOLD%^s"
"%^RESET%^%^RED%^on%^BOLD%^%^BLACK%^, as if they have been %^RESET%^eternally%^BOLD%^%^BLACK%^ tainted with %^RESET%^%^RED%^blood%^BOLD%^%^BLACK%^"
". The flexibility of the leather would not hinder movement while offering protection to the wearer.%^RESET%^");
   set_value(0);
	set_lore("%^BOLD%^%^BLACK%^The greaves of a tormented soul were highly prized by those of Loviatar's faith because it is rumored that they "
"had been blessed in the blood of a sacrifice to the Maiden of Pain. Some even insist that they can still hear the screams of the hapless victim "
"to this very day.  Greaves such as these, and any other sundry Lovite artifacts have become highly sought after in the years after the destruction "
"of Loviatar at the hands of Durias.%^RESET%^");
	set_property("lore difficulty",15);
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
    set_overallStatus(220);
    set_property("no disenchant",1);
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" smiles darkly.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^RED%^A %^BOLD%^%^BLACK%^dark chorus%^RESET%^%^RED%^ of %^BOLD%^%^RED%^tortured screams%^RESET%^%^RED%^ fills your mind as you fasten the greaves.%^RESET%^");
	ETO->cause_typed_damage(ETO, "torso", roll_dice(1, 5) - 1, "mental");
	ETO->set_property("evil item",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" looks momentarily distressed.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You remorsefully remove the "+query_short()+"%^BOLD%^%^BLACK%^.%^RESET%^");
	ETO->set_property("evil item",-1);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 400){
	tell_room(environment(query_worn()),"%^BOLD%^%^RED%^The %^RESET%^silver spikes%^BOLD%^%^RED%^ of "+ETOQCN+"'s%^BOLD%^%^RED%^ "+query_short()+"%^BOLD%^%^RED%^ tears into "+who->QCN+"%^BOLD%^%^RED%^'s flesh, splattering %^RESET%^%^RED%^blood%^BOLD%^%^RED%^ everywhere!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^RED%^You bash your knee into "+who->QCN+"%^RESET%^%^BOLD%^%^RED%^, ripping into the flesh.%^RESET%^");
	tell_object(who,"%^BOLD%^%^RED%^You feel your flesh ripped asunder as "+ETOQCN+"%^BOLD%^%^RED%^ bashes you with "+query_short()+"%^BOLD%^%^RED%^.%^RESET%^");
		who->cause_typed_damage(who, "torso", roll_dice(1, 7) + 19, "piercing");
return damage;	}
}

int is_metal() { return 0; }
