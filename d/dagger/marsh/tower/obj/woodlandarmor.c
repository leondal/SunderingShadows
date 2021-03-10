#include <std.h>
inherit "/d/common/obj/armour/studded";

void create(){
	::create();
	set_name("woodland armor");
	set_id(({ "armor", " woodland armor", "armor of the woodlands", "leather", "studded leather", "green studded leather" }));
	set_short("%^RESET%^%^GREEN%^A%^BOLD%^r%^RESET%^%^GREEN%^m%^BOLD%^o%^RESET%^%^GREEN%^r %^BOLD%^%^WHITE%^of"
" the %^RESET%^%^ORANGE%^W%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^l"
"%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^n%^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^s%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A deep %^RESET%^%^GREEN%^gr%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^en"
" %^BOLD%^%^BLACK%^studded leather%^RESET%^");
	set_long("%^RESET%^This armor is almost certainly made to blend in with the"
" %^BOLD%^%^GREEN%^f%^RESET%^%^ORANGE%^o%^BOLD%^%^GREEN%^r%^RESET%^%^ORANGE%^e%^BOLD%^%^GREEN%^s"
"%^RESET%^%^ORANGE%^t%^RESET%^.  The leather has been died a deep shade of %^RESET%^%^GREEN%^green"
" %^RESET%^with mixed splotches of %^RESET%^%^ORANGE%^browns"
"%^RESET%^, %^BOLD%^%^BLACK%^blacks%^RESET%^, and %^RESET%^%^CYAN%^grays%^RESET%^, making it effective woodland"
" camouflage as well as protection from blows.  The %^BOLD%^%^BLACK%^metal %^RESET%^rivets that stud it are all"
" colored to match the leather as well, leaving no outline that would give the wearer away.  Every bit of this"
" armor is made for functionality rather than extravagance and it looks like it would stand up to many years of"
" harsh treatment with barely a scratch.");
	set_weight(15);
	set_value(10000);
	set_lore("This leather armor was made by the grand armorsmith Ulrich von Osterland for the ranger"
" Pyotr Tsnenokof in the year 620 SG.  It was lost along with its wearer to some unknown menace in the"
" Northern Dagger Reaches some five years later.  This is supposedly Ulrich's masterwork piece of craftsmanship"
" and is quite a prize indeed.  It is said that when wearing this armor, a person can become at one with"
"nature and %^BOLD%^stalk %^RESET%^the wilds.");
	set_property("lore difficulty",15);
	set_size(2);
      set_property("enchantment",5);
      set_item_bonus("dexterity",4);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
    if((int)ETO->query_highest_level()<30){
       tell_object(ETO,"%^RESET%^%^ORANGE%^The armor refuses to be worn by you!");
        ETO->do_damage("torso",random(100)+20);
        ETO->add_attacker(TO);
        ETO->continue_attack();
        ETO->remove_attacker(TO);
        TO->remove();
      return 0;
    }
	tell_room(environment(ETO),""+ETOQCN+" wears a suit of green leather.",ETO);
	tell_object(ETO,"You slip on the suit of armor and feel more connected to the land.");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),""+ETOQCN+" removes a suit of green leather.",ETO);
	tell_object(ETO,"You feel your connection to the land lessen as you remove the armor.");
	return 1;
}
void init() {
    ::init();
    add_action("stalk","stalk");
}
void stalk(string str){
   if(!objectp(ETO)){
   return 1; 
   }
   if(!TO->query_worn()){ 
	tell_object(ETO,"%^RESET%^%^GREEN%^You must be wearing the armor!%^RESET%^");
   return 1; 
   }
   if (!ETO->is_class("ranger")) {
   tell_object(ETO,"Even this armor cannot help you, you do not know the ways of the wild.");
   return 0;
   }
   tell_object(ETO,"%^BOLD%^%^GREEN%^You allow yourself to succumb to the call of the wilds and disappear into the nature that surrounds you!%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" simply disappears into the surrounding wilderness!",ETO);
   new("/cmds/spells/m/_meld_into_nature.c")->use_spell(ETO,ETO->query_name(),20,100,"ranger");
   return 1;
}

