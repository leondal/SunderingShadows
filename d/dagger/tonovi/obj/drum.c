#include <std.h>

inherit OBJECT;
nosave int used; //so you can only use it once until it wears off - Saide//
nosave string name;
nosave object *affected_players;

// changed all global variable to static on Styx's advice, to stop them
// saving unnecessarily and to try to fix a bug
// when players logged out while the effect was still running
// Lujke September 2005


void create(){
    ::create();
    set_name("Bard's drum");
    set_id( ({"drum", "silver drum", "bard's drum"}) );
    set_short("Silver drum");
    set_long(
      "This silver drum was made for the bards of the land.  Crafted by the great musicians, it is said that its beat can enhance the rally call of a bard, exciting his friends even more."
    );
    set_weight(8);
    set_value(600);

}

void init(){
    ::init();
    add_action("rally", "rally");
}

int rally(string str) {
    object *inven, *cur_players;
    int i, align;

    if(!TP->is_class("bard")) {
        return notify_fail("Only bards may use the drum.");
    }

    align = TP->query_alignment();

    if(align==1 || align==3 || align==7 || align==9){
	    tell_object(TP,"You cannot use your bard skills unless you are of a neutral alignment!\n");
	    return 1;
    }

    if((object)TP->query_attackers() != ({})) {
	    tell_object(TP,"Not while fighting.\n");
	    return 1;
    }
    if(used==1) {
        tell_object(TP,"You begin to play the drum but realize "+
        "that its magic is in effect already!\n");
        return 1;
    }

    inven = ({});
    cur_players = ({});

    inven += all_living(environment(TP));

    for(i = 0;i<sizeof(inven);i++) {
	    if(userp(inven[i])) {
	        cur_players += ({inven[i]});
        }
    }
	tell_object(TP, "You begin to play your drum, trying to raise the spirits of your allies");
	tell_room(ETP, ""+TPQCN+" starts to play the drum, raising your spirits with its invigorating beat.", TP);
	tell_object(TP, "You continue to play the drum, making sure that it raises your comrade's spirits");
	TP->set_paralyzed(20,"You are busy trying to rally your friends");
    if(sizeof(cur_players)) {
        used = 1;
        call_out("set_listeners", 20, TP, cur_players);
    }
    return 1;
}

void set_listeners(object player, object *cur_players){
	int i;
	int time;
	object ob;
    affected_players = ({});
	name = player->query_name();
	for(i = 0;i <sizeof(cur_players);i++){
	    if(ob = present(cur_players[i],environment(player))){

        if(pointerp(ob->query_property("rally") )&& member_array(name,ob->query_property("rally")) != -1) continue;
		    ob->add_saving_bonus("all", 2);
		    ob->add_attack_bonus(2);
		    ob->add_stat_bonus("strength",1);
		    ob->add_stat_bonus("dexterity",1);
            affected_players += ({ob});
		    ob->set_property("rally",({player->query_name()}));
		    tell_object(ob,"You feel the power of adrenaline flowing through you.");
	    }
	}
    if(!sizeof(affected_players)) {
        used = 0;
    }
	time = ((int)player->query_guild_level("bard")*11);
	name = (string)player->query_name();
	call_out("reset_player",time, name, cur_players);
	player->remove_paralyzed();
	tell_object(player,"You finish inspiring your comrades.");
}

void reset_player(string name, object *players_listen){
	int i;
	string *tmp;

	for(i = 0;i <sizeof(players_listen);i++){
	    if(!objectp(players_listen[i])||(pointerp(players_listen[i]->query_property("rally"))&& member_array(name,players_listen[i]->query_property("rally")) == -1)) continue;
	        tell_object(players_listen[i],"You feel the effects "+
            "of the bard's song wear off.");
              used = 0;
	        players_listen[i]->add_saving_bonus("all",(-2));
	        players_listen[i]->add_attack_bonus((-2));
	        players_listen[i]->add_stat_bonus("strength",-1);
	        players_listen[i]->add_stat_bonus("dexterity",-1);
	        tmp = players_listen[i]->query_property("rally");
/*
            if(!pointerp(tmp)) {
                continue;
            }
            if(!name) {
                continue;
            }
removing this to see if it fixes error with rally wearing off.
Normal rally doesn't have these.  Circe 12/5/04
*/
	        tmp -= ({name});
	        players_listen[i]->remove_property("rally");
	        players_listen[i]->set_property("rally",tmp);
	  }
}

void remove() {
    if(used) {
        reset_player(name,affected_players);
    }
    ::remove();
}

int is_instrument(){return 1;}
