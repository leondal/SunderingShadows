#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

mapping __PosDir;
mapping __Colours;
mapping __RPictures;
mapping __LPictures;

int demon_pos, demon_dir;

void push2(object pusher, object pushed);
void enter_east();
void enter_west();
int check_bridge(string str);
void set_PosDir(object ob, int * PosDir);
void set_pos(object ob, int pos);
int query_pos(object ob);
void set_face(object ob, int face);
int query_face(object ob);
int query_dir(object ob);
void set_dir(object ob, int dir);
void set_demon_pos(int pos);
int query_demon_pos();
int set_demon_dir(int dir);
int query_demon_dir();
string long_desc();
string base_desc();
void tell_bridge( string str, object ob);

void create() {
  ::create();
  set_long( (: TO, "long_desc" :) );
  set_short("%^BOLD%^%^YELLOW%^On a creaky %^RESET%^%^ORANGE%^ropebridge");
}

void init(){
  ::init();
  add_action("head_east", "east");
  add_action("head_west", "west");
  add_action("climb_up", "climb");
  add_action("climb_down", "descend");
  add_action("fly_down", "fly");
  add_action("head_up", "up");
  add_action("head_down", "down");
  add_action("check_bridge", "check");
  add_action("fall_me", "fall");
  add_action("stop", "stop");
  add_action("turn", "turn");
  add_action("jump_off", "jump");
  add_action("hold_on", "hold");
  add_action("hold_on", "grip");
  add_action("hold_on", "grab");
  add_action("let_go", "let");
  add_action("cut_rope", "cut");
  add_action("push", "push");
  add_action("push", "shove");
  add_action("pull", "pull");
  add_action("pull", "yank");
  add_action("pull", "drag");
}

void reset(){
  object * obs, room;
  string rm_name;
  int i, j, flag;
  ::reset();
  obs = ({});
  obs = users();
  if (sizeof(obs)>1){
    for (i=0;i<sizeof(obs);i++){
      if (!objectp(obs[i])){ continue; }
      if ((int)obs[i]->query_property("gripped")>0){
        room = environment(obs[i]);
        if (!objectp(room)){
          obs[i]->remove_property("gripped");
          continue;
        }
        rm_name = file_name(room);
        flag = 0;
        for (j=0;j<6;j++){
          if(rm_name == JUNG_ROOM + "ropebridge" + i ||
             rm_name == JUNG_ROOM + "air" + i ||
             rm_name == JUNG_ROOM + "bbridge_e" + i ||
             rm_name == JUNG_ROOM + "bbridge_w" + i){
            flag = 1;
            break;
          }
        }
        if (flag == 0){
          obs[i]->remove_property("gripped");
        }
      }
    }
  }
}

int fly_down(string str){
  object room;
  if (!objectp(TP)){ return 1;}
  if ((int)TP->query_property("flying")!=1){
    return notify_fail("You can't do that - you're not flying. You can"
      +" try to %^BOLD%^%^WHITE%^<jump> %^RESET%^or%^BOLD%^%^WHITE%^"
      +" <fall>%^RESET%^, if you like?");
  }
  if (str != "down"){
    tell_object(TP, "You can use %^BOLD%^%^WHITE%^<up>%^RESET%^,"
      +" %^BOLD%^%^WHITE%^<down>%^RESET%^, %^BOLD%^%^WHITE%^<east>"
      +" %^RESET%^or %^BOLD%^%^WHITE%^<west>%^RESET%^ to fly in those"
      +" directions. Try %^BOLD%^%^WHITE%^<fly down>%^RESET%^ if you"
      +" want to land on the %^ORANGE%^canyon%^RESET%^ floor.");
    return 1;
  }
  if ((int)"/d/atoyatl/bridge_monitor_d.c"->query_break_point()==-1){
    if ((int)"/d/atoyatl/bridge_monitor_d.c"->query_vPos(TP)<13){
      tell_object(TP, "You aren't low enough to land on the canyon"
        +" floor yet. Go further %^BOLD%^%^WHITE%^<down>%^RESET%^.");
      return 1;
    }
  } else {
    if ((int)"/d/atoyatl/bridge_monitor_d.c"->query_vPos(TP)<21){
      tell_object(TP, "You aren't low enough to land on the canyon"
        +" floor yet. Go further %^BOLD%^%^WHITE%^<down>%^RESET%^.");
      return 1;
    }
  }
  room = find_object_or_load(JUNG_ROOM + "canyon_riverbank");
  if (objectp(room)){
    tell_room(ETP, TPQCN + " flies down to the %^ORANGE%^canyon"
      +" %^BOLD%^%^BLUE%^riverbank", TP);
    tell_room(room, TPQCN + " flies in from above.");
    tell_object(TP, "You fly down to the %^ORANGE%^canyon"
      +" %^BOLD%^%^BLUE%^riverbank%^RESET%^.");
    "/d/atoyatl/bridge_monitor_d.c"->remove_crosser(TP);
    TP->move(room);
    TP->force_me("look");
  }else {
    tell_object(TP, "There was a problem with the room you were trying"
      +" to fly down to. Please make a bug report for here, mentioning"
      +" a problem with the 'canyon riverbank' when flying down, and"
      +" that that %^BOLD%^%^GREEN%^Lujke%^RESET%^ is an idiot.");
  }
  return 1;
}

int push(string str){
  string who, where, count;
  int num, i, j, flag;
  object room, critter, * critters, * players;
  if ((int)TP->query_property("pushed")>0 && (int)TP->query_property("pushed")+ 4>=time()){
    tell_object(TP, "You haven't recovered from your last attempt to push someone yet!");
    if ((int) TP->query_property("pushed") > time()){
      TP->remove_property("pushed");
    }
    return 1;
  }
  num = sscanf(str, "%s %s %s", who, count, where);
  if (num < 1){
    tell_object(TP, "Who do you want to push off where?");
    return 1;
  }
  i = atoi(count);
  if (i != 0){
    who = who + " " + count;
  }
  players = users();
  if (sizeof(players)>0){
    for (j=0;j<sizeof(players);j++){
      if ((string)TP->knownAs(players[j]->query_name())==who){
        who = players[j]->query_name();
      }
    }
  }
  critters = ({});
  for (i=0;i<6;i++){
    room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
    if (objectp(room)){
      critter = present(who, room);
      if (objectp(critter)){
        critters += ({critter});
      }
    }
  }
  if (sizeof(critters)<1){
    tell_object(TP, "You can't push that - it is not on the bridge!");
    return 1;
  }
  TP->set_property("pushed", time());
  for (i=0;i<sizeof(critters); i++){
    if ((int)"/d/atoyatl/bridge_monitor_d.c"->can_reach(TP, critters[i])==1){
      push2(TP, critters[i]);
      return 1;
    }
  }
  tell_object(TP, "You aren't close enough to push that!");
  return 1;
}

void push2(object pusher, object pushed){
  int size1, size2, str1, str2, dex1, dex2, sizediff, strdiff, dexdiff;
  if (!objectp(pusher)){
    return;
  }
  if (!objectp(pushed)){
    tell_object(pusher, "There seems to be an error with the object you"
      +" were trying to push. Please make a bug report.");
    return;
  }
  str1 = pusher->query_stats("strength");
  str2 = pushed->query_stats("strength");
  size1 = pusher->query_size();
  size2 = pushed->query_size();
  dex1 = pusher->query_stats("dexterity");
  dex2 = pushed->query_stats("dexterity");
  str1 = str1 + (random(str1)/2);
  str2 = str2 + (random(str2)/2);
  dex1 = dex1 + (random(dex1)/2);
  dex2 = dex2 + (random(dex2)/2);
  size1 = size1*10 + (random(size1*10)/2);
  size2 = size2*10 + (random(size2*10)/2);
  if (str1 + dex1 + size1 > str2 + dex2 + size2){
    strdiff = str1 - str2;
    sizediff = size1 - size2;
    dexdiff = dex1 - dex2;
    if (strdiff > sizediff && strdiff > dexdiff){
      tell_object(TP, "You overcome " + pushed->QCN
        + " by main strength and push " + pushed->QO
        + " off the bridge!");
      tell_object(pushed, TPQCN + " overcomes you by main strength, and throws"
       +" you off the bridge!");
    } else {
      if (dexdiff > sizediff){
        tell_object(TP, "With a cunningly dextrous twist, you manage to fling "
          + pushed->QCN + " off the bridge!");
        tell_object(pushed, "With a cunningly dextrous twist, " + TPQCN
          + " flings you off the bridge!");
      } else {
        tell_object(TP, "You use your size advantage to push "
          + pushed->QCN + " off the bridge!");
        tell_object(pushed, TPQCN + " uses " + TP->QP + " size advantage"
         +" to throw you off the bridge!");
      }
    }
    "/d/atoyatl/bridge_monitor_d.c"->fall(pushed);
  } else {
    strdiff = str2 - str1;
    sizediff = size2 - size1;
    dexdiff = dex2 - dex1;
    if (strdiff > sizediff && strdiff > dexdiff){
      tell_object(pusher, pushed->QCN + " resists your attempt to push "
        + pushed->QO + " off the bridge with main strength!");
      tell_object(pushed, pusher->QCN + " tries to push you off the bridge, but you"
        +" resist " + pusher->QO + " with main strength!");
    } else {
      if (dexdiff > sizediff){
        tell_object(pusher, "You attempt to push " + pushed->QCN
          + " from the bridge, but " + pushed->QS + " evades your attempt with a"
          + " cunningly dextrous twist.");
        tell_object(pushed, pusher->QCN + " attempts to fling you off the bridge, but"
          +" you manage to evade the attempt with a cunningly dextrous twist!");
      } else {
        tell_object(pushed, pusher->QCN + " tries to push you off the bridge, but"
          +" you use your size advantage to resist " + pusher->QO + "!");
        tell_object(pusher, pushed->QCN + " uses " + pusher->QP + " size advantage"
         +" to  resist your attempt to throw him off the bridge!");
      }
    }
  }
}

