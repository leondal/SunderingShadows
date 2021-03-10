//mask_baator.c - special porcelain mask
//for new Seneca ~Circe~ 12/22/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("baator mask");
   set_obvious_short("%^RESET%^%^RED%^a blood-red porcelain "+
      "mask tinged with %^BOLD%^%^BLACK%^black%^RESET%^");
   set_short("%^RESET%^%^RED%^Mask of %^BOLD%^%^BLACK%^B"+
      "%^RESET%^%^RED%^a%^BOLD%^at%^RESET%^%^RED%^o%^BOLD%^"+
      "%^BLACK%^r%^RESET%^");
   set_id(({"mask","porcelain mask","baator mask","red porcelain mask","mask of baator","Mask of Baator","blood-red mask"}));
   set_long("%^RESET%^%^RED%^Red matte porcelain is sculpted "+
      "into this disturbing visage.  %^BOLD%^%^BLACK%^Horns "+
      "%^RESET%^%^RED%^made of %^BOLD%^%^BLACK%^r%^RESET%^i"+
      "%^BOLD%^%^BLACK%^b%^RESET%^b%^BOLD%^%^BLACK%^o%^RESET%^"+
      "n%^BOLD%^%^BLACK%^s %^RESET%^%^RED%^spiral upwards, "+
      "ending in %^BOLD%^red tips%^RESET%^%^RED%^ that seem "+
      "to be dripping %^BOLD%^blood%^RESET%^%^RED%^.  The "+
      "eyes are wide and glaring, rimmed in %^BOLD%^%^BLACK%^"+
      "ebony%^RESET%^%^RED%^.  The mouth is created gaping with "+
      "%^BOLD%^%^BLACK%^pointed black fangs %^RESET%^%^RED%^"+
      "tinged %^BOLD%^scarlet%^RESET%^%^RED%^, creating an "+
      "image of a blood-thirsty %^BOLD%^devil%^RESET%^%^RED%^.  "+
      "The edges of the mask are bristling with tiny %^BOLD%^"+
      "%^BLACK%^thorns%^RESET%^%^RED%^, making it treacherous.  "+
      "Completing the mask are a series of silk ribbons "+
      "attached at the sides that allow it to be secured.%^RESET%^");
   set_costume_type("%^RESET%^%^RED%^blood-red porcelain");
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
      "sell her creations.  %^BOLD%^The Mask of Baator, in "+
      "particular, is an artistic representation of Hannah's "+
      "vision of the baator, the ordered fiendish realm "+
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