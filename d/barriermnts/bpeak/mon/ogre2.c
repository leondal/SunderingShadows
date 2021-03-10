#include <std.h>
#include "../bpeak.h"

inherit MONSTER;
object obj;

void create()
{
    ::create();
    set_name("Dagdalz");
    set_id(({ "ogre", "Ogre", "ogre warrior", "ugly ogre warrior", "Dagdalz", "dagdalz" }));
    set_short("An especially large and brutish looking ogre");
    set_long("%^RESET%^Long %^BOLD%^%^BLACK%^greasy black hair %^RESET%^falls over"
             " this creatures huanched shoulders.  He wears many stinking %^ORANGE%^skins,"
             " %^RESET%^hiding most of his skin from view.  What is visible though is covered by"
             " large warts that give off their own rancid smell that makes it nearly impossible"
             " to be around him.  He stands nearly ten feet tall and his large muscles further"
             " confirm that he would be no easy target.  His face is always crumpled into a"
             " frown, and his large teeth curve up over his upper lip, nearly touching his"
             " snout-like nose.  This ogre is slightly different than the rest though, instead"
             " of roaming around like the others, he stays constantly near the well for some"
             " odd reason.  His sheer size is impressive, and even by ogre standards he is"
             " large.");
    set_race("ogre");
    set_gender("male");
    set_body_type("human");
    set_overall_ac(-15);
    set_hd(17, 2);
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
    set_exp(5000);
    set_alignment(9);
    add_search_path("/cmds/fighter");
    set_func_chance(20);
    set_funcs(({ "rush", "toss", "pretty" }));
    set("aggressive", 19);
    set_property("full attacks", 1);
    new(OBJD + "trevenge")->move(TO);
    command("wield polearm");
    //obj=new("/d/common/obj/potion/healing");
    //obj->move(TO);
    //obj->set_uses(50);
    set_property("add kits", 25);
}

void rush(object target)
{
    force_me("rush " + target->query_name() + "");
    return 1;
}

void toss(object target)
{
    force_me("speak undercommon");
    force_me("say %^RED%^You will make a good sacrafice to Axlhaina!%^RESET%^");
    if ((random(23) - 5) > target->query_stats("dexterity")) {
        tell_room((ETO), "%^RESET%^%^RED%^The ogre grabs " + target->query_cap_name() + " and visciously hurls " + target->query_objective() + " into the well!", target);
        tell_object(target, "%^RESET%^%^RED%^The ogre grabs you and hurls you into the well!");
        if (!TO->query_ghost()) {
            target->move_player(INRMS + "redge2.c");
        }
    }else {
        tell_room((ETO), "%^RESET%^%^RED%^The ogre grabs " + target->query_cap_name() + " and visciously hurls " + target->query_objective() + " towards the well, but " + target->query_subjective() + " catches " + target->query_objective() + "self on the ledge and climbs back up!", target);
        tell_object(target, "%^RESET%^%^RED%^The ogre grabs you and hurls you towards the well! You catch yourself on the ledge and scramble back up!");
    }
}

void pretty(object target)
{
    if (!present("ring", (TO))) {
        force_me("speak undercommon");
        force_me("say %^BOLD%^%^RED%^Me gots pretty!  Me saved it from Axlhaina!%^RESET%^");
        force_me("emote reaches into his armor and pulls out a band.  With a lopsided grin, he slides it onto his finger.");
        new("/d/azha/obj/mr_ring.c")->move(TO);
        command("wear ring");
        return 1;
    }
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
        force_me("emote 's eyes light up!");
        force_me("say %^RED%^Food for Axlhaina!%^RESET%^");
        force_me("emote grabs the corpse and throws it into the well!");
        obj->move(INRMS + "redge2.c");
        tell_room(find_object_or_load(INRMS + "redge2.c"), "%^BOLD%^%^RED%^A corpse drops through the hole in the ceiling and lands on the floor with a dull thud!%^RESET%^");
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
    if (present("ogre1", environment(TO))) {
        if (sizeof(TO->query_attackers()) == 0) {
            switch (random(100)) {
            case 0:
                force_me("speak undercommon");
                force_me("emote turns to the ogre and raises his club.");
                force_me("say %^RED%^Check the stairway for intruders!  Look over the path and make sure no one is coming!%^RESET%^");
                break;

            case 1..99:
                break;
            }
        }
    }
    if (present("giant", environment(TO))) {
        if (sizeof(TO->query_attackers()) == 0) {
            switch (random(100)) {
            case 0:
                force_me("speak undercommon");
                force_me("emote turns to the giant and nods with an eager expression on his face.");
                force_me("say %^RED%^Me be feeding Axlhaina.  Yes, yes!  Me not been feeding Axlhaina wolfies though, nope.%^RESET%^");
                force_me("emote shakes his head.");
                break;

            case 1..99:
                break;
            }
        }
    }
    if (present("wolf", environment(TO)) && !present("giant", environment(TO))) {
        if (sizeof(TO->query_attackers()) == 0) {
            switch (random(100)) {
            case 0:
                force_me("speak undercommon");
                force_me("emote looks around to make sure no one is looking and then looks at the wolf and rubs his hands together.");
                force_me("say %^RED%^Food for Axlhaina.  Come here wolfie, wolfie, wolfie!%^RESET%^");
                force_me("emote circles around the wolf slowly and then attacks!");
                force_me("kill wolf");
                break;

            case 1..99:
                break;
            }
        }
    }
}
