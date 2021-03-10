#include <std.h>
inherit "/d/common/obj/weapon/dagger";

void create(){
    ::create();
    set_name("tyranosaurus tooth");
    set_id( ({"tooth", "tyrano tooth", "tyranosaurus tooth","dagger"}) );
    set_short("tyranosaurus tooth");
    set_long(
      "This long tooth was pulled from the skull of a dead Tyrannosaurus.  Enchanted by unknown means, this is a common weapon on Dinosaur Island."
    );
    set_size(1);
    set_weight(9);
    set("value", 100);
    set_wc(1,6);
    set_large_wc(1,9);
    set_property("enchantment", 1);
    set_type("piercing");
}
