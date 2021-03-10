inherit "/std/armour";
#include <std.h>;
void create(){
    ::create();
    set_name("riding boots");
    set_id(({"riding boots","boots"}));
  set_short("riding boots");
    set("long",
      "These are high sided boots made of hard leather.  They are crafted to allow you to be able to ride horses and other animals comfortably.  They have small spurs on the heels, for use when riding."
    );
    set_type("clothing");
    set_limbs(({"right foot", "left foot"}));
    set_weight(1);
  set_value(25);
}
