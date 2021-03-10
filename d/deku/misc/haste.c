#include <std.h>
inherit POTION;

void create() {
    ::create();
set_short("A vial containing a pale black liquid");
    set_long("The pale black liquid is viscous and cool to the touch.");
    set("color", "black");
    set("efect_time",(random(4) * 7));
}
int do_effect() {
  tell_object(drinker, "A quick jolt of energy moves through your body, a making you shiver.");
  if(member_array(drinker, targ->query_attackers()) == -1) {
    tell_object(drinker, "%^GREEN%^This potion is best used when you are fighing your enemies.");
    return 1;
  }
    return 1;
}
int do_wear_off() {
}
