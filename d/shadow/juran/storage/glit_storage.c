#include <std.h>

inherit "/std/obj/fence_store_int";

void create(){
        object ob;
        ::reset();

    if(!present("smokebomb")) {
      ob = new("/d/tharis/obj/smokebomb");
      ob->move(TO);
      ob->set_origin("tharis");
    }
}
