
#include <std.h>

inherit "/std/room";

int x;
string array;

void init(){
  int i, flag;
  if(((string)TP->query_property("strength") == "fire")) {
    write("The warmth of the Plane of fire doesn't affect you!");
    return 1;
  }
  array = TP->all_armour();
  for(x=0;x=sizeof(array);x++) {
    if((string)array[x]->query_type() != "ring") {
      flag = 1;
      break;
    }
  }
  if(flag) {
    write("The warmth of the Plane of fire causes you to sweat profusely.");
    TP->do_damage("torso", random(10));
    TP->add_attacker(TO);
    TP->continue_attack();
  }
}
