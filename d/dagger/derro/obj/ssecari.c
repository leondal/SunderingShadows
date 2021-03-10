//Updated dagger - Cythera 8/05
#include <std.h>
inherit "/d/dagger/derro/obj/secari.c";

void create(){
	::create();
        set_id(({"secari","ornate secari","dagger"}));
        set_name("ornate secari");
        set_short("%^BOLD%^%^BLACK%^Ornate S%^RED%^e%^BOLD%^"+
             "%^BLACK%^c%^RED%^a%^BOLD%^%^BLACK%^ri%^RESET%^");
  	set_hit((:TO,"hit_func":));
   	set_property("enchantment",3);
   	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}
int wield_func(string str) {
   if((int)ETO->query_lowest_level() < 16) {
      tell_object(ETO,"%^BOLD%^%^BLACK%^The dagger is to hot for you to wield.");
      tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" pulls "+ETO->QP+" "+
		"hand back from the dagger suddenly.");
	return 0;
}
   	tell_object(ETO,"%^RED%^The dagger feels warm in your hand.");
   	tell_room(environment(ETO),"%^RED%^"+ETOQCN+" curls "+ETO->QP+" fingers "+
		"around the grip of the dagger.",ETO);
			ETO->set_property("evil item",1);

     	return 1;
}
int unwield_func(string str) {
   	tell_object(ETO,"%^RED%^You release the dagger for now.");
   	tell_room(environment(ETO),"%^RED%^"+ETO->QCN+"'s "+
      	"fingers unwrap grip of the dagger.",ETO);
   			ETO->set_property("evil item",-1);
   	return 1;
}

int hit_func(object victim) {
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(victim)) return 1;
   	
	if(!random(8)) {
  		tell_object(ETO,"%^RED%^You plunge the dagger into "+victim->QCN+","+
			" letting it drink "+victim->QP+" blood.");
      	tell_object(victim,"%^RED%^"+ETO->QCN+" plunges "+ETO->QP+" into you.\n"+
			" You can feel the dagger drinking in your blood!");
      	tell_room(environment(ETO),"%^RED%^With a cold murderous look in "+
                        ""+ETO->QP+" eyes, "+ETO->QCN+" plunges "+ETO->QP+" dagger into "+
       		""+victim->QCN+".",({ETO,victim}));
       			victim->do_damage("torso",random(4)+2);
		return 1;	
	}
	if(!random(16)) {
      	tell_object(ETO,"%^BOLD%^%^BLACK%^Boiling hot %^RED%^blood"+
			"%^BOLD%^%^BLACK%^ is sprayed out of"+
			" the dagger and onto "+victim->QCN+".");
      	tell_object(victim,"%^BOLD%^%^BLACK%^A boiling hot sticky blood red "+
			"liquid is sprayed onto you from "+ETO->QCN+"'s dagger.",);
      	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^A hot sticky blood "+
			"red liquid is sprayed onto "+victim->QCN+" from "+ETO->QCN+"'s"+
			" dagger.",({ETO,victim}));
				victim->do_damage("torso",random(6)+4);
      	return 1;
	}
}
