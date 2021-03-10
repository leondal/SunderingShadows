#include <std.h>
#include "../defs.h"
inherit INH+"lower";

void create(){ 
   ::create();
   set_long((:TO,"long_desc":));
   set_exits(([
     "north":MINES"lower2e",
     "south":MINES"lower1b",
   ]));
   add_item("lever","%^ORANGE%^A %^BOLD%^%^BLACK%^lever%^RESET%^%^ORANGE%^ "
"has been set into the wall, a few feet back from the vertical shaft that "
"leads upwards.  Perhaps you could %^YELLOW%^pull the lever"
"%^RESET%^%^ORANGE%^?%^RESET%^");
}

string long_desc() {
   if(member_array("enter",TO->query_exits()) != -1) {
     return("%^BOLD%^%^BLACK%^An underground mining tunnel%^RESET%^\n"
"%^BLUE%^You stand within the lower reaches of the mine system.  "
"The air is thick and %^RED%^humid %^BLUE%^here among the darker stone "
"tunnels, which have obviously been made by mortal hands.  %^ORANGE%^Heavy "
"wooden beams %^BLUE%^and %^WHITE%^metal bars %^BLUE%^support the stone of "
"the walls and roof, from which glitter specks of %^CYAN%^ge%^BOLD%^m"
"%^WHITE%^st%^CYAN%^o%^RESET%^%^CYAN%^ne %^BLUE%^and seams of precious "
"%^WHITE%^me%^BOLD%^t%^RESET%^%^WHITE%^als%^BLUE%^, only waiting to be "
"extracted from their rocky prison.  Along the ground, a pair of "
"%^BOLD%^%^BLACK%^thick metal rails %^RESET%^%^BLUE%^has been placed, perhaps "
"to carry mining carts back and forth.  The tunnel leads away to the north "
"and south into darkness.  Set within the stone at the side of the path is a "
"vertical shaft leading upwards, in which sits an odd looking metal cage, "
"with a %^BOLD%^%^BLACK%^lever%^RESET%^%^BLUE%^ beside it on the "
"wall.%^RESET%^\n");
   }
   return("%^BOLD%^%^BLACK%^An underground mining tunnel%^RESET%^\n"
"%^BLUE%^You stand within the lower reaches of the mine system.  "
"The air is thick and %^RED%^humid %^BLUE%^here among the darker stone "
"tunnels, which have obviously been made by mortal hands.  %^ORANGE%^Heavy "
"wooden beams %^BLUE%^and %^WHITE%^metal bars %^BLUE%^support the stone of "
"the walls and roof, from which glitter specks of %^CYAN%^ge%^BOLD%^m"
"%^WHITE%^st%^CYAN%^o%^RESET%^%^CYAN%^ne %^BLUE%^and seams of precious "
"%^WHITE%^me%^BOLD%^t%^RESET%^%^WHITE%^als%^BLUE%^, only waiting to be "
"extracted from their rocky prison.  Along the ground, a pair of "
"%^BOLD%^%^BLACK%^thick metal rails %^RESET%^%^BLUE%^has been placed, perhaps "
"to carry mining carts back and forth.  The tunnel leads away to the north "
"and south into darkness.  Set within the stone at the side of the path is a "
"vertical shaft leading upwards, with a %^BOLD%^%^BLACK%^lever%^RESET%^"
"%^BLUE%^ beside it on the wall.%^RESET%^\n");
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
   mylift->remote_moving("down");
   return 1;
}
