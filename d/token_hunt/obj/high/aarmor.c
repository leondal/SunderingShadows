#include <std.h>
inherit "/d/common/obj/armour/studded.c";

void create(){
   ::create();
   set_name("body armor");
   set_id(({ "body armor", "armor", "leather", "mesh" }));
   set_short("%^BOLD%^%^BLACK%^Armor of the assassin%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^A suit of dark armor%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This dark armor is extremely light but well constructed.  The leather has been expertly"
" crafted into one of the finest pieces you have ever seen.  The material is completely black except for the image"
" of two crossed %^RESET%^s%^BOLD%^%^WHITE%^i%^RESET%^l%^BOLD%^%^WHITE%^v%^RESET%^er da%^BOLD%^%^WHITE%^gg%^RESET%^ers"
" %^BOLD%^%^BLACK%^upon its breast.  The %^RESET%^daggers %^BOLD%^%^WHITE%^gleam %^BLACK%^against the dark image"
" of a %^RESET%^%^RED%^b%^BOLD%^%^RED%^ur%^RESET%^%^RED%^n%^BOLD%^%^RED%^i%^RESET%^%^RED%^ng"
" %^RED%^m%^RESET%^oo%^RED%^n %^BOLD%^%^BLACK%^symbolizing the craft in which the owner was gifted.  The armor"
" itself is light enough that it makes hardly a sound when moved, showing the true dedication the craftsman put"
" into the armor and clearly marking it as something nothing less than a true professional would be proud to wear.%^RESET%^\n");
   set_value(0);
   set_lore("%^BOLD%^%^BLACK%^This armor has been rumored to have been around for quite some time.  Once belonging"
" to the assassin Levalith, it is rumored that it was he that was sent after the ranger of Mielikki, Rangath, to"
" squish his hopes of saving the jungles of Attaya from Intruders rising armies.  It is not know if he was"
" successsful or not, all that is known is that both assassin and ranger disappeared without a trace.%^RESET%^");
   set_size(-1);
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_item_bonus("dexterity",2);
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
   set_overallStatus(220);
}

int wear_func(){
   tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The armor seems to take on an eerie presence as "+ETO->query_cap_name()+" wears it.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^A strange yet oddly familiar feeling overcomes you as you slip on the armor.%^RESET%^");
   return 1;
}

int remove_func(){
   tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" seems more placid as "+ETO->query_subjective()+" takes the armor off.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^Taking off the armor leaves you feeling vulnerable and open.%^RESET%^");
   return 1;
}