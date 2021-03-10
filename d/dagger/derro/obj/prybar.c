//Adjusting this to not be a weapon ~Circe~ 7/30/19

#include <std.h>
inherit OBJECT;

void create(){
   ::create();
   set_id(({"bar","pry bar","prybar","metal bar"}));
   set_name("prybar");
   set_short("metal bar");
   set_long("This metal bar is about three feet long and bent to an angle on one end while being flattened on the other.  Looks like it could be useful somewhere.");
   set_weight(5);
   set_value(1);
}
