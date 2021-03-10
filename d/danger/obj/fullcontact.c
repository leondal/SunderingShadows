#include <std.h>
inherit "/d/common/obj/armour/fullplate.c";

void create() {
   ::create();
   set_id(({"armor","full plate armor","plate","full contact"}));
   set_obvious_short("%^BOLD%^%^BLACK%^B%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d %^BOLD%^%^BLACK%^P%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^e %^BOLD%^%^BLACK%^A%^RESET%^ORANGE%^r%^BOLD%^%^BLACK%^m%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^r%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^F%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^l %^BOLD%^%^BLACK%^C%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^t %^RESET%^%^ORANGE%^P%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^e%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^At first glance this armor"+
" appears like an ordinary suit of fullplate. There are only"+
" two exceptions and the first is very obvious. The suit has"+
" obviously seen numerous battles and bears many %^BOLD%^%^BLACK%^dents%^RESET%^%^ORANGE%^, %^BOLD%^%^BLACK%^scratches%^RESET%^%^ORANGE%^, and even %^BOLD%^%^BLACK%^burn marks%^RESET%^%^ORANGE%^. The second exception is an emblem that falls"+
" below the %^BOLD%^%^WHITE%^solid metal%^RESET%^%^ORANGE%^ of the chest plate. The emblem is made of pure %^BOLD%^%^YELLOW%^gold %^RESET%^%^ORANGE%^and bears the image of a fist."+
" It is held in place by two %^BOLD%^%^BLACK%^iron%^RESET%^%^ORANGE%^ chains attatched to the chest plates. It between the plate are various weavings of sturdy"+
" fabric with the intent of giving maximum mobility while still offering protection.");
   set_lore("%^RESET%^%^ORANGE%^This armor was forged and named by Eziekiel Burns. During his time he was a famous smith and only made armor for those he deemed worthy. He would never accept money for his work. This particular piece was fashioned for a firbolg warrior named Gered that helped to fend off a drow attack on a small town. Soon after the attack word of Gered's heroics reached Eziekiel and the armor was made. Gered then traveled to the continent known commonly as Danger and was never heard from again.");
   set_property("lore difficulty",30);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
   while((int)TO->query_property("enchantment") != 5){
      TO->remove_property("enchantment");
      TO->set_property("enchantment",5);
   }
}

int wearme() {
   if((int)ETO->query_level() < 35) {
      tell_object(ETO,"You need practice before you can wear this effectively.");
      return 0;
   }
   if((ETO->is_class("fighter")) || (ETO->is_class("cavalier")) || (ETO->is_class("paladin"))) {
      tell_room(environment(ETO),"%^RESET%^%^ORANGE%^The gold emblem %^BOLD%^%^ORANGE%^flashes brightly%^RESET%^%^ORANGE%^ for a moment as "+ETOQCN+" dons the armor.",ETO);
      tell_object(ETO,"%^RESET%^%^ORANGE%^The gold emblem %^BOLD%^%^ORANGE%^flashes brightly%^RESET%^%^ORANGE%^ for a moment as you don the armor.");
      ETO->add_attack_bonus(4);
      ETO->add_damage_bonus(4);
      return 1;
   }else{
      return 1;
   }
}
int removeme() {
   if((ETO->is_class("fighter")) || (ETO->is_class("cavalier")) || (ETO->is_class("paladin"))) {
        tell_room(environment(ETO),"%^RESET%^%^ORANGE%^ "+ETOQCN+" removes the battered armor.",ETO); 
        tell_object(ETO,"%^RESET%^%^ORANGE%^You remove the battered suit of armor and you feel as if you are missing something.");
        ETO->add_attack_bonus(-4);
        ETO->add_damage_bonus(-4);
        return 1;
   }else{
      return 1;
   }
}

int query_size(){ 
    if(living(ETO)) return ETO->query_size();
    else return 1;
}