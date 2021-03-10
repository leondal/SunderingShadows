inherit "/std/armour";
#include <std.h>;
//string class;
int  real_str;
void create(){
::create();
set_name("soft boots");
set_id(({"soft boots","boots"}));
set("short","a pair of soft boots");
set("long","This is a pair of soft walking boots.");
set_type("clothing");
set_limbs(({"right foot","left foot"}));
set_weight(1);
set_size(random(3)+1);;;set_value(1);
}
