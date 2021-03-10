#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_name("A rugged wooden sign");
   set_short("%^RESET%^%^ORANGE%^A rugged wooden sign%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This rough wooden sign has been hammered into the stone wall to keep it in place.  Some "
"messy %^RESET%^writing %^ORANGE%^is scrawled upon it for you to read.%^RESET%^");
   set_id(({"sign","wooden sign","rugged sign","area sign","rugged wooden sign"}));
   set_weight(10000);
   set("read",(:"sign_read":));
   set_property("no animate",1);
}

int sign_read(string str){
   if(id(str)) {
     tell_object(TP,"%^BOLD%^%^WHITE%^Beware ye who travel below! Death awaits!%^RESET%^");
     if(!TP->query_invis()) tell_room(ETP,""+TPQCN+" seems to be studying the sign.",TP);
     return 1;   
   }
   return 0;
}
