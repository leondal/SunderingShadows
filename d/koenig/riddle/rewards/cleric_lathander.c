#include <std.h>
inherit "/d/common/obj/armour/breastplate";

int OWNED;
string owner;

void create(){
   ::create();
   set_name("%^YELLOW%^Breastplate of the %^MAGENTA%^d%^RESET%^%^ORANGE%^a%^YELLOW%^w%^RED%^n%^RESET%^");
   set_short("%^YELLOW%^Breastplate of the %^MAGENTA%^d%^RED%^a%^YELLOW%^w%^RESET%^%^ORANGE%^n%^RESET%^");
   set_obvious_short("%^YELLOW%^A golden breastplate%^RESET%^");
   set_id(({"breastplate","breast plate","plate","armor"}));
   set_long("%^RESET%^This %^YELLOW%^g%^RESET%^%^ORANGE%^o%^YELLOW%^ld%^RESET%^"
"%^ORANGE%^e%^YELLOW%^n breastplate %^RESET%^looks as though it were forged from"
" the %^YELLOW%^r%^WHITE%^a%^YELLOW%^y%^WHITE%^s %^RESET%^of the %^BOLD%^%^RED%^"
"r%^MAGENTA%^i%^RESET%^%^ORANGE%^s%^RED%^i%^MAGENTA%^n%^BOLD%^%^RED%^g %^YELLOW%^"
"sun %^RESET%^itself.  The slender %^MAGENTA%^fingers %^RESET%^of %^BOLD%^%^RED%^"
"s%^MAGENTA%^u%^YELLOW%^n%^RESET%^%^ORANGE%^r%^RED%^i%^MAGENTA%^s%^BOLD%^%^RED%^e"
" %^WHITE%^radiate %^RESET%^out from the awakening %^YELLOW%^sun %^RESET%^on the"
" front of this lovely plate in %^BOLD%^%^RED%^h%^MAGENTA%^u%^RESET%^%^RED%^e"
"%^ORANGE%^s %^RESET%^of %^BOLD%^%^RED%^r%^MAGENTA%^o%^RED%^se, %^RESET%^%^RED%^"
"r%^BOLD%^%^RED%^e%^RESET%^%^RED%^d, %^BOLD%^%^MAGENTA%^magenta %^RESET%^and"
" %^ORANGE%^orange%^RESET%^... all the colors of the %^BOLD%^%^RED%^d%^MAGENTA%^"
"a%^RESET%^%^ORANGE%^w%^MAGENTA%^n.  %^CYAN%^Ancient s%^BOLD%^%^CYAN%^y"
"%^RESET%^%^CYAN%^mbo%^BOLD%^%^CYAN%^l%^RESET%^%^CYAN%^s %^RESET%^of the"
" %^YELLOW%^sun %^RESET%^line the edges of this plate that emit a pleasantly"
" %^ORANGE%^w%^BOLD%^%^RED%^a%^RESET%^%^MAGENTA%^r%^CYAN%^m %^YELLOW%^glow"
" %^RESET%^as they %^MAGENTA%^hypnotically s%^BOLD%^%^MAGENTA%^w%^RESET%^"
"%^MAGENTA%^i%^BOLD%^%^MAGENTA%^r%^RESET%^%^MAGENTA%^l %^RESET%^and %^MAGENTA%^"
"m%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^v%^BOLD%^%^MAGENTA%^e, %^RESET%^"
"constantly %^ORANGE%^fading %^RESET%^into and out of existance.\n");
   set_lore("%^RESET%^The %^ORANGE%^ancient civilization %^RESET%^of %^CYAN%^Htuelin %^RESET%^is said the be the mother of this plate.  Favored by the %^BOLD%^%^MAGENTA%^Morning Lord %^RESET%^because of their devotion, they were given special powers to forge the finest of armors using his blessings.  Passed on from generation to generation, this plate embodies the very essence of the people of the %^BOLD%^%^RED%^d%^MAGENTA%^a%^RESET%^%^ORANGE%^w%^MAGENTA%^n.%^RESET%^");
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
   tell_object(ETO,"%^RESET%^The %^MAGENTA%^symbols %^RESET%^of the %^YELLOW%^sun %^RESET%^intensify in %^BOLD%^%^RED%^c%^MAGENTA%^o%^RESET%^%^ORANGE%^l%^MAGENTA%^o%^BOLD%^%^RED%^r %^RESET%^as you slip into the armor.%^RESET%^");
   tell_room(environment(ETO),"%^RESET%^The %^MAGENTA%^symbols %^RESET%^of the %^YELLOW%^sun %^RESET%^intensify in %^BOLD%^%^RED%^c%^MAGENTA%^o%^RESET%^%^ORANGE%^l%^MAGENTA%^o%^BOLD%^%^RED%^r %^RESET%^as "+ETO->query_cap_name()+" wears the armor.%^RESET%^",ETO);
   return 1;
}


int removeme(){
   tell_object(ETO,"%^RESET%^The %^BOLD%^%^RED%^c%^MAGENTA%^o%^RESET%^%^ORANGE%^l%^MAGENTA%^o%^YELLOW%^r%^RED%^s %^RESET%^in the breastplate %^MAGENTA%^fade %^RESET%^as you take off the armor.%^RESET%^");
   return 1;
}

void set_owner(string str){
   owner = str;
   OWNED = 1;
}