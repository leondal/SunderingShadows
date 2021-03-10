#include <std.h>
inherit "/d/common/obj/armour/pawguards";

void create() {
   ::create();
   set_name("%^ORANGE%^gn%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^llh%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^d%^BOLD%^%^BLACK%^e %^RESET%^%^ORANGE%^p%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^wg%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^ar%^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^s%^RESET%^");
   set_id(({"pawguards","leather pawguards","pawguard"}));
   set_short("%^ORANGE%^gn%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^llh%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^d%^BOLD%^%^BLACK%^e %^RESET%^%^ORANGE%^p%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^wg%^BOLD%^%^BLACK%^u%^RESET%^%^ORANGE%^ar%^BOLD%^%^BLACK%^d%^RESET%^%^ORANGE%^s%^RESET%^");
   set_obvious_short("%^ORANGE%^Rough leather pawguards%^RESET%^");
   set_long("%^ORANGE%^These p%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^wg%^BOLD%^%^BLACK%^ua%^RESET%^%^ORANGE%^rds "+
   "are made from raw g%^RED%^n%^ORANGE%^ollh%^RED%^i%^ORANGE%^d%^RED%^e%^ORANGE%^. Even though they are not "+
   "h%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^rd-b%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^il%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d, the "+
   "thick h%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^de will provide plenty of %^BOLD%^%^BLACK%^protection%^RESET%^%^ORANGE%^. "+
   "They lace up on the back of the foreleg ankles with thick leather straps and have %^BOLD%^%^BLACK%^reinforced padding "+
   "%^RESET%^%^ORANGE%^on the s%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^les. The front of the p%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^wg%^BOLD%^%^BLACK%^ua%^RESET%^%^ORANGE%^rds "+
   "are entirely open to allow %^RED%^cl%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^ws %^ORANGE%^to come out without damaging "+
   "the p%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^wg%^BOLD%^%^BLACK%^ua%^RESET%^%^ORANGE%^rds.");
   set_value(100);
	set_property("enchantment",3);
	set_item_bonus("armor bonus",1);
	set_wear((:TO,"wear_it":));
    set_remove((:TO,"remove_it":));
	set_size(3);
   
   }

   int wear_it(){
	if(ETO->query_level() < 15){
		tell_object(ETO,"%^GREEN%^These pawguards are too advanced for you!");
		tell_room(EETO,"%^GREEN%^"+ETO->QCN+"%^RESET%^%^GREEN%^ doesn't seem to be able to wear the pawguards.",ETO);
	return 0;}
	if((string)ETO->query_race() != "wemic"){
		tell_object(ETO,"These are called 'Paw'guards for a reason!");
		tell_room(EETO,""+ETP->QCN+" seem to realize that pawguards go on actual paws.",ETO);
	return 0;}
	tell_object(ETO,"%^RESET%^%^GREEN%^You lace the pawguards onto your front paws one at the time.");
	tell_room(EETO,"%^RESET%^%^GREEN%^"+ETO->QCN+"%^RESET%^%^GREEN%^ wears the pawsguards one at the time.",ETO);
return 1;}

int remove_it(){
	tell_object(ETO,"You unlace the pawguards.");
	tell_room(EETO,""+ETO->QCN+" unlaces and removes the pawguards.",ETO);
return 1;}