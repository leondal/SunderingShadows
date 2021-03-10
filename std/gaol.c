#include <std.h>

inherit VAULT ;
mapping prisoners = ([ ]) ;
void SAVE() {
  save_me(base_name(TO));
}
void RESTORE() {
  restore_me(base_name(TO));
 if(prisoners == 0) prisoners = ([ ]);
}
void create() {
  ::create();
  if ("/std/gaol" == base_name(TO)) return;
  RESTORE();
  SAVE();
}

void init() {
  if (member_array(TPQN,keys(prisoners)) != -1) {
    TP->set_bound(prisoners[TPQN]);
   add_action("pre_quit","quit");
    return;
  }
  add_action("release_prisoner","release");
  add_action("lockup_prisoner","lockup");
}
