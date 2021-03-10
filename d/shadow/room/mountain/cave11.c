//cave11.c
#include <std.h>
#include "/d/shadow/room/mountain/echoes.h"

inherit ECHOES;

string *can_pass;

void create(){
    ::create();
    set_pre_exit_functions(({"north"}),({"go_north"}));
    set_exits(([
        "west" : ROOMS"cave10",
        "north" : ROOMS"cave12"
   	]));
    can_pass = ({});
}

void init() {
    ::init();
    add_action("say_fun","say");
}

void say_fun(string str) {
    if(!present("mountain dwarf")) return;
    if(!str) return;
    if(strsrch(str,"ogre") != -1 || strsrch(str,"help") != -1 || strsrch(str,"yes") != -1 || strsrch(str,"Yes") != -1) {
        if(member_array(TPQN,can_pass) == -1) {
            can_pass += ({TPQN});
        }
    }
}
        
int go_north() {
   if(TP->query_invis()) return 1;
  if(present("mountain dwarf")) {
      if(member_array(TPQN,can_pass) == -1) {
        tell_room(ETP,"%^MAGENTA%^The Dwarf says: %^RESET%^What business do you have here?  Do you want to help us fight the ogres?");
        return 0;
      }
      if(member_array(TPQN,can_pass) != -1) {
        tell_room(ETP,"%^MAGENTA%^The dwarf says:  %^RESET%^Alright, you can pass.");
        return 1;
      }
  }

  return 1;
}
/*
void reset() {
  ::reset();
  if(!present("mountain dwarf")) {
   if(sizeof(children(MOBS"dwarf")) < 10) 
     new(MOBS"dwarf")->move(TO);
  }
}
*/