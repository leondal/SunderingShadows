#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
#define STORE "/d/atoyatl/tecqumin/rooms/storage/tec_storage.c"

inherit ZIG_INT_BASE;

  int ped_height;
  int raise_pedestal();
  int lower_pedestal();
  int stable();

void create() {
  object store_room;
  ::create();
  ped_height = 2;
  store_room = find_object_or_load(STORE);
  store_room->reset();
  set_long(TO, "long_desc");
  set_short("A large, open musty chamber");
  set_smell("default","The dust of centuries clogs your nostrils.");
  set_listen("default","It is silent. Deathly silent.");
  set_items((["pedestal": (:TO, "view_pedestal" :),
              "dais":"The oval dais is approximately twenty feet in"
    +" length and twenty feet wide only about eight inches high. It"
    +" is constructed from the same stone blocks as the%^ORANGE%^"
    +" ziggurat%^RESET%^ is built from.",
         ({"hand holds", "foot holds"}):"These have been carved into"
    +" the stone walls, presumably as a means to ascend to the room"
    +" above." ]));
  setup_exits();
}


void setup_exits(){
  set_exits( ([ "south" : ROOMS + "tun01"]) );
  set_climb_exits((["climb":({ROOMS+"corridor4",6,6,100})]));
}

string long_desc(){
  object ped_obj, store_room;
  string desc;
  store_room = find_object_or_load(STORE);
  if (objectp(store_room)){
    ped_obj = store_room->query_head_obj();
  }
  desc = "You are in a long, narrow chamber. The walls are cut from"
    +" the same stone blocks that feature in the rest of the"
    +" %^ORANGE%^ziggurat's%^RESET%^ construction. To the south,"
    +" however, a stone arch opens up into what looks like a natural"
    +" earthen tunnel. At the far end, a low, oval dais rises from"
    +" the stone flagged floor. The ceiling is open above the dais,"
    +" and hand and foot holds have been cut into the eastern wall,"
    +" leading to the area above. A rough pedestal sits in the centre"
    +" of the dais.";
  if (objectp(ped_obj)){
    desc += " Displayed on the pedestal is a ";
    desc += ped_obj->query_short() + ".";
  }
  return desc;
}



void init() {
    ::init();
    add_action("replace_fun", "replace");
    add_action("take_fun", "take");
    add_action("take_fun", "get");
    add_action("take_fun", "remove");
    add_action("look_fun", "look");
    add_action("detect_fun", "trap");
    add_action("estimate_fun", "estimate");
}

void reset(){
  object ped_obj, store_room;
  ::reset();
  store_room = find_object_or_load(STORE);
  ped_obj = store_room->query_head_obj();
  if (!objectp(ped_obj)){
    store_room->make_new_head();
    ped_obj = store_room->query_head_obj();
  }
  if (!ped_obj->id("shrunken head")&& random(2)>0){
    ped_obj->remove();
    if (!present("shrunken head", find_object_or_load(STORE))){
      ped_obj = new(OBJ + "head.c");
      ped_obj->move(STORE);
    } else {
      ped_obj = present("shrunken head", find_object_or_load(STORE));
    }
  }
  setup_exits();
}

string view_pedestal(){
  string desc;
  object ped_obj, store_room;
  store_room = find_object_or_load(STORE);
  ped_obj = store_room->query_head_obj();
  switch(ped_height){
  case 1:
    desc = "The pedestal is raised just a few inches above the"
                     +" dais. It is built from blackened clay bricks.";
    break;
  case 2:
    desc = "The pedestal is about three feet high. It is"
                        +" built from blackened clay bricks.";
    break;
  case 3:
    desc = "The pedestal is just over three feet high. It is"
                        +" built from blackened clay bricks.";
    break;

  }
  if(objectp(ped_obj)){
    desc += " A%^BOLD%^%^BLACK%^"
    +" shrunken human head%^RESET%^ sits on top of it.";
  }
  return desc;
}

