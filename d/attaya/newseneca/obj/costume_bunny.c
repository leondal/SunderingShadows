//costume_bunny.c - Bunny costume for new Seneca
//~Circe~ 12/19/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("bunny costume");
   set_id(({"costume","bunny costume","Bunny Costume","cute bunny costume"}));
   set_short("%^BOLD%^%^WHITE%^cute bunny costume%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Made from real fur, this cute "+
      "bunny costume features huge bunny feet and gloves that "+
      "cover the wearer's hands.  Rather than a mask, a headpiece "+
      "fashioned from hardened %^RESET%^%^ORANGE%^leather %^BOLD%^"+
      "%^WHITE%^covered with fur is provided, with eyeslits cut "+
      "through the large, round %^BLACK%^eyes%^WHITE%^ placed just "+
      "above a wiggly triangular %^MAGENTA%^nose%^WHITE%^.  "+
      "Two tall ears lined with %^MAGENTA%^pink felt %^WHITE%^"+
      "top the head, while a large oval "+
      "across the tummy has been lined with matching%^MAGENTA%^ "+
      "felt %^WHITE%^as well.  A little "+
      "%^RESET%^puffball tail %^BOLD%^made of fluffy white "+
      "cotton has been attached to the rear, helping hide "+
      "the flap which lets one into this costume.  The slit "+
      "through the back has ties which are hidden in the fur, "+
      "letting an actor quickly slip into or out of this costume.%^RESET%^");
   set_costume_type("%^BOLD%^%^WHITE%^cute bunny%^RESET%^");
   set_costume("costume");
   set_value(400);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}