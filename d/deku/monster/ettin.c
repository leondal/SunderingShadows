#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/forest.h"
inherit MONSTER;

int exps;

void create() 
{
    object ob;
    ::create();
	set_race("ettin");
    set_name("ettin");
    set_id(({"ettin","giant","two headed giant"}));
    set_short("A two headed giant");
    set_long("%^BOLD%^%^WHITE%^This massive creature resembles "+
    "the failed mixture of several other fiends.  Its two large "+
    "and orc like heads are nearly fourteen feet from the "+
    "ground.  The hair on each of them is long, unkept, and "+
    "thinned to the point of existing in nothing more than "+
    "heavily matted strings.  The eyes in either head "+
    "offer an intense glare of anger and hatred to anything "+
    "they look upon.  The mouths of each head reveal rows "+
    "of rotting teeth when they gape open and each offers "+
    "pig like tusks growing up from the bottom corners.  The flesh "+
    "of this beast appears to be an almost crusty gray "+
    "and is accented by an intensely offensive odor that seems "+
    "to continually come forth from and be emitted by it.%^RESET%^");
    set_hd(20,1);
    add_search_path("/cmds/fighter");
    set_body_type("humanoid");
    set_size(4);
    set_hp(450 + random(20));
    //set_exp(2000);
    set_new_exp(15, "normal");
    set_stats("strength",18);
    set_stats("intelligence",6);
    set_stats("wisdom",10);
    set_stats("charisma",11);
    set_stats("constitution",15);
    set_stats("dexterity",8);
    set_alignment(9);
    set("aggressive",27);
    set_property("full attacks",1); 
    set_func_chance(15);
    set_funcs(({"fury"}));
    set_max_level(20);
    set_overall_ac(1 - random(6));
    ob = new("/d/common/obj/weapon/club_lg");
    if(!random(3)) ob->set_property("enchantment",1);
    ob->move(TO);
    command("wield club");
    new("/d/common/obj/weapon/club_lg")->move(TO);
    command("wield club");
    add_attack_bonus(2);
    /*TRCALC->init_treasure_for_area("deku_forest_treasure", 150000,
    5000, 1, TO, 6000, 0);*/
}

void fury(object targ) 
{
    int x, attacks;
    tell_room(ETO,"%^RED%^The ettin bursts into a fit of wild and "+
    "vicious attacks!%^RESET%^");
    attacks = 2 + random(3);
    for(x = 0;x < attacks;x++) 
    {
        tell_room(ETO,"%^RED%^The ettin brutally slams "+
        targ->QCN+" in the head with its large club!%^RESET%^",targ);
        tell_object(targ,"%^RED%^The ettin brutally slams "+
        "you in the head with its large club!%^RESET%^");
        targ->do_damage("head",roll_dice(8,6) + random(6));
        continue;
    }
}

int query_watched() { return 40 + random(71); }