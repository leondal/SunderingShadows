#include <std.h>
inherit ROOM;
void create(){
  ::create();
  set_name("purple worms stomach");
  set_property("light",-10);
  set_property("indoors",1);
  set_property("no teleport",1);
  set_property("no attack",1);
  set_short("Purple worms stomach");
  set_long("Purple worms stomach");
  set_exits(([]));
  set_items(([]));
  set_smell("default","The acid burns at your mouth and lungs!");
  set_listen("default","You scream in hopes someone can kill this thing and let you out!");
  set_heart_beat(8);
  set_property("continue heartbeat",1);
}
void heart_beat(){
  object *acid;
  int i,j;
  ::heart_beat();
  acid=all_living(TO);
  j=sizeof(acid);
  for(i=0;i<j;i++){
  tell_object(acid[i],"%^RESET%^%^GREEN%^The acid burns at you!");
  acid[i]->do_damage(acid[i]->return_target_limb(),5);
  acid[i]->add_attacker(TO);
  acid[i]->continue_attack();
  }
}
