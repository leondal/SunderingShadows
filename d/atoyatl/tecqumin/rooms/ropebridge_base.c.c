#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit ROOM;

mapping __PosDir;
mapping __Colours;
mapping __RPictures;
mapping __LPictures;

int demon_pos, demon_dir;

void enter_east(object ob);
void enter_west(object ob);
void show(string * what);
string * get_picture(object ob, int dir, object looker);
void show_bridge(object looker);
void setup_Colours();
string crit_colour(int i);
void setup_Pictures();

void create() {
  ::create();
  set_exits(([
      "east" : JUNGLE + ""
   ]));
}


void init(){
  ::init();
  add_action("head_east", "east");
  add_action("head_west", "west");
  add_action("check_bridge", "check");
}

int head_west(string str){
  object * critters;
  int pos, dir, face, i;
  pos = "/d/atoyatl/bridge_monitor_d.c"->query_pos(TP);
  dir = "/d/atoyatl/bridge_monitor_d.c"->query_dir(TP);
  face = "/d/atoyatl/bridge_monitor_d.c"->query_face(TP);
  critters = all_living(TO);
  if (sizeof(critters)<1){
    return 0;
  }
  for (i = 0;i<sizeof(critters);i++){
    critters[i]->force_me("emote is doing: '" + (string)critters[i]->query_verb() + "'");
  }
  tell_room(TO, "Previous object is: " + file_name(PO));
  tell_room(TO, "Verb is: " + query_verb());
  if (pos < 2){
    
  }
  if (dir ==0){

  }
  return 1; 
}

int head_east(string str){
  return 1;
}


int check_bridge(string str){
  if (str != "bridge" && str !="rope bridge" && str != "ropebridge"
         && str != "progress" && str != "progress across bridge"){
    return notify_fail("Try <check progress>");
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

void set_dir(object ob, int dir){
  "/d/atoyatl/bridge_monitor_d.c"->set_demon_dir(ob, dir);
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


