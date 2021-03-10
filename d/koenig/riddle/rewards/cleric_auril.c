#include <std.h>
inherit "/d/common/obj/armour/breastplate";

int OWNED;
string owner;

void create(){
   ::create();
   set_name("%^BOLD%^%^CYAN%^Breastplate of %^WHITE%^f%^CYAN%^r%^RESET%^%^CYAN%^o%^BOLD%^%^CYAN%^s%^WHITE%^t%^RESET%^");
   set_short("%^BOLD%^%^CYAN%^Breastplate of %^WHITE%^f%^CYAN%^r%^RESET%^%^CYAN%^o%^BOLD%^%^CYAN%^s%^WHITE%^t%^RESET%^");
   set_obvious_short("%^RESET%^%^CYAN%^A %^BOLD%^%^CYAN%^f%^WHITE%^r%^RESET%^ot%^BOLD%^%^WHITE%^h%^CYAN%^y %^WHITE%^wh%^RESET%^i%^BOLD%^%^WHITE%^te %^RESET%^%^CYAN%^breastplate%^RESET%^");
   set_id(({"breastplate","breast plate","armor","plate"}));
   set_long("%^BOLD%^%^CYAN%^This breastplate is made of layers of"
" pure %^WHITE%^i%^RESET%^c%^BOLD%^%^WHITE%^e %^CYAN%^that are"
" magically enchanted to be rock hard and forever"
" %^RESET%^f%^BOLD%^%^WHITE%^r%^CYAN%^oz%^WHITE%^e%^RESET%^n."
"  %^BOLD%^%^CYAN%^The image of a single, large"
" %^WHITE%^snowflake %^CYAN%^is delicately %^RESET%^%^CYAN%^"
"etched %^BOLD%^%^CYAN%^on the shimmering %^CYAN%^surface, giving"
" an indication as to who the wearer of this plate serves.  More"
" interestingly, acting much like a %^RESET%^%^CYAN%^magical"
" %^BOLD%^%^WHITE%^h%^RESET%^o%^CYAN%^l%^BOLD%^%^CYAN%^og%^RESET%^"
"%^CYAN%^r%^RESET%^a%^BOLD%^%^WHITE%^m, %^CYAN%^this armor"
" depicts the image of a woman with a %^RESET%^bone-%^BOLD%^"
"%^WHITE%^chilling %^CYAN%^smile standing in the center of a"
" %^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^r%^BOLD%^"
"%^BLACK%^m %^CYAN%^as her raised arms call down the"
" %^BLACK%^fury %^CYAN%^of a constant %^RESET%^blizzard"
" %^BOLD%^%^CYAN%^between its %^WHITE%^i%^RESET%^c%^BOLD%^"
"%^WHITE%^y %^CYAN%^layers.%^RESET%^\n");
   set_lore("%^RESET%^It is rumored that soon after the days of creation, the %^BOLD%^%^WHITE%^frostmaiden %^RESET%^bestowed upon her high priestess, Eswaiyl, the essence of the %^BOLD%^%^BLACK%^w%^WHITE%^i%^RESET%^nt%^BOLD%^%^WHITE%^e%^BLACK%^r storm.  %^RESET%^As Eswaiyl's own life force began to falter with age, she looked for ways to bring herself to immortality.  Using the power granted to her, she encased herself in a block of %^BOLD%^%^CYAN%^i%^WHITE%^c%^CYAN%^e, %^RESET%^ensuring that it stayed forever %^BOLD%^%^WHITE%^frozen %^RESET%^by calling a fierce winter %^BOLD%^%^BLACK%^storm %^RESET%^withen the center.  This breastplate is said to be carved from that very same block and mirrors the great power that will now protect the one who proves themself worthy.");
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
      tell_object(ETO,"%^BOLD%^%^CYAN%^The figure in the armor does not recognize you as its master and turns the %^BLACK%^fury %^CYAN%^of the %^BLACK%^storm %^CYAN%^against you!");
      tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->query_cap_name()+" gets pelted with %^WHITE%^ice %^CYAN%^as the figure in the armor turns against "+ETO->query_objective()+" when "+ETO->query_subjective()+" tries to wear the breastplate.%^RESET%^",ETO);
      set_property("magic",1);
      ETO->do_damage("torso",random(20)+10);
      ETO->add_attacker(TO);
      ETO->continue_attack();
      ETO->remove_attacker(TO);
      remove_property("magic");
      return 0;
   }
   tell_object(ETO,"%^BOLD%^%^CYAN%^A cold smile crosses your lips as you slip on the smooth armor and feel the power of your goddess.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^CYAN%^The %^BLACK%^howl %^CYAN%^of a %^RESET%^%^CYAN%^Northern %^RESET%^gale %^BOLD%^%^CYAN%^whistles through the room as the temperature in the room suddenly drops.%^RESET%^",ETO);
   return 1;
}


int removeme(){
   tell_object(ETO,"%^RESET%^%^CYAN%^The presence of %^BOLD%^%^WHITE%^A%^CYAN%^u%^WHITE%^r%^CYAN%^i%^WHITE%^l %^RESET%^%^CYAN%^can be felt leaving you as you take off the armor.%^RESET%^");
   return 1;
}

void set_owner(string str){
   owner = str;
   OWNED = 1;
}