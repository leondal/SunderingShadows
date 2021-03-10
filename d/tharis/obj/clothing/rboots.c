inherit "/std/armour";
#include <std.h>;
void create(){
::create();
set_name("riding boots");
set_id(({"riding boots","boots"}));
set("short","a pair of riding boots");
set("long","This is a pair of riding boots.");
set_type("clothing");
    set_limbs(({"right foot", "left foot"}));
set_weight(1);
set_size(random(3)+1);;;set_value(3);
}
