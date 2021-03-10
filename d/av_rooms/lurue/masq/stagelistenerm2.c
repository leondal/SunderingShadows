//stagelistener
#include <std.h>
inherit MONSTER;

//#define ETC "/d/attaya/newseneca/rooms/mage_combat.c"
object caster, follower;
int look_room(object dest);

void create(){
   ::create();
   set_name("stagelistener");
   set_property("no detect",1);
   set_id(({"StageListenerM2"}));
   set_short(0);
   set_invis();
   add_limb("body","",0,0,0);
}

int move(mixed dest) { ::move(dest); }

set_caster(object cas){ caster = cas; }

set_target(object ob){ follower = ob; }

void die(object ob){}

void heart_beat(){
   if(!objectp(caster)) return;
   if(!objectp(follower)) return;
   if(ETO != environment(follower))
     move(environment(follower));
}

dest_me(){ remove(); }

catch_tell(string str){ tell_room(caster,"%^BOLD%^%^CYAN%^[Stage] %^RESET%^"+str); }

int do_damage(string str, int i){ return 0; }

int is_invincible(){ return 1;}
int is_detectable(){ return 0;}

int id(string str){
    if(objectp(TP) && !avatarp(TP)) return 0;
    else return ::id(str);
}

object query_caster() { return caster; }

void set_invis() {
  if (TO->query_invis()) return;
  else ::set_invis();
  return;
}
