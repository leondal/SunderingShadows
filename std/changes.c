
#include <std.h>
#include <daemons.h>

inherit DAEMON;

void do_fix(object player){
	string curclass,*classes;
	object ob;
	int i,hp_loss;
	
	player->query_classes();
	player->query_level();
	player->add_exp(-((int)player->query_exp()*9)/10);
	classes = player->query_classes();
    for(i=0;i<sizeof(player->query_classes());i++){
      	curclass = classes[i];
      	while((int)ADVANCE_D->get_exp(player->query_class_level(curclass),curclass) > ((int)player->query_exp()/sizeof(classes))){
        	player->set_mlevel(curclass,(int)player->query_class_level(curclass)-1);
        	hp_loss = ADVANCE_D->get_hp_bonus(curclass,player->query_stats("constitution"),player->query_class_level(curclass),player);
        	player->set_max_hp((int)player->query_max_hp() - hp_loss);
    		player->reduce_my_skills(curclass);
        	player->reduce_guild_level(curclass);
      	}
    }
    player->setenv("TITLE", (string)ADVANCE_D->get_new_title(player));
    while(ob = present("armour of the crimson wave",player))
    	ob->remove();
    while(ob = present("screamer",player))
    	ob->remove();
    while(ob = present("azure",player))
    	ob->remove();
    while(ob = present("dominion axe",player))
    	ob->remove();
    while(ob = present("great shield",player))
        ob->remove();
    while(ob = present("stormhammer",player))
        ob->remove();
    while(ob = present("phantasmic plate",player))
        ob->remove();
    while(ob = present("death shroud",player))
        ob->remove();
    while(ob = present("horned helmet",player))
        ob->remove();
    while(ob = present("silver shoulderplates",player))
        ob->remove();
        
    player->set_old_class(0);
}
