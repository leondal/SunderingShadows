#include <std.h>

inherit DAEMON;

int cmd_fakedeath(){

  TP->die();
  TP->move_player("/d/dagger/avalounge");
  TP->revive();
  TP->set_hp(TP->query_max_hp());
  write("You fake your death.");
    return 1;
}

int help(){
   write("Creates rope.");
   return 1;
}
