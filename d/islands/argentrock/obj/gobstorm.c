// coppied from demonstorm 5/31/11
// -hades
#include <std.h>

inherit OBJECT;

void create(){
    ::create();
    set_long("This is a swarm of spectral goblins!");
    set_short("%^RESET%^%^GREEN%^GOBLINSWARM%^RESET%^");
    set_name("gobswarmobj");
    set_id( ({"gobswarmobj", "gsobj", "goblinswarm", "swarm"}) );
    set_weight(1000000);
    set_property("no offer", 1);
    set_property("no animate", 1);
}

void start_obj(){
    call_out("flash_fun", 3);
    call_out("fire_fun", 5);
    call_out("fire_fun", 15);
    call_out("fire_fun", 30);
    call_out("endflame_fun", 31);
}

int fire_fun(){
    object ob,here,sucker,*players;
    int x,num_p;

    here=ETO;
    players=all_living(here);
    num_p=sizeof(players);
  if(!objectp(TO) || !objectp(ETO))   return 1;
    for(x=0;x<num_p;x++){
      sucker=players[x];
      if(sucker->query_true_invis()) continue;
	  if(member_array(sucker->query_race(),({"bugbear","gnoll","goblin","kobold","orc","hobgoblin" })) != -1)
          continue;	  
      if((living(sucker)) && sucker != TO ) {
        tell_object(sucker, "%^GREEN%^The chaotic swarm of %^BOLD%^goblin"+
		" specters%^RESET%^%^GREEN%^ repeatedly slash your knees and poke your bum!");
        tell_room(environment(sucker), "%^GREEN%^"+sucker->query_cap_name()+
		" screams out as minions %^BOLD%^goblin swarm%^RESET%^%^GREEN%^ circle "
		+sucker->query_possessive()+
		" legs and attack repeatedly!", sucker);
		sucker->cause_typed_damage(sucker,0,roll_dice(2,6),"negative energy");
   sucker->add_attacker(TO);
   if(!"/daemon/saving_throw_d.c"->reflex_save(sucker,-20))
   sucker->set_tripped(1);
   sucker->continue_attack();
   if(!objectp(sucker)) continue;
   sucker->remove_attacker(TO);
      }
    }
    return 1;
}

int flash_fun() {
  if(!objectp(TO) || !objectp(ETO))   return 1;
    tell_room(ETO, "%^GREEN%^A swarm of %^BOLD%^spectral goblins%^RESET%^%^GREEN%^ rush into the room!");
    return 1;
}

int endflame_fun() {
  if(!objectp(TO) || !objectp(ETO))   return 1;
    tell_room(ETO, "%^GREEN%^The goblins %^BOLD%^cheer%^RESET%^%^GREEN%^ in a high pitched voice before vanishing into a stinky mist!");
    TO->remove();
    return 1;

}