int cut_rope(string str){
  object * obs, ob;
  int i, flag, pos, ropes;
  if (str != "rope" && str != "through rope" &&
    str != "ropes" && str !="through ropes"){
    return notify_fail("What do you want to cut?");
  }
  if ((int)"/d/atoyatl/bridge_monitor_d.c"->query_break_point() !=-1){
    return notify_fail("The ropes have already all been cut!");
  }
  obs = TP->query_wielded();
  if (sizeof(obs)<1){
    return notify_fail("You probably can't chew through"
      +" a rope this thick. You'll need to be wielding"
      +" something sharp!");
  }
  flag = 0;
  for (i=0;i<sizeof(obs);i++){
    if ((string)obs[i]->query_damage_type()== "slashing"){
      ob = obs[i];
      flag = 1;
    }
  }
  if (flag ==0){
    return notify_fail("You'll need to be holding"
      +" something sharp!");
  }
  ropes = "/d/atoyatl/bridge_monitor_d.c"->query_ropes();
  if (ropes <1){
    tell_object(TP, "The ropes are all cut already");
    return 1;
  }
  pos = "/d/atoyatl/bridge_monitor_d.c"->query_pos(TP);
  if (pos < 5 || pos >59){
    tell_object(TP, "You need to be further along the bridge to cut"
                   +" the rope.");
    return 1;
  }
  switch (ropes){
  case 0:
    return notify_fail("The ropes are all cut already");
    break;
  case 1:
    tell_object(TP, "You turn and begin cutting the last rope"
      +" with your "+ ob->query_name());
    tell_bridge(TPQCN + " turns and begins cutting the last rope"
      +" with " + TP->QP + " "+ ob->query_name(), TP);
    call_out("cut2",2, TP);
    return 1;
    break;
  case 2:
    tell_object(TP, "You turn and begin cutting the second last"
      +" rope with your "+ ob->query_name());
    tell_bridge(TPQCN + " turns and begins cutting the second"
      +" last rope with " + TP->QP + " "+ ob->query_name(), TP);
    call_out("cut2",2, TP);
    return 1;
    break;
  case 3:
    tell_object(TP, "You turn and begin cutting the second"
      +" rope with your "+ ob->query_name());
    tell_bridge(TPQCN + " turns and begins cutting the second"
      +" rope with " + TP->QP + " "+ ob->query_name(), TP);
    call_out("cut2",2, TP);
    return 1;
    break;
  case 4:
    tell_object(TP, "You turn and begin cutting the first"
      +" rope with your "+ ob->query_name());
    tell_bridge(TPQCN + " turns and begins cutting the first"
      +" rope with " + TP->QP + " "+ ob->query_name(), TP);
    call_out("cut2",4, TP);
    return 1;
    break;
  }
  return 1;
}

void cut2(object ob){
  if (!objectp(ob)) { return;}
  if (!present(ob, TO)){
    tell_object(ob, "You moved before you finished cutting the rope");
    return;
  }
  "/d/atoyatl/bridge_monitor_d.c"->cut_rope(ob);
}

string base_desc(){
  string desc, fn;
  desc = "You are on a precarious %^ORANGE%^rope bridge"
    +" %^RESET%^over a broad river %^ORANGE%^canyon"
    +" %^RESET%^that cuts through the %^BOLD%^%^GREEN%^j"
    +"%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^"
    +"%^GREEN%^l%^BOLD%^%^GREEN%^e%^RESET%^ here. The"
    +" bridge has wooden slats to walk on, and two of"
    +" the ropes form hand rails, but it would be all"
    +" too easy to be buffeted off by the strong winds"
    +" rushing by. ";
  fn =  file_name(TO);
  switch (atoi(fn[strlen(fn)])){
    case 1:
      desc += "You are near the %^BOLD%^%^WHITE%^west"
        +" %^RESET%^end of the bridge";
      break;
    case 2:
      desc += "You are to the %^BOLD%^%^WHITE%^west"
        +" %^RESET%^of the %^CYAN%^centre%^RESET%^ of"
        +" the bridge";
      break;
    case 3:
      desc += "You are to the %^BOLD%^%^WHITE%^east"
        +" %^RESET%^of the %^CYAN%^centre%^RESET%^ of"
        +" the bridge";
      break;
    case 4:
      desc += "You are near the %^BOLD%^%^WHITE%^east"
        +" %^RESET%^end of the bridge";
      break;
  }
  return desc;
}

string long_desc(){
  int ropes;
  string desc;
  ropes = "/d/atoyatl/bridge_monitor_d.c"->query_ropes();
  TP->force_me("check bridge");
  desc = base_desc();
  switch(ropes){
  case 0:
    desc += "%^GREEN%^The ropes of the %^ORANGE%^bridge%^GREEN%^"
      +" have been %^BOLD%^%^RED%^cut%^RESET%^%^GREEN%^,"
      +" and it swings uselessly down the sides of the"
      +" canyon.";
    break;
  case 1:
    desc += "%^GREEN%^All but one of the ropes of the%^ORANGE%^"
      +" bridge%^GREEN%^ have been %^BOLD%^%^RED%^cut"
      +"%^RESET%^%^GREEN%^, and it hangs precariously"
      +" by that one remaining thread.";
    break;
  case 2:
    desc += "%^GREEN%^Two of the ropes of the%^ORANGE%^"
      +" bridge%^GREEN%^ have been %^BOLD%^%^RED%^cut"
      +"%^RESET%^%^GREEN%^, and the remaining two are"
      +" swaying alarmingly";
    break;
  case 3:
    desc += "%^GREEN%^One of the hand ropes of the%^ORANGE%^"
      +" bridge%^GREEN%^ has been %^BOLD%^%^RED%^cut"
      +"%^RESET%^%^GREEN%^, but the three remaining"
      +" ropes seem reasonably secure.";
    break;
  case 4:
    break;
  }
  desc +=" %^GREEN%^You can %^RESET%^<check bridge>"
  +" %^GREEN%^to see if anyone is travelling across it, or"
  +" %^RESET%^<check positions>%^GREEN%^ if you prefer a"
  +" written description.";
  return desc;
}

int let_go(string str){
  if (!stringp(str)){
    return notify_fail("You want to let go of something?");
  }
  if (str!="go" && str != "go of rope" && str != "go of bridge"
       && str != "go rope" && str!="go bridge"){
    return notify_fail("Let go of what?");
  }
  if ((int)TP->query_property("gripped")!=1){
    tell_object(TP, "You aren't holding onto the bridge");
    return 1;
  }
  TP->remove_property("gripped");
  if ((int)"/d/atoyatl/bridge_monitor_d.c"->query_break_point() != -1){
    TP->force_me("fall off bridge");
    return 1;
  }
  tell_object(TP, "You let go of the rope");
  tell_room(TO, TPQCN + " lets go of the rope", TP);
  return 1;
}

int hold_on(string str){
  if (!stringp(str)){
    return notify_fail("You want to hold on to something?");
  }
  if (str!="bridge" && str != "on to bridge" && str != "on tight"
       && str != "tight to bridge" && str!="rope" && str != "on to rope"
       && str != "on tight to rope" && str != "tight to rope"){
    return notify_fail("Hold on to what?");
  }
  if ((int)TP->query_gripped()==1){
    tell_object(TP, "You are already holding on tightly to the bridge");
    return 1;
  }
  tell_object(TP, "You grab the ropes and hold on"
    +" %^BOLD%^%^CYAN%^tight%^RESET%^!");
  tell_object(TP, "You can %^BOLD%^%^YELLOW%^<let go>%^RESET%^ at any"
    +" time");
  tell_room(TO, TPQCN + " grabs the ropes and holds on"
    +" %^BOLD%^%^CYAN%^tight%^RESET%^!", TP);
  TP->set_property("gripped", 1);
  return 1;
}

int turn(string str){
  int face, dir;
  if (str == "undead"){
    return 0;
  }
  if ((int)"/d/atoyatl/bridge_monitor_d.c"->query_break_point()!=-1){
    if (!TP->query_property("flying")){
      tell_object(TP, "The bridge is broken, you can't turn round on"
        +" it!");
      return 1;
    }
  }
  face = "/d/atoyatl/bridge_monitor_d.c"->query_face(TP);
  dir = "/d/atoyatl/bridge_monitor_d.c"->query_dir(TP);
  if ((int)TP->query_property("gripped") == 1){
    tell_object(TP, "You are holding tight to the ropes. You'll need"
      +" to %^BOLD%^%^YELLOW%^let go%^RESET%^ to move!");
    return 1;
  }
  if (face == WEST){
    tell_object(TP, "You turn and face %^BOLD%^%^WHITE%^east");
    face = EAST;
  } else {
    tell_object(TP, "You turn and face %^BOLD%^%^WHITE%^west");
    face = WEST;
  }
  "/d/atoyatl/bridge_monitor_d"->set_face(TP, face);
  switch (dir){
  case EAST:
    tell_object(TP, "You are still travelling"
      +" %^BOLD%^%^WHITE%^east. Type%^CYAN%^"
      +" <stop>%^RESET%^ if you want to stop, or %^CYAN%^<west>"
      +" %^RESET%^if you want to go west");
    break;
  case WEST:
   tell_object(TP, "You are still travelling"
      +" %^BOLD%^%^WHITE%^west. Type%^CYAN%^"
      +" <stop>%^RESET%^ if you want to stop, or %^CYAN%^<east>"
      +" %^RESET%^if you want to go east");
    break;
  }
  return 1;
}

int fall_me(string str){
    if (!stringp(str) || strlen(str)<1 || (str != "off bridge" &&
      str != "down" && str != "into water")){
        return notify_fail("Just type 'fall' or 'fall down' to fall"
        +" off the bridge.");
    }
  if ((int)"/d/atoyatl/bridge_monitor_d.c"->query_break_point() == -1){
    tell_object(TP, "You swing your leg over the guide rope and drop"
      +" off the bridge");
    tell_bridge(TPQCN + "swings " + TP->QP + " leg over the guide"
      +" rope and drops off the bridge", TP);
  } else {
    tell_object(TP, "You let go of the bridge and let yourself fall");
    tell_bridge(TPQCN + "lets go of the bridge and lets " + TP->QP
      + "self fall.", TP);
  }
  "/d/atoyatl/bridge_monitor_d.c"->fall(TP);
  return 1;
}

int stop (string str){
  int dir, point;
  string v;
  point = "/d/atoyatl/bridge_monitor_d.c"->query_break_point();
  if (point >-1){
    if ((int)TP->query_property("flying")==1){
      v = "flying across the canyon";
    } else {
      v = "climbing";
    }
  } else {
    v = "walking";
  }
  if ((int)TP->query_property("flying")==1){
    v = "flying across the canyon";
  }
  dir = "/d/atoyatl/bridge_monitor_d.c"->query_dir(TP);
  if (dir != STATIONARY){
    tell_object(TP, "You stop " + v);
    tell_bridge(TPQCN + " stops " + v, TP);
  } else {
    tell_object(TP, "You're not " + v);
  }
  "/d/atoyatl/bridge_monitor_d.c"->set_dir(TP, STATIONARY);
  return 1;
}

