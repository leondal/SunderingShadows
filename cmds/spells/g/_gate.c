#include <std.h>
#include <daemons.h>
#include <party.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

string purpose;
object endplace, beastie;
void do_summons();
void do_travel(string destination);

void create()
{
    ::create();
    set_author("nienne");
    set_spell_name("gate");
    set_spell_level(([ "mage" : 9, "cleric" : 9 ]));
    set_domains(({"good", "travel"}));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS gate on summoning
        cast CLASS gate on travel | LOCATION");
    set_description("The spell of gate is only available to the most skilled of conjurers, and holds twofold uses to its casting.

The first is the use of the conjured portal as a means of transit, both for the caster and his allies, to a specified location previously memorized.

The second is the use of the portal to draw forth a powerful planar creature under the control of the caster, to act as a servant and/or a protector. This is a greater summons, and cannot be used simultaneously with other greater summons. You can give it weapons and equipment if you wish so, outsider will bring them back from outer planes.
To command outsider, use %^ORANGE%^<command outsider to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^.
To make lost outsider to follow you, %^ORANGE%^<command outsider to follow>%^RESET%^.
To dismiss outsider, %^ORANGE%^<dismiss outsider>%^RESET%^.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_components(([
      "mage" : ([ "crushed black pearl" : 1, ]),
    ]));
    set_helpful_spell(1);
}

string query_cast_string()
{
	return "%^GREEN%^"+caster->QCN+
	" steps forward and commences the first short-clipped syllables of a spell.";
}

int preSpell()
{
    string destination;
    if(arg == "summoning" && (caster->query_property("has_elemental") || caster->query_property("mages_sword")))
    {
        tell_object(caster,"You already have a powerful summoned creature under your control.");
        return 0;
    }
    if (sscanf(arg,"%s | %s",purpose,destination) != 2 && arg != "summoning")
    {
        tell_object(caster, "Syntax: cast mage gate on summoning OR \n\t"+
        "cast mage gate on travel | location");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    string destination;
    if (!objectp(caster))
    {
        TO->remove();
        return;
    }
    arg = lower_case(arg);
    if(arg == "summoning")
    {
        do_summons();
        return;
    }
    if (sscanf(arg,"%s | %s",purpose,destination) == 2)
    {
        if(purpose == "travel")
        {
            do_travel(destination);
            return;
        }
    }
    tell_object(caster, "Syntax: cast mage gate on summoning OR \n\t"+
    "cast mage gate on travel | location");
    TO->remove();
    return;
}

void do_summons()
{
    if (!objectp(caster))
    {
        TO->remove();
        return;
    }
    if (environment(caster) != place)
    {
        tell_object(caster,"Your movement causes the spellcasting to fail.");
        tell_room(place,caster->QCN+" stops casting and looks a little disoriented.",caster);
        TO->remove();
        return;
    }
    tell_object(caster,"%^BOLD%^%^GREEN%^You swirl your arms "+
    "before you, conjuring forth a planar gate.  Tendrils of mist "+
    "trail after the motion of your hands as the magic takes effect.%^RESET%^");

    tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" swirls "+caster->QP+
    " arms before "+caster->QO+", and traces of "+
    "mist follow the motion of "+caster->QP+" hands.%^RESET%^",caster);

    call_out("do_summons_2",ROUND_LENGTH);
}

void do_summons_2()
{
    int myalign, beastalign;
    object device;
    if (!objectp(caster))
    {
        TO->remove();
        return;
    }
    if (environment(caster) != place)
    {
        tell_object(caster,"Your movement causes the spellcasting to fail.");
        tell_room(place,caster->QCN+" stops casting and looks a little disoriented.",caster);
        TO->remove();
        return;
    }

    tell_room(place,"%^BOLD%^%^GREEN%^The mists whorl faster and "+
    "faster of their own accord. Finally they shimmer into "+
    "being as an ovoid portal within the air, and from within "+
    "steps a creature from beyond...%^RESET%^");

    beastalign = caster->query_alignment();//query_true_align to diasllow them to mask intentions
    beastie = new("/d/magic/mon/outsider");

    beastie->set_static_bab(clevel);
    beastie->set_property("spelled", ({TO}));
    device = new("/d/magic/obj/gateholder");
    device->set_property("spell", TO);
    device->set_elemental(beastie);
    device->set_caster(caster);
    caster->add_follower(beastie);
    device->move(caster);
    beastie->set_property("spell_creature", TO);
    beastie->set_property("spell", TO);
    beastie->set_property("minion", caster);
    beastie->move(place);
    beastie->setup_beastie(caster,beastalign);
    beastie->set_caster(caster);
    beastie->set_mylevel(clevel);

    caster->set_property("has_elemental",1);
    addSpellToCaster();
}

void do_travel(string destination)
{
    string file;
    mapping tmp;
    if (!objectp(caster))
    {
        TO->remove();
        return;
    }
    if (environment(caster) != place)
    {
        tell_object(caster,"Your movement causes the spellcasting to fail.");
        tell_room(place,caster->QCN+" stops casting and looks a little disoriented.",caster);
        TO->remove();
        return;
    }

    if(member_array(destination,caster->query_rem_rooms_sort()) == -1)
    {
        tell_object(caster,"Your spell fizzles harmlessly as "+
        "you realize you can't remember a place like "+destination+".");

        tell_room(place,caster->QCN+" stops casting and looks a little disoriented.",caster);
        TO->remove();
        return;
    }

    tmp = caster->query_rem_rooms();
    file = tmp[destination];

    if(!file || !stringp(file))
    {
        tell_object(caster,"Your spell fizzles harmlessly as you "+
        "realize you can't remember a place like "+destination+".");

        tell_room(place,caster->QCN+" stops casting and looks a little disoriented.",caster);
        TO->remove();
        return;
    }
    tell_object(caster,"%^BOLD%^%^GREEN%^You swirl your arms before "+
    "you, conjuring forth a planar gate.  Tendrils of mist "+
    "trail after the motion of your hands as the magic takes effect.%^RESET%^");

    tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" swirls "+caster->QP+
    " arms before "+caster->QO+", and traces of "+
    "mist follow the motion of "+caster->QP+" hands.%^RESET%^",caster);

    call_out("do_travel_2",ROUND_LENGTH,file);
}

