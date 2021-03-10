//changed these as well, since they appear to be too good for the level range the area is meant for - tsera
//enchantment has been changed from  1+random(2) to random(2), and health is lowest level - 10
// set to give +1 con instead, as this will now award extra hp and be much cleaner. Boosted enchant. Nienne, 08/09.
// Fixing up so that they will always give the extra HP now that it works off +2 increments ~Circe~ 9/6/09
#include <std.h>
inherit ARMOUR;

nosave int flag;

void create(){
   ::create();
   set_name("amulet of health");
   set_short("%^GREEN%^Amulet of Health%^RESET%^");
   set_obvious_short("%^BOLD%^a platinum amulet%^RESET%^");
   set_id(({"amulet","bloodstone amulet","platinum amulet","neckthing"}));
   set_long("%^BOLD%^This amulet is made of a platinum torque "+
      "that fits snuggly around the wearer's neck.  A pendant "+
      "made of a square %^RESET%^%^GREEN%^bloo%^RED%^d%^GREEN%^stone "+
      "%^BOLD%^%^WHITE%^the color of %^RESET%^%^GREEN%^jade "+
      "%^BOLD%^%^WHITE%^with streaks of %^RESET%^%^RED%^red "+
      "%^BOLD%^%^WHITE%^dangles from the torque, providing "+
      "a little ornamentation to an otherwise plain - if "+
      "costly - piece of jewelry.");
   set_lore("The Amulet of Health was created ages ago by the firbolgs "+
      "of Lothwaite to help them combat the long winters in the "+
      "high altitudes of the Barrier Mountains.  The extra "+
      "heartiness has helped many firbolgs survive when the "+
      "fury of Auril's wrath would have taken them out.  "+
      "The manner of their construction is a well-guarded "+
      "secret even today.");
   set_property("lore difficulty",10);
   set_weight(2);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_ac(0);
   set_value(1750);
   set_property("enchantment",random(2)+1);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
   flag = 0;
}

int wearme(){
   if((string)ETO->query_name() == "firbolg ghost") return 1;
   if((int)ETO->query_level() < 15){
      tell_object(ETO,"%^BOLD%^%^RED%^The magic of the bloodstone "+
         "is far too powerful for you!");
      TO->remove();
      return 0;
   }
   if((int)ETO->query_stats("constitution") > 23){
      set_item_bonus("constitution",0);
      tell_object(ETO,"%^CYAN%^You feel a faint tingling as you "+
         "fasten the %^BOLD%^cool %^RESET%^%^CYAN%^amulet around your neck.%^RESET%^");
      tell_room(EETO,"%^GREEN%^"+ETOQCN+" fastens a platinum amulet "+
         "around "+ETO->QP+" neck.",ETO);
      return 1;
   }
   else set_item_bonus("constitution",2);
   flag = 1;
   tell_object(ETO,"%^GREEN%^You feel much more hearty as you "+
      "fasten the %^CYAN%^cool %^GREEN%^amulet around your neck.");
   tell_room(EETO,"%^GREEN%^"+ETOQCN+" fastens a platinum amulet "+
      "around "+ETO->QP+" neck.",ETO);
   return 1;
}

int unwearme(){
   if(flag){
      flag = 0;
      tell_object(ETO,"%^GREEN%^You feel strangely insubstantial "+
         "as you slip off the torque.");
      tell_room(EETO,"%^GREEN%^"+ETOQCN+" removes a platinum amulet "+
         "from around "+ETO->QP+" neck.",ETO);
   }
   return 1;
}
