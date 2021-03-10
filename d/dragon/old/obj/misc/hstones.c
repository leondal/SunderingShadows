#include <std.h>

inherit "/std/Object.c";

int use_it, use, num;

void create() {
  ::create();
  set_name("stone");
  set_id(({"stone","healing stone"}));
  set("short","A white stone");
  set("long","This looks like an ordinary stone.  The only difference is that\n"+
             "one of the sides is smoother than the other sides, as if, some\n"+
             "one has been rubbing it.");
  set_weight(1);
  set_value(20);
  num = 0;
  use = 5;
}

void init() {
  ::init();
  add_action("rub_it","rub");
}

int rub_it(string str) {
  int i;
  if(!str) {
    write("What are you tring to rub here?");
    return 1;
  }
  if(str != "stone") {
    write("You start rubbing "+str+" but nothing happens?");
    return 1;
  }
  if(num == 1) {
    write("%^GREEN%^The stone feels warm to the touch, like it's working already.");
    return 1;
  }
  write("%^GREEN%^You starting rubbing the stone.  The stone becomes warm to the touch.");
  call_out("do_heal", 40);
  num = 1;
  return 1;
}

void do_heal() {
  this_player()->add_hp(random(6));
  write("%^GREEN%^The stone becomes cool again.");
  num = 0;
  use -= 1;
  if(!use) {
    write("%^GREEN%^The stone become cold real quick, it doesnt seem to work anymore, and disapears.");
    remove();
    return 1;
  }
}
