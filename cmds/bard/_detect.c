#include <move.h>
#include <std.h>
inherit DAEMON;
int filter_living(object *inven);
int cmd_detect(string str){
  string where, *exits,dest_name, listen;
  object dest, *inven;
  int score, percent, living;

  inven = ({});
  if(!str){
    notify_fail("Detect noise where\n");
    return 0;
  }
  if(sscanf(str, "noise %s",where)!= 1){
    notify_fail("Care to try again.\n");
    return 0;
  }
  exits = environment(TP)->query_exits();
  if(member_array(where, exits) == -1){
    notify_fail("You can't detect noise without an exit.\n");
    return 0;
  }                                                                       
  dest_name = environment(TP)->query_exit(where);
  if(!TP->is_class("thief") && !TP->is_class("bard")){
    notify_fail("You can't do that!!\n");
    return 0;
  }
  if(!TP->query_invis())
    tell_room(environment(TP),"You see "+TPQCN+" attempt to detect noise toward the "+where+".",TP);
  score = TP->query_thief_skill("detect noise");
  if(TP->query_armour("torso"))
    score -= 10;
  percent = random(99);
  if(score <= percent){
    notify_fail("You hear nothing!!\n");
    return 0;
  }
  dest = find_object_or_load(dest_name);
  listen = dest->query_listen("default");
  inven = all_inventory(dest);
  living = filter_living(inven);
    if((living == 0) && ((listen == " ") || (!listen))){
      write("You hear nothing!!");
    }
  if((listen)&&(listen!=" "))
    write("You hear: "+listen);
  if(living == 1){
    write("You hear the movements of something in the next room.");
  }
  return 1;
}

int filter_living(object *inven){
  int i,ret;

  if(!inven) return 0;
  for(i=0;i<sizeof(inven);i++){
    ret = living(inven[i]);
    if(ret == 1) return 1;
  }
  return 0;
}
