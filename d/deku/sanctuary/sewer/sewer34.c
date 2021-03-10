#include <std.h>
#include "../dragon.h";

inherit BSEWER;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_short("Sewers under Sanctuary");
    set_long(
      "%^BOLD%^%^BLACK%^To the north, the tunnel slopes upward somewhat steeply. Flanking the"+
      " tunnel here, are a pair of very large statues of human warriors. Looking"+
      " deeper into the tunnel, you notice more statues at irregular intervals."+
      " In addition, the tunnel is faintly illuminated by lichen that clings to"+
      " the walls and ceiling."
    );
    set_exits(([
       "up" : SEWER+"sewer33",
       "south" : SEWER+"sewer35"
    ] ));
    set_items(([
       "statues":"These two stone statues are made of stone.  Each appear\n"+
                 "to have been alive once by looking at their facial expression."
    ] ));
    set_trap_functions(({"south"}),({"jump_em"}),({"south"}));
    set_property("no teleport", 1);
}

int jump_em() {
object ob;
toggle_trap("south");
   if(interactive(TP)){
   tell_object(TP,"As you turn to leave, two quaggoths ambush you!");
   tell_room(ETP,"As "+TPQCN+" turns to leave, two quaggoths jump out!",TP);
   ob = new(MON+"quaggoth");
   ob->set_property("no bows",1);
   ob->move(TO);
   ob->force_me("block up");
   ob = new(MON+"quaggoth");
   ob->set_property("no bows",1);
   ob->move(TO);
   ob->force_me("block south");
   return 1;
}
}
