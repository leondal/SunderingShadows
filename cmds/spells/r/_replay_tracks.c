#include <priest.h>
#include <daemons.h>
inherit SPELL;


void create()
{
    ::create();
    set_spell_name("replay tracks");
    set_spell_level(([ "druid" : 5, "inquisitor" : 4, "psion" : 5, "ranger" : 2 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS replay tracks");
    set_description("This spell allows you to reconstruct past events that occurred in your current location based on the tracks and other signs left behind. Ability to discern tracks will depend on your power.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

void spell_effect()
{
    string * tracks;
    string track;
    int tdiff;
    string who, what, whereto, name, time;
    int counter = clevel/12+1;
    tracks = place->query_tracks();

    tell_object(caster,"%^RED%^You %^RED%^k%^GREEN%^n%^RED%^eel,%^RED%^ touching the ground with your hand.
%^RED%^Images of %^RED%^the %^RED%^e%^GREEN%^v%^RED%^ent%^GREEN%^s %^GREEN%^p%^GREEN%^a%^RED%^s%^GREEN%^t%^RED%^ appear in your mind.");
    tell_room(place,"%^RED%^"+caster->QCN+" kneels and touches the ground with "+caster->QP+" hand.%^RESET%^",caster);

    foreach(track in tracks)
    {
        if(!track)
            break;
        sscanf(track,"%s&%s&%s&%s&%s", who, what, whereto, name, time);

        //tell_object(caster,":"+name);

        if(name == caster->query_name())
            continue;

        who = capitalize(article(who))+" "+who;

        tdiff=(time()-atoi(time))/20/60;

        if(tdiff<1)
            time = "within past hour";
        else
            time = tdiff+" hours ago";

        switch (what) {
        case "appeared":
            tell_player(caster, who+" appeared here "+time+".\n");
            break;
        case "entered":
            tell_player(caster, who+" entered this room from "+whereto+" "+time+".\n");
            break;
        case "left":
            tell_player(caster, who+" left this room headed "+whereto+" "+time+".\n");
            break;
        }

        if(counter<0)
            break;
        counter--;
    }

    tell_object(caster,"%^RED%^You don't see further than that.%^RESET%^");

    spell_successful();
}
