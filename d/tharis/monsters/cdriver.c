// Coded by Tristan with adaptions by Arabesque //
 // /d/tharis/monsters/cdriver.c   //

#include "/d/common/common.h"
#include "std.h"

inherit MONSTER;
void create() {
    ::create();
        set_name("driver");
        set_id( ({ "driver","caravan driver" }) );
        set("race", "human");
        set_gender("male");
        set_short("The caravan driver");
    set("long", "The caravan driver looks at you menacingly.\n"
        "He does not appear to be in the mood to chat.\n"
        "He also appears to be a fairly wealthy man.");
        set_level(4);
        set_body_type("human");
        set_class("fighter");
        set("aggressive",5);
        set_alignment(3);
        set_size(2);
        set_stats("intelligence",13);
        set_stats("wisdom",10);
        set_stats("strength",13);
        set_stats("charisma",13);
        set_stats("dexterity",9);
        set_stats("constitution",10);
        set_max_mp(0);
        set_mp(query_max_mp());
        set_hd(4, 5);
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
        set_wielding_limbs( ({ "right hand", "left hand" }) );
        new(CWEAP"longsword")->move(TO);
        command("wield sword in right hand");
        new(CARMOR"leather")->move(TO);
        command("wear armor");
        add_money("gold",random(10));
        add_money("silver",random(10));
        add_money("copper",random(20));
   }
 
void check_it(string str) {
  if(!str) return;
  if(this_player() == this_object()) return;
  if(interact("reward", str)
     || interact("give us", str)
     || interact("we get", str))
    return write("The driver says: I am a rich man, you will be well rewarded.");
  if(interact("need", str) || interact("want", str))
    return write("The driver says: These mangy dogs can't move this wagon, "
                 "maybe you can help push it!");
}
 
void catch_tell(string str) {
  if(!str) return;
  if(this_player() == this_object()) return;
  if(!interact("say", str)) return;
  call_out("check_it", 1, str);
}
 
 
