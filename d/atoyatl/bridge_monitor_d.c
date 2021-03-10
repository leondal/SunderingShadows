#include <std.h>
#include <daemons.h>
#include "/realms/lujke/tecqumin/tecqumin.h"

inherit DAEMON;

mapping __VPos;
mapping __PosDir;
mapping __Colours;
mapping __RPictures;
mapping __LPictures;

int demon_pos, demon_dir, break_point, ropes;

int convert_to_vPos(int pos);
int same_side(object ob1, object ob2);
varargs int query_vPos(object ob, string * pic);
int query_pos(object ob);
int query_face(object ob);
int query_width(object ob);
int query_height(object ob);
void enter_east(object ob);
void enter_west(object ob);
void show(string * what, object ob);
varargs void tell_bridge(string str, object ob);
string * get_picture(object ob, object looker);
string * get_untitled_pic(object ob);
string describe_fliers(object ob, int pos, int face);
void show_bridge(object looker);
void setup_Colours();
string crit_colour(int i);
void setup_Pictures();
int * query_PosDir(object ob);
int remove_crosser(object crosser);
object * query_crossers();
string * colour_bridge(string * bridge);
string * colour_broken_bridge(string * bridge);
void break_bridge(int bp, object breaker);
void fall(object faller);
void check_positions(object checker);

void create() {
  ::create();
  __VPos = ([]);
  __PosDir = ([]);
  __RPictures = ([]);
  __LPictures = ([]);
  setup_Pictures();
  break_point = -1;
  ropes = 4;
}


void clean_up() { 
  // This function added to prevent data being removed by the inherited
  // clean_up function.
  return; 
} 


int can_reach(object ob1, object ob2){
  int width1, width2, face1, face2, e1, e2, w1,w2,
                            height1, height2, u1, u2, d1,d2;
  if (!objectp(ob1)||!objectp(ob2)){
    return -1;
  }
  if (break_point>-1){
    if (d1 ==  -1 || d2  == -1){
      return -1;
    }
    height1 = query_height(ob1);
    height2 = query_height(ob2);
    if (query_pos(ob1)<break_point){
      if (query_pos(ob2)>break_point){
        return -1;
      }
      u1 = query_pos(ob1);
      u1 = convert_to_vPos(u1);
      u2 = query_pos(ob2);
      u2 = convert_to_vPos(u2);
      d1 = u1 + height1;
      d2 = u2 + height2;
      if (u1 < d2 + 2 && d1 > u2 - 2){
        return 1;
      }
    } else {
      if (query_pos(ob2)<break_point){
        return -1;
      }
      d1 = query_pos(ob1);
      d1 = convert_to_vPos(d1);
      d2 = query_pos(ob2);
      d2 = convert_to_vPos(d2);
      u1 = d1 + height1;
      u2 = d2 + height2;
      if (u1 > d2 - 2 && d1 < u2 + 2){
        return 1;
      }
    }
  } else {
    w1 = query_pos(ob1);
    w2 = query_pos(ob2);
    if (w1 ==  -1 || w2  == -1){
      return -1;
    }
    face1 = query_face(ob1);
    face2 = query_face(ob2);
    width1 = query_width(ob1);
    width2 = query_width(ob2);
    e1 = w1 + width1;
    e2 = w2 + width2;
    if ((e2 >= w1-2 && w2 <= e1+2) ||(e1 >= w2-2 && w1 <= e2+2)){
      return 1;
    }
  }
  return -1;
}

int query_ropes(){
  return ropes;
}

void set_ropes(int rp){
  ropes = rp;
}

void set_break_point(int br){
  break_point = br;
}

int query_break_point(){
  return break_point;
}

mapping query_LPictures(){
  return __LPictures;
}

mapping query_RPictures(){
  return __RPictures;
}

void setup_Colours(){
  __Colours = ([
     0:([]),1:([]),2:([]),3:([]),4:([]),
     5:([]),6:([]),7:([]),8:([]),9:([]),
     10:([]),11:([]),12:([]),13:([]),
     14:([]),15:([]),16:([]),17:([]),
     18:([]),19:([]),20:([]),21:([]),
     22:([]),23:([]),24:([]),25:([]),
     26:([]),27:([])
     ]);
}

int query_height(object ob){
  string * pic;
  int i, height, count;
  pic = get_untitled_pic(ob);
  height = 0;
  height = sizeof(pic);
  return height;
}

int query_width(object ob){
  string * pic;
  int i, width, count;
  pic = get_untitled_pic(ob);
  width = 0;
  count = sizeof(pic);
  if (count<1){
    return -1;
  }
  for (i = 0; i<count;i++){
    if (strlen(pic[i])>width){
      width = strlen(pic[i]);
    }
  }
  return width;
}

int is_higher(object ob1, object ob2){
  int pos1, pos2, break_point, u1, u2, d1, d2, height1, height2;
  if (break_point ==-1){
    return -1;
  }
  pos1 = query_pos(ob1);
  pos2 = query_pos(ob2);
  height1 = query_height(ob1);
  height2 = query_height(ob2);
  if (pos1 < break_point){
    if (pos2>break_point){
      return -1;
    }
    d1 = pos1;
    d2 = pos2;
    u1 = pos1 - height1;
    u2 = pos2 - height2;
    if (d1<u2){
      return 1;
    } else {
      return -1;
    }
  } else {
    if (pos2<break_point){
      return -1;
    }
    d1 = pos1;
    d2 = pos2;
    u1 = pos1 + height1;
    u2 = pos2 + height2;
    if (d1>u2){
      return 1;
    } else {
      return -1;
    }
  }
}

int is_lower(object ob1, object ob2){
  int pos1, pos2, break_point, u1, u2, d1, d2, height1, height2;
  pos1 = query_pos(ob1);
  pos2 = query_pos(ob2);
  height1 = query_height(ob1);
  height2 = query_height(ob2);
  if (break_point ==-1){
    return -1;
  }
  if (pos1 < break_point){
    if (pos2>break_point){
      return -1;
    }
    d1 = pos1;
    d2 = pos2;
    u1 = pos1 - height1;
    u2 = pos2 - height2;
    if (u1>d2){
      return 1;
    } else {
      return -1;
    }
  } else {
    if (pos2<break_point){
      return -1;
    }
    d1 = pos1;
    d2 = pos2;
    u1 = pos1 + height1;
    u2 = pos2 + height2;
    if (u1<d2){
      return 1;
    } else {
      return -1;
    }
  }
}

/*


    if (query_pos(ob1)<break_point){ //west side calculation
      if (query_pos(ob2)>break_point){
        return -1;
      }
      u1 = query_pos(ob1);
      u1 = convert_to_vPos(u1);
      u2 = query_pos(ob2);
      u2 = convert_to_vPos(u2);
      d1 = u1 + height1;
      d2 = u2 + height2;
      if (u1 < d2 + 2 && d1 > u2 - 2){
        return 1;
      }

    } else { //east side calculation
      if (query_pos(ob2)<break_point){
        return -1;
      }
      d1 = query_pos(ob1);
      d1 = convert_to_vPos(d1);
      d2 = query_pos(ob2);
      d2 = convert_to_vPos(d2);
      u1 = d1 + height1;
      u2 = d2 + height2;
      if (u1 > d2 - 2 && d1 < u2 + 2){
        return 1;
      }
    }
*/

object is_occupied(int pos){
  object * critters, occupier;
  int i, face, height, width, count, position, vPosition, u, d;
  critters = keys(__PosDir);
  count = sizeof(critters);
  if (count<1){
    return -1;
  }
  if (break_point!= -1){ //If the bridge is broken, work it out this way
    for (i=0;i<count;i++){
      pos = convert_to_vPos(pos);
      height = query_height(critters[i]);
      position = query_pos(critters[i]);
      vPosition = convert_to_vPos(position);
      if (position>break_point){ //east side calculation
        d = vPosition;
        u = d + height;
        if (pos>=d && pos <= u){
          return critters[i];
        }
      } else { //west side calculation
        u = vPosition;
        d = u + height;
        if (pos<=d && pos >= u){
          return critters[i];
        }
      }
    }
  } else {
    for (i=0;i<count;i++){  //If the bridge is intact, work it out this way
      width = query_width(critters[i]);
      position = query_pos(critters[i]);
      if (pos >= position && pos <= position +width){
        return critters[i];
      }
    }
  }
  return -1;
}

string describe_fliers(object ob, int pos, int face){
  string height, position, facing, rm_name;
  int vPos;
  object room;
  vPos = query_vPos(ob);
  switch (break_point){
  case -1:
    switch (vPos){
    case 0..6:
      height = "%^BOLD%^%^WHITE%^above%^RESET%^ the bridge";
      break;
    case 7..16:
      height = "%^ORANGE%^near%^RESET%^ the bridge";
      break;
    default:
      height = "%^BOLD%^%^BLUE%^below%^RESET%^ the bridge";
      break;
    }
    break;
  default:
    switch (vPos){
    case 0:
      height = "%^BOLD%^%^WHITE%^above%^RESET%^ the%^ORANGE%^"
              +" broken %^RESET%^bridge";
      break;
    case 7..13:
      height = "%^ORANGE%^near%^RESET%^ the %^ORANGE%^broken"
               +" %^RESET%^bridge";
      break;
    default:
      height = "%^BOLD%^%^BLUE%^below%^RESET%^ the%^ORANGE%^"
              +" broken %^RESET%^bridge";
      break;
    }
    break;
  }
  room = find_object_or_load(JUNG_ROOM + "ropebridge0");
  if (objectp(room)){
    rm_name = room->get_correct_room(pos);
    switch(rm_name){
    case JUNG_ROOM + "ropebridge0":
      position = " at the %^BOLD%^%^WHITE%^western%^RESET%^ end";
      break;
    case JUNG_ROOM + "ropebridge1":
      position = " near the %^BOLD%^%^WHITE%^western%^RESET%^"
                +" end";
      break;
    case JUNG_ROOM + "ropebridge2":
      position = " a little %^BOLD%^%^WHITE%^west%^RESET%^"
                +" of the middle";
      break;
    case JUNG_ROOM + "ropebridge3":
      position = " a little %^ORANGE%^east%^RESET%^"
                +" of the middle";
      break;
    case JUNG_ROOM + "ropebridge4":
      position = " near the %^ORANGE%^eastern%^RESET%^ end";
      break;
    case JUNG_ROOM + "ropebridge5":
      position = " at the %^ORANGE%^eastern%^RESET%^ end";
      break;
    }
  } else {
    position = ", but you can't work out how far along due to"
              +" an ERROR - please make a bug report, quoting"
              +" this text";
  }
  switch (face){
  case EAST:
    facing = ", facing %^ORANGE%^east%^RESET%^.";
    break;
  case WEST:
    facing = ", facing %^BOLD%^%^WHITE%^west%^RESET%^.";
    break;
  }
  return "%^RESET%^is %^BOLD%^%^CYAN%^flying%^RESET%^ " + height 
         + position + facing;
}

string describe_pos(int pos, int face){
  string str;
  str = "%^ORANGE%^";
  if (break_point == -1){
    switch(pos){
    case -4..1:
      str += "is standing before the %^BOLD%^%^WHITE%^west"
        +" %^RESET%^%^ORANGE%^end of the bridge";
      break;
    case 2..14:
      str += "is on the %^BOLD%^%^WHITE%^far west"
        +" %^RESET%^%^ORANGE%^quarter of the bridge";
      break;
    case 15..30:
      str += "is to the %^BOLD%^%^WHITE%^west%^RESET%^%^ORANGE%^"
        +" of the middle of the bridge";
      break;
    case 31..46:
      str += "is to the %^BOLD%^%^WHITE%^east%^RESET%^%^ORANGE%^"
        +" of the middle of the bridge";
      break;
    case 47..64:
      str += "is on the %^BOLD%^%^WHITE%^far east%^RESET%^"
        +" %^ORANGE%^quarter of the bridge";
      break;
    case 65..100:
      str += "is standing before the %^BOLD%^%^WHITE%^east"
        +" %^RESET%^%^ORANGE%^end of the bridge";
      break;
    }
    switch(face){
    case 0:
      str += ", facing %^RESET%^west%^ORANGE%^."; 
      break;
    case 1:
      str += ", facing %^RESET%^east%^ORANGE%^."; 
      break;
    }
  } else {
    switch(pos){
    case -4..1:
      str += "is standing before the %^BOLD%^%^WHITE%^west"
        +" %^RESET%^%^ORANGE%^end of the %^RED%^broken %^ORANGE%^bridge";
      break;
    case 2..14:
      if (pos<break_point){
        str += "is near the top of the%^BOLD%^%^WHITE%^ west"
          +" %^RESET%^%^ORANGE%^half of the %^RED%^broken %^ORANGE%^bridge";
      } else {
        str += "is very low on the%^BOLD%^%^WHITE%^ east"
          +" %^RESET%^%^ORANGE%^half of the %^RED%^broken %^ORANGE%^bridge";
      }
      break;
    case 15..30:
      if (pos<break_point){
        str += "is fairly high on the%^BOLD%^%^WHITE%^ west"
          +" %^RESET%^%^ORANGE%^half of the %^RED%^broken %^ORANGE%^bridge";
      } else {
        str += "is quite low on the%^BOLD%^%^WHITE%^ east"
          +" %^RESET%^%^ORANGE%^half of the %^RED%^broken %^ORANGE%^bridge";
      }
      break;
    case 31..46:
      if (pos<break_point){
        str += "is quite low on the%^BOLD%^%^WHITE%^ west"
          +" %^RESET%^%^ORANGE%^half of the %^RED%^broken %^ORANGE%^bridge";
      } else {
        str += "is fairly high on the%^BOLD%^%^WHITE%^ east"
          +" %^RESET%^%^ORANGE%^half of the %^RED%^broken %^ORANGE%^bridge";
      }
      break;
    case 47..64:
      if (pos<break_point){
        str += "is very low on the%^BOLD%^%^WHITE%^ west"
          +" %^RESET%^%^ORANGE%^half of the %^RED%^broken %^ORANGE%^bridge";
      } else {
        str += "is near the top of the%^BOLD%^%^WHITE%^ east"
          +" %^RESET%^%^ORANGE%^half of the %^RED%^broken %^ORANGE%^bridge";
      }
      break;
    case 65..100:
      str += "is standing before the %^BOLD%^%^WHITE%^east"
        +" %^RESET%^%^ORANGE%^end of the %^RED%^broken %^ORANGE%^bridge";
      break;
    }
  }
  return str;
}

