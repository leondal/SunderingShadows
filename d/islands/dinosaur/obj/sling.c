#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit "/d/common/obj/lrweapon/sling";

void create() {
    ::create();
    set_name("sling");
    set_id(({"woven sling","sling"}));
    set_short("%^RESET%^%^ORANGE%^roughly woven sling%^RESET%^");
    set_long("%^RESET%^This weapon is about as rudimentary as they come, short of bludgeoning "
"something with a fallen stick.  Several strands of some kind of %^GREEN%^sinewy plant fibre "
"%^RESET%^have been woven together to form a sturdy and non-elastic cord.  "
"Either end has been doubled back to make a %^BLUE%^loop %^RESET%^for fingers to hold, while a "
"small segment of %^ORANGE%^hide %^RESET%^is secured in the middle of the cord itself, as a "
"cradle to support %^BOLD%^%^BLACK%^stones %^RESET%^that could be thrown from the sling.  It "
"certainly doesn't make for a weapon that looks like much, but in the right hands it could "
"potentially be dangerous.%^RESET%^\n");
    set_lore("Such weapons, and the craft to make them, are traditionally held by tribes of "
"Tonaz'tlacar found across several eastern islands in the Saakrune sea.  While mainland children "
"and shepherds craft similarly styled weaponry from cloth and wool, the original islander "
"traditions draw on certain types of plants to create the woven cording, known as sennit.  Stones "
"are then specially selected, and sometimes carved with tribal emblems, before being used as a "
"weapon from afar.");
    set_value(700);
    set_property("enchantment",3);
    set_item_bonus("damage bonus",3);
    set_wield((: TO,"wieldme" :));
    set_lrhit((:TO,"extra_lrhit":));
}

int wieldme() {
    tell_object(ETO,"%^ORANGE%^You slip your fingers through the sennit loops and are ready to fight!");
    return 1;
}

int extra_lrhit(object targ){
   object *targweapon;
   int i;
   string *ids;
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!random(15)){
     tell_object(ETO,"%^YELLOW%^You spin the sling overhead and loose a glancing blow at "+targ->QCN+
"!%^RESET%^");
     tell_object(targ,"%^YELLOW%^"+ETOQCN+" spins "+ETO->QP+" sling overhead and looses a glancing blow "
"at you!%^RESET%^");
     tell_room(EETO,"%^YELLOW%^"+ETOQCN+" spins "+ETO->QP+" sling overhead and looses a glancing blow at "
+targ->QCN+"!%^RESET%^",({ETO,targ}));
     targ->do_damage(targ->return_target_limb(),random(6)+12);
     return 1;
   }
   if(!random(12)){
     tell_object(ETO,"%^ORANGE%^Your bullet flies true and hits "+targ->QCN+" in the eye!%^RESET%^");
     tell_object(targ,"%^ORANGE%^"+ETOQCN+"'s bullet flies true and hits you in the eye! Augh, that's "
"so painful!%^RESET%^");
     tell_room(EETO,"%^ORANGE%^"+ETOQCN+"'s bullet flies true and hits "+targ->QCN+" in the eye! That "
"looked painful!%^RESET%^",({ETO,targ}));
     targ->set_temporary_blinded(2);
     return 1;
   }
   if(!random(12)){
     targweapon = targ->query_wielded();
     if(sizeof(targweapon)) {
       tell_object(ETO,"%^RED%^You aim your shot with precision and it cracks across "+targ->QCN+"'s "
"knuckles, forcing "+targ->QO+" to drop "+targ->QP+" weapon!%^RESET%^");
       tell_object(targ,"%^RED%^"+ETOQCN+" takes precise aim and cracks a bullet across your knuckles! "
"You can't help but to drop your weapon!%^RESET%^");
       tell_room(EETO,"%^RED%^"+ETOQCN+" aims "+ETO->QP+" shot with precision and it cracks across "
+targ->QCN+"'s knuckles, forcing "+targ->QO+" to drop "+targ->QP+" weapon!%^RESET%^",({ETO,targ}));
       i = random(sizeof(targweapon));
       ids = targweapon[i]->query_id();
       targ->force_me("unwield "+ids[0]);
       targ->remove_property("disarm time");
       targ->set_property("disarm time",(time() + (ROUND_LENGTH * roll_dice(1,4))));
     }
     return 1;
   }
}