int head_up(string str){
  int pos, dir, face, bp;
  string room, start_room, verb, where;
  if ((int)"/d/atoyatl/bridge_monitor_d.c"->query_break_point()==-1
        && !(int)TP->query_property("flying")){
    tell_object(TP, "You can't go up here");
    return 1;
  }
  start_room = file_name(ETP);
  if (start_room[0..strlen(JUNG_ROOM + "bbridge")-1]!= JUNG_ROOM
    + "bbridge" && (int)TP->query_property("flying")!=1){
    tell_object(TP, "You can't go up from here!");
    return 1;
  }
  bp = "/d/atoyatl/bridge_monitor_d.c"->query_break_point();
  pos = "/d/atoyatl/bridge_monitor_d.c"->query_pos(TP);
  dir = "/d/atoyatl/bridge_monitor_d.c"->query_dir(TP);
  face = "/d/atoyatl/bridge_monitor_d.c"->query_face(TP);
  if ((int)TP->query_property("flying")==1){
    verb = "flying";
    where = " upwards";
  } else {
    verb = "climbing";
    where = " up the broken bridge";
  }
  switch (dir){
  case ASCENDING:
    tell_object(TP, "You are already " + verb + " up.");
    return 1;
    break;
  case STATIONARY:
  case DESCENDING:
  default:
    tell_object(TP, "You begin " + verb + where);
    tell_bridge(TPQCN + " begins " + verb + where, TP);
    dir = ASCENDING;
    break;
  }
  set_PosDir(TP, ({pos, dir,face}));
  call_out("climb_up", 2, TP);
  return 1;
}

int head_down(string str){
  int pos, dir, face, bp;
  string room, start_room, verb, where;
  if ((int)"/d/atoyatl/bridge_monitor_d.c"->query_break_point()==-1
                         && !(int)TP->query_property("flying")){
    tell_object(TP, "You can't go down here");
    return 1;
  }
  bp = "/d/atoyatl/bridge_monitor_d.c"->query_break_point();
  start_room = file_name(ETP);
  if (start_room[0..strlen(JUNG_ROOM + "bbridge")-1]!= JUNG_ROOM
    + "bbridge" && !(int)TP->query_property("flying")&& bp ==-1){
    tell_object(TP, "You can't go that way from here!");
    return 1;
  }
  bp = "/d/atoyatl/bridge_monitor_d.c"->query_break_point();
  pos = "/d/atoyatl/bridge_monitor_d.c"->query_pos(TP);
  dir = "/d/atoyatl/bridge_monitor_d.c"->query_dir(TP);
  face = "/d/atoyatl/bridge_monitor_d.c"->query_face(TP);
  if ((int)TP->query_property("flying")==1){
    verb = "flying";
    where = " downward";
  } else {
    verb = "climbing";
    where = " down the broken bridge";
  }
  switch (dir){
  case DESCENDING:
    tell_object(TP, "You are already " + verb + " down.");
    return 1;
    break;
  case ASCENDING:
  case STATIONARY:
  default:
    tell_object(TP, "You begin " + verb + where);
    tell_bridge(TPQCN + " begins " + verb + where, TP);
    dir = DESCENDING;
    break;
  }
  set_PosDir(TP, ({pos, dir,face}));
  call_out("climb_down", 2, TP);
  return 1;
}

int head_west (string str){
  int pos, dir, face, len;
  string room, start_room, where;
  if ((int)"/d/atoyatl/bridge_monitor_d.c"->query_break_point()!=-1
            && !(int)TP->query_property("flying")){
    tell_object(TP, "The bridge is broken! You can't go west!");
    return 1;
  }
  where = "along the bridge";
  start_room = file_name(ETP);
  if (start_room[0..strlen(JUNG_ROOM + "ropebridge")-1]!= JUNG_ROOM
                                                    + "ropebridge"){
    if ( start_room[0..strlen(JUNG_ROOM + "bbridge")-1]== JUNG_ROOM
                                                       + "bbridge"){
      if (!(int)TP->query_property("flying")){
        tell_object(TP, "You can't go that way from here - you're"
          +" not flying!");
        return 1;
      } else {
        where = "across the canyon";
      }
    } else {
      tell_object(TP, "You can't go that way from here!");
      return 1;
    }
  }
  if ((int)TP->query_property("flying")==1){
    where = "across the canyon";
  }
  if ((int)TP->query_property("gripped") == 1){
    tell_object(TP, "You are holding tight to the ropes. You'll need to"
      +" %^BOLD%^%^YELLOW%^let go%^RESET%^ to move!");
    return 1;
  }
  pos = "/d/atoyatl/bridge_monitor_d.c"->query_pos(TP);
  dir = "/d/atoyatl/bridge_monitor_d.c"->query_dir(TP);
  face = "/d/atoyatl/bridge_monitor_d.c"->query_face(TP);
  switch (face){
  case WEST:
    switch (dir){
    case WEST:
      tell_object(TP, "You are %^RED%^already%^RESET%^ heading"
        +" %^BOLD%^%^WHITE%^west%^RESET%^ " + where);
      return 1;
      break;
    case EAST:
      tell_object(TP, "You %^BLUE%^reverse direction%^RESET%^, to"
         +" head %^BOLD%^%^WHITE%^west%^RESET%^ " + where);
      tell_room(TO, TPQCN + " %^BLUE%^reverses direction%^RESET%^, to"
         +" head %^BOLD%^%^WHITE%^west%^RESET%^ " + where, TP);
      dir = WEST;
      face = WEST;
      break;
    case STATIONARY:
    default:
      tell_object(TP, "You set off %^BOLD%^%^WHITE%^west%^RESET%^ "
        + where);
      tell_room(TO, TPQCN + "sets off %^BOLD%^%^WHITE%^west%^RESET%^ "
        + where, TP);
      dir = WEST;
      face = WEST;
      break;
    }
    break;
  case EAST:
  default:
    switch (dir){
    case WEST:
      tell_object(TP, "You are already walking %^BLUE%^backwards%^RESET%^,"
        +" heading %^BOLD%^%^WHITE%^west%^RESET%^ " + where);
      tell_object(TP, "You can <turn> if you want to face the other way.");
      return 1;
      break;
    case EAST:
      tell_object(TP, "You %^BLUE%^turn%^RESET%^ and head"
         +" %^BOLD%^%^WHITE%^west%^RESET%^ " + where);
      tell_room(TO, TPQCN + " %^BLUE%^turns%^RESET%^ and heads"
         +" %^BOLD%^%^WHITE%^west%^RESET%^ " + where, TP);
      dir = WEST;
      face = WEST;
      break;
    case STATIONARY:
    default:
      tell_object(TP, "You %^BOLD%^%^CYAN%^set off%^RESET%^"
         +" %^BOLD%^%^WHITE%^west%^RESET%^ " + where);
      tell_room(TO, TPQCN + " %^BOLD%^%^CYAN%^sets off%^RESET%^"
         +" %^BOLD%^%^WHITE%^west%^RESET%^ " + where, TP);
      dir = WEST;
      face = WEST;
      break;
    }
  }
  if (pos ==-1){
    room = file_name(TO);
    len = strlen(room) - 1;
    room = room [len..len];
    switch (room){
    case "0":
      pos = 3;
      break;
    case "1":
      pos = 16;
      break;
    case "2":
      pos  = 33;
      break;
    case "3":
      pos = 51;
      break;
    case "4":
      pos  = 63;
      break;
    default:
      pos  = 63;
      break;
    }
  }
  set_PosDir(TP, ({pos, dir,face}));
  call_out("go_west", 2, TP);
  return 1;
}

void pull2(object puller, object pulled){
  int str1, str2, BAB, AC, siz1, siz2, roll, i, count;
  object * critters;
  string how;
  if (!objectp(puller)){ return;}
  if (!objectp(pulled)){
    tell_object(puller, "Your target is not here, so you can't pull"
      +" them off the bridge.");
    return;
  }
  puller->set_property("pulled", time());
  str1 = puller->query_stats("strength");
  str2 = pulled->query_stats("strength");
  siz1 = (int)puller->query_size()*10;
  siz2 = (int)pulled->query_size()*10;
  BAB = "/daemon/bonus_d.c"->new_bab(1, puller);
  AC = "/daemon/bonus_d.c"->effective_ac(pulled);
  roll = random(20);
  critters = "/d/atoyatl/bridge_monitor_d.c"->query_crossers();
  count = sizeof(critters);
  if (roll<19){ //auto hit on a natural 20
    if (roll + BAB < AC){
      tell_object(puller, "You try to grab " + puller->QCN + " by the"
        +" ankle, but miss!");
      tell_object(pulled, puller->QCN + " tries to grab you by the"
        +" ankle, but misses!");
      if (count>0){
        for (i=0;i<count;i++){
          if (objectp(critters[i])&&critters[i]!=puller && critters[i]!= pulled){
            tell_object(critters[i], puller->QCN + " tries to grab "
              + pulled->QCN + " by the ankle, but misses!");
          }
        }
      }
      return;
    }
  }
  str1 = str1 + random(str1);
  siz1 = siz1+ random(siz1);
  str2 = str2 + random(str2);
  siz2 = siz2 + random(siz2);
  if ((str1 - str2) > (siz1-siz2)){
    how = "superior strength";
  } else {
    how = "greater size";
  }
  if (str1 + siz1>str2 + siz2){
    tell_object(puller, "You grab " + pulled->QCN + " by the ankle and use your " + how
      + " to yank " + pulled ->QO + " off the bridge!");
    tell_object(pulled, puller->QCN + " grabs you by the ankle and uses " + puller->QP
      + " " + how + " to pull you off the bridge!");
    if (count>0){
      for (i=0;i<count;i++){
        if (objectp(critters[i])&&critters[i]!=puller && critters[i]!= pulled){
          tell_object(critters[i], puller->QCN + " grabs " + pulled->QCN
          + " by the ankle and uses " + puller->QP + " " + how + " to pull "
          + pulled->QO + " off the bridge!");
        }
      }
    }
    "/d/atoyatl/bridge_monitor_d.c"->fall(pulled);
  } else {
    tell_object(puller, "You grab " + pulled->QCN + " by the ankle, but you don't"
      +" manage to yank " + pulled ->QO + " off the bridge and " + pulled->QS
      + " kicks free of your grip.");
    tell_object(pulled, puller->QCN + " grabs you by the ankle and tries to pull"
      +" you off the bridge, but you manage to kick free of " + puller->QP + " grip.");
    if (count>0){
      for (i=0;i<count;i++){
        if (objectp(critters[i])&&critters[i]!=puller && critters[i]!= pulled){
          tell_object(critters[i], puller->QCN + " grabs " + pulled->QCN
          + " by the ankle, but " + pulled->QCN +" kicks free of  " + puller->QP
          + " grip.");
        }
      }
    }
  }
}

