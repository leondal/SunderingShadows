#include <std.h>
#include <daemons.h>
#include <magic.h>
#include "../../tecqumin.h"

inherit ROOM;

void crash();
string out_fun();
object ram;
int rolling, battering, approaching;

void create(){
  ::create();
  rolling = 0;
  battering = 0;
  approaching = 0;
  set_short("Inside a covered battering ram");
  set_long("You are inside the covered battering ram, serving as one of the operating crew. The sloped"
          +" roof above your head is covered with thick, %^BOLD%^%^BLACK%^water-soaked leather hides"
          +" %^RESET%^which should protect you from most attacks from outside. There is a"
          +" %^ORANGE%^handle%^RESET%^ attached to the %^ORANGE%^ram%^RESET%^, which you can use to"
          +" %^GREEN%^swing%^RESET%^ the ram and %^BOLD%^%^BLUE%^batter%^RESET%^ its target. You can"
          +" %^BOLD%^%^RED%^peek%^RESET%^ through a slit in the hide to see the area outside, and you"
          +" can %^BOLD%^%^GREEN%^roll%^RESET%^ the ram in any direction you want it to go.");
}

void init(){
  ::init();
  add_action("batter", "batter");
  add_action("swing", "swing");
  add_action("roll", "roll");
  add_action("peek", "peek");
  add_action("approach", "approach");
}

int peek(string str){
  object env;
  if (!objectp(ram)||!objectp(environment(ram))){
    tell_object(TP, "There's a problem with the ram, or the room it's in. %^BOLD%^%^RED%^Get out"
                   +" quick, while you can. Save yourselves! %^RESET%^And once you've done that,"
                   +" please tell a Wiz. Preferably %^BOLD%^%^GREEN%^Lujke%^RESET%^, who probably"
                   +" broke things. Or make a bug report or something.");
    return 1;
  }
  tell_object(TP, "%^BOLD%^%^BLUE%^You peer out through a slit in the hides covering the battering"
                 +" ram");
  TP->move(environment(ram));
  TP->force_me("look");
  TP->move(TO);
  return 1; 
}

int clean_up(){
  object r;
  int roll, batter, approach, result;
  r = ram;
  roll = rolling;
  batter = battering;
  approach = approaching;
  result = ::clean_up();
  ram = r;
  rolling = roll;
  approaching = approach;
  battering = batter;
  return result;
}

string out_fun(){
  object env;
  if (!objectp(ram)){
    return "/d/shadowgate/void";
  }
  env = environment(ram);
  if (!objectp(env)){
    return "/d/shadowgate/void";
  }
  return file_name(env);
}

object query_ram(){
  return ram;
}

void set_ram(object ob){
  ram = ob;
}

int swing(string str){
  tell_object(TP, "To use the ram, you need to %^BOLD%^%^YELLOW%^'batter <target>'%^RESET%^.");
  return 1;
}

int batter(string str){
  object envir;
  if (!objectp(ram)||!objectp(environment(ram))){
    tell_object(TP, "There seems to be a problem with the ram. Please tell a wiz. Preferably Lujke, as"
                    " it's all his stupid fault. Failing that, make a bug report.");
    return -1;
  }
  envir = environment(ram);
  if (present(str, envir)){
    if (living(present(str, envir))){
      tell_object(TP, (string)present(str, envir)->QCN + "%^RESET%^ is hardly likely to stand there"
                     +" and let you do that.");
    if (TP->id("orog")){
      TP->force_me("tell lujke I can't batter the " +str + " because it is alive");
    }
      return 1;
    }
  }

  if (!envir->query_batterable()){
    tell_object(TP, "There's nothing really worth battering here");
    if (TP->id("orog")){
      TP->force_me("tell lujke I can't batter the " +str + " for some reason");
    }    return 1;
  }

  if (!interact(str, (string)envir->query_batterable())){
    tell_object(TP, "You can't batter that. Try %^BOLD%^%^YELLOW%^'batter " 
                   + (string)envir->query_batterable() + "%^BOLD%^%^YELLOW%^'" );

    return 1;
  }
  if (envir->query_position(TO) < 10){
    tell_object(TP, "You aren't close enough to the " + str + "%^RESET%^ yet. You will need to"
                   +" %^BOLD%^%^YELLOW%^'approach "+ str + "%^BOLD%^%^YELLOW%^'%^RESET%^ first.");
    return 1;
  }
  if (battering ==1){
    tell_object(TP, "The ram is already being used to batter stuff! No need to do any more - just put"
                    +" your back into it!");
    return 1;
  }
  envir->batter(str, TP, TO);
  battering = 1;
  return 1;
}

