#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   "/d/attaya/newseneca/obj/valuables_base.c"->create_valuables(TO);
   set_long(""+TO->query_long()+"  %^RESET%^%^CYAN%^Some sort of %^BOLD%^m"+
      "ag%^WHITE%^i%^CYAN%^cal a%^BLACK%^u%^CYAN%^ra %^RESET%^%^CYAN%^"+
      "seems to radiate outward from this particular object, drawing "+
      "your eye.%^RESET%^");
}

void init(){
   ::init();
   add_action("break_em","break");
}

int break_em(string str){
   if(!str){
      tell_object(TP,"Break what?");
      return 1;
   }
   if(!id(str)) return 0;
   tell_object(TP,"%^BOLD%^%^MAGENTA%^As you break the "+str+", you "+
      "feel a pulse of power explode from its core.%^RESET%^");
   tell_room(ETP,"%^BOLD%^%^MAGENTA%^As "+TPQCN+" breaks the "+str+", "+
      "a pulse of power explodes from its core.%^RESET%^",TP);
   TO->set_value(0);
   TO->set_short(::query_short()+" %^BOLD%^%^WHITE%^(%^RED%^broken%^WHITE%^)%^RESET%^");
   TO->set_long(::query_long()+"  %^BOLD%^%^RED%^Unfortunately, this particular item is now broken and probably would be worthless.%^RESET%^");
   return 1;
}