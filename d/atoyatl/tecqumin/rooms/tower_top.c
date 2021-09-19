#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(SLICK_FLOOR);
  set_name("A wooden platform");
  set_short("A platform on the top of a wooden tower.");
  set_long( "%^ORANGE%^The %^RESET%^platform %^ORANGE%^extends out"
    +" from the top of the tower, beyond the width of the lowest"
    +" point. The instability of the whole structure is even more"
    +" obvious up here, as alarming creaks and groans reach your"
    +" ears and the floor moves under your feet." );
  set_items((["platform" : "The platform is wide enough for two"
    +" or three medium sized creatures to stand abreast. It is"
    +" secured to the four supporting struts of the tower, which"
    +" continue up to meet in a pair of A frames above your head."
    +" It extends out beyond the width of the tower, and sees to"
    +" invite you to jump.",
       ({"strut", "struts"}) : "The struts are not single poles,"
    +" but are made up of overlapping sets of branches lashed"
    +" together, making them less than reassuringly solid.",
        ]));
  set_smell("default","A fresh %^BOLD%^%^CYAN%^breeze%^RESET%^"
    +"%^ORANGE%^ reaches you from above the trees.");
  set_listen("default","The sounds of the jungle drift up to the"
   +" platorm.");
  set_climb_exits(([ "descend" : ({JUNG_ROOM6 + "bungee_room",2,0,100}), ]));  
}
void init() {
   ::init();
   add_action("jump", "jump");
   add_action("jump", "dive");
   add_action("jump", "leap");
}
string * query_anchor_points(){
  return ({"overhead crossbeam"});
}
int jump(string str){
  object bottom_room, midway;
  if (TP->query_paralyzed()){
    tell_object(TP, TP->query_paralyze_message());
    return 1;
  }
  if (str != "down" && str != "off platform" 
       && str != "off the platform"  && str != "off tower"
       && str != "off the tower"){
    tell_object(TP, "do you want to dive off the"
      +" platform?");
    return 1;
  }
  bottom_room = find_object_or_load(JUNG_ROOM + "bungee_room");
  tell_object(TP, "You %^CYAN%^dive%^RESET%^ from the top of the"
    +" tower, falling %^RED%^head first%^RESET%^ toward the"
    +" %^ORANGE%^ground");
  tell_room(TO, TPQCN + " %^CYAN%^dives%^RESET%^ from the top of"
    +" the tower, falling %^RED%^head first%^RESET%^ toward the"
    +" %^ORANGE%^ground", TP);
  if (objectp(bottom_room)){
    tell_room(bottom_room, TPQCN + " %^CYAN%^dives%^RESET%^ from"
    +" the top of the tower, falling %^RED%^head first%^RESET%^"
    +" toward the %^ORANGE%^ground", TP);
  }
  call_out("jump2", 1, TP); 
  midway = find_object_or_load(JUNG_ROOM + "midway");
  TP->move(midway);
  TP->set_paralyzed(10, "You are falling!");
  return 1;
}

void jump2(object ob){
  int hp, i, flag;
  object harness, harness2, wearer, bottom_room, vine; 
  if (!objectp(ob)) {return;}
  bottom_room = find_object_or_load(JUNG_ROOM + "bungee_room");
  if (objectp(bottom_room)){
    ob->move(bottom_room);
  }
  harness = present("bungee harness", ob);
  if (objectp(harness)){
    wearer = harness->query_worn();
    if (objectp(wearer)){
      vine = present("tethered vine", TO);
      if (objectp(vine)){
        harness2= vine->query_harness();
        flag = 1;
        if (harness2 != harness){
          flag = 0;
          for (i=2; i<10;i++){
            vine = present ("tethered vine " + i, TO);
            harness2= vine->query_harness();
            if (harness2 == harness){
              flag = 1;
              break;
            }
          }
        }
      }
      if (objectp(vine) && vine->query_anchor_point()!="none"){
        tell_object(ob, "Your %^GREEN%^h%^ORANGE%^a%^GREEN%^rn"
          +"%^ORANGE%^e%^GREEN%^ss%^RESET%^ catches your weight,"
          +" slowing you down just before you hit the %^ORANGE%^ground"
          +"%^RESET%^.");
        tell_room(TO, ob->QCN + "'s %^GREEN%^h%^ORANGE%^a%^GREEN%^rn"
          +"%^ORANGE%^e%^GREEN%^ss%^RESET%^ catches " + ob->QP 
          +" weight, slowing " + ob->QO + " down just before " + ob->QS 
          +" hit the %^ORANGE%^ground%^RESET%^.", ob);
        if (objectp(bottom_room)){
          tell_room(bottom_room, ob->QCN + "'s %^GREEN%^h%^ORANGE%^a"
            +"%^GREEN%^rn%^ORANGE%^e%^GREEN%^ss%^RESET%^ catches " 
            + ob->QP +" weight, slowing " + ob->QO + " down just before"
            +" " + ob->QS +" hit the %^ORANGE%^ground%^RESET%^.", ob);
          hp = ob->query_max_hp();
          hp = hp / 5;
          TO->cause_typed_damage(ob, ob->return_target_limb(), hp,
                                                       "bludgeoning");
          ob->add_attacker(TO);
          ob->continue_attack();
          if(objectp(ob)){
            ob->remove_attacker(TO);
            ob->remove_paralyzed();
            ob->move(TO);
            ob->force_me("descend");
          }
          return;  
        } 
      } else {
        tell_object(ob, "Your %^GREEN%^h%^ORANGE%^a%^GREEN%^rn"
          +"%^ORANGE%^e%^GREEN%^ss%^RESET%^ is not secured!");
      }
    } else {
      tell_object(ob, "You aren't wearing the harness, so it can't"
       +" save you!");
    }
  }
  tell_object(ob, "You %^BOLD%^%^RED%^crash%^RESET%^ into the"
    +" %^ORANGE%^ground%^RESET%^ with an agonising %^BOLD%^%^BLUE%^"
    +"thump%^RESET%^!");
  tell_room(TO, ob->QCN + " %^BOLD%^%^RED%^crashes%^RESET%^ into the"
    +" %^ORANGE%^ground%^RESET with an agonising %^BOLD%^%^BLUE%^"
    +"thump%^RESET%^!", ob);
  if (objectp(bottom_room)){
    tell_room(bottom_room, ob->QCN + " %^BOLD%^%^RED%^crashes"
      +"%^RESET%^ into the %^ORANGE%^ground%^RESET with an agonising"
      +" %^BOLD%^%^BLUE%^thump%^RESET%^!", ob);
  }
  hp = (int)ob->query_max_hp()/2;
  ob->cause_typed_damage(ob, ob->return_target_limb(), hp, "bludgeoning");
  ob->add_attacker(TO);
  ob->continue_attack();
  if(objectp(ob)){
    ob->remove_attacker(TO);  
    ob->remove_paralyzed();
    ob->move(TO);
    ob->force_me("descend");
  }
}
