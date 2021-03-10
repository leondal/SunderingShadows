#include <std.h>
#include "/d/dagger/Torm/tormdefs.h";
inherit OBJECT;
object ob;
  int done;
  object *heat;
  int i,j;
void create(){
  ::create();
  set_name("rubble");
  set_id(({"rubble","debris",
  "pile","pile of rubble",
  }));
  set_short("A pile of rubble");
  set_long(
  "  This is a small pile of smashed mechanical parts."  
  "  A gear slowly dances on the end of a twisted spring that juts from the greasy pile of parts."
  "  All of the pieces seem to have been smashed into rubble, reforged and smashed again."
  );
  set_weight(500);
  set("value",200);
  set_property("no animate",1);
}
void init(){
  ::init();
  if(done) return 1;
  call_out("smoke1",1,ETO);
  done=1;
  call_out("smoke2",6,ETO);
  call_out("smoke2",12,ETO);
  call_out("explode",15,ETO);
  }
int smoke1(){
  tell_room(ETO,"%^BOLD%^%^BLUE%^The rubble starts to smoke.");
  }
int smoke2(){
  tell_room(ETO,"%^BOLD%^%^BLUE%^The smoke from the rubble begins to hurt your lungs.");
}
  int explode(){
  tell_room(ETO,"Suddenly a spark catches and a %^RED%^explosion%^RESET%^ rocks the room as the pile of rubble detonates.");
  TO->set_name("exploding pile of rubble");
  TO->set_property("magic",1);
  heat=all_living(ETO);
  j=sizeof(heat);
  for(i=0;i<j;i++){
  heat[i]->do_damage("torso",random(50)+1);
  heat[i]->add_attacker(TO);
  heat[i]->continue_attack();
   }
  TO->remove();
}
