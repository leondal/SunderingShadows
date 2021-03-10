#include <std.h>
inherit "/d/deku/armours/cloak_inh.c";
 
create() {
  ::create();
    set_name("cloak");
    set_id(( {"cloak", "gray cloak","shawl"}));
    set_short("Shawl of indifference");
    set_obvious_short("A gray leather cloak");
    set_long("This is a long leather cloak with a hood.  "+
    "It is surprisingly clean and has been dyed a dull "+
    "gray color.  It has been made from soft, supple leather "+
    "that would probably provide some protection.  It closes "+
    "around the wearer's neck with a dull %^BOLD%^%^WHITE%^"+
    "silver%^RESET%^ clasp. ");
    set_wear("%^BOLD%^%^WHITE%^You feel protected as you "+
    "don the cloak.%^RESET%^");
    set_remove("%^BOLD%^%^WHITE%^You feel the strange "+
    "protection leave you as you remove the cloak.%^RESET%^");
}