int stop(string str){
  object envir;
  if (!battering){
    notify_fail("Stop what? You aren't battering anything at the moment.");
    return 0;
  }
  tell_object(TP, "%^BOLD%^%^BLUE%^You call a halt to the battering");
  tell_room(TO, "%^BOLD%^%^BLUE%^" + TPQCN + "%^BOLD%^%^BLUE%^ calls a halt to the battering");
  envir = environment(ram);
  if (objectp(envir)){
    tell_room(envir, "%^BOLD%^%^BLUE%^The %^BOLD%^%^BLACK%^ram%^BLUE%^^ ceases its assault");
  }
  battering = 0;
  return 1;
}

void roll2(string str, object stt, object dest){
  object orog;
  rolling = 0;
  if (!objectp(dest)){
    tell_room(TO, "There's a problem with the destination room in the " + str + "direction. Please"
                 +" make a bug report.");
    return;
  }
  if (!objectp(stt)){
    tell_room(TO, "There's a problem with the room the ram started in. Please"
                 +" make a bug report.");
    return;
  }
  tell_room(stt, ram->query_short() + " rolls off in the " + str + "%^RESET%^ direction");
  orog = present("orog", TO);
  if (objectp(orog)){
    orog->force_me("ram_roll");
  }
  tell_room(dest, ram->query_short() + " rolls in.");
  ram->move(dest);
  add_exit(out_fun(), "out");
  tell_room(TO, "The ram rolls in the " + str + "%^RESET%^ direction");
}

int roll(string str){
  object env, dest, orog, squad;
  string destination;
  if (!objectp(ram)||!objectp(environment(ram))){
    tell_object(TP, "There seems to be a problem with the ram. Please tell a wiz. Preferably Lujke, as"
                    " it's all his stupid fault. Failing that, make a bug report.");
    return 1;
  }
  if (rolling ==1){
    tell_object(TP, "The ram is already rolling somewhere.");
    return 1;
  }
  env = environment(ram);
  destination = env->query_exit(str);
  if (destination == "/d/shadowgate/void"){
    tell_object(TP, "There's no exit the ram can roll in in that direction. Have a %^BOLD%^%^RED%^peek"
                   +" %^RESET%^outside to see where you might be able to go.");
    squad = present("xxsquadxx", TO);
    if (objectp(squad)){
      squad->clear_directions();
      squad->roll_ram();
    }
    return 1;
  }
  dest = find_object_or_load(destination);
  if (!objectp(dest)){
    tell_object(TP, "Error loading the destination room. Please tell a wiz. If possible, make a bug"
                +" report from the room outside where the ram is now.");
    return 1;
  }
  tell_object(TP, "You start rolling the ram in the " + str + "%^RESET%^ direction");
  tell_room(TO, TPQCN + "%^RESET%^ begins rolling the ram in the " + str + "%^RESET%^ direction", TP);
  tell_room(env,ram->query_short() + "%^RESET%^ begins rolling in the " + str + "%^RESET%^ direction");
  rolling = 1;
  call_out("roll2", 2, str, env, dest);
//  roll2(str, env, dest);
  return 1;
}

int reset_ram(){
  object * rams;
  int i;
  rams = children(MOB + "ram_mob");
  if (sizeof(rams)>0){
    for (i=0;i<sizeof(rams);i++){
      if (objectp(rams[i])){
        ram = rams[i];
        return 1;
      }
    }
  }
  return 0;
}

