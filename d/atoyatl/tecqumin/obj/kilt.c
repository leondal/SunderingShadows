#define COLOURS ({"%^CYAN%^light blue%^RESET%^", "%^BOLD%^%^WHITE%^%^white%^RESET%^",\
                                          "%^ORANGE%^brown%^RESET%^"})
#define COLOUR_CODES ({"%^CYAN%^", "%^BOLD%^%^WHITE%^", "%^ORANGE%^",})
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
string obvious;

void create() {
   string colour1, colour2,  code1, code2;
   ::create();
   set_name("kilt");
   which = random(5)+1;
   set_id(({"kilt", "unpleated kilt", "tecqumin kilt", "short kilt"}));
   col1 = random(sizeof(COLOURS));
   col2 = random(sizeof(COLOURS));
   while (col1 == col2){
     col2 = random(sizeof(COLOURS));
   }
   colour1 = COLOURS[col1];
   colour2 = COLOURS[col2];
   code1 = COLOUR_CODES[col1];
   code2 = COLOUR_CODES[col2];
   obvious = "%^BOLD%^%^WHITE%^short kilt";
   switch (which){
   case WARRIOR:
     set_obvious_short(obvious + "%^BOLD%^%^WHITE%^ with a %^RESET%^crossed sword%^BOLD%^%^WHITE%^ motif");
     set_short(code1 + colour1 + " %^RESET%^%^CYAN%^Tecqumin " + code1 + "warrior's %^BOLD%^%^WHITE%^k%^RESET%^i%^BOLD%^%^WHITE%^lt");
     break;
   case ASSASSIN:
     set_obvious_short(obvious + "%^BOLD%^%^WHITE%^ with an %^BOLD%^%^BLACK%^unsheathed dagger%^BOLD%^%^WHITE%^ motif");
     set_short(code1 + colour1 +  " %^RESET%^%^CYAN%^Tecqumin " + code1 + "assassin's %^BOLD%^%^WHITE%^k%^RESET%^i%^BOLD%^%^WHITE%^lt");
     break;
   case CEREMONIAL:
     set_obvious_short(obvious + "%^BOLD%^%^WHITE%^ with a %^BOLD%^%^BLACK%^black blindfold%^BOLD%^%^WHITE%^ motif");
     set_short(code1 + colour1 + " %^RESET%^%^CYAN%^Tecqumin " + code1 + "ceremonial %^BOLD%^%^WHITE%^k%^RESET%^i%^BOLD%^%^WHITE%^lt");
     break;
   case TRACKER:
     set_obvious_short(obvious + "%^BOLD%^%^WHITE%^ with a %^BOLD%^%^GREEN%^ju%^RESET%^%^GREEN%^ng%^BOLD%^l%^RESET%^"
       +"%^GREEN%^e %^ORANGE%^path%^BOLD%^%^WHITE%^ motif");
     set_short(code1 + colour1 + " %^RESET%^%^CYAN%^Tecqumin " + code1 + "tracker's %^BOLD%^%^WHITE%^k%^RESET%^i%^BOLD%^%^WHITE%^lt");
     break;
   case DIVINER:
     set_obvious_short(obvious + "%^BOLD%^%^WHITE%^ with a %^ORANGE%^bl%^RESET%^%^ORANGE%^a%^BOLD%^zing s%^RESET%^%^ORANGE%^u%^BOLD%^n%^WHITE%^ motif");
     set_short(code1 + colour1 + " %^RESET%^%^CYAN%^Tecqumin " + code1 + "diviner's %^BOLD%^%^WHITE%^k%^RESET%^i%^BOLD%^%^WHITE%^lt");
     break;
   }
   set_long(long_desc());
   set_lore("The kilt was one of the traditional pieces of dress of"
     +" the %^CYAN%^Tecqumin%^RESET%^ civilisation, and it is known"
     +" that a number of enchanted varieties were made. Sages have"
     +" speculated that since the downfall of the %^CYAN%^Tecqumin"
     +" %^RESET%^civilisation, some varieties may exist that have taken"
     +" on the ethereal characteristics of their cursed, ghostly owners.");
   set_weight(4);
   set_type("clothing");
   set_limbs(({"left leg", "right leg"}));
   set_size(-1);
   set_ac(0);
   set_value(2000);
   set_property("enchantment",6);
   set_wear( (: TO,"wear_func" :) );
   set_remove( (: TO,"remove_func" :) );
   set_struck((:TO,"strike_func":));
}

