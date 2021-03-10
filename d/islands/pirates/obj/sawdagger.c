#include <std.h>
inherit "/d/common/obj/weapon/dagger";

int mytype;

void create(){
   ::create();
   set_name("dagger");
   switch(random(9)){
     case 0..2:
     set_id(({"sawtoothed","sawtooth","sawtoothed dagger","dagger"}));
     set_short("%^RESET%^%^BLUE%^sawtoothed dagger%^RESET%^");
     set_long("%^BLUE%^This is a short, lightweight dagger of %^BLACK%^%^BOLD%^steel%^RESET%^%^BLUE%^.  "
"The blade itself is rather unique compared to a normal dagger, with a thicker ridge in the centre, thining "
"on either side to finally cut sharply into a row of %^RED%^wicked teeth%^BLUE%^.  This sawtoothed edge of "
"the blade would open pretty nasty slashes in combat.  Only a small crosspiece of the same metal separates "
"the blade and hilt, which is bound with strips of %^ORANGE%^leather%^BLUE%^, giving it a comfortable grip "
"in the hand.%^RESET%^");
     set_value(500);
     mytype = 1;
     break;

     case 3..5:
     set_id(({"sawtoothed","sawtooth","sawtoothed dagger","dagger","rusted dagger","rusted sawtoothed dagger"}));
     set_short("%^RESET%^%^ORANGE%^rusted sawtoothed dagger%^RESET%^");
     set_long("%^BLUE%^This short dagger must once have been quite an impressive weapon, though the %^BLACK%^"
"%^BOLD%^steel%^RESET%^%^BLUE%^ of the blade is now covered in several places by small patches of %^ORANGE%^"
"rust%^BLUE%^.  Despite this, it still has a particularly unique appearance, and would probably leave a "
"nasty wound in combat, due to the row of %^RED%^wicked teeth%^BLUE%^ that cut sharply down each side of the "
"blade.  Only a small crosspiece of the same metal separates the blade and hilt, which is bound loosely with "
"strips of old, ragged %^ORANGE%^leather%^BLUE%^.%^RESET%^");
     set_value(100);
     mytype = 2;
     break;

     case 6..8:
     set_id(({"longdagger","dagger","long dagger","steel longdagger","steel long dagger"}));
     set_short("%^BOLD%^%^BLACK%^steel longdagger%^RESET%^");
     set_long("%^BLUE%^This smooth dagger of %^BLACK%^%^BOLD%^steel%^RESET%^%^BLUE%^ gleams in the "
"light.  It is quite lightweight, with somewhat of a longer blade than most standard daggers, giving it a "
"more effective range against an attacker.  The blade is thicker in the centre, thinning on each side to a "
"%^WHITE%^sharpened point%^BLUE%^.  It meets the hilt at a slender crosspiece, and continues further to a "
"shaped grip also of the same metal, that would fit smoothly into the hand.%^RESET%^");
     set_value(300);
     mytype = 3;
     break;
   }
   set_wc(1,6);
   set_large_wc(1,4);
   set_weight(3);
   set_wield((:TO,"wield_fun":));
   set_hit((:TO,"extra_hit":));
   set_property("enchantment",random(2)+1);
}

int wield_fun(string str){
    switch(mytype){
      case 1:
      tell_object(TP,"%^RED%^You grip the dagger and admire its wicked blade!%^RESET%^");
      tell_room(ETP,"%^RED%^"+TPQCN+"'s eyes light up as they focus upon the wickedly-sharp dagger."
"%^RESET%^",TP);
      break;

      case 2:
      tell_object(TP,"%^ORANGE%^You grip the dagger and admire its wicked blade!%^RESET%^");
      tell_room(ETP,"%^ORANGE%^"+TPQCN+"'s eyes light up as they focus upon the wickedly-sharp "
"dagger.%^RESET%^",TP);
      break;

      case 3:
      tell_object(TP,"%^BLACK%^%^BOLD%^You grip the dagger and admire its wicked blade!%^RESET%^");
      tell_room(ETP,"%^BLACK%^%^BOLD%^"+TPQCN+"'s eyes light up as they focus upon the wickedly-"
"sharp dagger.%^RESET%^",TP);
      break;
    }
    return 1;
}

int extra_hit(object targ){
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(random(20)<2){
     switch(mytype){
       case 1:
       tell_object(ETO,"%^RED%^The sawtoothed edge of your dagger tears into "+targ->QCN+"'s flesh!"
"%^RESET%^");
       tell_object(targ,"%^RED%^The sawtoothed edge of "+ETOQCN+"'s dagger tears into your flesh!%^RESET%^");
       tell_room(EETO,"%^RED%^The sawtoothed edge of "+ETOQCN+"'s dagger rips into "+targ->QCN+"'s flesh!"
"%^RESET%^",({ETO,targ}));
       break;

       case 2:
       tell_object(ETO,"%^ORANGE%^You tear into "+targ->QCN+"'s flesh with the rusted dagger!"
"%^RESET%^");
       tell_object(targ,"%^ORANGE%^"+ETOQCN+" tears your flesh open with the rusted dagger and "
"leaves a fiercely burning slash!%^RESET%^");
       tell_room(EETO,"%^ORANGE%^"+ETOQCN+" rips into "+targ->QCN+"'s flesh with "+ETO->QP+
" rusted dagger!%^RESET%^",({ETO,targ}));
       break;

       case 3:
       tell_object(ETO,"%^BLACK%^%^BOLD%^You quickly slash at "+targ->QCN+" with your longdagger!"
"%^RESET%^");
       tell_object(targ,"%^BLACK%^%^BOLD%^"+ETOQCN+" slashes quickly at you with the longdagger!"
"%^RESET%^");
       tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" slashes at "+targ->QCN+" with "+ETO->QP+
" longdagger!%^RESET%^",({ETO,targ}));
       break;
     }
     targ->do_damage(targ->return_target_limb(),random(5)+3);
     return 0;
   }
   return 0;
}
