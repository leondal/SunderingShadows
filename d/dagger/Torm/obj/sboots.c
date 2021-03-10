inherit "/std/armour";
#include <std.h>;
string class;
int  real_str;
void create(){
    ::create();
    set_name("soft boots");
    set_id(({"soft boots","boots"}));
    set("short", "boots of soft leather");
    set("long",
        "These are a pair of boots made from soft leather.  They provide a little protection, but not much, though they will keep your feet toasty warm."
    );
    set_type("clothing");
    set_limbs(({"right foot","left foot"}));
    set_weight(1);
    set_value(1);
}
