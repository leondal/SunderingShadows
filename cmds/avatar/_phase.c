#include <move.h>
#include <std.h>
inherit DAEMON;
int cmd_phase(string str){
  string where, *exits,dest_name;
  object dest;

  if(!str){
    notify_fail("Phase where?\n");
    return 0;
  }
  if(sscanf(str, "%s",where)!= 1){
    notify_fail("Care to try again?\n");
    return 0;
  }
  exits = environment(TP)->query_exits();
  if(member_array(where, exits) == -1){
    notify_fail("You can't phase without an exit.\n");
    return 0;
  }                                                                       
  dest_name = environment(TP)->query_exit(where);
  dest = find_object_or_load(dest_name);
  TP->move_player(dest);

  return 1;
}
void help() {
   write("Syntax: phase <exit>\n\n"
         "This will slip you through a door or exit without worrying about\n"
         "any doors or rubble or things of that nature between you and where\n"
         "you wish to go.\n"
        );
}
