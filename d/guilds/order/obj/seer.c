#include <std.h>;
inherit "/std/guild";
void create(){
    guild::create();
    set_name("tassel");
    set_id(({"tassel","elegant tassel"}));
    set("short", "Silver tassel");
    set("long",
      "This silver strand of cloth is given to all seers of the Order, in order to help protect and guid them. It will give you strength in times of need and help you to follow the dictates of the Order of the Metallic Dragon's."
    );
    set_weight(1);
    set_type("clothing");
    set_limbs(({"waist"}));
    set_ac(1);
    set_value(1);
    set_leader("mordred");
    set_guild_hc(({"fyndlorn","cromack","stilgar"}));
  set_guild_items(({base_name(TO)}));
    set_guild_home("/d/guilds/order/hall/main2.c");
    set_welcome("%^BOLD%^Welcome to this, the holiest of Orders.%^RESET%^");
    set_guild_name("Order of the Metallic Dragon");
    set_wear((:this_object(),"wear_robe":));
    set_remove((:this_object(),"remove_robe":));
}
void init(){
  ::init();
    if(ETO == TP){
    TP->force_me("wear tasel");
}
}
int wear_robe(){
  tell_object(this_player(),"%^BOLD%^%^BLUE%^You strap the silver tasel of the Order around your waste, and feel its protective magics take effect.%^RESET%^");
    return 1;
}
int remove_robe(){
  tell_object(this_player(),"%^CYAN%^You remove the tasel, and shiver, you are much weaker now.%^RESET%^");
    return 1;
}
