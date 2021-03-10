#include <std.h>
inherit "/d/common/obj/weapon/rapier";

void create(){
    ::create();
    set("value", 150);
    set_name("Triceratops horn");
    set_short("Triceratops horn");
    set_id( ({"horn", "tricera horn", "triceratops horn"}) );
    set_long(
      "This horn once belonged to a Triceratops, helping protect it against its foes.  Now its point serves as a weapon to those in need.  Enchanted by unknown methods, this horn could be a lethal weapon."
    );
    set_property("enchantment", 1);
}
