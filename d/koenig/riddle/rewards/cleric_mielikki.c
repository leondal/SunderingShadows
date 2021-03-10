#include <std.h>
inherit "/d/common/obj/armour/breastplate";

int OWNED;
string owner;

void create(){
   ::create();
   set_name("%^RESET%^%^GREEN%^F%^BOLD%^%^GREEN%^o%^RESET%^%^ORANGE%^r%^BOLD%^%^GREEN%^e%^RESET%^%^ORANGE%^s%^GREEN%^t%^BOLD%^%^GREEN%^pl%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^te%^RESET%^");
   set_short("%^RESET%^%^GREEN%^F%^BOLD%^%^GREEN%^o%^RESET%^%^ORANGE%^r%^BOLD%^%^GREEN%^e%^RESET%^%^ORANGE%^s%^GREEN%^t%^BOLD%^%^GREEN%^pl%^RESET%^%^GREEN%^a%^BOLD%^%^GREEN%^te%^RESET%^");
   set_obvious_short("%^RESET%^%^GREEN%^A %^BOLD%^%^BLACK%^d%^RESET%^%^GREEN%^a%^BOLD%^%^BLACK%^r%^RESET%^%^GREEN%^k green breastplate%^RESET%^");
   set_id(({"breastplate","breast plate","plate","armor"}));
   set_long("%^BOLD%^%^GREEN%^This %^BLACK%^d%^RESET%^%^GREEN%^"
"a%^BOLD%^%^BLACK%^r%^RESET%^%^GREEN%^k green breastplate"
" %^BOLD%^%^GREEN%^is not only made from several large,"
" interlocking %^RESET%^%^GREEN%^leaves %^BOLD%^%^GREEN%^that"
" are specially enchanted to protect the wearer from harm, but"
" is also designed to have the added benefit of %^RESET%^"
"%^GREEN%^cam%^ORANGE%^o%^GREEN%^fl%^ORANGE%^a%^GREEN%^ge"
" %^BOLD%^%^GREEN%^when in the %^RESET%^%^GREEN%^forest."
"  %^BOLD%^%^GREEN%^A light green %^RESET%^%^GREEN%^gl"
"%^BOLD%^%^GREEN%^o%^RESET%^%^GREEN%^w %^BOLD%^%^GREEN%^can be"
" seen coming from withen the layers, and the image of a"
" %^RESET%^s%^BOLD%^%^WHITE%^i%^RESET%^lv%^BOLD%^%^WHITE%^e"
"%^RESET%^ry %^BOLD%^%^WHITE%^white unicorn %^BOLD%^%^GREEN%^"
"facing to the left %^RESET%^sh%^BOLD%^%^CYAN%^i%^RESET%^"
"mm%^BOLD%^%^CYAN%^e%^RESET%^rs softly %^BOLD%^%^GREEN%^across"
" the surface.  Amazingly enough, you can occassionally"
" hear the faint sound of the %^RESET%^breeze %^BOLD%^"
"%^GREEN%^rustling through the %^RESET%^%^GREEN%^forest leaves"
" %^BOLD%^%^GREEN%^from somewhere withen the plate, accompanied"
" by a sudden burst of %^RESET%^%^MAGENTA%^sweet %^BOLD%^"
"%^GREEN%^smelling, fresh %^RESET%^%^GREEN%^forest %^RESET%^air.\n");
   set_lore("%^RESET%^%^GREEN%^It is said that in the early days"
" of life, a great %^ORANGE%^warrior %^GREEN%^was sent to protect"
" the %^BOLD%^%^GREEN%^forests %^RESET%^%^GREEN%^from the"
" ever-evolving %^BOLD%^%^BLACK%^evils %^RESET%^%^GREEN%^of the"
" plains. The %^ORANGE%^warrior %^GREEN%^fought %^MAGENTA%^"
"valiantly %^GREEN%^for his cause, but was one day defeated and"
" left for %^BOLD%^%^BLACK%^dead %^RESET%^%^GREEN%^withen the"
" very %^BOLD%^%^GREEN%^forest %^RESET%^%^GREEN%^he strove to"
" protect.  His %^RED%^blood %^GREEN%^spilled out onto the"
" %^BOLD%^%^GREEN%^forest floor, %^RESET%^%^GREEN%^seeping into"
" the %^BOLD%^%^GREEN%^leaves %^RESET%^%^GREEN%^that %^ORANGE"
"%^littered %^GREEN%^the ground below him.  Seeing the distress"
" of her %^MAGENTA%^beloved %^ORANGE%^warrior, %^BOLD%^"
"%^GREEN%^Mielikki %^RESET%^%^GREEN%^came down and guided him to"
" a place of safety where she hoped he could recover.  There are"
" still tales that he wanders the %^BOLD%^%^GREEN%^forests,"
" %^RESET%^%^GREEN%^fighting the %^BOLD%^%^BLACK%^evils"
" %^RESET%^%^GREEN%^of the land, but no living being has ever seen"
" him since.  This breastplate however, is rumored to"
" be composed of the %^BOLD%^%^GREEN%^leaves %^RESET%^%^GREEN%^"
"that had lain beneath him on that fateful day, and will serve"
" to protect the next %^MAGENTA%^valiant protector %^RESET%^"
"%^GREEN%^of the %^BOLD%^%^GREEN%^forest %^RESET%^%^GREEN%^from"
" that same fate.");
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
   tell_object(ETO,"%^RESET%^%^GREEN%^The leaves rustle softly as you slip into the breastplate.%^RESET%^");
   tell_room(environment(ETO),"%^RESET%^%^GREEN%^The leaves rustle softly as "+ETO->query_cap_name()+" slips into the breastplate.",ETO);
   return 1;
}


int removeme(){
   tell_object(ETO,"%^RESET%^%^GREEN%^You long for the forest as you remove the armor.%^RESET%^");
   return 1;
}

void set_owner(string str){
   owner = str;
   OWNED = 1;
}