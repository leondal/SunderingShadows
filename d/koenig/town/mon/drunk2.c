#include <std.h>
inherit "/std/monster";

string time;

create() {
    ::create();
	set_name("drunk");
	set_id( ({ "drunk","old drunk" }) );
        set_race("human");
	set_gender("male");
        set("short","A stumbling old drunk");
        set_long("This old drunk man wanders the streets of Muileann, mumbling to himself and pleading for handouts.\n");
	set_level(2);
	set_body_type("human");
  	set("aggressive",1);
  	set_alignment(6);
  	set_size(1);
        set_hd(2,1);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",13);
   	set_stats("charisma",3);
  set_exp(48);
       set_hp(12);
   	set_stats("dexterity",8);
   	set_stats("constitution",7);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        new("/d/deku/weapons/dagger")->move(this_object());
        new("/d/koenig/town/items/paper4.c")->move(this_object());
      	command("wield dagger in right hand");
	add_money("silver",random(10));
	add_money("copper",random(20));
  set_emotes(5, ({"The drunk gives a sigh and begins to mumble nonsense.",
  "%^MAGENTA%^Drunk mumbles: %^RESET%^I miss my drinking buddy, Horatio.",
  "%^BOLD%^%^WHITE%^The drunk pats the %^RESET%^skull%^BOLD%^%^WHITE%^ he carries craddled in one arm and begins to sob.%^RESET%^",
"%^MAGENTA%^Drunk sobs: %^RESET%^My poor friend, Horatio, he was a wonderful artist, his paintings and tapestries were so beautiful and magical.\n",
  "%^MAGENTA%^Drunk says: %^RESET%^He even let me enter one once...\n"}), 0);
  call_out("start_wander", 1);
   
}
void start_wander() {
  if(!objectp(ETO)) return;
  environment(TO)->init();
  call_out("do_wander",10);
  }
void do_wander() {
  string *exits;
  int i,j;
    if((mixed *)TO->query_attackers() == ({})) {
    exits = environment(TO)->query_exits();
    i = sizeof(exits);
    if(exits && i) {
    j = random(i);
    if(exits[j] != "down" && exits[j] != "up" && exits[j] != "gate" && exits[j] != "door" && exits[j] != "enter" && exits[j] != "stable" && exits[j] != "restaurant" && exits[j] != "bar")
    TO->force_me(exits[j]);
    }
  }
    call_out("do_wander", 10);
}
void reset() 
{
  ::reset();
    time = "daemon/events_d"->query_time_of_day();
    if(time == "twilight")
    remove();
}
