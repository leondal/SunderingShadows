#include <std.h>
#include <daemons.h>

inherit ROOM;

object owner, thingy,owner_area;

void fail_safe()
{
	int i;
	object *inven=({});

	if(!objectp(TO)) return;
	if(!objectp(owner))
	{
		inven = all_inventory(TO);
		if(sizeof(inven))
		{
			for(i=0;i<sizeof(inven);i++)
			{
				if(!objectp(inven[i])) { continue; }
				if(base_name(inven[i] == "/d/tharis/obj/treething")) { continue; }
				if(!objectp(owner_area))
				{
					inven[i]->move("/d/tharis/road/eroad16.c");
				}
				else
				{
					inven[i]->move(owner_area);
				}
			}
		}
		TO->remove();
	}
	return;
}


void set_owner(object tree){
	if(!objectp(tree)) { TO->remove(); return; }
    if(!objectp(TO)) { create(); }
   owner = tree;
   thingy->set_owner(owner);
}

void set_owner_area(object room)
{
	if(!objectp(TO)) { return; }
	if(!objectp(room)) { return; }
	owner_area = room;
	return;
}



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
	thingy = new ("/d/tharis/obj/treething");
	thingy->move(TO);
}

void init()
{
    int hp;
	::init();

	//if(!owner) owner = find_object_or_load("/d/tharis/monsters/hangman_tree");
	if(TP == thingy) return;
	if(!objectp(TO)) return;

	fail_safe();

	call_out("digest",15,TP);
	call_out("struggle",10,TPQN);
}

void digest(object who){
	string name;

	if(!objectp(who)) return;

	fail_safe();

	name = who->query_name();
	if(present(name)){
		tell_object(who,"You feel the digestion taking more strength from you!\n");
		who->do_damage(who->return_target_limb(),roll_dice(3,8));
		who->add_attacker(TO);
           if(!objectp(who)) return;
		who->continue_attack();
		call_out("digest",15,who);
	}
}

void struggle(string who){
	int damage;	
	object ob, *weapons;

	fail_safe();

	if(ob=present(who)){
		tell_room(TO,"%^BOLD%^%^GREEN%^"+capitalize(who)+" struggles violently!",ob);
		tell_object(ob,"%^BOLD%^%^GREEN%^You struggle to cut your way free of the tree!\n");

		ob->add_attacker(thingy);
//		ob->execute_attack();
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
