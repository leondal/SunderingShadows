//mask_jester.c - special porcelain mask
//for new Seneca ~Circe~ 12/22/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("jester mask");
   set_obvious_short("%^BOLD%^%^BLUE%^a t%^YELLOW%^r%^RED%^i"+
      "%^BLUE%^-%^YELLOW%^c%^RED%^o%^BLUE%^l%^YELLOW%^o%^RED%^r "+
      "%^BLUE%^eyemask%^RESET%^");
   set_short("%^BOLD%^%^BLUE%^Mask of the %^YELLOW%^J%^RED%^e"+
      "%^BLUE%^s%^YELLOW%^t%^RED%^e%^BLUE%^r%^RESET%^");
   set_id(({"mask","jester mask","eyemask","jester eyemask","tri-color mask","tri-color eyemask","mask of the jester","Mask of the Jester"}));
   set_long("%^RESET%^%^BLUE%^A molded leather eyemask painted "+
      "%^BOLD%^brilliant blue %^RESET%^%^BLUE%^makes up the "+
      "base for this creation.  The %^BOLD%^blue %^RESET%^"+
      "%^BLUE%^lightens to vibrant %^YELLOW%^yellow %^RESET%^"+
      "%^BLUE%^near the center of the mask along the bridge of "+
      "the nose, and %^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^l"+
      "%^RESET%^%^ORANGE%^d%^BOLD%^e%^RESET%^%^ORANGE%^n "+
      "%^BOLD%^s%^RESET%^%^ORANGE%^c%^BOLD%^r%^RESET%^%^ORANGE%^o"+
      "%^BOLD%^l%^RESET%^%^ORANGE%^l%^BOLD%^w%^RESET%^%^ORANGE%^o"+
      "%^BOLD%^r%^RESET%^%^ORANGE%^k %^BLUE%^spirals along "+
      "the face, their edges touching the %^YELLOW%^gold braid "+
      "%^RESET%^%^BLUE%^that bounds the mask.  Curling %^BOLD%^"+
      "velvet plumes %^RESET%^%^BLUE%^in %^BOLD%^%^RED%^red "+
      "%^RESET%^%^BLUE%^and %^BOLD%^blue %^RESET%^%^BLUE%^edged "+
      "in %^YELLOW%^gold %^RESET%^%^BLUE%^rise from the crown of "+
      "the mask, each of their tips ending in a tiny %^YELLOW%^"+
      "golden bell%^RESET%^%^BLUE%^.  %^BOLD%^Silken ribbons "+
      "%^RESET%^%^BLUE%^are attached at each corner of the mask "+
      "and may be tied around the head to secure it.%^RESET%^");
   set_costume_type("%^BOLD%^%^BLUE%^t%^YELLOW%^r%^RED%^i"+
      "%^BLUE%^-%^YELLOW%^c%^RED%^o%^BLUE%^l%^YELLOW%^o%^RED%^r");
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