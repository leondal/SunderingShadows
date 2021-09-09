#define COLOURS ({"%^RED%^russet%^RESET%^", "%^BLUE%^blue%^RESET%^",\
                                          "%^GREEN%^green%^RESET%^",\
   "%^ORANGE%^o%^RED%^r%^ORANGE%^a%^RED%^n%^ORANGE%^g%^RED%^e%^RESET%^"})
#define COLOUR_CODES ({"%^RED%^", "%^BLUE%^", "%^GREEN%^", "%^ORANGE%^",})
#define WARRIOR 1
#define ASSASSIN 2
#define CEREMONIAL 3
#define TRACKER 4
#define DIVINER 5
#include <std.h>
#include <daemons.h>
#include "../tecqumin.h"

inherit ARMOUR;
int col1, col2, which;

void create() {
   string colour1, colour2, code1, code2;
   ::create();
   set_name("poncho");
   set_id(({"poncho","colourful poncho"}));
   col1 = random(sizeof(COLOURS));
   col2 = random(sizeof(COLOURS));
   while(col2 == col1){
     col2 = random(sizeof(COLOURS));
   }
   colour1 = COLOURS[col1];
   colour2 = COLOURS[col2];
   code1 = COLOUR_CODES[col1];
   code2 = COLOUR_CODES[col2];
   which = random(5) +1;
   set_obvious_short("%^RESET%^" + code1 + "a " + code2 + "c" + code1 + "o" + code2
     + "l" + code1 + "ou" + code2 + "rf" + code1 + "u" + code2 + "l "
     + code1 + "p" + code2 + "o" + code1 + "nch" + code2 + "o");
   set_short("%^CYAN%^Tecqumin "+code1 + "sp" + code2 + "i" + code1
     + "r" + code2 + "i" + code1 +"t p" + code2 + "o" + code1 + "nch"
     + code2 + "o");
   set_long(long_desc());
   set_lore("The poncho was one of the traditional pieces of dress of"
     +" the %^CYAN%^Tecqumin%^RESET%^ civilisation, and it is known"
     +" that a number of enchanted varieties were made. Sages have"
     +" speculated that since the downfall of the %^CYAN%^Tecqumin"
     +" %^RESET%^civilisation, some varieties may exist that have taken"
     +" on the ethereal characteristics of their cursed, ghostly owners.");
   set_weight(6);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_size(-1);
   set_ac(0);
   set_value(2000);
   set_property("enchantment",6);
   set_wear( (: TO,"wear_func" :) );
   set_remove( (: TO,"remove_func" :) );
   set_struck((:TO,"strike_func":));
}

int wear_func() {
   string code1, code2;
   do_bonuses();
   code1 = COLOUR_CODES[col1];
   code2 = COLOUR_CODES[col2];
  tell_object(ETO,"You slide the " + query_obvious_short() + " %^RESET%^over your head, and smooth it down over your shoulders");
  if (objectp(EETO)){
    tell_room(EETO, ETO->QCN + " slides the " + query_obvious_short() + " %^RESET%^over " + ETO->QP + " head, and smooths it down over " + ETO->QP + " shoulders", ETO );
  }
  return 1;
}

