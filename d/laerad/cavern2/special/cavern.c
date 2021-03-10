// Room inheritable for Laerad
// High Mortal area
// Coded by Bane
#include <std.h>
inherit ROOM;
int flag;
void create(){
    ::create();
   set_terrain(NAT_TUNNEL);
   set_travel(FOOT_PATH);
    set_property("no teleport",1);
    set_property("continue heartbeat",1);
    set_heart_beat(1);
}

void init(){
    string *exits;
    int i;
    ::init();
    exits = TO->query_exits();
    for(i=0;i<sizeof(exits);i++)
      add_action("leaving",exits[i]);
}

void leaving(){
    if(random(20) < 3){
      if(flag) return 0;
      if(!interactive(TP)) return 0;
      write("A magical force seems to hold your feet in place.");
      return 1;
    }
    return 0;
}

void heart_beat(){
    object *things, moving, *inven;
    string *exits,*ids;
    int i, j, a, b;
    ::heart_beat();
    exits = TO->query_exits();
    i = sizeof(exits);
    j = random(i);
    things = all_living(TO);
    if(!sizeof(things)) return 1;
    moving = things[random(sizeof(things))];
    inven = all_inventory(moving);
    b = random(sizeof(inven));

    if(random(100) < 2){
      if(interactive(moving)){
        if(moving->query_paralyzed()) return 1;
        if(!wizardp(moving)){
          flag = 1;
          tell_object(moving,"A magical force shoves you "+exits[j]+"!");
          moving->force_me(exits[j]);
          flag = 0;
        }
      }
    }

    if(random(100) < 2){
     return; //DISABLING this function due to complaints, 4 Dec 19, Uriel
      if(interactive(moving)){
        if(!wizardp(moving)){
          for(a=0;a<1;a++){
            tell_object(moving,"A magical force tries making you drop "+inven[b]->query_name()+"!");
            if(inven[b]) { ids = inven[b]->query_id(); }
            moving->force_me("drop "+ids[0]);// added to fix problem with dropping items who's name wasn't one of their ids -Ares
          }
        }
      }
    }

    if(random(100) < 2){
      tell_object(moving,"You feel a tingling sensation.");
      moving->do_damage(moving->return_target_limb(),-2);
    }
}
