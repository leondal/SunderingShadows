#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("headband of sight");
   set_id(({"headband","Headband","headband of sight"}));
   set_short("%^RESET%^hea%^CYAN%^d%^RESET%^band of s%^CYAN%^i%^RESET%^ght");
   set_obvious_short("%^RESET%^headband with a %^MAGENTA%^painted%^RESET%^ eye");
   set_lore("This headband is created by the "+
   "master fey'ri weavers.  They have perfected "+
   "upon the elven art.  The weave not only "+
   "protect from attacks but also improved the sight of the wearer.");
   set_property("lore difficulty",30);
   set_long("This is a st%^CYAN%^r%^RESET%^angely "+
   "woven headband.  It looks like there is "+
   "some st%^CYAN%^ra%^RESET%^nge %^BLUE%^rune-like%^RESET%^ "+
   "pa%^CYAN%^tte%^RESET%^rn in the weaving.  Likely a "+
   "master weaver created it.  On the front of the headband is"+
   " a %^MAGENTA%^painted eye%^RESET%^.  It seems to "+
   "gl%^CYAN%^ist%^RESET%^en in the l%^CYAN%^i%^RESET%^ght."+
   "  One can't help but think the eye is looking back at them.");
   set_limbs(({"head"}));
   set_type("clothing");
   set_size(-1);
   set_weight(5); 
   set_value(5000);
   set_wear((:TO,"wear_me":));
   set_property("enchantment",4);
   set_item_bonus("perception",1);
}

int wear_me(){ 
  tell_object(ETO,"You see things more clearly.  The world comes into
%^CYAN%^focus.");
  return 1;
}
