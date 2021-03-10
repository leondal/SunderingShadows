//heavily updated mithril sword from torm -cythera
#include <std.h>
inherit "/d/common/obj/weapon/longsword.c";

void create() {
    ::create();
   set_id(({ "sword", "longsword", "long sword", "sword of dragon's majesty", "long","mithril sword","mithril longsword","mithril long sword","gilded longsword", }));
   set_name("gilded longsword");
   set_obvious_short("%^BOLD%^%^WHITE%^A%^YELLOW%^ gilded%^WHITE%^ mithril longsword%^RESET%^");
   set_short("%^BOLD%^%^CYAN%^Sword of %^YELLOW%^Dragon's %^WHITE%^Majesty%^RESET%^");
    set_long("%^BOLD%^%^CYAN%^Forged from %^WHITE%^mithril%^CYAN%^, the blade of "+
         "this sword is thicker than a typical long sword.  Both sides of the blade"+
         " have been sharpened, up to the kite shaped tip of the blade.  Etched into"+
         " the %^WHITE%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r%^BOLD%^y "+
         "mithril%^CYAN%^ are a series of proud and regal "+
         "patterns, each gilded with pure %^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^l"+
         "%^RESET%^%^ORANGE%^d%^BOLD%^%^CYAN%^.   The pattern seems to radiate "+
         "outwards from an %^MAGENTA%^i%^BLUE%^r%^GREEN%^i%^MAGENTA%^d%^BLUE%^e"+
         "%^GREEN%^s%^MAGENTA%^c%^BLUE%^e%^GREEN%^n%^MAGENTA%^t%^CYAN%^ %^WHITE%^silver"+
         " %^CYAN%^scale that has been fused with the %^WHITE%^mithril%^CYAN%^.  "+
         "The handhold of sword is sculpted from %^WHITE%^white palladium%^CYAN%^"+
         " into the image of a %^GREEN%^serpentine dragon%^CYAN%^ in flight.  The "+
         "wings of the dragon form a protective handguard for the wielder of this"+
         " fine blade.%^RESET%^"
      //"%^BOLD%^"
      //"  This is a bright silvery mithril longsword."
   //"  It was forged by the Dwarves of Mt. Sholkum in the Dagger Reaches."
     // "  Dwarven runes line the center of the blade and it glows with strength."
   //"  From the gold glittering on the hilt and the runes it's obviously the weapon of an officer."
     // "  On the hilt is the crest of the Army of the Dagger Reaches."
    );
    set_lore("Crafted for a long forgotten bloodline that once ruled Deku, these blades"+
         " were past onto the first born heirs of the family.  It has been speculated, by"+
         " deeper research that the firstborn children of the Jalimpar noble family were"+
         " the ones who use to wield such a blade.  The first born children from each "+
         "generation undertook oaths of chivalry and trained to become knights.  These"+
         " blades were said to have been a cherished gift for each child, as well as "+
         "claim to their noble herritage.  The Jalimpar crest was that of a mithril dragon"+
         " ringed by golden mist.");
    set_property("lore",13);
    //set_weight(7);
    //set_size(2);
    set_value(1500);
    //set_wc(1,8);
    //set_large_wc(1,12);
    //set_type("slashing");
    set_property("enchantment",3);
    set_item_bonus("armor bonus", 1);
    set_wield((:TO,"extra_wield":));
    set_hit((:TO,"extra_hit":));
    set_special_material_type("silver");
}
int extra_wield(){
    if(!ETO) return 0;
  if(!interactive(TP)) return 1;
    if((int)ETO->query_lowest_level()<15){
  write("You don't feel you've earned the right to this fine sword just yet.");
  tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETO->QCN+" sighs as "+ETO->QS+" looks at a "+
          "fine blade in "+ETO->QP+" hands.",ETO);
	return 0;
    }
    write("%^BOLD%^%^CYAN%^You admire the fine workmanship of this stunning blade as you wield it.");
  tell_room(EETO,ETO->QCN+" admires the fine workmanship of "+ETO->QP+" stunning sword.",ETO);
    return 1;
}
int extra_hit(object victim) {
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(victim)) return 1;

        if(!random(8)) {
                tell_object(ETO,"%^BOLD%^%^CYAN%^You follow through your slash, whipping the"+
                   " mithril blade back through "+victim->QCN+".");
        tell_object(victim,"%^BOLD%^%^CYAN%^"+ETO->QCN+" follows through "+
                   ""+ETO->QP+" attack, whipping the blade back through you.");
        tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETO->QCN+" follows "+
                   "through "+ETO->QP+" attack on "+victim->QCN+".",({ETO,victim}));
                        victim->do_damage("torso",random(4)+2);
                return 1;
        }
        if(!random(16)) {
        tell_object(ETO,"%^BOLD%^Your heart starts to race as the silvery scale"+
               " on the sword sheds a dim light.  You feel yourself quicken, "+
               "tearing into "+victim->QCN+" with a series of quick hits.");
        tell_object(victim,"%^BOLD%^"+ETO->QCN+" suddenly bursts into action, "+
               "slashing at you with a series of quick hits that you can't defend"+
               " youself from.");
        tell_room(EETO,""+ETO->QCN+" bursts into action, slashing at"+
                        " "+victim->QCN+" with a series of quick hits.",({ETO,victim}));
                                victim->do_damage("torso",random(6)+4);
        return 1;
        }
}