void check_positions(object checker){
  object * critters;
  int i, count, pos, face;
  string str;
  critters = keys(__PosDir);
  count = sizeof(critters);
  if (count <1){
    tell_object(checker, "There is no-one on the bridge at the moment");
    return;
  }
  for (i=0;i<count;i++){
    if (!objectp(critters[i])){
      remove_crosser(critters[i]);
      continue;
    }
    pos = __PosDir[critters[i]][0];
    face = __PosDir[critters[i]][2];
    str = "%^ORANGE%^";
    if (checker->isKnown(critters[i]->query_name())){
      str += checker->knownAs(critters[i]->query_name());
    } else {
      str += critters[i]->query_race();
    }
    if ((int)critters[i]->query_property("flying", 1)==1){
      str += " " + describe_fliers(critters[i], pos, face);
    } else {
      str += " " + describe_pos(pos, face);
    }
    tell_object(checker, str);
  }
}

int cut_rope(object cutter){
  object room, * critters;
  int i, count, dm, bp;
  string save_message, fall_message, grip_message;
  switch(ropes){
  case 0:
    tell_object(cutter, "%^ORANGE%^The ropes have all been %^BOLD%^%^RED%^cut"
      +" %^RESET%^%^ORANGE%^already!");
    return 1;
    break;
  case 4:
    tell_object(cutter, "%^ORANGE%^You cut through the top left rope, and the"
      +" hand support disappears");
    tell_bridge("%^ORANGE%^" + cutter->QCN + "%^ORANGE%^ cuts through the top"
      +" left rope, and the hand support disappears."
      , cutter);
    grip_message = "Fortunately, you are holding on tight, so there's no risk"
      +" of falling";
    save_message = "%^ORANGE%^" + cutter->QCN + "%^ORANGE%^ cuts through the top"
      +" left rope, and the hand support disappears. The %^RESET%^bridge"
      +" %^ORANGE%^shakes, but you manage to hang on.";
    fall_message = "%^BOLD%^%^RED%^" + cutter->QCN + "%^BOLD%^%^RED%^ cuts through"
      +" the %^RESET%^%^ORANGE%^rope%^BOLD%^%^RED%^ you were holding onto, and you"
      +" %^BOLD%^%^BLUE%^fall%^RED%^ off the %^RESET%^%^ORANGE%^bridge%^BOLD%^"
      +"%^RED%^!";
    dm = 10;
    ropes = 3;
    break;
  case 3:
    tell_object(cutter, "%^ORANGE%^You cut through the bottom left rope, and the"
      +" bridge %^BOLD%^%^BLUE%^sways%^RESET%^%^ORANGE%^ wildly");
    tell_bridge("%^ORANGE%^" + cutter->QCN + "%^ORANGE%^ cuts through the bottom"
      +" left rope, and the bridge %^BOLD%^%^BLUE%^sways%^RESET%^%^ORANGE%^ wildly."
      , cutter);
    grip_message = "Fortunately, you are holding on tight, so you don't fall";
    save_message = "%^ORANGE%^You quickly step across to balance to on the one"
       +" remaining lower rope, holding onto to the handrope";
    fall_message = "%^ORANGE%^As the slats disappear under your feet, your"
       +" %^BOLD%^%^BLUE%^balance%^RESET%^%^ORANGE%^ goes and you%^BOLD%^%^BLUE%^"
       +" fall%^RESET%^%^ORANGE%^ off the bridge! The%^RESET%^%^ORANGE%^"
       +" rope%^BOLD%^%^RED%^ you were holding onto, and you"
      +" %^BOLD%^%^BLUE%^fall%^RED%^ off the bridge!";
    dm = 20;
    ropes = 2;
    break;
  case 2:
    tell_object(cutter, "%^ORANGE%^You cut through the bottom left rope, and the"
      +" bridge %^BOLD%^%^GREEN%^shudders%^RESET%^%^ORANGE%^. The"
      +" last hand rope drops away into the canyon below!");
    tell_bridge("%^ORANGE%^" + cutter->QCN + "%^ORANGE%^ cuts through the top right"
      +" rope, and the bridge %^BOLD%^%^GREEN%^shudders%^RESET%^%^ORANGE%^. The"
      +" last hand rope drops away into the canyon below!"
      , cutter);
    save_message = "%^ORANGE%^You balance carefully on the one remaining rope.";
    grip_message = "Fortunately, you are holding on tight, so you don't fall.";
    fall_message = "%^ORANGE%^With nothing left to hold onto, you lose your balance"
      +" and %^BOLD%^%^BLUE%^fall%^RED%^ off the bridge!";
    dm = 30;
    ropes = 1;
    break;
  case 1:
    ropes = 0;
    bp = "/d/atoyatl/bridge_monitor_d.c"->query_pos(cutter);
    switch((int)"/d/atoyatl/bridge_monitor_d.c"->query_face(cutter)){
    case EAST:
      bp = bp + 0.5;
      break;
    case WEST:
      bp = bp - 0.5;
      break;
    }
    break_bridge(bp, cutter);
    break;
  }
  critters = ({});
  for (i=0;i<6;i++){
    room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
    if (objectp(room)){
      critters += all_living(room);
    }
  }
  count = sizeof(critters);
  if (count<1){ return 1;}
  for (i = 0; i<count; i++){
    if ((int)critters[i]->query_property("flying")==1){
      __VPos[critters[i]] = query_vPos(critters[i]) - 5;
    }
    if ((int)critters[i]->query_property("gripped") >0){
      tell_object(critters[i], "Your tight hold on the bridge saves"
        " you from falling!");
    } else {
      if ("/daemon/saving_throw_d.c"->reflex_save(critters[i],dm)){
        tell_object(critters[i], save_message);
      } else {
        tell_object(critters[i], fall_message);
        fall(critters[i]);
      }
    }
  }
  return 1;
}

int remove_crosser(object crosser){
  object * kys;
  kys = keys(__PosDir);
  if (member_array(crosser, kys)!=-1){
    map_delete(__PosDir, crosser);
  }
  kys = keys(__VPos);
  if (member_array(crosser, kys)!=-1){
    map_delete(__VPos, crosser);
  }
  return 1;
}

void set_PosDir(object ob, int * PosDir){
  object * obs;
  if (sizeof(__PosDir)>0){
    if(!objectp(ob)){
      return;
    }
    obs = keys(__PosDir);
    if (member_array(ob, obs)!=-1){
      map_delete(  __PosDir, ob); 
    }
  } else {
    __PosDir = ([ ]);
  }
  __PosDir += ([ob : PosDir]);
}

int query_PosDir(object ob){
  object * kys;
  kys = keys(__PosDir);
  if (member_array(ob, kys)==-1){
    return -1;
  }
  return __PosDir[ob];
}

object * query_crossers(){
  object * crossers;
  crossers = keys (__PosDir);
  return crossers;
}

void set_face(object ob, int face){
  object * obs;
  int dir, pos;
  dir = 0;
  pos = 0;
  obs = keys (__PosDir);
  if (member_array(ob, obs)!=-1){
    pos = __PosDir[ob][0];
    dir = __PosDir[ob][1];
    map_delete(__PosDir, ob); 
  }
  __PosDir += ([ob : ({pos, dir, face})]); 
}

int query_face(object ob){
  object * kys, room;
  int i, flag;
  if (!objectp(ob)){ return -1; }
  kys = keys (__PosDir);
  if (member_array( ob, kys)==-1){
    return -1;
  }
  flag = 0;
  for (i=0;i<6;i++){
    room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
    if (objectp(room)){
      if (present(ob, room)){
        flag = 1;
        break;
      }
    }
    if (i>0 && i<5){
      room = find_object_or_load(JUNG_ROOM + "bbridge_e" + i);
      if (objectp(room)){
        if (present(ob, room)){
          flag = 1;
          if ( !ob->query_property("flying")){
            return EAST;
            break;
          }
        }
      }
      room = find_object_or_load(JUNG_ROOM + "bbridge_w" + i);
      if (objectp(room)){
        if (present(ob, room)){
          flag = 1;
          if (!ob->query_property("flying")){
            return WEST;
            break;
          }
        }
      }
    }
  }
  room = find_object_or_load(JUNG_ROOM + "ropebridge_base");
  if (objectp(room) && present(ob, room)){
    flag = 1;
  }
  if (flag ==0){
    map_delete(__PosDir, ob);
    return -1;  
  }
  return __PosDir[ob][2];
}
 
void set_pos(object ob, int pos){
  object * obs;
  int dir, face;
  dir = 0;
  face = 0;
  obs = keys (__PosDir);
  if (member_array(ob, obs)!=-1){
    face = __PosDir[ob][2];
    dir = __PosDir[ob][1];
    map_delete(__PosDir, ob); 
  }
  __PosDir += ([ob : ({pos, dir, face})]); 
}

int query_pos(object ob){
  object * kys, room;
  int i, flag;
  if (!objectp(ob)){ return -1; }
  kys = keys (__PosDir);
  if (member_array(ob, kys)==-1){
    return -1;
  }
  flag = 0;
  for (i=0;i<6;i++){
    room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
    if (objectp(room)){
      if (present(ob, room)){
        flag = 1;
        break;
      }
    }
    if (i>0 && i<5){
      room = find_object_or_load(JUNG_ROOM + "bbridge_e" + i);
      if (objectp(room)){
        if (present(ob, room)){
          flag = 1;
          break;
        }
      }
      room = find_object_or_load(JUNG_ROOM + "bbridge_w" + i);
      if (objectp(room)){
        if (present(ob, room)){
          flag = 1;
          break;
        }
      }
    }
  }
  room = find_object_or_load(JUNG_ROOM + "ropebridge_base");
  if (objectp(room) && present(ob, room)){
    flag = 1;
  }
  if (flag ==0){
    map_delete(__PosDir, ob);
    return -1;  
  }
  return __PosDir[ob][0];
}

void set_dir(object ob, int dir){
  object * obs;
  int pos, face;
  pos = 0;
  face = 0;
  obs = keys (__PosDir);
  if (member_array(ob, obs)!=-1){
    face = __PosDir[ob][2];
    pos = __PosDir[ob][0];
    map_delete(__PosDir, ob); 
  }
  __PosDir += ([ob : ({pos, dir, face})]); 
}

int query_dir(object ob){
  object * kys, room;
  int i, flag;
  if (!objectp(ob)){ return -1; }
  kys = keys (__PosDir);
  if (member_array(ob, kys)==-1){
    return -1;
  }
  flag = 0;
  for (i=0;i<6;i++){
    room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
    if (objectp(room)){
      if (present(ob, room)){
        flag = 1;
        break;
      }
    }
    if (i >0 && i<5){
      room = find_object_or_load(JUNG_ROOM + "bbridge_e" + i);
      if (objectp(room)){
        if (present(ob, room)){
          flag = 1;
          break;
        }
      }
      room = find_object_or_load(JUNG_ROOM + "bbridge_w" + i);
      if (objectp(room)){
        if (present(ob, room)){
          flag = 1;
          break;
        }
      }
    }
  }
  room = find_object_or_load(JUNG_ROOM + "ropebridge_base");
  if (objectp(room) && present(ob, room)){
    flag = 1;
  }
  if (flag ==0){
    tell_object(ob, "You aren't in a ropebridge room!");
    map_delete(__PosDir, ob);
    return -1;  
  }
  return __PosDir[ob][1];
}

void set_demon_pos(int pos){
  demon_pos = pos;
}

int query_demon_pos(){
  return demon_pos;
}

int set_demon_dir(int dir){
  demon_dir = dir;
}

int query_demon_dir(){
  return demon_dir;
}


void show(string * what, object ob){
  int i, rows;
  string str;
  if (!objectp(ob)){ return;}
  rows = sizeof(what);
  for (i=0;i<rows;i++){
    str = what[i];
    tell_object(ob, str);
  }  
}

string query_colour(int row, int pos){
  if (member_array(row, keys(__Colours))==-1){
    return "";
  }
  if (member_array(pos, keys(__Colours[row]))==-1){
    return "";
  }
  return __Colours[row][pos];
}

int add_colour(int row, int pos, string col){
  string colour;
  mapping temp_map;
  if (member_array(row, keys(__Colours)) == -1){
    return -1;
  }
  colour = "";
  if (member_array(pos, keys(__Colours[row]))!=-1){
    colour = __Colours[row][pos];
  }
  colour += col;
  __Colours[row][pos] = colour;
  return 1;
}

int compare(int one, int two){
  return one - two;
}

string get_bg_colour(int row, int pos){
  string col, colour, bg;
  int i;
  bg = "%^B_";
  for (i=0;i<pos;i++){
    col = query_colour(row, i);
    if (col != "" && col[0..3] == bg[0..3]){
      colour = col;
    }
  }
  if (colour ==  ""){ colour = "";}
  return colour;
}

