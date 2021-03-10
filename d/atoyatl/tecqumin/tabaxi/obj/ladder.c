//Coded by Lujke


#include <std.h>
#include "../../tecqumin.h"
inherit OBJECT;
mapping climb_positions;
string raised_loc;

void create() {
    ::create();
    set_name("seige ladder");
    set_id( ({"ladder","seige ladder" }) );
    set_short("%^RESET%^%^ORANGE%^large seige ladder%^RESET%^");
    set_weight(30);
    set_long( (:TO, "long_desc":) );
    climb_positions = ([]);
}

void init(){
  ::init();
  set_long( (:TO, "long_desc":) );
  if (stringp(raised_loc) && file_name(ETO) != raised_loc){
    raised_loc = "";
  }
  add_action("raise_ladder", "raise");
}

mapping query_climb_positions(){
  return climb_positions;
}

int query_climb_position(object climber){
  return climb_positions[climber];
}

void set_climb_position(object climber, int pos){
  climb_positions[climber]= pos;
}
void remove_climber(object climber){
  map_delete(climb_positions, climber);
}

string query_raised_loc(){
  return raised_loc;
}

void set_raised_loc(string rl){
  raised_loc = rl;
}

int raise_ladder(string str){
  object * rooms, room, *critters;
  string filename;
  int pos, i, j;
  if (stringp(raised_loc) && raised_loc == file_name(ETO)){
    notify_fail("The ladder is already raised against the fence");
    if (TP->id("orog")){
      TP->force_me("climb ladder");
      TP->set_entry_method("scaled a seige ladder to get over the fence and onto the battlements");
    }
    return 0;
  }
  if (!objectp(ETO)){
    return 0;
  }
  if (living(ETO)){
    if (!objectp(EETO)){
      return 0;
    }
    room = EETO;
  } else {
    room = ETO;
  }
  filename = file_name(room);
  if (!interact(TABAXROOM + "main_field", filename) 
      && !interact(TABAXROOM + "low_field", filename)
      && !interact(TABAXROOM + "high_field", filename)){
    return 0; 
  }
  pos = room->query_position(TP);
  if (pos < 10 || !id(str)){
    tell_object(TP, "You could raise a ladder here, if you were close enough to the fence. Try to <approach fence>");
    if (TP->id("orog")){
      TP->force_me("approach fence");
    }
    return 1;
  }
  rooms =  ({find_object_or_load(TABAXROOM + "watchtower1"), (object)room->query_battlement() });
  if (sizeof(rooms)>0){
    for (i=0;i<sizeof(rooms);i++){
      if (objectp(rooms[i])){
        tell_room(rooms[i], "%^BOLD%^%^RED%^"+ TPQCN + " %^BOLD%^%^RED%^raises a"
                           +" %^RESET%^%^ORANGE%^seige ladder %^BOLD%^%^RED%^against the stockade"
                           +" fence, at the " + room->query_name());
        critters = all_living(rooms[i]);
        if (sizeof(critters)>0){
          for (j=0;j<sizeof(critters);j++){
            if ((int)critters[j]->id("tabaxi")==1){
              critters[j]->call_out("fend_off", 2+random(3));
            }
          }
        }
      }
    }
  }
  raised_loc = file_name(room); 
  if (room != ETO){
    TO->move(room);
  }
  tell_room(room, "%^BOLD%^%^RED%^"+ TPQCN + " %^BOLD%^%^RED%^raises a %^RESET%^%^ORANGE%^seige ladder"
                 +" %^BOLD%^%^RED%^against the stockade fence.", TP);
  if (TP->id("orog")){
    TP->call_out("force_me", 2, "climb ladder");
    TP->call_out("set_entry_method", 3, "scaled a seige ladder to get over the fence and onto the"
                +" battlements");
    return 1;
  }
  tell_object(TP, "You raise the seige ladder against the stockade fence");
  return 1;
}



string long_desc(){
  string desc, filename;
  int pits;
  object room;
  desc = "%^ORANGE%^A large seige ladder, about 30 feet in length. It is built from solid jungle"
        +" hardwood, and has a hooking device at the top to attach to the top of a wall or other"
        +" structure.%^RESET%^";
  room = EETO;
  if (!objectp(room)){
    room= ETO;
  }
  if (objectp(room)){
    filename = file_name(room);
    if(TABAXROOM + "main_field" == filename[0..strlen(TABAXROOM + "main_field")-1]
         ||TABAXROOM + "high_field" == filename[0..strlen(TABAXROOM + "high_field")-1]
         ||TABAXROOM + "low_field" == filename[0..strlen(TABAXROOM + "low_field")-1]){
      if (!stringp(raised_loc) || raised_loc != file_name(room)){
        desc += "%^ORANGE%^ You could probably %^BOLD%^%^YELLOW%^<raise>%^RESET%^%^ORANGE%^ the ladder"
            +" against the wall, if you were close enough to it.";
        raised_loc = "";
      } else{
        desc += " %^ORANGE%^The ladder has been raised against the stockade wall. You could probably"
               +" %^BOLD%^%^YELLOW%^<climb ladder> %^RESET%^%^ORANGE%^if you wanted.";
      }
    }
  }
  return desc;
}