void do_travel_2(string file)
{
    int mypower, startpower, endpower, bonus, portnum;
    if (!objectp(caster))
    {
        TO->remove();
        return;
    }
    if (environment(caster) != place)
    {
        tell_object(caster,"Your movement causes the spellcasting to fail.");
        tell_room(place,caster->QCN+" stops casting and looks a little disoriented.",caster);
        TO->remove();
        return;
    }
    if(file)
    {
        if(!(endplace = find_object_or_load(file))) file = 0;
    }
    if(endplace && (endplace->query_property("no teleport") ||
    place->query_property("no teleport") ||
    !endplace->is_room())) file = 0;

    if(endplace && (endplace->query_property("teleport proof") ||
    place->query_property("teleport proof")))
    {
        startpower = place->query_property("teleport proof");
        endpower = endplace->query_property("teleport proof");
        bonus = caster->query_stats("intelligence");
        bonus = bonus -10;
        if(sizeof(caster->query_attackers())) mypower = clevel + bonus + random(6);
        else mypower = clevel + bonus + random(6) + 5;
        if((mypower < startpower) || (mypower < endpower)) file = 0;
    }

    if(!file || endplace->is_flight_room())
    {
        tell_object(caster,"Something interferes with the conjuration "+
        "of the gate, and your spell fizzles.");
        tell_room(place,caster->QCN+" stops casting and looks a little disoriented.",caster);
        TO->remove();
        return;
    }

    tell_room(place,"%^BOLD%^%^GREEN%^The mists whorl faster and "+
    "faster of their own accord. Finally they shimmer into "+
    "being as an ovoid portal within the air, offering travel to another place.%^RESET%^");

    if(member_array("portal", place->query_exits()) == -1)
    {
        place->add_exit(file,"portal");
    }
    else
    {
        portnum = 1;
        while(member_array("portal"+portnum, place->query_exits()) != -1)
        {
            portnum++;
        }
        place->add_exit(file, "portal"+portnum);
        TO->set_property("MyCreatedEnter", "portal"+portnum);
    }

    tell_room(endplace,"%^BOLD%^%^GREEN%^Whorling mists coalesc "+
    "into being before you, spiralling faster and faster of "+
    "their own accord. Finally they shimmer into being as an "+
    "ovoid portal within the air, offering travel to somewhere beyond"+
    ".%^RESET%^");

    if(member_array("portal", endplace->query_exits()) == -1)
    {
        endplace->add_exit(base_name(place),"portal");
    }
    else
    {
        portnum = 1;
        while(member_array("portal"+portnum, endplace->query_exits()) != -1)
        {
            portnum++;
        }
        endplace->add_exit(base_name(place), "portal"+portnum);
        TO->set_property("MyCreatedExit", "portal"+portnum);
    }
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    string CreatedExit;
    if(purpose == "travel")
    {
        tell_room(place,"%^GREEN%^The portal ripples and then abruptly vanishes!%^RESET%^");
        tell_room(endplace,"%^GREEN%^The portal ripples and then abruptly "+
        "vanishes!%^RESET%^");
        if(CreatedExit = TO->query_property("MyCreatedEnter"))
        {
            if(objectp(place)) place->remove_exit(CreatedExit);
        }
        else if(objectp(place)) place->remove_exit("portal");
        if(CreatedExit = TO->query_property("MyCreatedExit"))
        {
            if(objectp(endplace)) endplace->remove_exit(CreatedExit);
        }
        else if(objectp(endplace)) endplace->remove_exit("portal");
    }
    if(objectp(caster) && arg == "summoning") caster->remove_property("has_elemental");
    if(objectp(beastie))
    {
        tell_room(environment(beastie),"%^BOLD%^%^GREEN%^The outsider "+
        "lashes out, suddenly freed of its compulsion, and "+
        "then it vanishes!");
        beastie->move("/d/shadowgate/void");
        beastie->remove();
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