void colour_unfettered(int row, int pos, int f){
  string colour, colour2, col;
  int i;
  colour = get_bg_colour(row + 2, pos +12);
  for (i=5;i<11;i++){
    add_colour(row+2, pos+i, "%^B_MAGENTA%^");
  }
  add_colour(row + 2, pos + 11, colour);
  colour = get_bg_colour(row + 3, pos +14);
  if (f == EAST){
    add_colour(row + 3, pos + 4, "%^B_MAGENTA%^%^BOLD%^%^RED%^" );
  }
  for (i=5;i<12;i++){
    switch (f){
    case EAST:
      switch(i){
      case (8):
        col = "%^B_BLACK%^%^BOLD%^%^RED%^";
        break;
      case (9):
        col = "%^B_BLACK%^%^BOLD%^%^BLUE%^";
        break;
      case (10):
        col = "%^B_BLACK%^%^BOLD%^%^RED%^";
        break;
      case (11):
        col = "%^B_MAGENTA%^%^BOLD%^%^RED%^";
        break;
      default:
        col = "%^B_MAGENTA%^";
      }
      break;
    case WEST:
      switch(i){
      case (6):
        col = "%^B_BLACK%^%^BOLD%^%^RED%^";
        break;
      case (7):
        col = "%^B_BLACK%^%^BOLD%^%^BLUE%^";
        break;
      case (8):
        col = "%^B_BLACK%^%^BOLD%^%^RED%^";
        break;
      default:
        col = "%^B_MAGENTA%^";
      }
      break;
    }
    add_colour(row+3, pos+i, col);
  }
  if (f == WEST){
    add_colour(row + 3, pos + 4, "%^B_MAGENTA%^" );
    add_colour(row + 3, pos + 13, "%^BOLD%^%^RED%^" );
  }
  add_colour(row + 3, pos + 14, colour );
  add_colour(row + 3, pos + 15, "%^BOLD%^%^WHITE%^");
  colour = get_bg_colour(row + 4, pos +13);
  colour2 = get_bg_colour(row + 4, pos +12);
  if (f == EAST){
    add_colour(row+4, pos+3, "%^B_MAGENTA%^");
  }
  for (i=4;i<13;i++){
    add_colour(row+4, pos+i, "%^B_MAGENTA%^");
  }
//  if (f == WEST){
    add_colour(row + 4, pos + 13, colour);
//  } else {
//    add_colour(row + 4, pos + 12, colour2);
//  }
  add_colour (row + 4, pos + 16,"%^BOLD%^%^WHITE%^");
  colour = get_bg_colour(row + 5, pos +13);
  colour2 = get_bg_colour(row + 5, pos +14);
  if (f == EAST){
    add_colour(row+5, pos+3, "%^B_MAGENTA%^");
  }
  for (i=4;i<13;i++){
    switch (f){
    case EAST:
      switch(i){
      case (11):
      case (12):
        col = "%^B_BLACK%^%^BOLD%^%^YELLOW%^";
        break;
      default:
        col = "%^B_MAGENTA%^";
      }
      add_colour(row+5, pos+i, col);
      break;
    case WEST:
      switch(i){
      case (4):
        col = "%^B_BLACK%^%^BOLD%^%^YELLOW%^";
        break;
      case (5):
        col = "%^B_BLACK%^%^BOLD%^%^YELLOW%^";
        break;
      case (6):
        col = "%^B_MAGENTA%^%^BOLD%^%^RED%^";
        break;
      case (13): col = "";
        break;
      default:
        col = "%^B_MAGENTA%^";
      }
      add_colour(row+5, pos+i, col);
      break;
    }
  }
  add_colour(row + 5, pos + 13, colour );
  add_colour(row + 5, pos + 14, colour2 );
  add_colour(row+5, pos + 16,  "%^BOLD%^%^WHITE%^");
  colour = get_bg_colour(row + 6, pos +13);
  for (i=4;i<13;i++){
    switch (f){
    case EAST:
      switch(i){
      case (10):
      case (11):
      case (12):
        col = "%^B_BLACK%^%^BOLD%^%^YELLOW%^";
        break;
      case (13):
        col = "%^BOLD%^%^WHITE%^";
        break;
      default:
        col = "%^B_MAGENTA%^";
      }
      add_colour(row+6, pos+i, col);
      break;
    case WEST:
      switch(i){
      case (4):
      case (5):
      case (6):
        col = "%^B_BLACK%^%^BOLD%^%^YELLOW%^";
        break;
      case (12):
        col = "%^BOLD%^%^RED%^";
        break;
      default:
        col = "%^B_MAGENTA%^";
      }
      add_colour(row+6, pos+i, col);
      break;
    }
  }
  add_colour(row + 6, pos + 13, colour);
  switch (f){
  case EAST:
    colour = get_bg_colour(row + 7, pos +12);
    break;
  case WEST:
    colour = get_bg_colour(row + 7, pos +11);
    break;
  }
  if (f ==EAST){
    add_colour(row+7, pos + 11, "%^B_MAGENTA%^");
  }
  for (i=5;i<11;i++){
    add_colour(row+7, pos+i, "%^B_MAGENTA%^");
  }
  if (f==WEST){
    add_colour(row+7, pos+ 4, "%^B_MAGENTA%^");
    add_colour(row + 7, pos + 11, colour );
  } else {
    add_colour(row+7, pos+ 11, "%^B_MAGENTA%^");
    add_colour(row + 7, pos + 12, colour );
  }
  add_colour(row + 7, pos + 14, "%^BOLD%^%^WHITE%^");
}

string * colour_broken_bridge(string * bridge){
  int i,j, *positions;
  int * unfettered;
  for (i = 0;i<28;i++){
    positions = keys(__Colours[i]);
    if (sizeof(positions)<1){
      continue;
    }
    positions = sort_array(positions, "compare", TO);
    for (j = sizeof(positions)-1;j>-1;j--){
      bridge[i] ="/daemon/str_insert_d.c"->brute_insert_string(bridge[i],__Colours[i][positions[j]], positions[j]);
    }
  }
  return bridge;
}

void insert_bridge_colours(string * bridge){
  int j;
  for(j=0;j<sizeof(bridge);j++){
  switch(j){
  case 0..2: 
    add_colour(j,0, "%^B_CYAN%^");
    break;
  case 3:
    add_colour(j,43, "%^B_GREEN%^");
    add_colour(j,33, "%^B_CYAN%^");
    add_colour(j,0, "%^B_GREEN%^");
    break;
  case 4:
    add_colour(j, 42, "%^B_GREEN%^");
    add_colour(j, 33, "%^B_CYAN%^");
    add_colour(j, 31, "%^B_ORANGE%^");
    add_colour(j, 29, "%^B_WHITE%^");
    add_colour(j, 0, "%^B_GREEN%^");
    add_colour(j, 0, "%^BOLD%^%^WHITE%^");
    break;
  case 5:
    add_colour(j, 43, "%^B_GREEN%^");
    add_colour(j, 42, "%^B_WHITE%^");
    add_colour(j, 41, "%^B_GREEN%^");
    add_colour(j, 38, "%^B_BLUE%^");
    add_colour(j, 32, "%^B_GREEN%^");
    add_colour(j, 29, "%^B_ORANGE%^");
    add_colour(j, 25, "%^B_WHITE%^");
    add_colour(j, 0, "%^B_GREEN%^");
    add_colour(j, 0, "%^BOLD%^%^WHITE%^");
    break;
  case 6:
    add_colour(j, 44, "%^B_GREEN%^");
    add_colour(j, 43, "%^B_WHITE%^");
    add_colour(j, 41, "%^B_ORANGE%^");
    add_colour(j, 39, "%^B_GREEN%^");
    add_colour(j, 36, "%^B_BLUE%^");
    add_colour(j, 30, "%^B_GREEN%^");
    add_colour(j, 25, "%^B_ORANGE%^");
    add_colour(j, 22, "%^B_WHITE%^");
    add_colour(j, 0, "%^B_GREEN%^");
    add_colour(j, 0, "%^BOLD%^%^WHITE%^");
    break;
  case 7:
    add_colour(j, 45, "%^B_GREEN%^");
    add_colour(j, 44, "%^B_WHITE%^");
    add_colour(j, 43, "%^B_ORANGE%^");
    add_colour(j, 40, "%^B_GREEN%^");
    add_colour(j, 37, "%^B_BLUE%^");
    add_colour(j, 31, "%^B_GREEN%^");
    add_colour(j, 24, "%^B_ORANGE%^");
    add_colour(j, 21, "%^B_WHITE%^");
    add_colour(j, 0, "%^B_GREEN%^");
    add_colour(j, 0, "%^BOLD%^%^WHITE%^");
    break;
  case 8:
    add_colour(j, 46, "%^B_GREEN%^");
    add_colour(j, 45, "%^B_WHITE%^");
    add_colour(j, 44, "%^B_ORANGE%^");
    add_colour(j, 39, "%^B_GREEN%^");
    add_colour(j, 36, "%^B_BLUE%^");
    add_colour(j, 29, "%^B_GREEN%^");
    add_colour(j, 21, "%^B_ORANGE%^");
    add_colour(j, 19, "%^B_WHITE%^");
    add_colour(j, 0, "%^B_GREEN%^");
    add_colour(j, 0, "%^BOLD%^%^WHITE%^");
    break;
  case 9:
    add_colour(j, 48, "%^B_GREEN%^");
    add_colour(j, 46, "%^B_WHITE%^");
    add_colour(j, 44, "%^B_ORANGE%^");
    add_colour(j, 39, "%^B_GREEN%^");
    add_colour(j, 34, "%^B_BLUE%^");
    add_colour(j, 27, "%^B_GREEN%^");
    add_colour(j, 19, "%^B_ORANGE%^");
    add_colour(j, 17, "%^B_WHITE%^");
    add_colour(j, 0, "%^B_GREEN%^");
    add_colour(j, 0, "%^BOLD%^%^WHITE%^");
    break;
  case 10:
    add_colour(j, 56, "%^B_GREEN%^");
    add_colour(j, 51, "%^B_GREEN%^");
    add_colour(j, 48, "%^B_WHITE%^");
    add_colour(j, 44, "%^B_ORANGE%^");
    add_colour(j, 39, "%^B_GREEN%^");
    add_colour(j, 32, "%^B_BLUE%^");
    add_colour(j, 25, "%^B_GREEN%^");
    add_colour(j, 18, "%^B_ORANGE%^");
    add_colour(j, 17, "%^B_WHITE%^");
    add_colour(j, 0, "%^B_GREEN%^");
    add_colour(j, 0, "%^BOLD%^%^WHITE%^");
    break;
  case 11:
    add_colour(j, 54, "%^B_GREEN%^");
    add_colour(j, 50, "%^B_WHITE%^");
    add_colour(j, 44, "%^B_ORANGE%^");
    add_colour(j, 39, "%^B_GREEN%^");
    add_colour(j, 30, "%^B_BLUE%^");
    add_colour(j, 24, "%^B_GREEN%^");
    add_colour(j, 18, "%^B_ORANGE%^");
    add_colour(j, 16, "%^B_WHITE%^");
    add_colour(j, 0, "%^B_GREEN%^");
    add_colour(j, 0, "%^BOLD%^%^WHITE%^");
    break;
  case 12:
    add_colour(j, 56, "%^B_GREEN%^");
    add_colour(j, 53, "%^B_WHITE%^");
    add_colour(j, 44, "%^B_ORANGE%^");
    add_colour(j, 40, "%^B_GREEN%^");
    add_colour(j, 29, "%^B_BLUE%^");
    add_colour(j, 24, "%^B_GREEN%^");
    add_colour(j, 17, "%^B_ORANGE%^");
    add_colour(j, 14, "%^B_WHITE%^");
    add_colour(j, 0, "%^B_GREEN%^");
    add_colour(j, 0, "%^BOLD%^%^WHITE%^");
    break;
  case 13:
    add_colour(j, 58, "%^B_GREEN%^");
    add_colour(j, 55, "%^B_WHITE%^");
    add_colour(j, 44, "%^B_ORANGE%^");
    add_colour(j, 41, "%^B_GREEN%^");
    add_colour(j, 27, "%^B_BLUE%^");
    add_colour(j, 23, "%^B_GREEN%^");
    add_colour(j, 14, "%^B_ORANGE%^");
    add_colour(j, 11, "%^B_WHITE%^");
    add_colour(j, 0, "%^B_GREEN%^");
    add_colour(j, 0, "%^BOLD%^%^WHITE%^");
    break;
  case 14:
    add_colour(j, 60, "%^B_GREEN%^");
    add_colour(j, 56, "%^B_WHITE%^");
    add_colour(j, 44, "%^B_ORANGE%^");
    add_colour(j, 41, "%^B_GREEN%^");
    add_colour(j, 25, "%^B_BLUE%^");
    add_colour(j, 20, "%^B_GREEN%^");
    add_colour(j, 11, "%^B_ORANGE%^");
    add_colour(j, 9, "%^B_WHITE%^");
    add_colour(j, 0, "%^B_GREEN%^");
    add_colour(j, 0, "%^BOLD%^%^WHITE%^");
    break;
  case 15:
    add_colour(j, 62, "%^B_GREEN%^");
    add_colour(j, 58, "%^B_WHITE%^");
    add_colour(j, 46, "%^B_ORANGE%^");
    add_colour(j, 43, "%^B_GREEN%^");
    add_colour(j, 22, "%^B_BLUE%^");
    add_colour(j, 17, "%^B_GREEN%^");
    add_colour(j, 9, "%^B_ORANGE%^");
    add_colour(j, 7, "%^B_WHITE%^");
    add_colour(j, 0, "%^B_GREEN%^");
    add_colour(j, 0, "%^BOLD%^%^WHITE%^");
    break;
  case 16:
    add_colour(j, 63, "%^B_GREEN%^");
    add_colour(j, 59, "%^B_WHITE%^");
    add_colour(j, 47, "%^B_ORANGE%^");
    add_colour(j, 44, "%^B_GREEN%^");
    add_colour(j, 21, "%^B_BLUE%^");
    add_colour(j, 15, "%^B_GREEN%^");
    add_colour(j, 7, "%^B_ORANGE%^");
    add_colour(j, 5, "%^B_WHITE%^");
    add_colour(j, 0, "%^B_GREEN%^");
    add_colour(j, 0, "%^BOLD%^%^WHITE%^");
    break;
  case 17:
    add_colour(j, 64, "%^B_GREEN%^");
    add_colour(j, 61, "%^B_WHITE%^");
    add_colour(j, 48, "%^B_ORANGE%^");
    add_colour(j, 46, "%^B_GREEN%^");
    add_colour(j, 19, "%^B_BLUE%^");
    add_colour(j, 13, "%^B_GREEN%^");
    add_colour(j, 5, "%^B_ORANGE%^");
    add_colour(j, 4, "%^B_WHITE%^");
    add_colour(j, 0, "%^B_GREEN%^");
    add_colour(j, 0, "%^BOLD%^%^WHITE%^");
    break;
  case 18:
    add_colour(j, 66, "%^B_GREEN%^");
    add_colour(j, 62, "%^B_WHITE%^");
    add_colour(j, 49, "%^B_ORANGE%^");
    add_colour(j, 47, "%^B_GREEN%^");
    add_colour(j, 17, "%^B_BLUE%^");
    add_colour(j, 11, "%^B_GREEN%^");
    add_colour(j, 4, "%^B_ORANGE%^");
    add_colour(j, 2, "%^B_WHITE%^");
    add_colour(j, 0, "%^B_GREEN%^");
    add_colour(j, 0, "%^BOLD%^%^WHITE%^");
    break;
  case 19:
    add_colour(j, 67, "%^B_GREEN%^");
    add_colour(j, 62, "%^B_WHITE%^");
    add_colour(j, 50, "%^B_ORANGE%^");
    add_colour(j, 48, "%^B_GREEN%^");
    add_colour(j, 15, "%^B_BLUE%^");
    add_colour(j, 10, "%^B_GREEN%^");
    add_colour(j, 3, "%^B_ORANGE%^");
    add_colour(j, 1, "%^B_WHITE%^");
    add_colour(j, 0, "%^B_GREEN%^");
    add_colour(j, 0, "%^BOLD%^%^WHITE%^");
    break;
  case 20:
    add_colour(j, 64, "%^B_WHITE%^");
    add_colour(j, 51, "%^B_ORANGE%^");
    add_colour(j, 49, "%^B_GREEN%^");
    add_colour(j, 14, "%^B_BLUE%^");
    add_colour(j, 9, "%^B_GREEN%^");
    add_colour(j, 2, "%^B_ORANGE%^");
    add_colour(j, 0, "%^B_WHITE%^");
    add_colour(j, 0, "%^BOLD%^%^WHITE%^");
    break;
    }
  }
}

