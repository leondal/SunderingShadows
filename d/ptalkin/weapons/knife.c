#include <std.h>
inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "knife"}));
   set_name("knife");
   set_short("A knife");
   set_long(
	"This is a shiney, well kept knife. "
   );
   set_weight(1);
   set_size(1);
   set("value", 5);
   set_cointype("silver");
	set_wc(1,4);
	set_large_wc(2,5);
   set_type("piercing");
}
void init()
{
  ::init();
add_action("circle","circle");
}
int circle(string str)
{
object target;
target=present(str,environment(TP));
if(!target)
{
    notify_fail("What?\n");
    return 0;
}
write("You circle around your opponent.");
target->add_hp(-(random(50)));
write("You stab your opponent in the back");
return 1;
}
