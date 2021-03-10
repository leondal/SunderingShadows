//Coded by Lujke

#include <std.h>
#include "../tecqumin.h"
#define HITLOCS ({"through the eye", "in the chest", "in its neck",\
       "to the stomach", "in the leg", "in the face", "in the groin"})
inherit OBJECT;

int count_tabaxi();
void marshall();
void ground_attack();
void broadcast(string str);

void create() {
    ::create();
    set_name("Tabaxi battle organiser");
    set_id( ({"organiser","battle organiser","tabaxi battle organiser",}));

    set_short("Tabaxi battle organiser");
    set_weight(4);
    set_long("This is a device for organising battles. For the tabaxi. The"
            +" clue is in the title, really.");
}


void init(){
  ::init();
  add_action("start_attack", "start");
  add_action("deploy_defenders","deploy");
}

void broadcast(string str){
  int i;
  object * rooms, room;
  rooms = ({});
  room = find_object_or_load(TREEHOUSE + "/rooms/"+ "t_house_base");
  if (objectp(room)){
    rooms+=({room});
  }
  for (i=1;i<9;i++){
    room = find_object_or_load(TREEHOUSE + "/rooms/"+ "platform0" + i);
    if (objectp(room)){
      rooms+=({room});
    }
    room = find_object_or_load(TREEHOUSE + "/rooms/"+ "treetop_base0" + i);
    if (objectp(room)){
      rooms+=({room});
    }
    room = find_object_or_load(TREEHOUSE + "/rooms/"+ "treetop0" + i);
    if (objectp(room)){
      rooms+=({room});
    }
  }
  room = find_object_or_load(TREEHOUSE + "/rooms/"+ "crowsnest");
  if (objectp(room)){
    rooms +=({room});
  }
  if (sizeof(rooms)>0){
    for (i=0; i<sizeof(rooms); i++){
      room = rooms[i];
      tell_room(room, str);
    }
  }
}

int start_attack(string str){
  int i, num;
  object ren, room;
  if (str != "attack"){
    tell_object(TP, "Start what? An attack or something?");
    return 1;
  }
  num = 10 + random(10);
  room = find_object_or_load(TREEHOUSE + "/rooms/"+ "t_house_base");
  broadcast("Orog warriors and archers begin arriving at"
                         +" the base of the higureon tree");
  for (i=0;i<num;i++){
    ren  = new(MOB + "orog");
    if (objectp(ren)&& objectp(room)){
      ren->move(room);
    }
  }
  num = 5 + random(10);
  for (i=0;i<num;i++){
    ren  = new(MOB + "orog_archer");
    if (objectp(ren)&& objectp(room)){
      ren->move(room);
    }
  }
  call_out("marshall", 3);
  return 1;
}

void marshall(){
  broadcast("The orog quickly move into attack formations round the base"
           +" of the higureon tree. The warriors move to the fore, while"
           +" the crossbowmen hang back");
  call_out("ground_attack", 3);
}
void ground_attack(){
  int i, climbers;
  object * critters, * rens, ren, room;
  room = find_object_or_load(TREEHOUSE + "/rooms/"+ "t_house_base");
 // tell_room(room, "The ground attack begins!");
  if ((string)room->query_exit("up")!="/d/shadowgate/void"){
    critters = all_living(room);
    rens = ({});
    if (sizeof(critters)<1){ return;}
    for (i=0;i<sizeof(critters);i++){
      if (critters[i]->id("orog warrior")){
        rens += ({critters[i]});
      }
    }
    if (sizeof(rens)<1){return;}
    climbers = 0;
    for(i=0;i<sizeof(rens);i++){
      if (random(3)>0){
        rens[i]->force_me("up");
        climbers ++;
      }
    }
    switch(climbers){
    case 0:
      break;
    case 1:
      broadcast("A lone orog warrior makes a dash for the rope ladder"
               +" and climbs to the platform");
      break;
    case 2..5:
      broadcast("A small group of orog warriors make a dash for the"
               +" rope ladder and climb to the platform");
      break;
    default:
      if (climbers == sizeof(rens)){
        broadcast("The orog warriors charge en masse and swarm up the"
                 +" rope ladder to the platform");
        break;
      } else {
        broadcast("A large group of orog warriors charge toward the"
                 +" higureon tree and swarm up the rope ladder to the"
                 +" platform");
        break;
      }
    }
  } else {
    broadcast("The orog warriors mill around at the base of the tree"
             +", but seem unable to find a way up. They retreat to the"
             +" edges of the clearing");
    call_out("shoot_rope",2+ random(3));
  }
  call_out("volley",2+ random(2));
  call_out("tabaxi_attack", 3+ random(2));
}


