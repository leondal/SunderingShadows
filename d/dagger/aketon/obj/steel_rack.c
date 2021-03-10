#include "/d/dagger/aketon/short.h"

inherit OBJECT;

void create() {
   ::create();
   set_name("steel rack");
   set_id( ({"rack","cable rack"}) );
   set("short","Steel rack");
   set("long","A large rack made of steel. It is fixed in place by some "
      "thick nails. Four long cables are mounted on it extending into "
      "four different directions.");
   set_weight(10000);
   set_value(0);
   set_property("no animate",1);
}
