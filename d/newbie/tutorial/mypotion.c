#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("brilliant blue vial");
   set_short("A kit of brilliant blue healing vials (newbie) [1 left]");
   set_id(({"brilliant blue","vial","potion","kit","kitabc","blue","newbvial"}));
   set_long("%^BOLD%^%^BLUE%^The brilliant blue liquid contained in this kit's vials is smooth but bitter."
"  \n\t%^RESET%^%^ORANGE%^The case can hold many vials, each one slipping into a pocket where tubes poke "
"through valved holes in the cork.  The tubes from each vial are connected to a central one, allowing the "
"user to quickly <quaff> or <drink> several doses by tipping it up or simply sucking the liquid through "
"the central tube.  There seems to be a small flapper inside the drinking tube that prevents the potion "
"from seeping out but gives way under suction or when held for drinking.  You will find the case itself "
"will vaporize if all the vials are emptied.\n%^RESET%^(A newbie-only kit)\t[1 left]");
   set_weight(0);
   set_value(0);
}

void save_me(string file) { return 1; }