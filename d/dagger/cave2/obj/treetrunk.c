#include <std.h>

inherit "std/weapon";

void create() {
    ::create();
    set_name("treetrunk");
    set_id( ({"tree", "club", "treetrunk"}) );
    set_short("a club made from a tree");
    set_long("This is a club crudely fashioned from a tree.  It is quite large and heavy.  Most of the limbs have been cut off and the roots have been pulled off, but some metal spikes have been hammered through the one end.");
    set_weight(30);
    set_value(2);
     set_wc(1,11);
     set_large_wc(1,19);
    set_size(4);
    set_type("bludgeoning");
    set_prof_type("giant clublike");
}