int approach(string str){
  object envir;
  if (!objectp(ram)){
    if (reset_ram()<1){
      tell_object(TP, "There seems to be a problem with the ram. Please tell a wiz - preferably that"
                   +" scaly lizard %^BOLD%^%^GREEN%^Lujke%^RESET%^, who is likely to be responsible."
                   +" Failing that, make a bug report.");
      return 1;
    }
  }
  if (TP->query_paralyzed() || TP->query_bound()){
    TP->send_paralyzed_message("info",TP);
    return 1;
  }
  if (approaching ==1){
    tell_object(TP, "The ram is already rolling in the right direction");
    return 1;
  }
  envir = environment(ram);
  if (!objectp(envir)){
    tell_object(TP, "There seems to be a problem with the ram's environment. Please tell a wiz -"
                   +" preferably that"
                   +" scaly lizard %^BOLD%^%^GREEN%^Lujke%^RESET%^, who is likely to be responsible."
                   +" Failing that, make a bug report.");
    return 1;
  }
  if (!envir->query_batterable()){
    tell_object(TP, "There doesn't seem to be anything worth approaching here. Perhaps you should look"
                   +" for a gate, or something worth knocking down?");
    return 1;
  }
  if (str != (string)envir->query_batterable()){
    tell_object(TP, "Try %^BOLD%^%^YELLOW%^'approach " + envir->query_batterable() 
                  + "%^BOLD%^%^YELLOW%^'");
    return 1;
  }
  tell_object(TP, "You begin slowly rolling the ram toward the " + str);
  tell_room(TO, TPQCN + " begins slowly rolling the ram toward the " + str, TP);
  tell_room(envir, "The " + ram->query_short() +"%^RESET%^ begins slowly rolling toward the " + str);
  approaching = 1;
  call_out("approach2", 3,  envir, str);
  return 1;
}

