#include <std.h>
inherit "/d/common/obj/lrweapon/longbow";

void create(){
   ::create();
   set_name("long bow");
   set_id(({"bow","long bow","elven long bow"}));
   set_obvious_short("A finely crafted long bow");
   set_short("%^RESET%^%^GREEN%^Elven%^RESET%^ long bow");
   set_long(
      "The craftsmenship of the longbow is exquisite,"+
      " revealing instantly its %^BOLD%^%^GREEN%^elven"+
      " %^RESET%^workings. The length of the longbow is"+
      " made out of a polished oak limb, magically paint"+
      "ed in a light %^GREEN%^jade %^RESET%^and covered in"+
      " elven %^BOLD%^%^YELLOW%^runes%^RESET%^. The bowstri"+
      "ng is made of a long strand of bark, twisted to perfe"+
      "ction by the finest of elven bowyers. The bowstring is"+
      " coated in a resin that allows for a powerful pull with"+
      " the greatest of ease on the user."
   );
   set_property("enchantment",1);
   set_value(900);
   set_wield((:TO,"wieldit":));
   set_unwield((:TO,"unwieldit":));
    set_lrhit((:TO,"lrhitit":));
}

int wieldit(){
   tell_object(ETO,"%^BOLD%^%^GREEN%^You grip the shaft of the bow and feel ready to fire.%^RESET%^");
   return 1;
}

int unwieldit(){
   tell_object(ETO,"%^BOLD%^%^GREEN%^You reluctantly release your grip on the bow.%^RESET%^");
   return 1;
}

int lrhitit(object targ) {
    targ = ETO->query_current_attacker();
    if(random(1000) < 200){
        if(!objectp(targ)) return roll_dice(1,6);

        tell_object(ETO,"%^BOLD%^%^GREEN%^You draw back the bowstring by your "
"cheek and fire a devastating shot at "+targ->QCN+"!%^RESET%^");
        tell_object(targ,"%^BOLD%^%^GREEN%^"+ETO->QCN+" fires a devastating "
"shot that plunges deep into your skin!%^RESET%^");
        tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETO->QCN+" fires a devastating "
"shot at "+targ->QCN+"!%^RESET%^",({ETO,targ}));
        return roll_dice(1,10)+2;
    }
}
