#include <std.h>

inherit WEAPONLESS;

void create() {
    ::create();
    set_name("emmeth");
    set_id(({"emmeth","general", "lord", "lord emmeth"}));
    set_short("Lord Emmeth, General of Aloysius' Army");
    set_long(
@DARKWOOD
  Lord Emmeth is a powerfully built man in the prime of his life. 
His skill on the battlefield and behind the scenes has earned him
the rank of General in Aloysius' mercenary army.

  Although he leads mercenaries, he is not for sale.  His sole
allegience belongs to Aloysius the Archmage, a man who delivered him
certain death on Attaya at the hands of the undead he sought to
vanquish.  Today, he still carrys the equipment he won from that
evil place, as he has vowed to return one day to crush Intruder and
take his place.
DARKWOOD
    );
    
    set_race("human");
    set_hd(30,10);
    set_level(30);
    set_gender("male");
    set_size(2);
    set_overall_ac(-18);
    set_class("fighter");
    set_guild_level("fighter",35);
    set_max_hp(420);
    set_hp(420);
    set_wielding_limbs(({"right hand","left hand"}));
    add_limb("left metal appendage","left metal appendage",96,1,4);
    add_limb("right metal appendage","right metal appendage",96,1,4);
    add_limb("horned helmet","iron helmet",96,1,4);
    set_attacks_num(6);
    set_attack_limbs(({"left metal appendage","right metal appendage",
    "horned helmet","left hand","right hand","left foot","right foot"}));
    set_base_damage_type("blunt");
    set_damage(2,10);
    set_body_type("human");
    set_property("swarm",1);
    set_property("no bump",1);
    set_stats("strength",16);
    set_stats("dexterity",16);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
    set_exp(50000);
    set_alignment(8);
    new("/d/attaya/obj/azure.c")->move(this_object());
    command("wear armor");
    new("/d/attaya/obj/bhelm.c")->move(this_object());
    command("wear helmet");
}
void die(object ob) {
       force_me("say Can't you hear him laughing at me?  "+
       "Intruder, you should have fallen by my hand...BASTARD!!!!.");
       force_me("sigh");
       message("environment",
       "%^BOLD%^%^MAGENTA%^Emmeth drops to his knees and falls face first into the dust.\n"
       ,environment(TO));
     ::die(ob);
}
int aggfunc() {
    string mrace=TP->query_race();
    if (mrace == "undead") {
        force_me ("grin");
        return 1;
    } else {
        TP->kill_ob(TO,0);
        force_me("say %^RED%^Prepare for death, fool.");
        force_me("storm");
    }
}
void set_paralyzed(int time,string message){return 1;}

