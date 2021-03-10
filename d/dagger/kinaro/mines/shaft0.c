#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_name("A short side tunnel");
   set_short("%^BOLD%^%^BLACK%^A short side tunnel%^RESET%^");
   set_long((:TO,"long_desc":));
   set_exits(([
     "north":MINES"mines4",
     "enter":MINES"elevator",
   ]));
   add_item("lever","%^ORANGE%^A %^BOLD%^%^BLACK%^lever%^RESET%^%^ORANGE%^ "
"has been set into the wall, a few feet back from the vertical shaft that "
"leads downwards.  Perhaps you could %^YELLOW%^pull the lever"
"%^RESET%^%^ORANGE%^?%^RESET%^");
}

string long_desc() {
   if(member_array("enter",TO->query_exits()) != -1) {
     return("%^BOLD%^%^BLACK%^A short side tunnel%^RESET%^\n"
"%^ORANGE%^This shaft is obviously not naturally formed, cut into the "
"recesses of the mountainside and supported by %^RED%^wooden struts "
"%^ORANGE%^and %^BOLD%^%^BLACK%^bars %^RESET%^%^ORANGE%^at regular intervals. "
" From within the stone walls themselves glitter hints of%^WHITE%^ "
"met%^BOLD%^a%^RESET%^ls %^ORANGE%^and precious%^BOLD%^%^RED%^ "
"g%^YELLOW%^e%^RESET%^%^GREEN%^m%^BLUE%^s%^ORANGE%^, just waiting to be "
"extracted.  Along the ground run %^BOLD%^%^BLACK%^sturdy metal rails%^RESET%^"
"%^ORANGE%^, probably designed to carry mining carts back and forth.  The "
"rails, and indeed the entirety of the short tunnel, come to an abrupt halt "
"only a short way in from the main thoroughfare.  At the end is an odd "
"looking metal cage, suspended in a vertical shaft leading downward by a "
"complicated system of cogs and pulleys.  Set into the stone wall before it "
"is a %^BOLD%^%^BLACK%^lever%^RESET%^%^ORANGE%^.%^RESET%^\n");
   }
   return("%^BOLD%^%^BLACK%^A short side tunnel%^RESET%^\n"
"%^ORANGE%^This shaft is obviously not naturally formed, cut into the "
"recesses of the mountainside and supported by %^RED%^wooden struts "
"%^ORANGE%^and %^BOLD%^%^BLACK%^bars %^RESET%^%^ORANGE%^at regular intervals. "
" From within the stone walls themselves glitter hints of%^WHITE%^ "
"met%^BOLD%^a%^RESET%^ls %^ORANGE%^and precious%^BOLD%^%^RED%^ "
"g%^YELLOW%^e%^RESET%^%^GREEN%^m%^BLUE%^s%^ORANGE%^, just waiting to be "
"extracted.  Along the ground run %^BOLD%^%^BLACK%^sturdy metal rails%^RESET%^%^ORANGE%^"
", probably designed to carry mining carts back and forth.  The rails, and "
"indeed the entirety of the short tunnel, come to an abrupt halt only a "
"short way in from the main thoroughfare.  At the end is a vertical shaft "
"leading downwards, in which is a complicated system of cogs and pulleys.  "
"Set into the stone wall before it is a %^BOLD%^%^BLACK%^lever%^RESET%^"
"%^ORANGE%^.%^RESET%^\n");
}

void init(){
   ::init();
   add_action("pull_fun","pull");
}

int pull_fun(string str){
   object mylift;
   if(!str) {
     notify_fail("What do you want to pull?\n");
     return 0;
   }
   if(str != "lever" && str != "the lever") {
     notify_fail("You can't pull that\n");
     return 0;
   }
   if(member_array("enter",TO->query_exits()) != -1) {
     tell_object(TP,"%^ORANGE%^You pull the lever, but nothing "
"happens.%^RESET%^");
     tell_room(TO,"%^ORANGE%^"+TP->QCN+" pulls the lever, but nothing "
"happens.%^RESET%^",TP);
     return 1;
   }
   mylift = find_object_or_load(MINES"elevator");
   if(mylift->query_property("moving")){
     tell_object(TP,"%^ORANGE%^You pull the lever, but nothing "
"happens.%^RESET%^");
     tell_room(TO,"%^ORANGE%^"+TP->QCN+" pulls the lever, but nothing "
"happens.%^RESET%^",TP);
     return 1;
   }
   tell_object(TP,"%^ORANGE%^You pull the lever, and a low rumbling becomes "
"audible from the vertical shaft in front of you.%^RESET%^");
   tell_room(TO,"%^ORANGE%^"+TP->QCN+" pulls the lever, and a low rumbling "
"becomes audible from the vertical shaft in front of you.%^RESET%^",TP);
   mylift->remote_moving("up");
   return 1;
}
