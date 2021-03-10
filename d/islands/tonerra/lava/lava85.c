#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit LAVAH;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  set_short("Cave in site");
  set_long(
@DESC
   %^BOLD%^%^RED%^A Cave in of some sort%^RESET%^
This room is empty. The wall to the east is covered with a
pile of rubble. You think it might be a cave in of some form.
The feeling of lava is less here, possibly you farther from
the lava flow then you thought.
DESC
  );
  set_items(([
   "rubble":"You think this is a cave in until you inspect the ceiling. There is no sign of this rubble coming from the ceiling of this cavern. Someone moved this rubble here. Why?",
   "pile":"Its made of a ton of rubble, or maybe 2 or 3",
   ]));
  
  
  set_exits(([
    "northwest":LAVA+"lava84",
    "southwest":LAVA+"lava86"
  ]));
}

int rubble = 50;

void init(){
   ::init();

   add_action("move_rub","move");
}

int move_rub(string str){
   if(!str || str != "rubble")
      return notify_fail("Move What?\n");

   tell_room(TO,"%^BOLD%^"+TPQCN+" starts to move the rubble.",TP);
   write("You start to move the rubble.");
   rubble--;
   call_out("moving",1,TP);
   return 1;
}

void moving(object ob){
   if(!objectp(ob) || !present(ob) || rubble == 50)
      return;
   if(rubble < 1){
      tell_room(TO,"At last the rubble is moved.");
      tell_room(TO,"%^BOLD%^You see a silver ring on the ground.");
      tell_room(TO,"%^BOLD%^Magically the cave in return to its previous form, leaving the ring however.");
      rubble = 50;
      new(OBJ+"ring3")->move(TO);
      return;
   }
   tell_room(TO,"%^BOLD%^"+ob->query_cap_name()+" moves some more rubble, and could probably use help.",ob);
   write("You move more rubble, wish you had some help?");
   rubble--;
   if(!random(4)){
      tell_room(TO,"%^RED%^"+ob->query_cap_name()+" seems to hurt "+ob->QP+" back moving a large boulder.",ob);
      tell_object(ob, "You hurt your back moving a large boulder.");
      ob->do_damage("torso",roll_dice(2,10));
   }

   call_out("moving",1,ob);
}