int pull (string str){
  object who, * critters;
  int i, count, nm;
  string true_name, name, where;
  if ((int)"/d/atoyatl/bridge_monitor_d.c"->query_break_point()==-1){
    return notify_fail("You can't really pull anyone off the bridge at"
    +" the moment. You might be able to push someone, if you were close"
    +" enough.");
  }
  if (TP->query_property("pulled") > time()-5 &&
           TP->query_property("pulled")<time()+ 5){
    return notify_fail("You are still recovering from your last attempt to"
      +" dislodge someone from the bridge");
  }
  nm = sscanf(str, "%s from the %s", name, where);
  if (nm<2){
    nm = sscanf(str, "%s from %s", name, where);
  }
  if (nm<2){
    nm = sscanf(str, "%s off of the %s", name, where);
  }
  if (nm<2){
    nm = sscanf(str, "%s off of %s", name, where);
  }
  if (nm<2){
    nm = sscanf(str, "%s off the %s", name, where);
  }
  if (nm<2){
    nm = sscanf(str, "%s off %s", name, where);
  }
  if (nm<2){
    return notify_fail("who do you want to pull off of where?");
  }
  if (!stringp(name)){
    return notify_fail("Who do you want to pull from where?");
  }
  if (!stringp(where) || (where != "bridge" && where!= "broken bridge"
             && where != "ropebridge" && where != "the ropebridge")){
    tell_object(TP, "Since you are on the %^BOLD%^%^WHITE%^bridge"
      +"%^RESET%^, the only place you could %^BOLD%^%^WHITE%^pull"
      +" %^RESET%^someone from is there.");
    return 1;
  }
  critters = "/d/atoyatl/bridge_monitor_d.c"->query_crossers();
  count = sizeof(critters);
  if (count<1){
    return notify_fail("There's no-one on the bridge for you to pull");
  }
  if (count ==1 && member_array(TP, critters) != -1){
    return notify_fail("There's no-one else on the bridge for you to pull");
  }
  for (i = 1; i<count;i++){
    if (critters[i]==TP) { continue;}
    true_name = critters[i]->query_name();
    if (TP->isKnown(true_name)){
      if ( (string)TP->knownAs(name)==true_name){
        name = true_name;
      }
    }
    if (critters[i]->id(name)){
      who = critters[i];
      if ("d/atoyatl/bridge_monitor_d.c"->can_reach(TP, who) &&
          "d/atoyatl/bridge_monitor_d.c"->is_above(who, TP)){
        pull2(TP, who);
        TP->set_property("pulled", time());
        return 1;
      }
    }
  }
  return 0;
}

void kick2(object kicker, object kicked){
  int str1, str2, BAB, AC, siz1, siz2, roll, i, count;
  object * critters;
  string how;
  if (!objectp(kicker)){ return;}
  if (!objectp(kicked)){
    tell_object(kicker, "Your target is not here, so you can't kick"
      +" them off the bridge.");
    return;
  }
  kicker->set_property("pulled", time());
  str1 = kicker->query_stats("strength");
  str2 = kicked->query_stats("strength");
  siz1 = (int)kicker->query_size()*10;
  siz2 = (int)kicked->query_size()*10;
  BAB = "/daemon/bonus_d.c"->new_bab(1, kicker);
  AC = "/daemon/bonus_d.c"->effective_ac(kicked);
  roll = random(20);
  critters = "/d/atoyatl/bridge_monitor_d.c"->query_crossers();
  count = sizeof(critters);
  if (roll<19){ //auto hit on a natural 20
    if (roll + BAB < AC){
      tell_object(kicker, "You try to grab " + kicker->QCN + " by the"
        +" ankle, but miss!");
      tell_object(kicked, kicker->QCN + " tries to grab you by the"
        +" ankle, but misses!");
      if (count>0){
        for (i=0;i<count;i++){
          if (objectp(critters[i])&&critters[i]!=kicker && critters[i]!= kicked){
            tell_object(critters[i], kicker->QCN + " tries to kick down at "
              + kicked->QCN + ", but misses!");
          }
        }
      }
      return;
    }
  }
  str1 = str1 + random(str1);
  siz1 = siz1+ random(siz1);
  str2 = str2 + random(str2);
  siz2 = siz2 + random(siz2);
  if (str1 + siz1>str2 + siz2){
    tell_object(kicker, "You kick out at " + kicked->QCN + " and knock " + kicked ->QO
      + " off the bridge!");
    tell_object(kicked, kicker->QCN + " kicks out at you and knocks you off the bridge!");
    if (count>0){
      for (i=0;i<count;i++){
        if (objectp(critters[i])&&critters[i]!=kicker && critters[i]!= kicked){
          tell_object(critters[i], kicker->QCN + " kicks out at " + kicked->QCN
          + " and knocks " + kicker->QP + " off the bridge!");
        }
      }
    }
    "/d/atoyatl/bridge_monitor_d.c"->fall(kicked);
  } else {
    if ((str2 - str1) > (siz2-siz1)){
      how = " too strong";
    } else {
      how = " too big";
    }
    tell_object(kicker, "You kick down at " + kicked->QCN + "and connect, but "
      + kicked->QS +" is " + how + " for you to knock " + kicked->QO
      + " off the bridge.");
    tell_object(kicked, kicker->QCN + " kicks down at you and connects, but you are "
      + how  +" for " + kicker->QO + " to knock you off the bridge.");
    if (count>0){
      for (i=0;i<count;i++){
        if (objectp(critters[i])&&critters[i]!=kicker && critters[i]!= kicked){
          tell_object(critters[i], kicker->QCN + " kicks down at " + kicked->QCN
          + " and connects, but " + kicked->QCN + " is" + how + " for  "
          + kicker->QO + " to knock " + kicked->QO + " off the bridge.");
        }
      }
    }
  }
}

int kick (string str){
  object who, * critters;
  int i, count, nm;
  string true_name, name, where;
  if ((int)"/d/atoyatl/bridge_monitor_d.c"->query_break_point()==-1){
    return notify_fail("You can't really kick anyone off the bridge at"
    +" the moment. You might be able to push someone, if you were close"
    +" enough.");
  }
  if (TP->query_property("pulled") > time()-5 &&
           TP->query_property("pulled")<time()+ 5){
    return notify_fail("You are still recovering from your last attempt to"
      +" dislodge someone from the bridge");
  }
  nm = sscanf(str, "%s off of the %s", name, where);
  if (nm<2){
    nm = sscanf(str, "%s off of %s", name, where);
  }
  if (nm<2){
    nm = sscanf(str, "%s off the %s", name, where);
  }
  if (nm<2){
    nm = sscanf(str, "%s off %s", name, where);
  }
  if (nm<1){
    return notify_fail("who do you want to kick?");
  }
  if (!stringp(name)){
    return notify_fail("Who do you want to kick?");
  }
  if (!stringp(where) || (where != "bridge" && where!= "broken bridge"
             && where != "ropebridge" && where != "the ropebridge")){
    tell_object(TP, "Since you are on the %^BOLD%^%^WHITE%^bridge"
      +"%^RESET%^, the only place you could %^BOLD%^%^WHITE%^kick"
      +" %^RESET%^someone from is there.");
    return 1;
  }
  critters = "/d/atoyatl/bridge_monitor_d.c"->query_crossers();
  count = sizeof(critters);
  if (count<1){
    return notify_fail("There's no-one on the bridge for you to kick");
  }
  if (count ==1 && member_array(TP, critters) != -1){
    return notify_fail("There's no-one else on the bridge for you to kick");
  }
  for (i = 1; i<count;i++){
    if (critters[i]==TP) { continue;}
    true_name = critters[i]->query_name();
    if (TP->isKnown(true_name)){
      if ( (string)TP->knownAs(name)==true_name){
        name = true_name;
      }
    }
    if (critters[i]->id(name)){
      who = critters[i];
      if ("d/atoyatl/bridge_monitor_d.c"->can_reach(TP, who)){
        if ( "d/atoyatl/bridge_monitor_d.c"->is_below(who, TP)){
          kick2(TP, who);
          TP->set_property("pulled", time());
          return 1;
        }
      }
    }
  }
  return 0;
}


int head_east(string str){
  int pos, dir, face, len;
  string room, start_room, where;
  if ((int)"/d/atoyatl/bridge_monitor_d.c"->query_break_point()!=-1
      && !(int)TP->query_property("flying")){
    tell_object(TP, "The bridge is broken! You can't go east!");
    return 1;
  }
  if ((int)TP->query_property("gripped") == 1){
    tell_object(TP, "You are holding tight to the ropes. You'll need to"
      +" %^BOLD%^%^YELLOW%^let go%^RESET%^ to move!");
    return 1;
  }
  start_room = file_name(ETP);
  where = "along the bridge";
  if (start_room[0..strlen(JUNG_ROOM + "ropebridge")-1]!= JUNG_ROOM
                                                     + "ropebridge"){
    if ( start_room[0..strlen(JUNG_ROOM + "bbridge")-1]== JUNG_ROOM
                                                        + "bbridge"){
      if (!(int)TP->query_property("flying")){
        tell_object(TP, "You can't go that way from here - you're"
          +" not flying!");
        return 1;
      } else {
        where = "across the canyon";
      }
    } else {
      tell_object(TP, "You can't go that way from here!");
      return 1;
    }
  } else {
    if (start_room[strlen(JUNG_ROOM + "ropebridge0")-1]== '0'
        || start_room[strlen(JUNG_ROOM + "ropebridge0")-1] == '5'){
      if ((int)"/d/atoyatl/bridge_monitor_d.c"->query_break_point() > -1
                          && (int)TP->query_property("flying")==1){
        where = "across the canyon";
      }
    }
  }
  if ((int)TP->query_property("flying")==1){
    where = "across the canyon";
  }
  pos = "/d/atoyatl/bridge_monitor_d.c"->query_pos(TP);
  dir = "/d/atoyatl/bridge_monitor_d.c"->query_dir(TP);
  face = "/d/atoyatl/bridge_monitor_d.c"->query_face(TP);
  switch (face){
  case EAST:
    switch (dir){
    case EAST:
      tell_object(TP, "You are %^RED%^already%^RESET%^ heading"
        +" %^BOLD%^%^WHITE%^east%^RESET%^ " + where);
      return 1;
      break;
    case WEST:
      tell_object(TP, "You %^BLUE%^reverse direction%^RESET%^ to"
         +" move forward, %^BOLD%^%^WHITE%^east%^RESET%^ " + where);
      tell_room(TO, TPQCN + " %^BLUE%^reverses direction%^RESET%^ to"
        +" move forward, %^BOLD%^%^WHITE%^east%^RESET%^ " + where, TP);
      dir = EAST;
      face = EAST;
      set_PosDir(TP, ({pos, dir,face}));
      call_out("go_east", 1, TP);
      return 1;
      break;
    case STATIONARY:
    default:
      tell_object(TP, "You set off %^BOLD%^%^WHITE%^east%^RESET%^ "
        + where);
      tell_room(TO, TPQCN + "sets off %^BOLD%^%^WHITE%^east%^RESET%^ "
        + where, TP);
      dir = EAST;
      face = EAST;
      set_PosDir(TP, ({pos, dir,face}));
      call_out("go_east", 1, TP);
      return 1;
      break;
    }
    break;
  case WEST:
  default:
    switch (dir){
    case EAST:
      tell_object(TP, "You are already moving %^BLUE%^backwards%^RESET%^,"
        +" heading %^BOLD%^%^WHITE%^east%^RESET%^ " + where);
      tell_object(TP, "You can <turn> if you want to face the other way.");
      return 1;
      break;
    case WEST:
      tell_object(TP, "You %^BLUE%^turn%^RESET%^ and head"
         +" %^BOLD%^%^WHITE%^east%^RESET%^ " + where);
      tell_room(TO, TPQCN + " %^BLUE%^turns%^RESET%^ and heads"
         +" %^BOLD%^%^WHITE%^east%^RESET%^ " + where, TP);
      dir = EAST;
      face = EAST;
      break;
    case STATIONARY:
    default:
      tell_object(TP, "You %^BOLD%^%^CYAN%^set off%^RESET%^"
         +" %^BOLD%^%^WHITE%^east%^RESET%^ " + where);
      tell_room(TO, TPQCN + " %^BOLD%^%^CYAN%^sets off%^RESET%^"
         +" %^BOLD%^%^WHITE%^east%^RESET%^ " + where, TP);
      dir = EAST;
      face = EAST;
      break;
    }
  }
  if (pos == -1){
    room = file_name(TO);
    len = strlen(room) - 1;
    room = room [len..len];
    switch (room){
    case "0":
      pos = 1;
      break;
    case "1":
      pos = 14;
      break;
    case "2":
      pos  = 27;
      break;
    case "3":
      pos = 40;
      break;
    case "4":
      pos  = 53;
      break;
    default:
      pos  = 65;
      break;
    }
  }
  set_PosDir(TP, ({pos, dir,face}));
  call_out("go_east", 2, TP);
  return 1;
}

