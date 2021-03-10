
#include <std.h>
inherit "/std/monster";

create() {
    ::create();
	set_name("drunk");
	set_id( ({ "drunk","old drunk" }) );
	set("race", "dwarf");
	set_gender("male");
        set("short","Old dwarven drunk");
         set("long","This old drunk has lived in the ruined keep.  He is \n"+
                   "a crazed lunatic that walks the streets of Sanctuary.\n");
	set_level(2);
	set_body_type("human");
  	set("aggressive",1);
  	set_alignment(3);
  	set_size(1);
        set_hd(2,1);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",13);
   	set_stats("charisma",3);
        set_exp(40);
       set_hp(30);
   	set_stats("dexterity",8);
   	set_stats("constitution",7);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
            new("/d/common/obj/weapon/dagger")->move(TO);
      	command("wield dagger in right hand");
	add_money("silver",random(10));
	add_money("copper",random(20));
        set_emotes(30, ({"Drunk says: It's a fine day today.",
                 "Drunk says: You are a funny looking person.",
                 "Drunk says: Your boots are untied.",
                  "Drunk says: Could you buy me an alcoholic drink?",
                 "Drunk says: Do you have any extra silver I could have?"}), 0);
  call_out("start_wonder", 1);
   
}

void start_wonder() {
  environment(this_object())->init();
  call_out("do_wonder", 10);
}

void do_wonder() {
  string *exits;
  int i,j;
  if((mixed *)this_object()->query_attackers() == ({})) {
    exits = environment(this_object())->query_exits();
    i = sizeof(exits);
    if(exits && i) {
      j = random(i);
      if(exits[j] != "down" && exits[j] != "up" && exits[j] != "exit")
        this_object()->force_me(exits[j]);
    }
  }
  call_out("do_wonder", 10);
}
#include <std.h>
