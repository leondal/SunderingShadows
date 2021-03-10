#include <std.h>
#include <daemons.h>

inherit ROOM;

object owner;

void set_owner(object tree){ owner = tree;}
void create(){
        ::create();
        set_name("Hangman's trunk");
        set_property("light",-10);
        set_property("indoors",1);
        set_property("no teleport",1);
        set_property("no attack",1);
        set("short","The trunk of a hangman tree's trunk");
        set("long","You need to struggle!!");
        set_exits(([]));
        set_smell("default","The fumes of the digestive juices nearly suffocate you!");
        set_listen("default","You can distinctly hear the sounds of battle to the outside");

}

void init(){
        int hp;

	::init();
	if(!owner) owner = find_object_or_load("/d/tharis/monsters/hangman_tree");
	call_out("digest",15,TP);
	call_out("struggle",10,TPQN);
}

void digest(object who){
	string name;

	if(!objectp(who)) return;
	name = who->query_name();
	if(present(name)){
		tell_object(who,"You feel the digestion taking more strength from you!\n");
		who->do_damage(who->return_target_limb(),roll_dice(3,4));
		who->add_attacker(TO);
		who->continue_attack();
		call_out("digest",15,who);
	}
}

void struggle(string who){
	int damage;
	object ob, *weapons;
	if(ob=present(who)){
		tell_room(TO,"%^BOLD%^%^GREEN%^"+capitalize(who)+" struggles violently!",ob);
		tell_object(ob,"%^BOLD%^%^GREEN%^You struggle to cut your way free of the tree!\n");

		ob->add_attacker(owner);
		ob->execute_attack();
/*		weapons= ob->query_wielded();
		if(random(20) > (int)ob->Thaco(1,owner,0)){
			if(weapons != ({})){
				damage = weapons[0]->query_large_damage();
				damage += ob->get_damage(weapons[0]);
				ob->send_messages(0, weapons[0],"trunk",damage,owner);
			}else {
				damage = random(4);
				ob->send_messages(0, 0,"trunk",damage,owner);
			}
			owner->do_damage("trunk",damage);
		}
*/
		call_out("struggle",10,who);
	}

}

void clean_up(){ return 1;}
