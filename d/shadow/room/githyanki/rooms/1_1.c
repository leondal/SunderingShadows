#include <std.h>
#include "../githyanki.h"

inherit STORAGE"1floor.c";


void init() {
    ::init();
    add_action("jump", "jump");
}

void create(){
   ::create();
  set_long(::query_long()+"%^RESET%^%^ORANGE%^The wall has been destroyed on one side, creating a large crack%^RESET%^.\n");
   set_exits(([
      "east" : ROOMS"1_14",
      "south" : ROOMS"1_2",
   ]));
   add_item("crack","%^RESET%^%^ORANGE%^Something horrible must have struck the fortress to create this large a crack in the wall. It exposes the fortress to the outside world. If you wanted to leave you could always jump...%^RESET%^");
}

int jump(){
        
    tell_object(TP,"%^RED%^you step up to the edge and jump!%^RESET%^");
        tell_room(ETP,"%^RESET%^%^RED%^Are they crazy? "+TPQCN+"%^RESET%^%^RED%^"+
" walks over to the crack and jumps out of the fortress%^RESET%^",TP);
        TP->move_player("/d/shadow/virtual/desert/18,45.desert.c");
        tell_object(TP,"%^BLACK%^%^BOLD%^You feel a tingling "+
"sensation as a spell of featherfall is cast on you! Luckily you "+
"land softly.%^RESET%^");
    return 1;
}