string long_desc(){
   string colour1, colour2,  code1, code2, result;
   colour1 = COLOURS[col1];
   colour2 = COLOURS[col2];
   code1 = COLOUR_CODES[col1];
   code2 = COLOUR_CODES[col2];
   result = "This simple " + code1 + "kilt%^RESET%^ is made of fine linen."
     +" It falls to around mid thigh and is quite fitted to the wearer's form."
     +" It has a fastening of " + colour2 + " rope";
   switch (which){
   case WARRIOR:
     result = result +  ", and is %^BOLD%^%^WHITE%^embroidered%^RESET%^ with"
       +" a small design representing a pair of %^BOLD%^%^WHITE%^cr%^RESET%^o"
       +"%^BOLD%^%^WHITE%^ss%^RESET%^e%^BOLD%^%^WHITE%^d"
       +" sw%^RESET%^o%^BOLD%^%^WHITE%^rds%^RESET%^.";
     return result;
     break;
   case ASSASSIN:
     result = result + ", and is %^BOLD%^%^BLACK%^embroidered%^RESET%^"
       +" with a small motif of an unsheathed %^BOLD%^%^BLACK%^dagger%^RESET%^.";
     return result;
     break;
   case CEREMONIAL:
     result = result + ", and is %^BOLD%^%^BLACK%^embroidered%^RESET%^"
       +" with a small motif of a %^BOLD%^%^BLACK%^ragged black blindfold%^RESET%^.";
     return result;
     break;
   case TRACKER:
     result = result + ", and is %^BOLD%^%^GREEN%^embr%^RESET%^%^GREEN%^oi"
       +"%^BOLD%^d%^RESET%^%^GREEN%^e%^BOLD%^r%^RESET%^%^GREEN%^e%^BOLD%^d%^RESET%^"
       +" with a small motif of a %^BOLD%^%^GREEN%^ju%^RESET%^%^GREEN%^ngl%^RESET%^"
       +"%^GREEN%^e %^ORANGE%^path%^RESET%^.";
     return result;
     break;
   case DIVINER:
     result = result + ", and is %^BOLD%^%^BLACK%^embroidered%^RESET%^"
       +" with a small motif of a %^BOLD%^%^ORANGE%^bl%^RESET%^%^ORANGE%^a%^BOLD%^zing "
       +"s%^RESET%^%^ORANGE%^u%^BOLD%^n%^WHITE%^.";
     return result;
     break;
   }
}



void do_bonuses(){
  switch(which){
  case WARRIOR:
    set_item_bonus("strength", 6);
    break;
  case ASSASSIN:
    set_item_bonus("stealth", 6);
    break;
  case CEREMONIAL:
    set_item_bonus("bonus_spell_slots",3);
    break;
  case TRACKER:
    set_item_bonus("dexterity", 6);
    break;
  case DIVINER:
    set_item_bonus("spellcraft", 6);
    break;
  }
}

int wear_func()
{
    string code1, code2;
    do_bonuses();
    code1 = COLOUR_CODES[col1];
    code2 = COLOUR_CODES[col2];
    tell_object(ETO, "You fasten the " + query_obvious_short() + "%^RESET%^ around your waist");
    if (objectp(EETO)) {
        tell_room(EETO, ETO->QCN + " fastens the " + query_obvious_short() + "%^RESET%^ around " + ETO->QP + " waist.", ETO);
    }
    return 1;
}

int remove_func() {
   string code1, code2;
   code1 = COLOUR_CODES[col1];
   code2 = COLOUR_CODES[col2];
   tell_object(ETO,"You unfasten the " + query_obvious_short() + "%^RESET%^ from around"
     +" your waist.");
   if (objectp(EETO)){
     tell_room(EETO, ETO->QCN + " unfastens the " + query_obvious_short() + "%^RESET%^"
      +" from around " + ETO->QP + " waist.", ETO );
   }
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
        tell_room(EETO, ETOQCN + "'s " + query_obvious_short() + "%^RESET%^ flickers, and " + ETO->QS + " becomes momentarily insubstantial, allowing " + who->QCN+" 's blow to pass right through " + ETO->QO, ({ETO, who}));

        tell_object(ETO, "Your "+ query_obvious_short() +"%^RESET%^ goes cold and you feel a strange shock as " + who->QCN + "'s attack passes right through, leaving you feeling weird but otherwise unharmed.");

        tell_object(who,  ETOQCN + "'s " + query_obvious_short() + "%^RESET%^ flickers, and " + ETO->QS + " becomes momentarily insubstantial, allowing your blow to pass right through " + ETO->QO);
        return 0;
    }
    return damage;
}
