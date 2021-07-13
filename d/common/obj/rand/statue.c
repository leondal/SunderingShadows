//
#include <std.h>

inherit OBJECT;

string name1;

void create(){
   ::create();
   set_name("");
   set_id(({"statue"}));
   set_short("");
   set_long("");
   set_weight(5);
   set_value(2500);
}

void setStuff(){
   if(!living(ETO)) return;
   name1 = ETO->query_race();
   TO->set_name("statue of "+article(name1)+" "+name1);
   set_id( ({ }) );
   add_id("statue");
   add_id("statue of "+article(name1)+" "+name1);
   add_id("statue of "+capitalize(ETO->query_name()));
}

void init(){
   ::init();

      if(!stringp(name1)) setStuff();
}
