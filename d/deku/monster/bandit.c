#include <std.h>
#include "/d/deku/inherits/forest.h"
#define H_RACES ({"werewolf","hag","ettin","giant","gnoll","goblin",\
"kobold","athach","drow","half-drow","goblin","owlbear","bugbear",\
"ogre","ogre-magi","ogre-mage"})

inherit MONSTER;
int camped, attacked, exps;

void create()
{
    ::create();
    set_name("bandit");
    set_id(({"bandit","thief","human"}));
    set_race("human");
    set_short("A human clad with black leather");
    set_long("%^RESET%^This man is of average height and has a frail build. His hair and eyes are dark and unremarkable.  He "+
    "wears a suit of %^BOLD%^%^BLACK%^black leather%^RESET%^ armor that covers a great deal of his body. "+
    "The exposed parts of his flesh are dirty, suggesting that he doesn't care much about keeping himself "+
    "clean, and littered with nicks and scratches, some of which have already began to scab over. "+
    "He carries a short sword in each hand.");    
    set_class(!random(2) ? "thief" : "fighter");
    set_guild_level(query_class(),20);
    set_mlevel(query_class(),query_guild_level(query_class()));
    set("aggressive","stab_them");
    set_alignment(7);
    set_stats("strength",17 + random(2));
    set_stats("intelligence",9);
    set_stats("wisdom",9);
    set_stats("dexterity",15);
    set_stats("charisma",8);
    set_stats("constitution",12);
    set_gender("male");
    set_hp(395 + random(20));
    set_new_exp(20, "normal");
    new("/d/common/obj/weapon/shortsword")->move(TO);
    command("wield sword");
    new("/d/common/obj/weapon/shortsword")->move(TO);
    command("wield sword");
    new("/d/common/obj/armour/leather")->move(TO);
    command("wear leather");
    add_search_path("/cmds/thief");
    add_money("silver",random(400));
    add_money("copper",random(800));
    add_money("gold",800 + random(850));
    set_max_level(25);
    if(is_class("fighter")) 
    {
        set_funcs(({"flash_em"}));
        set_func_chance(25 + random(26));
        add_search_path("/cmds/fighter");
    }
}

void make_camp() 
{
    object ob, ob1;
    if(camped != 1 && !random(2)) {
        camped = 1;
        switch(random(4)) {
            case 0:
                ob = new("/d/common/obj/misc/sack");
                ob1 = new("/std/obj/coins");
                ob1->add_money("gold",200 + random(151));
                ob1->move(ob);
                ob->move(TO);
                break;
            case 1:
                ob = new("/d/common/obj/misc/pouch");
                new("/d/antioch/valley/obj/gem")->move(ob);
                ob->move(TO);
                command("wear pouch");
                break;
            case 2:
                ob = new("/d/common/obj/misc/ssack");
                ob1 = new("/std/obj/coins");
                ob1->add_money("gold",455 + random(551));
                ob1->add_money("electrum",500 + random(81));
                ob1->add_money("silver",600 + random(101));
                ob1->move(ob);
                ob->move(TO);
                break;
            case 3:
                ob = new("/d/common/obj/misc/pouch");
                ob1 = new("/std/obj/coins");
                ob1->add_money("platinum",300 + random(431));
                ob1->move(ob);
                ob->move(TO);
                command("wear pouch");
                break;
        }
    }
    set("aggressive",0);
}

void break_camp() {
    set("aggressive","stab_them");
}

void stab_them() {
    if(!TP->query_invis() && objectp(TP) && attacked != 1) {
        command("say I'll have my share!");
        if(TO->is_class("fighter")) {
            command(!random(2) ? "rush "+TPQN : "kill "+TPQN);
        }
        if(TO->is_class("thief")) {
            command(!random(2) ? "stab "+TPQN : "kill "+TPQN);
            command("kill "+TPQN);
        }
    }
}

void flash_em(object targ) {
    command("flash");
}

void heart_beat() {
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
/*    if((int)TO->query_exp() > exps) {
        FENC->fix_exp(TO,exps);
    }
*/
    if(sizeof(TO->query_current_attackers()) < 1 && attacked == 1) {
        attacked = 0;
        return;
    }
}

void init() {
    string msg;
    ::init();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(TP)) return;
    if(TP->query_invis()) return;
    if(member_array((string)TP->query_race(),H_RACES) != -1) {
        switch(random(4)) {
            case 0: 
                msg = "die ya damned abomination!!";
                break;
            case 1:
                msg = "what the hell are ya doing here??? DIE!";
                break;
            case 2:
                msg = "YA SON OF FILTHY FIEND!!! GET IN THE GROUND!!";
                break;
            case 3:
                msg = "Time fer ya to get outta here!";
                break;
            }
        command("say "+msg);
        if(!objectp(TP)) return;
        command("stab "+TPQN);
        if(!objectp(TP)) return;
        command("kill "+TPQN);
        attacked = 1;
        return;
    }
}