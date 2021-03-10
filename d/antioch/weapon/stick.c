//  Created by Ignatius, for ShadowGate
//  Coded 25 June, 1995
//  Just a lowly little stick

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit "/std/weapon";

create() {
    ::create();
  set_id(({ "stick", "short stick" }));
   set_name("stick");
   set_short("A short stick");
   set_long(
       "This is a stick, pointy on one end and about two feet long.\n"
   );
   set_weight(3);
   set_size(1);
   set_wc(1,4);
   set_type("bludgeoning");
}
