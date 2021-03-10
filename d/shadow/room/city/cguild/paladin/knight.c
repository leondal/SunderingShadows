#include <std.h>
#include "/realms/grazzt/paladin/short1.h"
inherit "/std/vendor";

void create() {
   ::create();
   set_name("knight");
   set_id( ({ "knight", "clerk", "shop keeper", "shopkeeper"}) );
   set_short("%^RED%^Knight of the Order's "
	"Armoury%^BOLD%^%^GREEN%^");
   set("aggressive", 0);
   set_level(19);
   set_long("He buys and sells equipment.\n"+
        "<help shop> will get you a list of shop commands.\n");
   set_languages( ({ "common" }) );
   set_gender("male");
   set_alignment(1);
   set("race", "human");
   add_money("gold", random(500));
   set_body_type("human");
   set_storage_room( RPATH "storage");
   set_property("no attack", 1);
   set_hd(19,3);
   set_items_allowed("all");
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
}
__List(string str){
    if(TP->is_class("paladin")) return ::__List(str);
    else {
      tell_object(TP, "Only the knights of holy may purchase from me!");
      return 1;
    }
}
__Buy(string str){
    if(TP->is_class("paladin")) return ::__Buy(str);
    else {
      tell_object(TP, "Only the knights of holy may purchase from me!");
      return 1;
    }
}
__Sell(string str){
    if(TP->is_class("paladin")) return ::__Sell(str);
    else {
      tell_object(TP, "Only the knights of holy may purchase from me!");
      return 1;
    }
}
__Show(string str){
    if(TP->is_class("paladin")) return ::__Show(str);
    else {
      tell_object(TP, "Only the knights of holy may purchase from me!");
      return 1;
    }
}
__Value(string str){
    if(TP->is_class("paladin")) return ::__Value(str);
    else {
      tell_object(TP, "Only the knights of holy may purchase from me!");
      return 1;
    }
}
