

#include <std.h>
#include <priest.h>



inherit OBJECT;




void create() {
    ::create();
    set_name("godsfavor");
    set("id", ({ "remotexoli"}) );
    set_short("");
    set_long("");
    set_property("no animate", 1);
    set_weight(0);
}



void init() {
    ::init();
    add_action("now","now");
}

int now(string str){
   string where, temple,diety;
   diety = TP->query_diety();
   if(TP->query_diety()) {
      where = "/d/magic/temples/"+diety;
      temple = "Temple of "+capitalize(TP->query_diety());
   }
   else{
      tell_object(TP,"You need to follow a god to be saved by one.");
      dest_effect();
      return 0;
   }
   if (environment(TP)->query_property("no teleport") || environment(TP)->query_property("teleport proof")) {
      tell_object(TP,"Even "+TP->query_diety()+" is unable to save you from here.");
      dest_effect();
      return 0;
   }
   tell_object(TP,"You feel the presence of your diety fill the room as you are swept away from danger and brought back to the "+temple+"!");
   tell_room(environment(ETO), "A holy presence fills the room and "+TPQCN+" disappears from view!", ({TP}));
   TP->move_player(where);
   dest_effect();
   return 1;
}
void dest_effect(){
   TO->remove();
}
