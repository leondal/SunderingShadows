#include <std.h>
inherit OBJECT;
void init(){
  ::init();
  add_action("hurl","hurl");
}
void create(){
  ::create();
  set_id(({"pumpkin"}));
  set_name("flaming jack-o-lantern");
  set_short("%^BOLD%^RED%^flaming jack-o-lantern%^RESET%^");
  set_long(
  "  Its a large withered looking pumpkin with a demonic face carved in from which glows a hellish light."
  );
  set_weight(1);
  set_property("monsterweapon",1);
  set_value(1);
}
int hurl(string str){
  object ob;
  string who;
  if(!str) return notify_fail("Throw what?\n");
  if(sscanf(str,"at %s",who) !=1) return notify_fail("Wrong");
  if(!(ob= present(who,environment(TP)))) return notify_fail("That is not here!\n");
  tell_object(ob,"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" hurls a flaming pumpkin at you and it bursts into flaming chunks of pulp against your chest!");
  tell_object(ETO,"Correct");
  tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" hurls a flaming pumpkin at "+ob->query_cap_name()+" which explodes into flaming fragments as it hits him!!\n",({ob,ETO}));
  ob->do_damage("torso",roll_dice(5,10));
  if(!ETO->kill_ob(ob,0)) return 1;
  return 1;
  }
