//costume_lion.c - Lion costume for new Seneca
//~Circe~ 12/22/07
#include <std.h>
#include "../seneca.h"

inherit COSTUME;

void create(){
   ::create();
   set_name("lion costume");
   set_id(({"costume","lion costume","Lion Costume","majestic lion costume"}));
   set_short("%^RESET%^%^ORANGE%^majestic%^BOLD%^ lion%^RESET%^%^ORANGE%^ costume%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^A one-piece jumpsuit crafted from "+
      "tawny plush cotton covers the wearer's entire body except "+
      "for the head and hands.  The %^BOLD%^%^WHITE%^feet "+
      "%^RESET%^%^ORANGE%^are stuffed and tipped "+
      "with %^BOLD%^%^WHITE%^white claws%^RESET%^%^ORANGE%^, "+
      "while the attached %^YELLOW%^tail%^RESET%^%^ORANGE%^ "+
      "ends with a %^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^l"+
      "%^RESET%^%^ORANGE%^d%^BOLD%^e%^RESET%^%^ORANGE%^n "+
      "tuft.  A plush headpiece with a %^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^l"+
      "%^RESET%^%^ORANGE%^d%^BOLD%^e%^RESET%^%^ORANGE%^n "+
      "%^BOLD%^mane%^RESET%^%^ORANGE%^ helps complete the "+
      "illusion, along with the tawny facepaint provided.%^RESET%^");
   set_costume_type("%^RESET%^%^ORANGE%^majestic%^BOLD%^ lion");
   set_costume("costume");
   set_value(400);
   set_weight(5);
   if(!random(4)){
      set_size(random(3)+1);
   }else{
      set_size(2);
   }
}