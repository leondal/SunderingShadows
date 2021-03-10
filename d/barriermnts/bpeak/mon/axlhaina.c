#include <std.h>
#include "../bpeak.h"

inherit MONSTER;
object obj;

void create()
{
    ::create();
    set_name("Axlhaina");
    set_id(({ "ogre", "Ogre", "ogre warrior", "ugly ogre warrior", "Axlhaina" }));
    set_short("A grotesque looking female ogre");
    set_long("%^RESET%^Axlhaina is a grotesque looking female ogre ...even by ogre"
             " standards.  Her long, scraggly %^BOLD%^%^BLACK%^black hair %^RESET%^falls down"
             " around her naked body in tangled masses that are almost equal to"
             " %^BOLD%^%^BLACK%^dreadlocks.  %^RESET%^She is quite obese and roll after roll of"
             " stinking, warty, purplish flesh is all you can make out.  There is no waistline,"
             " there are no breasts, her butt is distinguishable only by the crack that runs"
             " down the middle of it, but you're sorry you ever looked there.  Her face is"
             " smashed into an ever-living frown and her large, %^YELLOW%^yellow,"
             " %^RESET%^tarter covered teeth jut out from her lower jaw and wrap up to her"
             " snout like nose.  Just under her right %^BOLD%^%^BLACK%^beady black eye,"
             " %^RESET%^is a large %^YELLOW%^p%^GREEN%^u%^YELLOW%^s%^GREEN%^s%^RESET%^-filled"
             " wart covered in %^BOLD%^%^BLACK%^long black hairs.  %^RESET%^She wears many"
             " mis-matched items of jewelry and wallows around down here in her hoarde of"
             " stinking furs and leathers.");
    set_race("ogre");
    set_gender("female");
    set_body_type("human");
    set_overall_ac(-15);
    set_hd(20, 2);
    set_size(3);
    set_stats("intelligence", 6);
    set_stats("strength", 18);
    set_stats("wisdom", 10);
    set_stats("dexterity", 13);
    set_stats("constitution", 18);
    set_stats("charisma", 4);
    set_money("gold", random(200));
    set_hp(random(50) + 300);
    set_max_hp(query_hp());
    set_max_level(45);
    set_exp(10000);
    set_alignment(9);
    add_search_path("/cmds/fighter");
    set_func_chance(20);
    set_funcs(({ "rush", "bellyflop" }));
    set("aggressive", 19);
    set_property("full attacks", 1);
    obj = new(OBJD + "basicc");
    obj->move(TO);
    command("wield club");
    obj->set_property("monsterweapon", 1);
    //obj=new("/d/common/obj/potion/healing");
    //obj->move(TO);
    //obj->set_uses(25);
    set_property("add kits", 20);
}

void rush(object target)
{
    force_me("rush " + target->query_name() + "");
    return 1;
}

void bellyflop(object target)
{
    if (!"daemon/saving_d"->saving_throw(target, "paralyzation_poison_death")) {
        tell_room(ETO, "%^RESET%^%^ORANGE%^Axlhaina throws herself at " + target->query_cap_name() + "!%^RESET%^", target);
        tell_object(target, "%^RESET%^%^ORANGE%^Axlhaina leaps into the air and flies towards you, blocking out all light with her emmense body before her stinking flesh makes contact... Wow, you wish you were dead!%^RESET%^");
        target->set_tripped(3, "You are still trying to catch your breath.");
        return roll_dice(2, 10) + 5;

        return 1;
    }
    tell_room(ETO, "%^RESET%^%^ORANGE%^Axlhaina leaps into the air and flies towards " + target->query_cap_name() + ", but misses " + target->query_objective() + "!", target);
    tell_object(target, "%^RESET%^%^ORANGE%^Axlhaina leaps into the air and flies at you, but misses!%^RESET%^");
    return 1;
}

void die(object ob)
{
    tell_room(ETO,
              "%^MAGENTA%^As Axlhaina falls to the ground, the stuff she was hiding behind her large form becomes visible.%^RESET%^");
    switch (random(10)) {
    case 0..3:
        new("/d/antioch/valley/obj/gem.c")->move(ETO);
        new("/d/antioch/valley/obj/gem.c")->move(ETO);
        new("/d/antioch/valley/obj/gem.c")->move(ETO);
        new("/d/antioch/valley/obj/gem.c")->move(ETO);

    case 4..6:
        new("/d/antioch/valley/obj/gem.c")->move(ETO);
        new("/d/antioch/valley/obj/gem.c")->move(ETO);

    case 7..9:
        new("/d/antioch/valley/obj/gem.c")->move(ETO);
        new("/d/antioch/valley/obj/gem.c")->move(ETO);
        break;
    }
    switch (random(10)) {
    case 0:
        new(OBJD + "vinering.c")->move(ETO);
        break;

    case 1..2:
        break;

    case 3..4:
        new(OBJD + "saring.c")->move(ETO);
        break;

    case 5:
        new(OBJD + "pmsring.c")->move(ETO);
        break;

    case 6..7:
        new(OBJD + "searcuff.c")->move(ETO);
        break;

    case 8..9:
        new(OBJD + "rarmband.c")->move(ETO);
        break;
    }
    new(OBJD + "leather.c")->move(ETO);
    ob = new("/d/magic/scroll");
    ob->set_spell(random(3) + 2);
    ob->move(ETO);
    new(OBJD + "goldnugget.c")->move(ETO);
    new(OBJD + "goldnugget.c")->move(ETO);
    :: die(ob);
}

void heart_beat()
{
    object obj;
    ::heart_beat();
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (obj = present("corpse", ETO)) {
        obj == ("corpse");
        force_me("speak undercommon");
        force_me("speech grunt excitedly");
        force_me("emote 's eyes light up as she cackles with delight!");
        force_me("say %^RED%^Food for me belly!%^RESET%^");
        force_me("emote runs over to the corpse and eagerly snatches it up before ripping into its flesh!");
        tell_room(find_object_or_load(INRMS + "tcliff4.c"), "%^BOLD%^%^RED%^A delighted cackle echoes up through the well followed by sickening slurping noises and the sounds of bones snapping.%^RESET%^");
        obj->remove();
    }
    /*if(query_hp()<150  && present("vial",TO)){
       command("open vial");
       command("drink vial");
       command("drink vial");
       command("drink vial");
       command("drink vial");
       command("drink vial");
       command("offer bottle");
       command("offer bottle");
       command("offer bottle");
       command("offer bottle");
       command("offer bottle");
       }*/
    if (sizeof(TO->query_attackers()) == 0) {
        switch (random(100)) {
        case 0:
            force_me("speak undercommon");
            force_me("emote looks up at the light filtering through the hole in the ceiling.");
            force_me("yell %^BLUE%^Dagdalz lets me out you lilly livered sissy!  I promise not to try to breed anymore!%^RESET%^");
            force_me("emote mumbles something and goes back to playing with her jewelry.");
            tell_room(find_object_or_load(INRMS + "tcliff4"), "%^BOLD%^%^BLUE%^A yell can be heard echoing up through the well.");
            if (present("ogre", (find_object_or_load(INRMS + "tcliff4")))) {
                tell_room(find_object_or_load(INRMS + "tcliff4"), "%^RED%^The ogre visibly shudders and nervously looks around before peering down the well and shuddering again.");
            }
            break;

        case 1..99:
            break;
        }
    }
}
