//tentob.c - Tent object to load in hill rooms to connect to tent rooms

#include <std.h>
#include "/d/newbie/newbie.h"

inherit OBJECT;

void create(){
    ::create();
    set_name("tent");
    set_id( ({"tent", "canvas tent"}) );
    set_short("%^RESET%^%^ORANGE%^Small canvas tent%^RESET%^");
    set_long(
      "This is a nice little tent with sturdy poles that has been made to be very quickly and easily set up.  The sturdy cloth for the walls and roof has been coated to be waterproof.  A flap is open so you can enter it.  Most everyone but little people will have stoop inside though because it's barely tall enough for a short human."
    );
    set_weight(10000);
    set_property("no animate",1);
    call_out("place_tent",1);
}

void place_tent(){
   object ob, ob2;
   if (!objectp(ETO)) return;
   ob = new(HILL"tent1");
   ob2 = (base_name(ETO));
   ob->remove_exit("back");
   ob->add_exit(base_name(ETO), "out");
   ob2->add_exit(file_name(ob), "tent");
}
