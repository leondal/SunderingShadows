//mask_flames.c - special porcelain mask
//for new Seneca ~Circe~ 12/22/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("flames mask");
   set_obvious_short("%^RESET%^%^RED%^a f%^BOLD%^i%^YELLOW%^"+
      "e%^RED%^r%^RESET%^%^RED%^y red porcelain mask%^RESET%^");
   set_short("%^BOLD%^%^RED%^Mask of %^RESET%^%^RED%^F%^BOLD%^l"+
      "%^YELLOW%^am%^RED%^e%^RESET%^%^RED%^s%^RESET%^");
   set_id(({"mask","porcelain mask","flames mask","mask","mask of flames","Mask of Flames","fiery red mask","red mask","fiery red porcelain mask"}));
   set_long("%^RESET%^%^RED%^Glistening s%^BOLD%^c%^RESET%^"+
      "%^RED%^a%^BOLD%^r%^RESET%^%^RED%^l%^BOLD%^e%^RESET%^"+
      "%^RED%^t porcelain forms the base of this mask.  "+
      "%^YELLOW%^G%^RESET%^%^ORANGE%^i%^BOLD%^l%^RESET%^"+
      "%^ORANGE%^d%^BOLD%^e%^RESET%^%^ORANGE%^d feathers "+
      "%^RED%^are arranged around the eyes, their forms "+
      "painted in %^YELLOW%^golds %^RESET%^%^RED%^and "+
      "%^BOLD%^reds%^RESET%^%^RED%^ in imitation of f"+
      "%^BOLD%^l%^YELLOW%^am%^RED%^e%^RESET%^%^RED%^s.  "+
      "Dangling from either side of the mask are long "+
      "%^YELLOW%^b%^RESET%^%^ORANGE%^e%^RED%^a%^BOLD%^d"+
      "%^YELLOW%^e%^RESET%^%^ORANGE%^d %^RED%^decorations "+
      "that jingle lightly with movement, while matching "+
      "%^YELLOW%^b%^RESET%^%^ORANGE%^e%^RED%^a%^BOLD%^d"+
      "%^YELLOW%^s %^RESET%^%^RED%^form a %^BOLD%^fiery image "+
      "%^RESET%^%^RED%^on the forehead of the mask just "+
      "beneath the elaborate %^BOLD%^plume %^RESET%^"+
      "%^RED%^rising overhead.  A stylized representation "+
      "of a %^BOLD%^flame%^RESET%^%^RED%^ has been crafted "+
      "from reinforced %^BOLD%^red silk %^RESET%^%^RED%^"+
      "edged with %^YELLOW%^golden glitter%^RESET%^%^RED%^ "+
      "and decorated with colored f%^BOLD%^e%^RESET%^%^ORANGE%^"+
      "a%^YELLOW%^t%^RED%^h%^RESET%^%^RED%^e%^ORANGE%^r%^BOLD%^"+
      "%^RED%^s%^RESET%^%^RED%^, making the mask look as if it "+
      "were a%^BOLD%^f%^YELLOW%^la%^RED%^m%^RESET%^%^RED%^e.  "+
      "%^BOLD%^Silken ribbons %^RESET%^%^RED%^tied to each "+
      "side provide security for the mask.%^RESET%^");
   set_costume_type("%^RESET%^%^RED%^a f%^BOLD%^i%^YELLOW%^"+
      "e%^RED%^r%^RESET%^%^RED%^y red");
   set_costume("mask");
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