#include <std.h>


int cmd_racetoggle(string str) {
  string * old_id_list;
  
  if (!stringp(str)) {
    return notify_fail("You need to specify <on> or <off>.\n");
  }
  if (lower_case(str) == "on") {
    if (TP->id(TP->query_race())) {
      write("You already have your race as an ID.\n");
      return 1;
    } else {
      TP->add_id(TP->query_race());
      write("Race "+TP->query_race()+" added to your ID listing.");
      return 1;
    }
  } else if (lower_case(str) == "off") {
    if (TP->id(TP->query_race())) {
      old_id_list = (string *)TP->query_id();
      old_id_list -= ({ (string)TP->query_race() }) ;
      TP->set_id(old_id_list);
      write("Race "+TP->query_race()+" removed from your ID listing.");
      return 1;
      
    } else {
      write("You don't need to get your race removed from your ID listing!");
      return 1;
    }
    
  }
}

int help() {
  write("racetoggle on adds your race to your list of ID's.");
  write("racetoggle off removes your race from your list of ID's.");
  write("Your ID list is reset on logging in or charswitching over to the new character.");
  return 1;
}
