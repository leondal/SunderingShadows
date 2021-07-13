// Chernobog (3/6/21)
// Shadow Coliseum
// Circe's code from Seneca, adapted for the dungeon
// by Tsera and then stolen by Chernobog

#include <std.h>

inherit MONSTER;

#define ETC "/d/shadow/coliseum/room/stands3.c"

object caster, follower, myETC;

int look_room(object dest);

void create(){
   ::create();
   set_name("arena_listenerC");
   set_property("no detect",1);
   set_id(({"arena_listenerC"}));
   set_short(0);
   set_invis();

   add_limb("body","",0,0,0);
}

int move(mixed dest){
   ::move(dest);
}

set_caster(object cas){
   caster = cas;
}

set_target(object ob){
   follower = ob;
}

void die(object ob){
}

void heart_beat(){
   if(!objectp(caster)) return;
   if(!objectp(follower)) return;
   if(ETO != environment(follower))
      move(environment(follower));
}
dest_me(){
   remove();
}

catch_tell(string str){
   object *livings;
   int i,j;
   if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
   myETC = find_object_or_load("/d/shadow/coliseum/room/stands3.c");
   if(!objectp(myETC)) return;
   livings = ({});
   livings =all_living(myETC);
   j = sizeof(livings);
   for(i=0;i<j;i++){
   if(!interactive(livings[i])) { continue; }
   tell_object(livings[i],"[D] "+str,caster);
   }
}
int do_damage(string str, int i){
    return 0;
}

int is_invincible(){ return 1;}
int is_detectable(){ return 0;}

int id(string str){
    if(objectp(TP) && !avatarp(TP)) return 0;
    else return ::id(str);
}

object query_caster() { return caster; }

void set_invis() {
  if (TO->query_invis())
    return;
  else ::set_invis();
  return;
}

