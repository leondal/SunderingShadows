//updated by Circe 1/1/05 with new lore, etc.
#include <std.h>
inherit LRWEAPON;

void create() {
    ::create();
    set_name("composite bow");
    set_id(({"composite bow","bow"}));
    set_obvious_short("%^BOLD%^%^WHITE%^Bone fused bow%^RESET%^");
    set_short("%^ORANGE%^tabaxi %^BOLD%^%^WHITE%^bone bow%^RESET%^");
    set_long("%^ORANGE%^A relatively short, single curved bow, made with wood %^BOLD%^%^WHITE%^composited%^RESET%^%^ORANGE%^ with %^BOLD%^%^WHITE%^bone%^RESET%^%^ORANGE%^. Its string is made from twined black %^BOLD%^%^BLACK%^animal hair%^RESET%^");
    set_lore("The Tabaxi bone bow is somewhat poorly named, for in fact its construction is a mixture of wood and bone, set in layers as with any composite bow. The construction places stretching pressure on the wood and compression on the bone when the bow is drawn. However, while the basic construction is not unusual, the tabaxi are skilled bowmen and their bows well crafted");
    set_property("lore difficulty",25);
    set_weight(10);
    set_size(2);
    set_value(1200);
    set_wc(1,4);
    set_large_wc(1,4);
    set_two_handed();
    set_lr_prof_type("short bow");
    set_prof_type("club");
    set_type("bludgeoning");
    set_decay_rate(150);
    set_rate_of_fire(3);
    set_range(5,10,15);
    set_ammo("arrows");
    set_property("enchantment",2);
    set_wield((:TO,"wieldme":));
    set_hit("%^BOLD%^%^MAGENTA%^You shoot a glowing arrow of light into your target.");
}

int wieldme(){
   if((int)ETO->query_level() < 25){
      tell_object(ETO, "This is more weapon than you can handle yet."
                      +" Sorry.");
      return 0;
   }
   tell_object(ETO,"The bow feels comfortable and balanced in your hand as"
                  +" you wield it.");
   tell_room(EETO,ETOQCN + "%^ORANGE%^smiles grimly as "+ETO->QS+" "
                         + "wields " + ETO->QP +" composite short bow."
                         ,ETO);
   return 1;
}
