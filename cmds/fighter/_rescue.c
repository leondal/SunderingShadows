// /cmds/fighter/_rescue.c

#include <std.h>
inherit DAEMON;

int cmd_rescue(string str) {
  object ob;
  object target;
  object *attack_list;
  object *new_attack_list;
  int x;
  
  if(!str) {
    write("You must specify a person to rescue.");
    return 1;
  }
  if(!TP->is_class("fighter")) {
    write("You are not a fighter and cannot do that!");
    return 1;
  }
  ob = present(str,ETP);
  if(!ob) {
    write("That is not here!");
    return 1;
  }
  if(!living(ob)) {
    write("That is not a living being!");
    return 1;
  }
// Saide added exclusion, 12/24/03, last change 7/20/98
  if(ob == TP) {
    write("You can't rescue yourself!");
    return 1;
  }
// adding to exclude disabled or blinded *Styx* 12/24/03
  if(TP->query_bound() || TP->query_tripped() || TP->query_paralyzed()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
  }
  if(TP->query_blind())
      return notify_fail("You can't see well enough to rescue someone else!\n");

  target = ob->query_current_attacker();
  if(!target) {
    write("Nobody is attacking "+ob->query_cap_name()+"!");
    return 1;
  }
  write("You deftly run in front of "+ob->query_cap_name()+".");
// changed from say to tell_room *Styx* 12/24/03, last change 7/20/98
  tell_room(ETP, TPQCN+" bravely runs in front of "+ob->query_cap_name()+".", TP);
  attack_list = target->query_attackers();
  new_attack_list = allocate(sizeof(attack_list)+1);
  for(x = 0; x < sizeof(attack_list); x++)
    new_attack_list[x+1] = attack_list[x];
  new_attack_list[0] = TP;
  target->set_attackers(new_attack_list);
  TP->use_stamina(5);  // added to use some stamina too *Styx*  12/24/03
  return 1;
}
                                                                                
void help() {
  write("Syntax: <rescue (player)>");
  write("  This command will cause you to take the hits from the first");
  write("attacker on the one you rescue's attacker list.");
}
