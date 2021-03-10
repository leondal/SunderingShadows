#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(DECAYED_FLOOR);
  set_name("The upper floor of a ruined tower.");
  set_short("The upper floor of a ruined tower.");
  set_long( "This is the upper room of a ruined tower. Part of one"
    +" wall has collapsed, and there is no remaining ceiling."
    +" Instead, the branches of the %^GREEN%^j%^BOLD%^%^GREEN%^u"
    +"%^RESET%^%^GREEN%^ng%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^e"
    +" c%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^no%^BOLD%^%^GREEN%^p"
    +"%^RESET%^%^GREEN%^y %^RESET%^form a vaulted arch above you."
    +" The tower itself is of grey stone construction, but old and"
    +" ruined enough to not seem terribly sturdy or safe. The stones"
    +" have slipped against one another, and gaps and misalignments"
    +" are readily apparent. No trace of whatever the tower's"
    +" original function remains, but an acrid, musty smell and"
    +" various stains on the stonework suggest that something has"
    +" been using the tower as a toilet in more recent times.  In"
    +" one corner of the room there is a stairwell leading"
    +" downwards." );
  set_items(([({"wall", "walls", "stone", "stones"}) : "The walls of"
    +" the tower reall appear unsafe. One of them has already"
    +" collapsed, and most of the rest of them look like a good"
    +" shove could bring them down. Possibly not a good idea,"
    +" though.",
       ({"stairwell", "stairs", "stair"}) : "The stairwell in the"
   +" corner of the room leads downwards, but peering into it, you"
   +" can see that no stair remains. Indeed, no floor remains in"
   +" the next level down, just a pile of rubble on the floor at"
   +" the very bottom of the tower. It is quite a long way down,"
   +" but you could jump down the stairwell if you want.",
      ({"branches", "branch", "tree", "higurion", "higurion tree"}) : 
     "Branches of the %^ORANGE%^higurion%^RESET%^ tree poke in"
    +" through the windows and the collapsed wall and ceiling of the"
    +" tower. The branches are thick and sturdy, meaning it would"
    +" probably be possible to climb out into the tree." 
        ]));
  set_smell("default","It is a bit musty in the tower, but the heady"
    +" scents of the jungle still reach you here.");
  set_listen("default","The sounds of the jungle drift into the"
   +" tower.");
  set_climb_exits(([ "climb" : ({ROOMS + "tower",2,0,100}), ]));  
}
void init() {
   ::init();
   add_action("jump", "jump");
   add_action("shove", "shove");
}



int climb(){
  object tower;
  tell_object(TP, "With a fair amount of scraping and struggling,"
   +" you wriggle your way out through a lucky gap in the pile of"
   +" stones.");
  tell_room(TO, TPQCN +" struggles " + TP->QP + " up through a"
   +" small gap between the collapsed stones.", TP );
  tower = find_object_or_load(ROOMS + "tower");
  if (objectp(tower)){
    tell_room(tower , "A scraping noise draws your attention to"
      +" a small gap in the pile of stones. After a moment or two,"
      +" " + TPQCN + " emerges from the hole, brushing dust and"
      +" debris from " + TP->QO 
      +"self.", TP);
  }
  return 1;
}

void collapse(){
  set_long( "You are in a space in the middle of a collapsed pile of"
   +" stones and rubble. It's quite uncomfortable, but at least you"
   +" are not crushed and there is a little air to breathe. Some"
   +" light filters in from above you, and a gap in the stones"
   +" suggests that it may be possible to climb out." );
   remove_action("jump", "jump");
   remove_action("shove", "shove");
   remove_item(({"wall", "walls", "stone", "stones", "stairwell", 
     "stairs", "stair"}) );
//   set_pre_exit_functions(({"climb"}), ({ "climb"}));
}

int shove(string str){
  object tower;
  if (str != "wall" && str != "the wall") {
    return notify_fail("Do you want to shove the wall?");
  }
  tell_object(TP, "You give the wall a tentative shove. Perhaps not"
   +" tentative enough, though, as the stone you were pushing"
   +" against falls out and drops to the ground outside the tower.");
  tell_room(TO, TPQCN + " gives the wall a shove. Worryingly, the"
   +" stone " + TP->QS + " pushes falls out of the wall and drops to"
   +" the ground outside of the tower.", TP);
  tower = find_object_or_load(ROOMS + "tower");
  if (objectp(tower)){
    tell_room(tower, "A large stone falls suddenly from one of the"
     +" remaining upper walls of the tower, leaving a hole.");
  }
  call_out("shove2", 3);
  return 1;
}

void shove2(){
  object tower, ground_floor;
  tell_room(TO, " ");
  tell_room(TO, "The stones of the wall %^ORANGE%^creak%^RESET%^"
   +" alarmingly, and you can see them actually moving above the"
   +" hole that was left behind by the stone that just fell.");
  tower = find_object_or_load(ROOMS + "tower");
  ground_floor = find_object_or_load(ROOMS + "ground_floor");
  if (objectp(tower)){
    tell_room(tower, " ");
    tell_room(tower, "The stones of the tower %^ORANGE%^creak"
     +" %^RESET%^and %^CYAN%^groan%^RESET%^ alarmingly.");
  }
  if (objectp(ground_floor)){
    tell_room(ground_floor, " ");
    tell_room(ground_floor, "You hear an alarming %^BOLD%^"
      +"%^BLACK%^groaning%^RESET%^ sound from the stones"
      +" high above you.");
  }
  call_out("shove3", 4);
}
void shove3(){
  object tower, ground_floor;
  tell_room(TO, " ");
  tell_room(TO, "The stones %^ORANGE%^creak%^RESET%^ again, and you"
    +" think you see more movement.");
  tower = find_object_or_load(ROOMS + "tower");
  ground_floor = find_object_or_load(ROOMS + "ground_floor");
  if (objectp(tower)){
    tell_room(tower, " ");
    tell_room(tower, "There is another, quieter %^ORANGE%^creak"
      +"%^RESET%^ from the stones overhead");
  }
  if (objectp(ground_floor)){
    tell_room(ground_floor, " ");
    tell_room(ground_floor, "There is a second, quieter %^ORANGE%^"
      +"creak%^RESET%^ from above you.");
  }
  call_out("shove4", 3);
}


