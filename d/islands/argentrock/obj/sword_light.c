//removed references to old gods ~Circe~ 7/30/19
#include <std.h>
inherit "/d/common/obj/weapon/longsword.c";

string owner;
int COUNT,FLAG;

void create(){
   ::create();
   set_name("magnificent longsword");
   set_id(({"sword","great sword","long sword","longsword","great sword of light","magnificent sword","magnificent longsword","sword of light"}));
   set_obvious_short("%^BOLD%^%^WHITE%^a %^YELLOW%^mag%^CYAN%^n%^YELLOW%^ifi%^CYAN%^c%^YELLOW%^ent %^WHITE%^longsword%^RESET%^");
   set_short("%^BOLD%^%^WHITE%^Great Sword of %^YELLOW%^Lig%^CYAN%^h%^YELLOW%^t%^RESET%^");
   set_long("This sword is nothing short of %^CYAN%^breathtaking %^RESET%^in appearance, with a brilliant %^BOLD%^%^WHITE%^si%^RESET%^l%^BOLD%^%^WHITE%^ve%^RESET%^r%^BOLD%^%^WHITE%^y-wh%^RESET%^i%^BOLD%^%^WHITE%^te %^RESET%^blade honed to a %^BOLD%^%^CYAN%^razor-sharp %^RESET%^edge. It seems designed to be a little broader across the blade than a normal longsword, and indeed seems somewhat %^RED%^he%^MAGENTA%^avi%^RED%^er %^RESET%^because of this. An eyecatching symbol of the %^YELLOW%^s%^RESET%^%^ORANGE%^u%^YELLOW%^n %^RESET%^is carved in the blade itself, just where it meets the hilt, with a brilliant-cut %^RED%^r%^BOLD%^u%^RESET%^%^RED%^b%^BOLD%^y %^RESET%^forming the heart of the sun itself. The%^BOLD%^%^WHITE%^ sp%^YELLOW%^a%^WHITE%^rkl%^CYAN%^i%^WHITE%^ng %^RESET%^gemstone refracts light in all directions, across the etched %^YELLOW%^golden rays %^RESET%^that form the hilt of the weapon itself.  The entire weapon seems to be immersed in a radiance all of its own, and a %^ORANGE%^w%^RED%^a%^ORANGE%^rm %^RESET%^feeling engulfs you just from being near it.");
   set_lore("This blade was once a well-known holy relic of the faith of Jarmila. It was carried by a paladin of the Golden Guard, Aurin the Lightbringer, who was greatly reputed for his good deeds and his valiant efforts against the forces of evil. For many years he carried out his crusade in the name of the light, until one such journey led him to the island of Argentrock. He never returned from the island, and eventually both his memory, and that of his holy weapon, fell into the realms of myth and legend.");
   set_property("lore difficulty",36);
   set_property("enchantment",5);
   while((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_item_bonus("attack bonus",4);
   set_item_bonus("damage bonus",3);
   set_weight(10);
   set_value(5800);
   FLAG = 0;
   set_wield((:TO,"more_wield":));
   set_unwield((:TO,"more_unwield":));
   set_hit((:TO,"more_hit":));
   //set_weapon_prof("exotic"); //removed exotic weapon proficiency requirement as per the Grand Weapon Update/Standardization of 2019 ~Odin
}

void init() {
   ::init();
   if(interactive(TP) && TP == environment(TO) && !owner) {
      owner = TPQN;
      return;
   }
   set_heart_beat(1);
}

int more_wield() {
   int myalign;
   if(!interactive(ETO) || avatarp(ETO) )
      return 1;
   if((int)ETO->query_level() < 30 ) {
      tell_object(ETO,"You don't have the power to lift this magnificent sword!");
      return 0;
   }
   if((string)ETOQN != owner) {
      tell_object(ETO,"The magnificent blade fails to bond with you and vanishes.");
      TO->remove();
      return 0;
   }
   myalign = (int)ETO->query_alignment();
   if((myalign % 3) == 1) {
      tell_room(EETO,"%^CYAN%^The gemstone inset on the hilt of the "
"magnificent blade shines %^BOLD%^%^WHITE%^br%^YELLOW%^i%^WHITE%^gh"
"%^YELLOW%^t%^WHITE%^ly %^RESET%^%^CYAN%^as "+ETOQCN+" wields it.",ETO);
      tell_object(ETO,"%^CYAN%^The gemstone inset on the hilt of the "
"magnificent blade shines %^BOLD%^%^WHITE%^br%^YELLOW%^i%^WHITE%^gh"
"%^YELLOW%^t%^WHITE%^ly %^RESET%^%^CYAN%^as you wield it.%^RESET%^");
   ETO->set_property("good item",1);
      return 1;
   }
   tell_object(ETO,"%^BLUE%^The gemstone inset on the hilt of the magnificent "
"blade suddenly pulses with a %^BOLD%^%^WHITE%^br%^YELLOW%^i%^WHITE%^ght "
"%^RESET%^%^BLUE%^light and shocks you!%^RESET%^");
   tell_room(EETO,"%^BLUE%^The gemstone inset on the hilt of the magnificent "
"blade suddenly pulses with a %^BOLD%^%^WHITE%^br%^YELLOW%^i%^WHITE%^ght "
"%^RESET%^%^BLUE%^light and shocks "+ETOQCN+"!%^RESET%^",ETO);
   ETO->do_damage("left hand",40 + random(20));
   ETO->add_attacker(TO);
   ETO->continue_attack();
   ETO->remove_attacker(TO);
   return 0;
}

int more_unwield() {
   tell_room(EETO,"%^CYAN%^The gemstone inset on the hilt of the "
"magnificent blade stops %^BOLD%^%^WHITE%^sh%^YELLOW%^i%^WHITE%^ning "
"%^RESET%^%^CYAN%^as "+ETOQCN+" unwields it.%^RESET%^", ETO);
   tell_object(ETO,"%^CYAN%^The gemstone inset on the hilt of the "
"magnificent blade stops %^BOLD%^%^WHITE%^sh%^YELLOW%^i%^WHITE%^ning "
"%^RESET%^%^CYAN%^as you unwield it.%^RESET%^");
   ETO->set_property("good item",-1);
   return 1;
}

int more_hit(object targ) {
   object *weapons,*armours;
   int myenchant,myenchant2,choose,pick,diff,old_ac,new_ac,targalign;
   string weapon_name,armour_name;
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   targalign = targ->query_alignment();

   if(userp(targ) && (targalign % 3) == 1) {
     if(!TO->query_property("enchantment")) return 0;
     if(COUNT == 1) return 0;
     tell_room(EETO,"%^CYAN%^The gemstone inset on the hilt of the "
"magnificent blade seems to %^BOLD%^%^BLACK%^d%^RESET%^u%^BOLD%^%^BLACK%^ll "
"%^CYAN%^as it hits "+targ->QCN+".%^RESET%^");
     tell_object(ETO,"%^CYAN%^You can almost feel the blade's despair as it "
"harms another of the %^WHITE%^light%^CYAN%^.%^RESET%^");
     tell_object(targ,"%^CYAN%^The gemstone inset on the hilt of the "
"magnificent blade seems to %^BOLD%^%^BLACK%^d%^RESET%^u%^BOLD%^%^BLACK%^ll "
"%^CYAN%^as it hits you.%^RESET%^");
     myenchant = (int)TO->query_property("enchantment");
     myenchant--;
     while((int)TO->query_property("enchantment") != myenchant) {
       TO->remove_property("enchantment");
       TO->set_property("enchantment",myenchant);
     }
     COUNT = 1;
     call_out("reset_count",20);
     return 1;
   }

   if(!((int)targ->query_alignment() % 3)) {
     if(random(100) == 13) {
       if(FLAG != 0) return 0;
       weapons = (object *)targ->query_wielded();
       weapons = distinct_array(weapons);
       if(sizeof(weapons) == 0) return 0;
       choose = random(sizeof(weapons));
       weapon_name = weapons[choose]->query_name();
       if((int)weapons[choose]->query_property("enchantment") <= 0) return 0;
       tell_object(ETO,"%^CYAN%^The gemstone inset on the hilt of your "
"magnificent blade flares with %^YELLOW%^light %^RESET%^%^CYAN%^as you "
"strike at "+targ->QCN+".\nAs the light vanishes, the "+weapon_name+
" wielded by "+targ->QO+" ceases giving out a magical %^MAGENTA%^au%^BLUE%^"
"r%^MAGENTA%^a %^CYAN%^and looks perfectly normal!%^RESET%^");
       tell_room(EETO,"%^CYAN%^The gemstone inset on the hilt of "+ETO->QCN+
"'s magnificent blade flares with %^YELLOW%^light %^RESET%^%^CYAN%^as "
+ETO->QS+" strikes at "+targ->QCN+".\nAs the light vanishes, the "+weapon_name+
" wielded by "+targ->QO+" ceases giving out a magical %^MAGENTA%^au%^BLUE%^"
"r%^MAGENTA%^a %^CYAN%^and looks perfectly normal!%^RESET%^",({targ,ETO}));
       tell_object(targ,"%^CYAN%^The gemstone inset on the hilt of "+ETO->QCN+
"'s magnificent blade flares with %^YELLOW%^light %^RESET%^%^CYAN%^as "
+ETO->QS+" strikes at you.\nAs the light vanishes, your "+weapon_name+
" ceases giving out a magical %^MAGENTA%^au%^BLUE%^r%^MAGENTA%^a "
"%^CYAN%^and looks perfectly normal!%^RESET%^");
       weapons[choose]->remove_property("enchantment");
       FLAG = 600;
       set_heart_beat(1);
       return 1;
     }

     if(random(50) > 39) {
       tell_object(ETO,"%^CYAN%^The magnificent sword %^RED%^b%^ORANGE%^l"
"%^YELLOW%^a%^WHITE%^z%^RED%^e%^RESET%^%^RED%^s %^CYAN%^brilliantly as it "
"sears "+targ->QCN+"'s evil flesh!%^RESET%^");
       tell_room(EETO,"%^CYAN%^"+ETO->QCN+"'s magnificent sword %^RED%^b"
"%^ORANGE%^l%^YELLOW%^a%^WHITE%^z%^RED%^e%^RESET%^%^RED%^s %^CYAN%^brilliantly "
"as it sears "+targ->QCN+"'s evil flesh!%^RESET%^",({targ,ETO}));
       tell_object(targ,"%^CYAN%^"+ETO->QCN+"'s magnificent sword %^RED%^b"
"%^ORANGE%^l%^YELLOW%^a%^WHITE%^z%^RED%^e%^RESET%^%^RED%^s %^CYAN%^brilliantly "
"as it sears your flesh!%^RESET%^");
      return roll_dice(2,8)+4;
   }

   if(random(150) == 7) {
     if(FLAG) return 0;
     armours = (object *)targ->all_armour();
     if(sizeof(armours) == 0) return 0;
     pick = random(sizeof(armours));
     if((int)armours[pick]->query_property("enchantment") <= 1) return 0;
     armour_name = armours[pick]->query_name();
     diff = (int)armours[pick]->query_property("enchantment") - 1;
     while((int)armours[pick]->query_property("enchantment") != diff) {
       armours[pick]->remove_property("enchantment");
       armours[pick]->set_property("enchantment",diff);
     }
     tell_object(ETO,"%^CYAN%^The gemstone inset on the hilt of your "
"'s magnificent blade flares with %^YELLOW%^light %^RESET%^%^CYAN%^as "
"you strike at "+targ->QCN+".\nAs the light vanishes, the magical "
"%^MAGENTA%^au%^BLUE%^r%^MAGENTA%^a %^CYAN%^surrounding "+targ->QP+" "
+armour_name+" seems to fade slightly!%^RESET%^");
     tell_room(EETO,"%^CYAN%^The gemstone inset on the hilt of "+ETO->QCN+
"'s magnificent blade flares with %^YELLOW%^light %^RESET%^%^CYAN%^as "
+ETO->QS+" strikes at "+targ->QCN+".\nAs the light vanishes, the magical "
"%^MAGENTA%^au%^BLUE%^r%^MAGENTA%^a %^CYAN%^surrounding "+targ->QP+" "
+armour_name+" seems to fade slightly!%^RESET%^",({targ,ETO}));
     tell_object(targ,"%^CYAN%^The gemstone inset on the hilt of "+ETO->QCN+
"'s magnificent blade flares with %^YELLOW%^light %^RESET%^%^CYAN%^as "
+ETO->QS+" strikes at you.\nAs the light vanishes, the magical %^MAGENTA%^au"
"%^BLUE%^r%^MAGENTA%^a %^CYAN%^surrounding your "+armour_name+" seems to "
"fade slightly!%^RESET%^");
     FLAG = 750;
     set_heart_beat(1);
     return 1;
   }
     if(random(50)>40){
     tell_object(ETO,"%^CYAN%^You land a %^GREEN%^heavy blow %^CYAN%^on "
+targ->QCN+" with the sharpened edge of your magnificent sword!%^RESET%^");
     tell_room(EETO,"%^CYAN%^"+ETO->QCN+" lands a %^GREEN%^heavy blow %^CYAN%^"
"on "+targ->QCN+" with the sharpened edge of "+ETO->QP+" magnificent "
"sword!%^RESET%^",({targ,ETO}));
     tell_object(targ,"%^CYAN%^"+ETO->QCN+" lands a %^GREEN%^heavy blow %^CYAN%^"
"on you with the sharpened edge of "+ETO->QP+" magnificent sword!%^RESET%^");
     return random((int)ETO->query_level()/3 + 5);
   }

   if(random(100)>90){
      tell_room(EETO,"%^RESET%^%^CYAN%^The blade of "+ETO->QCN+"'s sword takes on a %^BOLD%^startling glow %^RESET%^%^CYAN%^as it sweeps through the %^BOLD%^%^WHITE%^air %^RESET%^%^CYAN%^towards "+targ->QCN+", the %^BOLD%^%^WHITE%^light blinding %^RESET%^%^CYAN%^as it crashes into "+targ->QO+"!%^RESET%^ ",({targ,ETO}));
      tell_object(targ,"%^RESET%^%^CYAN%^The blade of "+ETO->QCN+"'s sword takes on a %^BOLD%^startling glow %^RESET%^%^CYAN%^as it sweeps through the air toward you, the %^BOLD%^%^WHITE%^light blinding %^RESET%^%^CYAN%^as the blade crashes into you.%^RESET%^!");
      tell_object(ETO," %^RESET%^%^CYAN%^The blade of your sword takes on a %^BOLD%^startling glow %^RESET%^%^CYAN%^as it sweeps through the %^RESET%^air %^CYAN%^towards "+targ->QCN+", the %^BOLD%^%^WHITE%^light blinding %^RESET%^%^CYAN%^as it crashes into "+targ->QO+"!%^RESET%^");
      targ->set_paralyzed(roll_dice(2,6)," %^YELLOW%^The blinding light overwhelms you!%^RESET%^");
      if(!random(3)) targ->set_blind(1);
      return roll_dice(2,6);
      }
   }
   return random((int)ETO->query_level()/10 + 5);
}

void reset_count() {
   if(!objectp(TO)) return;
   COUNT = 0;
   return;
}

void heart_beat() {
   if(FLAG > 0) {
     FLAG--;
     return;
   }
   if(FLAG <= 0) FLAG = 0;
   set_heart_beat(0);
}
