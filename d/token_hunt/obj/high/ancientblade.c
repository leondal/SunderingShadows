#include <std.h>
inherit "/d/common/obj/weapon/longsword.c";

void create(){
	::create();
	set_name("ancient blade");
	set_id(({ "sword", "blade", "ancient blade", "longsword", "long sword" }));
	set_short("%^BOLD%^%^BLACK%^Ancient Blade%^RESET%^");
	set_obvious_short("%^RESET%^an old sword");
	set_long("%^BOLD%^%^BLACK%^The blade is razorsharp and roughly three feet seven inches long. It is wrought in a strong and %^RESET%^silvery alloy%^BOLD%^%^BLACK%^ "
"that leads one to believe that elves were once involved in it's creation. The crossguard consists of two wings that protudes from the hilt. In the centre where they meet, "
"a %^RESET%^%^RED%^ruby%^BOLD%^%^BLACK%^ is set. The world burns red when looked upon through the gemstone. Straps of darkened %^RESET%^%^ORANGE%^leather%^BOLD%^%^BLACK%^ "
"has been carefully wound around the hilt, ensuring the wielder a comfortable and durable grip even in the heat of the fiercest battles. The pommel itself resembles the "
"foot of a bird of prey. A single %^RESET%^%^GREEN%^emerald%^BOLD%^%^BLACK%^ is held in place by the gripping %^RESET%^talons%^BOLD%^%^BLACK%^.");
	set_weight(20);
      set_value(0);
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
      set_item_bonus("attack bonus",4);
      set_item_bonus("damage bonus",4);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
	set_overallStatus(220);
    set_property("no disenchant",1);
}

int wield_func(){
	tell_room(environment(ETO),"As "+ETO->query_cap_name()+" grabs the hilt of the "+query_short()+" the pommel jewel flashes pale green for just a second.",ETO);
	tell_object(ETO,"As you grab the hilt of the "+query_short()+" the pommel jewel flashes pale green for just a second.");
	return 1;
}

int unwield_func(){
	tell_room(environment(ETO),"As "+ETO->query_cap_name()+" unwields the "+query_short()+" the pommel jewel flashes green for an instant and then fades.",ETO);
	tell_object(ETO,"The pommel jewel flashes green for an instant and then fades.");
	return 1;
}

int hit_func(object targ){
	if(random(1000) < 400){
	tell_room(environment(query_wielded()),"The %^RESET%^%^RED%^ruby%^RESET%^ on "+ETO->query_cap_name()+"'s sword flashes once and the blade seems to glow %^RED%^red%^RESET%^ for a short while.",({ETO,targ}));
	tell_object(ETO,"The %^RESET%^%^RED%^ruby%^RESET%^ flashes once and the blade seems to glow %^RED%^red%^RESET%^ for a short while.");
	tell_object(targ,"The blade of "+ETO->query_cap_name()+"'s sword glows red for a short while as it slips past your defences.");
		return roll_dice(3,6)+0;	}
}