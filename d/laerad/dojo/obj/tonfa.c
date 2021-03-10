#include <std.h>
#include <magic.h>
#include "../dojo.h"
inherit "/d/common/obj/weapon/shortsword";

void create() {
    ::create();
    set_name("bladed tonfa");
    set_id(({"tonfa","bladed tonfa","ivory tonfa","steel tonfa","bladed tonfa of ivory and steel","amihan bantay","Amihan Bantay"}));
    set_short("%^BOLD%^%^BLACK%^A%^RESET%^m%^BOLD%^%^BLACK%^ih%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^n B%^RESET%^%^ORANGE%^an%^BOLD%^%^BLACK%^t%^RESET%^a%^BOLD%^%^BLACK%^y%^RESET%^");
    set_obvious_short("%^RESET%^%^ORANGE%^bladed tonfa of %^RESET%^i%^BOLD%^%^WHITE%^vo%^RESET%^ry %^ORANGE%^and %^BOLD%^%^BLACK%^ste%^RESET%^e%^BOLD%^%^BLACK%^l%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^The main grip of this weapon is a handle of polished %^RESET%^ivory%^BOLD%^%^WHITE%^, "
"darkened to a dull %^RESET%^%^ORANGE%^br%^RESET%^ow%^ORANGE%^n %^BOLD%^%^WHITE%^with age, and set with a raised ridge "
"at both top and base to serve for a better grip.  The curved handle itself is polished %^RESET%^%^MAGENTA%^s%^BOLD%^m"
"%^RESET%^%^MAGENTA%^o%^RED%^ot%^MAGENTA%^h%^BOLD%^%^WHITE%^, allowing it to be spun in a circular motion with ease.  "
"Attached to this is the main body of the weapon, a single-edged blade of %^BOLD%^%^BLACK%^st%^WHITE%^e%^YELLOW%^e%^BLACK%^l "
"%^WHITE%^that bears a slightly raised notch before dipping back to a straight line.  Pale %^RESET%^i%^BOLD%^%^WHITE%^v"
"%^RESET%^ory %^BOLD%^%^WHITE%^runs the length of the opposite side of the blade down to the blunted counterweight knob, "
"patterned with %^RESET%^%^ORANGE%^da%^RED%^r%^ORANGE%^ken%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d %^BOLD%^%^WHITE%^scrollwork "
"in an elaborate series of whorls and etchings.  A secondary blade rises directly perpendicular to the primary edge, curved "
"%^YELLOW%^sh%^WHITE%^a%^YELLOW%^r%^BLACK%^p%^RESET%^l%^YELLOW%^y %^BOLD%^%^WHITE%^around upon itself and gleaming with a "
"razor-sharp edge.  The tonfa, while of particularly unusual appearance, bears a %^RESET%^%^CYAN%^f%^BOLD%^%^CYAN%^l%^RESET%^"
"%^CYAN%^awl%^GREEN%^es%^CYAN%^s%^BOLD%^%^WHITE%^ balance only found in masterworked weaponry.\n%^RESET%^");
   set_lore("%^WHITE%^%^BOLD%^The tonfa is commonly used as a defensive weapon, and whether made of wood or metal, it "
"generally consists of only a blunt rod with a curved handle to allow for striking blows.  This particular piece, however, is "
"more distinctive for its bladed edge, which is only mentioned in the pages of the Shouryin Kai.  This tome details the "
"histories of those rare Senzokuan clans who prized the martial arts above the arcane more commonly embraced by their people.  "
"Many such unusual yet lethal weapons were devised by these clans, of such difficulty to handle that it would take a lifetime "
"to perfect their use.  These bladed tonfa were used in pairs in an elaborate dervish-like style of combat, and were known as "
"'Amihan Bantay', wind guards.%^RESET%^\n");
   set("no curse",1);
   set_property("lore difficulty",27);
   set_property("enchantment",4);
   set_item_bonus("reflex",2);
   set_value(9250);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
   set_weapon_prof("exotic");
}

