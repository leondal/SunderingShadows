#include <std.h>
inherit ARMOUR;
void is_straight_cleric(object ob);

void create(){
	::create();
	set_name("cassock of deepening darkness");
	set_id(({ "coat","coat of deepening darkness","dark coat","cassock","cassock coat"}));
	set_short("%^BOLD%^%^BLACK%^Cassock of %^RESET%^%^BLUE%^"+
		"D%^BOLD%^ee%^BLACK%^p%^RESET%^%^BLUE%^en%^BOLD%^i"+
		"%^RESET%^%^BLUE%^ng %^BOLD%^%^BLACK%^Da%^BLUE%^"+
		"rk%^BLACK%^ness%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A dark cassock coat%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This coat is crafted out of an etheral "+
		"substance that soaks up the surrounding light.  The coat"+
		" is cut to fit close to the body.  With long tailored "+
		"sleeves, the coat offers a versatility in wear.  The "+
		"tab collar of the coat curves around the wearer's neck."+
		"  An inverted pleat on the back of the coat allows for "+
		"ease in movement.  %^RESET%^%^BLUE%^Dark blue%^BOLD%^%^BLACK%^"+
		" pipping trims the front of the coat, matching in color the"+
		" buttons that run from neck to hem.  Appliques of silk and"+
		" satin in %^BLUE%^b%^RESET%^%^BLUE%^l%^BOLD%^u%^RESET%^%^BLUE%^"+
		"e%^BOLD%^s%^BLACK%^, %^RESET%^grays%^BOLD%^%^BLACK%^, and blacks"+
		" create swirling tendrils across the shoulders and up the cuffs"+
		" of the sleeves.  The inside of the coat is lined with black "+
		"spidersilk, an expensive fabric prized for its durability and"+
		" lightweight nature.%^RESET%^\n");
	set_weight(4);
	set_value(1500);
	set_lore("The Cassock of Deepening Darkness was said to have been"+
		" crafted from shadows during the night of a lunar eclipse."+
		"  The fabric used to create the coat is said to be made from"+
		" the blood of a shadow dragon and requires seven shadows to "+
		"be used in the process.  The shadows are rumored to still "+
		"remain in their state of undeath within the fabric and only"+
		" those dark of heart will find the shadows waiting to aid them."+
		" - Rare Cloth and Clothing - Keisha Blackmace");
	set_property("lore difficulty",18);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
	set_property("enchantment",3);
	set_ac(0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}

int wear_func(){
	if(ALIGN->is_good(ETO)) {
      tell_object(ETO,"The cassock reject someone of your nature!");
      return 0;
   }
   if(ETO->query_lowest_level() < 20) {
      tell_object(ETO,"You are too inexperienced to wear such a fine coat.");
      return 0;
   }
   if(ETO->query_property("good item")) {
      tell_object(ETO,"The cassock refuse to be worn while you're using such"+
		" good items.");
      return 0;
   }
     if(member_array("%^BOLD%^%^CYAN%^Lucid Dreams%^RESET%^",ETO->query_mini_quests())== -1) {
      tell_object(ETO,"You have not earned the right to make use of this item.");
      return 0;
   }
	tell_room(environment(ETO),"%^BOLD%^%^%^BLACK%^"+ETOQCN+" 's coat almost"+
		" seems to soak in the surrounding light as "+ETO->QS+" buttons"+
		" is closed.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You slip into the coat and marvel at"+
		" how it seems to soak in the surrounding light.");
			ETO->set_property("evil item",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" slips out of"+
		" "+ETO->QP+" coat.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You unbutton the cassock and slip it off.");
			ETO->set_property("evil item",-1);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) > 25 && ETO->is_singleClass()){
	if(!"daemon/saving_d"->saving_throw(who,"spell",-6)) {
	tell_room(environment(query_worn()),"%^BOLD%^%^%^BLACK%^"+who->QCN+""+
		" howls in pain as dark claws emerge from  "+
		""+ETOQCN+"'s coat and tears into "+who->QS+".",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^%^BLACK%^A pair of dark claws emerge from"+
		" the fabric of your coat and slice into "+who->QCN+"");
	tell_object(who,"%^BOLD%^%^BLACK%^A pair of dark claws emerge from"+
		" the fabric of "+ETOQCN+"'s coat and tear into your flesh!");
			who->do_damage("torso",random(10)+3);
	}
	else{	
	tell_room(environment(query_worn()),"%^BOLD%^%^%^BLACK%^"+who->QCN+""+
		" looks suprised as claws emerge from "+
		""+ETOQCN+"'s coat and take a swipe at "+who->QS+".",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^%^BLACK%^A pair of dark claws emerge from"+
		" the fabric of your coat and tries to slice into "+who->QCN+"");
	tell_object(who,"%^BOLD%^%^BLACK%^A pair of dark claws emerge from"+
		" the fabric of "+ETOQCN+"'s coat and take a swipe at you!");
	return 1;
	}

}
}