void volley(){
  object * critters, * archers, archer, platform, target, corpse, clearing;
  int i, plat_num, count, ticker, shielded;
  string plat_name, hit_loc;
  clearing = find_object_or_load(TREEHOUSE + "/rooms/"+ "t_house_base");
  critters = all_living(clearing);
  if (sizeof(critters)<1){
    return;
    call_out("ground_attack", 2+ random(3));
  }
  archers = ({});
  for (i=0;i<sizeof(critters);i++){
    if (critters[i]->id("orog archer")){
      archers += ({critters[i]});
    }
  }
  if (sizeof(archers)<1){
    call_out("ground_attack", 2+ random(3));
    return;
  }
  count = 0;
  shielded = 0;
  for(i=0;i<sizeof(archers);i++){
    if (random(7)<2) { 
      continue;
    }
    count ++;
    ticker = 0;
    while(!objectp(target) && ticker <5){
      ticker ++;
      switch(random(2)){
      case 0:
        plat_num = random(8)+1;
        plat_name = TREEHOUSE + "/rooms/"+ "platform0" + plat_num;
        break;
      default:
        plat_name = TREEHOUSE + "/rooms/"+ "t_house_middle";
        break;
      }
      platform = find_object_or_load(plat_name);
      if (!objectp(platform)){
        tell_room(TO, "Error loading the platform. Please tell a wiz.");
        return;
      }
      target = present("tabaxi", platform);
    }
    if (!objectp(target)){ 
      count --;
      continue;
    }
    if ((int)platform->query_screened()==1 && random(7)>1){
      shielded++;
      count --;
      tell_room(platform, "An arrow clatters harmlessly against the wicker"
                         +" screen");
      continue;
    }
    hit_loc = HITLOCS[random(sizeof(HITLOCS))];
    tell_room(platform, "A tabaxi takes an arrow " + hit_loc + " and falls"
                       +" out of the tree");
    target->die();
    corpse = present("corpse", platform);
    if (objectp(corpse)){
      clearing = find_object_or_load(TREEHOUSE + "/rooms/"+ "t_house_base");
      if (objectp(clearing)){
        corpse->move(clearing);
      }
    }
  }
  switch(shielded){
  case 0:
    switch(count){
    case 0:
      broadcast("The orog crossbow troops launch a volley of arrows toward the"
             +" higureon tree, but fail to dislodge anything other than"
             +" the odd leaf");
      break;
    case 1:
      broadcast("The orog crossbow troops launch a volley of arrows toward the"
             +" higureon tree, but only manage to kill a single tabaxi");
      break;
    case 2..5:
      broadcast("The orog crossbow troops launch a volley of arrows toward the"
             +" higureon tree, killing a small group of the tabaxi defenders");
      break;
    default:
      broadcast("The orog crossbow troops launch a volley of arrows toward the"
             +" higureon tree, killing a large number of tabaxi");
      break;
    }
   break; 
  case 1:
    switch(count){
    case 0:
      broadcast("The orog crossbow troops launch a volley of arrows toward the"
             +" higureon tree, but fail to dislodge anything other than"
             +" the odd leaf. They might have hit one defender, but the"
             +" wicker screens got in the way");
      break;
    case 1:
      broadcast("The orog crossbow troops launch a volley of arrows toward the"
             +" higureon tree, but only manage to kill a single tabaxi."
             +" They might have hit another, but the"
             +" wicker screens got in the way");
      break;
    case 2..5:
      broadcast("The  orog crossbow troops launch a volley of arrows toward the"
             +" higureon tree, killing a small group of tabaxi. One lucky"
             +" tabaxi defender successfully took cover behind the wicker screens");
      break;
    default:
      broadcast("The orog crossbow troops launch a volley of arrows toward the"
             +" higureon tree, killing a large number of tabaxi defenders. One"
             +" lucky tabaxi successfully took cover behind the wicker"
             +" screens");
      break;
    }
    break;
  case 2..5:
    switch(count){
    case 0:
      broadcast("The orog crossbow troops launch a volley of arrows toward the"
             +" higureon tree, but fail to dislodge anything other than"
             +" the odd leaf. Several tabaxi were saved by the defensive"
             +" wicker screens");
      break;
    case 1:
      broadcast("The orog crossbow troops launch a volley of arrows toward the"
             +" higureon tree, but only manage to kill a single tabaxi."
             +" Several more of the defencers were saved by the defensive"
             +" wicker screens");

      break;
    case 2..5:
      broadcast("The orog crossbow troops launch a volley of arrows toward the"
             +" higureon tree, killing a small group of tabaxi. Several"
             +" more tabaxi would have been hit, but were saved by the defensive"
             +" wicker screens");
      break;
    default:
      broadcast("The orog crossbow troops launch a volley of arrows toward the"
             +" higureon tree, killing a large number of tabaxi. Several"
             +" tabaxi were nevertheless saved by the defensive wicker screens");
      break;
    }
    break;
  default:
    switch(count){
    case 0:
      broadcast("The  orog crossbow troops launch a volley of arrows toward the"
             +" higureon tree, but fail to dislodge anything other than"
             +" the odd leaf. Lots of the tabaxi were saved by the"
             +" defensive wicker screens");
      break;
    case 1:
      broadcast("The orog crossbow troops launch a volley of arrows toward the"
             +" higureon tree, but only manage to kill a single tabaxi defender."
             +" A large number of other tabaxi were saved by the"
             +" defensive wicker screens");

      break;
    case 2..5:
      broadcast("The orog crossbow troops launch a volley of arrows toward the"
             +" higureon tree, killing a small group of tabaxi defenders. Lots of"
             +" the tabaxi were saved by the defensive wicker screens");
      break;
    default:
      broadcast("The orog crossbow troops launch a volley of arrows toward the"
             +" higureon tree, killing a large number of the tabaxi. Lots of "
             +" other tabaxi were saved by the defensive wicker screens");
      break;
    }
    break;
  }
  call_out("ground_attack", 2+ random(3));
}



