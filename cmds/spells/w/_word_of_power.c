#include <priest.h>
inherit SPELL;

#define ACTIVETEMPLES ({ "jarmila", "kreysneothosies", "cevahir", "lord shadow", "lysara", "the faceless one", "callamir", "kismet", "nilith", "nimnavanon", "seija","khyron"})

void create()
{
    ::create();
    set_spell_name("word of power");
    set_spell_level(([ "cleric" : 6, "inquisitor" : 2, "druid" : 6, "paladin" : 2]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS word of power [to DESTINATION]");
    set_description("Word of power will teleport you to a church of your choice.  For now, you can reach the following churches:

Antioch
Asgard (Laerad)
Azha
Dallyh
Eldebaro (East Oasis)
Graez (Sangri)
Ice
Juran
Kinaro
Lothwaite
Muul'daan
Nurval
Seneca (Attaya)
Shadow
Tabor
Tharis
Tonovi
Torm
Verbobone (Deku)

You can also go to the temple of your deity by using 'temple' as the location.
");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_peace_needed(1);
    set_helpful_spell(1);
}

void spell_effect(int prof)
{
    string arg, where, placename, mygod;
    int mypower, startpower, endpower, bonus;

    arg = lower_case(ARG);
    tell_object(CASTER, "You reach your hands out and wave them in strange motions.");
    tell_room(PLACE, YOU + " reaches out and waves " + MINE + " arms in strange motions.", ({ CASTER }));
    switch (arg) {
    case "shadow":
        where = "/d/shadow/city/room/church";
        placename = "Shadow";
        break;
    case "dallyh":
    case "amazons":
        where = "/d/islands/dallyh/forest/rooms/church";
    placename = "Dallyh";
    break;
    case "tharis":
        where = "/d/tharis/newtharis/rooms/tharis_church1.c";
        placename = "Tharis";
        break;
    case "azha":
        where = "/d/azha/town/church";
        placename = "Azha";
        break;
    case "kinaro":
        where = "/d/dagger/kinaro/church";
        placename = "Kinaro";
        break;
    case "lothwaite":
        where = "/d/barriermnts/lothwaite/rooms/chapel5";
        placename = "Lothwaite";
        break;
    case "seneca":
        where = "/d/attaya/newseneca/rooms/cath_nave";
        placename = "Seneca";
        break;
    case "graez":
    case "sangri":
        where = "/d/undead/rooms/town/church1";
    placename = "Graez";
    break;
    case "asgard":
        where = "/d/laerad/parnelli/asgard/as72";
        placename = "Asgard";
        break;
    case "antioch":
        where = "/d/antioch/wild/forest/chapel_out";
        placename = "Antioch";
        break;
    case "juran":
        where = "/d/shadow/juran/city/church";
        placename = "Juran";
        break;
    case "deku":
    case "verbobone":
        where = "/d/deku/town/church";
    placename = "Verbobone";
    break;
    case "tonovi":
        where = "/d/dagger/tonovi/town/temple1.c";
        placename = "Tonovi";
        break;
    case "nurval":
        where = "/d/dagger/nurval/room/shrine";
        placename = "Nurval";
        break;
    case "eldebaro":
        placename = "Eldebaro";
        where = "/d/islands/common/eldebaro/newrooms/church";
        break;
    case "torm":
        where = "/d/dagger/Torm/city/c101b.c";
        placename = "Torm";
        break;
    case "tabor":
        where = "/d/darkwood/tabor/room/church";
        placename = "Tabor";
        break;
    case "muuldaan":
    case "muul'daan":
        where = "/d/shadow/room/muuldaan/rooms/church";
    placename = "Muul'daan";
    break;
    case "ice":
        where = "/d/islands/elf/church";
    placename = "ice";
    break;
    case "temple":
        mygod = (string)CASTER->query_diety();
        if (member_array(mygod, ACTIVETEMPLES) != -1) {
            placename = "the Temple of " + capitalize(mygod);
            mygod = replace_string(mygod, " ", "_");
            where = "/d/magic/temples/" + mygod + "/" + mygod;
            break;
        } else {
            where = "/d/darkwood/room/road18";
            placename = "Shadow";
            break;
        }
    default:
        where = "/d/darkwood/room/road18";
        placename = "Shadow";
        break;
    }

    if (!objectp(find_object_or_load(where))) {
        tell_object(caster, "Nothing happens.");
        dest_effect();
        return;
    }

    if (environment(caster)->query_property("no teleport") ||
        where->query_property("no teleport")) {
        tell_object(caster, "Nothing happens.");
        dest_effect();
        return;
    }
    if (where &&
        (where->query_property("teleport proof") ||
         place->query_property("teleport proof") ||
         !where->is_room())) {
        startpower = place->query_property("teleport proof");
        endpower = where->query_property("teleport proof");
        bonus = caster->query_stats("wisdom");
        bonus = bonus - 10;
        if ((object*)caster->query_attackers() != ({})) {
            mypower = CLEVEL + bonus + random(6);
        }else {
            mypower = CLEVEL + bonus + random(6) + 5;
        }
        if ((mypower < startpower) || (mypower < endpower)) {
            tell_object(CASTER, "Nothing happens.");
            dest_effect();
            return;
        }
    }

    caster->clear_followers();

    tell_object(CASTER, "You are magically transported to the church in " + placename + ".");
    find_object_or_load(where)->set_property("recent teleport", place);
    place->set_property("recent teleport", find_object_or_load(where));
    CASTER->move_player(where);

    CASTER->set_casting(0);
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
