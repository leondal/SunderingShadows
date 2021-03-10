#include <std.h>
inherit "/std/obj/fence_store_mid";

void reset() {
   object ob;
   ::reset();
   if(!present("dark lantern")) new("/d/common/obj/misc/darkbeacon.c")->move(TO);
   if(!present("smokebomb")) {
     ob = new("/d/tharis/obj/smokebomb");
     ob->move(TO);
     ob->set_origin("juran");
   }
}
