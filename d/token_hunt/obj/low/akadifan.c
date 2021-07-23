#include <std.h>
inherit "/d/common/obj/weapon/fan.c";

void create(){
   ::create();
   set_name("silk fan");
   set_id(({"fan","silk fan","silken fan","silver fan","breath","breath of the zephyr","breath of zephyr","zephyr"}));
   set_short("%^RESET%^%^CYAN%^B%^BOLD%^re%^WHITE%^a%^RESET%^%^WHITE%^t%^CYAN%^h o%^BOLD%^%^BLUE%^f %^CYAN%^t%^RESET%^%^WHITE%^h%^BLUE%^e %^BOLD%^Z%^CYAN%^ep%^RESET%^%^CYAN%^h%^BOLD%^%^WHITE%^y%^CYAN%^r%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLUE%^A %^CYAN%^silk fan %^BLUE%^with a %^WHITE%^silver frame%^RESET%^");
   set_long("%^ORANGE%^This fan seems, at first glance, to be nothing more than a delicate accessory used by "
"so many women in hot weather.  A closer look though, reveals that it has been designed in just a way to "
"effectively support the many %^WHITE%^si%^BOLD%^lv%^RESET%^%^WHITE%^er%^BOLD%^y %^RESET%^%^ORANGE%^tines of "
"its frame, so as not to break easily under pressure.  Each tine narrows to a razor-sharp point, with a "
"surprisingly dangerous appearance for such an otherwise unassuming item.  The base is also crafted of "
"%^WHITE%^s%^BOLD%^il%^RESET%^%^WHITE%^ve%^BOLD%^r%^RESET%^%^ORANGE%^, etched with swirling patterns that you "
"can't truly discern any purpose for.  Covering the %^WHITE%^si%^BOLD%^lv%^RESET%^%^WHITE%^er%^BOLD%^y "
"%^RESET%^%^ORANGE%^ribs is a length of thin shimmering silk, although it is impossible to tell what color it "
"should originally be.  Patternings of %^BOLD%^%^CYAN%^azure%^RESET%^%^ORANGE%^, %^BOLD%^%^BLUE%^cobalt"
"%^RESET%^%^ORANGE%^, %^BLUE%^navy%^ORANGE%^, %^CYAN%^aquamarine%^ORANGE%^ and just about every other shade of "
"blue imaginable, whorl across the surface of the cloth in chaotic mottled patterns, that never seem the same "
"from one second to the next.  It is almost distracting just to watch it, though indeed it is a stunning piece "
"of crafting.\n%^RESET%^"); 
	set_lore("%^BOLD%^%^WHITE%^It was said that only two fans such as this were ever made, as mirror images "
"of each other that were perfectly balanced, to be used in harmonious synchrony.  They were designed and "
"crafted to the instructions of Xlarenna, a half-elven gypsy of renown in the realms to the west.  It is told "
"in lore that the Queen of the Winds was so pleased with the absolute freedom and unrestricted nature of "
"Xlarenna's life, that upon a whim She let Her blessings fall upon the identical fans.  Even as the gypsy "
"woman danced in the open air, did the breeze pick up and lift her with it.  When they set her down again a "
"moment later, the very essence and strength of the winds were still carried in the fans she held, evermore "
"blessed within them.");
   	set_property("lore difficulty",15);
	set_value(0);
   while ((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
      set_item_bonus("attack bonus",1);
   	set_wield((:TO,"wield_fun":));
	set_unwield((:TO,"unwield_fun":));
	set_hit((:TO,"hit_func":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wield_fun() {
   tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+" smoothly opens the fan with a flick of "+ETO->QP+" wrist.",ETO);
   tell_object(ETO,"%^BOLD%^%^CYAN%^You smoothly open the fan with a flick of your wrist.%^RESET%^");
   return 1;
}

int unwield_fun(){
   tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+" closes the fan in a single fluid motion.",ETO);
   tell_object(ETO,"%^BOLD%^%^CYAN%^You close the fan in a single fluid motion.%^RESET%^");
   return 1;
}

int hit_func(object targ){
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!random(12)) {
      tell_object(ETO,"%^BOLD%^%^CYAN%^A gentle breeze picks up around you, guiding your hands.%^RESET%^");
      tell_object(targ,"%^BOLD%^%^CYAN%^A gentle breeze picks up around "+ETO->QCN+" as "+ETO->QS+" slashes at "
"you.%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^BLUE%^ A gentle breeze picks up around "+ETO->QCN+" as "+ETO->QS+" slashes at "
+targ->QCN+".%^RESET%^",({ETO,targ}));
      return roll_dice(1,4)+4;
      return 1;
   }

   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^You move with fluid grace, slashing at "+targ->QCN+" with the razor-"
"sharp tips of the fan.%^RESET%^");
      tell_object(targ,"%^BOLD%^%^WHITE%^Moving with fluid grace, "+ETO->QCN+" slashes at you with the razor-"
"sharp tips of "+ETO->QP+" fan.%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^WHITE%^Moving with fluid grace, "+ETOQCN+" slashes at "+targ->QCN+" with the "
"razor-sharp tips of "+ETO->QP+" fan.",({ETO,targ}));
      targ->cause_typed_damage(targ, "torso", roll_dice(1, 4)+5, "slashing");
      return 1;
   }

   if(!random(10)) {
      tell_object(ETO,"%^BOLD%^%^BLUE%^As you whirl and spin, the chaotic patterning of your fan seems to "
"distract "+targ->QCN+" from "+targ->QP+" attack!%^RESET%^");
      tell_object(targ,"%^BOLD%^%^BLUE%^You find yourself distracted, almost hypnotised, by the chaotic "
"patterning of "+ETOQCN+"'s fan as "+ETO->QS+" spins it before you!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^BLUE%^"+targ->QCN+" seems to become distracted by the chaotic patterning of "
+ETOQCN+"'s fan as "+ETO->QS+" spins it before "+targ->QO+"!%^RESET%^",({ETO,targ}));
      targ->set_paralyzed(random(4)+3,"%^BOLD%^%^BLUE%^You are enthralled by the fan's stunning, chaotic "
"patterns!%^RESET%^");
      return 1;
   }
}