void approach2(object envir, string str){
  int pos, pits, stakes, i;
  object * critters, orog;
  if (!objectp(envir)){
    approaching = 0;
    return;
  }
  if (rolling !=0 || !present(ram, envir)){
    tell_room(TO, "The ram has left the area of the " + str + ", so the approach has come to an end");
    envir->set_position(TO, 0);
    approaching = 0;
    return;
  }
  pos = envir->query_position(TO);
  stakes = envir->query_staked();
  pits = envir->query_pitted();
  switch (stakes){
  case 0:
    switch (pits){
    case 0: // Clear
      tell_room(TO, "You roll the ram closer to the " + str);
      tell_room(envir, "The " + (string)ram->query_short() + " rolls closer to the " + str 
                + ".");
      envir->set_position(TO, pos+2+ random(2));
      break;

    case 1: // Open pits
      if (random(15)>13){ 
        crash();
        return;
      }
      tell_room(TO, "You roll the ram slowly closer to the " + str + "%^RESET%^, trying to avoid the"
                   +" pits.");
      tell_room(envir, "The " + (string)ram->query_short() + " rolls slowly closer to the " + str 
                + ", weaving its way around the pits.");
      envir->set_position(TO, pos+1+ random(2));
      break;
    case 2: // Covered pits
      switch (random(15)){
      case 0..10:
        tell_room(TO, "You roll the ram closer to the " + str);
        tell_room(envir, "The " + (string)ram->query_short() + " rolls closer to the " + str 
                  + ".");
        envir->set_position(TO, pos+2+ random(2));
        break;
      default:
        crash();
        return;
      }
      break;
    case 3: // Staked pits
      if (random(15)>13){ 
        crash();
        return;
      }
      tell_room(TO, "You roll the ram slowly closer to the " + str + "%^RESET%^, trying to avoid the"
                   +" pits.");
      tell_room(envir, "The " + (string)ram->query_short() + " rolls slowly closer to the " + str 
                + ", weaving its way around the pits.");
      envir->set_position(TO, pos+1+ random(2));
      break;
    case 4: // covered staked pits
      switch (random(15)){
      case 0..10:
        tell_room(TO, "You roll the ram closer to the " + str);
        tell_room(envir, "The " + (string)ram->query_short() + " rolls closer to the " + str 
                  + ".");
        envir->set_position(TO, pos+2+ random(2));
        break;
      default:
        crash();
        return;
      }
      break;
    }
    break;
  case 1:
    switch (pits){
    case 0: // No pits
      tell_room(TO, "You roll the ram slowly closer to the " + str + "%^RESET%^, avoiding the"
                   +" stakes.");
      tell_room(envir, "The " + (string)ram->query_short() + " rolls slowly closer to the " + str 
                + ", weaving its way around the stakes.");
      envir->set_position(TO, pos+1+ random(2));
    case 1: // Open pits
      if (random(90)>88){ 
        crash();
        return;
      }
      tell_room(TO, "You roll the ram slowly closer to the " + str + "%^RESET%^, avoiding the stakes"
                   +" and pits.");
      tell_room(envir, "The " + (string)ram->query_short() + " rolls slowly closer to the " + str 
                + ", weaving its way around the stakes and pits.");
      envir->set_position(TO, pos+1+ random(2));
      break;
    case 2: // Covered pits
      switch (random(15)){
      case 0..13:
        tell_room(TO, "You roll the ram slowly closer to the " + str + "%^RESET%^, avoiding the" 
                     +" stakes.");
        tell_room(envir, "The " + (string)ram->query_short() + " rolls slowly closer to the " + str 
                       + ", weaving its way around the stakes.");
        envir->set_position(TO, pos +1 + random(2));
        break;
      default:
        crash();
        return;
      }
      break;
    case 3: // Staked pits
      if (random(90)>88){ 
        crash();
        return;
      }
      tell_room(TO, "You roll the ram slowly closer to the " + str + "%^RESET%^, avoiding the stakes"
                   +" and pits.");
      tell_room(envir, "The " + (string)ram->query_short() + " rolls slowly closer to the " + str 
                + ", weaving its way around the stakes and pits.");
      envir->set_position(TO, pos+1+ random(2));
      break;
    case 4: // covered staked pits
      switch (random(15)){
      case 0..13:
        tell_room(TO, "You roll the ram slowly closer to the " + str);
        tell_room(envir, "The " + (string)ram->query_short() + " rolls slowly closer to the " + str );
        envir->set_position(TO, pos +1 + random(2));
        break;
      default:
        crash();
        return;
      }
      break;
    }
    break;
  }
  switch (pos){
  case 0:
    tell_room(TO, "It is still a long way away");
    tell_room(envir, "It is still a long way away");
    break;
  case 1..2:
    tell_room(TO, "It is quite distant");
    tell_room(envir, "It is still quite distant");
    break;
  case 3..4:
    tell_room(TO, "You are almost halfway there");
    tell_room(envir, "It is almost halfway there");
    break;
  case 5..6:
    tell_room(TO, "You are over halfway there");
    tell_room(envir, "It is over halfway there");
    break;
  case 7..8:
    tell_room(TO, "You are getting close");
    tell_room(envir, "It is getting close");
    break;
  case 9:
    tell_room(TO, "You are nearly there");
    tell_room(envir, "It is nearly there");
    break;
  default:
    tell_room(TO, "You have arrived by the gate. Let the battering commence!");
    tell_room(envir, (string)ram->query_short() + " has arrived by the gate!");

    approaching = 0;
    orog = present("orog", TO);
    if (objectp(orog)){
      orog->force_me("tell lujke attempting to batter the gate");
      orog->force_me("batter gate");
    }
    return;
  }
  call_out("approach2", 2 + random(3),  envir, str);
}

void crash(){
  object envir, * critters, orog;
  int i;
  if (!objectp(ram)){
    return;
  }
  envir = environment(ram);
  if (objectp(envir)){
    tell_room(envir, "The %^BOLD%^%^BLACK%^ram%^RESET%^ has crashed into a covered pit! It will take"
                    +" some time for them to recover from that.");
  }
  tell_room(TO, "The ram has rolled into a pit! It's going to take some time to set it"
               +" right and get going again.");
  critters = all_living(TO);
  if (sizeof(critters)>0){
    for (i=0;i<sizeof(critters);i++){
      critters[i]->set_paralyzed(ROUND_LENGTH * (2+ random(4)), "You are stunned from the crash!");
    }
  }
  orog = present("orog", TO);
  if (objectp(orog)){
    orog->crash();
  }
  rolling = 0;
  approaching = 0;
}
