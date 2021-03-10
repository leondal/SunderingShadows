#define PRISON_D "/adm/daemon/prison_d"
#define TP this_player()
#define VAL_DIV 1 /* full market value */
#define MAX_PRICE 100000 /* corresponding...also see /std/vendor.c */
#define VALID_JAIL_ACTIONS ({ "look", "say","quit","help","mail","lawmail","why","bboard","chfn"})
#define TPQN this_player()->query_name()
#define LAW_OR_SU "law_c"
inherit "/std/room";

int log_say(string str);
void spring_em(object vic);
void get_back();


void create() {
  ::create();
  set_light(2);
  set_indoors(1);
  set_short("Jail");
  set_property("no starve", 1);
  set_property("no teleport", 1);
  set_long(
@GARRETT
This is the ShadowGate Mud Jail. It is an empty white room
A strange tingling field envelops you and limits your will
to do much at all to try to escape.\n A large neon sign states:
Do NOT bother the arches about your imprisonment 
or you might make matters worse for yourself and end up rid.

  If you do not know why you were imprisoned, type <why>.
  If you think you have been treated unfairly, make a respectful
appeal by mail to the law arches (lawmail).
GARRETT
);

//call_out("get_back",1);

}

void init() {
  ::init();
  
  if (!member_group(geteuid(this_player()),LAW_OR_SU))
    add_action("why","why");
  if (!member_group(geteuid(this_player()),LAW_OR_SU)){
    if (!PRISON_D->is_imprisoned(this_player()->query_name())) {
      write("You are escorted out of the MUD jail.");
      spring_em(this_player());
      return;
    }
    
    add_action("filter_act","",1);
if (!member_group(geteuid(TP),LAW_OR_SU)) log_file("adm/jail/"+(string)TP->query_name(), TPQN+" logged in on: ["+ctime(time())+"]\n");
    
  } else {
    add_action("log_say","say");
  }
}

int filter_act(string str) {

  if (!member_group(geteuid(this_player()),LAW_OR_SU)){
    if (!PRISON_D->is_imprisoned(this_player()->query_name())) {
      write("You are escorted out of the MUD jail.");
      spring_em(this_player());
      return 1;
    }
  }

  if (member_array(query_verb(), VALID_JAIL_ACTIONS ) == -1) {
    write("Prisoners are incapable of such acts.");
    return 1;
  }

  if (query_verb() == "say") {
    log_say(str);
  }
  return 0;
}

int log_say(string str) {
  int iter;
  object ob, *liveones;
  
  liveones=all_living(environment(this_player()));
  //  write(identify(liveones)); write(identify(sizeof(liveones)));
  
  for (iter=sizeof(liveones); iter > 0 ; iter--){
    ob=liveones[iter-1];
    //    write(identify(ob));
    //    write(identify(geteuid(ob)));
    //    write(identify(iter));
    
    if (!objectp(ob))
      continue;
    if (!member_group(geteuid(ob),LAW_OR_SU)) {
      log_file("adm/jail/"+(string)ob->query_name(), TPQN+" says: "+str+"["+ctime(time())+"]\n");
    }
    
  }
  return 0;
}

int why() {
  if (PRISON_D->is_imprisoned(this_player()->query_name())) {
    write("You are imprisoned for: "+
	  PRISON_D->query_reason(this_player()->query_name()));
    write("You will be released: "+
	  ctime(PRISON_D->query_release_time(this_player()->query_name())));
  }
  return 1;
}

void heart_beat() {
  ::heart_beat();
  get_back();
}

void get_back(){
  string *players;
  object player;
  int i,j;
  
  players = keys(PRISON_D->query_prison_list());
  j = sizeof(players);
  if(j){
    for(i=0;i<j;i++){
      if(present(players[i])) continue;
      else
	if(player = find_player(players[i]))
	  player->force_me("quit");
    }
  }
  // call_out("get_back",1);
}
		
void spring_em(object victim) {
  if (!objectp(victim)) return;
  if (!interactive(victim)) return;

  if (victim->move(victim->query_last_location())) {
    
    victim->move(victim->getenv("start"));
  } else {
    return;
  }
  
  if (this_object() == environment(victim) )
    victim->move("/d/shadowgate/adv_main");
  return;
}