int has_moved_east(int pos, int dist){
  switch (dist){
  case 1:
    switch (pos){
    case 17:
    case 33:
    case 49:
      return 1;
    }
    break;
  case 2:
    switch (pos){
    case 17..18:
    case 33..34:
    case 49..50:
      return 1;
    }
    break;
  }
  return 0;
}

int has_moved_west(int pos, int dist){
  switch (dist){
  case 1:
    switch (pos){
    case 16:
    case 32:
    case 48:
      return 1;
    }
    break;
  case 2:
    switch (pos){
    case 17..18:
    case 33..34:
    case 49..50:
      return 1;
    }
    break;
  }
  return 0;
}

string get_correct_room(int pos){
  int break_point;
  break_point = "/d/atoyatl/bridge_monitor_d.c"->query_break_point();
  if (break_point == -1){
    switch(pos){
    case -1..1:
      return JUNG_ROOM + "ropebridge0";
      break;
    case 2..16:
      return JUNG_ROOM +"ropebridge1";
      break;
    case 17..32:
      return JUNG_ROOM +"ropebridge2";
      break;
    case 33..48:
      return JUNG_ROOM +"ropebridge3";
      break;
    case 49..63:
      return JUNG_ROOM +"ropebridge4";
      break;
    case 64..68:
      return JUNG_ROOM + "ropebridge5";
      break;
    }
  } else {
    if (pos <= break_point){
      switch (pos){
      case -2..1:
        return JUNG_ROOM + "ropebridge0";
        break;
      case 2..16:
        return JUNG_ROOM +"bbridge_w1";
        break;
      case 18..32:
        return JUNG_ROOM +"bbridge_w2";
        break;
      case 34..48:
        return JUNG_ROOM +"bbridge_w3";
        break;
      case 49..63:
        return JUNG_ROOM +"bbridge_w4";
        break;
      case 64..68:
        return JUNG_ROOM + "ropebridge5";
        break;
      }
    } else {
      switch (pos){
      case -2..1:
        return JUNG_ROOM + "ropebridge0";
        break;
      case 2..16:
        return JUNG_ROOM +"bbridge_e4";
        break;
      case 17..32:
        return JUNG_ROOM +"bbridge_e3";
        break;
      case 33..48:
        return JUNG_ROOM +"bbridge_e2";
        break;
      case 49..63:
        return JUNG_ROOM +"bbridge_e1";
        break;
      case 64..68:
        return JUNG_ROOM + "ropebridge5";
        break;
      }
    }
  }
}

void tell_bridge( string str, object ob){
  "/d/atoyatl/bridge_monitor_d.c"->tell_bridge( str, ob);
}

void climb_up(object ob){
  int i, j, pos, dist, ath, dir, face, break_point, top, fly1, fly2;
  object room, occupier, * critters;
  string movement, movementb, correct_room, room_name, who, *pic;
  break_point = "/d/atoyatl/bridge_monitor_d.c"->query_break_point();
  pos = "/d/atoyatl/bridge_monitor_d.c"->query_pos(ob);
  face = "/d/atoyatl/bridge_monitor_d.c"->query_face(ob);
  dir = "/d/atoyatl/bridge_monitor_d.c"->query_dir(ob);
  if (dir != ASCENDING){
    tell_object(ob, "You are no longer going up");
    return 1;
  }
  correct_room = get_correct_room(pos);
  if(file_name(TO)!=correct_room){
    room = find_object_or_load( correct_room);
    if (objectp(room)){
      if(present(ob, room)){
        room->climb_up(ob);
        return 1;
      }
      tell_room(TO, ob->QCN + " moves to another part of the bridge.", ob);
      tell_room(room, ob->QCN + " arrives from another part of the bridge.", ob);
      tell_object(ob, "You move to another part of the bridge");
      ob->move(room);
      ob->force_me("look");
      room->climb_up(ob);
      return 1;
    }
  }
  top = 0;
  if (pos<= break_point){
    top = pos;
    i = -1;
  } else {
    top = pos + "/d/atoyatl/bridge_monitor_d"->query_height(ob);
    i = 1;
  }
  ath = ob->query_skill("athletics");
  if (ath>20){
    dist = 2;
    movement = "scale";
    movementb = " the bridge rapidly, with practiced climbing technique.";
  } else {
    dist = 1;
    movement = "climb";
    movementb = " slowly up the bridge.";
  }
  if ((int)ob->query_property("flying")==1){
    movement = "fly";
    movementb = " swiftly up the canyon.";
    dist = 2;
  }
  dist = dist * i;
  critters = "/d/atoyatl/bridge_monitor_d.c"->query_crossers();
  if (sizeof(critters)>1){
    for (j = 0;j<sizeof(critters);j++){
      if (critters[j]==ob){continue;}
      if ((int)"/d/atoyatl/bridge_monitor_d.c"->can_reach(ob, critters[j])== 1 &&
            (int)"/d/atoyatl/bridge_monitor_d.c"->is_above( critters[j], ob)==1 ){
        fly1 = ob->query_property("flying");
        fly2 = critters[j]->query_property("flying");
        if (fly1 != fly2 || fly1 == 1){
          continue;
        }
        who = critters[j]->query_name();
        if (ob->isKnown(who)){
          who = capitalize(ob->knownAs(who));
        } else {
          who = critters[j]->query_short();
        }
        tell_object(ob, "%^BOLD%^%^YELLOW%^You can't go any further. " + who
          + " %^BOLD%^%^YELLOW%^is in your way. If " +  critters[j]->QS
          + " won't let you past, your only option may be to"
          +" %^BOLD%^%^WHITE%^pull%^BOLD%^%^YELLOW%^ or"
          +" %^BOLD%^%^WHITE%^drag%^BOLD%^%^YELLOW%^ " + critters[j]->QO
          + " off the bridge.");
        return;
      }
    }
  }
  tell_object(ob, "You " + movement + movementb);
  tell_bridge(ob->QCN + movement + "s" + movementb, ob);
  if ((int)ob->query_property("flying")==1){
    "/d/atoyatl/bridge_monitor_d.c"->set_VPos(ob,
                       (int)"/d/atoyatl/bridge_monitor_d.c"->query_vPos(ob) - 2);
    pic = "/d/atoyatl/bridge_monitor_d.c"->get_picture(ob, TP);
    if ((int)"/d/atoyatl/bridge_monitor_d.c"->query_vPos(ob) < 0){
      "/d/atoyatl/bridge_monitor_d.c"->set_VPos(ob, 0);
      tell_object(ob, "You can't fly any higher!");
      return;
    }
  }
  if ((int)ob->query_property("flying")!=1){
    pos = pos + dist;
  }
  room_name = correct_room;
  correct_room = get_correct_room(pos);
  if (room_name != correct_room){
    switch(correct_room){
    case JUNG_ROOM + "ropebridge5":
    case JUNG_ROOM + "ropebridge0":
      tell_object(ob, "%^CYAN%^You finally %^RESET%^clamber%^CYAN%^ over the"
        +" edge of the canyon and onto %^ORANGE%^solid ground%^CYAN%^.");
      tell_bridge("%^CYAN%^"+ ob->QCN + "%^RESET%^%^CYAN%^ finally%^RESET%^"
        +" clambers%^CYAN%^ over the edge of the canyon and onto%^ORANGE%^"
        +" solid ground%^CYAN%^.", ob);
      if (pos <1){pos = 1;}
      if (pos >64){pos = 64;}
      break;
    case JUNG_ROOM + "bbridge_e1":
    case JUNG_ROOM + "bbridge_w1":
      tell_object(ob, "%^CYAN%^You are getting close to the top of the canyon");
      tell_bridge("%^CYAN%^"+ ob->QCN + "%^RESET%^%^CYAN%^ is getting close"
        +" to the top of the %^ORANGE%^canyon%^CYAN%^.", ob);
      break;
    case JUNG_ROOM + "bbridge_e2":
    case JUNG_ROOM + "bbridge_w2":
      tell_object(ob, "%^CYAN%^You are making some progress up the canyon");
      tell_bridge("%^CYAN%^"+ ob->QCN + "%^RESET%^%^CYAN%^ is making some"
        +" progress up the %^ORANGE%^canyon%^CYAN%^.", ob);
      break;
    case JUNG_ROOM + "bbridge_e3":
    case JUNG_ROOM + "bbridge_w3":
      tell_object(ob, "%^CYAN%^You have moved up from the lowest point of"
        +" the %^RESET%^broken bridge%^CYAN%^.");
      tell_bridge("%^CYAN%^"+ ob->QCN + "%^RESET%^%^CYAN%^ has moved up from"
        +" the lowest point of the%^RESET%^ broken bridge%^CYAN%^.", ob);
      break;
    case JUNG_ROOM + "bbridge_e4":
    case JUNG_ROOM + "bbridge_w4":
      tell_object(ob, "%^CYAN%^You are at the bottom of"
        +" the %^RESET%^broken bridge%^CYAN%^.");
      tell_bridge("%^CYAN%^"+ ob->QCN + "%^RESET%^%^CYAN%^ is at the"
        +" bottom of the%^RESET%^ broken bridge%^CYAN%^.", ob);
      break;
    }
    room = find_object_or_load(correct_room);
    tell_room(environment(ob), ob->QCN + " climbs out of reach.", ob);
    if (objectp(room)){
      ob->move(room);
      ob->force_me("look");
    }
  }
  if (pos <1){pos = 1;}
  if (pos >64){pos = 64;}
//adjust their position
  set_PosDir(ob, ({pos, ASCENDING, face}));
  if (pos > 1 && pos <64 || (int)ob->query_property("flying")==1){
    call_out("climb_up", 2, ob);
  }
  return 1;
}

