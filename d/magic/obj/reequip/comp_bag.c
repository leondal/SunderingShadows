#include <std.h>
inherit "/d/magic/comp_bag";

void create() {
   ::create();
   set_id(({"bag","leather bag", "components bag", "compx"}));
   set_long("This is a very small leather bag.  It is only in this bag that you store the material components "
"for casting your spells.  Only the bare minimum of components are within, as it is a temporary bag only.  You "
"are unable to add or remove components to this bag.\n\n"
"     To check what is in the bag type <components>.\n");
}

int produce(string str) {
        if(!str) return notify_fail("Produce what?\n");
        tell_object(TP,"This is only a temporary bag, you cannot take components out of it!");
        return 1;
}

int query_value(){ return 0; }