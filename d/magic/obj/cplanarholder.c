// Note:  If something is changed here, please review if the following files also need the same fix or change since they are nearly identical: celemholder.c, cgenieholder.c, csalholder.c, ctreeholder.c, cplanarholder.c  *Styx*

#include <std.h>
inherit OBJECT;

object caster, mon, *foes;
int freed, count;

void save_me(string file){return 1;}

void create(){
   ::create();
   set_name("device");
   set("id", ({ "celemdevicex999" }) );
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

set_elemental(object ob){
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

   if(!objectp(mon) || !objectp(caster)) {
// added the caster check & return for bug prevention/fix  *Styx*  5/17/03
	remove();
	return;  
   }
   tmp = ({});
   numfoes=sizeof(tmp = caster->query_attackers());
   for(num =0;num < numfoes;num++){
      if(!objectp(tmp[num])) continue;
      if(member_array(tmp[num], (object *)mon->query_attackers()) != -1)
         continue;
      mon->kill_ob(tmp[num],1);
      tell_room(environment(mon),"%^BOLD%^%^RED%^The planar creature attacks "+tmp[num]->query_cap_name()+"!");
   }
   return;
}

void heart_beat(){
   if(!objectp(mon))
      remove();
   if(!objectp(caster))
      remove();
   if(!freed && sizeof(caster->query_attackers()) ) // was bugging, changed to sizeof() from object casting - Ares 2-22-05
      defend();
   if(freed){
      count++;
      if(count > 5){
         tell_room(environment(mon),"%^BOLD%^Weared from its time on this plane, the planar creature returns to its own realm!");
         remove();
      }
   }
}

void remove(){
   if(objectp(mon)){
      if(objectp(mon->query_property("spell")))
         mon->query_property("spell")->dest_effect();
   }
   if(objectp(mon)) mon->remove();
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

   if(!objectp(mon)) {
	remove();
	return 0;  // added the return 0 to stomp bugs - Styx 5/17/03
   }
   if(!str) return notify_fail("Care to tell it what to do?\n");
   if(freed) return notify_fail("It has broken your spell!\n");
   if(sscanf(str, "%s to %s", who, what) != 2)
      return notify_fail("Syntax: command <monster> to <jump up and down>\n");
   if(!mon->id(who)) return 0;
   if(what[0..3] == "kill") {
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
   if(what[0..3] == "wear")
	return notify_fail("Planar creatures cannot wear anything.");
   if(!mon->force_me(what))
      return notify_fail("You fail to command the elemental to "+what+"!\n");
   return 1;
}
	
int dismiss(string str){
   if(!objectp(mon)) return 0;
   if(!str || !mon->id(str))
      return 0;
   if(freed)
      return notify_fail("You have no power over this being any more.\n");
   tell_room(environment(caster),"%^BOLD%^"+caster->query_cap_name()+" dismisses the planar creature!",caster);
   tell_object(caster,"%^BOLD%^You dismiss the planar creature!\n");
   call_out("timed",1);
   return 1;
}

timed(){
   remove();
}
