//updated by ~Circe~ 10/14/09 to current code and new descriptions, etc.
#include <std.h>

inherit MONSTER;

void create(){
      object ob;
    ::create();
    set_name("warrior");
    set_id(({"undead warrior","undead","warrior"}));
    set_short("Undead Warrior");
    set_long("This rotting mass of flesh and bone was once a proud warrior.  Now "+
        "one of the cursed undead of the island, he wanders about in "+
        "his rusty armor, still bearing some traces of the golden "+
        "accents.  He was rather tall for a human, but it is difficult to "+
        "tell how bulky he as, as most of his flesh has rotted from "+
        "his bones.  He surveys the land with baleful, empty "+
        "eye sockets, and the scent of an open grave follows him.");
    set_race("undead");
    set_gender("male");
    set_hd(35,10);
    set_size(2);
    set_overall_ac(-6);
    set_class("fighter");
    set_guild_level("fighter",35);
    set_max_hp(query_hp());
    set_hp(450+random(200));
    set_wielding_limbs(({"right hand"}));
    set_body_type("humanoid");
    set_property("swarm",1);
    set_property("full attacks",1);
    set_property("no bump",1);
    set_stats("strength",18);
    set_stats("dexterity",16);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
    set_exp(14000);
    set_alignment(9);
    new("/d/attaya/obj/rusts.c")->move(TO);
    command("wear shield");
    new("/d/attaya/obj/rustb.c")->move(TO);
    command("wield blade in right hand");
    set_property("add kits",10);
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("bone dust");
      ob->move(TO);
    }
   set_resistance("negative energy",10);
   set_resistance("positive energy",-10);
}

void die(object ob)
{
    string area;
    
    tell_room(ETO,"%^RED%^The undead warrior collapses into a pile of bones and armor.%^RESET%^");
       
    if(objectp(ETO))
    {
        area = base_name(ETO);
        if(strsrch(area, "eldebaro") != -1)
        {
            "/d/islands/common/eldebaro/kill_tracker_d.c"->register_death(all_living(ETO));
        }
    }    
    :: die(ob);
}

int aggfunc(){
    string mrace=TP->query_race();
    if (mrace == "undead") {
	force_me ("grin");
	return 1;
    } else {
//	TP->kill_ob(TO,0);
	force_me("say %^RED%^Death to all who oppose us!");
    }
}
/*
Taking dispel out until we get a chance to fix it.  Right now, it's way too good. ~Circe~ 10/14/09
int kill_ob(object who, int which){
    int hold;
     hold = ::kill_ob(who,which);
     "cmds/wizard/_dispel_magic"->use_spell(TO,0,34);
    return hold;
}
*/