void insert_broken_bridge_colours(string * bridge){
  int j;
  for(j=0;j<sizeof(bridge);j++){
    switch(j){
    case 0..6: 
      add_colour(j,0, "%^B_CYAN%^");
      add_colour(j, 0, "%^BOLD%^%^WHITE%^");
      break;
    case 7:
      add_colour(j,59, "%^B_GREEN%^");
      add_colour(j,8, "%^B_CYAN%^");
      add_colour(j,0, "%^B_GREEN%^");
      add_colour(j, 0, "%^BOLD%^%^WHITE%^");
      break;
    case 8:
      add_colour(j,59, "%^B_WHITE%^");
      add_colour(j,48, "%^B_GREEN%^");
      add_colour(j,18, "%^B_CYAN%^");
      add_colour(j, 8, "%^B_GREEN%^");
      add_colour(j,0, "%^B_WHITE%^");
      add_colour(j, 0, "%^BOLD%^%^WHITE%^");
      break;
    case 9:
      add_colour(j, 60, "%^B_ORANGE%^");
      add_colour(j, 59, "%^B_YELLOW%^");
      add_colour(j, 48, "%^B_WHITE%^");
      add_colour(j, 38, "%^B_GREEN%^");
      add_colour(j, 27, "%^B_CYAN%^");
      add_colour(j, 18, "%^B_GREEN%^");
      add_colour(j, 8, "%^B_WHITE%^");
      add_colour(j, 7, "%^B_YELLOW%^");
      add_colour(j, 0, "%^B_ORANGE%^");
      add_colour(j, 0, "%^BOLD%^%^WHITE%^");
      break;
    case 10:
      add_colour(j, 60, "%^B_ORANGE%^");
      add_colour(j, 59, "%^B_YELLOW%^");
      add_colour(j, 48, "%^B_ORANGE%^");
      add_colour(j, 38, "%^B_WHITE%^");
      add_colour(j, 27, "%^B_CYAN%^");
      add_colour(j, 18, "%^B_WHITE%^");
      add_colour(j, 8, "%^B_ORANGE%^");
      add_colour(j, 7, "%^B_YELLOW%^");
      add_colour(j, 0, "%^B_ORANGE%^");
      add_colour(j, 0, "%^BOLD%^%^WHITE%^");
      break;
    case 11..22:
      add_colour(j, 60, "%^B_ORANGE%^");
      add_colour(j, 59, "%^B_YELLOW%^");
      add_colour(j, 38, "%^B_ORANGE%^");
      add_colour(j, 27, "%^B_CYAN%^");
      add_colour(j, 8, "%^B_ORANGE%^");
      add_colour(j, 7, "%^B_YELLOW%^");
      add_colour(j, 0, "%^B_ORANGE%^");
      add_colour(j, 0, "%^BOLD%^%^WHITE%^");
      break;
    case 23:
      add_colour(j, 38, "%^B_ORANGE%^");
      add_colour(j, 27, "%^B_BLUE%^");
      add_colour(j, 0, "%^B_ORANGE%^");
      add_colour(j, 0, "%^BOLD%^%^WHITE%^");
      break;
    case 24:
      add_colour(j, 42, "%^B_ORANGE%^");
      add_colour(j, 18, "%^B_BLUE%^");
      add_colour(j, 0, "%^B_ORANGE%^");
      add_colour(j, 0, "%^BOLD%^%^WHITE%^");
      break;
    case 25:
      add_colour(j, 45, "%^B_ORANGE%^");
      add_colour(j, 15, "%^B_BLUE%^");
      add_colour(j, 0, "%^B_ORANGE%^");
      add_colour(j, 0, "%^BOLD%^%^WHITE%^");
      break;
    case 26:
      add_colour(j, 48, "%^B_ORANGE%^");
      add_colour(j, 12, "%^B_BLUE%^");
      add_colour(j, 0, "%^B_ORANGE%^");
      add_colour(j, 0, "%^BOLD%^%^WHITE%^");
      break;
    case 27:
      add_colour(j, 50, "%^B_ORANGE%^");
      add_colour(j, 10, "%^B_BLUE%^");
      add_colour(j, 0, "%^B_ORANGE%^");
      add_colour(j, 0, "%^BOLD%^%^WHITE%^");
      break;
    }
  }
}

string * colour_bridge(string * bridge){
  int i,j, *positions;
  for (i = 0;i<21;i++){
    positions = keys(__Colours[i]);
    if (sizeof(positions)<1){
      continue;
    }
    positions = sort_array(positions, "compare", TO);
    for (j = sizeof(positions)-1;j>-1;j--){
      bridge[i] ="/daemon/str_insert_d.c"->brute_insert_string(bridge[i],__Colours[i][positions[j]], positions[j]);
    }
  }
  return bridge;
}

varargs void tell_bridge(string str, object ob){
  int i;
  object room, room2;
  for (i=0;i<6;i++){
    room = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
    if (objectp(room)){
      if (objectp(ob)){
        tell_room(room, str, ob);
      } else {
        tell_room(room, str);
      }
    }
  }
  for (i=1;i<5;i++){
    room = find_object_or_load(JUNG_ROOM + "bbridge_e" + i);
    room2 = find_object_or_load(JUNG_ROOM + "bbridge_w" + i);
    if (objectp(room)){
      if (objectp(ob)){
        tell_room(room, str, ob);
        tell_room(room2, str, ob);
      } else {
        tell_room(room, str);
        tell_room(room2, str);
      }
    }
  }
}

int is_above(object ob1, object ob2){
  int vPos1, vPos2;
  if (!objectp(ob1)||!objectp(ob2)){
    return -1;
  }
  if (break_point == -1){
    return -1;
  }
  vPos1 = query_vPos(ob1); 
  vPos2 = query_vPos(ob2);
  if (vPos1 < vPos2){
    return 1;
  } else {
    return -1;
  }
}

int is_below(object ob1, object ob2){
  int vPos1, vPos2;
  if (!objectp(ob1)||!objectp(ob2)){
    return -1;
  }
  if (break_point == -1){
    return -1;
  }
  
  vPos1 = query_vPos(ob1); 
  vPos2 = query_vPos(ob2);
  if (vPos1 > vPos2){
    return 1;
  } else {
    return -1;
  }
}

int same_side(object ob1, object ob2){
  int pos1, pos2;
  if (!objectp(ob1)||!objectp(ob2)){
    return -1;
  }
  pos1 = query_pos(ob1);
  pos2 = query_pos(ob2);
  if ((pos1>break_point && pos2 > break_point)||
              (pos1<break_point&&pos2<break_point)){
    return 1;
  }
  return 0;
}

int convert_to_vPos(int pos){
  int vPosition;
  if (pos >break_point){
    vPosition = 66 - pos/3;
  } else {
    vPosition = 3 + pos /3;
  }
  return vPosition;
}


varargs int query_vPos(object ob, string * pic){
  int p, vPos, vHeight, bridge_height;
  object * flyers;
  if (!objectp(ob)){
    return -1;
  }
  if (sizeof(pic) <1){
    pic = get_picture(ob, TP);
  }
  if (sizeof(pic) <1){
    return -1;
  }
  vHeight = sizeof(pic);
  if (break_point>-1){
    bridge_height = 28;
  } else {
    bridge_height = 21;
  }
  if ((int)ob->query_property("flying")==1 ){
    flyers = keys (__VPos);
    if (sizeof(flyers)>0){ 
      if (member_array(ob, flyers)!=-1){
        vPos =  __VPos[ob];
        if (vPos + vHeight > bridge_height){
          vPos = bridge_height - vHeight;
        }
        return vPos;
      }
    }
  }
  p = query_pos(ob);
  if (break_point>-1 && !(int)ob->query_property("flying")){  
    if (p <= break_point){
      ob->set_face(WEST);
      vPos = 6 + p/3;
    } else {
      ob->set_face(EAST);
      vPos = vHeight + (65 - p)/3;
    }  
    if(vPos + vHeight> 28){
      vPos = 28 - vHeight;
    }
  } else {
    switch (p){
    case 0..7:
      vPos = 9;
      break;
    case 8:
      vPos = 10;
      break;
    case 9:
      vPos = 11;
      break;
    case 10:
      vPos = 12;
      break;
    case 11..54:
      vPos = 12;
      break;
    case 55:
      vPos = 11;
      break;
    case 56:
      vPos = 10;
      break;
    default:
      vPos = 9;
      break;
    }
    vPos -= (vHeight -5);
  }
  if (break_point>-1 && (int)ob->query_property("flying")){
    vPos -= 6;
  }
  if ( (int)ob->query_property("flying")){
    if (break_point>=-1){
      vPos -= 2;
    } else {
      vPos -= 5;
    }
  }
  if (vPos + vHeight > bridge_height){
    vPos = bridge_height - vHeight;
  }
  __VPos[ob] = vPos;
  return vPos;
}

void fall(object faller){
  int i;
  object room;
  if(!objectp(faller)||faller->query_true_invis()){
    tell_object(faller, "As an IMMORTAL, you are saved the ravages of falling,"
      +" and drift easily to the ground");
    room = find_object_or_load(JUNG_ROOM + "canyon_riverbank");
    if (objectp(room)){
      faller->remove_paralyzed();
      faller->move(room);
      faller->force_me("look");
    }
    remove_crosser(faller);
    return;
  }
  if ((int)faller->query_property("flying")){
    tell_object(faller, "Rather than falling, you are able to%^BOLD%^%^WHITE%^"
      +" swoop %^RESET%^across the %^ORANGE%^canyon%^RESET%^.");
    return;
  }
  tell_object(faller, "%^BLUE%^You %^BOLD%^%^WHITE%^sail%^RESET%^%^BLUE%^"
    +" through the air, as the %^BOLD%^%^BLUE%^w%^CYAN%^a%^BLUE%^ters"
    +" %^RESET%^%^BLUE%^of the %^BOLD%^%^BLUE%^river%^RESET%^%^BLUE%^ rush up to"
    +" meet you.");

  i = random(5)+1;
  room = find_object_or_load(JUNG_ROOM + "air" + i);
  if (objectp(room)){
    faller->remove_paralyzed();
    faller->move(room);
    faller->force_me("look");
  }
  remove_crosser(faller);
  faller->set_paralyzed(200, "%^BOLD%^%^CYAN%^You are falling through the"
    +" %^BOLD%^%^WHITE%^a%^RESET%^i%^BOLD%^%^WHITE%^r%^BOLD%^%^CYAN%^.");      
  call_out("land", 1, faller);
}

void swing(object * swingers, int fallers){
  int i, count, pos;
  string side, swingers_desc, fallers_desc;
  object room;
  count = sizeof(swingers);
  if (count<1){ return;}
  switch(count){
  case 1:
    swingers_desc = "One creature";
    break;
  case 2..4:
    swingers_desc = "A few creatures";
  case 5:
    swingers_desc = "Lots of creatures";
  }
  switch (fallers){
  case 1:
    fallers_desc = "One creature";
    break;
  case 2..4:
    fallers_desc = "A few creatures";
    break;
  case 5:
    fallers_desc = "Lots of creatures";
    break;
  }
  tell_bridge("%^BOLD%^%^BLUE%^As the %^RESET%^%^ORANGE%^bridge"
    +" %^BOLD%^%^BLUE%^collapses, the two sides swing down to smash"
    +" against the canyon walls. %^RESET%^" + fallers_desc + " fall off"
    +" the bridge and into the %^BOLD%^%^CYAN%^r%^BOLD%^%^WHITE%^i"
    +"%^BOLD%^%^BLUE%^v%^RESET%^%^BLUE%^e%^BOLD%^%^CYAN%^r%^BOLD%^%^BLUE%^"
    +" below.");
  if (count >0){
    tell_bridge(swingers_desc + " manage to cling onto the bridge and ride"
      +" it all the way down.");
    for (i=0;i<count;i++){
      pos = query_pos(swingers[i]);
      if (pos < break_point){
        side = "west";
      } else {
        side = "east";
      }
      tell_object(swingers[i], "%^ORANGE%^As one of the lucky ones clinging"
        +" onto the bridge, you sail all the way down to finish on the "
        + side + " side of the canyon.");
      room = find_object_or_load((object)environment(swingers[i])->get_correct_room(pos));
      if (objectp(room)){
        swingers[i]->move(room);
        swingers[i]->force_me("look");
      } else {
        tell_object(swingers[i], "ERROR - something's wrong with the room"
          +" you were supposed to move to. Please make a bug report,"
          +" mentioning the 'bridge monitor daemon'");
      }
    }
  }
}

