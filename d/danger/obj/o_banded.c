#include <std.h>
inherit "/d/common/obj/armour/banded.c";

void create() {
   ::create();
   set_id(({"armor","banded armor","banded","orcish banded"}));
   set_obvious_short("%^RESET%^%^GREEN%^hi%^BOLD%^%^BLACK%^gh%^RESET%^%^GREEN%^ly %^RESET%^%^ORANGE%^d%^RESET%^e%^RESET%^%^ORANGE%^c%^RESET%^o%^RESET%^%^ORANGE%^r%^RESET%^a%^RESET%^%^ORANGE%^t%^RESET%^e%^RESET%^%^ORANGE%^d %^RESET%^%^GREEN%^ba%^BOLD%^%^BLACK%^nd%^RESET%^%^GREEN%^ed ar%^BOLD%^%^BLACK%^m%^RESET%^%^GREEN%^or%^RESET%^");
   set_short("%^RESET%^%^GREEN%^O%^BOLD%^%^BLACK%^r%^RESET%^%^GREEN%^c%^BOLD%^%^BLACK%^i%^RESET%^%^GREEN%^s%^BOLD%^%^BLACK%^h %^RESET%^%^GREEN%^B%^BOLD%^%^BLACK%^a%^RESET%^%^GREEN%^n%^BOLD%^%^BLACK%^d%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^d%^RESET%^");
   set_long("%^RESET%^%^GREEN%^This is a set of well crafted banded armor. Overlapping strips of %^BOLD%^%^BLACK%^dark metal%^RESET%^%^GREEN%^ are sewn to a backing of %^RESET%^%^ORANGE%^supple leather %^RESET%^%^GREEN%^and %^BOLD%^%^WHITE%^steel chainmail%^RESET%^%^GREEN%^. The strips cover only"+
" the vulnerable areas, while the chain and leather protect the joints, allowing for maximum protection"+
" and maneuverability. The system of %^RESET%^%^ORANGE%^straps%^RESET%^%^GREEN%^ and %^RESET%^%^ORANGE%^buckles%^RESET%^%^GREEN%^ balances the weight perfectly. A strap runs over the right shoulder, across the chest, and down to the waist, where"+
" it wraps around the hip of the wearer. The %^BOLD%^%^GREEN%^strap%^RESET%^%^GREEN%^ is completely covered in tiny %^RESET%^skulls%^RESET%^%^GREEN%^. Most of them appear to"+
" be replicas of animals, but some appear %^RESET%^%^RED%^humanoid%^RESET%^%^GREEN%^. The details of the skulls is remarkable.");
   set_lore("%^RESET%^%^GREEN%^Smithed by orcs for orcs, it is sturdy in every possible way. The Halani hunters are a specific group of orcs that worship Malar and revel in the hunt. As a hunter makes a signifigant kill, their armor is ritually decorated and magically enhanced. Often times, the skulls of various kills are shrunk so that they may be attatched to the armor. This armor must have belonged to one of their greatest hunters.");
   set_property("lore difficulty",10);
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
      tell_room(environment(ETO),"%^RESET%^%^GREEN%^The %^RESET%^tiny skulls %^RESET%^%^GREEN%^on the armor rattle as "+ETOQCN+" wears the banded.",ETO);
      tell_object(ETO,"%^RESET%^%^GREEN%^The %^RESET%^tiny skulls %^RESET%^%^GREEN%^on the armor rattle as you wear the banded.");
   if((string)ETO->query_race() == "orc") {
        ETO->add_attack_bonus(4);
        ETO->add_damage_bonus(4);
        return 1;
   }
   if((string)ETO->query_race() == "half-orc") {
        ETO->add_attack_bonus(3);
        ETO->add_damage_bonus(3);
        return 1;
   }
        ETO->add_attack_bonus(2);
        ETO->add_damage_bonus(2);
        return 1;
}

int removeme() {
        tell_room(environment(ETO),"%^RESET%^%^GREEN%^The %^RESET%^tiny skulls %^RESET%^%^GREEN%^on the armor rattle as "+ETOQCN+" removes the banded.",ETO); 
        tell_object(ETO,"%^RESET%^%^GREEN%^The %^RESET%^tiny skulls %^RESET%^%^GREEN%^on the armor rattled as you remove the banded.");
   if((string)ETO->query_race() == "orc") {
        ETO->add_attack_bonus(-4);
        ETO->add_damage_bonus(-4);
        return 1;
   }
   if((string)ETO->query_race() == "half-orc") {
        ETO->add_attack_bonus(-3);
        ETO->add_damage_bonus(-3);
        return 1;
   }
        ETO->add_attack_bonus(-2);
        ETO->add_damage_bonus(-2);
        return 1;
}

int query_size(){ 
    if(living(ETO)) return ETO->query_size();
    else return 1;
}

