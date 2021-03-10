#include <std.h>
inherit "/d/common/obj/weapon/claw.c";

void create(){
	::create();
	set_name("shadow glove");
	set_id(({ "glove","fist","stealthwhisper" }));
	set_short("%^BOLD%^%^BLACK%^Stealthwhisper%^RESET%^");
	set_obvious_short("A black, weighted glove");
	set_long("%^RESET%^This is a %^BOLD%^%^BLACK%^dark leather%^RESET%^, heavily weighted glove."+
    " Completely black, the weapon shows almost no distinctive features."+
    " The only distinguishable feature is a %^BOLD%^%^CYAN%^quartz"+
    " %^RESET%^rested int he palm of the glove. Within the quartz, a %^BOLD%^%^WHITE%^smoky"+
    " %^RESET%^substance whisps around.");
	set_weight(2);
	set_value(1000);
	set_lore("Rumored to be a special gift to Maskarrans who have completed a special mission for their deity.");
	set_type("piercing");
	set_prof_type("stealthwhisper");
	set_size(1);
	set_wc(1,4);
	set_large_wc(1,4);
	set_property("enchantment",2);
      set_item_bonus("dexterity",1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" wears the glove and a dark shadow bursts forth from the dagger crawling up their arm. "+ETO->query_cap_name()+"'s eyes %^BOLD%^%^CYAN%^glow %^BOLD%^%^BLACK%^for a moment before returning to normal.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^Shadows burst forth from the glove and crawl up your arms. A strange feeling passes through your body.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^The sensation leaves you.");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 75){
	tell_object(ETO,"%^BOLD%^%^BLACK%^You see tentacles burst from your fist, enveloping your target!");
	tell_object(targ,"%^BOLD%^%^BLACK%^Long tentacles of shadows burst forth from the glove, enveloping you!");
		targ->set_paralyzed(roll_dice(1,4)+0);
return 0;	}
}