int climb_down(object ob){
  int i, j, pos, dist, ath, face, break_point, dir, fly1, fly2, bridge_height;
  object room, * critters;
  string movement, movementb, correct_room, room_name, who, *pic;
  break_point = "/d/atoyatl/bridge_monitor_d.c"->query_break_point();
  pos = "/d/atoyatl/bridge_monitor_d.c"->query_pos(ob);
  face = "/d/atoyatl/bridge_monitor_d.c"->query_face(ob);
  dir = "/d/atoyatl/bridge_monitor_d.c"->query_dir(ob);
  if (dir != DESCENDING){
    tell_object(ob, "You are no longer going down");
    return 1;
  }
  correct_room = get_correct_room(pos);
  if(file_name(TO)!=correct_room){
    room = find_object_or_load( correct_room);
    if (objectp(room)){
      if(present(ob, room)){
        room->climb_down(ob);
        return 1;
      }
      if ((int)ob->query_property("flying")){
        tell_room(TO, ob->QCN + " flies to another level of the canyon.", ob);
        tell_room(room, ob->QCN + " flies in from another level of the canyon.", ob);
        tell_object(ob, "You fly to another level of the canyon");
      } else {
        tell_room(TO, ob->QCN + " moves to another part of the bridge.", ob);
        tell_room(room, ob->QCN + " arrives from another part of the bridge.", ob);
        tell_object(ob, "You move to another part of the bridge");
      }
      ob->move(room);
      ob->force_me("look");
      room->climb_down(ob);
      return 1;
    }
  }
  if (pos<= break_point){
    i = 1;
  } else {
    i = -1;
  }
  ath = ob->query_skill("athletics");
  if (ath>20){
    dist = 2;
    movement = "descend";
    movementb = " the bridge rapidly, with practiced climbing technique.";
  } else {
    dist = 1;
    movement = "climb";
    movementb = " slowly down the bridge.";
  }
  if ((int)ob->query_property("flying")){
    dist = 2;
    movement = "fly swiftly down";
    movementb = " the canyon.";
  }
  dist = dist * i;
  critters = "/d/atoyatl/bridge_monitor_d.c"->query_crossers();
  if (sizeof(critters)>1){  // check for other creatures in your way
    for (j = 0;j<sizeof(critters);j++){
      if (critters[j]==ob){continue;}
      if ((int)"/d/atoyatl/bridge_monitor_d.c"->can_reach(ob, critters[j])== 1 &&
            (int)"/d/atoyatl/bridge_monitor_d.c"->is_below( critters[j], ob)==1 ){
        fly1 = ob->query_property("flying");
        fly2 = critters[j]->query_property("flying");
        if (fly1 != fly2 || fly1 == 1){
          continue;
        }
        who = critters[j]->query_name();
        if (ob->isKnown(who)){
          who = capitalize(ob->knownAs(who));
        } else {
          who = critters[j]->query_short();
        }
        tell_object(ob, "%^BOLD%^%^YELLOW%^You can't go any further. " + who
          + " %^BOLD%^%^YELLOW%^is in your way. If " +  critters[j]->QS
          + " won't let you past, your only option may be to"
          +" %^BOLD%^%^WHITE%^kick%^BOLD%^%^YELLOW%^ " + critters[j]->QO
          + " off the bridge.");
        return -1;
      }
    }
  }
  if ((int)ob->query_property("flying")){
    "/d/atoyatl/bridge_monitor_d.c"->set_VPos(ob,
                          "/d/atoyatl/bridge_monitor_d.c"->query_vPos(ob) + 2);
    pic = "/d/atoyatl/bridge_monitor_d.c"->get_picture(ob, TP);
    if (break_point>-1){
      bridge_height = 27;
    } else {
      bridge_height = 20;
    }
    if ("/d/atoyatl/bridge_monitor_d.c"->query_vPos(ob) >
                                             bridge_height - sizeof(pic)+1){
      "/d/atoyatl/bridge_monitor_d.c"->set_VPos(ob, bridge_height - sizeof(pic)+1);
      tell_object(ob, "You can't fly any lower while staying in touch with"
        +" the bridge.");
      tell_object(ob, "You can %^BOLD%^%^WHITE%^<fly down>%^RESET%^ if you"
        +" want to land on the canyon floor");
      "/d/atoyatl/bridge_monitor_d.c"->set_dir(TP, STATIONARY);
      return 1;
    }
  }
  if (((pos < break_point && pos + dist > break_point )||
                      (pos > break_point && pos + dist < break_point))
                                     && (int)ob->query_property("flying")!=1){
    tell_object(ob, "%^ORANGE%^You are at the very bottom of the%^RESET%^"
      +" bridge%^ORANGE%^. If you want to go further, you'll have to%^RESET%^"
      +" <fall>");
    tell_bridge("%^ORANGE%^" + ob->QCN + " has reached the very bottom of the"
      +" bridge!", ob);
    ob->force_me("stop");
    return 1;
  }
  if (!ob->query_property("flying")){
    pos = pos + dist;
  }
  tell_object(ob, "You " + movement + movementb);
  tell_bridge(ob->QCN + movement + "s" + movementb, ob);
  if (pos > break_point ){
    if (pos - 2 < break_point && (int)ob->query_property("flying")!=1){
      tell_object(ob, "%^RED%^You are getting close to the bottom of the"
        +" %^RESET%^broken bridge%^RED%^!");
    }
  } else {
    if (pos + 2 > break_point && (int)ob->query_property("flying")!=1){
      tell_object(ob, "%^RED%^You are getting close to the bottom of the"
        +" %^RESET%^broken bridge%^RED%^!");
    }
  }
  room_name = correct_room;
  correct_room = get_correct_room(pos);
  if (room_name != correct_room){
    switch(correct_room){
    case JUNG_ROOM + "bbridge_e1":
    case JUNG_ROOM + "bbridge_w1":
      tell_object(ob, "%^CYAN%^You are close to the top of the canyon");
      tell_bridge("%^CYAN%^"+ ob->QCN + "%^RESET%^%^CYAN%^ is close"
        +" to the top of the %^ORANGE%^canyon%^CYAN%^.", ob);
      break;
    case JUNG_ROOM + "bbridge_e2":
    case JUNG_ROOM + "bbridge_w2":
      tell_object(ob, "%^CYAN%^You some way from the top of the canyon");
      tell_bridge("%^CYAN%^"+ ob->QCN + "%^RESET%^%^CYAN%^ is some way"
        +" from the top of the %^ORANGE%^canyon%^CYAN%^.", ob);
      break;
    case JUNG_ROOM + "bbridge_e3":
    case JUNG_ROOM + "bbridge_w3":
      tell_object(ob, "%^CYAN%^You are near the bottom of"
        +" the %^RESET%^broken bridge%^CYAN%^.");
      tell_bridge("%^CYAN%^"+ ob->QCN + "%^RESET%^%^CYAN%^ is near the"
        +" bottom of the%^RESET%^ broken bridge%^CYAN%^.", ob);
      break;
    case JUNG_ROOM + "bbridge_e4":
    case JUNG_ROOM + "bbridge_w4":
      tell_object(ob, "%^CYAN%^You are at the bottom of"
        +" the %^RESET%^broken bridge%^CYAN%^.");
      tell_bridge("%^CYAN%^"+ ob->QCN + "%^RESET%^%^CYAN%^ is at the"
        +" bottom of the%^RESET%^ broken bridge%^CYAN%^.", ob);
      break;
    }
    room = find_object_or_load(correct_room);
    tell_room(environment(ob), ob->QCN + " descends out of reach.", ob);
    if (objectp(room)){
      ob->move(room);
      ob->force_me("look");
    }
  }
  if (pos <1){pos = 0;}
  if (pos >64){pos = 65;}
//adjust their position
  set_PosDir(ob, ({pos, DESCENDING, face}));
  if (pos > 1 && pos <64 ||(int)ob->query_property("flying")==1){
    call_out("climb_down", 2, ob);
  }
  return 1;
}

