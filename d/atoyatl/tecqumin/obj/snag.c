//Coded by Lujke

#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("snag");
    set_id( ({"xxsnagxx"}) );
    set_short("");
    set_obvious_short("");
    set_weight(0);
    set_long("");
}

void init(){
  ::init();
//  add_action("move_fun", "north");
//  add_action("move_fun", "northeast");
//  add_action("move_fun", "east");
//  add_action("move_fun", "southeast");
//  add_action("move_fun", "south");
//  add_action("move_fun", "southwest");
//  add_action("move_fun", "west");
//  add_action("move_fun", "northwest");
//  add_action("move_fun", "down"); 
   call_out("dest_effect", 2);
}

dest_effect(){
  remove();
}

int move_fun(){
  if (!objectp(TP) || TP->query_true_invis()){ 
    return 0;
  }
  if (!objectp(ETP)){
    return 0;
  }
  if (!objectp(EETO) || EETO->is_clear()){
    return 0;
  }
  tell_object(TP, "%^ORANGE%^Your foot snags on one of the tangled roots"
                 +" on the floor and you trip!%^RESET%^");
  tell_room(ETP, "%^ORANGE%^" +TPQCN + "%^RESET%^%^ORANGE%^ trips and"
                +" falls!%^RESET%^", TP);
  TP->set_tripped(2,"You are trying to stand!");
  call_out("dest_effect",1+ random(2));
  return 1;
}

