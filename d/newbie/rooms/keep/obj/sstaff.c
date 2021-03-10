#include <std.h>
inherit "/d/common/obj/weapon/sstaff.c";

void create() {
   ::create();
   set_short("%^BOLD%^%^WHITE%^Shaman's Bludgeon%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^a bone staff%^RESET%^");
   set_id(({"staff","small staff","bone staff"}));
   set_long("%^CYAN%^This small staff has been made from the %^WHITE%^polished leg bone %^CYAN%^of some "
"incredibly large monster. The tip of the staff is sharply pointed, while the top has been rounded, probably "
"to better bash opponents. Partway down the shaft, a %^ORANGE%^ratty leather strap %^CYAN%^has been tied and "
"fixed with clattering trinkets; %^YELLOW%^fangs %^RESET%^%^CYAN%^and %^WHITE%^rat skulls %^CYAN%^and other "
"nasty items.\n%^RESET%^");
   set_lore("This staff was crafted by a xvart, the small, blue creatures that overran Keep Kilgore northeast "
"of Offestry.  From all you have been able to learn, a strange sickness affected the Kilgore family in the "
"year 596 SG.  The keep lay abandoned for many decades before the xvarts moved into the already-decaying "
"stone structure.  This staff is often wielded by a xvart shaman, the highest ranked among them.");
   set_property("lore difficulty",3);
   set_value(5);
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"removeme":));
   set_hit((:TO,"hitme":));
}

int wieldme() {
   if(ALIGN->is_good(ETO)) {
      tell_object(ETO,"%^BLUE%^You feel a sense of wrongness as you wield the staff.%^RESET%^");
      return 1;
   }
   tell_object(ETO,"%^BLUE%^A wicked feeling fills you as you take up the staff.%^RESET%^");
   return 1;
}

int removeme() {
   if(ALIGN->is_good(ETO)) {
      tell_object(ETO,"%^BLUE%^You feel better as you release the staff.%^RESET%^");
      return 1;
   }
   tell_object(ETO,"%^BLUE%^You set aside the ghastly staff.%^RESET%^");
   return 1;
}

int hitme(object targ){
   int dam;
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!random(6)) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You smack "+targ->QCN+" sharply with the staff!%^RESET%^");
     tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->QCN+" smacks you sharply with the staff!%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETO->QCN+" smacks "+targ->QCN+" sharply with the "
"staff!%^RESET%^",({ETO,targ}));
     return 1;
   }
}
