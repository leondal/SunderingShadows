#include <std.h>
#include "/d/dagger/drow/short.h"
inherit "/std/vendor";
void create() {
    :: create();
    set_name("slythssz");
    set_id(({
      "elite","drow","merchant","slythssz","drow merchant"
      }));
    set_short("%^RESET%^%^RED%^Slythssz, the Drow Merchant%^RESET%^");
    set_long("He buys and sells goods for adventuring.\n"+
             "<help shop> will get you a list of shop commands.\n"
    );
    set_gender("male");
   set_race("drow");
    set_hd(16,5);
    set_size(2);
    set_languages( ({ "common" }) );
    set_storage_room("/d/dagger/drow/storage.c");
    set_property("no bump",1);
    set_property("no attack",1);
    set_body_type("human");
    set_alignment(9);

   set_exp(10);
}