string long_desc(){
   string colour1, colour2,  code1, code2, result;
   colour1 = COLOURS[col1];
   colour2 = COLOURS[col2];
   code1 = COLOUR_CODES[col1];
   code2 = COLOUR_CODES[col2];
   result = "This " + code1 + "p" + code2 + "o" + code1 + "nch" + code2
     +"o%^RESET%^ is made from a simple square of " +code1+ "fabric"
     +"%^RESET%^, "+ code2 + "woven%^RESET%^ with geometric"
     +" designs in threads of " + colour1 + " and " + colour2 + ". It"
     +" has a central hole for the wearer's head, and drapes over the"
     +" back, chest and arms, providing protection from the%^MAGENTA%^"
     +" elements%^RESET%^ without significantly impeding movement. The"
     +" whole thing is lighter than it looks, and has an odd, %^BOLD%^"
     +"%^WHITE%^in%^CYAN%^subst%^WHITE%^a%^CYAN%^nt%^WHITE%^ia%^CYAN%^l"
     +" %^RESET%^feel to it.";

   switch (which){
   case WARRIOR:
     result = result + " It is %^BOLD%^%^WHITE%^embroidered%^RESET%^ with"
       +" a small design representing a pair of %^BOLD%^%^WHITE%^cr%^RESET%^o"
       +"%^BOLD%^%^WHITE%^ss%^RESET%^e%^BOLD%^%^WHITE%^d"
       +" sw%^RESET%^o%^BOLD%^%^WHITE%^rds.";
     break;
   case ASSASSIN:
     result =  result + " It is %^BOLD%^%^BLACK%^embroidered%^RESET%^"
       +" with a small motif of an unsheathed %^BOLD%^%^BLACK%^dagger%^RESET%^.";
     break;
   case CEREMONIAL:
     result =  result + " It is %^BOLD%^%^BLACK%^embroidered%^RESET%^"
       +" with a small motif of a %^BOLD%^%^BLACK%^ragged black blindfold%^RESET%^.";
     break;
   case TRACKER:
     result = result + " It is %^BOLD%^%^GREEN%^embr%^RESET%^%^GREEN%^oi"
       +"%^BOLD%^d%^RESET%^%^GREEN%^e%^BOLD%^r%^RESET%^%^GREEN%^e%^BOLD%^d%^RESET%^"
       +" with a small motif of a %^BOLD%^%^GREEN%^ju%^RESET%^%^GREEN%^ng%^BOLD%^l"
       +"%^RESET%^%^GREEN%^e %^ORANGE%^path%^RESET%^.";
     break;
   case DIVINER:
     result = result + " It is %^BOLD%^%^ORANGE%^embr%^RESET%^%^ORANGE%^oi"
       +"%^BOLD%^d%^RESET%^%^ORANGE%^e%^BOLD%^r%^RESET%^%^ORANGE%^e%^BOLD%^d%^RESET%^"
       +" with a small motif of a %^ORANGE%^bl%^RESET%^%^ORANGE%^a%^BOLD%^zing s%^RESET%^%^ORANGE%^u%^BOLD%^n%^RESET%^.";
     break;
   }
   return result;
}

void do_bonuses(){
  switch(which){
  case WARRIOR:
    set_item_bonus("constitution", 6);
    break;
  case ASSASSIN:
    set_item_bonus("dexterity", 6);
    break;
  case CEREMONIAL:
    set_item_bonus("wisdom", 6);
    break;
  case TRACKER:
    set_item_bonus("survival", 6);
    break;
  case DIVINER:
    set_item_bonus("intelligence", 6);
    break;
  }
}

int remove_func() {
   string code1, code2;
   code1 = COLOUR_CODES[col1];
   code2 = COLOUR_CODES[col2];
   tell_object(ETO,"You lift the " + query_obvious_short() + " %^RESET%^off over your head");
   return 1;
}

int * query_cols(){
  return ({col1, col2});
}

string * query_colour_codes(){
  return ({COLOUR_CODES[col1], COLOUR_CODES[col2]});
}

int strike_func(int damage, object what, object who)
{
   string code1, code2;
    object mob;
   code1 = COLOUR_CODES[col1];
   code2 = COLOUR_CODES[col2];
    if(!objectp(ETO)) return 0;
    if(!objectp(who)) return 0;
    if(random(6)<1)
    {
        tell_room(EETO, ETOQCN + "'s " + query_obvious_short() + " %^RESET%^flickers, and " + ETO->QS + " becomes momentarily insubstantial, allowing " + who->QCN+" 's blow to pass right through " + ETO->QO, ({ETO, who}));

        tell_object(ETO, "Your " + query_obvious_short() + " %^RESET%^goes cold and you feel a strange shock as " + who->QCN + "'s attack passes right through, leaving you feeling weird but otherwise unharmed.");

        tell_object(who,  ETOQCN + "'s " + query_obvious_short() + " %^RESET%^flickers, and " + ETO->QS + " becomes momentarily insubstantial, allowing your blow to pass right through " + ETO->QO);
        return 0;
    }
    return damage;
}
