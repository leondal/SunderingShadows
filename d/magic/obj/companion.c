#include <std.h>
inherit "/d/magic/obj/basemonster";

create() {
   ::create();
   set_name("companion");
   set_id(({"companion"}));
   set_short("a summoned companion");
   set_long("This is a generic companion for mage summoning.%^RESET%^");
}