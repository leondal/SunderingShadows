#include <std.h>

inherit "/std/Object";

int num;

void create() {
  ::create();
  set_name("elektra");
  set_id(({"stick","elektra","wood"}));
  set_short("A mystical stick");
  set_long("This 1' length of solid oak, feels very lightweight.  "
    "Something looks like el add ek and trea minus e is carved on "
     "the wand. It does not make much sense to you.");
  set_weight(1);
  set_value(100);
  num = random(5) + 5;
}

void init() {
  ::init();
  add_action("elektra","elektra");
}

int elektra(string str) {
  string name;
  object ob;
    if(TP->query_bound() || TP->query_unconscious()){
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if(!query_wielded()) return notify_fail("Wield it first?\n");
  if(!str) {
    notify_fail("Who/What would you like to aim?\n");
    return 0;
  }
  if(num == 0) {
    write("The magical feeling of the wand fades away. It crumbles to dust.");
    say(TP->query_cap_name()+"'s wand crumbles to dust and fades away.");
    remove();
  }
  else if(TP->query_stats("intelligence") <= 9)
    return notify_fail("You cannot be so smart figuring this thing out!\n");
  else if(ob = present(str, ETP)){
  if(ob != TP){
    new("/cmds/spells/w/_web.c")->use_spell(TP,str,TP->query_max_level(),100,"mage");
    num--;
  }
  else return notify_fail("No not you!\n");
  }
  return 1;
}
