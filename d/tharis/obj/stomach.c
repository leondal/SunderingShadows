//stomach.c

#include <std.h>
#include <daemons.h>

inherit ROOM;

object owner;
mapping digestion;

void set_owner(object behir){ owner = behir;}
void create(){
	::create();
	set_name("Behir's stomach");
	set_property("light",-10);
	set_property("indoors",1);
	set_property("no teleport",1);
	set_property("no attack",1);
	set("short","The stomach of a behir");
	set("long","You need to struggle!!");
	set_exits(([]));
	set_smell("default","The fumes of the digestive juices nearly sufficae you!");
	set_listen("default","You can distinctly hear the sounds of battle to the outside");
}

void init(){
	int hp;

	::init();
	if(!owner) owner = find_object_or_load("/d/tharis/monsters/behir");
	hp = TP->query_max_hp();
	hp = hp/6;
	call_out("digest",15,TP,hp);
	call_out("struggle",10,TPQN);
}

void digest(object who,int how){
	string name;

    if (!objectp(who)) return;  // changed to !objectp *Styx*  8/18/02

	name = who->query_name();
	if(wizardp(who))     return;   //this one is right
	if(present(name)){
                tell_object(who,"%^BOLD%^%^GREEN%^You feel the digestion taking more strength from you!\n");
		who->do_damage(who->return_target_limb(),how);
		who->add_attacker(TO);
		who->continue_attack();
		call_out("digest",15,who,how);
	}
}

void struggle(string who){
	int th, damage;
	object ob, *weapons;
//	if(!objectp(who) || !objectp(TO))  return;  //added by *Styx*  8/18/02
        if( !objectp(TO)) return;  // who is a string handler not an object. - G.
	if(wizardp(who))  call_out("struggle",100,who);
		if(ob=present(who)){
                tell_room(TO,"%^BOLD%^%^GREEN%^"+capitalize(who)+" struggles violently!",ob);
		tell_object(ob,"%^BOLD%^%^GREEN%^You struggle to cut your way free of the behir!\n");
		th =  BONUS_D->thaco(ob->query_level(),
                    ob->query_class() );
        th -= BONUS_D->tohit_bonus(owner->query_stats(
              "dexterity"), ob->query_stats("strength"), owner);
        th -= 7;
        if(random(20) > th){
        	if((object *)(weapons= ob->query_wielded()) != ({})){
        		damage = weapons[0]->query_large_damage();
        		damage += ob->get_damage(weapons[0]);
        		ob->send_messages(0, weapons[0],"stomach",damage,owner);
        	}else {
        		damage = random(4);
        		ob->send_messages(0, 0,"stomach",damage,owner);
        		}
        	owner->do_damage("torso",damage);
        }
        call_out("struggle",10,who);
    }
}
