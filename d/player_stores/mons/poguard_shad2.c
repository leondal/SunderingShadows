#include <std.h>

#define POSHAD "/d/player_stores/poffices/"
#define GUARD_D "/d/shadow/mon/guards/guard_d"

inherit MONSTER;

void get_help(object badguy);

create() {
  object weap;
  ::create();
  set_name("Raylon Ventrayer");
  set_id(({ "guard", "shop guard", "Raylon","raylon"}));
  set_short("Raylon Ventrayer, guard");
  set_long("Raylon is a lean, hard-eyed male human with wiry muscles.  His "
	"face is pitted with old scars and his nose is crooked from past breaks."
	"  He wears his auburn hair quite long and it falls in soft waves just "
	"past his shoulders, in an oddly feminine contrast to the rest of his "
	"appearance. He is dressed in black leather armor and carries a wicked "
	"looking sword.");
   set_gender("male");
   set_race("human");
   set_body_type("human");
   set_hd(28,2);
   set("aggressive", 0);
   set_property("swarm", 1);
   set_alignment(5);
   add_money("gold", random(200));
   set_overall_ac(2);
   set_max_hp(250+random(50));
   set_hp(query_max_hp());
   set_exp(500);
   weap = new("/d/common/obj/weapon/bastard");
        weap->set_property("enchantment", 2);
	weap->move(TO);
        command("wield sword");
}

// borrowed from Shadow guards since this one is allegedly commissioned by them
int kill_ob(object ob, int i){
    int hold;
    hold = ::kill_ob(ob,i);
    if (hold) {
       if (!GUARD_D->isWanted(ob))
           GUARD_D->add_wanted(ob);
       get_help(ob);
    }
    return hold;
}

void get_help(object badguy) {
   object watch;
   watch = new("/d/shadow/mon/guards/watch");
   watch->move("/d/shadow/room/city/nroad");
   GUARD_D->blow_horn(TO);
   GUARD_D->call_watch(TO, badguy);
   watch->command("open door");
   watch->command("yell It's the post office!");
   watch->command("west");
   watch->command("block east");
}
