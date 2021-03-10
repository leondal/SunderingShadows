#include <std.h>

inherit MONSTER;

string time;

create() {
    ::create();
	set_name("drunk");
	set_id( ({ "drunk","old drunk" }) );
	set("race", "orc");
	set_gender("male");
        set("short","A stumbling old drunk");
   set_long("This old drunk looks to have been here for some time, drinking away his troubles and fears.\n");
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
      	command("wield dagger in right hand");
	add_money("silver",random(10));
	add_money("copper",random(20));
   set_emotes(5, ({"%^MAGENTA%^Drunk says%^RESET%^: It is a sad day today.",
   "%^MAGENTA%^Drunk says%^RESET%^: You are a fool to have come to this town!",
   "%^MAGENTA%^Drunk sings bitterly%^RESET%^: Meat for silver platters, blood for golden goblets, the Gentleman will feast well tonight.\n%^BOLD%^%^WHITE%^Drunk bursts into insane laughter.\n",
   "%^MAGENTA%^Drunk says%^RESET%^: Could you buy me a drink to chase the nightmares away, friend?",
   "%^MAGENTA%^Drunk says%^RESET%^: %^RED%^Do not enter the evil tower, or your family will mourn your death and the eternal damnation of your soul!\n"}), 0);
   
}

