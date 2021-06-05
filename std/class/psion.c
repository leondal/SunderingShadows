#include <std.h>
inherit DAEMON;

void create() { ::create(); }

string *search_paths() { return ({ "/cmds/psion","/cmds/psionics" }); } // temporary

int caster_class() { return 1; }

string *restricted_races() {
    return ({ "beastman","bugbear","dwarf","elf","gnome","goblin",
        "orc","drow","firbolg","gnoll","half-ogre","ogre","ogre-mage",
        "voadkyn","wemic" });
}

string *restricted_classes() { return ({ "psywarrior","mage","sorcerer","warlock" }); }

int *restricted_alignments() { return ({}); }

string *restricted_gods() { return ({}); }

mapping stat_requirements() {
    return ([ "intelligence" : 16 ]);
}

// strong & weak saving throws. Fort, Ref, Will
int *saving_throws() { return ({ 0,0,1 }); }

string *combat_styles() {
    return ({});
}

string *class_feats(string myspec)
{
    return ({ "simple weapon proficiency",
              "discipline",
              "spell focus", });
}

mapping class_featmap(string myspec, object player) {

    mapping feats;

    feats = ([ 1 : ({ "simple weapon proficiency", "spell focus", "discipline", }), ]);

    switch(player->query_discipline())
    {
        case "egoist":
        feats += ([ 2 : ({ "metabolic healing" }), 11 : ({ "resilient body" }), 21 : ({ "infused form" }) ]);
        break;
        case "kineticist":
        feats += ([ 2 : ({ "telekinetic hurl" }), 11 : ({ "kinetic aura" }), 21 : ({ "energy immunity" }) ]);
        break;
        case "telepath":
        feats += ([ 2 : ({ "mental intrusion" }), 11 : ({ "psychic vampire" }), 21 : ({ "guarded thoughts" }) ]);
        break;
        case "shaper":
        feats += ([ 2 : ({ "astral construct" }), 11 : ({ "summoners call" }), 21 : ({ "astral ally" }) ]);
        break;
        case "nomad":
        feats += ([ 2 : ({ "nomads step" }), 11 : ({ "inconstant position" }), 21 : ({ "worldly traveler" }) ]);
        break;
        case "seer":
        feats += ([ 2 : ({ "seeing the connections" }), 11 : ({ "alter the waves" }), 21 : ({ "perpetual foresight" }) ]);
        break;
    }

    return feats;
}

string *class_skills()
{
    return ({ "academics","spellcraft" });
}

string *discipline_skills(string discipline) {
    if(!discipline || discipline == "") return ({"academics","spellcraft"});
    switch(discipline) {
      case "kineticist": return ({"academics","spellcraft","dungeoneering","influence"}); break;
      case "nomad": return ({"academics","spellcraft","endurance","survival"}); break;
      case "seer": return ({"academics","spellcraft","influence","perception"}); break;
      case "telepath": return ({"academics","spellcraft","influence","perception"}); break;
      case "shaper": return ({"academics","spellcraft","influence","endurance"}); break;
      case "egoist": return ({"academics","spellcraft","athletics","perception"}); break;
      default: return ({"academics","spellcraft"}); break;
    }
}

int skill_points() { return 4; }

string old_save_type() { return "psion"; }

string new_save_type() { return "psion"; }

void advanced_func(object player)
{
    player->set_guild_level("psion",(int)player->query_class_level("psion"));
    return;
}

int hit_dice() { return 4; }  // hit dice rolled for hitpoints each level

int default_hitpoints() { return 2; } // hitpoints per level above level 20

string armor_allowed() { return "mage"; }

string weapons_allowed() { return "mage"; }

int max_stance_offensive() { return 1; }

int max_stance_defensive() { return 1; }

int attack_bonus(object player)
{
    int bonus;
    float penalty, full_level, class_level;

    full_level = to_float(player->query_base_character_level());
    class_level = to_float(player->query_prestige_level("psion"));

    if(full_level < 20.00)
    {
        bonus = (to_int(class_level) * 1 / 2);
        return bonus;
    }

    // Above 20
    // 1/2 BAB gets full penalty to BAB
    // Weighted average of class level compared to total level
    penalty = (10.00 * (class_level / full_level));
    bonus = to_int(class_level - penalty);

    return bonus;
}

int number_of_attacks(object player)
{
    int num;
    if(!objectp(player)) { return 0; }
    num = "/daemon/bonus_d.c"->attack_bonus("psion",player->query_class_level("psion"),player);
    num = num / 7;
    return num;
}

string query_casting_stat(){
   return "intelligence";
}

mapping query_class_spells()
{
    return(([
        1 : ({"detect aura","inertial armor","matter agitation","mind thrust","minor prescience","mylight","skate","sleep","vigor","water breathing","weapon of energy"}),
        2 : ({"alter self","biofeedback","cloud mind","concealing amorpha","genesis","id insinuation","psionic identify","sustenance","swarm of crystals","tongues"}),
        3 : ({"aura alteration","body adjustment","dispel psionics","energy bolt","energy retort","eradicate invisibility","time hop","touchsight"}),
        4 : ({"body purification","detect remote viewing","dimension door","inertial barrier","power leech","slip the bonds","telepathy","wall of ectoplasm"}),
        5 : ({"biting cold","catapsi","creation","ectoplasmic swarm","power resistance","remote viewing"}),
        6 : ({"breath of the black dragon","exigency","fear","mind over energy","remote view trap","temporal acceleration"}),
        7 : ({"evade burst","mind blank","oak body","phase door","prescience","ultrablast"}),
        8 : ({"dispelling buffer","fold space","iron body","reaving dispel","recall death","true metabolism"}),
        9 : ({"microcosm","timeless body","unravel psionics"}),
    ]));
}

string newbie_choice() { return "Discipline Name"; }
string *query_newbie_stuff() { return ({ "egoist","kineticist","nomad","seer","shaper","telepath" }); }
void process_newbie_choice(object who, string str)
{
    if(!objectp(who) || !stringp(str)) return;
    who->set_discipline(str);
}
void newbie_func(object who)
{
    object ob;
    if(!objectp(who)) return;
 }

int caster_level_calcs(object player, string the_class)
{
    int level;
    if(!objectp(player)) { return 0; }
    switch(the_class)
    {
        case "psion":
        default:
            return player->query_class_level(the_class);
    }
    return 0;
}