void go_west(object ob){
  int i, pos, dist, face, dir, fly1, fly2;
  object room, moveroom, occupier;
  string movement, movementb, correct_room, obstacle, where, start_room;
  face = WEST;
  dir = "/d/atoyatl/bridge_monitor_d.c"->query_dir(ob);
  if (dir !=WEST){
    return;
  }
  if ((int)TP->query_property("gripped") == 1){
    tell_object(TP, "You stop moving, as you are holding tight to the"
      +" ropes.");
    "/d/atoyatl/bridge_monitor_d.c"->set_dir(ob, STATIONARY);
    return;
  }
  pos = "/d/atoyatl/bridge_monitor_d.c"->query_pos(ob);
  face = "/d/atoyatl/bridge_monitor_d.c"->query_face(ob);
// First make sure they are in the right room, according to their
// position on the bridge
  correct_room = get_correct_room(pos);
  where = "the bridge";
  start_room = file_name(ETP);
  if (start_room[0..strlen(JUNG_ROOM + "ropebridge")-1]!= JUNG_ROOM
                                                    + "ropebridge"){
    if ( start_room[0..strlen(JUNG_ROOM + "bbridge")-1]== JUNG_ROOM
                                                       + "bbridge"){
      if (!(int)TP->query_property("flying")){
        tell_object(TP, "You can't go east any more - you're"
          +" not flying!");
        "/d/atoyatl/bridge_monitor_d.c"->set_dir(ob, STATIONARY);
        return;
      } else {
        where = "across the canyon";
      }
    } else {
      tell_object(TP, "You can't go east from here, so you stop moving");
      "/d/atoyatl/bridge_monitor_d.c"->set_dir(ob, STATIONARY);
      return;
    }
  }
  if(file_name(TO)!=correct_room){
    room = find_object_or_load( correct_room);
    if (objectp(room)){
      if(present(ob, room)){
        room->go_west(ob);
        return;
      }
      tell_room(TO, ob->QCN + " moves to another part of " + where + ".", ob);
      tell_room(room, ob->QCN + " arrives from another part of " + where + ".", ob);
      tell_object(ob, "You move to another part of " + where + ".");
      ob->move(room);
      ob->force_me("look");
      room->go_west(ob);
      return;
    }
  }
  start_room = file_name(ETP);
  if (start_room[0..strlen(JUNG_ROOM + "ropebridge")-1]!= JUNG_ROOM
                                                    + "ropebridge"){
    if ( start_room[0..strlen(JUNG_ROOM + "bbridge")-1]== JUNG_ROOM
                                                       + "bbridge"){
      if (!(int)TP->query_property("flying")){
        tell_object(TP, "You can't go west any more - you're"
          +" not flying!");
        return;
      } else {
        where = "the canyon";
      }
    } else {
      tell_object(TP, "You can't go west from here, so you stop moving");
      "/d/atoyatl/bridge_monitor_d.c"->set_dir(STATIONARY);
      return;
    }
  }
//Set up the right movement text and distance, according to whether they are
// going backwards or forwards
  switch (face){
  case EAST:
    dist = 1;
    movement = "edge slowly backwards along";
    movementb = "edges slowly backwards along";
    break;
  case WEST:
  default:
    movement = "make progress across";
    movementb = "makes progress across";
    dist = 2;
    break;
  }
  pos = pos - dist;
  occupier = "/d/atoyatl/bridge_monitor_d.c"->is_occupied(pos);
  if (objectp(occupier) && occupier!=ob){
    fly1 = ob->query_property("flying");
    fly2 = occupier->query_property("flying");
    if (fly1 == fly2 && fly1 != 1){
      if (ob->isKnown(occupier)){
        obstacle = ob->knownAs(occupier);
      } else {
        obstacle = "a " + occupier->query_race();
      }
      tell_object(ob, "You can't go any further west at the moment; "
        + obstacle + " is in the way.");
      tell_object(ob, "%^ORANGE%^If they won't get out of the way, your"
                       +" only option might be to push them!");
      set_dir(ob, STATIONARY);
      return;
    }
  }
  moveroom = TO;
//send the messages about movement to the mover, and to each room on the
//bridge
  switch(pos){
  case -2..0:
     pos = 0;
     if ((int)ob->query_property("flying")==1){
       tell_object(ob, "You reach the western end of the canyon");
     } else {
       tell_object(ob, "You step off the bridge at the western end");
     }
     "/d/atoyatl/bridge_monitor_d.c"->set_dir(ob, STATIONARY);
     for (i=1;i<6;i++){
       room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
       if (objectp (room)){
         if ((int)ob->query_property("flying")==1){
           tell_room(room, ob->QCN + " flies over land at the western edge"
                           +" of the canyon");
         } else {
           tell_room(room, ob->QCN + " steps off the bridge at the western"
             +" end.", ob);
         }
       }
     }
     moveroom = find_object_or_load(JUNG_ROOM + "ropebridge0");
     if (objectp(moveroom)){
       ob->move(moveroom);
       ob->force_me("look");
        if ((int)ob->query_property("flying")==1){
          tell_room(moveroom, ob->QCN + " flies in from elsewhere", ob);
        } else {
          tell_room(moveroom, ob->QCN +" steps in from the bridge.", ob);
        }
     }
     return; // makes sure they don't keep trying to cross
     break;
   case 1..14:
     tell_object(ob, "You " + movement + " " + where + ", heading"
      +" %^BOLD%^%^WHITE%^west%^RESET%^.");
     for (i=1;i<6;i++){
       room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
       if (objectp (room)){
         tell_room(room, ob->QCN + " " + movementb  + " " + where + ","
           +" heading %^BOLD%^%^WHITE%^west%^RESET%^.", ob);
       }
     }
     break;
   case 15..16:
     tell_object(ob, "You " + movement + " " + where + ", heading"
       +" %^BOLD%^%^WHITE%^west%^RESET%^.");
     if (has_moved_west(pos, dist)){
       tell_object(ob, "You are about three quarters of the way across.");
     }
     for (i=1;i<6;i++){
       room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
       if (objectp (room)){
         tell_room(room, ob->QCN + "  " + movementb  + " " + where + ","
           +" heading %^BOLD%^%^WHITE%^west%^RESET%^.", ob);
         if (has_moved_west(pos, dist)){
           tell_room(room, ob->QCN + "  is about three quarters of the way"
             +" across.", ob);
         }
       }
     }
     if (has_moved_west(pos, dist)){
       moveroom = find_object_or_load(JUNG_ROOM + "ropebridge1");
       if (objectp(moveroom)){
         ob->move(moveroom);
         ob->force_me("look");
          tell_room(moveroom, ob->QCN +" arrives in this section of the"
            +" bridge.",ob);
       }
     }
     break;
   case 17..30:
     tell_object(ob, "You " + movement + " " + where + ", heading"
       +" %^BOLD%^%^WHITE%^west%^RESET%^.");
     for (i=1;i<6;i++){
       room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
       if (objectp (room)){
         tell_room(room, ob->QCN + "  " + movementb  + " " + where + ","
           +" heading %^BOLD%^%^WHITE%^west%^RESET%^.", ob);
       }
     }
     break;
   case 31..32:
     tell_object(ob, "You " + movement + " " + where + ", heading"
       +" %^BOLD%^%^WHITE%^west%^RESET%^.");
     if (has_moved_west(pos, dist)){
       tell_object(ob, "You are about halfway across.");
     }
     for (i=1;i<6;i++){
       room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
       if (objectp (room)){
         tell_room(room, ob->QCN + "  " + movementb  + " " + where + ","
          +" heading %^BOLD%^%^WHITE%^west%^RESET%^.", ob);
         if (has_moved_west(pos, dist)){
           tell_room(room, ob->QCN + "  is about halfway across.", ob);
         }
       }
     }
     if (has_moved_west(pos, dist)){
       moveroom = find_object_or_load(JUNG_ROOM + "ropebridge2");
       if (objectp(moveroom)){
         ob->move(moveroom);
         ob->force_me("look");
          tell_room(TO, ob->QCN + " moves to the next section of " + where
            +" to the %^BOLD%^%^WHITE%^west%^RESET%^");
          tell_room(moveroom, ob->QCN +" arrives in this section of the"
            +" bridge.",ob);
       }
     }
     break;
   case 33..46:
     tell_object(ob, "You " + movement + " " + where + ", heading"
      +" %^BOLD%^%^WHITE%^west%^RESET%^.");
     for (i=1;i<6;i++){
       room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
       if (objectp (room)){
         tell_room(room, ob->QCN + "  " + movementb  + " " + where + ","
          +" heading %^BOLD%^%^WHITE%^west%^RESET%^.", ob);
       }
     }
     break;
   case 47..48:
     tell_object(ob, "You " + movement + " " + where + ", heading"
       +" %^BOLD%^%^WHITE%^west%^RESET%^.");
     if (has_moved_west(pos, dist)){
       tell_object(ob, "You are about a quarter of the way across.");
     }
     for (i=1;i<6;i++){
       room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
       if (objectp (room)){
         tell_room(room, ob->QCN + "  " + movementb  + " " + where + ","
           +" heading %^BOLD%^%^WHITE%^west%^RESET%^.", ob);
         if (has_moved_west(pos, dist)){
           tell_room(room, ob->QCN + "  is about a quarter of the way"
            +" across.",ob);
         }
       }
     }
     if (has_moved_west(pos, dist)){
       moveroom = find_object_or_load(JUNG_ROOM + "ropebridge1");
       if (objectp(moveroom)){
         ob->move(moveroom);
         ob->force_me("look");
         tell_room(TO, ob->QCN + " moves to the next section of " + where
           +" to the %^BOLD%^%^WHITE%^west%^RESET%^");
         tell_room(moveroom, ob->QCN +" arrives in this section of the"
           +"bridge.",ob);
       }
     }
     break;
   case 49..65:
   default:
     tell_object(ob, "You " + movement + " " + where + ", heading"
       +" %^BOLD%^%^WHITE%^west%^RESET%^.");
     for (i=1;i<6;i++){
       room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
       if (objectp (room)){
         tell_room(room, ob->QCN + "  " + movementb  + " " + where + ","
           +" heading %^BOLD%^%^WHITE%^west%^RESET%^.", ob);
       }
     }
     break;
   }
//adjust their position
  set_PosDir(ob, ({pos, WEST, face}));
  call_out("go_west", 2, ob);
  return;
}

