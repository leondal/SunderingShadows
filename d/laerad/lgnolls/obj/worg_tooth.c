// Worg Tooth. -Essillys- Maj 2014
#include <std.h>
inherit "/d/common/obj/weapon/light_rapier.c";



void create(){
	::create();
set_id(({"knife","dagger","tooth","worg tooth"}));
  	set_name("Pristine worg tooth");
  	set_short("A pristine worgs tooth ");
	set_obvious_short("A long worgs canine");
  	set_long("This %^BOLD%^canine %^RESET%^is as long as a normal person's forearm. "+
	"The base of the %^BOLD%^t%^RESET%^oo%^BOLD%^th %^RESET%^has been wrapped with "+
	"%^ORANGE%^leather %^WHITE%^to form a %^ORANGE%^h%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^ndl%^BOLD%^%^BLACK%^e "+
	"%^RESET%^which oddly enough provides excellent grip on the %^BOLD%^t%^RESET%^oo%^BOLD%^th%^RESET%^. "+
	"The '%^BOLD%^%^BLACK%^b%^WHITE%^l%^BLACK%^a%^WHITE%^d%^BLACK%^e%^RESET%^' of the %^BOLD%^t%^RESET%^oo%^BOLD%^th "+
	"%^RESET%^is %^YELLOW%^pr%^WHITE%^i%^ORANGE%^st%^WHITE%^i%^ORANGE%^n%^WHITE%^e %^RESET%^and ends in a incredibly %^BOLD%^sharp point%^RESET%^.");
	set_lore("It has always been said that the canines of a worg den-mother are as strong as steel and just as sharp. This very tooth seem to prove that point. "+
	"They are mostly used by Gnolls who uses the worgs as slaves and mounts (and food). But lately many native tribes have been hunting den-mothers as a test of manhood. "+
	"In their eyes, owning a canine such as this is prof as being a mighty warrior and a great honor.");
	set_property("lore",15);
    	set_value(30);
    	set_property("enchantment",3);
	set_hit((:TO,"hit_func":));
     	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
}
int wield_func(string str) {
   if((int)ETO->query_lowest_level() < 16) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^The tooth slips out of your grasp.");
      tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" fumbles when"+
		" trying to wield the tooth and drops it.");
	return 0;
}
        tell_object(ETO,"%^BOLD%^%^BLACK%^You get a sense of power as you wield the tooth.");
   	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" looks at the %^RESET%^canine%^BOLD%^%^BLACK%^ with "+
	"a proud smile as "+ETO->QP+" wields it.",ETO);
			
     	return 1;
}
int unwield_func(string str) {
   	tell_object(ETO," You feel the power of the tooth leave as you unwield it.");
   	tell_room(environment(ETO),"%^CYAN%^"+ETO->QCN+" sighs slightly "+
		" as "+ETO->QS+" releases the tooth.",ETO);
   	
   	return 1;
}

int hit_func(object victim) {
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(victim)) return 1;
   	
	if(random(1000) < 225)
	{
	switch(random(20))
	{
	case 0..15:
	tell_object(ETO, "The %^BOLD%^t%^RESET%^oo%^BOLD%^th %^RESET%^pierces right through " +victim->QCN+ "'s "+
	"a%^BOLD%^%^BLACK%^rm%^RESET%^o%^BOLD%^%^BLACK%^r %^RESET%^and draws %^BOLD%^%^RED%^blood!");
	tell_object(victim, "%^RESET%^" +ETO->QCN+ "'s %^BOLD%^t%^RESET%^oo%^BOLD%^th %^RESET%^pierces right "+
	"through your a%^BOLD%^%^BLACK%^rm%^RESET%^o%^BOLD%^%^BLACK%^r %^RESET%^and you feel a %^RED%^sharp %^BOLD%^pain!");
	tell_room(environment(ETO), "%^RESET%^" +ETO->QCN+ "'s %^BOLD%^t%^RESET%^oo%^BOLD%^th %^RESET%^pierces through"+
	" " +victim->QCN+ "'s a%^BOLD%^%^BLACK%^rm%^RESET%^o%^BOLD%^%^BLACK%^r %^RESET%^with ease and comes "+
	"back out with a %^BOLD%^%^RED%^gush %^RESET%^of %^RED%^blood!",({ETO,victim}));
	victim->do_damage("torso",(4,4)+4);
	break;
	
	
	case 16..19:
	tell_object(ETO, "%^BOLD%^%^BLACK%^With a p%^WHITE%^o%^BLACK%^w%^WHITE%^e%^BLACK%^rf%^WHITE%^u%^BLACK%^l "+
	"thrust you piece the %^WHITE%^t%^RESET%^oo%^BOLD%^th %^BLACK%^in between "+victim->QCN+ "'s ribs, "+
	"%^RESET%^%^RED%^piecing the %^BOLD%^lung%^BLACK%^!%^RESET%^",victim);
	tell_object(victim, "%^BOLD%^%^BLACK%^" +ETO->QCN+ " %^BOLD%^%^BLACK%^forces the %^WHITE%^t%^RESET%^oo%^BOLD%^th %^BLACK%^through "+
	"your ribcage and %^RESET%^%^RED%^pierces your %^BOLD%^lung%^BLACK%^!%^RESET%^",ETO);
	tell_room(environment(ETO), " %^BOLD%^%^BLACK%^" +ETO->QCN+ " %^BOLD%^%^BLACK%^thrusts the %^WHITE%^t%^RESET%^oo%^BOLD%^th "+
	"%^BLACK%^through " +victim->QCN+ "'s ribcage making "+victim->QO+" cough up %^RED%^blood "+
	"%^RESET%^%^RED%^violently!%^RESET%^",({victim,ETO}));
	victim->do_damage("torso",(1,12)+5);
	victim->set_paralyzed(random(15),"%^BOLD%^%^BLACK%^You are too busy %^RESET%^%^RED%^coughing %^BOLD%^blood!%^RESET%^");
	break;
	
	}
	}
}
