#include <std.h>
#include "../defs.h"
inherit INH+"chasm";

int found;

void create(){ 
   ::create();
   set_long("%^MAGENTA%^A cavern within the Wailing Chasm%^RESET%^\n"
"%^BLUE%^This small cavern lies all on its own along the wall of the Wailing Chasm.  You're not sure if you could "
"even really call it a cavern, as it lies mostly open to the howling and buffeting of the winds in the chasm.  "
"You're not sure that there is any particular purpose to this alcove, though perhaps one of the great flying "
"or climbing creatures of underdark may once have lived here.  Surely it seems empty now.  Somewhere a little "
"further above lies a narrow ledge; you suspect from this angle that the alcove you stand in wouldn't be visible "
"from above.%^RESET%^\n");
   set_climb_exits(([
     "climb":({"/d/underdark/mid/chasm28",15,roll_dice(2,10),100}),
   ]));
   set_search("default",(:TO,"search_room":));
   found = 0;
}

int search_room(string str) {
    object ob;
    if((string)TP->query_name() != "saturnina" && !avatarp(TP)) {
      tell_object(TP,"You search around but you don't find anything of interest.");
      return 1;
    }
    if(found) {
      tell_object(TP,"You can sense nothing here.");
      return 1;
    }
    tell_object(TP,"%^MAGENTA%^You know exactly what you're looking for, and it resonates with the divine power "
"you wield. Calling upon the Lady's blessings, you meld your hand into the stone of the alcove's back wall at "
"a specific point, and withdraw a %^RESET%^silvery chain%^MAGENTA%^.%^RESET%^");
    tell_room(ETP,"%^MAGENTA%^"+TP->QCN+" speaks a prayer and reaches into and through the back wall, before "
"drawing "+TP->QP+" hand back out holding a %^RESET%^silvery chain%^MAGENTA%^.%^RESET%^",TP);
    new("/d/avatars/nienne/shartalisman")->move(ETP);
    found = 1;
    return 1;
}