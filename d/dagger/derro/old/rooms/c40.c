#include <std.h>
#include "../derrodefs.h"
inherit ROOM;

void create(){
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(LEDGE);
  set_property("no teleport",1);
  set_property("light",2);
  set_name("lava pit");
  set_property("indoors",1);
  set_short("%^RED%^Bottom of the shaft%^RESET%^");
  set_long(
  "%^RED%^Bottom of the shaft%^RESET%^\n"
  "  You stand on a narrow ledge around a pit of lava.   The heat here is cooking you."
  "  A long shaft leads up here to a two holes in the ceiling and a natural lava pathway leads northeast."
  "  The walls here are glassy and smooth while the flow crumbles in places around the edge of the ledge where a fall any further would be certain death."
  );
  set_smell("default","Your clothes start to catch fire!");
  set_listen("default","The heat burns you!");
  set_items(([
  "lava":"Boiling red hot molten metal and earth.   It's going to kill you.",
  "shaft":"Leads up to two small holes far above you.  The walls are slick here but seem to get craggier and more crumbled as you get higher up.",
  "ledge":"A narrow walkway leads around a circular bed of lava.  The edges of it are crumbling into the seething mass below and you wonder how safe it is?",
  "walls":"The walls are slick here but seem to get craggier and crumbled as you get higher up.",
  ]));
  set_exits(([
  "northeast":ROOMS"c41",
  "northwest":ROOMS"c42",
  "up":ROOMS"c39",
  ]));
  set_heart_beat(3);
  set_property("continue heartbeat",1);
  
}

void heart_beat(){
  object *heat;
  int i, j;
  ::heart_beat();
  heat=all_living(TO);
  j=sizeof(heat);
  for(i=0;i<j;i++){
  if(!objectp(heat[i])) { continue; }
  if(heat[i]->query_true_invis())  continue;
  tell_object(heat[i],"%^BOLD%^%^RED%^The heat sears you!");
  heat[i]->do_damage(heat[i]->return_target_limb(),20);
  heat[i]->add_attacker(TO);
  heat[i]->continue_attack();
  if(objectp(heat[i])) { heat[i]->remove_attacker(TO); }
  }
}
