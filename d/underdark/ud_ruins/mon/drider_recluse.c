#include <std.h>
#include "../ud_ruins.h"

inherit MONSTER;

void create() {
    object eq;
    ::create();
    set_name("Drider Recluse");
    set_id(({"drider","recluse","drider_recluse","drider recluse","aberration"}));
    set_short(
        "%^RESET%^"
        "%^ORANGE%^a %^BOLD%^%^BLACK%^disheveled %^RESET%^%^ORANGE%^and "
        "%^BOLD%^wild-looking "
        "%^RESET%^%^MAGENTA%^d%^BOLD%^%^RED%^r%^BLACK%^i%^RESET%^%^MAGENTA%^d"
        "%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^r%^WHITE%^"
    );
    set_long(
        "%^BOLD%^%^RED%^This is a bizarre creature with the upper body of a "
        "%^RESET%^%^MAGENTA%^drow%^BOLD%^%^RED%^, but the lower body of a "
        "%^BLACK%^giant black spider%^RED%^, this particular drider looks even"
        "more savage than others of its kind. His heavily-muscled torso is "
        "entirely bare, and covered in %^RESET%^%^ORANGE%^scars "
        "%^BOLD%^%^RED%^and strange %^RESET%^%^RED%^blood-red tattoos%^BOLD%^. "
        "Long, %^WHITE%^w%^RESET%^i%^BOLD%^s%^RESET%^p%^BOLD%^y "
        "w%^RESET%^h%^BOLD%^i%^RESET%^t%^BOLD%^e h%^RESET%^a%^BOLD%^ir "
        "%^RED%^obscures his face almost in its entirety, but two " "%^RESET%^%^RED%^gl%^BOLD%^o%^WHITE%^w%^RED%^i%^RESET%^%^RED%^ng red "
        "eyes %^BOLD%^burn unmistakably as they look out at their surroundings."
        "%^RESET%^"
    );
    set_race("drider");
    set_body_type("arachnid");
    //The following limb functions are located in /std/living/body.c :-)
    //these SHOULD remove the pincers
    remove_limb("left pincer");
    remove_limb("right pincer");
    //I am not a limb specialist :P but I think it's basically that one limb
    //needs to be connected to another - so in this case lets make right/left arm, connected to torso
    //then the hands connected to the arms - you may dig deeper in /std/living/body.c if needed.
    add_limb("right arm","torso",0,0,0);
    add_limb("left arm","torso",0,0,0);
    add_limb("right hand", "right arm", 0, 0, 0);
    add_limb("left hand", "left arm", 0, 0, 0);
    //add_limb("right hand","right pincer",0,0,0);
    //add_limb("left hand","left pincer",0,0,0);
    set_attack_limbs(({"right hand","left hand"}));
    set_wielding_limbs(({"right hand","left hand"}));
    set_hd(25,16);
    set_class("barbarian");
    set_mlevel("barbarian",25);
    set_guild_level("barbarian",25);
    add_search_path("/cmds/barbarian");
    set_all_stats(({24,20,28,14,16,10}));
    set_alignment(9);
    set_gender("male");
    set_size(2);
    set_property("swarm",1);
    set_exp(15000);
    set_overall_ac(-10);
    set_max_hp(700+random(301));
    set_hp(query_max_hp());
    set_property("full attacks",1);
    set_damage(2,6);
    set_property("no knockdown", 1);
    set_property("no paralyze", 1);
    set_property("no web", 1);
    set_property("no poison", 1);
    set_property("no dominate", 1);
    set_property("no bows", 1);
    set_mob_magic_resistance("average");
    set_property("no random treasure", 1);
    set("aggressive","aggfunc");
    eq = new(OBJ"greater_drider_whip");
    eq->set_property("monsterweapon",1);
    eq->move(TO);
    eq = new("/d/common/obj/potion/advanced_heal");
    eq->set_uses(10);
    eq->move(TO);
    command("wield whip");
    set_monster_feats(({"rage","greater rage","mighty rage"}));
}

int aggfunc(object target) {
    if(!query_property("raging")){
        force_me("rage on");
    }
    force_me("kill "+TP->query_name());
    return 1;
}

void die(object ob) {
    if(!random(3)) {
        new(OBJ"greater_drider_whip")->move(TO);
    }
    if(!random(3)) {
        new(OBJ"mushroom_staff")->move(TO);
    }
    if(!random(3)) {
        new(OBJ"chime_of_opening")->move(TO);
    }

    //::die();
    //Q, make sure that you do ::die(ob)
    return ::die(ob);
}

void heart_beat()
{
    //this is important - otherwise heart beat stuff that
    //happens by default will be skipped - Saide
    ::heart_beat();
    //ALWAYS have the following check or stuff will break :P even if it doesn't always break, it will when it's most inconvenient :P
    if(!objectp(TO)) return;
    if(query_hp() < query_max_hp() / 3) {
        force_me("drink rose");
        force_me("drink rose");
        force_me("drink rose");
        force_me("drink rose");
    }
}
