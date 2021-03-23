//Liveoak - summon treant spell for druids
//Coded by ~Circe~ 3/19/13, based on astral construct
// shifted over to innate spell list to remove from druids; they have three solid summons already so this is overkill. N, 10/15.
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int i, v;
object endplace, device;
object tree;

void create() {
    ::create();
    set_spell_name("liveoak");
    set_spell_level(([ "druid" : 7, "oracle":7]));
    set_mystery("nature");
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS liveoak");
    set_description("Upon casting this spell, the druid calls upon her connection with nature to bring forth the magic inherent in an acorn. The druid tosses the acorn to the ground, where it sprouts into a mighty treant to protect her.

To command the treant, simply: <command treant to action>.
If theeant lost you and you wish for it to follow you again: <command treant to follow>");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    return "%^RESET%^%^GREEN%^"+caster->QCN+" tosses an %^ORANGE%^acorn%^GREEN%^ "
        "to the ground and closes "+caster->QP+" eyes.%^RESET%^";
}

int preSpell() {
    if (present("ctreedevicex999",caster)) {
        tell_object(caster,"You can only control one treant at a time!\n");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    mapping tmp;

    if (!objectp(caster)){
        TO->remove();
        return;
    }
    if (objectp(place)) place = environment(caster);
    tell_room(place,"%^RESET%^%^ORANGE%^"+caster->QCN+" holds "+caster->QP+" "
              "hand over the ground, palm down.  A faint %^CYAN%^breeze%^ORANGE%^ "
              "stirs "+caster->QP+" hair as "+caster->QS+" begins to whisper.%^RESET%^", caster);
    tell_object(caster,"%^RESET%^%^ORANGE%^With your eyes firmly closed, you begin "+
                "to whisper an incantation, calling forth the magic in the acorn.%^RESET%^");
    call_out("next_step",10);
}

void next_step() {
    if (!objectp(caster)){
        TO->remove();
        return;
    }
    if (objectp(place)) place = environment(caster);
    tell_room(place,"%^YELLOW%^The acorn on the ground before "+caster->QCN+" "
              "begins to tremble before a %^GREEN%^shoot %^YELLOW%^breaks forth, "
              "seeking the ground.%^RESET%^",caster);
    tell_object(caster,"%^YELLOW%^You feel the magic in the acorn resonate "
                "as you open your eyes and see a %^GREEN%^shoot %^YELLOW%^burst forth "
                "from the shell, seeking the ground.%^RESET%^");
    call_out("step3",5);
}

void step3() {
    object ob;
    if (!objectp(caster)){
        TO->remove();
        return;
    }
    if (objectp(place)) place = environment(caster);
    switch(season(time())){
    case "summer":
        ob = new("/d/magic/mon/treant_summer");
        break;
    case "autumn":
        ob = new("/d/magic/mon/treant_fall");
        break;
    case "winter":
        ob = new("/d/magic/mon/treant_winter");
        break;
    default:
        ob = new("/d/magic/mon/treant_spring");
        break;
    }
    tree = ob;
    ob->set_property("spell",TO);
    ob->set_mylevel(clevel);
    ob->set_property("spelled", ({TO}) );
    ob->set_property("spell_creature", TO);
    ob->set_property("minion", caster);
    ob->set_caster(caster);
    device = new("/d/magic/obj/ctreantholder");
    tell_room(place,"%^BOLD%^%^GREEN%^The ground shakes as the acorn explodes "
              "and a treant bursts forth, towering over "+caster->QCN+"!%^RESET%^",caster);
    tell_object(caster,"%^BOLD%^%^GREEN%^Energy surges from the earth as the acorn "
                "explodes and a treant bursts forth, towering over you!%^RESET%^");
    tell_room(place,"%^RESET%^%^ORANGE%^The treant shudders, and a creak fills the "
              "air as it stretches from roots to crown.  Saucer-sized eyes creak open in the "
              "bark beneath the spreading branches, and a sound like a ponderous sigh "
              "whispers on the wind.%^RESET%^");
    tell_object(caster,"%^YELLOW%^Seeing you, the treant gives a slight bow, "+
                "ready to accept your commands!%^RESET%^");
    tell_room(place,"%^YELLOW%^The treant catches sight "+
              "of "+caster->QCN+" and gives a small bow, awaiting "+caster->QP+" command!",caster);
    device->set_elemental(ob);
	addSpellToCaster();

    device->set_caster(caster);
    caster->add_follower(ob);
    device->move(caster);
    device->set_property("spell",TO);
    device->set_property("spelled", ({TO}) );
    ob->move(place);
}

void dest_effect() {
    if(objectp(tree)){
        tell_room(environment(tree), "%^YELLOW%^The treant shudders and disappears.");
        tree->move("/d/shadowgate/void");
        tree->remove();
    }

    if(objectp(device))
        device->remove();
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
