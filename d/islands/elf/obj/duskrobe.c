#include <std.h>
inherit "/d/common/obj/clothing/magerobe.c";

void create() {
   ::create();
   set_name("dusk robes");
   set_id(({"robe","robes","dusk robes","dusk robe","tattered robe"}));
   set_obvious_short("%^RESET%^%^MAGENTA%^A tattered %^CYAN%^ornate%^MAGENTA%^ robe%^RESET%^");
   set_short("%^RESET%^%^MAGENTA%^D%^CYAN%^u%^MAGENTA%^sk R%^CYAN%^o%^MAGENTA%^bes%^RESET%^");
  set_long("%^BOLD%^%^BLACK%^This robe seems to have served "+
  "its purpose in %^RESET%^%^CYAN%^times %^BOLD%^%^BLACK%^past."+
  " What once could easily have been a %^RESET%^%^MAGENTA%^formal"+
  " %^WHITE%^garment %^BOLD%^%^BLACK%^for a %^MAGENTA%^young "+
  "%^RESET%^%^MAGENTA%^lady %^BOLD%^%^BLACK%^has lost most of "+
  "its %^WHITE%^splendor%^BLACK%^. F%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^ayed "+
  "and %^RESET%^%^RED%^torn %^BOLD%^%^BLACK%^the black "+
  "v%^RESET%^%^MAGENTA%^e%^BOLD%^%^BLACK%^lvet of the "+
  "robe is cut to flow over a %^RESET%^%^MAGENTA%^young "+
  "woman's %^BOLD%^%^BLACK%^figure, purposefully hourglassed"+
  " to preserve modesty and functionality while still"+
  " %^RESET%^%^MAGENTA%^feminine%^BOLD%^%^BLACK%^. A wide "+
  "neckline supports a hood that can just as easily be "+
  "worn down on the shoulders and back as shading the wearer's"+
  " head. Long sleeves end in narrow cuffs. The robe ends "+
  "in %^RESET%^%^RED%^tatters %^BOLD%^%^BLACK%^just above "+
  "the feet, loose strips of fabric dragging into the ground"+
  " or torn away from years of neglect. Even after years of "+
  "fading the delicate fabric retains much of its"+
  " %^WHITE%^luster%^BLACK%^, shifting from pitch "+
  "black to alluring shades of %^RESET%^%^MAGENTA%^purple"+
  " %^BOLD%^%^BLACK%^with the %^WHITE%^light%^BLACK%^.%^RESET%^"
    );
set_lore("Cerilana was one of two half-elven children "+
"that were born from an elven princess and a human noble"+
" in an attempt to stop the conflict between the humans"+
" and the elves.  Both of their parents were killed by "+
"assassins and the older brother raised the younger "+
"sister.  He also tried to stop the slaughter.  When "+
"left all alone the woman who had no place in either "+
"world was consumed with despair.  She was said to have"+
" wandered off into the wilds to search for her brother"+
" years into his absence  but was never seen again. ");
set_property("lore difficulty",25);
   set_weight(5);
   set_value(3300);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_max_internal_encumbrance(30);
   set_property("enchantment",3+random(2));
   set_wear((:TO,"wear":));
   set_remove((:TO,"unwear":));
   set_item_bonus("bonus_spell_slots_3",1);
   set_item_bonus("negative energy resistance",5);
}

int wear(){
   if((int)ETO->query_level() < 20) {
     tell_object(ETO,"The robe doesn't seem to fit you.");
     return 0;
   }
   return 1;
}

int unwear(){
   if(!objectp(ETO)) return 0;
   tell_object(ETO,"%^MAGENTA%^You disrobe.");
   return 1;
}
