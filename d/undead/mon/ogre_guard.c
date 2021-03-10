#include <std.h>
#include "../undead.h"
inherit CREATURE;

void create()  {
    object ob;
    string *races, *mytypes, thisrace, thistype;
    ::create();
    races = ({ "dwarf","human","human","human","half-elf","half-elf","half-ogre","ogre","half-orc","orc","hobgoblin"});
    mytypes = ({ "rugged","burly","hulking","rough-looking","brawny","scarred"});
    thisrace = races[random(sizeof(races))];
    thistype = mytypes[random(sizeof(mytypes))];
    set_name("city guard");
    set_id(({"guard","city guard"}));
    set_race(thisrace);
    set_body_type("human");
    set_gender("male");
    set_short("a "+thistype+" "+thisrace+" guard");
    set_long("%^RESET%^%^CYAN%^Before you stands one of the creatures hired "
"to guard the remains of this city, a "+thistype+" "+thisrace+".  A little "
"more %^ORANGE%^ragged %^CYAN%^a bunch than would be expected, they are "
"still well armed and armored, and they all look more than %^RED%^dangerous "
"%^CYAN%^in a fight.  You're quite sure such a mismatched group would never "
"have banded together if it were not for the common threat from beyond the "
"city walls.%^RESET%^");
    set_hd(25,0);
    set_class("fighter");
    set_mlevel("fighter",25);
    add_search_path("/cmds/fighter");
    set("aggressive", 0);
    set_alignment(5);
    set_ac(5);
    if(thisrace == "ogre" || thisrace == "half-ogre") set_size(3);
    else set_size(2);
    set_property("swarm", 1);
    set_exp(1);
    set_stats("intelligence",12);
    set_stats("wisdom",12);
    set_stats("strength",16);
    set_stats("charisma",12);
    set_stats("dexterity",14);
    set_stats("constitution",16);
    set_damage_bonus(2);
    set_attack_bonus(2);
    set_hp(600);
    new(OBJS"halberd")->move(TO);
    command("wield halberd");
    if(thisrace == "ogre" || thisrace == "half-ogre") {
      new(CWEAP"handaxe")->move(TO);
      command("wield axe");
    }
    ob = new(CARMOR"chain.c");
    ob->set_property("enchantment",3);
    ob->set_size(TO->query_size());
    ob->move(TO);
    command("wear chain");
    set_funcs(({"rush_targs"}));
    set_func_chance(20);
    add_money("electrum",random(10));
    add_money("silver",random(10));
    add_money("gold",random(5));
    add_money("copper",random(20));
    set_new_exp(25,"normal");
}

void rush_targs(object targ) {
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    command("rush "+targ->QN+"");
    return;
}