void land(object faller){
  int damage, roll, i;
  object room;
  if(!objectp(faller)||faller->query_true_invis()){return;}
  roll = (int)faller->query_skill("athletics")-random(10)-random(10)-random(10)-random(10);
  if (roll<0 && roll > -10) {roll = 0;}
  switch(roll){
    case 0:
      tell_bridge("%^BLUE%^" + faller->QCN + " %^BOLD%^%^YELLOW%^SMACKS"
        +" %^BOLD%^%^BLUE%^flat into the %^BOLD%^%^BLUE%^w%^CYAN%^a%^BLUE%^ter"
        +"%^RESET%^%^BLUE%^, with an impact like a sack of %^BOLD%^%^MAGENTA%^o%^RED%^"
        +"f%^RESET%^%^MAGENTA%^f%^BLUE%^a%^BOLD%^%^MAGENTA%^l%^RESET%^%^BLUE%^"
        +" slamming into a %^RESET%^stone rockface.", faller);
      tell_object(faller, "%^BLUE%^You %^BOLD%^%^YELLOW%^SMACK"
        +" %^BOLD%^%^BLUE%^flat into the %^BOLD%^%^BLUE%^w%^CYAN%^a%^BLUE%^ter"
        +"%^RESET%^%^BLUE%^, with an impact like a sack of %^BOLD%^%^MAGENTA%^o%^RED%^"
        +"f%^RESET%^%^MAGENTA%^f%^RED%^a%^BOLD%^%^MAGENTA%^l%^RESET%^%^BLUE%^"
        +" slamming into a %^RESET%^stone rockface.", faller);
      damage = (int)faller->query_max_hp() * (50 + random(25))/100;
      faller->cause_typed_damage(faller, faller->return_target_limb(),damage/3 + random(damage), "bludgeoning");
      faller->add_attacker(TO);
      faller->continue_attack();
      break;
    case 1..10:
      tell_bridge("%^BLUE%^" + faller->QCN + "%^RESET%^%^BLUE%^hits the water feet"
        +" first, not entirely straight, %^RED%^hurting " + faller->QO + "self%^BLUE%^"
        +" quite badly in the process", faller);
      tell_object(faller, "%^BLUE%^You %^RESET%^%^BLUE%^hit the water feet first,"
        +" not entirely straight, %^RED%^hurting yourself%^BLUE%^ quite badly in the"
        +" process.");
      roll = 50 + random(25);
      damage = (int)faller->query_max_hp() * roll / 100;
      faller->cause_typed_damage(faller, faller->return_target_limb(), damage, "bludgeoning");
      break;
    case 11..20:
      tell_bridge("%^BLUE%^" + faller->QCN + "%^RESET%^%^BLUE%^hits the water hard,"
        +" causing " + faller->QP + "self a good deal of %^RED%^pain%^BLUE%^", faller);
      tell_object(faller, "%^BLUE%^You hit the water hard, causing yourself a good"
        +" deal of %^RED%^pain%^BLUE%^.");
      roll = 10 + random(25);
      damage = (int)faller->query_max_hp() * roll / 100;
      faller->cause_typed_damage(faller, faller->return_target_limb(), damage, "bludgeoning");
      break;
    case 21..30:
      tell_bridge("%^BLUE%^" + faller->QCN + " %^RESET%^%^BLUE%^converts "
        + faller->QP + " fall into a %^BOLD%^%^WHITE%^smooth dive%^RESET%^%^BLUE%^"
        +" into the %^BOLD%^%^BLUE%^river%^RESET%^%^BLUE%^.", faller);
      tell_object(faller, "%^BLUE%^You %^RESET%^%^BLUE%^convert your fall into a"
        + " fall into a %^BOLD%^%^WHITE%^smooth dive%^RESET%^%^BLUE%^ into the"
        +" %^BOLD%^%^BLUE%^river%^RESET%^%^BLUE%^.");
      break;  
    case 31..20000:
      tell_bridge("%^BLUE%^" + faller->QCN + " %^RESET%^%^BLUE%^turns a"
        +" %^BOLD%^%^YELLOW%^flashy somersault%^RESET%^ before diving into the river"
        +" with %^BOLD%^%^CYAN%^barely a splash%^RESET%^%^BLUE%^.", faller);
      tell_object(faller, "%^BLUE%^You  %^RESET%^%^BLUE%^turn a"
        +" %^BOLD%^%^YELLOW%^flashy somersault%^RESET%^ before diving into the river"
        +" with %^BOLD%^%^CYAN%^barely a splash%^RESET%^%^BLUE%^.");
      break;
    default:
      tell_bridge("%^BLUE%^" + faller->QCN + " %^BOLD%^%^YELLOW%^SMACKS"
        +" %^BOLD%^%^BLUE%^flat into the %^BOLD%^%^BLUE%^w%^CYAN%^a%^BLUE%^ter"
        +"%^RESET%^%^BLUE%^, with an impact like a sack of %^BOLD%^%^MAGENTA%^o%^RED%^"
        +"f%^RESET%^%^MAGENTA%^f%^BLUE%^a%^BOLD%^%^MAGENTA%^l%^RESET%^%^BLUE%^"
        +" slamming into a %^RESET%^stone rockface.", faller);
      tell_object(faller, "%^BLUE%^You %^BOLD%^%^YELLOW%^SMACK"
        +" %^BOLD%^%^BLUE%^flat into the %^BOLD%^%^BLUE%^w%^CYAN%^a%^BLUE%^ter"
        +"%^RESET%^%^BLUE%^, with an impact like a sack of %^BOLD%^%^MAGENTA%^o%^RED%^"
        +"f%^RESET%^%^MAGENTA%^f%^BLUE%^a%^BOLD%^%^MAGENTA%^l%^RESET%^%^BLUE%^"
        +" slamming into a %^RESET%^stone rockface.", faller);
      damage = (int)faller->query_max_hp() * 95 / 100;
      faller->cause_typed_damage(faller, faller->return_target_limb(), damage, "bludgeoning");
      break;
  }
  i = random(5)+1;
  room = find_object_or_load(JUNG_ROOM + "canyon_riverbank");
  if (objectp(room)){
    faller->remove_paralyzed();
    faller->move(room);
    faller->force_me("look");
  }
  faller->set_paralyzed(10 + random (10), "%^BOLD%^%^CYAN%^You are recovering from"
    +" your fall.");      
}

void break_bridge(int bp, object breaker){
  object rm, otherroom, * critters, *swingers, * weapons, weapon;
  int i, count, fallers, j, k;
  string wp_name;
  if (!objectp(breaker)){
    return;
  }
  fallers = 0;
  swingers = ({});
  critters= ({});
  break_point = bp;
  tell_object(breaker, "%^BOLD%^%^YELLOW%^You %^BOLD%^%^RED%^cut"
    +" %^BOLD%^%^YELLOW%^through the final rope, and the bridge"
    +" collapses!");
  for (i = 0;i<6;i++){
    rm = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
    if (objectp(rm)){
      tell_room(rm, "%^BOLD%^%^YELLOW" + breaker->QCN + "%^BOLD%^%^RED%^cuts"
        +" %^BOLD%^%^YELLOW%^through the final rope, and the bridge"
        +" collapses!", breaker);
      critters += all_living(rm);
    }
  }
  count = sizeof(critters);
  if (count >0){
    for (i=0;i<count;i++){
      if ((int)critters[i]->query_property("gripped")==1){
        if (!critters[i]->query_true_invis()){
          tell_bridge("%^BOLD%^%^BLUE%^" + critters[i]->QCN 
            + " %^BOLD%^%^BLUE%^hangs onto the bridge as it collapses!"
            , critters[i]);
        }
        tell_object(critters[i], "%^BOLD%^%^BLUE%^You hang onto the bridge as"
          +" it collapses!");
        swingers += ({critters[i]});
        weapons = critters[i]->query_wielded();
        if (sizeof(weapons)>0){
          tell_object(critters[i], "%^BOLD%^%^CYAN%^You lose grip on your weapons!");
          for (j = 0;j<sizeof(weapons);j++){
            wp_name = weapons[i]->query_name();
            weapon = present(wp_name, critters[i]);
            if (weapon != weapons[i]){
              for (k=1;k<10;k++){
                weapon = present(wp_name + " " + k, critters[i]);
                if (weapon == weapons[i]){
                  wp_name = wp_name + " " + k;
                  break;
                }
              }
            }
            critters[i]->force_me("unwield " + wp_name);
          }
        }
        critters[i]->set_dir(STATIONARY);
        critters[i]->remove_property("gripped");
        continue;
      }
      if ("/daemon/saving_throw_d.c"->reflex_save(critters[i],-27)){
        if (!critters[i]->query_true_invis()){
          tell_bridge("%^BOLD%^%^BLUE%^Quick as a %^BOLD%^%^YELLOW%^flash"
          +" %^BOLD%^%^BLUE%^"+critters[i]->QCN+"%^BOLD%^%^BLUE%^ grabs for"
          +" the bridge as it collapses underneath " + critters[i]->QO
          , critters[i]);
        }
        tell_object(critters[i], "%^BOLD%^%^BLUE%^Quick as a"
         +" %^BOLD%^%^YELLOW%^flash, you grab for the bridge as it collapses"
         +" underneath you!");
        weapons = critters[i]->query_wielded();
        if (sizeof(weapons)>0){
          tell_object(critters[i], "%^BOLD%^%^CYAN%^You lose grip on your weapons!");
          for (j = 0;j<sizeof(weapons);j++){
            wp_name = weapons[i]->query_name();
            weapon = present(wp_name, critters[i]);
            if (weapon != weapons[i]){
              for (k=1;k<10;k++){
                weapon = present(wp_name + " " + k, critters[i]);
                if (weapon == weapons[i]){
                  wp_name = wp_name + " " + k;
                  break;
                }
              }
            }
            critters[i]->force_me("unwield " + wp_name);
          }
        }
        if (random(20)+ random(7) + random(6)
                                    > critters[i]->query_stats("strength")){
          if (!critters[i]->query_true_invis()){
            tell_bridge("%^BOLD%^%^BLUE%^" + critters[i]->QCN + "loses " 
              + critters[i]->QP + "grip on the bridge and%^BOLD%^%^RED%^"
              +" falls%^BOLD%^%^BLUE%^!",critters[i]);
          }
          tell_object(critters[i], "%^BOLD%^%^BLUE%^You lose your grip on"
             +" the bridge and%^BOLD%^%^RED%^ fall%^BOLD%^%^BLUE%^!");
          fall(critters[i]);
        } 
      } else {
        if (!critters[i]->query_true_invis()){
          tell_bridge("%^BOLD%^%^BLUE%^"+critters[i]->QCN+"%^BOLD%^%^RED%^"
            +" plunges%^BOLD%^%^BLUE%^ through the %^BOLD%^%^CYAN%^air"
            +" %^BOLD%^%^BLUE%^as the bridge collapses underneath "
            + critters[i]->QO, critters[i]);
        }
        tell_object(critters[i], "%^BOLD%^%^BLUE%^You%^BOLD%^%^RED%^ plunge" 
          +" %^BOLD%^%^BLUE%^through the %^BOLD%^%^CYAN%^air%^BOLD%^%^BLUE%^"
          +" as the bridge collapses underneath you!");
        fall(critters[i]);
        fallers ++;        
      } 
    }
    call_out("swing", 1, swingers, fallers);
  }
}

void set_VPos(object ob, int vPos){
  __VPos[ob] = vPos;
} 

