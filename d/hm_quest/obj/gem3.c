#include <std.h>
inherit OBJECT;

string owner;

void create() {
    ::create();
    set_name("diamond");
    set_id(({"gem3","hm_quest_diamond","diamond"}));
    set_short("%^RESET%^%^YELLOW%^A sparkling diamond%^RESET%^");
    set_long("%^RESET%^This large %^BOLD%^%^WHITE%^diamond %^RESET%^gemstone certainly appears to be worth a bit of money. It has been cut to display its upper facets to best effect, and seems "
"to %^BOLD%^%^WHITE%^glow %^RESET%^with a faint magical light from within. Its underside is slightly %^BOLD%^%^BLACK%^scratched%^RESET%^, leaving you to think you could insert it into the right "
"setting.%^RESET%^");
    set_weight(2);
    set_value(0);
    set_heart_beat(1);
}

void init() {
    ::init();
    if(interactive(TP) && !owner) owner = TP->query_true_name();
}

void heart_beat() {
    string holder;
    if(!objectp(ETO)) return;
    if(!interactive(ETO)) return;
    holder = ETO->query_true_name();
    if(holder != owner) {
      tell_object(ETO,"The diamond vanishes!");
      TO->remove();
    }
}