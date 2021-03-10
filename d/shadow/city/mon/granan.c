#include <std.h>
inherit "/std/fence";

void create() {
   ::create();
   set_name("Granan");
    set_id( ({ "granan","Granan","shop keeper"}) );
    set_short("%^RESET%^G%^BOLD%^r%^RESET%^a%^BOLD%^%^BLACK%^na%^RESET%^n%^BOLD%^%^BLACK%^, "+
	"%^WHITE%^S%^RESET%^h%^BOLD%^%^BLACK%^ad%^RESET%^o%^BOLD%^w "+
	"%^RESET%^G%^BOLD%^%^BLACK%^ui%^RESET%^l%^BOLD%^d%^RESET%^'s "+
	"%^BOLD%^%^BLACK%^Fe%^RESET%^n%^BOLD%^c%^RESET%^e");
   set("aggressive", 0);
    set_level(20);
set_long("%^RESET%^This short and fairly unimpressive looking man "+
"would be called nondescript but for his large "+
"%^BOLD%^%^BLACK%^b%^RESET%^%^BLUE%^l%^BOLD%^ue-%^RESET%^%^BLUE%^g%^BOLD%^%^BLACK%^r%^RESET%^%^BLUE%^a%^BOLD%^y "+
"e%^RESET%^%^BLUE%^y%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^s %^WHITE%^"+
"that bulge from his oval face. Short-cropped %^ORANGE%^brown hair %^WHITE%^"+
"covers his head in an untidy mop, while his skin has a "+
"%^BOLD%^white p%^RESET%^a%^BOLD%^ll%^RESET%^o%^BOLD%^r %^RESET%^that suggests he rarely sees the sun. Dressed "+
"in %^BOLD%^%^BLACK%^common %^RESET%^clothing, he might be mistaken for any citizen "+
"of the city. A ploy that is likely a plus in his profession. "+
"Currently, he sits behind the counter of the Shadow Guild's "+
"thief store where you can <buy>, <fence> or <launder>.");
   set_gender("male");
   set_alignment(5);
   set_class("thief");
   set("race", "human");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no bump", 1);
    set_hd(20,30);
     set_spoken("wizish");
}

int __Buy(string str){
    if(TP->is_class("thief") || TP->is_class("bard") ||
TP->is_class("assassin") || avatarp(TP)) return ::__Buy(str);
    else {
      tell_object(TP, "Granan shakes his head, ""You don't belong here.");
      return 1;
    }
}

int __Sell(string str){
    if(TP->is_class("thief") || TP->is_class("bard") ||
TP->is_class("assassin") || avatarp(TP)) return ::__Sell(str);
    else {
      tell_object(TP, "Granan shakes his head, ""You don't belong here.");
      return 1;
    }
}

int __Show(string str){
    if(TP->is_class("thief") || TP->is_class("bard") ||
TP->is_class("assassin") || avatarp(TP)) return ::__Show(str);
    else {
      tell_object(TP, "Granan shakes his head, ""You don't belong here.");
      return 1;
    }
}

int __List(string str){
    if(TP->is_class("thief") || TP->is_class("bard") ||
TP->is_class("assassin") || avatarp(TP)) return ::__List(str);
    else {
      tell_object(TP, "Granan shakes his head, ""You don't belong here.");
      return 1;
    }
}

int __Value(string str){
    if(TP->is_class("thief") || TP->is_class("bard") ||
TP->is_class("assassin") || avatarp(TP)) return ::__Value(str);
    else {
      tell_object(TP, "Granan shakes his head, ""You don't belong here.");
      return 1;
    }
}