int detect_fun(string str){
  string action, obj;
  object ped_obj, store_room;
  int score;
//  tell_object(TP, "Starting detect fun\n");
  store_room = find_object_or_load(STORE);
  if (!objectp(store_room)){
//    tell_object(TP, "No store room found\n");
    return 0;
  }
  ped_obj = STORE->query_head_obj();
  sscanf(str, "%s on %s", action, obj);
  if (!objectp(ped_obj)){
//    tell_object(TP, "There's nothing on the pedestal. Nothing"
//      +" doing");
    return 0;
  }
  if (action == "find"){
   tell_object(TP, "Action confirmed as 'find'\n");
    if (obj == "pedestal" || ped_obj->id(obj)){
      score = TP->query_skill("dungeoneerning");
      if (score<5){
//    tell_object(TP, "Score less than 5\n");
        return 0;
      }
      if(score < roll_dice(1,60)) {
//    tell_object(TP, "You didn't make the roll\n");
         tell_object(TP, "%^BOLD%^You don't seem to find any traps"
           +" on the "+ obj);
         tell_room(TO, "%^BOLD%^" + TPQCN + " doesn't seem to find"
           +" any traps on the " + obj, TP);
         return 1;
      }
      tell_object(TP, "You find some vertical scratch marks around"
        +" the pedestal, which make you think it might move somehow."
        +" It's probably a trap, but there's no way to get to"
        +" whatever mechanism might be beneath the floor. Probably"
        +" your best bet is to replace the "      
        + ped_obj->query_short() + "%^RESET%^ with something"
        +" else, if you want to take it with you. It should be"
        +" something about the same weight, to avoid disturbing the"
        +" pedestal. You can 'estimate weight of <object>' if you"
        +" want to.");
      tell_room(TO,TPQCN+ " seems to find a trap on the " + obj, TP);
      return 1;
    }
  }
  return 0;
}

int estimate_fun(string str){
  string obj, stat;
  object ped_obj;
  int score, weight;
  ped_obj = find_object_or_load(STORE)->query_head_obj(); 
  if (!objectp(TP)||!objectp(ped_obj)){
    return 0;
  }
  weight = ped_obj->query_weight();
  score = TP->query_skill("dungeoneering");
  if (score < 10){
    return notify_fail("You don't really have the eye for that sort"
      +" of thing. It's not in your professional training. ");
  }
  if (score < 25){
    return notify_fail("You're really not sure how much it weighs."
    +" Perhaps someone with more experience with traps could help.");
  }
  if (sscanf(str, "%s of %s", stat, obj)<2){
    tell_object(TP, "Try 'estimate weight of <object>'");
    return 1;
  }
  if (stat != "weight"){
    tell_object(TP, "Try 'estimate weight of <object>'");
    return 1;
  }
  if (!ped_obj->id(obj)){
    tell_object(TP, "It won't help you to estimate the weight of"
      +" that!");
    return 1;
  }

  if(score < roll_dice(1,50)) {
    weight += random(4)-2;    
  }
  tell_object(TP, "You think it probably weighs about " + weight );
  return 1;
}

int look_fun(string str){
  object store_room, ped_obj;
  store_room = find_object_or_load(STORE);
  ped_obj = store_room->query_head_obj();
  if (!objectp(ped_obj)){
    return 0;
  }
  if (ped_obj->id(str)){
    tell_object(TP, ped_obj->query_long());
    return 1;
  }
  return 0;
}

int replace_fun(string str) {
    string item, item_two, preposition;
    object thing, ped_obj, store_room;
    int thing_weight, ped_obj_weight;
    store_room = find_object_or_load(STORE);
    ped_obj = store_room->query_head_obj();
    if (!objectp(ped_obj)){
        notify_fail("There's nothing on the pedestal to be replaced./n");
        return 0;
    }
    if(!str) {
        notify_fail("Replace what with what?\n");
        return 0;
    }
    sscanf(str, "%s %s %s", item, preposition, item_two);
    if (preposition != "with"){
      if (preposition == "head"){
        notify_fail("Try replace <something> %^BOLD%^%^YELLOW%^"
                    +"with%^RESET%^ <something>\n");
          return 0;
      }
        notify_fail("Replace what with what?\n");
        return 0;
    }
    if (!ped_obj->id(item)){
        notify_fail("That probably won't do much.\n");
        return 0;
    }
    thing = present(item_two, TP);
    if (!objectp(thing)){
        notify_fail("You don't have any " + item_two + "s with you./n");
        return 0;
    }
    thing_weight = thing->query_weight();
    ped_obj_weight = ped_obj->query_weight();
    tell_object(TP,"Balancing the " + thing->query_short() 
      + "%^RESET%^ carefully in one hand, you deftly use it to"
      +" replace"
                  +" the " + ped_obj->query_short() + "%^RESET%^ on the"
                  +" pedestal.");
    TP->set_paralyzed(2, "You are still busy swapping stuff over");

    tell_room(TO,"Balancing a " + thing->query_short() + "%^RESET%^"
              +" carefully in one hand, " + TPQCN + " deftly places it"
              +" onto the clay brick pedestal, in place of the "
              + ped_obj->query_short() + "%^RESET%^, which " + TP->QS 
              +" removes.",TP);
    thing->move(STORE);
    ped_obj->move(TP);
    ped_obj = thing;
    if (ped_height > 1){
      if (thing_weight > ped_obj_weight){
        call_out ("lower_pedestal",2);
        return 1;
      }
    }
    if (ped_height<3){
      if (thing_weight < ped_obj_weight){
        call_out("raise_pedestal",2);
        return 1;
      }
    }
    if (thing_weight == ped_obj_weight){
      call_out("stable",1);
      return 1;
    }
    return 0;
}

