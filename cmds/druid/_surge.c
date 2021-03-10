// surge command for elemental shapeshift.
// to let the player trigger as desired, rather than potentially blocking their spells for a round. N, 8/15.
#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit DAEMON;

int cmd_surge(string str) {
    string myrace, *specials, *active_specials;
    int chance, i, duration;
    object *myattackers, myshape, mytarg;

    if (TP->query_bound() || TP->query_paralyzed()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if(str) return notify_fail("Syntax: <surge>\n");
    if(!TP->query_property("shapeshifted")) return notify_fail("Only an elemental can <surge>.\n");
    if((string)TP->query("relationship_profile") != "druid_elemental_999") return notify_fail("Only an elemental can <surge>.\n");
    if(!objectp(myshape = TP->query_property("shapeshifted"))) return notify_fail("Only an elemental can <surge>.\n");
    if(TP->query_casting()) return notify_fail("You're already casting a spell!\n");

    myattackers = (object*)TP->query_attackers();
    myattackers = distinct_array(myattackers);
    if(!sizeof(myattackers)) return notify_fail("You can only do that in combat!");

    myrace = (string)myshape->query_shape_race();
    chance = (int)TP->query_guild_level("druid");
    if(chance < 15) chance = 15;
    if(chance > 60) chance = 60;

    // picks up one spell of L2, L3 and L4 for each type of elemental (and default). Varies by element.
    // switch falls through intentionally 
    specials = ({});
    active_specials = ({});
    switch(chance) {
        case 35..60: specials += ({ "level 4" });
        case 30..34: specials += ({ "level 3" });
        case 25..29: specials += ({ "level 2" });
        case 20..24: specials += ({ "level 4" });
        case 15..19: specials += ({ "stun slam" });
        case 10..14: specials += ({ "level 3" });
        default:     specials += ({ "level 2"  });
    }

    //////////////
    i=0;
    do {
        active_specials += ({ specials[random(sizeof(specials))] });
        i += 5;
    }
    while(roll_dice(1,100) < (chance - i));
    //////////////

    mytarg = myattackers[random(sizeof(myattackers))];
    TP->set_casting(1);
    for(i=0;i<sizeof(active_specials);i++) {
        if(!objectp(TP) || !objectp(mytarg)) return 0;

        switch(active_specials[i]) {
          case "stun slam":
            if(time() > (int)TP->query_property("druid_trip_timer")) {
                duration = time() + (ROUND_LENGTH * 25);
                TP->set_property("druid_trip_timer",duration);

                tell_object(TP,"%^BOLD%^%^WHITE%^You heave yourself up, before slamming back down into the ground!");
                tell_room(ETP,"%^BOLD%^%^WHITE%^"+TP->QCN+" heaves "+TP->QO+"self up, before slamming back down into the ground!",TP);

                new("/cmds/druid/spells/_earthshaker")->use_spell(TP,0,chance,100,"druid"); break;              
                return 1;
            } // falls through if timer isn't up

        case "level 2":
            tell_object(TP,"%^RED%^You call upon the elements and invoke a spell at "+mytarg->QCN+"!%^RESET%^");
            tell_object(mytarg,"%^RED%^"+TP->QCN+" calls upon the elements and invokes a spell at you!%^RESET%^");
            tell_room(ETP,"%^RED%^"+TP->QCN+" calls upon the elements and invokes a spell at "+mytarg->QCN+"!%^RESET%^",({TP,mytarg}));

            switch(myrace) {
              case "fire elemental": case "earth elemental": new("/cmds/spells/h/_heat_metal")->use_spell(TP,mytarg,chance,100,"druid"); break;
              case "air elemental": case "water elemental": default: new("/cmds/spells/c/_chill_metal")->use_spell(TP,mytarg,chance,100,"druid"); break;
            }
            return 1;

        case "level 3":

            tell_object(TP,"%^CYAN%^You raise an arm and call upon the elements for aid!%^RESET%^");
            tell_room(ETP,"%^CYAN%^"+TP->QCN+" raises an arm and calls upon the elements for aid!%^RESET%^",TP);

            switch(myrace) {
              case "water elemental": case "earth elemental": new("/cmds/spells/q/_quench")->use_spell(TP,mytarg,chance,100,"druid"); break;
              case "fire elemental": case "air elemental": default: new("/cmds/spells/c/_call_lightning")->use_spell(TP,mytarg,chance,100,"druid"); break;
            }
            return 1;

        case "level 4":

            tell_object(TP,"%^GREEN%^You clench your fist and then fling your hand towards "+mytarg->QCN+", striking him with nature's wrath!%^RESET%^");
            tell_object(mytarg,"%^GREEN%^"+TP->QCN+" clenches a fist and then flings "+TP->QP+" hand towards you, striking you with nature's wrath!%^RESET%^");
            tell_room(ETP,"%^GREEN%^"+TP->QCN+" clenches a fist and then flings "+TP->QP+" hand towards "+mytarg->QCN+", striking "+mytarg->QO+" with nature's wrath!%^RESET%^",({TP,mytarg}));

            switch(myrace) {
              case "fire elemental": case "air elemental": new("/cmds/spells/f/_flame_strike")->use_spell(TP,mytarg,chance,100,"druid"); break;
              case "water elemental": case "earth elemental": default: new("/cmds/spells/r/_rusting_grasp")->use_spell(TP,mytarg,chance,100,"druid"); break;
            }
            return 1;
        }
    }
    return 1;
}

void help() {
    if(FEATS_D->usable_feat(TP,"wild shape elemental") || avatarp(TP)) {
        write("Syntax: <surge>\n\n" +
        "Allows a druid in elemental shapeshift to draw upon the energies of the world around them, "
        "and hurl it at one of their foes.  These energies will take shape as one of several lesser "
        "spells familiar to the druid, aligned with the type of elemental they have become.\n");
    }
}