int wield_fun(){
    int toenchant;
    if(userp(ETO) && member_array("%^RESET%^%^MAGENTA%^%^Defeated the masters of the Vasati Aadhyaatmika.%^RESET%^",ETO->query_mini_quests())== -1) {
      tell_object(ETO,"%^BOLD%^You have not earned the right to make use of this item.%^RESET%^");
      return 0;
    }
    if(userp(ETO) && (int)ETO->query_level() < 25) {
      tell_object(ETO,"%^BOLD%^You must train further before you can attempt to use a weapon of this calibre.%^RESET%^");
      return 0;
    }
    tell_room(EETO,"%^RESET%^%^ORANGE%^You close your fingers around the tonfa's grip, as comfortably as if it were made just for you.%^RESET%^");
    return 1;
}

int unwield_fun() {
   tell_object(ETO,"%^ORANGE%^You loose your hold on the smooth ivory handle, careful not to harm yourself on the curved blade.%^RESET%^");
   tell_room(EETO,"%^CYAN%^"+ETOQCN+" looses "+ETO->QP+" hold on the smooth ivory handle of the tonfa.%^RESET%^",ETO);
   return 1;
}

int hit_fun(object targ) {
   object dustobj;
   targ = ETO->query_current_attacker();
   if(random(2500)<500){
     switch(random(400)){
       case 0..199:
       tell_object(ETO,"%^ORANGE%^You duck under a wild blow from "+targ->QCN+", rising to strike at "+targ->QP+" unprotected side!%^RESET%^");
       tell_object(targ,"%^ORANGE%^"+ETOQCN+" ducks beneath your wild swing, rising to strike at your unprotected side!%^RESET%^");
       tell_room(EETO,"%^ORANGE%^"+ETOQCN+" ducks under a wild blow from "+targ->QCN+", rising to strike at "+targ->QP+" unprotected "
"side!%^RESET%^",({ETO,targ}));
       return 10;
       break;

       case 200..299:
       ETO->execute_attack();
       tell_object(ETO,"%^RED%^The tonfa connects solidly with "+targ->QCN+" and you follow through on the momentum of "
"the blow, letting the handle spin in your grip to land a second strike!%^RESET%^");
       tell_object(targ,"%^RED%^"+ETOQCN+"'s tonfa impacts you solidly, and "+ETO->QS+" follows through with the momentum "
"to spin the weapon and land a second strike!%^RESET%^");
       tell_room(EETO,"%^RED%^"+ETOQCN+"'s tonfa connects solidly with "+targ->QCN+", and "+ETO->QS+" follows through "
"with the momentum to spin the weapon and land a second strike!%^RESET%^",({ETO,targ}));
       return 1;
       break;

       case 300..399:
       tell_object(ETO,"%^WHITE%^%^BOLD%^A sudden twist of your wrist changes the angle of your strike, catching "+targ->QCN+
" with a %^BOLD%^%^GREEN%^glanc%^YELLOW%^i%^BOLD%^%^GREEN%^ng %^BOLD%^%^WHITE%^blow that leaves "+targ->QO+" looking dazed!%^RESET%^");
       tell_object(targ,"%^WHITE%^%^BOLD%^A sudden twist of "+ETOQCN+"'s wrist changes the angle of "+ETO->QP+" strike, catching "
+targ->QCN+" with a %^BOLD%^%^GREEN%^glanc%^YELLOW%^i%^BOLD%^%^GREEN%^ng %^BOLD%^%^WHITE%^blow that leaves "+targ->QO+" looking dazed!%^RESET%^");
       tell_room(EETO,"%^WHITE%^%^BOLD%^A sudden twist of "+ETOQCN+"'s wrist changes the angle of "+ETO->QP+" strike, catching "+targ->QCN+
" with a %^BOLD%^%^GREEN%^glanc%^YELLOW%^i%^BOLD%^%^GREEN%^ng %^BOLD%^%^WHITE%^blow that leaves "+targ->QO+" looking dazed!%^RESET%^",({ETO,targ}));
       if(dustobj = present("silence-dust-obj",targ)) dustobj->remove();
       new(OBJ"silenceobj")->move(targ);
       break;
     }
   }
   return 1;
}