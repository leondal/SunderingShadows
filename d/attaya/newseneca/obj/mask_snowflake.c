//mask_snowflake.c - special porcelain mask
//for new Seneca ~Circe~ 12/22/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("snowflake mask");
   set_obvious_short("%^BOLD%^%^WHITE%^a s%^RESET%^i"+
      "%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r%^BOLD%^y "+
      "%^RESET%^w%^BOLD%^h%^RESET%^i%^BOLD%^t%^RESET%^e "+
      "%^BOLD%^eyemask%^RESET%^");
   set_short("%^BOLD%^%^WHITE%^S%^RESET%^n%^BOLD%^o%^CYAN%^w"+
      "%^WHITE%^f%^RESET%^l%^BOLD%^a%^CYAN%^k%^WHITE%^e "+
      "Eyemask%^RESET%^");
   set_id(({"mask","leather mask","snowflake mask","eyemask","snowflake eyemask","silvery white eyemask","white eyemask","leather eyemask","silvery white mask","white mask"}));
   set_long("%^BOLD%^%^WHITE%^Molded white leather has been cut into "+
      "this delicate eyemask that %^RESET%^g%^BOLD%^l"+
      "%^RESET%^i%^BOLD%^t%^RESET%^t%^BOLD%^e%^RESET%^r"+
      "%^BOLD%^s with %^RESET%^silver%^BOLD%^.  Crushed "+
      "d%^RESET%^i%^CYAN%^a%^RESET%^m%^BOLD%^o%^CYAN%^n"+
      "%^WHITE%^d%^RESET%^s %^BOLD%^have been arranged in "+
      "a snowflake pattern at the outer corner of each eye, "+
      "while a crown of %^RESET%^silver%^BOLD%^ graces the "+
      "upper portion of the mask.  A single curling "+
      "swan feather in purest white rises high overhead, "+
      "its downy edges dancing on the lightest breeze.  "+
      "Smaller feathers gather at the crown, their stems "+
      "tinged with %^RESET%^silver%^BOLD%^ that matches "+
      "the %^RESET%^r%^BOLD%^i%^RESET%^b%^BOLD%^b%^RESET%^o"+
      "%^BOLD%^n%^RESET%^s %^BOLD%^that secure the mask in "+
      "place.%^RESET%^");
   set_costume_type("%^BOLD%^%^WHITE%^a s%^RESET%^i"+
      "%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r%^BOLD%^y "+
      "%^RESET%^w%^BOLD%^h%^RESET%^i%^BOLD%^t%^RESET%^e");
   set_costume("eyemask");
   set_value(750);
   set_limbs(({"head"}));
   set_lore("This mask seems to have been made by Hannah Lycinthe, "+
      "costume maker for the Bard Academy in Seneca.  Hannah's "+
      "fascination with costumes began when she was a child.  "+
      "Despite growing up in a city that was constantly under "+
      "siege, Hannah had a strong imagination and would gather "+
      "scraps of fabric to create unique clothing for her dolls - "+
      "which, in turn, were cloth creations she made herself.  "+
      "As time passed and Seneca gained prosperity, Hannah "+
      "began to make costumes for actors, in particular "+
      "Malachai Freeman, who helped found the Bard Academy.");
   set_property("lore difficulty",17);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}

int isMagic(){
   int magicmask;
   magicmask = ::isMagic();
   magicmask = magicmask+1;
   return magicmask;
}