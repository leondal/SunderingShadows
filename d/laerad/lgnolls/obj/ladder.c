#include <std.h>
#include "../lgnoll.h"
inherit OBJECT;
void create(){
  ::create();
  set_name("ladder");
 set_id(({"ladder","wooden ladder","woodenladder"}));
  set_short("%^ORANGE%^A wooden ladder%^RESET%^");
  set_long("%^ORANGE%^This is a large wooden ladder. It has "+
  "been constructed quite cleverly as it has been made in modules."+
  " Each part of this ladder can be connected to the next with a "
  "hook secured by a loop. When all the ladder modules are "+
  "connected this ladder must be around 60 feet long!  ");
   set_weight(15);
  set_value(random(25)+50);
}

int is_ladder(){return 1;}