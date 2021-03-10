#include <std.h>

inherit MONSTER;

void make_me();

void create(){
        ::create();
        set_name("mercenary");
        set_id(({"soldier","mercenary soldier","mercenary", "merc"}));
        set("short","Mercenary soldier");
        set("long",
@DARKWOOD
  This warrior is one of a group of mercenary soldiers hired
by the mage Aloysius to take over and then hold the Chateau d'Arcy
against the remains of the Marquis' army.  This mercenary seems to
be barely more than hired muscle, but it might be wise not to
underestimate him.  

DARKWOOD
        );
        set_hd(8,1);
        set_exp(1250);
        set_stats("strength",18);
        set_alignment(3);
        set_size(2);
        set_body_type("human");
        add_limb("neck","neck",0,0,0);
        set_wielding_limbs(({"right hand","left hand"}));
        set_gender("male");
        set("aggressive",17);
        set_property("swarm",1);
        set_mob_magic_resistance("average");
        make_me();
        add_money("gold",random(50));
        add_money("silver",random(50));
        add_money("electrum",random(50));

}
void make_me(){
        object ob;
        int i,j,k;
        string class,race;
        i = random(5);
        switch(i){
        case 0: race = "dwarf";
                break;
        case 1: race = "human";
                break;
        case 2: race = "half orc";
                break;
        case 3: race = "gnome";
                break;
        case 4: race = "human";
                break;
        }

        set_race(race);
        i = random(4);
        switch(i){
        case 0:
        case 1: class = "fighter";
                break;
        case 2: class = "cleric";
                break;
        case 3: class = "mage";
        }
        set_class(class);

        switch(class){
        case "fighter":
                set_hp(65);
                ob = new("/d/shadow/obj/weapon/longsword");
                ob->set_property("enchantment",1);
                if(random(40) < 39) ob->set_property("monsterweapon",1);
                ob->move(TO);
                command("wield sword in right hand");
                ob=new("/d/shadow/obj/armor/chain");
                ob->set_property("enchantment",1);
                if(random(40) < 39) ob->set_property("monsterweapon",1);
                ob->move(TO);
                command("wear armor");
                break;
        case "cleric":
                set_hp(55);
                ob = new("/d/shadow/obj/weapon/mace");
                ob->set_property("enchantment",1);
                if(random(40) < 39) ob->set_property("monsterweapon",1);
                ob->move(TO);
                command("wield mace in right hand");
                ob=new("/d/shadow/obj/armor/chain");
                ob->set_property("enchantment",1);
                if(random(40) < 39) ob->set_property("monsterweapon",1);
                ob->move(TO);
                command("wear armor");
                set_spells(({ "cause light wounds","call lightning"}));
                set_spell_chance(50);
                break;
        case "mage":
                command("wear medallion");
                ob = new("/d/shadow/obj/weapon/dagger");
                ob->set_property("enchantment",1);
                ob->set_property("monsterweapon",1);
                ob->move(TO);
                command("wield dagger in right hand");
                set_spells(({"magic missile",
                                "lightning bolt",
                                "burning hands"}));
                set_spell_chance(90);
                break;
        }
}

