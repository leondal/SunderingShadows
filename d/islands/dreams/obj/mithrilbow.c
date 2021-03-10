//updated to current code and to remove references to old gods ~Circe~ 9/21/19

#include <std.h>
inherit "/d/common/obj/lrweapon/longbow.c";

void create(){
   ::create();
   set_name("mithril long bow");
   set_short("%^BOLD%^%^WHITE%^M%^CYAN%^i%^WHITE%^thr%^CYAN%^i%^WHITE%^l Long Bow%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^A mithril long bow%^RESET%^");
   set_id(({"long bow","bow","longbow","mithril bow","mithril long bow"}));
   set_long("%^BOLD%^This fine m%^CYAN%^i%^WHITE%^thr%^CYAN%^i%^WHITE%^l bow seems to be elven-made, with beautiful %^BLUE%^r%^GREEN%^u%^BLUE%^n%^GREEN%^e%^BLUE%^s%^WHITE%^ and %^RESET%^%^GREEN%^de%^CYAN%^c%^GREEN%^orati%^CYAN%^o%^GREEN%^ns%^BOLD%^%^WHITE%^ running along the length of the shaft. It has been strung with an incredibly thin material that almost looks like spider's silk, except that it is very strong.%^RESET%^");
   set_value(1000);
   set_property("enchantment",3);
   set_lore("These mithril bows pose a curious query to many.  Their design, construction, and shape lead many to belive them to be of elven make, but many elves point to some variations and differences in design and make from their legendary methods.  Some have pondered if they are of drow make then, but drow generally favor crossbows over the traditional bow, to further separate themselves from their surface cousins. - Piercing the Quiver: A History and Study of Bows - Yardan Greenwood");
   set_property("lore difficulty",10);
   set_lrhit((:TO,"extra_lrhit":));
   set_item_bonus("athletics",2);
}

int extra_lrhit(object targ){
int mylvl;
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!random(10)){
      tell_object(ETO,"%^BOLD%^%^WHITE%^The %^BLUE%^r%^GREEN%^u%^BLUE%^n%^GREEN%^e%^BLUE%^s%^WHITE%^ on the bow flare brightly as you fire at "+targ->QCN+"!%^RESET%^");
      tell_object(targ,"%^BOLD%^%^WHITE%^The %^BLUE%^r%^GREEN%^u%^BLUE%^n%^GREEN%^e%^BLUE%^s%^WHITE%^ on "+ETO->QCN+"'s bow flare brightly as "+ETO->QS+" fires at you!%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^WHITE%^The %^BLUE%^r%^GREEN%^u%^BLUE%^n%^GREEN%^e%^BLUE%^s%^WHITE%^ on "+ETO->QCN+"'s bow flare brightly as "+ETO->QS+" fires at "+targ->QCN+"!%^RESET%^",({ETO,targ}));
      set_property("magic",1);
      targ->do_damage("torso",random(4)+10);
      remove_property("magic");
      return roll_dice(2,4);
   }
   if(!random(18)){
      tell_object(ETO,"%^BOLD%^%^WHITE%^The %^BLUE%^r%^GREEN%^u%^BLUE%^n%^GREEN%^e%^BLUE%^s%^WHITE%^ on the bow take on a soft gleam, and you feel renewed.%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^WHITE%^The %^BLUE%^r%^GREEN%^u%^BLUE%^n%^GREEN%^e%^BLUE%^s%^WHITE%^ on "+ETO->QCN+"'s bow take on a soft gleam, and "+ETO->QS+" looks refreshed.%^RESET%^",ETO);
      set_property("magic",1);
      ETO->do_damage("torso",(-1)*(random(20)+10));
      remove_property("magic");
      return 1;
   }
   if(!random(8)){
      mylvl = ETO->query_level()/3;
      if(mylvl < 8) mylvl = 8;
      tell_object(ETO,"%^YELLOW%^The %^BLUE%^r%^GREEN%^u%^BLUE%^n%^GREEN%^e%^BLUE%^s%^YELLOW%^ on your bow flash like %^WHITE%^lig%^CYAN%^h%^WHITE%^tning %^YELLOW%^as you set your sights on "+targ->QCN+"!%^RESET%^");
      tell_object(targ,"%^YELLOW%^The %^BLUE%^r%^GREEN%^u%^BLUE%^n%^GREEN%^e%^BLUE%^s%^YELLOW%^ on "+ETOQCN+"'s bow flash like %^WHITE%^lig%^CYAN%^h%^WHITE%^tning %^YELLOW%^as "+ETO->QS+" sets "+ETO->QP+" sights on you!%^RESET%^");
      tell_room(EETO,"%^YELLOW%^The %^BLUE%^r%^GREEN%^u%^BLUE%^n%^GREEN%^e%^BLUE%^s%^YELLOW%^ on "+ETOQCN+"'s bow flash like %^WHITE%^lig%^CYAN%^h%^WHITE%^tning %^YELLOW%^as "+ETO->QS+" sets "+ETO->QP+" sights on "+targ->QCN+"!%^RESET%^");
      new("/cmds/spells/m/_moonbeam")->use_spell(ETO,targ,mylvl,100,"cleric");
      return;
   }
}
