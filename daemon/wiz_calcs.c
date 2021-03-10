//      Wizard Calcs Daemon
//      Thorn@Shadowgate
//      1/22/95
//      Daemons for Wizard Class
//      cleric_calcs.c
// 		extended for hm use Tristan@Shadowgate
//      Recoded like cleric_calcs Grendel@Shadowgate
//      1/2000
// ported to generic daemon for all classes, Aug 2010. -Nienne.
// added psywarrior 9/12/15 ~Circe~

#include <std.h>
#include <wizards.h>
#include <psions.h>
#include <master_limits.h>
inherit DAEMON;

void create() {
    seteuid(getuid());
}

int *get_wizard_spell_total(int wizard_level, int stat, int *spells){ //generic extra spell slots based on stat
    mapping bonuses;
    int *extra,i;
    bonuses = ([ 10 : ({0,0,0,0,0,0,0,0,0}),
                 11 : ({0,0,0,0,0,0,0,0,0}),
                 12 : ({1,0,0,0,0,0,0,0,0}),
                 13 : ({1,0,0,0,0,0,0,0,0}),
                 14 : ({1,1,0,0,0,0,0,0,0}),
                 15 : ({1,1,0,0,0,0,0,0,0}),
                 16 : ({1,1,1,0,0,0,0,0,0}),
                 17 : ({1,1,1,0,0,0,0,0,0}),
                 18 : ({1,1,1,1,0,0,0,0,0}),
                 19 : ({1,1,1,1,0,0,0,0,0}),
                 20 : ({2,1,1,1,1,0,0,0,0}),
                 21 : ({2,1,1,1,1,0,0,0,0}),
                 22 : ({2,2,1,1,1,1,0,0,0}),
                 23 : ({2,2,1,1,1,1,0,0,0}),
                 24 : ({2,2,2,1,1,1,1,0,0}),
                 25 : ({2,2,2,1,1,1,1,0,0}),
                 26 : ({2,2,2,2,1,1,1,1,0}),
                 27 : ({2,2,2,2,1,1,1,1,0}),
                 28 : ({3,2,2,2,2,1,1,1,1}),
                 29 : ({3,2,2,2,2,1,1,1,1}),
                 30 : ({3,3,2,2,2,2,1,1,1}) ]);
    extra = bonuses[stat];
    if(!pointerp(extra)) extra = ({0,0,0,0,0,0,0,0,0});

    for(i=0;i<sizeof(spells);i++) {
        if(spells[i]) spells[i] += extra[i];
    }
    return spells;
}


// this is pretty close to what our existing table looks like at level 40, good as I can get it
// a math guru can feel free to make it better -Ares
int *get_high_spell_level_array(int caster_level,string caster_class) // should add a new formula for classes with different progressions at some point
{
    int *spell_levels = allocate(9);
    int i;

    for(i=0;i<sizeof(spell_levels);i++)
    {
        spell_levels[i] = ( caster_level / 6 ) + (  (12 - (i-1)) / 3);
    }

    return spell_levels;
}



int *query_max_spell_array(int wizard_level, string caster_class, int stat) {
    int *spells_allowed, i;

    if(wizard_level > 105) wizard_level = 105;
    spells_allowed = allocate(10);

    switch(caster_class) {
    case "bard": case "inquisitor": case "magus":
        if(wizard_level > 50) { spells_allowed = get_high_spell_level_array(wizard_level,caster_class); }
        else { spells_allowed = BARDLEVELS[wizard_level]; }
        spells_allowed = get_wizard_spell_total(wizard_level,stat,spells_allowed);
        spells_allowed[6]=0; // bard spells do not go above L6, which is array [5]
        spells_allowed[7]=0;
        spells_allowed[8]=0;
        break;
    case "ranger": case "paladin": case "antipaladin":
        if(wizard_level > 50) { spells_allowed = get_high_spell_level_array(wizard_level,caster_class); }
        else { spells_allowed = PALILEVELS[wizard_level]; }
        spells_allowed = get_wizard_spell_total(wizard_level,stat,spells_allowed);
        spells_allowed[4]=0; // pali and ranger spells do not go above L4, which is array [3]
        spells_allowed[5]=0;
        spells_allowed[6]=0;
        spells_allowed[7]=0;
        spells_allowed[8]=0;
        break;
    case "assassin":
        if(wizard_level > 50) { spells_allowed = get_high_spell_level_array(wizard_level,caster_class); }
        else { spells_allowed = ASSASSINLEVELS[wizard_level]; }
        spells_allowed = get_wizard_spell_total(wizard_level,stat,spells_allowed);
        break;
    case "sorcerer": case "oracle":
        if(wizard_level > 50) { spells_allowed = get_high_spell_level_array(wizard_level,caster_class); }
        else { spells_allowed = SORCLEVELS[wizard_level]; }
        spells_allowed = get_wizard_spell_total(wizard_level,stat,spells_allowed);
        break;
    case "psywarrior":
        if(wizard_level > 50) { spells_allowed = get_high_spell_level_array(wizard_level,caster_class); }
        else { spells_allowed = PWKNOWN[wizard_level]; }
        spells_allowed = get_wizard_spell_total(wizard_level,stat,spells_allowed);
        break;
    case "psion":
        if(wizard_level > 50) { spells_allowed = get_high_spell_level_array(wizard_level,caster_class); }
        else { spells_allowed = PSIONKNOWN[wizard_level]; }
        spells_allowed = get_wizard_spell_total(wizard_level,stat,spells_allowed);
        break;
    default: // currently accurate for: mage, cleric, druid
        if(wizard_level > 50) { spells_allowed = get_high_spell_level_array(wizard_level,caster_class); }
        else { spells_allowed = MAGELEVELS[wizard_level]; } // basic level-based spell slots
        spells_allowed = get_wizard_spell_total(wizard_level,stat,spells_allowed); // stat based bonus slots
        break;
    }
    return spells_allowed;
}

int query_spell_limit(int spell_level, int wizard_level, string caster_class, int stat) {
    int *x;
    if(!spell_level) { return 0; }
    x = query_max_spell_array(wizard_level, caster_class, stat);
    return x[spell_level-1];
}

int can_memorize(object caster, int splvl){
    int perc, roll, mlevel;

    roll = random(100) + 1;
    if(roll == 100) return 0;

    perc = MEMCHANCE[(int)caster->query_stats("intelligence")];
    if(caster->is_class("fighter") || caster->is_class("thief") || caster->is_class("cleric")) perc -= 15;
    if(caster->is_class("bard")) {
      perc -= 10;
      mlevel = (int) caster->query_guild_level("bard");
    }
    else mlevel = (int) caster->query_guild_level("mage");

    perc += 2*(mlevel - (2*splvl));
    if(roll < perc) return 1;
    return 0;
}