int deploy_defenders(string str){
  object * rooms, room, critter;
  int i, j, num;
  rooms = ({});
  room = find_object_or_load(TREEHOUSE + "/rooms/"+ "crowsnest");
  rooms += ({room});
  for (i=1;i<9;i++){
    room = find_object_or_load(TREEHOUSE + "/rooms/"+ "platform0" +i);
    rooms += ({room});   
  }
  for (i=0;i<sizeof(rooms);i++){
    room = rooms[i];
    num = 1 + random(3) + random(2);
    for (j=0;j<num;j++){
      critter = new(MOB + "tabaxi");
      critter->move(room);
    }
  }
  room = find_object_or_load(TREEHOUSE + "/rooms/"+ "t_house_middle");
  num = 3 + random(4) + random(3);
  for (j=0;j<num;j++){
    critter = new(MOB + "tabaxi_archer");
    critter->move(room);
  }
  broadcast("A force of tabaxi archers take positions in the higureon"
           +" tree");
  return 1;
}





void shoot_rope(){
  object * creatures, * archers, room;
  int i, flag;
  flag = 0;
  room = find_object_or_load(TREEHOUSE + "/rooms/"+ "t_house_base");
  if ((string)room->query_exit("up") != "/d/shadowgate/void"){
    return;
  }
  creatures = all_living(room);
  archers = ({});
  if (sizeof(creatures)>0){
 //   tell_room(room, "There are some critters in the room");
    for (i=0;i<sizeof(creatures);i++){
      if (creatures[i]->id("crossbowman")){
        archers += ({creatures[i]});
      }
    }
  }
  if (sizeof(archers)>0){
    for (i=0;i<sizeof(archers);i++){
      if (random(5)){
        continue;
      }
      broadcast("%^BOLD%^%^BLUE%^An orog crossbowman takes a shot towards the"
             +" %^RESET%^%^ORANGE%^support rope%^BOLD%^%^BLUE%^"
             +" securing the platform hatch");
      archers[i]->force_me("shoot rope");
    }
  }
  call_out("ground_attack", 2+ random(3));
}


