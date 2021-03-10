//added extra chances of getting the closer alignments and made three chances
//of the group of getting the right one  *Styx*  6/5/02
#include <priest.h>
inherit SPELL;

create() {
    ::create();
    set_spell_name("know alignment");
    set_spell_level(([ "cleric" : 2, "inquisitor" : 2 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS know alignment on TARGET");
    set_description("Allows the caster to learn the target's alignment. This can be foiled by certain illusion magics.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string() {
   return YOU+" concentrates carefully.\n";
}

spell_effect(int prof) {
    int al;
    string align;
    int *choices;

    al = TARGET->query_alignment();
    align = capitalize(TARGET->query_al_title(al));
    tell_object(CASTER, "You cast know alignment on "+HIM+".");
    if(do_save(TARGET,0)) {
    //if ("/daemon/saving_d"->saving_throw(TARGET, "spell") || prof < random(100)) {
        tell_object(CASTER,"You get no impressions about "+HIM+"'s alignment.");
    } else {
        if (random(2) && prof < 110) {
            switch (al) {
            case 1:
                choices = ({1,2,3,4,7,1,2,4,1});
                break;
            case 2:
                choices = ({1,2,3,5,8,1,2,3,5,2});
                break;
            case 3:
                choices = ({1,2,3,6,9,2,3,6,3});
                break;
            case 4:
                choices = ({1,4,5,6,7,1,4,7,4});
                break;
            case 5:
                choices = ({2,4,5,6,8,2,8,5});
                break;
            case 6:
                choices = ({3,4,5,6,9,3,5,6,6});
                break;
            case 7:
                choices = ({1,4,7,8,9,4,7,8,7});
                break;
            case 8:
                choices = ({2,5,7,8,9,5,7,8,8});
                break;
            case 9:
                choices = ({3,6,7,8,9,6,8,9,9});
                break;
            }
            al = choices[random(sizeof(choices))];
            switch (al) {
            case 1:
                align = "Lawful Good";
                break;
            case 2:
                align = "Lawful Neutral";
                break;
            case 3:
                align = "Lawful Evil";
                break;
            case 4:
                align = "Neutral Good";
                break;
            case 5:
                align = "True Neutral";
                break;
            case 6:
                align = "Neutral Evil";
                break;
            case 7:
                align = "Chaotic Good";
                break;
            case 8:
                align = "Chaotic Neutral";
                break;
            case 9:
                align = "Chaotic Evil";
                break;
            }
        }
        tell_object(CASTER, "You see that "+HIM+"'s alignment is "+align);
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
