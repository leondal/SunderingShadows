//Coded by Lujke


#include <std.h>
#include "../tecqumin.h"
inherit OBJECT;

int speed;
string last_exit;

void create() {
    ::create();
    speed = 0;
    last_exit = "up";
    set_name("ball of stone");
    set_id( ({"ball","stone ball","stone", "ball of stone"}) );
    set_short("An enormous ball of stone");
    set_weight(400);
    set_long("A %^ORANGE%^huge%^RESET%^, roughly hewn ball of%^ORANGE%^"
            +" stone%^RESET%^, gathering speed as it rolls towards you."
            +" The ball is pock marked and pitted, filling up almost the"
            +" entire space of the tunnel it is in. It would probably be"
            +" a good idea to get out of the way somehow.");
}

void start_rolling(){
  call_out("start_rolling2",4);
}

void start_rolling2(){
  if (!objectp(ETO)){
    return;
  }
  tell_room(ETO, "%^ORANGE%^The massive stone ball creaks loudly and"
                +" starts rolling ponderously towards you, picking up"
                +" speed as it comes.");
  call_out("roll", 5-speed);
}

string query_last_exit(){
  return last_exit;
}

string get_next_exit(){
  string exit, *exits;
  int i;
  if (!objectp(ETO)){
    return "undefined";
  }
  exits = ETO->query_exits();
  if (sizeof(exits)<1){
    return "no exits";
  }
  for (i=0;i<sizeof(exits);i++){
    if (exits[i] != last_exit){
      last_exit = exits[i];
      return last_exit;
    }
  }
}

string reverse_exit(string exit){
  switch (exit){
  case "north":
    return "south";
  case "northeast":
    return "southwest";
  case "east":
    return "west";
  case "southeast":
    return "northwest";
  case "south":
    return "north";
  case "southwest":
    return "northeast";
  case "west":
    return "east";
  case "northwest":
    return "southeast";
  }

  
}

void roll(){
  int i, j, count;
  string next_exit, next_roomname;
  object next_room, critter, head, powder, wisp, * inv;
  if (!objectp(ETO)){
    return;
  }
  next_exit = get_next_exit();
  next_room = find_object_or_load(ETO->query_exit(next_exit));
  tell_room(ETO, "The massive stone ball rumbles forward to the " 
                + next_exit + " crushing everything in its path!/n");
  if (sizeof (all_living(ETO))>0){
    for (i=0;i<sizeof(all_living(ETO));i++){
      critter = all_living(ETO)[i];
      if (critter->query_true_invis()){
        tell_object(critter, "As an immortal, you simply phase through"
                            +" the  stone ball as it rolls past. You are"
                            +" completely unharmed.");
        continue;
      }
      tell_object(critter, "%^RED%^You are crushed beneath the enormous"
                          +" %^RESET%^stone ball%^RED%^ as it rolls over"
                          +" you!%^RESET%^\n");
      tell_room(ETO, "%^RED%^" + critter->QCN + " %^RESET%^%^RED%^ is"
                          +" crushed beneath the enormous %^RESET%^stone"
                          +" ball%^RED%^ as it rolls over" + critter->QO
                          +"!%^RESET%^\n", critter); 
      /// make sure the shrunken head is crushed, if they are carrying one
      while(present("shrunken head", critter))
      {
        head = present("shrunken head", critter); 
        if (objectp(head)){
          tell_object(critter, "The " + head->query_short() + "%^RESET%^ "
                              +"you are carrying is crushed to powder!\n" ); 
          head->remove();
          powder = new(OBJ + "powdered_bone.c");
          wisp = new(OBJ + "wisp_of_hair.c");
          powder->move(critter);
          wisp->move(critter);
        }
      }
      inv = deep_inventory(critter);
      count = sizeof(inv);
      if (count>0)
      {
        for (j=0;j<count;j++)
        {
          head = inv[i];
          if (objectp(head) && head->id("shrunken head"))
          {
            tell_object(critter, "The " + head->query_short() + "%^RESET%^ "
               +"you are carrying is crushed to powder!\n" ); 
            head->remove();
            powder = new(OBJ + "powdered_bone.c");
            wisp = new(OBJ + "wisp_of_hair.c");
            powder->move(critter);
            wisp->move(critter);
          }
        }
      }
      ////////////////
      all_living(ETO)[i]->cause_typed_damage(all_living(ETO)[i], all_living(ETO)[i]->return_target_limb(), roll_dice(1, 250) + 149, "bludgeoning");
      all_living(ETO)[i]->add_attacker(TO);
      all_living(ETO)[i]->continue_attack();
      if(objectp(all_living(ETO)[i])){
        all_living(ETO)[i]->remove_attacker(TO);
      }
    }
  }
  //// destroy any shrunken heads in the room
 head = present("shrunken head", ETO);
 while (objectp(head)){
    tell_room(ETO, " A " + head->query_short() + "%^RESET%^ is crushed to"
                  +" %^BOLD%^%^WHITE%^powder%^RESET%^ under the weight of"
                  +" the ball of stone!\n");
    head->remove();
    powder = new(OBJ + "powdered_bone.c");
    wisp = new(OBJ + "wisp_of_hair.c");
    powder->move(ETO);
    wisp->move(ETO);
    head = present("shrunken head", ETO);
  }
  tell_room(ETO, "The massive stone ball rolls out through the " 
                + next_exit + " exit.\n");
  last_exit = reverse_exit(next_exit);
  tell_room(next_room, "%^RED%^A massive %^RESET%^stone ball%^RED%^ rolls"
                      +" in through the %^RESET%^" + last_exit + "%^RED%^"
                      +" exit!");
  if (base_name(ETO) == ROOMS + "head_room") ETO->setup_exits();
  move(next_room);
  if (random(3)<1 && speed <4){
    tell_room(ETO, "With a rumble, it picks up speed!");
    speed ++;
  }
  call_out("roll", 4-speed);
}