void show_bridge(object looker){
  string * bridge, *pic, * rooms;
  object * critters, *obs, ob;
  int i, j, *posDir, vPos, vHeight, hPos, unf_pos, unf_row, unf_face, flag;
  setup_Colours();
  if (break_point == -1){
    bridge = ({
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"   ||  ||                                                   ||  ||   ",
"   ||  ||                                                   ||  ||   ",
" __||__||                                                   ||__||__ ",
" --||--||\\                                                 /||--||-- ",
"         \\\\- - - - - - - - - - - - - - - - - - - - - - - -//         ",
"          \\\\_____________________________________________//          ",
"           \\---------------------------------------------/           ",
"                                                                     ",
"                                                                     ",
"                                                                     "});
  } else {
  bridge = ({
"                                                                     ",
"                                                                     ",
"                                                                     ",
"   ||  ||                                                   ||  ||   ",
"   ||  ||                                                   ||  ||   ",
" __||__||                                                   ||__||___",
" --||--||\\                                                 /||--||---",
"         \\\\                                               //||  ||   ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     ",
"                                                                     "
    });
    for (i = 0;i<break_point/3;i++){
      bridge[i+8] = "/daemon/str_insert_d.c"->insert_string(
                                 bridge[i+8],"||",9);
    }
    for (i = 0;i<(60-break_point)/3;i++){
      bridge[i+8] = "/daemon/str_insert_d.c"->insert_string(
                                 bridge[i+8],"||",56);
    }
  }
  for (i = 1;i<5;i++){  
    ob = find_object_or_load(JUNG_ROOM + "ropebridge" + i);
    critters = keys(__PosDir);
  }
  if (sizeof(critters)<1){
    if (break_point == -1){
      insert_bridge_colours(bridge);
      colour_bridge(bridge);
    } else {
      insert_broken_bridge_colours(bridge);
      colour_broken_bridge(bridge);
    }
    show(bridge, looker);
    return;
  }
  flag = 0; //becomes 1 if Unfettered on bridge
  for (i=0;i<sizeof(critters);i++){
    posDir = ({0,0,0});
    ob = critters[i];
    if (!objectp(ob)){
      continue;
    }
    posDir = __PosDir[ob];
    if (sizeof(posDir)<3){
      continue;
    }
    if (break_point > -1 && !ob->query_property("flying")){
      if (posDir[0] <= break_point) {
        if (posDir[0] >0 && posDir[0] <65){
          posDir[2] = WEST;
          ob->set_face(WEST);
        }
      }else{ 
        if (posDir[0] >0 && posDir[0] <65){
          ob->set_face(EAST);
          posDir[2] = EAST;
        }
      }
    }
    pic = get_picture(ob, TP);
    vHeight = sizeof(pic);
    switch (posDir[0]){
    case 0..7:
      vPos = 9;
      break;
    case 8:
      vPos = 10;
      break;
    case 9:
      vPos = 11;
      break;
    case 10:
      vPos = 12;
      break;
    case 11..54:
      vPos = 12;
      break;
    case 55:
      vPos = 11;
      break;
    case 56:
      vPos = 10;
      break;
    default:
      vPos = 9;
      break;
    }
    if (break_point == -1 || (int)ob->query_property("flying")){
      vPos -= (vHeight -5);
      hPos = posDir[0];
      if ((int)ob->query_property("flying")){
        vPos -= 2;
      }
    } else {
      if (posDir[0] <= break_point){
        posDir[2] = EAST;
        hPos = 10;
        vPos = 3 + posDir[0]/3;
      } else {
        posDir[2] = WEST;
        hPos = 53;
        vPos = vHeight + 1 + (65 - posDir[0])/3;
      }  
      switch (posDir[0]){ //Set up top of the bridge positions
      case -10..0:
        hPos = 3;
        vPos = 6- vHeight;
        break;
      case 1..2:
        hPos -= 2;
        break;
      case 3..5:
        hPos -= 1;
        break;
      case 63..64:
        hPos += 1;
        break;
      case 65..100:
        hPos = 60;
        vPos = 6 - vHeight;
        break;
      }
    }
    vPos = query_vPos(ob, pic);
    for (j=vPos; j<vPos + vHeight;j++){
      bridge[j]="/daemon/str_insert_d.c"->insert_string(
                                 bridge[j],pic[j-vPos],hPos);
      if (strlen(bridge[j])>68){
        bridge[j] = bridge[j][0..68];
      }
      add_colour(j, hPos, crit_colour(i));
      add_colour(j, hPos+strlen(pic[j-vPos]), "%^BOLD%^%^WHITE%^");
    }
    if (ob->id("unfettered")){
      unf_row = vPos;
      unf_pos = hPos;
      unf_face = posDir[2];
      flag = 1;
    }
  }
  if (break_point == -1){
//    tell_bridge("inserting bridge colours");
    insert_bridge_colours(bridge);
//    tell_bridge("inserting unfettered colours");
    if (flag ==1){
      colour_unfettered(unf_row, unf_pos, unf_face);
    }
//    tell_bridge("putting colours into place");
    colour_bridge(bridge);
  } else {
    insert_broken_bridge_colours(bridge);
    if (flag ==1){
      colour_unfettered(unf_row, unf_pos, posDir[2]);
    }
    colour_broken_bridge(bridge);
  }
  show(bridge, looker);
}

string crit_colour(int i){
  i = i % 5; 
  switch (i){
  case 0:
    return "%^BOLD%^%^RED%^";
  case 1:
    return "%^BOLD%^%^BLUE%^";
  case 2:
    return "%^BOLD%^%^CYAN%^";
  case 3:
    return "%^BOLD%^%^GREEN%^";
  case 4:
    return "%^BOLD%^%^BLACK%^";
  }
}

