#include <std.h>
#include "../tormdefs.h"
inherit MARKET;
void create()
  {
  ::create();
   set_long(TO->query_long()+" There is a large fountain to the northeast and it looks as though there is a bank directly south of here.");
   set("night long",TO->query("night long")+"  Strangely enough the bank to the south seems to be the only thing open.");
   add_item("bank","There is a bank to the south that seems constantly busy.");
  set_exits(([
  "north":TCITY+"c55",
  "east":TCITY+"c64",
  "south":TCITY+"c100",
  "west":TCITY+"c62",
  ]));
  set_pre_exit_functions(({"south"}),({"block"}));
}
int block(){
  if((string)TP->query_race()=="sahuagin"){
  return 0;
  }
  tell_object(TP,"You walk into the bank of Torm.");
  if(!(TP->query_invis())){
  tell_room(ETP,""+TP->query_name()+" walks south into the bank.",TP);
  }
  return 1;
}
