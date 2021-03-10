// Note:  If something is changed here, please review if the following files also need the same fix or change since they are nearly identical: celemholder.c, cgenieholder.c, csalholder.c, ctreeholder.c, cplanarholder.c  *Styx*

#include <std.h>
inherit OBJECT;

object caster, mon, *foes;
int freed, count;

void save_me(string file){return 1;}

void create(){
   ::create();
   set_name("device");
   set("id", ({ "ctreedevicex999" }) );
   set("short", "");
   set("long", "");
   set_weight(0);
}

int move(mixed dest){
   if(ETO && objectp(ETO))
      if(interactive(ETO))
         return 0;
   ::move(dest);
   set_heart_beat(10);
}

set_caster(object ob){
   if(objectp(ob))
      caster = ob;
   else
      remove();
}

int query_freed(){return freed;}

object query_mon(){return mon;}

object query_caster(){return caster;}

set_tree(object ob){
   if(objectp(ob))
      mon = ob;
   else
      remove();
}

set_freed(int x){
   freed = x;
}

void defend(){
   int num,numfoes;
   object *tmp;

   tmp = ({});
   numfoes=sizeof(tmp = caster->query_attackers());
   for(num =0;num < numfoes;num++){
      if(!objectp(tmp[num])) continue;
      if(member_array(tmp[num], (object *)mon->query_attackers()) != -1)
         continue;
      mon->kill_ob(tmp[num],1);
      tell_room(environment(mon),"%^BOLD%^%^RED%^The treant attacks "+tmp[num]->query_cap_name()+"!");
   }
   return;
}

void heart_beat(){
   if(!objectp(mon))
      remove();
   if(!objectp(caster))
      remove();
   if(!freed && (object *)caster->query_attackers() != ({}))
      defend();
   if(freed){
      count++;
      if(count > 5){
        tell_room(environment(mon),"%^BOLD%^The treant returns to the ground!");
         remove();
      }
   }
}

void remove(){
   if(objectp(mon)){
      if(objectp(mon->query_property("spell")))
         mon->query_property("spell")->dest_effect();
      if(objectp(mon))
         mon->remove();
   }
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

   if(!objectp(mon)) remove();
   if(!str) return notify_fail("Care to tell it what to do?\n");
   if(freed) return notify_fail("It has broken your spell!\n");
   if(sscanf(str, "%s to %s", who, what) != 2)
      return notify_fail("Syntax: command <monster> to <jump up and down>\n");
   if(!mon->id(who)) return 0;
   if(str[0..3] == "kill") {
      if(sscanf(what, "kill %s",who) == 1)
         if(ob = present(who,environment(caster)))
            if(!caster->ok_to_kill(ob))
               return notify_fail("You are not allowed to kill that creature!\n");
   }
   if(what == "follow")
   {
       caster->add_follower(mon);
       tell_object(caster,""+mon->query_name()+" is now following you.");
   }
   if(!mon->force_me(what))
      return notify_fail("You fail to command the treant to "+what+"!\n");
   return 1;
}
	
int dismiss(string str){
   if(!str || !mon->id(str))
      return 0;
   if(freed)
      return notify_fail("You have no power over this being any more.\n");
   tell_room(environment(caster),"%^BOLD%^"+caster->query_cap_name()+" dismisses the treant!",caster);
   tell_object(caster,"%^BOLD%^You dismiss the treant!\n");
   call_out("timed",1);
   return 1;
}

timed(){
   remove();
}