void shove4(){
  object tower, ground_floor;
  tell_room(TO, " ");
  tell_room(TO, "With a %^GREEN%^groan%^RESET%^, the stones of the"
    +" wall %^ORANGE%^collapse%^RESET%^ into the hole left behind by"
    +" the one that fell out, and then fall inwards onto the tower"
    +" floor");
  tower = find_object_or_load(ROOMS + "tower");
  ground_floor = find_object_or_load(ROOMS + "ground_floor");
  if (objectp(tower)){
    tell_room(tower, " ");
    tell_room(tower, "A %^ORANGE%^CRASH%^RESET%^ from above draws"
      +" your attention to one of the upper walls of the tower,"
      +" which has just crashed inward.");
  }
  if (objectp(ground_floor)){
    tell_room(ground_floor, " ");
    tell_room(ground_floor, "A loud series of %^ORANGE%^crashes"
      +" %^RESET%^and %^BOLD%^%^BLUE%^bangs%^RESET%^ from above"
      +" suggests that something very bad is about to happen to the"
      +" dangerously unstable tower. You can see the%^ORANGE%^"
      +" ceiling%^RESET%^ overhead %^CYAN%^tremble%^RESET%^ and"
      +" %^BOLD%^%^BLUE%^quake%^RESET%^. ");
  }
  call_out("shove5", 3);
}

void shove5(){
  int i, num, hp;
  object tower, ground_floor, * critters, ob;
  tell_room(TO, " ");
  tell_room(TO, "With a final %^ORANGE%^creak%^RESET%^, the floor of"
    +" the tower gives way, sending you %^BOLD%^%^BLUE%^tumbling"
    +" %^RESET%^to the ground in the middle of a mass of %^CYAN%^"
    +"falling masonry%^RESET%^.");
  tell_room(TO, "You hit your head, hard, and everything goes"
   +"%^BOLD%^%^BLACK%^dark%^RESET%^.");
  tower = find_object_or_load(ROOMS + "tower");
  ground_floor = find_object_or_load(ROOMS + "ground_floor");
  if (objectp(tower)){
    tell_room(tower, " ");
    tell_room(tower, "A series of loud %^BOLD%^%^BLUE%^bangs"
      +" %^RESET%^and %^ORANGE%^crashes%^RESET%^ come from the tower"
      +", which eventually collapses inward in a great cloud of"
      +" %^BOLD%^%^WHITE%^dust%^RESET%^ and %^ORANGE%^broken masonry"
      +"%^RESET%^. When the dust clears, all that remains is a mass"
      +" of rubble.");
  }
  if (objectp(ground_floor)){
    tell_room(ground_floor, " ");
    tell_room(ground_floor, "With fearful inevitability, and a lot"
      +" of very loud noise, the %^ORANGE%^ceiling%^RESET%^ falls on"
      +" your head from two stories up, followed by the%^ORANGE%^"
      +" stones%^RESET%^ of the rest of the tower as it %^BOLD%^"
      +"%^BLUE%^collapses%^RESET%^ inward on top of you. You are"
      +" left with a vision of a mass of %^CYAN%^falling masonry"
      +"%^RESET%^ heading toward you at high speed, then"
      +" everything goes %^BOLD%^%^BLACK%^dark%^RESET%^.");
  }
  critters = all_living(TO);
  if (objectp(ground_floor)){
    critters += all_living(ground_floor);
  }
  num = sizeof(critters);
  if (num <1) { return;}
  for (i=0;i<num;i++){
    ob = critters[i];
    ob->set_hp(-10);
    ob->set_unconscious(5);
  }
  collapse();
  if (objectp(tower)){
    tower->collapse();
  }
  if (objectp(ground_floor)){
    ground_floor->collapse();
  }
}


int jump(string str){
  if (str != "down" && str != "into stairwell" 
       && str != "down stairwell"  && str != "down the stairwell"
       && str != "down stairs"){
    return notify_fail("do you want to jump down the stairwell?");
  }
  tell_object(TP, "Hoping for the best, you jump down into the open"
   +" stairwell");
  tell_room(TO, TPQCN + " takes a breath and leaps into the open"
    +" stairwell", TP);
  call_out("jump2", 2, TP); 
  TP->move(ROOMS + "ground_floor");
  return 1;
}

void jump2(object ob){
  int hp;
  if (!objectp(ob)) {return;}
  tell_object(ob, "You hit the ground with an agonising thump!");
  hp = (int)ob->query_max_hp()/4;
  ob->do_damage(ob->return_target_limb(),hp + random(hp));
  ob->add_attacker(TO);
  ob->continue_attack();
  if(objectp(ob))    ob->remove_attacker(TO);  
}