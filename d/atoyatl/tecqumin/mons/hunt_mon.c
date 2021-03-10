#include <std.h>
inherit WEAPONLESS;

string * path, * quarry;
object scanner;

void chase();

void create(){
  ::create();
      set_property("not random monster", 1);
d
  path = ({});
  quarry = ({});
  scanner = new("/realms/lujke/tecqumin/obj/far_scanner3");
  scanner->move(TO);
}

void heart_beat(){
  ::heart_beat();
  if(!objectp(TO) || !objectp(ETO)) return;
  if(query_hp()< 500 && present("vial",TO)){
    force_me("open vial");
    force_me("quaff vial");
    force_me("offer bottle");
    force_me("quaff vial");
    force_me("offer bottle");
    force_me("quaff vial");
    force_me("offer bottle");
    force_me("quaff vial");
    force_me("offer bottle");
    force_me("quaff vial");
    force_me("offer bottle");
    force_me("quaff vial");
    force_me("offer bottle");
    force_me("quaff vial");
    force_me("offer bottle");
    force_me("quaff vial"); 
    force_me("offer bottle");
    force_me("quaff vial");    
    force_me("offer bottle");
    force_me("quaff vial");
    force_me("offer bottle");
  }
  chase();
}

void set_prey(string prey){
  quarry +=({prey});
}

void chase(){
  string * newpath,* finalpath, step;
  object * rooms,  prey, player;
  int pathsize, i, depth, flag;
  if(!objectp(TO) || !objectp(ETO)) return;
  newpath = ({});
  finalpath = ({});
  rooms = ({});
  path = ({});
  if (sizeof(quarry)>0){
    for(i=0;i<sizeof(quarry);i++){
      player = find_player(quarry[i]);
      if (objectp(player)){
        prey = present(player, ETO);
      } else {
        if (!objectp(prey)){
          prey = present(quarry[i], ETO);
        }
      }
      if (objectp(prey)){
        return;
      }
      if (objectp(player)){
        prey = player;
      } else {
        prey = scanner->far_present(ETO, quarry[i], 4);
      }
      if (objectp(prey) && objectp(environment(prey))){
         newpath = scanner->findpath(ETO, environment(prey), newpath,
                                                 finalpath, rooms, 4, 1);
         if (sizeof(path)<1||(sizeof(newpath)<sizeof(path)
                                           &&sizeof(newpath)>0)){
           path = newpath;
         }
      }
    }
  }else{ 
    path = ({});
  }
  if (path != ({})){
    step = path[0];
    force_me(step);
  }
}

string * query_quarry(){
  return quarry;
}

object present(string what, object room){
  object * inv;
  int i, count;
  inv = all_inventory(room);
  count = sizeof(inv);
  for (i=0;i<count;i++){
    if (inv[i]->id(what)){
      return inv[i];
    }
  }
  return 0;
}

void catch_tell(string str)
{
  string door_name;
  if (interact("You bump into the closed", str)){
    sscanf(str, "You bump into the closed %s.", door_name);
    force_me("open " + door_name);
  }
}
