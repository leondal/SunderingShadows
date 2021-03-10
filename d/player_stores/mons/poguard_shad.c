#include <std.h>

#define POSHAD "/d/player_stores/poffices/"
#define GUARD_D "/d/shadow/mon/guards/guard_d"

inherit MONSTER;

void get_help(object badguy);
void make_me();

void create() {
  ::create();
   set_gender("male");
   set_race("human");
   set_body_type("human");
   set_hd(28,2);
   make_me();
   set("aggressive", 0);
   set_property("swarm", 1);
   set_alignment(5);
   add_money("gold", random(200));
   set_overall_ac(2);
   set_max_hp(250+random(50));
   set_hp(query_max_hp());
   set_exp(500);
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

void make_me() {
   object weap;
   switch(random(2)) {
     case 0:
	set_name("Buchary Romhoff");
	set_id(({ "guard", "shop guard", "Buchary","buchary"}));
	set_short("Buchary Romhoff, a guard");
	set_long("A burly, clean shaven human dressed in smart pantaloons, "
	  "a tailored shirt and waistcoat.  He watches the store with a practiced "
	  "eye, all the while swinging a small billy club at his side.  He wears "
	  "a small %^BOLD%^%^BLACK%^hunting horn %^RESET%^on a chain round his neck.");
	weap = new("/d/common/obj/weapon/club");
          weap->set_property("enchantment", 2);
          weap->set_short("A billy club");
          weap->add_id("billy club");
          weap->set_long("This club is a type commonly carried by guards who may want "
	   "to subdue an opponent by knocking them out without killing them.  It is "
	   "slender enough at the base for a human to grip easily in one hand and "
	   "only widens slightly from there.  It is approximately two foot long and "
	   "has a leather strap that is worn around the wrist of the wielder or used "
	   "to hang from a buckle on the belt.");
	  weap->move(TO);
        command("wield club");
	set_emotes(1, ({ "Buchary clears his throat.",
		"Buchary taps his billy club lightly in his palm.",
		"%^MAGENTA%^Buchary says:  %^RESET%^It's okay, I'm properly licensed by the Shadow Watch.",
		"Buchary casts an appraising eye over you but says nothing.",
		"Buchary wanders about then returns to standing in front of the iron bound door.",
	}), 0 );
	break;
     case 1:
	set_name("Bornoss");
	set_id(({ "shop guard", "guard", "Bornoss", "bornoss", "falbert" }));
	set_short("Bornoss Falbert, a guard");
 	set_long("A dark eyed man with a neatly trimmed beard, Bornoss stands "
"guard in the shop.  His posture is relaxed but alert, his weight resting "
"comfortably on the balls of his feet as he watches for trouble of any sort.  "
"His sword is sheathed but his hand rests on the hilt.  He looks well able to "
"put it to good use and a small badge on his chest indicates that he is "
"authorized to do so in the name of the Shadow Watch.");
	weap = new("/d/common/obj/weapon/bastard");
        weap->set_property("enchantment", 2);
	weap->move(TO);
        command("wield sword");
//	set_emotes(1, ({ }), 0 );
	break;
   }
}
