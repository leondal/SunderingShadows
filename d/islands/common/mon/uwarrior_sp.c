// copy of the uwarrior but has a random very special magical weapon.
// use very sparingly...  *Styx*  5/26/02

#include <std.h>
inherit MONSTER;
void create() {
      object ob;
    ::create();
    set_name("warrior");
    set_id(({"undead warrior","undead","warrior"}));
    set_short("Undead Warrior");
    set_long("
    It is a potent warrior in rusty armor that still has accents of gold.
");
    set_race("undead");
    set_gender("male");
    set_hd(25,10);
    set_size(2);
    set_overall_ac(-6);
    set_class("fighter");
    set_guild_level("fighter",35);
    set_max_hp(query_hp());
    set_hp(250+random(200));
    set_wielding_limbs(({"right hand", "left hand"}));
    set_body_type("human");
    set_property("swarm",1);
    set_property("full attacks",1);
    set_property("no bump",1);
    set_stats("strength",18);
    set_stats("dexterity",16);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
    set_exp(9000);
    set_alignment(9);
    new("/d/common/obj/special/sp_randwpn")->move(this_object());
    command("wield rweapon");
    set_property("add kits",25);
    ob = new("/d/common/obj/brewing/herb_special_inherit");
    ob->set_herb_name("bone dust");
    ob->move(TO);
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
    ::die(ob);
}

int aggfunc() {
    string mrace=TP->query_race();
    if (mrace == "undead") {
	force_me ("grin");
	return 1;
    } else {
	TP->kill_ob(TO,0);
	force_me("say %^RED%^Death to all who oppose us!");
    }
}
int kill_ob(object who, int which){
    int hold;
     hold = ::kill_ob(who,which);
     "cmds/spells/d/_dispel_magic"->use_spell(TO,0,34,100,"mage");
    return hold;
}
