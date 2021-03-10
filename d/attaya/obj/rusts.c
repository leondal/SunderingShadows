#include <std.h>
inherit "/d/common/obj/armour/shield.c";

void create() {
    ::create();
    set_name("rusting shield");
    set("id", ({ "shield","rusting shield", "rust" }) );
    set_short("%^RESET%^%^RED%^r%^ORANGE%^u%^RED%^st%^ORANGE%^y %^RED%^sh%^ORANGE%^ie%^RED%^ld%^RESET%^");
    set_long(
      "It is an old circular shield coated with rust.  It is still quite effective at blocking attacks, though."
    );
    set_limbs( ({ "right hand" }) );
}
