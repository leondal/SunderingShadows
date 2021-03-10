//mask_celestia.c - special porcelain mask
//for new Seneca ~Circe~ 12/21/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("celestia mask");
   set_obvious_short("%^BOLD%^a white porcelain mask decorated with %^YELLOW%^gold%^RESET%^");
   set_short("%^BOLD%^%^WHITE%^Mask of %^RESET%^C%^BOLD%^e%^YELLOW%^"+
      "l%^WHITE%^e%^RESET%^s%^BOLD%^t%^YELLOW%^i%^WHITE%^a%^RESET%^");
   set_id(({"mask","porcelain mask","celestia mask","white porcelain mask","mask of celestia","Mask of Celestia"}));
   set_long("%^BOLD%^%^WHITE%^Flawless white porcelain molds "+
      "perfectly to the wearer's face, creating a wonderful "+
      "illusion.  The exquisitely formed lips are painted "+
      "a glistening %^YELLOW%^gold %^WHITE%^that matches the "+
      "delicate %^YELLOW%^metallic flowers %^WHITE%^and "+
      "%^YELLOW%^vines %^WHITE%^painted around the eye holes, "+
      "which have been decorated with thin, delicate %^RESET%^"+
      "lace%^BOLD%^.  %^YELLOW%^Gold braid%^WHITE%^ runs along "+
      "the outer edge of the mask, leading under the chin to the "+
      "decorative earrings dangling from the sides of the mask.  "+
      "Each is a collection of %^RESET%^p%^BOLD%^e%^RESET%^a"+
      "%^BOLD%^r%^RESET%^l %^BOLD%^s%^RESET%^t%^BOLD%^r%^RESET%^a"+
      "%^BOLD%^n%^RESET%^d%^BOLD%^s dangling from a %^YELLOW%^"+
      "golden orb%^WHITE%^, the tips of the earrings reaching the "+
      "wearer's shoulders.  A triangular cap of %^YELLOW%^gold "+
      "foil %^WHITE%^rests atop the mask's forehead, and thick "+
      "twin %^RESET%^%^ORANGE%^s%^BOLD%^p%^RESET%^%^ORANGE%^i"+
      "%^BOLD%^r%^RESET%^%^ORANGE%^a%^BOLD%^l%^RESET%^%^ORANGE%^"+
      "i%^BOLD%^n%^RESET%^%^ORANGE%^g %^BOLD%^ribbons %^WHITE%^"+
      "edged in thin %^RESET%^lace%^BOLD%^ climb to points above "+
      "the top of the mask.  Delicate %^YELLOW%^silk ribbons "+
      "%^WHITE%^are arranged in such a way as to make the mask "+
      "quite comfortable to wear.%^RESET%^");
   set_costume_type("%^BOLD%^%^WHITE%^white porcelain%^RESET%^");
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
      "sell her creations.  %^BOLD%^The Mask of Celestia, in "+
      "particular, is an artistic representation of Hannah's "+
      "vision of Celestia, the ordered, good-natured realm "+
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