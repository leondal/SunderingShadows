#include <std.h>
#include "/d/common/common.h"
#include "std.h"

inherit MONSTER;

int build,reload;
string *outs,*exit_dir;

void do_check();
void do_bow();

int count;

void create() {
    object ob;
    ::create();
    set_name("archer");
    set_id(({"an archer","archer","small archer"}));
    set_race("human");
    set_gender("male");
    set_short("A small archer");
    set_long("A man hired by the forces of evil for his archery skills.  His dark leather armor, leggings, and boots camouflage him well.\n");
    set_level(20);
    set_hd(20,1);
    set_hp(150+random(20));
    set_exp(3500);
    set_body_type("human");
    set_class("fighter");
    set_property("full attacks",1);
    set("aggressive", 25);
    set_alignment(3);
    set_size(2);
    set_stats("intelligence",12);
    set_stats("wisdom",12);
    set_stats("strength",18);
    set_stats("charisma",10);
    set_stats("dexterity",14);
    set_stats("constitution",16);
    set_max_hp(query_hp());
//    set_wielding_limbs( ({ "right hand", "left hand"}) );
    set_overall_ac(0);
    ob = new(CLRWEAP"arrows");
      ob->move(TO);
      ob->set_property("monsterweapon",1);
    ob = new(CLRWEAP"shortbow");
      ob->move(TO);
      command("wield bow");
    ob = new(CWEAP"longsword");
      ob->move(TO);
      ob->set_property("monsterweapon",1);
    ob = new(CWEAP"longsword");
      ob->move(TO);
      ob->set_property("monsterweapon",1);
    add_money("electrum",random(10));
    add_money("silver",random(10));
    add_money("gold",random(100));
    enable_commands();
    set_max_level(25);
}
void start_heart() {
    set_heart_beat(1);
}

void heart_beat() {
    ::heart_beat();
//moved stuff below from before to after the ::heart_beat() to let heart_beat
//finish before trying to do them.

    count++;
    if(objectp(TO))  do_check();       //added check for valid object first.
    if(objectp(query_weapon("right hand")))
        if((string)query_weapon("right hand")->query_name() != "longsword" && count > 5)
            do_bow();
}

void do_bow() {
    int i,j, y,z;
    object ob, *inven, *living_bad;
    string exit,*paths, *ids;

    living_bad = ({});
    if(ETO && objectp(ETO)) {
        paths = ETO->query_destinations();
        if(j = sizeof(paths)) {
            for(i=0;i<j;i++) {

                if(ob = find_object_or_load(paths[i]) && objectp(ob)) {

                    inven = all_inventory(ob);
                    z = sizeof(inven);

                    for(y=0;y<z;y++)
                        if(living(inven[y]) && ALIGN->is_good(inven[y])) {
                            living_bad += ({inven[y]});
                        }

                    if(z = sizeof(living_bad)) {
                        y = random(z);
//added check for invis.  Put it here rather than excluding them from living_bad
//so if there is an elf 2 etc. it will have the target id right - Styx 12/29/01
                        if(living_bad[y]->query_invis())  break;
                        exit = ETO->query_direction(paths[i]);
                        if(!interactive(living_bad[y])) {
                            ids = living_bad[y]->query_id();
                            command("shoot "+ids[0]+" 1 "+exit);
                        }
                        else
                            command("shoot "+living_bad[y]->query_name()+" 1 "+exit);
                        break;
                    }
                }
            }
        }
    }
    count = 0;
}



void do_check() {
    object *weapons;
    int i;

    weapons = TO->query_wielded();

    if(sizeof(weapons)) {
        if((string)weapons[0]->query_name() != "shortbow") {
            if((object *)TO->query_attackers() == ({})) {
                command("unwield sword");
                command("unwield sword 2");
                command("wield bow");
            }
        }
        else
            if((string)weapons[0]->query_name() == "shortbow") {
            if((object *)TO->query_attackers() != ({})) {
                command("unwield bow");
                command("wield sword");
                command("wield sword 2");
            }
        }
    }
    if(!present("arrows"))
        new(CLRWEAP"arrows")->move(TO);
}

void init() {
    ::init();

    if(ALIGN->is_good(TP) && !TP->query_invis())
        kill_ob(TP,1);
}
