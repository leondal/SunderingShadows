//I reduced the chance of some things dropping since there are multiple places for
//the demon to spawn now.  This was based on feedback from several players and
//a few bug reports about the number of items dropping.  Circe 12/21/03
#include <std.h>
#include "../ruins.h"
inherit MONSTER;

string OBJ1, OBJ2, OBJ3;
int y, w, z, j, FLAG;

void create()
{
    object ob;
    ::create();
    set_name("Vakloshx");
    set_short("Vakloshx, a greater demon");
    set_id(({ "vakloshx", "Vakloshx", "demon", "greater demon" }));
    set_long(
        "Vakloshx is a greater demon from the nine hells, and he looks quite" +
        " angry right now. He stands nine feet tall and weighs several hundred" +
        " pounds. Dark red skin stretches over his muscled body and two white" +
        " horns are on his forehead. He is mostly humanoid in appearance, and has" +
        " two large black wings on his back. His hands and feet are massive claws" +
        " and his teeth are razor sharp spikes. A black forked tongue snakes out" +
        " of his mouth from time to time, and his yellow eyes watch you carefully." +
        " He is wearing some leather armor and large boots, with a wickedly spiked" +
        " mace in one hand."
        );
    set_gender("male");
    set_race("demon");
    set_hd(35, 50);
    set_max_hp(1200 + random(150));
    set_hp(query_max_hp());
    set_alignment(9);
    set_body_type("humanoid");
    set_size(2);
    add_limb("right wing", "torso", 0, 0, 0);
    add_limb("left wing", "torso", 0, 0, 0);
    set_overall_ac(-20);
    set_class("ranger");
    set_mlevel("ranger", 35);
    set_class("mage");
    set_mlevel("mage", 35);
    set_level(35);
    set_property("full attacks", 1);
    set_property("swarm", 1);
    set_mob_magic_resistance("average");
    set_property("magic", 1);
    set_property("no hold", 1);
    set_property("no paralyze", 1);
    set_property("no bows", 1);
    set_exp(50000);
    set_funcs(({ "stomp" }));
    set_func_chance(20);
    set_spells(({
        "ice storm",
        "fireball",
        "chain lightning",
        "meteor swarm",
    }));
    set_spell_chance(20);
    new(OBJ + "nightbringer")->move(TO);
    command("wield nightbringer");
    call_out("dress_me", 0);
    command("speech boom");
    ob = new("/d/common/obj/brewing/herb_special_inherit");
    ob->set_herb_name("patch of demonskin");
    ob->move(TO);
}

int dress_me()
{
    object obj;

    switch (random(90)) {
    case 0..20:
        OBJ1 = OBJ + "demon_boots";
        break;

    case 21..40:
        OBJ1 = OBJ + "doom_bracers";
        break;

    case 41..60:
        OBJ1 = OBJ + "gloves";
        obj = new(OBJ + "darkbracelets");
        //if(!random(6)) { obj->set_property("monsterweapon",1); }
        obj->move(TO);
        break;

    case 61..70:
        OBJ1 = OBJ + "ebony_armor";
        break;

    case 71..80:
        OBJ1 = OBJ + "starlight_sword";
        y = 1;
        break;

    case 81..90:
        OBJ1 = OBJ + "nightbringer";
        w = 1;
        break;
    }
    new(OBJ1)->move(TO);
    if (!random(6)) {
        OBJ1->set_property("monsterweapon", 1);
    }
    if (y == 1) {
        command("wield sword");
    }
    if (w == 1) {
        command("wield mace");
    }
    if (!random(3)) {
        call_out("dress_me2", 0);
        return 1;
    }
    command("wearall");
    if (!present("nightbringer 2") || !present("sword of starlight")) {
        obj = new(OBJ + "nightbringer");
        obj->move(TO);
        force_me("wield nightbringer");
        obj->set_property("monsterweapon", 1);
        return 1;
    }
    return 1;
}

int dress_me2()
{
    object obj;

    switch (random(31)) {
// This was 50. I don't know why, when you've only got cases up to 30...
// I changed it to 31.
    case 0..10:
        OBJ2 = OBJ + "ebony_armor";
        break;

    case 11..20:
        OBJ2 = OBJ + "starlight_sword";
        j = 1;
        break;

    case 21..30:
        OBJ2 = OBJ + "nightbringer";
        z = 1;
        break;
    }
    if (OBJ1 == OBJ2) {
        call_out("dress_me2", 1);
        return 1;
    }
    new(OBJ2)->move(TO);
    if (!random(10)) {
        OBJ2->set_property("monsterweapon", 1);
    }
    if (j == 1) {
        command("wield sword");
    }
    if (z == 1) {
        command("wield mace");
    }
    if (!random(6)) {
        call_out("dress_me3", 0);
        return 1;
    }
    command("wearall");
    if (!present("nightbringer 2") || !present("sword of starlight")) {
        obj = new(OBJ + "nightbringer");
        obj->move(TO);
        force_me("wield nightbringer");
        obj->set_property("monsterweapon", 1);
        return 1;
    }
    return 1;
}

