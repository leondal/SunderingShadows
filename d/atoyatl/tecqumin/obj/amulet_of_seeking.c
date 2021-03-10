#include <std.h>
#include "../tecqumin.h"
inherit OBJ + "far_scanner3.c";

int last_used;

create(){
  ::create();
  set_name("amulet");
  set_id(({"amulet","scanner", "amulet of scanning", "amulet of seeking"}));
  set_obvious_short("an amulet of clay");
  set_short("Amulet of seeking");
  set_long("A leather thong has been looped through a hole in the top of a"
          +" rectangular clay tablet, to form an amulet. On the face of the"
          +" amulet, some unusual looking cuneiform runes have been raised"
          +" above the flat surface, and enclosed within a raised border."
          +" The back of the amulet has some more recent looking writing"
          +" scratched on the back."); 
  set_weight(5);
  set_read("(The writing is scratchy and worn, having the appearance of"
          +" having been scratched into the clay long after the amulet was"
          +" made) %^ORANGE%^...use amule.. call ancestors.. scan ... what"
          +" xxx seek%^RESET%^");
  set_value(20000);
  last_used = 0;
}

void init(){
  ::init();
  add_action("scan_area", "scan");
  add_action("find_all", "find");
}

int scan_area2(string str, object holder){
  string * path, *finalpath, directions, usermessage, envmessage;
  int i, item_score, holder_score;
  object item, startroom, itemenv, * rooms;
  path = ({});
  rooms = ({});
  if (!objectp(holder)){
    return 0;
  }
  startroom = environment(holder);
  usermessage = "nothing to see";
  if (!objectp(startroom)){
    notify_fail("ERROR - you are in an invalid environment."
                       +" Please tell a WIZ");
    return 0;
  }
  holder->set_paralyzed(0);
  if (holder != ETO){
    tell_object(holder, "You cannot complete your search, as you no longer"
                       +" have the amulet");
    tell_room(startroom, "%^CYAN%^" + holder->QCN + "%^RESET%^%^CYAN%^"
                        +" opens " + holder->QP + " eyes and looks around"
                        +" as " + holder->QS + " emerges from " + holder->QP 
                        +" trance.", holder);
    return 1;
  }
  startroom = environment(holder);
  item = present(str, startroom);
  if (!objectp(item)){
    tell_object(holder, "You can't detect a " + str + " anywhere round"
                       +" here");
    tell_room(startroom, "%^CYAN%^" + holder->QCN + "%^RESET%^%^CYAN%^"
                        +" opens " + holder->QP + " eyes and looks around"
                        +" as " + holder->QS + " emerges from " + holder->QP 
                        +" trance.", holder);
    return 1;
  }


  if (objectp(item)){ 
    usermessage= "%^CYAN%^The spirits take you briefly out of your body, and"
            +" you see a vision of the room you are standing in, with a "
                +"%^RESET%^" + item->query_name()+ "%^RESET%^%^CYAN%^ right"
                +" there.%^RESET%^";
    envmessage = "%^CYAN%^" + holder->QCN + "%^RESET%^%^CYAN%^ opens "
               + holder->QP + " eyes and looks around as " + holder->QS 
               + " emerges from " + holder->QP + " trance.";
  } else {
    item = far_present(startroom , str, 5);
    if (objectp(item)){
      itemenv = environment(item);
    } 
    if (objectp(item) && !objectp(itemenv)){
      notify_fail("ERROR - the item is in an invalid environment."
                         +" Please tell a WIZ");
      return 0;
    }
    usermessage = "%^CYAN%^The spirits take your mind's eye way over to"
                     +" a place that looks like " + itemenv->query_short() 
                     +"%^RESET%^%^CYAN%^ You can see a "+ item->query_name() 
                     +"%^RESET%^%^CYAN%^ there."; 
  }

  tell_object(holder, usermessage );
    tell_room(startroom, envmessage, holder);
  if (interactive(item)){
    item_score = (int)item->query_highest_level()* 
                                            (random(50)+random(50))/100;
    holder_score = (int)item->query_highest_level()* 
                                            (random(50)+random(50))/75;
    if (item_score>=holder_score){
      switch(random(5)){
      case 0:
        tell_object(item, "You feel a faint %^CYAN%^chill%^RESET%^, and"
                         +" the hairs stand up on the back of your neck.");
        break;
      case 1:
        tell_object(item, "A whisper of a breeze passes by.");
        break;
      case 2:
        tell_object(item, "You have an uneasy feeling.");
        break;
      case 3:
        tell_object(item, "A bird nearby takes to the air in alarm.");
        break;
      case 4:
        tell_object(item, "You catch a movemment in the corner of your"
                         +" eye.");
        break;
      }
    }
  }
  if (objectp(environment(holder))&&objectp(environment(item))&& environment(holder)!=environment(item)){
    path = findpath(environment(holder), environment(item), path, finalpath, rooms, 5,1);
    if (sizeof(path)>0){
      directions = path [0];
      if (sizeof(path)>1){
        for (i = 1;i<sizeof(path);i++){
          directions += ", " + path[i];
        }
      }
      directions += "%^RESET%^.";
      tell_object(holder, "You sense that you can get to it by going"
                         +" %^CYAN%^" + directions + ".");
    }
  }
  return 1;
}

int query_last_used(){
  return last_used;
}


int scan_area(string str){
  object holder, env;
  holder = ETO;
  env = EETO;
  if (!objectp (holder) || !interactive(holder)){
    return 0;
  }
  if (!str){
    tell_object(holder, "Try %^BOLD%^%^YELLOW%^scan <item>%^RESET%^");
    return 1;
  }
  if (!objectp(env)){
    tell_object(holder, "you are in an invalid environment. Hold your"
                       +" breath, cross your fingers and please tell a Wiz."
                       +" You can tell them your amulet said so. Lujke");
  }
  if (last_used > time() - 90){
    tell_object(holder, "%^CYAN%^You close your eyes, but you cannot feel"
                       +" any contact from the %^RESET%^spirits%^CYAN%^."
                       +" Perhaps they are not yet ready to search for"
                       +" you.");
    tell_room(env, "%^CYAN%^" + holder->QCN + "%^RESET%^%^CYAN%^"
                        +" places " + holder->QP + " hand over "+ holder->QP
                        +" amulet and closes " + holder->QP + " eyes, but"
                        +" then opens them again, looking slightly"
                        +" disoriented.", holder);
    return 1;   
  }
  last_used = time();
  tell_object(holder, "%^CYAN%^Placing your hand over the amulet, you close"
                     +" your eyes and feel your mind drift outwards,"
                     +" carried by the spirits of long dead ancestors");
  tell_room(env, "%^CYAN%^" + holder->QCN + "%^RESET%^%^CYAN%^ places " 
                + holder->QP + " hand over " + holder->QP + " amulet and"
                +" closes " + holder->QP + " eyes, appearing to go into"
                +" some form of trance", holder);
  holder->set_paralyzed(30, "%^CYAN%^Your thoughts are travelling with the"
                            " spirits");
  call_out("scan_area2", 4+ random(2), str, holder);
  return 1;
}
