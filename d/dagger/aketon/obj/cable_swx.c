#include "/d/dagger/aketon/short.h"

inherit OBJECT;

void create() {
   ::create();
   set_name("steel cable");
   set_id( ({"cable","blue cable","long cable"}) );
   set("short","%^RESET%^%^BLUE%^blue long cable");
   set("long","This cable is made of enchanted steel. It extends up to "
     "the huge tree towards the northeast. It is fixed in place on a large "
      "steel rack.");
   set_weight(10000);
   set_value(0);
   set_property("no animate",1);
}
