inherit "/std/armour";
#include <std.h>;
void create(){
    ::create();
    set_name("hose leggings");
  set_id(({
  "hose","fine hosery","leggings","hose leggings",
  }));
    set("short","fine hosery");
    set("long",
        "These are finely made hose, in a dark green color."
    );
    set_type("clothing");
    set_limbs(({"right leg","left leg"}));
    set_weight(1);
  set_value(35);
}
