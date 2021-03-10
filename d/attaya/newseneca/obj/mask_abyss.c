//mask_abyss.c - special porcelain mask
//for new Seneca ~Circe~ 12/21/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("abyss mask");
   set_obvious_short("%^BOLD%^%^BLACK%^a black porcelain mask with "+
      "%^RED%^red%^BLACK%^ and %^YELLOW%^gold %^BLACK%^hues%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Mask of the %^RED%^A%^RESET%^%^RED%^"+
      "b%^BOLD%^%^BLACK%^y%^RESET%^%^RED%^s%^BOLD%^s%^RESET%^");
   set_id(({"mask","porcelain mask","abyss mask","black porcelain mask","mask of the abyss","Mask of the Abyss","red and gold mask"}));
   set_long("%^BOLD%^%^BLACK%^Crafted from black porcelain, this "+
      "mask features jagged edges and wicked points that bring "+
      "to mind images of horror.  The eyes are cut narrowly, "+
      "overshadowed by the band of %^RED%^red %^BLACK%^tinged "+
      "with %^YELLOW%^gold%^BLACK%^ that encircles the forehead.  "+
      "The mouth and nose are elongated, rather like a demonic "+
      "%^RED%^beak%^BLACK%^, their center left gaping open in a "+
      "shape much like a twisted %^RED%^heart%^BLACK%^.  Enameled "+
      "%^RED%^red %^BLACK%^streaks down the %^YELLOW%^golden "+
      "cheeks %^BLACK%^like so many tears while an elaborate "+
      "crest of b%^RED%^l%^BLACK%^a%^RESET%^%^RED%^c%^BOLD%^k "+
      "%^BLACK%^a%^RED%^n%^RESET%^%^RED%^d %^BOLD%^r%^BLACK%^e"+
      "%^RESET%^%^RED%^d f%^BOLD%^e%^BLACK%^a%^RED%^t%^RESET%^"+
      "%^RED%^h%^BOLD%^%^BLACK%^e%^RED%^r%^RESET%^%^RED%^s "+
      "%^BOLD%^%^BLACK%^claws its way from the top of the mask.  "+
      "S%^RESET%^i%^BOLD%^%^BLACK%^l%^RESET%^k %^BOLD%^%^BLACK%^r"+
      "%^RESET%^i%^BOLD%^%^BLACK%^b%^RESET%^b%^BOLD%^%^BLACK%^o"+
      "%^RESET%^n%^BOLD%^%^BLACK%^s black as the %^RESET%^abyss "+
      "%^BOLD%^%^BLACK%^are attached to the sides of the mask, "+
      "allowing it to be tied on securely.%^RESET%^");
   set_costume_type("%^BOLD%^%^BLACK%^black porcelain");
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
      "sell her creations.  %^BOLD%^The Mask of the Abyss, in "+
      "particular, is an artistic representation of Hannah's "+
      "vision of the abyss, the chaotic cut-throat realm "+
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