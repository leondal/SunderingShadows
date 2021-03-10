#include <std.h>
inherit OBJECT;
//goes in derro forest, portal stone for players to find
void create() {
  set_id( ({"stone","portal stone","Portal Stone"}));
  set_name("Portal Stone");
  set_short("%^RESET%^%^CYAN%^A rune covered stone");
  set_weight(10000000);
  set_value(0);
  set_property("no animate", 1);
  set_long("%^CYAN%^This is a large stone that is "+
  "inscribed with runes.  It looks rather old but "+
  "seems to be in good working order.  It is a dark"+
  " gray granite.  Perhaps one could <read> the runes if they tried.%^RESET%^");
}
void init(){
  ::init();
  add_action("touch_fun","touch");
  add_action("read_symbols","read");
}
void touch_fun(string str){
   if ( !str || str !="stone") {
      notify_fail ("Touch what?\n");
      return 0;
   }
   TP->force_me("emote touches the stone.");
   if(!present("pasque flower",TP)){
     tell_object(TP,"You try to activate the stone but nothing happens.");
     return 1;
   } 
   tell_object(TP,"%^CYAN%^Your flower seems to resonate with the stone."+
      "  The world spins and you find yourself standing in a different location.");
   tell_room(TO,"%^CYAN%^The stone glows and "+TP->QCN+" vanishes.",TP);
   TP->move("/d/islands/elf/ice/planar");
   "/d/islands/elf/ice/planar"->set_place("/d/islands/elf/ice/ruin2");
   return 1;
}
int read_symbols(string str) {
   if(str != "runes" && str != "runes") {
   return 0;
   }
   if( (string)TP->query_race() != "elf") {
      tell_object(TP,"%^CYAN%^The symbols are only gibberish.");
      tell_room(ETP,"%^CYAN%^"+TPQCN+" reads the symbols.",TP);
      return 1;
   }
   tell_object(TP,"%^CYAN%^To use the portal: touch "+
   "it with the pasque flower on your person.");
   tell_room(ETP,"%^CYAN%^"+TPQCN+" reads the symbols.",TP);
   return 1;
}
