//costume_knight.c - knight costume for new Seneca
//~Circe~ 12/28/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("knight costume");
   set_id(({"costume","knight costume","Knight Costume","gallant knight costume"}));
   set_short("%^RESET%^%^RED%^gallant %^BOLD%^%^BLACK%^knight "+
      "%^RESET%^%^RED%^costume%^RESET%^");
   set_long("This costume features a %^RED%^red tunic %^RESET%^"+
      "with a %^BOLD%^cross %^RESET%^stitched onto the chest.  "+
      "The tunic has %^BOLD%^%^BLACK%^black sleeves %^RESET%^"+
      "and a %^BOLD%^silver belt %^RESET%^made to look like "+
      "chainmail.  A similar %^BOLD%^silver cloak %^RESET%^"+
      "fits as a coif and flows down the wearer's back.  "+
      "Fitted %^BOLD%^%^BLACK%^black pants %^RESET%^sewn "+
      "into %^BOLD%^silver %^RESET%^'chainmail' toppers that "+
      "begin at the knee complete the look.");
   set_costume_type("%^RESET%^%^RED%^gallant knight");
   set_costume("costume");
   set_value(400);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}