#include <std.h>

inherit OBJECT;

void create() {
  ::create();
    set_name("monolith");
    set_id( ({ "monolith" }) );
    set_short("%^BOLD%^%^RED%^A magnificent monolith");
    set_long("%^BOLD%^%^RED%^This monolith is tremendous in size and "
"dominates the room.  It nearly covers the whole rear wall of the temple "
"behind the altar.  It is carved from a single flamedance stone and the "
"craftsmanship is spectacular.  The carving is such that it appears to be "
"a flame that f%^YELLOW%^l%^RED%^ic%^YELLOW%^k%^RED%^er%^YELLOW%^s %^RED%^"
"as you walk around it.  Engraved into a part of this "
"monolith is Kossuth's charge followed below that with the initials "
"%^YELLOW%^LD%^RESET%^.");
    set_weight(10000);
    set_property("no animate", 1);
    set_value(10000);
    set_cointype("gold");
}
