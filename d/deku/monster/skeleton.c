#include <std.h>

inherit MONSTER;

void create() {
    ::create();
   set_name("skeleton");
   set_id( ({ "skeleton","skeleton guard" }) );
   set_race("undead");
   set_gender("male");
   set_short("A skeleton");
   set_long("%^BOLD%^%^WHITE%^This skeletal creature is the "+
   "unliving remains of what was once a human.  Its body is "+
   "nothing more than bones, some which have tattered "+
   "bits of rotting flesh attached and some which have "+
   "been picked clean.  Much of its body is caked with "+
   "the remains of armor that was once made from a dark "+
   "leather, but has faded over the course of time.  The "+
   "armor has began the process of decaying and now "+
   "remains only in tatters.  The eye sockets of this "+
   "creature are a dull black, with a slight %^RED%^"+
   "ember of red%^BOLD%^%^WHITE%^, inset into its "+
   "contrasting white skull.%^RESET%^");
   set_body_type("human");
   set_alignment(9);
   set_size(2);
   set_hd(20,1);
   set_stats("intelligence",6);
   set_stats("wisdom",4);
   set_stats("strength",18);
   set_stats("charisma",3);
   set_stats("dexterity",8);
   set_stats("constitution",7);
   set_hp(255 + random(30));
   //set_exp(12500);
	set_new_exp(20, "normal");
   
   new("/d/common/obj/weapon/shortsword")->move(TO);
     command("wield sword");
   if(query_hd() > 9) {
   	new("/d/common/obj/weapon/shortsword")->move(TO);
     command("wield sword");
   }
   add_money("electrum",random(10));
   add_money("silver",random(10));
   add_money("gold",random(5));
   add_money("copper",random(20));
   set_property("undead",1);
   set_property("swarm",1);
   set_property("no death",1);
   set_property("full attacks",1);
   set_overall_ac(3);
   set_property("no paralyze",1);
   set("aggressive",30);
   set_max_level(25);
}

