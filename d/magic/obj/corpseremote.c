//holder.c

#include <std.h>

inherit OBJECT;

object caster, *mon, *foes;
int freed, count;
int GOING = 0;

void save_me(string file){return 1;}

void create(){
  ::create();
  set_name("device");
  set("id", ({ "devicex998" }) );
  set("short", "");
  set("long", "");
  set_property("no animate",1);
  set_weight(0);
}

int move(mixed dest){
  if(ETO && objectp(ETO))
    if(interactive(ETO))
      return 0;
  ::move(dest);
  set_heart_beat(1);

}

add_mon(object ob){
  if(!mon) mon = ({});
  mon += ({ob});
}

remove_mon(object ob) {
    if(!mon) return;
    mon -= ({ob});
}

object *query_mons() {
    if(!pointerp(mon)) mon = ({});
    return mon;
}

set_caster(object ob){
  if(objectp(ob)){
    caster = ob;
  } else
    remove();
}


object *query_mon(){return mon;}

object query_caster(){return caster;}

set_mons(object *ob){
  mon = ob;		
}


void defend(){
  int num,numfoes,i,j;
  object *tmp;

  tmp = ({});
  numfoes=sizeof(tmp = caster->query_attackers());


  for(num =0;num < numfoes;num++){
    if(!objectp(tmp[num])) continue;
    if(member_array(tmp[num], (object *)mon->query_attackers()) != -1)
      continue;
    j = sizeof(mon);
    for(i =0;i < j;i++){
      if(!objectp(mon[i])) continue;
      mon[i]->kill_ob(tmp[num],1);
    }

    tell_room(caster,"%^BOLD%^%^RED%^The corpses attack "+tmp[num]->query_cap_name()+"!");
  }
		
  return;
}

void heart_beat(){
  object *tmp;
  int i,j;
  tmp = ({});
  if(!objectp(caster))
    remove();
  j = sizeof(mon);
  for(i=0;i<j;i++){
    if(!objectp(mon[i]))
      tmp += ({mon[i]});
  }
  //tmp -= 0;	
  mon -= tmp;
  if(!sizeof(mon)) remove();
	
  if((object *)caster->query_attackers() != ({})){
    defend();
  }
}

void remove(){
  object spellob;
  object *spellarr = ({ });
  if (!objectp(TO)) return;

  if (GOING) return;
  GOING = 1;

  spellarr = query_property("spelled");
  remove_property("spelled");

  if (sizeof(spellarr))
  spellarr -= ({ 0 });

  while (sizeof(spellarr) > 0) {
    spellob=spellarr[0];

    spellarr -= ({ spellob });                                                 
    if (!objectp(spellob)) continue;

    spellob->dest_effect();

  }
  
  if(objectp(spellob=(object) query_property("spell")))
    spellob->dest_effect();
  remove_property("spell");


  ::remove();
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
    return notify_fail("Syntax: command corpses to <jump up and down>\n");
	
  if(who != "corpses")
    return 0;
	
  if(what[0..3] == "kill") {
    if(sscanf(what, "kill %s",who) == 1)
      if(ob = present(who,environment(caster)))
	if(objectp(ob))
	  if(!caster->ok_to_kill(ob))
	    return notify_fail("You are not allowed to kill that creature!\n");
    "/daemon/killing_d"->check_actions(caster,ob);
  }
	
  j = sizeof(mon);
  for(i=0;i<j;i++){
    if(!objectp(mon[i])) continue;
    if(!mon[i]->force_me(what))
      write("You fail to command the "+mon[i]->query_cap_name()+" to "+what+"!\n");
  }
  return 1;
}
	
	
	
int dismiss(string str){
	
  if(!str || str != "corpses")
    return 0;
	
	
  tell_room(environment(caster),"%^BOLD%^"+caster->query_cap_name()+" dismisses the corpses!",caster);
  tell_object(caster,"%^BOLD%^You dismiss the corpses to rest!\n");
  call_out("timed",1);
  return 1;
}

void timed(){
  if(objectp(TO))
    remove();
}
