//holder.c

#include <std.h>

inherit OBJECT;

object caster, sword, *foes;
int freed, count;

void save_me(string file){return 1;}

void create(){
    ::create();
    set_name("device");
    set("id", ({ "devicex999" }) );
    set("short", "");
    set("long", "");
    set_weight(0);
}

int move(mixed dest){
   if(ETO && objectp(ETO))
      if(interactive(ETO))
         return 0;
   ::move(dest);
   set_heart_beat(1);
}

set_caster(object ob){
   if(objectp(ob)){
      caster = ob;
   }
   else
      remove();
}

object query_sword(){return sword;}

object query_caster(){return caster;}

void set_sword(object ob){
   sword = ob;
}

void defend(){
   int num,numfoes,i,j;
   object *tmp;

   tmp = ({});
   numfoes=sizeof(tmp = caster->query_attackers());
   for(num =0;num < numfoes;num++){
      if(!objectp(tmp[num])) continue;
      if(member_array(tmp[num], (object *)sword->query_attackers()) != -1)
         continue;
      if(!objectp(sword))
	 continue;
      sword->kill_ob(tmp[num],1);
      tell_room(ENV(sword),"%^BOLD%^%^RED%^The sword attacks "+tmp[num]->query_cap_name()+"!");
   }
   return;
}

void heart_beat(){
   object *tmp;
   int i,j;

   tmp = ({});
   if(!objectp(caster))
      remove();
   if(!objectp(sword))
       remove();

   if(objectp(caster))
    {
        if((object *)caster->query_attackers() != ({}))
        {
            defend();
        }
    }
}

void remove()
{
    if(!objectp(TO)) { return; }
   if(objectp(TO->query_property("spell")))
      TO->query_property("spell")->dest_effect();
   if(objectp(TO))
      return ::remove();
}

void init(){
   ::init();
   add_action("cmd","command");
   add_action("dismiss","dismiss");
}

int cmd(string str){
   object ob;
   string what, who, what2, holder;
   int i,j;

   if(!str) return notify_fail("Care to tell it what to do?\n");
   if(sscanf(str, "%s to %s", who, what) != 2)
      return notify_fail("Syntax: command sword to <jump up and down>\n");
   if(who != "sword")
      return 0;
   if(what[0..3] == "kill") {
      if(sscanf(what, "kill %s",who) == 1){
         if(ob = present(who,environment(caster))){
            if(objectp(ob)){
               if(!caster->ok_to_kill(ob)){
                  tell_object(caster,"You are not allowed to kill that creature!");
                  return 1;
               }
            }
         }
      }
   }
   if(what == "follow") {
      if(present(sword,environment(caster))){
         tell_object(caster,"Broad sword is now following you.");
         caster->add_follower(sword);
         return 1;
      }else{
         tell_object(caster,"The sword must be present before it can follow you!");
         return 1;
      }
   }
      if(!caster->query_property("safe arena") || !ob->query_property("safe arena"))
      "/daemon/killing_d"->check_actions(caster,ob);
   if(!sword->force_me(what))
      return notify_fail("You fail to command the sword to "+what+"!\n");
   tell_object(caster,"Broad sword obeys your command to "+what+".");
//   sword->force_me(what);
   if(!objectp(sword)) return 1;
   return 1;
}

int dismiss(string str){
   if(!str || str != "sword")
      return 0;
   tell_room(environment(caster),"%^BOLD%^"+caster->query_cap_name()+" dismisses the sword!",caster);
   tell_object(caster,"%^BOLD%^You dismiss the sword!\n");
   if (objectp(sword)) sword->remove();
   call_out("timed",1);
   return 1;
}

int timed(){
   remove();
}