void go_east(object ob){
  int i, pos, dist, face, dir, width, fly1, fly2;
  object room, moveroom, occupier;
  string movement, movementb, correct_room, obstacle, where, start_room;
  face = EAST;
  dir = "/d/atoyatl/bridge_monitor_d.c"->query_dir(ob);
  if (dir !=EAST){
    return;
  }
  if ((int)ob->query_property("gripped") == 1){
    tell_object(ob, "You stop moving, as you are holding tight to the ropes.");
    "/d/atoyatl/bridge_monitor_d.c"->set_dir(ob, STATIONARY);
    return;
  }
  where = "the bridge";
  start_room = file_name(ETP);
  if (start_room[0..strlen(JUNG_ROOM + "ropebridge")-1]!= JUNG_ROOM
                                                    + "ropebridge"){
    if ( start_room[0..strlen(JUNG_ROOM + "bbridge")-1]== JUNG_ROOM
                                                       + "bbridge"){
      if (!(int)TP->query_property("flying")){
        tell_object(TP, "You can't go east any more - you're"
          +" not flying!");
        "/d/atoyatl/bridge_monitor_d.c"->set_dir(ob, STATIONARY);
        return;
      } else {
        where = "across the canyon";
      }
    } else {
      tell_object(ob, "You can't go east from here, so you stop moving");
      "/d/atoyatl/bridge_monitor_d.c"->set_dir(ob, STATIONARY);
      return;
    }
  }
  pos = "/d/atoyatl/bridge_monitor_d.c"->query_pos(ob);
  face = "/d/atoyatl/bridge_monitor_d.c"->query_face(ob);
// First make sure they are in the right room, according to their
// position on the bridge
  correct_room = get_correct_room(pos);
  if(file_name(TO)!=correct_room){
    room = find_object_or_load( correct_room);
    if (objectp(room)){
      if(present(ob, room)){
        room->go_east(ob);
        return;
      }
      tell_room(TO, ob->QCN + " moves to another part of " + where + ".", ob);
      tell_room(room, ob->QCN + " arrives from another part of " + where + ".", ob);
      tell_object(ob, "You move to another part of " + where + "");
      ob->move(room);
      ob->force_me("look");
      room->go_east(ob);
      return;
    }
  }
  where = "the bridge";
  start_room = file_name(ETP);
  if (start_room[0..strlen(JUNG_ROOM + "ropebridge")-1]!= JUNG_ROOM
                                                    + "ropebridge"){
    if ( start_room[0..strlen(JUNG_ROOM + "bbridge")-1]== JUNG_ROOM
                                                       + "bbridge"){
      if (!(int)TP->query_property("flying")){
        tell_object(TP, "You can't go east any more - you're"
          +" not flying!");
        "/d/atoyatl/bridge_monitor_d.c"->set_dir(ob, STATIONARY);
        return;
      } else {
        where = "across the canyon";
      }
    } else {
      tell_object(ob, "You can't go east from here, so you stop moving");
      "/d/atoyatl/bridge_monitor_d.c"->set_dir(ob, STATIONARY);
      return;
    }
  }
  if ((int)ob->query_property("flying")==1){
    where = "across the canyon";
  }
//Set up the right movement text and distance, according to whether they are
// going backwards or forwards
  switch (face){
  case WEST:
    dist = 1;
    if ((int)ob->query_property("flying")==1){
      movement = "flies backwards across";
      movementb = "flies backwards across";
    } else {
      movement = "edge slowly backwards along";
      movementb = "edges slowly backwards along";
    }
    break;
  case EAST:
  default:
    if ((int)ob->query_property("flying")==1){
      movement = "make progress flying across";
      movementb = "makes progress flying across";
    } else {
      movement = "make progress across";
      movementb = "makes progress across";
    }
    dist = 2;
    break;
  }
  pos = pos + dist;
  width = "/d/atoyatl/bridge_monitor_d.c"->query_width(ob);
  occupier = "/d/atoyatl/bridge_monitor_d.c"->is_occupied(pos + width);
  if (objectp(occupier) && occupier!=ob){
    fly1 = ob->query_property("flying");
    fly2 = occupier->query_property("flying");
    if (fly1 == fly2 && fly1 != 1){
      if (ob->isKnown(occupier)){
        obstacle = ob->knownAs(occupier);
      } else {
        obstacle = "a " + occupier->query_race();
      }
       tell_object(ob, "You can't go any further east at the moment; "
        + obstacle + " is in the way.");
      tell_object(ob, "%^ORANGE%^If they won't get out of the way, your"
                     +" only option might be to push them!");
      set_dir(ob, STATIONARY);
      return;
    }
  }
  moveroom = TO;

//send the messages about movement to the mover, and to each room on the
//bridge
  switch(pos){
  case 64..68:
     pos = 65;
     if ((int)ob->query_property("flying")==1){
       tell_object(ob, "You reach the eastern edge of the canyon");
     } else {
       tell_object(ob, "You step off the bridge at the eastern end");
     }
     "/d/atoyatl/bridge_monitor_d.c"->set_dir(ob, STATIONARY);
     for (i=1;i<6;i++){
       room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
       if (objectp (room)){
         tell_room(room, ob->QCN + " steps off the bridge at the eastern"
           +" end.", ob);
       }
     }
     moveroom = find_object_or_load(JUNG_ROOM + "ropebridge5");
     if (objectp(moveroom)){
       ob->move(moveroom);
       ob->force_me("look");
       tell_room(moveroom, ob->QCN +" steps in from " + where +".", ob);
     }
//     "/d/atoyatl/bridge_monitor_d.c"->remove_crosser(ob);
     return; // makes sure they don't keep trying to cross
     break;
   case 51..63:
     tell_object(ob, "You " + movement + " " + where + ", heading"
      +" %^BOLD%^%^WHITE%^east%^RESET%^.");
     for (i=1;i<6;i++){
       room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
       if (objectp (room)){
         tell_room(room, ob->QCN + "  " + movementb  + " " + where + ","
           +" heading%^BOLD%^%^WHITE%^east%^RESET%^.", ob);
       }
     }
     break;
   case 49..50:
     tell_object(ob, "You " + movement + " " + where + ", heading"
       +" %^BOLD%^%^WHITE%^east%^RESET%^.");
     if (has_moved_east(pos, dist)){
       tell_object(ob, "You are about three quarters of the way across.");
     }
     for (i=1;i<6;i++){
       room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
       if (objectp (room)){
         tell_room(room, ob->QCN + "  " + movementb  + " " + where + ","
           +" heading %^BOLD%^%^WHITE%^east%^RESET%^.", ob);
         if (has_moved_east(pos, dist)){
           tell_room(room, ob->QCN + "  is about three quarters of the way"
             +" across.", ob);
         }
       }
     }
     if (has_moved_east(pos, dist)){
       moveroom = find_object_or_load(JUNG_ROOM + "ropebridge4");
       if (objectp(moveroom)){
         ob->move(moveroom);
         ob->force_me("look");
          tell_room(moveroom, ob->QCN +" arrives in this section of " + where
            +".",ob);
       }
     }
     break;
   case 35..48:
     tell_object(ob, "You " + movement + " " + where + ", heading"
       +" %^BOLD%^%^WHITE%^east%^RESET%^.");
     for (i=1;i<6;i++){
       room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
       if (objectp (room)){
         tell_room(room, ob->QCN + "  " + movementb  + " " + where + ","
           +" heading %^BOLD%^%^WHITE%^east%^RESET%^.", ob);
       }
     }
     break;
   case 33..34:
     tell_object(ob, "You " + movement + " " + where + ", heading"
       +" %^BOLD%^%^WHITE%^east%^RESET%^.");
     if (has_moved_east(pos, dist)){
       tell_object(ob, "You are about halfway across.");
     }
     for (i=1;i<6;i++){
       room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
       if (objectp (room)){
         tell_room(room, ob->QCN + "  " + movementb  + " " + where + ","
          +" heading %^BOLD%^%^WHITE%^east%^RESET%^.", ob);
         if (has_moved_east(pos, dist)){
           tell_room(room, ob->QCN + "  is about halfway across.", ob);
         }
       }
     }
     if (has_moved_east(pos, dist)){
       moveroom = find_object_or_load(JUNG_ROOM + "ropebridge2");
       if (objectp(moveroom)){
         ob->move(moveroom);
         ob->force_me("look");
          tell_room(TO, ob->QCN + " moves to the next section of " + where
            +" to the %^BOLD%^%^WHITE%^east%^RESET%^");
          tell_room(moveroom, ob->QCN +" arrives in this section of " + where
            +".",ob);
       }
     }
     break;
   case 17..32:
     tell_object(ob, "You " + movement + " " + where + ", heading"
      +" %^BOLD%^%^WHITE%^east%^RESET%^.");
     for (i=1;i<6;i++){
       room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
       if (objectp (room)){
         tell_room(room, ob->QCN + "  " + movementb  + " " + where + ","
          +" heading %^BOLD%^%^WHITE%^east%^RESET%^.", ob);
       }
     }
     break;
   case 15..16:
     tell_object(ob, "You " + movement + " " + where + ", heading"
       +" %^BOLD%^%^WHITE%^east%^RESET%^.");
     if (has_moved_east(pos, dist)){
       tell_object(ob, "You are about a quarter of the way across.");
     }
     for (i=1;i<6;i++){
       room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
       if (objectp (room)){
         tell_room(room, ob->QCN + "  " + movementb  + " " + where + ","
           +" heading %^BOLD%^%^WHITE%^east%^RESET%^.", ob);
         if (has_moved_east(pos, dist)){
           tell_room(room, ob->QCN + "  is about a quarter of the way"
            +" across.",ob);
         }
       }
     }
     if (has_moved_east(pos, dist)){
       moveroom = find_object_or_load(JUNG_ROOM + "ropebridge1");
       if (objectp(moveroom)){
         ob->move(moveroom);
         ob->force_me("look");
          tell_room(TO, ob->QCN + " moves to the next section of " + where
            +" to the %^BOLD%^%^WHITE%^east%^RESET%^");
          tell_room(moveroom, ob->QCN +" arrives in this section of " + where
            +".",ob);
       }
     }
     break;
   case 0..14:
   default:
     tell_object(ob, "You " + movement + " " + where + ", heading"
       +" %^BOLD%^%^WHITE%^east%^RESET%^.");
     for (i=1;i<6;i++){
       room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
       if (objectp (room)){
         tell_room(room, ob->QCN + "  " + movementb  + " " + where + ","
           +" heading %^BOLD%^%^WHITE%^east%^RESET%^.", ob);
       }
     }
     break;
   }
//adjust their position
  set_PosDir(ob, ({pos, EAST, face}));
  call_out("go_east", 2, ob);
  return;
}

int check_bridge(string str){
  if (str != "bridge" && str !="rope bridge" && str != "ropebridge"){
    if (str != "positions" && str != "progress"
                               && str != "progress across bridge"){
      return notify_fail("Try <check progress> or <check bridge>");
    }
    "/d/atoyatl/bridge_monitor_d.c"->check_positions(TP);
    return 1;
  }
  "/d/atoyatl/bridge_monitor_d.c"->show_bridge(TP);
  return 1;
}

void set_PosDir(object ob, int * PosDir){
  "/d/atoyatl/bridge_monitor_d.c"->set_PosDir(ob, PosDir);
}

void set_pos(object ob, int pos){
  "/d/atoyatl/bridge_monitor_d.c"->set_pos(ob, pos);
}

int query_pos(object ob){
  return "/d/atoyatl/bridge_monitor_d.c"->query_pos(ob);
}

void set_face(object ob, int face){
  "/d/atoyatl/bridge_monitor_d.c"->set_face(ob, face);
}

int query_face(object ob){
  return "/d/atoyatl/bridge_monitor_d.c"->query_face(ob);
}

int query_dir(object ob){
  return "/d/atoyatl/bridge_monitor_d.c"->query_dir(ob);
}

void set_dir(object ob, int dir){
  "/d/atoyatl/bridge_monitor_d.c"->set_dir(ob, dir);
}

void set_demon_pos(int pos){
  "/d/atoyatl/bridge_monitor_d.c"->set_demon_pos(pos);
}

int query_demon_pos(){
  return "/d/atoyatl/bridge_monitor_d.c"->query_demon_pos();
}

int set_demon_dir(int dir){
  demon_dir = dir;
}

int query_demon_dir(){
  return demon_dir;
}
