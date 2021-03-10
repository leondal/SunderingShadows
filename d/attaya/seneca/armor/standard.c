#include <std.h>
inherit "/std/plate";
 
void create() {
    ::create();
    set_name("field plate");
  set("id", ({"field armor","standard armor","armor","armour","standard" }) );
   set_short("Standard issue field armor");
    set_long("
    This is Standard issue field armor of the Seneca high infantry.  It is finely polished and comprised of a breast plate, hip plates, a left shoulder plate, and a back plate.  It is banded together with shiny silver mesh.
");
    set_weight(40);
    set("value", 9000);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    set_ac(6);
        set_wear((:this_object(), "extra_wear":));
}
int extra_wear() {
    if((int)TP->query_level() < 18) {
    notify_fail("You are not ready for this armor.");
    return 0;
    }
    write("You wear the standard issue Seneca field armor and almost blind yourself in the mirror like finish!");
    return 1;
}