int take_fun(string str){
  object ped_obj, store_room;
  store_room = find_object_or_load(STORE);
  ped_obj = store_room->query_head_obj();
  if (!objectp(ped_obj)){
    return 0;
  }
  if (!present(str, TO) && ped_obj->id(str)){
    tell_object(TP,"Reaching out, you take the " + ped_obj->query_short()
                 + "%^RESET%^ from the pedestal.");
  
    tell_room(TO,"Reaching out, " + TPQCN + "%^RESET%^ takes the " 
                 + ped_obj->query_short() + "%^RESET%^ from the"
                 +" pedestal",TP);
    TP->set_paralyzed(2, "You are still busy grabbing the " + ped_obj->query_short());

    ped_obj->move(TP);
    ped_obj = 0;
    store_room->set_head_obj(ped_obj);
    call_out ("raise_pedestal",2);
    return 1;
  }
  return 0; 
}

int stable(){
  string desc;
  object ped_obj, store_room;
  store_room = find_object_or_load(STORE);
  ped_obj = store_room->query_head_obj();
  desc = "The pedestal is about three feet high. It is"
                        +" built from blackened clay bricks.";
  if (objectp(ped_obj)){
    desc += " A " + ped_obj->query_short() + "%^RESET%^ sits atop it.";
  }
  add_item("pedestal", desc );
  tell_room(TO, "The pedestal trembles for a moment, then stills.");
  return 1;
}

int lower_pedestal(){
  object ped_obj, store_room;
  store_room = find_object_or_load(STORE);
  ped_obj = store_room->query_head_obj();
  //PUT BAD THINGS TO HAPPEN HERE
  call_out("start_rolling", 1);
  ////////////////////////////
  tell_room(TO, "The pedestal trembles for a moment, then begins to sink"
               +" into the floor. Bad things may be about to happen.");
  tell_room(TO, "There is a loud rumbling sound from above. The way up is blocked.");
//  remove_exit("up");
  set_climb_exits(([]));
  ped_height --;
  if (ped_height <1){
    ped_height = 1;
  }
  return 1;
}

int raise_pedestal(){
  string desc;
  object ped_obj, store_room;
  store_room = find_object_or_load(STORE);
  ped_obj = store_room->query_head_obj();

  //PUT BAD THINGS TO HAPPEN HERE
  if (ped_height == 2){
    tell_room(TO, "The pedestal trembles for a moment, then rises"
               +" fractionally from the floor. There is a distinct"
               +" 'click'. This probably isn't good.");
  } else {
    tell_room(TO, "The pedestal trembles for a moment, then rises"
               +" from the floor, to just over 3 feet in height. There"
               +" is a distinct 'click'. This probably isn't good.");
  }
  tell_room(TO, "There is a loud rumbling sound from above. The way up is blocked.");
//  remove_exit("up");
  set_climb_exits(([]));
  call_out("start_rolling", 1);
  ped_height ++;
  if (ped_height > 3){ 
    ped_height = 3;
  } 
  return 1;
}

void start_rolling(){
  object ball, *victims;
  int i;
  tell_room(TO, "With an almighty CRASH, an ENORMOUS ball of stone"
    +" crashes through the opening above the dais. It lands with a"
    +" crunching and cracking of stone and starts rolling towards"
    +" you. Time to %^BOLD%^%^RED%^RUN SOUTH%^RESET%^, unless you"
    +" want to be turned into a slippery smear of adventurer-based"
    +" pate!");
  victims = all_living(TO);
  for (i=0;i<sizeof(victims);i++){
    if (interactive(victims[i])>0){
      victims[i]->set_paralyzed(5, "You are momentarily frozen with fear!"
                                  +" Get ready to run as soon as you"
                                  +" can!");
    }
  }
  ball = new (OBJ + "stoneball.c");
  ball->move(TO);
  ball->start_rolling();
}