void setup_Pictures(){
  mapping pics;
  pics = ([]);
  __RPictures = ([]);
  __LPictures = ([]);
//human pics
  pics["bow"] = ({"(..)|\\", "<||=|-)>", " LL '/"});
  pics["crossbow"] = ({"(..)\\","<||=-)>"," LL /"});
  pics["axe"] = ({"(..) <)"," ||-/"," LL"});
  pics["dagger"] = ({"(..)"," ||-/"," LL"});
  pics["sword"] = ({"(..) /"," ||-/"," LL"});
  pics["mace"] = ({"(..) O"," ||-/"," LL"});
  pics["star"] = ({"(..) *"," ||-/"," LL"});
  pics["empty hand"] = ({"(..)"," ||-"," LL"});
  pics["staff"] = ({"(..)|"," ||-|"," LL '"});
  pics["spear"] = ({"(..) /"," ||-/"," LL/" });
  pics["dual wield"] = ({"\\ (..) /"," \\-||-/","   LL"});
  pics["two handed sword"] = ({"      /","(..) /"," ||=+"," LL'"});
  __RPictures["human"] = pics;
  pics = ([]);
  pics ["bow"] = ({"  /|(..)","<(-|=||>","  `' //"});
  pics["crossbow"] = ({"  /(..)","<(-=||>","  ` //"});
  pics["axe"] = ({"(..) <)"," ||-/"," LL"});
  pics["sword"] = ({"\\ (..)"," \\-||","   //"});
  pics["dagger"] = ({" (..)", "\\-||", "  //"});
  pics["mace"] = ({"O (..)", " \\-||", "   //"});
  pics["star"] = ({"* (..)"," \\-||", "   //"});
  pics["empty hand"] = ({"(..)", "-||", " //"});
  pics["staff"] = ({"|(..)","|-||","' //"});
  pics["spear"] = ({"\\ (..)", " \\-||","  \\//"});
  pics["dual wield"] = ({"\\ (..) /"," \\-||-/","   //"});
  pics["two handed sword"] = ({"\\"," \\ (..)","  +=||","   `//"});
  __LPictures["human"] = pics;

//elf pics
  pics = ([]);
  pics["bow"] = ({" ,,", "(..)|\\", "<()=|-)>", " LL '/"});
  pics["crossbow"] = ({" ,,","(..)\\","<()=-)>"," LL /"});
  pics["axe"] = ({" ,,","(..) <)"," ()-/"," LL"});
  pics["dagger"] = ({" ,,","(..) ",  " ()-/"," LL"});
  pics["sword"] = ({" ,,","(..) /"," ()-/"," LL"});
  pics["mace"] = ({"   ,,","O (..)", " \\-()","   //"});
  pics["star"] = ({" ,,", "(..) *", " ()-/"," LL"});
  pics["empty hand"] = ({" ,,","(..)"," ()-"," LL"});
  pics["staff"] = ({" ,,","(..)|"," ()-|"," LL '"});
  pics["spear"] = ({" ,,   7","(..) /"," ()-/"," LL/" });
  pics["dual wield"] = ({"   ,,","\\ (..) /"," \\-()-/","   LL"});
  pics["two handed sword"] = ({" ,,   /","(..) /"," ()=+"," LL'","\\   ,,",});
  __RPictures["elf"] = pics;
  pics = ([]);
  pics ["bow"] = ({"     ,,","  /|(..)","<(-|=()>","  `' //"});
  pics["crossbow"] = ({"    ,,","  /(..)","<(-=()>","  ` //"});
  pics["axe"] = ({"    ,,","(> (..)","  \\-()","    //"});
  pics["sword"] = ({"   ,,","\\ (..)"," \\-()","   //"});
  pics["dagger"] = ({" ,,","(..) "," ()-/"," LL"});
  pics["mace"] = ({"O (..)", " \\\\-||", "   //"});
  pics["star"] = ({"   ,,","* (..)"," \\-()","   //"});
  pics["empty hand"] = ({"  ,,"," (..)",  " -()","  //"});
  pics["staff"] = ({"  ,,","|(..)","|-()","' //"});
  pics["spear"] = ({"^   ,,"," \\ (..)", "  \\-()","   \\//"});
  pics["dual wield"] = ({"   ,,","\\ (..) /"," \\-()-/","   //"});
  pics["two handed sword"] = ({"\\   ,,"," \\ (..)","  +=()","   `//"});
  __LPictures["elf"] = pics;
 
//Centaur pics
  pics = ([]);
  pics ["bow"] = ({"     (} |\\", "| __<|)-|-)>", "'( __ ) |/"," ))  ))"});
  pics["crossbow"] = ({"     (} \\", "| __<|)--)>","'( __ ) /"," ))  ))"});
  pics["axe"] = ({"     (}  <)", "| ___|)-/", "'( __ )", " ))  ))"});
  pics["dagger"] = ({"     (}", "| ___|)-/", "'( __ )", " ))  ))"});
  pics["sword"] = ({"     (}  /", "| ___|)-/", "'( __ )", " ))  ))"});
  pics["mace"] = ({"     (}  0", "| ___|)-/", "'( __ )", " ))  ))"});
  pics["star"] = ({"     (}  *", "| ___|)-/", "'( __ )", " ))  ))"});
  pics["empty hand"] = ({"     (}", "| ___|)-", "'( __ )", " ))  ))"});
  pics["staff"] = ({"     (} |", "| ___|)=|", "'( __ ) |", " ))  )) '"});
  pics["spear"] = ({"          7","     (}  /","| ___|)=/","'( __ )/"," ))  ))"});
  pics["dual wield"] = ({"  \\  (}  /", "| _\\-|)-/", "'( __ )", " ))  ))"});
  pics["two handed sword"] = ({"          /", "     (}  /", "| ___|)=+", "'( __ )^", " ))  ))"});
  __RPictures["centaur"] = pics;
  pics = ([]);
  pics ["bow"] = ({"  /| {)", "<(-|-(|>__ |", "  \\| ( __ )'", "     ((  (("});
  pics["crossbow"] = ({"  / {)", "<(--(|>__ |", "  \\ ( __ )'", "    ((  (("});
  pics["axe"] = ({"(>  {)", "  \\-(|___ |", "    ( __ )'" , "    ((  (("});
  pics["sword"] = ({"\\  {)", " \\-(|___ |", "   ( __ )'", "   ((  (("});
  pics["dagger"] = ({"  {)", "\\-(|___ |", "  ( __ )'", "  ((  (("});
  pics["mace"] = ({"0  {)", " \\-(|___ |", "   ( __ )'", "   ((  (("});
  pics["star"] = ({"*  {)", " \\-(|___ |", "   ( __ )'", "   ((  (("});
  pics["empty hand"] = ({"  {)", " -(|___ |", "  ( __ )'", "  ((  (("});
  pics["staff"] = ({"| {)", "|=(|___ |", "| ( __ )'", "' ((  (("});
  pics["spear"] = ({"^", " \\  {)", "  \\=(|___ |", "   \\( __ )'", "    ((  (("});
  pics["dual wield"] = ({"\\  {)  /"," \\-(|-/_ |","   ( __ )'", "   ((  (("});
  pics["two handed sword"] = ({"\\", " \\  {)", "  +=(|___ |", "   ^( __ )'", "    ((  (("});
  __LPictures["centaur"] = pics;


//Ogre pics
  pics = ([]);
  pics ["bow"] = ({" (..) |\\","<r  7=|-)>","  \\/  |/"," L  L"});
  pics["crossbow"] = ({" (..) \\","<r  7=-)>","  \\/  /"," L  L"});
  pics["axe"] = ({"(..)  <)","r  7-/"," \\/","L  L"});
  pics["dagger"] = ({"(..)","r  7-/"," \\/","L  L"});
  pics["sword"] = ({"       ,","(..)  /","r  7-/"," \\/","L  L"});
  pics["mace"] = ({"       O","(..)  /","r  7-/"," \\/","L  L"});
  pics["star"] = ({"       X","(..)  /","r  7-/"," \\/","L  L"});
  pics["empty hand"] = ({"(..)","r  7-<"," \\/","L  L"});
  pics["staff"] = ({"(..) |","r  7=|"," \\/  |","L  L '"});
  pics["spear"] = ({"       7","(..)  /","r  7=/"," \\/ /","L  L"});
  pics["dual wield"] = ({".          ,"," \\  (..)  /","  \\-r  7-/","     \\/","    L  L"});

  pics["two handed sword"] = ({"        /","       /","(..)  /","r  7=+"," \\/ '","L  L"});
  __RPictures["ogre"] = pics;
  pics = ([]);
  pics ["bow"] = ({"  /| (..)","<(-|=r  7>","  \\|  \\/","     /  /"});
  pics["crossbow"] = ({"  / (..)","<(-=r  7>","  \\  \\/","    /  /"});
  pics["axe"] = ({"(>  (..)","  \\-r  7","     \\/","    /  /"});
  pics["sword"] = ({"."," \\  (..)","  \\-r  7","     \\/","    /  /"});
  pics["dagger"] = ({"  (..)","\\-r  7","   \\/","  /  /"});
  pics["mace"] = ({"O"," \\  (..)","  \\-r  7","     \\/","    /  /"});
  pics["star"] = ({"X"," \\  (..)","  \\-r  7","     \\/","    /  /"});
  pics["empty hand"] = ({"  (..)",">-r  7","   \\/","  /  /"});
  pics["staff"] = ({"| (..)","|=r  7","|  \\/","' /  /"});
  pics["spear"] = ({"^"," \\  (..)","  \\=r  7","   \\ \\/","    /  /"});
  pics["dual wield"] = ({".          ,"," \\  (..)  /","  \\-r  7-/","     \\/","    /  /"});
  pics["two handed sword"] = ({"       /","      /","(..) /"," \\/=+"," LL'"});
  __LPictures["ogre"] = pics;

//Firbolg pics
  pics = ([]);
  pics ["bow"] = ({"     |\\", "(..) | \\", "<__:==--)>", " \\ / | /", " | | |/", " L L"});
  pics["crossbow"] = ({"(..)   \\", "<__7==--)>", " \\ /   /", " | |  '", " L L"});
  pics["axe"] = ({"(..)   <)", "r  7--/", " \\ /", " | |", " L L"});
  pics["dagger"] = ({"   (..)  /", "   r  7-+", "    \\ /", "    | |", "    L L"});
  pics["sword"] = ({"(..)   /", "r  7--/", " \\ /", " | |", " L L"});
  pics["mace"] = ({"      O", "(..)  |", "r  7--|", " \\ /", " | |", " L L"});
  pics["star"] = ({"      *", "(..)  |", "r  7--|", " \\ /", " | |", " L L"});
  pics["empty hand"] = ({"(..)", "r   7--", " \\ /", " | |", " L L"});
  pics["staff"] = ({"      |", "(..)__|", "r  7--|", " \\ /  |", " | |  |", " L L"});
  pics["spear"] = ({"        ^", "(..)__ /", "r  7--/", " \\ / /", " | |", " L L"});
  pics["dual wield"] = ({"\\   (..)  /", " \\=r   7=/", "   `\\ / '", "    | |", "    L L"});
  pics["two handed sword"] = ({"         /", "        /", "(..)  _/_", "(  7==<", " \\ / '", " | |", " L L"});
  __RPictures["firbolg"] = pics;
  pics = ([]);
  pics ["bow"] = ({"   /|", "  / | (..)", "<(--==:__7", "  \\ |  \\ /", "   \\|  | |", "       / /"});
  pics["crossbow"] = ({"  /   (..)", "<(--==r__>", "  \\   \\ /", "   `  | |", "      / /"});
  pics["axe"] = ({"(>   (..)", "  \\--r  7", "      \\ /", "      | |", "      / /"});
  pics["sword"] = ({"\\   (..)", " \\--r  7", "     \\ /", "     | |", "     / /"});
  pics["dagger"] = ({" \\  (..)","  +-r   7","     \\ /","     | |","     / /"});
  pics["mace"] = ({"O","|  (..)", "|--r  7", "    \\ /", "    | |", "    / /"});
  pics["star"] = ({"*", "|  (..)", "|--r  7", "    \\ /", "    | |", "    / /"});
  pics["empty hand"] = ({"    (..)", "  --r   7", "     \\ /", "     | |", "     / /"});
  pics["staff"] = ({"|", "|__(..)", "|--r  7", "|  \\ /", "|  | |", "   / /"});
  pics["spear"] = ({"^", " \\ __(..)", "  \\--r  7", "   \\ \\ /", "     | |", "     / /"});
  pics["dual wield"] = ({"\\  (..)   /", " \\=r   7=/", "   `\\ / '", "    | |", "    / /"});
  pics["two handed sword"] = ({"\\", " \\", " _\\_  (..)", "   >==r   )", "    `  \\ /", "       | |", "       / /"});
  __LPictures["firbolg"] = pics;

//Minotaur pics
  pics = ([]);          
  pics ["bow"] = ({" /)/)", " \\~/|\\", "<( )--)>", " /m\\|/", " L L'"});
  pics["crossbow"] = ({" /)/)", " \\~/ \\", "<( )--)>", " /m\\ /", " L L"});
  pics["axe"] = ({"/)/)", "\\~/  <)", "( )-/", "/m\\", "L L"});
  pics["dagger"] = ({"/)/)", "\\~/", "( )-/", "/m\\", "L L"});
  pics["sword"] = ({"/)/)", "\\~/  /", "( )-/", "/m\\", "L L"});
  pics["mace"] = ({"/)/)", "\\~/  O", "( )-/", "/m\\", "L L"});
  pics["star"] = ({"/)/)", "\\~/  *", "( )-/", "/m\\", "L L"});
  pics["empty hand"] = ({"/)/)", "\\~/", "( )-", "/m\\", "L L"});
  pics["staff"] = ({"/)/) .", "\\~/  |", "( )=<|", "/m\\  |", "L L  '"});
  pics["spear"] = ({"/)/)  ^", "\\~/  /", "( )=/", "/m\\/", "L L"});
  pics["dual wield"] = ({"   /)/)", "\\  \\~/  /", " \\-( )-/", "   /m\\", "   L L"});
  pics["two handed sword"] = ({"/)/)  /", "\\~/  /", "( )=+", "/m\\'", "L L"});
  __RPictures["minotaur"] = pics;
  pics = ([]);
  pics ["bow"] = ({"   (\\(\\", "  /|\\~/", "<(--( )>", "  \\|/m\\", "   '/ /"});
  pics["crossbow"] = ({"   (\\(\\", "  / \\~/", "<(--( )>", "  \\ /m\\", "    / /"});
  pics["axe"] = ({"   (\\(\\", "(>  \\~/", "  \\-( )", "    /m\\", "    / /"});
  pics["sword"] = ({"  (\\(\\", "\\  \\~/", " \\-( )", "   /m\\", "   / /"});
  pics["dagger"] = ({" (\\(\\", "  \\~/", "\\-( )", "  /m\\", "  / /"});
  pics["mace"] = ({"  (\\(\\", "O  \\~/", " \\-( )", "   /m\\", "   / /"});
  pics["star"] = ({"  (\\(\\", "*  \\~/", " \\-( )", "   /m\\", "   / /"});
  pics["empty hand"] = ({"(\\(\\"," \\~/","-( )"," /m\\"," / /"});
  pics["staff"] = ({". (\\(\\","|  \\~/", "|>=( )", "|  /m\\", "'  / /"});
  pics["spear"] = ({"^  (\\(\\"," \\  \\~/","  \\=( )","   \\/m\\","    / /"});
  pics["dual wield"] = ({"  (\\(\\","\\  \\~/  /"," \\-( )-/","   /m\\","   / /"});
  pics["two handed sword"] = ({"\\  (\\(\\"," \\  \\~/","  +=( )","   '/m\\","    / /"});
  __LPictures["minotaur"] = pics;

//Dragon pictures
  pics = ([]);
  pics["empty hand"] = ({"     _______.", "     )       \\;`a__", ">-_  )______/ /-,w ~~", "    `( )_____)/", "    __>   __>"});
  __RPictures["dragon"] = pics;
  pics = ([]);
  pics["empty hand"] = ({"         ._______", "   __a';/       (", "~~ w.-\\ \\______(   _,-<", "       \\(_____( )'", "         <__    <__" });
  __LPictures["dragon"] = pics;


// wolf pictures
  pics = ([]);          
  pics["empty hand"] = ({"||    ^^.__","\\\\___/  r--^"," \\ ___ /"," //   \\\\"});
  __RPictures["wolf"] = pics;
  pics = ([]);
  pics["empty hand"] = ({" __.^^    ||","^--7  \\___//","    \\ ___ /","    //   \\\\"});
  __LPictures["wolf"] = pics;

// bird pictures
  pics = ([]);          
  pics["empty hand"] = ({"{>(__O>","  /__/", " "," ", " ", " "});
  __RPictures["bird"] = pics;
  pics = ([]);
  pics["empty hand"] = ({"<O__)<}"," \\__\\", " "," ", " ", " "});
  __LPictures["bird"] = pics;

// cat pictures
  pics = ([]);          
  pics["empty hand"] = ({" ))", "((__/;)"," (   )","  '' ``"});
  __RPictures["cat"] = pics;
  pics = ([]);
  pics["empty hand"] = ({"     ((","(;\\__))"," (   )"," '' ``"});
  __LPictures["cat"] = pics;

// big cat pictures

  pics = ([]);          
  pics["empty hand"] = ({"\\\\    , ,"," \\\\__(..)"," ( ___ )","  \\\\  ))"});
  __RPictures["big cat"] = pics;
  pics = ([]);
  pics["empty hand"] = ({" , ,   //","(..)__//"," ( ___ )"," ((  //"});
  __LPictures["big cat"] = pics;

// bear pictures

  pics = ([]);          
  pics["empty hand"] = ({"  ____","o/    \\__","( ___ __*<)","//.  \\\\."});
  __RPictures["bear"] = pics;
  pics = ([]);
  pics["empty hand"] = ({"     ____","  __/    \\o","(>*__ ___ )","   .//  .\\\\"});
  __LPictures["bear"] = pics;

// tree pictures
  pics = ([]);          
  pics["empty hand"] = ({" \\ ///","  |()|","==|  |==<","  \\  |","  // ||"," //  //"});
  __RPictures["tree"] = pics;
  pics = ([]);
  pics["empty hand"] = ({"  \\\\\\ //","   |()|",">==|  |==","   |  /","  || \\\\","  \\\\  \\\\"});
  __LPictures["tree"] = pics;

// rabbit pictures

  pics = ([]);          
  pics["empty hand"] = ({"  \"\"","0(..)","(  )"});
  __RPictures["rabbit"] = pics;
  pics = ([]);
  pics["empty hand"] = ({" \"\"","(..)o"," (  )"});
  __LPictures["rabbit"] = pics;

// rat pictures

  pics = ([]);          
  pics["empty hand"] = ({"   __","~~(__)>."});
  __RPictures["rat"] = pics;
  pics = ([]);
  pics["empty hand"] = ({"   __",".<(__)~~"});
  __LPictures["rat"] = pics;

//squirrel pictures

  pics = ([]);          
  pics["empty hand"] = ({"{ }( .>","{  } r"," {   )"});
  __RPictures["squirrel"] = pics;
  pics = ([]);
  pics["empty hand"] = ({"<. ){ }"," 7 {  }"," (   }"});
  __LPictures["squirrel"] = pics;

//ferret pictures

  pics = ([]);          
  pics["empty hand"] = ({"         __","        ( -;","________||","-(_r---7_|"
       });
  __RPictures["ferret"] = pics;
  pics = ([]);
  pics["empty hand"] = ({" __",":-7)","  ||________","  |_r---7_)-"});
  __LPictures["ferret"] = pics;

//raccoon pictures
  pics = ([]);          
  pics["empty hand"] = ({"        n","(\\/) _ //","(..)- \\/","( __ _/","// //"});
  __RPictures["raccoon"] = pics;
  pics = ([]);
  pics["empty hand"] = ({"n","\\\\ _ (\\/)"," \\/ -(..)","  \\_ __ )","    \\\\ \\\\"});
  __LPictures["raccoon"] = pics;

//monkey pictures
  pics = ([]);          
  pics["empty hand"] = ({"|    nn","\\ __(..)"," (  _ )","  / \\"});
  __RPictures["monkey"] = pics;
  pics = ([]);
  pics["empty hand"] = ({" nn   |","(..)__/"," (  _ )","  /3 \\3"});
  __LPictures["monkey"] = pics;

//mole pictures
  pics = ([]);          
  pics["empty hand"] = ({"--( )>."});
  __RPictures["mole"] = pics;
  pics = ([]);
  pics["empty hand"] = ({".<( )--"});
  __LPictures["mole"] = pics;

//horse pictures
  pics = ([]);          
  pics["empty hand"] = ({"      ^_","| ___//-;","'( __ )"," ))  ))"});
  __RPictures["horse"] = pics;
  pics = ([]);
  pics["empty hand"] = ({" _^",":-\\\\___ |","  ( __ )'","  ((  (("});
  __LPictures["horse"] = pics;


//Antelope pictures
  pics = ([]);          
  pics["empty hand"] = ({"     ^._","| ___||-;","'( __ )"," //  \\\\"});
  __RPictures["antelope"] = pics;
  pics = ([]);
  pics["empty hand"] = ({" _.^",":-||___ |","  ( __ )'","  //  \\\\"});
  __LPictures["antelope"] = pics;

//Moose pictures
  pics = ([]);          
  pics["empty hand"] = ({"     r^._",",    | r-;","| ---  |","'\\ __ /"," //  \\\\"," ''   ''"});
  __RPictures["moose"] = pics;
  pics = ([]);
  pics["empty hand"] = ({" _.^7",":-7 |    ,","  |  --- |","   \\ __ /'","   //  \\\\","   ''   ''"});
  __LPictures["moose"] = pics;

//camel pictures
  pics = ([]);          
  pics["empty hand"] = ({"   __    _","  /  \\  / \\._"," /    \\/  r--;","(  ____  /"," //    \\\\"," ''     ''"});
  __RPictures["camel"] = pics;
  pics = ([]);
  pics["empty hand"] = ({"    _    __"," _./ \\  /  \\",":--7  \\/    \\","   \\  _____  )","    //     \\\\","    ''      ''"});
  __LPictures["camel"] = pics;






//Halfling pics
  pics = ([]);          
  pics ["bow"] = ({"(..)|\\ "," LL |/"});
  pics["crossbow"] = ({"(..)_\\", " LL  /"});
  pics["axe"] = ({"(..)/<)", " LL'" });
  pics["dagger"] = ({"(..)/", " LL"});
  pics["sword"] = ({"      /", "(..)./.", " LL '"});
  pics["mace"] = ({"    o", "(..)|", " LL "});
  pics["star"] = ({"    *", "(..)|", " LL"});
  pics["empty hand"] = ({"(..)_", " LL"});
  pics["staff"] = ({"    |", "(..)|", " LL |"});
  pics["spear"] = ({"     /","(..)/"," LL/"});
  pics["dual wield"] = ({"\\(..)/","  LL"});
  pics["short sword"] = ({"(..)/", " LL'"});
  __RPictures["halfling"] = pics;
  pics = ([]);
  pics ["bow"] = ({"/|(..)", "\\| //"});
  pics["crossbow"] = ({"/_(..)", "\\  //"});
  pics["axe"] = ({"(>\\(..)", "   `//"});
  pics["sword"] = ({"\\",".\\.(..)", "  ` //"});
  pics["dagger"] = ({"\\(..)", "  //"});
  pics["mace"] = ({"o","|(..)", "  //"});
  pics["star"] = ({"*","|(..)", "  //"});
  pics["empty hand"] = ({"_(..)", "  //" });
  pics["staff"] = ({"|","|(..)", "| //"});
  pics["spear"] = ({"\\"," \\(..)","  \\//"  });
  pics["dual wield"] = ({"\\(..)/","  //"});
  pics["short sword"] = ({"\\(..)", " `//"});
  __LPictures["halfling"] = pics;


//Orc pics
  pics = ([]);          
  pics ["bow"] = ({"(..)|\\","<\\/=|-)>"," LL '/"});
  pics["crossbow"] = ({"(..)\\","<\\/=-)>"," LL /"});
  pics["axe"] = ({"(..) <)"," \\/-/"," LL" });
  pics["dagger"] = ({"(..) "," \\/-/"," LL"});
  pics["sword"] = ({"(..) /"," \\/-/"," LL"});
  pics["mace"] = ({"(..) O", " \\/-/"," LL"});
  pics["star"] = ({"(..) *"," \\/-/"," LL"});
  pics["empty hand"] = ({"(..)",  " \\/-"," LL"});
  pics["staff"] = ({"(..)|"," \\/-|"," LL '"});
  pics["spear"] = ({"      7","(..) /"," \\/-/"," LL/"});
  pics["dual wield"] = ({"\\ (..) /"," \\-\\/-/","   LL"});
  pics["two handed sword"] = ({"      /","(..) /"," \\/=+"," LL'"});
  __RPictures["orc"] = pics;
  pics = ([]);
  pics ["bow"] = ({"  /|(..)","<(-|=\\/>","  `' //"});
  pics["crossbow"] = ({"  /(..)","<(-=\\/>","  ` //"});
  pics["axe"] = ({"(> (..)","  \\-\\/","    //"});
  pics["sword"] = ({"\\ (..)"," \\-\\/","   //"});
  pics["dagger"] = ({" (..)",  "\\-\\/","  //"});
  pics["mace"] = ({"O (..)", " \\-\\/","   //"});
  pics["star"] = ({"* (..)"," \\-\\/","   //"});
  pics["empty hand"] = ({" (..)"," -\\/","  //"});
  pics["staff"] = ({"|(..)","|-\\/","' //"});
  pics["spear"] = ({"^     "," \\ (..)", "  \\-\\/","   \\//"});
  pics["dual wield"] = ({"\\ (..) /"," \\-\\/-/","   //"});
  pics["two handed sword"] = ({"\\     ",  " \\ (..)","  +=\\/","   `//"});
  __LPictures["orc"] = pics;


//Dwarf pics
  pics = ([]);          
  pics ["bow"] = ({" [..]|\\","<[__]=-)>"," '  ''/"});
  pics["crossbow"] = ({"[..] \\","[__]-->","'  ' /"});
  pics["axe"] = ({"[..]  <)","[__]-/","'  '"});
  pics["dagger"] = ({"[..]", "[__]-/",  "'  '"});
  pics["sword"] = ({"[..]  /","[__]-/","'  '"});
  pics["mace"] = ({"[..]  O","[__]-/","'  '"});
  pics["star"] = ({"[..]  *","[__]-/","'  '"});
  pics["empty hand"] = ({"[..]", "[__]-","'  '"});
  pics["staff"] = ({"     |","[..] |","[__]=|","'  ' '"});
  pics["spear"] = ({"       /","[..]  /","[__]=/","'  ''"});
  pics["dual wield"] = ({"\\  [..]  /"," \\-[__]-/","   '  '"});
  pics["two handed sword"] = ({"        /","       /","[..]  /","[__]=+-","'  ''"});
  __RPictures["dwarf"] = pics;
  pics = ([]);
  pics ["bow"] = ({"  /|[..]","<(-=[__]","  \\|'  '"});
  pics["crossbow"] = ({" / [..]","<--[__]"," \\ '  '"});
  pics["axe"] = ({"(>  [..]","  \\-[__]","    '  '"});
  pics["sword"] = ({"\\  [..]"," \\-[__]","   '  '"});
  pics["dagger"] = ({"   [..]"," \\-[__]","   '  '"});
  pics["mace"] = ({"O  [..]"," \\-[__]","   '  '"});
  pics["star"] = ({"*  [..]"," \\-[__]","   '  '"});
  pics["empty hand"] = ({" [..]","-[__]"," '  '"});
  pics["staff"] = ({" |",  " | [..]"," |-[__]"," ` '  '"});
  pics["spear"] = ({"\\", " \\  [..]","  \\=[__]","   `'  '"});
  pics["dual wield"] = ({"\\  [..]  /"," \\-[__]-/","   '  '"});
  pics["two handed sword"] = ({"\\"," \\","  \\  [..]","  -+-[__]","    `'  '"});
  __LPictures["dwarf"] = pics;

//Wemic pics
  pics = ([]);          
  pics ["bow"] = ({"*   {..}|\\", " \\__<|)-|-)>"," { __ } |/"," //  \\\\"});
  pics["crossbow"] = ({"*   {..}\\"," \\__<|)--)>"," { __ } /"," //  \\\\"});
  pics["axe"] = ({"*   {..} <)"," \\___|)-/"," { __ }"," //  \\\\"});
  pics["dagger"] = ({"*   {..}"," \\___|)-/"," { __ }"," //  \\\\"});
  pics["sword"] = ({"*    {..} /"," \\ ___|)-/","  { __ }","  //  \\\\"});
  pics["mace"] = ({"*   {..} 0"," \\___|)-/"," { __ }"," //  \\\\"});
  pics["star"] = ({"*    {..} *"," \\ ___|)-/","  { __ }","  //  \\\\"});
  pics["empty hand"] = ({"*   {..}"," \\___|)-"," { __ }"," //  \\\\"});
  pics["staff"] = ({"*   {..}|"," \\___|)=|"," { __ } |"," //  \\\\ '"});
  pics["spear"] = ({"          7","*   {..} /"," \\___|)=/"," { __ }/"," //  \\\\"});
  pics["dual wield"] = ({"* \\ {..} /"," \\_\\-|)-/"," { __ }"," //  \\\\"});
  pics["two handed sword"] = ({"           /","*    {..} /"," \\ ___|)=+","  { __ }^","  //  \\\\"});
  __RPictures["wemic"] = pics;
  pics = ([]);
  pics ["bow"] = ({"  /|{..}   *","<(-|-(|>__/","  \\| { __ }","     //  \\\\"});
  pics["crossbow"] = ({"  /{..}   *","<(--(|>__/","  \\ ( __ )","    //  \\\\"});
  pics["axe"] = ({"(> {..}   *","  \\-(|___/","    { __ }","    //  \\\\"});
  pics["sword"] = ({"\\ {..}   *"," \\-(|___/","   { __ }","   //  \\\\"});
  pics["dagger"] = ({" {..}   *","\\-(|___/","  { __ }","  //  \\\\"});
  pics["mace"] = ({"0 {..}   *"," \\-(|___/","   { __ }","   //  \\\\"});
  pics["star"] = ({"* {..}   *"," \\-(|___/","   { __ }","   //  \\\\"});
  pics["empty hand"] = ({"{..}   *","-(|___/"," { __ }"," //  \\\\"});
  pics["staff"] = ({"|{..}   *","|=(|___/","| { __ }","' //  \\\\"});
  pics["spear"] = ({"^"," \\ {..}   *","  \\=(|___/","   \\{ __ }","    //  \\\\"});
  pics["dual wield"] = ({"\\ {..} / *"," \\-(|-/_/","   { __ }","   //  \\\\"});
  pics["two handed sword"] = ({"\\"," \\ {..}   *","  +=(|___/","   ^{ __ }","    //  \\\\"});
  __LPictures["wemic"] = pics;


//Kobold pics
  pics = ([]);          
  pics ["bow"] = ({"  , ,"," (..)|\\ ","~~LL |/"});
  pics["crossbow"] = ({"   , ,","~~(..)_\\","   LL  /"});
  pics["axe"] = ({"  , ,"," (..)/<)","~~LL'" });
  pics["dagger"] = ({"  , ,"," (..)/","~~LL"});
  pics["sword"] = ({"  , ,  /"," (..)./.","~~LL '"});
  pics["mace"] = ({"  , ,o", " (..)|","~~LL "});
  pics["star"] = ({"  , ,*"," (..)|","~~LL"});
  pics["empty hand"] = ({"  , ,"," (..)_","~~LL"});
  pics["staff"] = ({"  , ,|"," (..)|","~~LL |"});
  pics["spear"] = ({"  , , /"," (..)/","~~LL/"});
  pics["dual wield"] = ({"  , ,","\\(..)/","~~LL"});
  __RPictures["kobold"] = pics;
  pics = ([]);
  pics ["bow"] = ({"   , ,","/|(..)~~", "\\| //"});
  pics["crossbow"] = ({"   , ,","/_(..)~~","\\  //"});
  pics["axe"] = ({"    , ,","(>\\(..)~~","   `//"});
  pics["sword"] = ({"\\   , ,",".\\.(..)~~","  ` //"});
  pics["dagger"] = ({"  , ,","\\(..)~~","  //"});
  pics["mace"] = ({"o , ,","|(..)~~","  //"});
  pics["star"] = ({"* , ,","|(..)~~","  //"});
  pics["empty hand"] = ({"  , ,","_(..)~~","  //"});
  pics["staff"] = ({"| , ,","|(..)~~","| //"});
  pics["spear"] = ({"\\  , ,"," \\(..)~~","  \\//"});
  pics["dual wield"] = ({"  , ,","\\(..)/~","  //"});
  __LPictures["kobold"] = pics;

// unfettered pictures
  pics = ([]);
  pics["empty hand"] = ({ 
"      _____",
"___  /     \\  __",
"  \\\\/ <@>   \\//",
"   {__       }~~",
"    VV\\      }==",
"   -^^-     /\\\\_",
"___//--___//" });
  __LPictures["outsider"] = pics;
  pics = ([]);
  pics["empty hand"] = ({ 
"      _____",
"___  /     \\  __",
"  \\\\/   <@> \\//",
" ~~{       __}~~",
" =={      /VV",
"__//\\     -^^-",
"    \\\\__--\\\\__" 
});
  __RPictures["outsider"] = pics;
}

