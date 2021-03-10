#include <std.h>

inherit "/d/dagger/cave2/mon/wonder.c";
object ob;

void create() {
    ::create();
    set_name("Demonic Berserker");
    set_id( ({"berserker", "demon", "demonic berserker", "Demonic Berserker", "cavemon"}) );
    set_short("Demonic Berserker");
    set_long(
      "Before you stands one of the feared demonic berserkers.  Once human, he was possessed by demons at one time, and during this time gained many great powers, but was also driven insane.  Now he wanders these caves, looking for demons to kill, or anything else he happens upon."
    );
    set_race("human");
    set_body_type("human");
    set_gender("male");
    set_size(2);
    set_class("ranger");
    set_mlevel("ranger", 19);
    set_class("fighter");
    set_mlevel("fighter", 19);
    set_hd(19,4);
    set_exp(7500);
    set("aggressive", 20);
    set_property("swarm", 1);
    set_property("full_attacks", 1);
    set_stats("strength", 20);
    set_stats("dexterity", 21);
    set_stats("constitution", 17);
    set_stats("charisma", 10);
    set_stats("wisdom", 10);
    set_stats("intelligence", 10);
    set_max_hp(350);
    set_hp(350);
    set_overall_ac(-9);
    set_alignment(5);
    add_money("gold", random(2000)+1000);
    ob = new("/d/dagger/cave2/obj/blacksword.c");
    if(!random(5)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    ob = new("/d/dagger/cave2/obj/blacksword.c");
    if(!random(5)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield sword");
    command("wield sword 2");
    set_funcs(({"berserk"}));
    set_func_chance(40);
    add_search_path("/cmds/fighter");
   if(!random(15)) {
     ob = new("/d/common/obj/brewing/herb_special_inherit");
     ob->set_herb_name("patch of demonskin");
     ob->move(TO);
   }
   if(!random(15)) {
     ob = new("/d/common/obj/brewing/herb_special_inherit");
     ob->set_herb_name("patch of demonskin");
     ob->move(TO);
   }
}

void berserk(object targ) {
    int i;

    tell_object(targ, "%^YELLOW%^The berserker suddenly looks at you and charges you, screaming at the top of his lungs!!!\n\n");
    tell_room(ETO, "%^YELLOW%^The berserker suddenly lets out a bloodcurdling scream, and rushes at "+targ->query_cap_name()+"!!!", targ);

    call_out("force_me",2,"rush "+targ->query_name());

    for(i=0;i<1+random(8);i++){
      tell_object(targ, "%^YELLOW%^The berserker strikes you in your "+targ->return_target_limb()+"!!\n");
      targ->do_damage(targ->return_target_limb(), random(10)+5);
    }
    tell_room(ETO, "%^YELLOW%^The berserker executes a series of lightning attacks on "+targ->query_cap_name()+"!!", targ);
}
