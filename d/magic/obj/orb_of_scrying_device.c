//eye_orb.c, based off of shadowlistener.c

#include <std.h>

inherit MONSTER;

object caster, follower;
void self_destruct();
void set_scry_power(int x);
void query_scry_power();
void query_mycaster();

int power;

void create()
{
   ::create();

    set_name("orb_of_scrying_device");
    set_property("no detect",1);
    set_id(({"orb_of_scrying_device_xxx"}));
    set_short(0);
    set_invis();
    add_limb("body","",0,0,0);
}

int move(mixed dest)
{
    ::move(dest);
    if(!objectp(TO)) { return 1; }
    if(!objectp(ETO)) { return 1; }
    if(!objectp(caster)) { return 1; }
   
    if(environment(TO) == environment(follower))
    {
        tell_room(environment(caster),"%^BOLD%^[S]%^RESET%^" +ETO->query_long()+"");
    }
}

set_caster(object cas){
   caster = cas;
}

void query_mycaster(){
   return caster;
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
   if(ETO->query_property("no scry")) self_destruct();
   if(follower->query_true_invis()) self_destruct();
   if(present("blockerx111", ETO)) self_destruct();
}

dest_me(){
//   tell_room(ETO,"%^BLACK%^%^BOLD%^A shadow off to one side shimmers and disappears.",TO);
//Removing this since the spells are now detectable through normal
//scrying detections ~Circe~ 5/27/08
   remove();
}

catch_tell(string str){
   if(!objectp(caster)){
      dest_me();
      return;
   }

   tell_room(environment(caster),"%^BOLD%^[S]%^RESET%^" +str);

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

void set_scry_power(int x){
   power = x;
}

void query_scry_power(){
   return power;
}

void self_destruct() 
{
    int i;
    object casterobj;
    casterobj = find_player(caster);

    if(objectp(casterobj))
    {
        tell_room(environment(casterobj),"%^CYAN%^Mist fills up the center of the orb and clouds "
            "your vision of the images within.%^RESET%^");
    }

    if(objectp(TO)) dest_me();
    return;
}

int is_priest_scry(){ return 1; }