#include "/d/shadow/room/city/cguild/ranger/ranger.h"
inherit "/std/vendor";

void create() {
   ::create();
   set_name("grackil");
   set_id(({ "clerk","ranger","wolf","wolf lord","shop keeper","grackil","gstorekeeper"}));
   set_short("%^BOLD%^%^BLACK%^Grackil the Wolflord%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This being looks like a man-size wolf, save that "
"he stands erect.  %^RESET%^%^ORANGE%^Dark fur %^BOLD%^%^BLACK%^coats his "
"entire body, save where it is hidden beneath his clothing.  %^YELLOW%^Gleaming "
"amber eyes %^BLACK%^survey all visitors to this store.  While he doesn't seem "
"aggressive or threatening, he moves with the grace of the creature he "
"resembles, and you can imagine he could defend his shop just as competently as "
"he runs it.%^RESET%^\n\n%^YELLOW%^<help shop>%^RESET%^ will give you a list of "
"shop commands.%^RESET%^");
   set("aggressive", 0);
   set_class("ranger");
   set_guild_level("ranger",25);
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(1);
   set_race("lupine");
   add_money("gold",1);
   set_body_type("human");
   set_storage_room(RROOM"storage.c");
   set_hd(19,10);
   set_items_allowed("all");
   set_max_hp(250);
   set_hp(250);
}
int __List(string str){
    if(TP->is_class("ranger") || TP->is_class("druid") || avatarp(TP)) return ::__List(str);
    else {
      tell_object(TP,"Grackil snarls as you try to approach, seeming to sense "
"that you are not of the forests. It seems he will not let you use this shop.");
      return 1;
    }
}
__Buy(str){
    if(TP->is_class("ranger") || TP->is_class("druid") || avatarp(TP)) return ::__Buy(str);
    else {
      tell_object(TP,"Grackil snarls as you try to approach, seeming to sense "
"that you are not of the forests. It seems he will not let you use this shop.");
      return 1;
    }
}
__Sell(str){
    if(TP->is_class("ranger") || TP->is_class("druid") || avatarp(TP)) return ::__Sell(str);
    else {
      tell_object(TP,"Grackil snarls as you try to approach, seeming to sense "
"that you are not of the forests. It seems he will not let you use this shop.");
      return 1;
    }
}
__Show(str){
    if(TP->is_class("ranger") || TP->is_class("druid") || avatarp(TP)) return ::__Show(str);
    else {
      tell_object(TP,"Grackil snarls as you try to approach, seeming to sense "
"that you are not of the forests. It seems he will not let you use this shop.");
      return 1;
    }
}
__Value(str){
    if(TP->is_class("ranger") || TP->is_class("druid") || avatarp(TP)) return ::__Value(str);
    else {
      tell_object(TP,"Grackil snarls as you try to approach, seeming to sense "
"that you are not of the forests. It seems he will not let you use this shop.");
      return 1;
    }
}
