inherit "/std/guild";
#include <std.h>;
void create(){
  guild::create();
    set_name("crest");
    set_id(({"crest","dragon crest","dragon"}));
    set("short", "Dragon crest");
    set("long",
      "This adornment is fashioned from dragon scales, and set to rest atop the young knights helm. From there it can shed its protective magics across the wearer, helping to guide the warrior along his path."
    );
    set_type("clothing");
    set_limbs(({"right hand"}));
    set_wear((:this_object(),"wear_plate":));
    set_remove((:this_object(),"remove_plate":));

    set_weight(1);
    set_value(1);
    set_ac(1);
    set_leader("mordred");
    set_guild_hc(({"fyndlorn","cromack","stilgar"}));
  set_guild_items(({base_name(TO)}));
    set_guild_home("/d/guilds/order/hall/main2.c");
    set_welcome("Welcome to this, the holiest of Orders.");
    set_guild_name("Order of the Metallic Dragon");
}
void init(){
  ::init();
  if(ETO == TP){
    TP->force_me("wear gauntlet");
    }
}
int drop(){
  return 1;
}
int wear_plate(){
  tell_object(this_player(),"%^BOLD%^The glory and wisdom of the Order of the Mettallic Dragons rushes into your body as you don this gauntlet.%^RESET%^");
    return 1;
}
int remove_plate(){
  tell_object(this_player(),"%^CYAN%^You remove the mighty gauntlet and feel cold and alone.%^RESET%^\n");
    return 1;
}
