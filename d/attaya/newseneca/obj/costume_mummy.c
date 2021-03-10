//costume_mummy.c - mummy costume for new Seneca
//~Circe~ 12/29/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
string gender;
   ::create();
   set_name("mummy costume");
   set_id(({"costume","mummy costume","Mummy Costume","eerie mummy costume"}));
   set_short("%^BOLD%^%^WHITE%^eerie %^RESET%^%^ORANGE%^mummy "+
      "%^BOLD%^%^WHITE%^costume%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This two-piece costume is made "+
      "from a base of an off-white cotton tunic and trousers "+
      "topped by a hood that covers the wearer's face and head.  "+
      "Strips of ragged bandages are sewn onto the fabric, "+
      "some of the tails allowed to flow freely while others "+
      "spiral around the wearer's body.  The mask has holes cut "+
      "out for the mouth, nose, and eyes, all cleverly hidden "+
      "by well-placed bandages.  The costume includes a pair of "+
      "bandage-wrapped shoes to mask the actor's feet, completing "+
      "this spooky illusion.%^RESET%^");
   set_costume_type("%^BOLD%^%^WHITE%^spooky mummy");
   set_costume("costume");
   set_value(300);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}