int dress_me3()
{
    object obj;

    switch (random(30)) {
    case 0..10:
        OBJ3 = OBJ + "gloves";
        obj = new(OBJ + "darkbracelets");
        //if(!random(6)) { obj->set_property("monsterweapon",1); }
        obj->move(TO);
        break;

    case 11..20:
        OBJ3 = OBJ + "demon_boots";
        break;

    case 21..30:
        OBJ3 = OBJ + "doom_bracers";
        break;
    }
    if (OBJ3 == OBJ1) {
        call_out("dress_me3", 0);
        return 1;
    }else {
        new(OBJ3)->move(TO);
        command("wearall");
        return 1;
    }
}

void heart_beat()
{
    object ob, demon;

    ::heart_beat();
// added objectp check per Saide's testing *Styx*  11/14/03, last change 5/21/02
// also adding check for ETO so the master object doesn't bug from not being in one
    if (!objectp(TO) || !objectp(ETO)) {
        return;
    }
    if (!present("corpse", ETO)) {
        return;
    }
    ob = present("corpse", ETO);
    if (FLAG == 1) {
        return;
    }else if (ob->get_was_user()) {
        tell_room(ETO, "%^BOLD%^%^BLACK%^Vakloshx uses the energy of the death to" +
                  " call forth a fearsome demon!");
        call_out("shadow_demon", 0, TO);
        FLAG = 1;
    }else {
        tell_room(ETO, "%^BLUE%^The demon waves his hand and seems to draw" +
                  " energy from the corpse as it crumbles to dust.");
        ob->remove();
        if (!TO->heal(150)) {
            call_out("energy_ball", 1, TO);
        }else {
            TO->heal(100 + random(50));
        }
    }
}

void init()
{
    ::init();

    if (TP->query_true_invis()) {
        return;
    }

    force_me("watch");
    if (TP->query_invis() && !avatarp(TP) && TP->query_level() > 10) {
        tell_object(TP, "The demon cackles as he stares right at you.");
        TO->force_me("kill " + TP->query_name() + "");
    }else if (!TP->query_invis() && interactive(TP) && TP->query_level() > 10) {
        tell_object(TP, "%^MAGENTA%^Vakloshx roars in a thunderous voice%^RESET%^:" +
                    " It is time to die, mortal!");
        TO->force_me("kill " + TP->query_name() + "");
    }else if (!TP->query_invis() && interactive(TP) && TP->query_level() < 11) {
        tell_object(TP, "Vakloshx sneers at you in contempt.\n" +
                    "%^MAGENTA%^Vakloshx roars in a thunderous voice%^RESET%^: I will not" +
                    " waste my time on one as pathetic as you.");
    }
    //if(TP->id("horse")) { // trying to be more friendly to horses
    //	tell_room(ETO,"The horse gives out a shrill whinny and then keels over"+
    //	" dead.");
    //	TP->die(TO);
    //}
    if (!objectp(TP)) {
        return;
    }
    if (TP->id("animated_object")) {
        tell_room(ETO, "The objects fall apart!");
        TP->die(TO);
    }
}

void stomp(object targ)
{
    int i, j;
    object* inven;
    inven = all_living(ETO);
    j = sizeof(inven);

    for (i = 0; i < j; i++) {
        if (!objectp(inven[i])) {
            continue;
        }
        if (inven[i] == TO) {
            continue;
        }
        if (!"daemon/saving_d"->saving_throw(inven[i], "paralyzation_poison_death", -6)) {
            tell_object(inven[i], "%^RED%^The demon stomps on the ground!\n" +
                        "The ground rises up in a wave, knocking you off of your feet!");
            inven[i]->do_damage("torso", random(10) + 30);
            inven[i]->set_tripped(1, "You're still recovering from" +
                                  " being thrown to the ground.");
        }else {
            tell_object(inven[i], "%^GREEN%^The demon stomps on the ground and" +
                        " you can barely stay on your feet as the earth rises in a wave" +
                        " beneath you.");
        }
    }
}

void energy_ball()
{
    int i, j;
    object* inven;
    inven = all_living(ETO);
    j = sizeof(inven);

    for (i = 0; i < j; i++) {
        if (!objectp(inven[i])) {
            continue;
        }
        if (inven[i] == TO) {
            continue;
        }
        if (!"daemon/saving_d"->saving_throw(inven[i], "spell", -7)) {
            tell_object(inven[i], "%^YELLOW%^Vakloshx hurls the dark energy at" +
                        " you!");
            inven[i]->do_damage("torso", random(20) + 20);
            return;
        }else {
            tell_object(inven[i], "%^YELLOW%^Vakloshx hurls the dark energy at" +
                        " you, but you resist its magic.");
            return;
        }
    }
}

void die(object ob)
{
    force_me("yell NOOOOOOOOOOOOOO!!!!!!");
    force_me("say You may have banished me for a time, mortals," +
             " but you have not vanquished me!");
    force_me("speech scream");
    force_me("say I WILL RETURN!");
    tell_room(ETO, "A black smoke rises up from the body and" +
              " dissipates into the air.");
    new(OBJ + "stone_heart")->move(TO);
    ::die(ob);
}

void shadow_demon()
{
    object ob, demon;

    new(MONS + "shadow_demon")->move(ETO);
    demon = present("shadow demon", ETO);
    demon->set("aggressive", 20);
    demon->force_me("get all from corpse");
    ob = present("corpse", ETO);
    ob->remove();
    call_out("reset_flag", 5, TO);
    return;
}

void reset_flag()
{
    FLAG = 0;
}
