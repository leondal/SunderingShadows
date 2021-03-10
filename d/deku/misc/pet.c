
inherit "/std/monster";

int leashed;
object owner, sicked;

create() {
    ::create();
	set_name("eagle");
	set_id( ({ "eagle","valor" }) );
	set("race", "eagle");
	set_gender("female");
        set("short","A bald eagle");
        set("long","This is an overpowering evil bald eagle.");
	set_level(10);
	set_body_type("fowl");
  	set("aggressive",1);
  	set_alignment(8);
  	set_size(2);
        set_hd(10,1);
   	set_stats("intelligence",10);
   	set_stats("wisdom",4);
   	set_stats("strength",16);
   	set_stats("charisma",14);
        set_exp(200);
   	set_stats("dexterity",20);
   	set_stats("constitution",7);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
        set_emotes(10, ({"The eagle flies about the room",
                         "The eagle ruffles its feathers",
                         "The eagle swoops onto a handy ledge",
                           "The eagle rests upon her masters shoulder"}), 0);
        set_emotes(15, ({"The eagle pecks at the eyes of its opponent",
                         "The eagle swoops in for the kill",
                         "The eagle tears at its opponent with its beak"}),1);
      leashed = 0;
      call_out("follow_me", 2);
   
}


void init() {
  ::init();
  add_action("sic","sic");
  add_action("name","name");
  add_action("leash","leash");
  add_action("free","free");
  add_action("heel","heel");
}

int sic(string str) {
  if(!str) {
    write("What would you like your pet to attack!");
    return 1;
  }
  if(this_player() != owner) return 0;
  if(sicked = !present(str, environment(this_player()))) {
    write("The eagle looks for something to attack, then gives up.");
    return 1;
  }
  force_me("kill "+str);
  write("You point your finger toward "+str+" and yell:  SIC EM!");
  say(this_player()->query_cap_name()+" points at "+str+" and yells:  SIC EM!");
  return 1;
}

int leash(string str) {
  if(str != "valor" && str != "eagle" && str != "Valor") {
    return 0;
  }
  if(leashed == 1) {
    write("Someone else has a leash on the mighty bald eagle.");
    return 1;
  }
  write("You leashed the bald eagle, and she under your control.");
  owner = this_player();
  leashed = 1;
  set_short(owner->query_cap_name()+"'s pet eagle");
  return 1;
}

follow_me() {
  if(leashed == 1) {
    if(environment() != environment(owner)) {
      if(!environment(owner)) {
        remove();
      }
      move(environment(owner));
      tell_room(environment(owner),"An eagle wings into the room after "+owner->query_cap_name()+".");
    }
  }
  call_out("follow_me", 2);
}

int free(string str) {
  if(str != "valor" && str != "eagle" && str != "Valor") {
    return 0;
  }
  if(leashed = 0 || this_player() != owner) {
    return 0;
  }
  leashed = 0;
  write("You unleash the eagle, and let him fly into the sky.");
  say(this_player()->query_cap_name()+" lets his eagle go free.");
  remove();
  return 1;
}

int name(string str) {
  if(!str) {
    write("What would you like to name your pet eagle.");
    return 1;
  }
  if(leashed = 0 || this_player() != owner) {
    write("You cannot name someone elses pet!");
    return 1;
  }
  write("You name your eagle "+str+".");
  set("short",str+", "+owner->query_cap_name()+"'s pet eagle");
  set_id(({""+str+"","eagle"}));
  leashed = 1;
  return 1;
}

int heel() {
  if(leashed = 0 || this_player() != owner) {
    return 0;
  }
  write("You tell your pet to heel!");
  say(this_player()->query_cap_name()+" calls his pet to his side.");
  this_object()->cease_all_attacks();
  return 1;
}
