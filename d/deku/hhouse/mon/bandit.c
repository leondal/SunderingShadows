#include <std.h>
#include "../inherits/area_stuff.h"

inherit MONSTER;
int attacked;

void create()
{
    object ob;
    ::create();
    set_name("bandit");
    set_id(({"bandit","thief","human"}));
    set_race("human");
    set_short("A human clad with black leather");
    set_long("%^RESET%^This man is of average height and has a "+
    "frail build.  His hair and eyes "+
    "are dark and unremarkable.  He wears a suit of %^BOLD%^%^BLACK%^black "+
    "leather%^RESET%^ "+
    "armor that covers a great deal of his body.  "+
    "The exposed parts of his flesh are dirty, "+
    "suggesting that he doesn't care much about keeping himself "+
    "clean, and	littered with "+
    "nicks and scratches, some of which have already "+
    "began to scab over.  He carries a "+
    "short sword in each hand.");
    set_class(!random(2) ? "thief" : "fighter");
    set_guild_level(query_class(),34);
    set_mlevel(query_class(),query_guild_level(query_class()));
    set("aggressive","kill_em");
    set_alignment(7);
    set_stats("strength",19);
    set_stats("intelligence",9);
    set_stats("wisdom",9);
    set_stats("dexterity",20);
    set_stats("charisma",8);
    set_stats("constitution",12);
    if(!random(2)) set_invis();
    set_gender("male");
    set_hp(375 + random(226));
    set_new_exp(28, "normal");
    ob = new("/d/common/obj/weapon/shortsword");
    ob->set_property("enchantment", 3);
    ob->move(TO);
    command("wield sword");
    ob = new("/d/common/obj/weapon/shortsword");
    ob->set_property("enchantment", 3);
    ob->move(TO);

    command("wield sword");
    ob = new("/d/common/obj/armour/leather");
    ob->set_property("enchantment", 3);
    ob->move(TO);
    command("wear leather");
    add_search_path("/cmds/thief");

    add_money("gold",475 + random(450));

    add_attack_bonus(4 + random(6));
    set_funcs(({"flash_em"}));
    set_func_chance(25 + random(26));
    add_search_path("/cmds/fighter");
    set_property("full attacks", 1);
    set_moving(1);
    set_speed(45);
    set_nogo(({FFROOMS+"iw20", BROOMS+"rr1", BROOMS+"rr2", BROOMS+"rr3", RROOMS+"3"}));
}

void stab_them()
{
    if(!objectp(TO)) return;
    if(!objectp(TP)) return;
    if(!TP->query_invis() && objectp(TP) && attacked != 1)
    {
        command("say I'll have my share!");
        if(TO->is_class("fighter"))
        {
            command(!random(2) ? "rush "+TPQN : "kill "+TPQN);
        }
        if(TO->is_class("thief"))
        {
            command(!random(2) ? "stab "+TPQN : "kill "+TPQN);
            command("kill "+TPQN);
        }
    }
}

void flash_em(object targ)
{
    command("flash");
}

void heart_beat()
{
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(sizeof(TO->query_current_attackers()) < 1 && attacked == 1)
    {
        attacked = 0;
        return;
    }
}

void kill_em()
{
    string msg;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(TP)) return;
    if(!TP->is_player()) return;
    if(strsrch(base_name(TP), HHMON) != -1) return;
    if(TP->query_invis()) return;
    if(attacked) return;
    switch(random(4))
    {
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
