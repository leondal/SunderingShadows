#include <std.h>;
inherit "/std/guild";
void create(){
    guild::create();
    set_name("pendant");
    set_id(({"pendant","lordly pendant"}));
    set("short", "Lordly Pendant");
    set("long",
    "This is a remarkably plain looking pendant given to the Lords of the Order of the Metallic Dragons to wear upon their breatplates. For a Lord must show humility before those he would wish to govern."
    );
    set_weight(1);
    set_type("clothing");
    set_limbs(({"torso"}));
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
    TP->force_me("wear pendant");
}
}
int wear_robe(){
  tell_object(this_player(),"%^BOLD%^You clip the plain pendant to your breastplate and are encompassed in and aura of white light.%^RESET%^");
    return 1;
}
int remove_robe(){
    tell_object(this_player(),"%^CYAN%^You remove the pendant and see the white aura dissolve itself.%^RESET%^");
    return 1;
}
