#include <std.h>
#include "../tecqumin.h"
#define KAYAK "/d/atoyatl/tecqumin/rooms/canoe"
inherit OBJECT;         

create(){
  ::create();
  set_name("canoe paddle");
  set_id(({"paddle","canoe paddle","leaf shaped paddle"}));
  set_short("leaf shaped paddle");
  set_long("A fairly standard canoe paddle, with a broad leaf shaped"
          +" head. It is designed to be used in both hands. "
          +"This paddle can be used to power the canoe down the river"
          +" and to change direction:\n\n"
     +"<launch boat> set off on your journey downstream\n"
     +"<paddle left> paddle forward on the left side of the canoe\n"
     +"<paddle right> paddle forward on the right side of the canoe\n"
     +"<reverse left> paddle backward on the left side of the canoe\n"
     +"<reverse right> paddle backward on the right side of the canoe\n"
     +"<tips> see some more instructions");
  set_weight(4);
  set_value(20);
}

void init(){
  add_action("launch_boat", "launch");
  add_action("launch_boat", "push");
  add_action("paddle","paddle");
  add_action("back_paddle", "reverse");
  add_action("tips", "tips");
}

int tips(string str){
  string result;
  result  = 
  "%^BOLD%^%^YELLOW%^Controls%^RESET%^\n\n"
 +"%^CYAN%^Launch canoe %^RESET%^- set off along the river\n\n"
 +"%^CYAN%^Paddle right %^RESET%^- go faster, turn to the left.\n\n"
 +"%^CYAN%^Paddle left %^RESET%^- go faster, turn to the right.\n\n"
 +"%^CYAN%^Backpaddle right %^RESET%^- go slower, turn to the right.\n\n"
 +"%^CYAN%^Backpaddle left %^RESET%^- go slower, turn to the left.\n\n"
 +"%^CYAN%^Pause %^RESET%^- temporarily stop the canoe ride. You will get a countdown until it restarts.\n\n"
 +"%^CYAN%^Resume %^RESET%^- restart the canoe ride before the pause countdown runs out.\n\n"
 +"%^BOLD%^%^RED%^Tips\n\n%^RESET%^"
 +"%^ORANGE%^Travel speed is a combination of the river flow and the relative speed of the boat\n\n"
 +"%^ORANGE%^As you go faster, there will be less delay before the canoe advances again\n\n"
 +"%^ORANGE%^If you go too fast overall, you may capsize\n\n"
 +"%^ORANGE%^If you hit an obstruction, you will capsize.\n\n"
 +"%^ORANGE%^If you go side on to the river when the flow is fast, you will capsize.\n\n"
 +"%^ORANGE%^If you hit the bank, you will capsize.\n\n"
 +"%^ORANGE%^The canoe is not to scale, and sometimes the body of it may seem out of place, especially near the banks, or if you are going against the flow of the river. You can judge where the boat is in the river from the position of the red prow.\n\n"
 +"%^ORANGE%^You may be able to see more of the river by increasing your SCREEN and LINES settings with the < setenv > command. Increasing SCREEN may need you to change a corresponding setting in your mud client.";
  tell_object(TP, result);
  return 1;
}

int paddle(string str){
  object holder, room;
  holder = ETO;
  room = EETO;
  if (!objectp(holder)||!objectp(room)){
    return 0;
  }
  if (file_name(room)[0..(sizeof( KAYAK )-1)] != KAYAK){
    tell_object(holder, "You aren't in a vessel!");
    return 1;
  }

  if (str=="left"){
    tell_object(holder, "You paddle strongly on the left hand side of the"
                       +" canoe");
    tell_room(room, (string)holder->QCN + " paddles strongly on the left"
                    +" hand side of the canoe.", holder);
    room->paddle_left();
    return 1;
  }else{
    if (str =="right"){
      tell_object(holder, "You paddle strongly on the right hand side of"
                         +" the canoe");
      tell_room(room, (string)holder->QCN + " paddles strongly on the"
                    +" right hand side of the canoe.", holder);
    room->paddle_right();
    return 1;
    }else{
      tell_object(holder, "paddle right or left?");
      return 1;
    }
  }
}

int back_paddle(string str){
  object holder, room;
  holder = ETO;
  room = EETO;
  if (!objectp(holder)||!objectp(room)){
    return 0;
  }
  if (file_name(room)[0..(sizeof( KAYAK )-1)] != KAYAK){
    tell_object(holder, "You aren't in a vessel!");
    return 1;
  }

  if (str=="left"){
    tell_object(holder, "You back paddle strongly on the left hand side"
                       +" of the canoe");
    tell_room(room, (string)holder->QCN + " back paddles strongly on the"
                    +" left hand side of the canoe.", holder);
    room->back_paddle_left();
    return 1;
    
  }else{
    if (str =="right"){
      tell_object(holder, "You back paddle strongly on the right hand"
                         +" side of the canoe");
      tell_room(room, (string)holder->QCN + " back paddles strongly on"
                    +" the right hand side of the canoe.", holder);
    room->back_paddle_right();
    return 1;
    }else{
      tell_object(holder, "reverse right or left?");
      return 1;
    }
  }
}


int launch_boat(string str){
  object holder, room;
  if (query_verb() == "launch"){
    if (str != "boat" && str != "canoe" && str != "canoe"){
      tell_object(TP, "Launch what?");
      return 1;
    }
  } else{
    if (query_verb() == "push"){
      if (str != "off"){
        return 0;
      }
    } else{
      return 0;
    }
  }
  holder = ETO;
  room = EETO;

  if (!objectp(holder)){
    return 0;
  }
  if (!interactive(holder))
  {
    return notify_fail("You would need to be holding the paddle to do that");
  }
  if (!objectp(room)){
    tell_object(holder, "The oom you are in is not valid. Please make a"
                       +" bug report on the paddle you are holding.");
    return 0;
  }
  if (file_name(room)[0..(sizeof( KAYAK )-1)] != KAYAK){
    tell_object(holder, "You aren't in a vessel!");
  }
  room->launch(holder);
  return 1;
}
