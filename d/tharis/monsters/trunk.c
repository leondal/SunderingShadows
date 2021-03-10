//Trying to fix this - adding an owner area - in case the owner no longer exists 
//then the person should be moved there - in the case of their not being an owner 
//area then the person will be moved to where ever they were before being put into the trunk 
//and IF that should fail they will be moved to the entrance of Tharis Forest - Saide

#include <std.h>
#include <daemons.h>

inherit ROOM;

object owner;
object owner_area;

void set_owner(object tree){ owner = tree;}
void set_owner_area(object area) { owner_area = area; }
object query_owner() { return owner; }
void create(){
        ::create();
        set_name("Hangman's trunk");
        set_property("light",-10);
        set_property("indoors",1);
        //set_property("no teleport",1);
        set_property("no attack",1);
        set("short","Thetrunk of a hangman tree's trunk");
        set("long","You need to struggle!!");
        set_exits(([]));
        set_smell("default","The fumes of the digestive juices nearly sufficateyou!");
        set_listen("default","You can distinctly hear the sounds of battle to the outside");

}

void init(){
        int hp;

        ::init();
	  //commenting this out - since this is the actual problem - if there
        //is no owner it makes one - which means the new one has no environment, 
	  //which in turns means you are stuck there forever - Saide
        //if(!owner) owner = find_object_or_load("/d/tharis/monsters/hangman_tree");
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

void struggle(string who)
{
      int th, damage, i, j;
      object ob, *weapons, where, *inven;
	if(!objectp(owner)) 
	{
		inven = all_inventory(TO);
        	i = sizeof(inven);
        	if(i)
		{
            	for(j = 0;j<i;j++)
			{
				if(!objectp(inven[j]) || !objectp(TO)) { continue; }					
				if(objectp(owner_area)) where = owner_area;
				if(!objectp(where)) 
				{
					where = inven[j]->query_property("whereiwaseaten");
					inven[j]->delete_property("whereiwaseaten");
				}
				if(!objectp(where)) 
				{
					where = find_object_or_load("/d/tharis/forest/forest1");
				}
                        inven[j]->move(where);
                       	if(objectp(inven[j]) && interactive(inven[j]))
				{
                       		inven[j]->describe_current_room(1);
                       	}
                  }
			TO->remove();
			return;
        	}
	}
	if(ob=present(who))
	{
      	tell_room(TO,"%^BOLD%^%^GREEEN%^"+capitalize(who)+" struggles violently!",ob);
            tell_object(ob,"%^BOLD%^%^GREEN%^You struggle to cut your way free of the tree!\n");
            th =  BONUS_D->thaco(ob->query_level(),
            ob->query_class() );
        	th -= BONUS_D->tohit_bonus(owner->query_stats("dexterity"), ob->query_stats("strength"), owner);
        	th -= 7;
        	if(random(20) > th)
		{
            	if((object *)(weapons= ob->query_wielded()) != ({}))	
			{
                  	damage = weapons[0]->query_large_damage();
                        damage += ob->get_damage(weapons[0]);
                        ob->send_messages(0, weapons[0],"trunk",damage,owner);
                	}else 
			{
                  	damage = random(4);
                        ob->send_messages(0, 0,"trunk",damage,owner);
               	}
               	owner->do_damage("trunk",damage);
        	}
        	call_out("struggle",10,who);
    	}
}

void clean_up(){ return 1;}
