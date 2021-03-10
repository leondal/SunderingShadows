// First aid

// know as _heal.c

//Will allow players to perform basic first aid on themselves and others
//To balance the obvious repeat commands will no allow the players 
// involved in the the first aid to attack for 5 rounds --
// 1/2 to get to the player and the rest to perform.
// Note the monsters will still be attacking --- this will keep players 
// from attempting to mass heal themselves while in combat.


#include <std.h>

inherit DAEMON;



int cmd_heal(string str){

    string who, extra;
    int x;
    object player;


    if(!str) {
      notify_fail("Syntax: heal <name>\n");
      return 0;
    }
       if(!player = present(str,environment(TP))){
      notify_fail("This person is not here now.\n");
      return 0;
    }
    
    if(TP == player){ 
	write("You start healing");
        tell_room(environment(TO),TPQCN+" attempts to heal himself.");
            TP->set_paralyzed(10,"You are healing");
    }
    else {
        TP->set_paralyzed(50,"You are healing "+player->query_cap_name()+".");
     player->set_paralyzed(50,"You are being healed");   
        write("You start healing "+player->query_cap_name()+".");
       tell_room(environment(TP),TPQCN+" attempts to heal "+player->query_cap_name()+".",({TP,player}));
      tell_player(player,TPQCN+" attempts to heal you.\n");
    }

    if((int)TP->query_stats("wisdom") <(random(20)+2)){
          write("%^BOLD%^ You, apparently, are failing...%^BOLD%^");
if(TP != player)
           tell_player(player,"%^GREEN%^%^%BOLD%^You see a worried expression cross "+TPQCN+"'s face.%^GREEN%^%^BOLD&^\n");
    }
    else {
      write("It seems to be working.");
if(TP != player)
      tell_player(player,"It seems to be working.\n");
x = random(3) + 1;
player->heal(x);
      x = player->query_poisoning();
      player->add_poisoning(-(x));
    }

    return 1;
     }
