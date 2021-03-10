#include <std.h>
inherit MONSTER;

void make_me();

void create(){
        string subj, pos;
        ::create();
        set_name("Tharis City Guard");
        set_id(({"guard","tharis guard","soldier","tharis soldier","soldier of the city guard"}));
        set_short("%^BLACK%^%^BOLD%^A so%^RESET%^l%^BLACK%^%^BOLD%^dier of the %^RESET%^Tharis%^BLACK%^%^BOLD%^ Gua%^RESET%^r%^BLACK%^%^BOLD%^d%^RESET%^");
        switch(random(2)) {
          case 0: set_gender("male"); subj = "he"; pos = "his"; break;
          default: set_gender("female"); subj = "she"; pos = "her"; break;
        }
        set_long("%^RESET%^%^CYAN%^This soldier looks capable and ready for any trouble "
+subj+" may encounter. "+capitalize(pos)+" armor and weapons are well tended and handled "
+"with expertise. An emblem is embossed over "+pos+" left breast, of a black sphere with "
+"a silver border, within which is depicted a single tall spire.");
        set_race("human");
        set_hd(20,8);
        set_exp(1400);
        set_stats("strength",18);
        set_stats("wisdom",18);
        set_stats("intelligence",18);
        set_alignment(6);
        set_size(2);
        set_body_type("human");
        add_limb("neck","neck",0,0,0);
        set_wielding_limbs(({"right hand","left hand"}));
        set("aggressive",6);
        set_property("swarm",1);
        set_mob_magic_resistance("average");
        set_max_level(15);
        make_me();
        add_money("gold",10+random(5));
        add_money("silver",10+random(5));
        add_money("electrum",10+random(5));
}

void make_me(){
        object ob;
        int i,j,k;
        string theclass,race;

        i = random(4);
        switch(i){
        case 0:
        case 1: theclass = "fighter";
                break;
        case 2: theclass = "cleric";
                break;
        case 3: theclass = "mage";
        }
        set_class(theclass);
        set_guild_level(theclass,20);
        set_mlevel(theclass,20);

        switch(theclass){
        case "fighter":
                set_hp(350);
                ob = new("/d/common/obj/weapon/longsword");
                ob->set_property("enchantment",4);
                ob->set_property("monsterweapon",1);
                ob->move(TO);
                command("wield sword");
                ob = new("/d/common/obj/armour/chain");
				ob->set_property("enchantment",3);
				ob->move(TO);
                command("wear armor");
                break;
        case "cleric":
                set_hp(300);
                new("/d/tharis/obj/mrmedalion")->move(TO);
                command("wear medallion");
                ob = new("/d/common/obj/weapon/mace");
                ob->set_property("enchantment",3);
                ob->set_property("monsterweapon",1);
                ob->move(TO);
                command("wield mace");
                ob = new("/d/common/obj/armour/chain");
				ob->set_property("enchantment",3);
				ob->move(TO);
                command("wear armor");
                set_spells(({ "cause moderate wounds","call lightning", "dispel magic", "hold person"}));
                set_spell_chance(60);
                break;
        case "mage":
                set_hp(250);
                ob = new("/d/common/obj/armour/bracers");
                ob->set_property("enchantment",3);
                ob->set_property("monsterweapon",1);
                ob->move(TO);
                command("wear bracers");
                ob = new("/d/common/obj/weapon/dagger");
                ob->set_property("enchantment",3);
                ob->set_property("monsterweapon",1);
                ob->move(TO);
                command("wield dagger");
                set_spells(({"magic missile",
                                "lightning bolt",
                                "magic missile",
                                "dispel magic"}));
                set_spell_chance(90);
                break;
        }
}


