#include <std.h>
inherit "/d/common/obj/armour/breastplate";

int OWNED;
string owner;

void create(){
   ::create();
   set_name("%^RESET%^%^GREEN%^Breastplate of %^ORANGE%^Brambles%^RESET%^");
   set_short("%^RESET%^%^GREEN%^Breastplate of %^ORANGE%^Brambles%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^A thorny breastplate%^RESET%^");
   set_id(({"breastplate","breast plate","plate","armor"}));
   set_long("%^RESET%^This is a rather %^ORANGE%^w%^GREEN%^il%^ORANGE%^d"
" %^RESET%^looking breastplate, composed completely of %^ORANGE%^brambles"
" %^RESET%^and %^ORANGE%^thorns %^RESET%^that look as though they have been"
" %^GREEN%^grown, %^RESET%^or are still %^GREEN%^growing, %^RESET%^due to some inner"
" %^CYAN%^magic.  %^RESET%^A few %^GREEN%^leaves %^RESET%^stick out here and there,"
" as well as a few %^GREEN%^vines %^RESET%^that constantly seem to be"
" %^ORANGE%^t%^GREEN%^wi%^ORANGE%^st%^GREEN%^in%^ORANGE%^g %^RESET%^and"
" %^GREEN%^mo%^ORANGE%^vi%^GREEN%^ng %^RESET%^throughout the %^ORANGE%^"
"pl%^GREEN%^at%^ORANGE%^e%^RESET%^.\n");
   set_lore("%^RESET%^%^GREEN%^The breastplate of %^ORANGE%^brambles %^GREEN%^has"
" long been rumored to exist, but until now, no living proof has ever been found."
"  Said to be an actual living %^ORANGE%^organism %^GREEN%^grown in the"
" %^BOLD%^%^GREEN%^forest %^RESET%^%^GREEN%^for the sole purpose of protecting"
" its eventual master, one can feel honored to be chosen as such.%^RESET%^");
   set_property("lore difficulty",12);
   set_property("enchantment",2);
      if(TO->query_property("enchantment")< 2){
      remove_property("enchantment");
      set_property("enchantment",2);
      }   
   set_value(0);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
}

void init()
{
   ::init();
   if(!interactive(ETO)) return;
   if(interactive(TP) && TP == environment(TO) && !OWNED) {
   owner = TPQN;
   OWNED = 1;
   set_size(TP->query_size());
   }
}

int wearme()
{
   if((string)TPQN != owner) {
      tell_object(ETO,"%^RESET%^%^GREEN%^The vines recoil in horror as you try to wear the armor and lash out at you! 
You are not its master!%^RESET%^");
      tell_room(environment(ETO),"%^RESET%^%^GREEN%^"+ETO->query_cap_name()+" screams in pain as the vines turn against "+ETO->query_objective()+".%^RESET%^",ETO);
      set_property("magic",1);
      ETO->do_damage("torso",random(20)+10);
      ETO->add_attacker(TO);
      ETO->continue_attack();
      ETO->remove_attacker(TO);
      remove_property("magic");
      return 0;
   }
   tell_object(ETO,"%^RESET%^The %^GREEN%^vines %^RESET%^begin to %^ORANGE%^tw%^GREEN%^is%^ORANGE%^t %^RESET%^and %^GREEN%^t%^ORANGE%^ur%^GREEN%^n, %^RESET%^wrapping themselves securely around you as you wear the %^ORANGE%^pl%^GREEN%^at%^ORANGE%^e.%^RESET%^");
   tell_room(environment(ETO),"%^RESET%^The %^GREEN%^vines %^RESET%^of the %^ORANGE%^pl%^GREEN%^at%^ORANGE%^e %^RESET%^come to %^GREEN%^life %^RESET%^as they wrap themselves securely around "+ETO->query_cap_name()+".%^RESET%^",ETO);
   return 1;
}
int removeme(){
   tell_object(ETO,"%^RESET%^%^GREEN%^The vines release their protective grip as you remove the plate.%^RESET%^");
   tell_room(environment(ETO),"%^RESET%^%^GREEN%^The vines slowly release their protective grip on "+ETO->query_cap_name()+" as "+ETO->query_subjective()+" removes the armor.%^RESET%^",ETO);
   return 1;
}

void set_owner(string str){
   owner = str;
   OWNED = 1;
}