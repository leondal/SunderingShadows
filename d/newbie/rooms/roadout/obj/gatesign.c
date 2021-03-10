#include <std.h>
inherit OBJECT ;

void create() {
  ::create();
  set_property("no offer", 1);
  set_weight(1000);
   set_long("This is a very important looking sign hanging on the gate.  You should definitely read it.");
   set_short("A sign hanging on the gate");
   set_name("Sign");
   set_id(({ "gate sign", "sign", "sign on the gate", "sign on gate" }));
}
