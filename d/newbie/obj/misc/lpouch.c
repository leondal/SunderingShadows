#include <std.h>
#include <move.h>
inherit PARMOUR;
object ob;

void create(){
   ::create();
   set_name("leather pouch");
   set_short("%^RESET%^%^ORANGE%^A small leather pouch%^RESET%^");
   set_id(({"leather pouch","pouch"}));
   set_long("%^RESET%^%^ORANGE%^This is a small little leather pouch that is supported about ones waist by a matching leather thong.  Once new, this pouch is now worn and supple from years of use.  It is not very large, but is probably good for storing a few small things.%^RESET%^\n");

   set_weight(3);
   set_type("clothing");
   set_limbs(({"waist"}));
   set_value(10);
   set_max_internal_encumbrance(10);
/*
      switch(random(4)){
         case 0:
         ob = new("/std/obj/coins");
         ob->set_money("gold", random(200)+50);
         ob->move(TO);
         break;
         case 1:
         new("/d/newbie/rooms/keep/obj/gem.c")->move(TO);
         new("/d/newbie/rooms/keep/obj/gem.c")->move(TO);
         case 2:
         new("/d/newbie/rooms/keep/obj/gem.c")->move(TO);
         new("/d/newbie/rooms/keep/obj/gem.c")->move(TO);
         case 3:
         new("/d/newbie/rooms/keep/obj/gem.c")->move(TO);
         break;
         default: break;
      gems = 1;
      return 1;
      }
I took this out as it was continually producing gems when people logged in, giving them endless money and causing things to fall out of the pouch.  I'll try to track down the mobs that use it to add gems to them specifically.  Circe 7/29/04
*/
}

int query_size(){
   if(!userp(ETO)) return 2;
   return ETO->query_size();
}
