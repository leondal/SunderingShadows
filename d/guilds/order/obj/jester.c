#include <std.h>;
inherit "/std/guild";
void create(){
    guild::create();
    set_name("mask");
      set_id(({"mask","jester's face mask","face mask"}));
     set("short", "A jester's face mask");
    set("long",
      "This mask is worn by court jesters to aid them in their comical performances. This particular mask was enchanted by the Order's magi, it helps to make the Jester more comical, by driving them insane. Isn't that just a laugh?"
    );
    set_weight(1);
    set_type("clothing");
    set_limbs(({"head"}));
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
    TP->force_me("wear mask");
    }
}
int drop(){
  return 1;
}
int wear_robe(){
  object targ;
  tell_object(this_player(),"%^BOLD%^%^MAGENTA%^You place the mask over your face and begin cackling insanely!%^RESET%^");
  write("%^BOLD%^%^MAGENTA%^"+TPQCN+" dons the jester's mask and begins to laugh hysterically.");
    return 1;
}
int remove_robe(){
  tell_object(this_player(),"%^CYAN%^The world seems much more bland as you remove the mask.%^RESET%^");
    return 1;
}
