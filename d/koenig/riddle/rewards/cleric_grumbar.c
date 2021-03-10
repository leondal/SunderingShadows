#include <std.h>
inherit "/d/common/obj/armour/breastplate";

int OWNED;
string owner;

void create(){
   ::create();
   set_name("%^RESET%^Breastplate of S%^BOLD%^%^WHITE%^t%^BLACK%^o%^WHITE%^n%^RESET%^e");
   set_short("%^RESET%^Breastplate of S%^BOLD%^%^WHITE%^t%^BLACK%^o%^WHITE%^n%^RESET%^e");
   set_obvious_short("%^RESET%^A d%^BOLD%^%^BLACK%^u%^WHITE%^l%^RESET%^l breastplate");
   set_id(({"breastplate","breast plate","plate","armor"}));
   set_long("%^RESET%^This breastplate is quite impressive to look"
" at.  Designed from %^BOLD%^%^BLACK%^massive %^RESET%^s%^BOLD%^"
"%^BLACK%^l%^WHITE%^a%^RESET%^b%^BOLD%^%^BLACK%^s %^RESET%^of"
" pure %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^WHITE%^a%^RESET%^"
"n%^BOLD%^%^BLACK%^i%^RESET%^t%^BOLD%^%^BLACK%^e, %^RESET%^the"
" faint %^RED%^gl%^BOLD%^%^RED%^o%^RESET%^%^RED%^w %^RESET%^of"
" what looks to be %^RED%^lava %^RESET%^can be seen underneath"
" the hardened %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^WHITE%^c"
"%^BLACK%^k, %^RESET%^allowing the %^BOLD%^%^BLACK%^g%^RESET%^r"
"%^BOLD%^%^BLACK%^a%^WHITE%^n%^BLACK%^i%^RESET%^t%^BOLD%^%^BLACK%^"
"e %^RESET%^plates to slide around and conform to the wearers"
" body perfectly.  The image of three %^BLUE%^mountains"
" %^RESET%^standing side by side is carved into the %^BOLD%^"
"%^BLACK%^hard %^RESET%^surface, constantly emitting a steady,"
" unchanging %^ORANGE%^e%^RESET%^a%^ORANGE%^r%^BOLD%^%^BLACK%^"
"t%^RESET%^%^ORANGE%^h%^RESET%^l%^ORANGE%^y au%^YELLOW%^r"
"%^RESET%^ORANGE%^a.%^RESET%^\n");
   set_lore("It is said that a small human settlement in the"
" mountains far to the north had Grumbars favor; rich"
" %^RED%^lava flows %^RESET%^from the mountain provided them"
" with heat and ways to melt their %^BOLD%^%^BLACK%^o%^RESET%^r"
"%^BOLD%^%^BLACK%^e, %^RESET%^giving them a way to boon from the"
" %^ORANGE%^earthlords %^RESET%^blessings.  Change began to take"
" place however, and the human settlement made a radical change"
" from trading goods made from the %^ORANGE%^earth %^RESET%^to"
" ones made from the %^BLUE%^s%^CYAN%^e%^BOLD%^%^BLUE%^a"
" %^RESET%^and %^BOLD%^%^WHITE%^air.  %^RESET%^To express his"
" displeasure, the lord of the earth called upon a mighty"
" %^ORANGE%^e%^RESET%^a%^BOLD%^%^BLACK%^r%^RESET%^t%^ORANGE%^"
"h%^RESET%^q%^BOLD%^%^BLACK%^u%^RESET%^a%^BOLD%^%^BLACK%^k"
"%^RESET%^%^ORANGE%^e %^RESET%^that raised a mountain range"
" to cut off their passageway to the %^BLUE%^s%^CYAN%^"
"e%^BOLD%^%^BLUE%^a, %^RESET%^to prevent the %^BOLD%^%^WHITE%^winds"
" %^RESET%^from reaching them, and to stop the influence of the"
" outside world.  Few travellers have found this fabled land"
" since, but it is said that this plate has been carved from"
" the %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^WHITE%^a%^RESET%^"
"n%^BOLD%^%^BLACK%^i%^RESET%^t%^BOLD%^%^BLACK%^e %^RESET%^found"
" in that very range to serve as memory.");
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
      tell_object(ETO,"The armor refuses to fit to your form! 
You are not its master!");
      tell_room(environment(ETO),""+ETO->query_cap_name()+" screams in pain as "+ETO->query_subjective()+" tries to slip on
the armor.",ETO);
      set_property("magic",1);
      ETO->do_damage("torso",random(20)+10);
      ETO->add_attacker(TO);
      ETO->continue_attack();
      ETO->remove_attacker(TO);
      remove_property("magic");
      return 0;
   }
   tell_object(ETO,"%^RESET%^You snap the breastplate into place and feel much more protected as the %^BOLD%^%^WHITE%^%^r%^BLACK%^o%^RESET%^c%^BOLD%^%^BLACK%^k %^RESET%^hard armor conforms to your body.%^RESET%^");
   tell_room(environment(ETO),"%^RESET%^%^ORANGE%^ "+ETO->query_cap_name()+" looks more confident as "+ETO->query_subjective()+" snaps the %^RESET%^r%^BOLD%^%^BLACK%^o%^WHITE%^c%^RESET%^k %^ORANGE%^armor into place.%^RESET%^",ETO);
   return 1;
}


int removeme(){
   tell_object(ETO,"You feel vulnerable once again as you remove the armor.");
   return 1;
}

void set_owner(string str){
   owner = str;
   OWNED = 1;
}