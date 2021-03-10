
//holder.c

#include <std.h>

inherit OBJECT;

object caster, *mon, *foes;
int freed, count;
object spl;

void save_me(string file){return 1;}

void create(){
    ::create();
    set_name("device");
    set_id(({ "devicex999" }) );
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
	if(objectp(ob))  {
	   caster = ob;
  	} else
	   remove();
}


object query_mon(){return mon;}

object query_caster(){return caster;}

void set_my_spell(object obx){
    spl = obx;
}

set_mons(object *ob){
	mon = ob;
}


void defend(){
    int num,numfoes,i,j;
    object *tmp;
    tmp = ({});
// added checks below to try to stop bugging on defend  *Styx*  9/8/02
    if(!objectp(TO) || !objectp(caster))  return;
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

	tell_room(caster,"%^BOLD%^%^RED%^The objects attack "+tmp[num]->query_cap_name()+"!");
	}
    return;
}

void heart_beat(){
	object *tmp;
	int i,j;
	tmp = ({});
	if(!objectp(caster)) {
	   remove();
           return ;
        }
	j = sizeof(mon);
	for(i=0;i<j;i++){
		if(!objectp(mon[i]))
			tmp += ({mon[i]});
	}
	mon -= tmp;
	
	if(!sizeof(mon)) {  
// was just remove, adding return so won't call defend *Styx*  11/6/02
		remove();
		return;
	}	
	if((object *)caster->query_attackers() != ({})) {
		defend();
	}
}

void remove(){
    if(!objectp(TO)) return;
    if(objectp(spl))
      spl->dest_effect();
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
		return notify_fail("Syntax: command objects to <jump up and down>\n");
	
	if(who != "objects")
		return 0;
	
   if(what[0..4] == "drink") return notify_fail("Animated objects don't drink!\n");
   if(what[0..4] == "quaff") return notify_fail("Animated objects can't quaff a potion!\n");
   if(what[0..2] == "eat") return notify_fail("Animated objects don't eat!\n");
   if(what[0..2] == "say") return notify_fail("Animated objects can't talk!\n");
   if(what[0..3] == "yell") return notify_fail("Animated objects can't talk, let alone yell!\n");
   if(what[0..4] == "shout") return notify_fail("Animated objects can't talk, let alone shout!\n");
   if(what[0..6] == "whisper") return notify_fail("Animated objects can't talk, let alone whisper!\n");
   if(what[0..4] == "teach") return notify_fail("Animated objects can't talk, let alone teach a language!\n");
   if(what[0..7] == "offerall") return notify_fail("Uh, no, I don't think so.\n");

   if(what[0..3] == "kill") 
	return notify_fail("Animated objects will defend you but not fight alone.\n");

/* changing from this to disallow kill entirely since that is what gets abused -
no risk factor of making them kill stuff with no alignment effect from other room and/or
even standing in room and healing them without being in combat at all
reviewed with Garrett and Grendel until a better idea comes up to stop the problem
*Styx*  12/03/02
	{	
   	if(sscanf(what, "kill %s",who) == 1)
			if(ob = present(who,environment(caster)))
			   if(objectp(ob))
				if(!caster->ok_to_kill(ob))
					return notify_fail("You are not allowed to kill that creature!\n");
       if(!caster->query_property("safe arena") || !ob->query_property("safe arena"))
        "/daemon/killing_d"->check_actions(caster,ob);
	}
*/	
	j = sizeof(mon);
	for(i=0;i<j;i++){
		if(!objectp(mon[i])) continue;
		if(!mon[i]->force_me(what))
			return notify_fail("You fail to command the "+mon[i]->query_cap_name()+" to "+what+"!\n");
	}
	return 1;
}
	
	
	
int dismiss(string str){
	
	if(!str || str != "objects")
		return 0;
	
	
	tell_room(environment(caster),"%^BOLD%^"+caster->query_cap_name()+" dismisses the objects!",caster);
	tell_object(caster,"%^BOLD%^You dismiss the objects!\n");
	call_out("timed",1);
	return 1;
}

int timed(){
	remove();
}
int isMagic() {return 0;}
int is_detectable() {return 0;}
