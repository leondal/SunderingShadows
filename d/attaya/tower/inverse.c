inherit "/std/room";

#include <std.h>
void create() {
     ::create();
     set_terrain(STONE_BUILDING);
     set_travel(PAVED_ROAD);
     set_light(2);
     set_indoors(1);
     set_property("no teleport",1);
     set_short("High Council Chamber of the Kinnesaruda");
      set_long("
    You enter a large ornate room.  Glittering red drapes line the walls and the ceiling is accented by gold and colored glass.  A long, shiny, black table stretches out before you.  Around it sit ten chairs and a remarkable silver throne.  
    The lighting here seems to vary in brightness and fluctuates from very bright to almost pitch black.  At the far end of the room, two large black obelisks stand on either side of a glowing portal.
%^BOLD%^%^BLUE%^A Mysterious Portal is here.
");
     set_smell("default", "%^BOLD%^A glowing symbol appears on the table for a moment, then fades away.\n");
}
void reset() {
  ::reset();
    if(!present("intruder"))
      new("d/attaya/mon/intruder")->move(this_object());
}
void init() {
  ::init();
  add_action("whistle", "whistle");
  add_action("enter", "enter");
}
int whistle(string str) {
  write("You whistle for backup.",TP);
       tell_room(TO,"As "+TPQCN+" whistles for backup "+TP->query_possessive()+" eyes concentrate on a spot on the floor nearby.",TP);
  write("You grin evilly as a dark figure begins to take shape.\n");
  say((string)this_player()->query_cap_name()+" grins to you evilly as a dark form begins to take shape.\n");
  this_player()->add_hp(-(random(5)));
        call_out("backup",1,TP);
  return 1;
}
void backup(object targ){
        object ob;
        if(objectp(targ)){
                if(present(targ->query_name())){
                        tell_room(TO,"The shadows congeal and begin to take the shape of a figure");
                        targ->add_attacker(TO);
                       targ->continue_attack();
                        tell_room(TO,"A dark warrior emerges from the shadows nearby!");
                       ob=new("/d/attaya/mon/uwarrior");
                        ob->move(TO);
                        ob->kill_ob(targ,1);
               }
          }
}

int enter(string str) {
  write("%^CYAN%^You enter the mysterious portal.\n");
  say((string)this_player()->query_cap_name()+" enters the mysterious portal.\n");
  this_player()->move_player("/d/attaya/firedock");
  return 1;
}

