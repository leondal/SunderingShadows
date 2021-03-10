//heavily modified robe of the bandits - is a little more decent now - Saide 12/31/03
#include <std.h>
inherit "/d/common/obj/armour/robe";

void create() {
    ::create();
   set_name("dark blue and yellow robe");
   
   set_id( ({"robe","blue robe","garment","frizzelfoot robe","yellow "+
   "robe","yellow garment","blue garment","frizzlefoot garment"}) );
   
   set_obvious_short("%^RESET%^%^BLUE%^A dark blue and %^YELLOW%^"+
   "yellow%^RESET%^%^BLUE%^ robe%^RESET%^");

   set_short("%^BLUE%^Fr%^YELLOW%^i%^RESET%^%^BLUE%^zzl%^YELLOW%^e"+
   "%^RESET%^%^BLUE%^foot's sh%^YELLOW%^ie%^RESET%^%^BLUE%^ld g"+
   "%^YELLOW%^a%^RESET%^%^BLUE%^rm%^YELLOW%^e%^RESET%^%^BLUE%^nt"+
   "%^RESET%^");

   set_long("%^BLUE%^This robe is made from a thick and dark blue "+
   "cloth that has several stripes of %^YELLOW%^yellow fabric%^RESET%^"+
   "%^BLUE%^ sewn seamlessly into it.  The %^YELLOW%^stripes%^RESET%^"+
   "%^BLUE%^ serve to reflect a boldness that lingers on the border "+
   "of arrogance.  Despite its absurd coloration and seamless form "+
   "it appears quite simple.  It has been kept in remarkably good "+
   "and clean condition which effectively masks its age.%^RESET%^");
   
    set_lore("%^BOLD%^%^BLUE%^The bandit king had these robes crafted "+
    "by a mercenary magi to ensure that he would be able to withstand  "+
    "the onslaught from %^BOLD%^%^BLACK%^Lord Blacktongues%^BOLD%^%^BLUE%^ " +
    "werewolves and the growing number of adventurers who travel to Deku "+
    "attempting to stem the darkness or increase their own power.%^RESET%^");

   set_size(1);
   set_weight(7);
   set_value(200);
   set_property("enchantment",3);
   set_item_bonus("slashing resistance",1);
   set_wear((:TO,"wearme":));
   set_remove("%^YELLOW%^You feel the energy of the garment recede "+
   "and find yourself vunerable once more!%^RESET%^");
   set_struck((:TO,"strike_me":));
}

int wearme() {
  if(ETO->query_highest_level() < 20) {
    tell_object(ETO,"%^RED%^The magic of the garment is beyond your "+
    "understanding!%^RESET%^");
    return 0;
  }
  tell_object(ETO,"%^YELLOW%^As you don the garment you feel an "+
  "invisible energy seep out from it and encompass you!%^RESET%^");
  return 1;
}

int strike_me(int damage, object what, object who){
 if(random(1000) > 750  && (int)TO->query_property("enchantment") >= 1) {
  tell_room(EETO,who->QCN+"%^BLUE%^'s blow appears weakened as "+
  who->QS+"%^BLUE%^ strikes the robe worn by "+ETO->QCN+
  "%^BLUE%^!%^RESET%^",({ETO,who}));
  tell_object(ETO,who->QCN+"%^BLUE%^'s blow is weakened as "+
  who->QS+"%^BLUE%^ strikes your robe!%^RESET%^");
  tell_object(who,"%^BLUE%^Your blow is weakened as you strike the "+
  "robe worn by "+ETO->QCN+ "%^BLUE%^!%^RESET%^");
  return (damage*(1/2));
 }
}
