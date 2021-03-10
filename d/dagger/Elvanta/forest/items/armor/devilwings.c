#include <std.h>
inherit "/std/armour";

void create() {
    ::create();
set_name("devil wings");
set_id(({"robe", "wings", "devil wings"}));
set_short("devil wings");
set_long("%^BOLD%^RED%^While closed this long deep red robe appears to be fairly ordinary.  You cannot not, however, help but notice the clasp at the the top, and that it resembles clenched claws.  As the robe unfurls, you gasp....IT IS NOT A ROBE, but wings, bat-like and large.");
set_weight(2);
    set("value", 4);
set_type("clothing");
set_limbs( ({"torso"}) );
set_ac(-3);
set_wear((:TO, "wearit":));
}
int wearit() {
if((string)TP->query_race() !="devil") {
write("%^RED%^You are not EVIL enough to wear these!!");
return 0;
}
  return 1;
}
