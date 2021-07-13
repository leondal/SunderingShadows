// remote control for shadow double. Same as the mages sword controller (same vars etc) but with different wording. N, 10/15.
#include <std.h>
inherit "/d/magic/obj/swordremote";

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
      tell_room(ENV(sword),"%^BOLD%^%^RED%^The shadow attacks "+tmp[num]->query_cap_name()+"!");
   }
   return;
}

int cmd(string str){
   object ob;
   string what, who, what2, holder;
   int i,j;

   if(!str) return notify_fail("Care to tell it what to do?\n");
   if(sscanf(str, "%s to %s", who, what) != 2)
      return notify_fail("Syntax: command shadow to <jump up and down>\n");
   if(who != "shadow")
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
         tell_object(caster,"The shadow is now following you.");
         caster->add_follower(sword);
         return 1;
      }else{
         tell_object(caster,"The shadow must be present before it can follow you!");
         return 1;
      }
   }
      if(!caster->query_property("safe arena") || !ob->query_property("safe arena"))
      "/daemon/killing_d"->check_actions(caster,ob);
   if(!sword->force_me(what))
      return notify_fail("You fail to command the shadow to "+what+"!\n");
   tell_object(caster,"The shadow obeys your command to "+what+".");
   if(!objectp(sword)) return 1;
   return 1;
}

int dismiss(string str){
   if(!str || str != "shadow") return 0;
   tell_room(environment(caster),"%^BOLD%^"+caster->query_cap_name()+" dismisses the shadow!",caster);
   tell_object(caster,"%^BOLD%^You dismiss the shadow!\n");
   if (objectp(sword)) sword->remove();
   call_out("timed",1);
   return 1;
}
