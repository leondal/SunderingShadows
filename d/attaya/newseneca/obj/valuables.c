#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   "/d/attaya/newseneca/obj/valuables_base.c"->create_valuables(TO);
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
   tell_object(TP,"You break the "+str+", rendering it worthless.");
   tell_room(ETP,""+TPQCN+" breaks the "+str+".",TP);
   TO->set_value(0);
   TO->set_short(::query_short()+" %^BOLD%^%^WHITE%^(%^RED%^broken%^WHITE%^)%^RESET%^");
   TO->set_long(::query_long()+"  %^BOLD%^%^RED%^Unfortunately, this particular item is now broken and probably would be worthless.%^RESET%^");
   return 1;
}