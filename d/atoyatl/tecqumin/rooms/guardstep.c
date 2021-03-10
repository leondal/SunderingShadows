#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"

inherit STEP_LOW;

void add_monsters();
object has_sacrifice(object ob);
void take_sacrifice();
void take_sacrifice2(object ghost, object sacrifice);
void take_sacrifice3(object ghost, object sacrifice);
void take_sacrifice4();

int sacrifice_made;

void create() {
  ::create();
  sacrifice_made = 0;
  set_pre_exit_functions(({"up",}),({"go_up",}));
}

void init(){
  ::init();
  call_out("take_sacrifice", 1); // made this a call_out, to 
                                 // make sure any dragged player is in the 
                                 // room by the time it is called.
}

void take_sacrifice(){
// checks for a 'sacrifice' (any dragged captive), takes it from whoever
// is dragging it, then allows the party a set time to pass by.
  int i;
  object ghost, carrier, sacrifice;
  if (!objectp(TO)){
    return;
  }
  ghost = present("ghost warrior", TO);
  if (!objectp(ghost)){
//    tell_room(TO, "There is no ghost here");
    return;
  }
  if (sizeof(all_living(TO))>0){
    for (i=0;i<sizeof(all_living(TO));i++){
      carrier = all_living(TO)[i];
      if (objectp(carrier)&& !carrier->id("ghost")){
//       tell_room(TO, "Checking for sacrifices on " + carrier->QCN);
        sacrifice = has_sacrifice(carrier);
        if (objectp(sacrifice)){
//         tell_room(TO, "Found a sacrifice");
          ghost->force_me("say %^BOLD%^%^CYAN%^Another sacrifice! The"
                        " %^WHITE%^gods %^BOLD%^%^CYAN%^will be appeased"
                       +" and their favour will shine upon the"
                       +"homes of the%^RESET%^%^ORANGE%^ Tecqumin%^BOLD%^"
                       +"%^CYAN%^!");
          tell_object(carrier, "%^CYAN%^The %^BOLD%^"
                                     +"%^WHITE%^ghost%^RESET%^%^CYAN%^"
                                     +" reaches out with insubstantial"
                                     +" hands and takes the captive from"
                                     +" your grasp!");
          tell_room(TO, "%^CYAN%^The %^BOLD%^%^WHITE%^ghost%^RESET%^"
                      +"%^CYAN%^ reaches out with insubstantial hands and"
                      +" takes the captive from" + carrier->QCN
                      +"'s grasp!", carrier);
          all_living(TO)[i]->force_me("drop " + sacrifice->query_race());
          ghost->drag_me(sacrifice);
          call_out("take_sacrifice2",4, ghost, sacrifice);
          return;
        }
      }
    }
  }
}

void take_sacrifice2(object ghost, object sacrifice){
  if (objectp(ghost)&&present(ghost, TO)){
    if (!objectp(sacrifice)){
      return;
    }
    ghost->force_me("say %^BOLD%^%^CYAN%^You may continue on your path,"
                   +" pilgrims. Your sacrifice will be delivered to the"
                   +"%^BOLD%^%^WHITE%^ gods %^CYAN%^and will serve to"
                   +" escort the Sun in his travels across the sky after"
                   +" experiencing the glory of the flowery death.");
    ghost->force_me("say %^BOLD%^%^CYAN%^Pass quickly, though. The"
                   +" %^BOLD%^%^WHITE%^gods%^BOLD%^%^CYAN%^ do not like"
                   +" to be kept waiting.");
    sacrifice_made = 1;
  }
  call_out ("take_sacrifice3", 2, ghost, sacrifice);
}

void take_sacrifice3(object ghost, object sacrifice){
  if (objectp(ghost)&&present(ghost, TO)){
    if (!objectp(sacrifice)){
      return;
    }
  }
  if (present(ghost)){
    ghost->start_walking("/realms/lujke/tecqumin/rooms/zigzenith"); 
  }
  call_out ("take_sacrifice4", 18);
}


void take_sacrifice4(){
  sacrifice_made = 0;

}

object has_sacrifice(object ob){
  string * words, name;
  object * inv, dragthing, sacrifice, * critters;
  int i,j;
  if (!objectp(ob)){
    return 0;
  }
  inv= all_inventory(ob);
  if (sizeof(inv)<1){
    return 0;
  }
  for (i=0;i<sizeof(inv);i++){
//    tell_room(TO, "Checking whether " + inv[i]->query_short() 
//              + " is interactive");
    if (interact("Dragging",inv[i]->query_short())){
      dragthing = inv[i];
//    tell_room(TO, inv[i]->query_short() + " is being dragged");
      critters = all_living(TO);
      words = explode(dragthing->query_short(), " ");
      name = words[1][0..strlen(words[1])-2];
//    tell_room(TO, name +" will be the sacrifice");
      sacrifice = present(name, TO);
      if (objectp(sacrifice)){
        return sacrifice;
      }
    }
  }
  return 0;
}

int go_up(string str){
  object ghost, ob;
  int i;
  ghost = present("ghost warrior", TO);
  if (objectp(ghost)&& !TP->id("ghost")&&!TP->query_true_invis()){
      if (TP->id("unfettered")){
        ghost->force_me("emote cringes and stands aside in awe as the"
          +" %^MAGENTA%^U%^BLUE%^nf%^MAGENTA%^e%^BLUE%^tt%^MAGENTA%^e"
          +"%^BLUE%^r%^MAGENTA%^e%^BLUE%^d%^RESET%^ makes its way up"
          +" the steps");
        return 1;
      }

      switch (sacrifice_made){
      case 0:
        ghost->force_me("say %^BOLD%^%^CYAN%^None may ascend to the hall"
                       +" of the gods without bearing sacrifice!");
        sacrifice_made -= 1;
        return 0;
        break;
      case 1:
        tell_object(TP, "%^CYAN%^The " +ghost->QCN + " %^CYAN%^stands"
                       +" aside to let you pass");
        tell_room(TO, "%^CYAN%^The " +ghost->QCN + " %^RESET%^"
                      +"%^CYAN%^stands aside to let " + TPQCN 
                      + "%^RESET%^%^CYAN%^ pass", TP);
        return 1;
        break;
      case -1:
        // if a warning has already been given recently,
        // force all ghosts present in the room to attack the person#
        // trying to walk upwards

        ghost->force_me("say %^BOLD%^%^CYAN%^You have been told you may"
                       +" not pass! Now you shall be a %^RESET%^"
                       +"%^RED%^sacrifice%^BOLD%^%^CYAN%^ yourself!");
        for(i=0;i<sizeof(all_living(TO));i++){
          if (all_living(TO)[i]->id("ghost")){
            all_living(TO)[i]->force_me("kill " + TP->query_name());
            }
        }
        sacrifice_made = 0;
        return 0;
        break;
      }
  }else{
    return 1;
  }
}

