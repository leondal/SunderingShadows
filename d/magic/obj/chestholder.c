#include <std.h>
inherit "/d/magic/obj/holder";

void defend(){
    int num,numfoes;
    object *tmp;
    
    tmp = ({});
    numfoes=sizeof(tmp = caster->query_attackers());

	for(num =0;num < numfoes;num++){
		if(!objectp(tmp[num])) continue;
		if(member_array(tmp[num], (object *)mon->query_attackers()) != -1) continue;
		mon->kill_ob(tmp[num],1);
		tell_room(environment(mon),"%^BOLD%^%^RED%^The chest slams into "+tmp[num]->query_cap_name()+"!");
	}
    return;
}

int cmd(string str){
	object ob;
	string what, who, what2, holder;
	
	if(!objectp(mon)) {
        remove();
        return 0;
	}
	if(!str) return notify_fail("Care to tell it what to do?\n");
	if(sscanf(str, "%s to %s", who, what) != 2) return notify_fail("Syntax: <command chest to ACTION>\n");
	if(!mon->id(who)) return 0;
	if(what == "follow") {
        caster->add_follower(mon);
        tell_object(caster,"The "+mon->query_short()+" is now following you.");
        return 1;
	}
	
	if(what[0..3] == "kill") {
		if(sscanf(what, "kill %s",who) == 1)
			if(ob = present(who,environment(caster)))
				if(!caster->ok_to_kill(ob))
					return notify_fail("You are not allowed to kill that creature!\n");
	}
	if(what[0..3] == "wear") return notify_fail("The chest refuses.");
	if(!mon->force_me(what)) return notify_fail("You fail to command the chest to "+what+"!\n");
	return 1;
}
	
int dismiss(string str){
	if(!str || !mon->id(str))
        return 0;
	if(objectp(caster))
        caster->remove_property("has_elemental");
	tell_object(caster,"%^BOLD%^You dismiss the chest!\n");
	call_out("timed",1);
	return 1;
}
