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

    set_name("EyeOrb");
    set_property("no detect", 1);
    set_id(({ "EyeOrb", "scryx222" }));
    set_short(0);
    set_invis();
    add_limb("body", "", 0, 0, 0);
}

int query_true_invis() { return 1; }

int move(mixed dest)
{
    ::move(dest);
    if (!objectp(TO)) {
        return 1;
    }
    if (!objectp(ETO)) {
        return 1;
    }
    if (!objectp(caster)) {
        return 1;
    }

    heart_beat();

    if (environment(TO) == environment(follower)) {
        tell_room(environment(caster), "%^BOLD%^[S]%^RESET%^" + ETO->query_long() + "");
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

void heart_beat()
{
    if (!objectp(caster)) {
        return;
    }
    if (!objectp(follower)) {
        return;
    }
    if (ETO != environment(follower)) {
        move(environment(follower));
    }
    if (ETO->query_property("no scry")) {
        self_destruct();
    }
    if (follower->query_true_invis()) {
        self_destruct();
    }
    if (present("blockerx111", ETO)) {
        self_destruct();
    }
}

void dest_me(){
//   tell_room(ETO,"%^BLACK%^%^BOLD%^A shadow off to one side shimmers and disappears.",TO);
//Removing this since the spells are now detectable through normal
//scrying detections ~Circe~ 5/27/08
   remove();
}


void receive_message(string cl, string str)
//void catch_tell(string str)
{
    object *scry_objects=({}),*people=({}),*temp=({}),room;
    int i;

    if(objectp(PO))
    {
        if(PO->id("scryx222")) { return; }
    }

    if(!objectp(caster))
    {
        dest_me();
        return;
    }

    room = environment(caster);

    if(!objectp(room)) { return; }

    people = all_living(room);

    if(sizeof(people))
    {
        for(i=0;i<sizeof(people);i++)
        {
            if(people[i]->id("scryx222")) { scry_objects += ({ people[i] }); }
            else { temp += ({ people[i] }); }
        }
    }

    scry_objects += ({ TO });

    //tell_room(room,"scry_objects: "+identify(scry_objects)+"");
    //tell_room(room,"people: "+identify(people)+"");

    message(cl,"%^BOLD%^[S]%^RESET%^" +str, temp,scry_objects);

    //tell_room(environment(caster),"%^BOLD%^[S]%^RESET%^" +str);

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
        tell_room(environment(casterobj),"%^ORANGE%^The %^RED%^glowing red eye %^ORANGE%^within "
            "the misty orb closes suddenly, once again becoming just a %^RED%^hazy "
            "red light!%^RESET%^");
    }

    if(objectp(TO)) dest_me();
    return;
}

int is_priest_scry(){ return 1; }

//Adding this so that Detect Scrying, etc. work correctly with this spell
//~Circe~ 8/17/13
int is_scry_object(){ return 1; }
