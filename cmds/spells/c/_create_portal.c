//~Circe~ 7/30/05
//This power will allow the psion to open a portal, allowing
//people to travel between two places.
//Ganked for the cleric domain version -Ares
#include <spell.h>
#include <magic.h>

inherit SPELL;

void open_portal();
object endplace;

void create()
{
    ::create();
    set_spell_name("create portal"); // just portal in srds
    set_spell_level((["mage" : 7, "cleric":7]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS create portal on DESTINATION");
    set_description("This power allows the priest to call on the power of his deity to open a portal from his current "
                    "location to any place that he has remembered before.  The portal can not open unless both rooms may be teleported to "
                    "and from.  The portal remains in effect longer for stronger casters.

%^BOLD%^%^RED%^See also:%^RESET%^ remember, unremember, recall");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

string query_cast_string()
{
    tell_object(caster, "%^MAGENTA%^Holding your holy symbol high into " +
                "the air, you begin to focus on a distant location as you chant" +
                " in a rhythmic fashion.");
    tell_room(place, "%^MAGENTA%^" + caster->QCN + " holds " + caster->QP + " holy" +
              " symbol high in the air above " + caster->QP + " head "
              "and begins a rhythmic chant.", caster);
    return "display";
}

void spell_effect(int prof)
{
    string a, file, tempstr, * tempdir;
    int mypower, startpower, endpower, bonus;
    mapping tmp;

    if (!sscanf(arg, "%s", a)) {
        tell_object(caster, "This spell requires a target destination.");
        tell_room(place, caster->QCN + " looks confused.", caster);
        TO->remove();
        return;
    }

    tmp = caster->query_rem_rooms();
    file = tmp[a];

    if (member_array(a, caster->query_rem_rooms_sort()) < 0 || !file || !stringp(file)) {
        tell_object(caster, "You can't remember a place named " + a + ".");
        tell_room(place, caster->QCN + " looks confused.", caster);
        TO->remove();
        return;
    }

    if (file) {
        if (!(endplace = find_object_or_load(file))) {
            file = 0;
        }
    }

    if (endplace && (endplace->query_property("no teleport") || place->query_property("no teleport") || !endplace->is_room())) {
        file = 0;
    }
//teleport proof stuff by ~Circe~ 6/20/08
//new property to be used for areas protected from teleport
//but not foolproof
    if (endplace &&
        (endplace->query_property("teleport proof") ||
         place->query_property("teleport proof") ||
         !endplace->is_room())) {
        startpower = place->query_property("teleport proof");
        endpower = endplace->query_property("teleport proof");
        bonus = caster->query_stats("intelligence");
        bonus = bonus - 10;
        if ((object*)caster->query_attackers() != ({})) {
            mypower = CLEVEL + bonus + random(6);
        }else {
            mypower = CLEVEL + bonus + random(6) + 5;
//making it easier to teleport out if you aren't in combat
        }
        if ((mypower < startpower) || (mypower < endpower)) {
            file = 0;
        }
    }

    if (!file) {
        tell_object(caster, "You sense some sort of interference " +
                    "blocking your way.");
        tell_room(place, caster->QCN + " looks confused.", caster);
        TO->remove();
        return;
    }
    if (endplace->is_flight_room()) {
        tell_object(caster, "You cease your spell-casting as " +
                    "you sense something blocking your magical " +
                    "passage.");
        tell_room(place, caster->QCN + " apparently " +
                  "looks startled.", caster);
        TO->remove();
        return;
    }

    if (place == endplace) {
        tell_object(caster, "The spell does nothing as you try to open a portal "
                    "to where you are standing.");
        tell_room(place, caster->QCN + " looks confused.", caster);
        TO->remove();
        return;
    }
    spell_successful();

    tell_object(caster, "%^BOLD%^%^CYAN%^You feel the power of the weave as the shimmering "
                "outline of a portal begins to appear!");
    tell_room(place, "%^BOLD%^%^CYAN%^" + caster->QCN + "'s chanting grows louder and the shimmering "
              "outline of a portal begins to appear in the air!", caster);
    call_out("do_portal", 3, endplace);
    caster->setAdminBlock();
    return;
}

void do_portal(object endplace)
{
    if (!caster) {
        dest_effect(); return;
    }
    caster->removeAdminBlock();
    if (caster->query_ghost()) {
        dest_effect(); return;
    }

    if (!endplace) {
        tell_object(caster, "%^BOLD%^^%MAGENTA%^You sense some sort of interference " +
                    "blocking your way.");
        tell_room(place, caster->QCN + " looks confused.", caster);
        dest_effect();
        return;
    }
    tell_room(place, "%^MAGENTA%^The image of the portal begins to become "
              "less transparent as it materializes into reality.");
    call_out("do_next", 2 + random(3), endplace);
    return;
}

void do_next(object endplace)
{
    string newplace;
    if (!caster) {
        dest_effect(); return;
    }
    caster->removeAdminBlock();
    if (caster->query_ghost()) {
        dest_effect(); return;
    }

    if (!endplace) {
        tell_object(caster, "You sense some sort of interference " +
                    "blocking your way.");
        tell_room(place, caster->QCN + " looks confused.", caster);
        dest_effect();
        return;
    }
    newplace = endplace->query_short();
    if (!newplace) {
        newplace = "a room";
    }
    tell_room(place, "%^CYAN%^With a sudden flash of light, the portal is completed, "
              "opening to " + newplace + "!");
    open_portal();
    //changing this so if it's dispelled the portal will go away correctly
    //functions much like gate - Saide
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
    return;
}

int open_portal()
{
    int portnum;
    addSpellToCaster();
    tell_room(endplace, "%^BOLD%^%^CYAN%^A shimmering portal opens in the air!");

    if (member_array("portal", place->query_exits()) == -1) {
        place->add_exit(base_name(endplace), "portal");
    }else {
        portnum = 1;
        while (member_array("portal" + portnum, place->query_exits()) != -1) {
            portnum++;
        }
        place->add_exit(base_name(endplace), "portal" + portnum);
        TO->set_property("MyCreatedEnter", "portal" + portnum);
    }

    if (member_array("portal", endplace->query_exits()) == -1) {
        endplace->add_exit(base_name(place), "portal");
    }else {
        portnum = 1;
        while (member_array("portal" + portnum, endplace->query_exits()) != -1) {
            portnum++;
        }
        endplace->add_exit(base_name(place), "portal" + portnum);
        TO->set_property("MyCreatedExit", "portal" + portnum);
    }
    //endplace->add_exit(base_name(place), "portal");
    //place->add_exit(base_name(endplace), "portal");
    return 1;
}

int close_portal()
{
    string CreatedExit;
    if (objectp(endplace)) {
        if (CreatedExit = TO->query_property("MyCreatedExit")) {
            endplace->remove_exit(CreatedExit);
        }else {
            endplace->remove_exit("portal");
        }

        tell_room(endplace, "%^MAGENTA%^The portal shimmers briefly, " +
                  "then closes and fades away.");
    }
    if (objectp(place)) {
        if (CreatedExit = TO->query_property("MyCreatedEnter")) {
            place->remove_exit(CreatedExit);
        }else {
            place->remove_exit("portal");
        }

        tell_room(place, "%^MAGENTA%^The portal shimmers briefly, " +
                  "then closes and fades away.");
    }
    return 1;
}

void dest_effect()
{
    close_portal();
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