string get_weapon(object ob){
  object * wielded, wpn;
  string weapon, race;
  wielded = ob->query_wielded();
  tell_room(TO, "number of weapons:" + sizeof(wielded));
  weapon = "empty hand";
  if (sizeof(wielded)<1){
    weapon = "empty hand";
  } else {
    wpn = wielded[0];
    if (sizeof(wielded)>1 && wielded [0] != wielded[1]){
      weapon = "dual wield";
    } else {
      if (wpn->id("bow")||wpn->id("shortbow")||wpn->id("longbow")){
        weapon = "bow";
      }
      if (wpn->id("crossbow")){
        weapon = "crossbow";
      }
      if (wpn->id("axe")||wpn->id("handaxe")||wpn->id("battleaxe")){
        weapon = "axe";
      }
      if (wpn->id("dagger")||wpn->id("knife")){
        weapon = "dagger";
      }
      if (wpn->id("mace")||wpn->id("hammer")){
        weapon = "mace";
      }
      if (wpn->id("star")){
        weapon =  "star";
      }
      if (wpn->id("staff")){
        weapon = "staff";
      }
      if (wpn->id("spear")){
        weapon = "spear";
      }
      if (wpn->id("sword")){
        weapon = "sword";
      }
      if (wpn->id("two handed sword")){
        weapon = "two handed sword";
      }
      if (wpn->id("shortsword")||wpn->id("short sword")){
        race = ob->query_race();
        if (race == "halfling" || race == "gnome"){
          weapon = "short sword";
        }
      }
    }
  }
  return weapon;
}

mapping get_left_pics(string race){
  return __LPictures[race];  
}

mapping get_right_pics(string race){
  return __RPictures[race];  
}

string * get_picture(object ob, object looker){
  string nm, race, * pic;
  int i;
  if (!objectp(ob)){
    return ({});
  }
  race = ob->query_race();
  nm = race;
  if (objectp(looker)){
    if (looker->isKnown(ob->query_name())){
      nm = looker->knownAs(ob->query_name());
    }
  }
  pic = get_untitled_pic(ob);
  return ({nm}) + pic;
}

string * get_untitled_pic(object ob){
  object * wielded, wpn;
  string  * pic, race, weapon, * allowed_weapons;
  int face;
  mapping pics;
  if (!objectp (ob)){
    return({});
  }
  race = ob->query_race();
  face = query_face(ob);
  weapon = get_weapon(ob);
  switch (race){
  case "wolf":
    break;
  case "bird":
    break;
  case "cat":
    break;
  case "tiger":
  case "leopard":
  case "panther":
  case "lion":
  case "lynx":
  case "cheetah":
  case "jaguar":
  case "ocelot":
    race = "big cat";
    break;
  case "bear":
    break;
  case "dragon":
    break;
  case "rabbit":
    break;
  case "rat":
    break;
  case "squirrel":
    break;
  case "ferret":
  case "mongoose":
    race = "ferret";
    break;
  case "raccoon":
    break;
  case "monkey":
    break;
  case "mole":
    break;
  case "horse":
    break;
  case "antelope":
  case "deer":
    race = "antelope";
    break;
  case "moose":
    break;
  case "camel":
    break;
  case "halfling":
  case "gnome":
    race = "halfling";
    break;
  case "wemic": 
    race = "wemic";
    break;
  case "centaur":
    race = "centaur";
    break;
  case "minotaur":
    race = "minotaur";
    break;
  case "dwarf":
    race = "dwarf";
    break;
  case "firbolg":
    race = "firbolg";
    break;
  case "orc":
    race = "orc";
    break;
  case "ogre":
  case "ogre-mage":
    race = "ogre";
    break;
  case "kobold":
    race = "kobold";
    break;
  case "elf":
    race = "elf";
    break;
  case "tree":
    race = "tree";
    break;
  case "outsider":
    if (ob->id("unfettered")){
      race = "outsider";
      break;
    }
  default:
    race = "human";
  }
  switch(face){
  case WEST:
    pics = __LPictures[race];
    allowed_weapons = keys(pics);
    if (member_array(weapon, allowed_weapons)==-1){
      weapon = "empty hand";
    }
    pic = pics[weapon];
    break;
  case EAST:
    pics = __RPictures[race];
    allowed_weapons = keys(pics);
    if (member_array(weapon, allowed_weapons)==-1){
      weapon = "empty hand";
    }
    pic = pics[weapon];
    break;
  }
  return pic;
}
