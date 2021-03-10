//mask_arborea.c - special porcelain mask
//for new Seneca ~Circe~ 12/21/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("arborea mask");
   set_obvious_short("%^RESET%^%^ORANGE%^a bronze porcelain half-mask "+
      "with the colors of the %^GREEN%^f%^BOLD%^o%^RESET%^"+
      "%^ORANGE%^r%^GREEN%^e%^BOLD%^s%^RESET%^%^GREEN%^t%^RESET%^");
   set_short("%^RESET%^%^ORANGE%^Mask of %^GREEN%^A%^BOLD%^r%^RESET%^"+
      "%^GREEN%^b%^ORANGE%^o%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^a%^RESET%^");
   set_id(({"mask","porcelain mask","arborea mask","bronze porcelain mask","mask of arborea","Mask of Arborea","forest mask","half-mask","porcelain half-mask"}));
   set_long("%^RESET%^%^ORANGE%^Smooth porcelain painted a warm "+
      "bronze makes up this half-mask.  Light %^YELLOW%^g%^RESET%^"+
      "%^ORANGE%^o%^BOLD%^l%^RESET%^%^ORANGE%^d%^BOLD%^e%^RESET%^"+
      "%^ORANGE%^n %^BOLD%^b%^RESET%^%^ORANGE%^e%^BOLD%^a%^RESET%^"+
      "%^ORANGE%^d%^BOLD%^i%^RESET%^%^ORANGE%^n%^BOLD%^g %^RESET%^"+
      "%^ORANGE%^ runs around the edges of the mask, decorating "+
      "the cheeks and eye holes.  An elaborate decoration rises "+
      "above the mask, layers of %^GREEN%^green silk %^ORANGE%^"+
      "arranged in an arched crest five inches tall.  Strands of "+
      "%^WHITE%^m%^BOLD%^e%^RESET%^t%^BOLD%^a%^RESET%^l%^BOLD%^l"+
      "%^RESET%^i%^BOLD%^c %^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v"+
      "%^RESET%^e%^BOLD%^r %^RESET%^r%^BOLD%^i%^RESET%^b%^BOLD%^b"+
      "%^RESET%^o%^BOLD%^n %^RESET%^%^ORANGE%^line the %^GREEN%^"+
      "green crest%^ORANGE%^, forming concentric arches that "+
      "disappear beneath a fanciful %^GREEN%^f%^BOLD%^o%^RESET%^"+
      "%^GREEN%^r%^ORANGE%^e%^GREEN%^s%^BOLD%^t %^RESET%^%^ORANGE%^"+
      "of %^GREEN%^foil leaves%^ORANGE%^ while the %^GREEN%^"+
      "darker green silk %^ORANGE%^curves around, forming a "+
      "hooded covering for the back of the wearer's head.  "+
      "Decorative tassles made of looped %^GREEN%^b%^BOLD%^e"+
      "%^RESET%^%^ORANGE%^a%^YELLOW%^d%^GREEN%^e%^RESET%^%^GREEN%^"+
      "d strands %^ORANGE%^dangle from the sides of the mask, "+
      "partially covering the %^GREEN%^silk ribbons %^ORANGE%^"+
      "used to secure it.%^RESET%^");
   set_costume_type("%^RESET%^%^ORANGE%^bronze porcelain");
   set_costume("mask");
   set_value(750);
   set_limbs(({"head"}));
   set_lore("The specific construction of the mask and the placement "+
      "of the ribbons suggest that it was crafted by Hannah Lycinthe, "+
      "a costume designer of renown based out of Seneca.  Hannah "+
      "creates costumes and masks of all sorts, and she is widely "+
      "known to place minor wardings upon her more expensive creations, "+
      "helping them to resist - thought not avoid - breaking.  "+
      "She began her career working with a struggling actor named "+
      "Malachai Freeman, and the two experienced many lean years "+
      "while Malachai tried to find work in war-torn Seneca.  "+
      "As the time of prosperity finally began to dawn, Malachai "+
      "- and consequently Hannah - found himself in more demand.  "+
      "Eventually, he became one of the founding members of the "+
      "Seneca Bard Academy, and he rewarded Hannah for her loyalty "+
      "and efforts by gifting her with her own shop to display and "+
      "sell her creations.  %^BOLD%^The Mask of Arborea, in "+
      "particular, is an artistic representation of Hannah's "+
      "vision of Arborea, the free-spirited, good-natured realm "+
      "thought to exist beyond this one.%^RESET%^");
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