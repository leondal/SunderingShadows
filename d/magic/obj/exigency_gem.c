#include <std.h>

inherit OBJECT;

string name1;

void create(){
   ::create();
   set_name("");
   set_id(({"gem","crystal","exigency gem"}));
   set_short("a crystal");
   set_long("");
   set_weight(10);
   set_value(2500);
}

void setStuff(){
   if(!living(ETO)) return;
   name1 = ETO->query_race();
   TO->set_name("crystal of "+article(name1)+" "+name1);
   set_id( ({ }) );
   add_id("gem");
   add_id("gem of "+article(name1)+" "+name1);
   add_id("gem of "+capitalize(ETO->query_name()));
   add_id("exigency gem");

   set_short("%^YELLOW%^a gem attuned to "+article(name1)+" "+name1+"%^RESET%^");
   set_long("This is a small gem that sparkles in the light.  An "+
      "image carved within marks this gem as belonging to a "+
      "particular "+name1+".");
}

void init(){
   ::init();

      if(!stringp(name1)) setStuff();
}
