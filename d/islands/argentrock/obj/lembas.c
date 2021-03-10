//Elven waybread (Lembas bread) -- Yves
#include <std.h>
inherit "/std/food.c";

void create(){
   ::create();
    set_name("A loaf of elven waybread");
    set_id(({
        "lembas",
        "lembas bread",
        "elven waybread",
        "waybread",
        "bread",
        "food",
    }));
    set_short("A loaf of elven waybread");
    set_long(
        "%^ORANGE%^This is a loaf of famous freshly baked %^MAGENTA%^elven%^ORANGE%^ waybread. It is "
        "%^BOLD%^%^BLACK%^crispy%^RESET%^%^ORANGE%^ and brown on the outside, and soft on the inside "
        "with a %^BOLD%^%^WHITE%^creamy white%^RESET%^%^ORANGE%^ color.%^RESET%^"
    );
    set_destroy();
    set_poison(0);
    set_strength(0);
    set_my_mess(
        "%^ORANGE%^You bite into the %^MAGENTA%^elven%^ORANGE%^ waybread and enjoy the filling taste of "
        "fresh cooked bread. The %^BOLD%^%^BLACK%^crispness%^RESET%^%^ORANGE%^ of the outside and the "
        "%^RESET%^softness%^ORANGE%^ of the inside contrast %^CYAN%^perfectly%^ORANGE%^ and the flavor is "
        "simply delicious.%^RESET%^",
    );
    set_your_mess(
        "takes delight in the smell of the elven waybread before eating "
        "it all.",
    );
    set_weight(0);
    set_value(0);
    set_canSave(1);
}

void init(){
    ::init();
    add_action("eat_func","eat");
}

int eat_func(string str) {
    if(!str){return 0;} 
    if(TP->query_current_attacker()) {
        notify_fail("You are too busy to eat anything!\n");
        return 0;
    }
    if((int)TP->query_stuffed() < ((int)TP->query_formula()/1)) //dont think I need this
    TP->add_stuffed(((int)TP->query_formula()/250));
    TP->reset_condition();
    tell_object(ETO,my_mess);
    tell_room(EETO,TPQCN+" "+your_mess,ETO);
    remove();
    return 1;
}
