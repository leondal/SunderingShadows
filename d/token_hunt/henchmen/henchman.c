/*
stuff to do

add more random banter
respond to player emotes

remember to exclude from boss monsters or whatever that auto-kill fodder, we don't want these to get auto-killed

*/

#include <std.h>
#include <daemons.h>
#include <move.h>
#include <clock.h>
#include <magic.h>
#include "henchmen.h"
#include "names.h"

#define OTO environment(OWNER)
#define QTN query_true_name()
#define TOD "daemon/events_d"->query_time_of_day()

inherit MONSTER;

// might add more of these later at some point, classes, fighting styles, and stances
#define RACES ({ "half-elf","human","half-orc" })
//#define CLASSES ({ "fighter","cleric","thief","mage" })
#define CLASSES ({"cleric"})
//#define FIGHTING_STYLES ({ "ranged","dual wield","two handed","sword and shield","casting" })
#define FIGHTING_STYLES ({"sword and shield"})
//#define COMBAT_STANCE ({ "defensive","aggressive","balanced" })
#define COMBAT_STANCE ({"balanced"})
// it shouldn't follow the player into any rooms here, unless it walks into the room with the player...  useful for the flying room, possibly others
#define EXCLUDED_ROOMS ({ "/std/flying_room" })


nosave mapping  INFO,
                ENEMIES,
                TIMERS;


nosave object   REAL_OWNER,
                TEMP_OWNER,
                OWNER,
                MY_WHISTLE;


nosave string   OWNER_NAME;


nosave int      DISMISSED,
                FIRED,
                PARTY_COUNTER,
                COMBAT_TIME,
                IDLE_TIME,
                ACTING,
                TALKING,
                FLAG,
                END_TIME,
                NOTIFIED,
                NOTIFIED_TWICE,
                DOUBLE_PRICE,
                DITCHED,
                ALONE,
                BEAT;


string query_diety() { return "nilith"; }

void increment_stamina(int x) { return; }

void db(string str)
{
    object ob;
    ob = find_object_or_load("/realms/ares/workroom.c");
    if(objectp(ob)) { tell_object(ob,str); }
    return;
}

void toggle_dismissed()
{
    if(DISMISSED) { DISMISSED = 0; }
    DISMISSED = 1;
}

int get_end_time() { return END_TIME; }

int is_merc() { return 1; }

void fire_me()
{
    object whistle;
    if(objectp(TEMP_OWNER)) { return; } // can't fire somebody else's merc

    if(objectp(OWNER)) { whistle = present("merc_whistle_999",OWNER); }
    if(objectp(whistle))
    {
        tell_object(OWNER,"%^RESET%^%^BOLD%^%^GREEN%^The magical whistle vanishes as you terminate the mercenary contract.%^RESET%^");
        whistle->remove();
    }

    FIRED = 1;
    if(DOUBLE_PRICE)
    {
        HENCH_D->penalize(OWNER_NAME,"late");
    }

    if(objectp(TO))
    {
        TO->move(HENCH_ROOM);
        TO->remove();
    }
    return;
}


string desc_me()
{
    string desc,race,gender,name;
    race = (string)TO->query_race();
    gender = (string)TO->query_gender();
    name = capitalize((string)TO->query_name());

    switch(race)
    {
    case "human":

        switch(gender)
        {
        case "male":

            desc = ""+name+" is tall for a human male, standing over six and a half feet in height.  He looks to be heavily built, "
            "but beneath all the armor it's difficult to tell how much of that bulk is muscle and how much is padding. A heavy helm "
            "covers his head and makes it difficult to make out many details.  What is clear is that he is still somewhat young.  Out "
            "of his teenaged years, but probably not yet into his thirties.  He carries himself with the easy grace of a man who has spent "
            "a lot of time wearing his armor and a lot of time wielding his weapon.  The armor and shield are well made, but lack any of the "
            "fancy adornments that are more typical of the gear adventurers wear.  Instead it looks like quality gear that is meant to be "
            "mass produced.";
            break;

        case "female":
        default:

            desc = ""+name+" is around average height for a female human, standing just under five and a half feet tall.  She has a slender, "
            "build but looks quite heavy in the suit of steel armor. A heavy helm prevents you from seeing much of her face, but long brownish "
            "hair sometimes escapes the confines of the headgear.  She seems to be youthful in age, probably out of her teens but not yet into "
            "her thirties.  She carries himself with the easy grace of someone who has spent a lot of time wearing heavy armor and has learned "
            "how to move in it.  The armor and shield are well made, but lack any of the fancy adornments that are more typical of the gear "
            "adventurers wear.  Instead it looks like quality gear that is meant to be mass produced.";
            break;
        }

        break;

    case "half-orc":

        switch(gender)
        {
        case "male":

            desc = ""+name+" is tall for a half-orc, standing nearly six feet in height.  His body is very bulky beneath the suit of heavy "
            "armor.  A helm covers his head and face and makes it difficult to determine much about his appearance.  He seems to be of middle "
            "age for a half-orc.  He carries the heavy armor on his body as if it were a second skin, the considerable bulk of the metal armor doing "
            "nothing at all to slow down his movements.  The armor and shield are well made, but lack any of the fancy adornments that are "
            "more typical of the gear adventurers wear.  Instead it looks like quality gear that is meant to be mass produced.";
            break;

        case "female":
        default:

            desc = ""+name+" is about average height for a female half-orc, standing just a bit over five feet tall.  Her body is bulky beneath the suit "
            "of heavy armor.  A helm covers her face and makes it difficult to determine many of the details, save for the fact that she seems to be "
            "approaching middle age for a half-orc.  The armor seems to do very little to limit her movements, despite its weight and bulk.  The armor and "
            "shield are well made, but lack any of the fancy adornments that are more typical of the gear adventurers wear.  Instead it looks like quality "
            "gear that is meant to be mass produced.";
            break;
        }

        break;

    case "half-elf":

        switch(gender)
        {
        case "male":

            desc = ""+name+" is about average height for a half-elven male, standing a couple inches above five feet in height.  His body seems to be slender "
            "in build, with armor that fits very well to his torso.  He wears a heavy helm on his head that makes it difficult to make out many of the details.  "
            "His skin has the same smooth appearance as those that are very young, but it is difficult to be sure with those of elven blood.  His appearance would "
            "be very similar were he just out of his teenage years or well into his fifth decade of life.  The armor he wears does almost nothing to limit his movements, "
            "it seems to be so well crafted as to hinder him not at all.  The armor and shield are well made, but lack any of the fancy adornments that are more typical "
            "of the gear adventurers wear.  Instead it looks like quality gear that is meant to be mass produced.";
            break;

        case "female":
        default:

            desc = ""+name+" is just under average height for a half-elven female, standing a couple inches shy of five feet.  Her body is quite slender in build and "
            "her armor has been form fitted to hug the contours.  She wears a heavy helm on her head that makes it difficult to determine many of the details of her "
            "appearance.  It is difficult to pinpoint her age by the texture of her skin, as those with elven blood would look much the same just out of their "
            "teenage years as they would going into their fifth decade of life.  The armor she wears does nothing to limit her movements, it seems to be so well crafted "
            "as to hinder her not at all.  The armor and shield are well made, but lack any of the fancy adornments that are more typical of the gear "
            "adventurers wear.  Instead it looks like quality gear that is meant to be mass produced.";
            break;
        }

        break;
    }

    return desc;
}


string choose_name(string race, int level)
{
    string name;

    if(!stringp(race) || race == "" || race == " ") { return "John Doe"; }

    switch(level)
    {
    case 0..10:

        if(race == "human")
        {
            name = HUMAN_NAMES_10[random(sizeof(HUMAN_NAMES_10))];
        }

        if(race == "half-elf")
        {
            name = HALF_ELF_NAMES_10[random(sizeof(HALF_ELF_NAMES_10))];
        }

        if(race == "half-orc")
        {
            name = HALF_ORC_NAMES_10[random(sizeof(HALF_ORC_NAMES_10))];
        }

        break;

    case 11..20:

        if(race == "human")
        {
            name = HUMAN_NAMES_20[random(sizeof(HUMAN_NAMES_20))];
        }

        if(race == "half-elf")
        {
            name = HALF_ELF_NAMES_20[random(sizeof(HALF_ELF_NAMES_20))];
        }

        if(race == "half-orc")
        {
            name = HALF_ORC_NAMES_20[random(sizeof(HALF_ORC_NAMES_20))];
        }

        break;

    case 21..30:

        if(race == "human")
        {
            name = HUMAN_NAMES_30[random(sizeof(HUMAN_NAMES_30))];
        }

        if(race == "half-elf")
        {
            name = HALF_ELF_NAMES_30[random(sizeof(HALF_ELF_NAMES_30))];
        }

        if(race == "half-orc")
        {
            name = HALF_ORC_NAMES_30[random(sizeof(HALF_ORC_NAMES_30))];
        }

        break;

    default:

        if(race == "human")
        {
            name = HUMAN_NAMES_40[random(sizeof(HUMAN_NAMES_40))];
        }

        if(race == "half-elf")
        {
            name = HALF_ELF_NAMES_40[random(sizeof(HALF_ELF_NAMES_40))];
        }

        if(race == "half-orc")
        {
            name = HALF_ORC_NAMES_40[random(sizeof(HALF_ORC_NAMES_40))];
        }

        break;
    }

    return name;
}

// attempting to make monster gender based on spelling of the name.  Might need a bit of tweaking -Ares
string choose_gender(string name)
{
    string last_char,next_char;
    int last;

    string *feminine_last_chars = ({ "a","i","y" });
    string *maybe_last_chars = ({ "n","u","e", });
    string *confirm_chars = ({ "r","s","u","a" });

    if(!stringp(name) || name == "" || name == " ") { return "male"; }

    if(strlen(name) < 3) { return "female"; }

    last = strlen(name) - 1;
    last_char = name[last..last];
    next_char = name[(last-1)..(last-1)];

    if(member_array(last_char,feminine_last_chars) != -1) { return "female"; }
    if(member_array(last_char,maybe_last_chars) != -1)
    {
        if(member_array(next_char,confirm_chars) != -1) { return "female"; }
    }

    return "male";
}


void set_my_skills(int level)
{
    string *skills = ({ "athletics","dungeoneering","endurance","healing","perception","stealth","spellcraft","survival","thievery" });
    int i;

    for(i=0;i<sizeof(skills);i++)
    {
        set_skill(skills[i],level+(level/8));
    }

    return;
}


void set_my_stats(string myclass,int level)
{
    int high,mid,low;

    high = 20 + (level / 7);
    mid  = 15 + (level / 9);
    low  = 10 + (level / 9);

    set_stats("strength",low);
    set_stats("dexterity",mid);
    set_stats("constitution",high);
    set_stats("intelligence",low);
    set_stats("wisdom",high);
    set_stats("charisma",mid);

    /*
    switch(class)
    {
    case "fighter":
        set_stats("strength",high);
        set_stats("dexterity",high);
        set_stats("constitution",high);
        set_stats("intelligence",low);
        set_stats("wisdom",low);
        set_stats("charisma",low);
        break;

    case "cleric":
        set_stats("strength",high);
        set_stats("dexterity",mid);
        set_stats("constitution",high);
        set_stats("intelligence",low);
        set_stats("wisdom",high);
        set_stats("charisma",mid);
        break;

    case "thief":
        set_stats("strength",mid);
        set_stats("dexterity",high);
        set_stats("constitution",high);
        set_stats("intelligence",mid);
        set_stats("wisdom",low);
        set_stats("charisma",low);
        break;

    case "mage":
        set_stats("strength",low);
        set_stats("dexterity",mid);
        set_stats("constitution",high);
        set_stats("intelligence",high);
        set_stats("wisdom",mid);
        set_stats("charisma",mid);
        break;
    }
    */
    return;
}


void describe_me(string name, string myclass, string race, string gender)
{
    set_short(""+capitalize(name)+", a veteran "+gender+" "+race+" mercenary");
    set_long(desc_me());
}


void equip_me()
{
    int level;
    object obj;

    if(!objectp(TO)) { return; }

    level = (int)TO->query_level();

    switch(level)
    {
    case 0..10:
        obj = new("/d/common/obj/armour/banded");
        obj->set_property("no curse",1);
        obj->set_property("monsterweapon",1);
        obj->set_property("enchantment",level/5);
        obj->set_short("%^RESET%^%^BOLD%^gleaming suit of banded armor%^RESET%^");
        obj->move(TO);
        TO->force_me("wear banded");
        break;
    default:
        obj = new("/d/common/obj/armour/fullplate");
        obj->set_property("no curse",1);
        obj->set_property("monsterweapon",1);
        obj->set_property("enchantment",level/5);
        obj->set_short("%^RESET%^%^BOLD%^gleaming suit of full plate armor%^RESET%^");
        obj->move(TO);
        TO->force_me("wear plate");
        break;
    }

    obj = new("/d/common/obj/armour/shield");
    obj->set_property("no curse",1);
    obj->set_property("monsterweapon",1);
    obj->set_property("enchantment",level/5);
    obj->set_short("%^RESET%^%^BOLD%^polished tower shield");
    obj->move(TO);
    TO->force_me("wear shield");

    obj = new("/d/common/obj/armour/helm");
    obj->set_property("no curse",1);
    obj->set_property("monsterweapon",1);
    obj->set_property("enchantment",level/5);
    obj->set_short("%^RESET%^%^BOLD%^gleaming steel great helm");
    obj->move(TO);
    TO->force_me("wear helm");

    obj = new("/d/common/obj/armour/gauntlets");
    obj->set_property("no curse",1);
    obj->set_property("monsterweapon",1);
    obj->set_property("enchantment",level/5);
    obj->set_short("%^RESET%^%^BOLD%^polished mithril gauntlets");
    obj->move(TO);
    TO->force_me("wear gauntlets");

    obj = new("/d/common/obj/armour/greaves");
    obj->set_property("no curse",1);
    obj->set_property("monsterweapon",1);
    obj->set_property("enchantment",level/5);
    obj->set_short("%^RESET%^%^BOLD%^polished mithril greaves");
    obj->move(TO);
    TO->force_me("wear greaves");

    obj = new("/d/common/obj/clothing/belt");
    obj->set_property("no curse",1);
    obj->set_property("monsterweapon",1);
    obj->set_property("enchantment",level/5);
    obj->set_short("%^RESET%^%^YELLOW%^sturdy leather belt");
    obj->move(TO);
    TO->force_me("wear belt");

    obj = new("/d/deku/armours/ring_p");
    obj->set_property("no curse",1);
    obj->set_property("monsterweapon",1);
    obj->set_property("enchantment",level/5);
    obj->move(TO);
    TO->force_me("wear ring");

    switch(level)
    {
    case 0..9:

        obj = new("/d/common/obj/weapon/longsword");
        obj->set_property("no curse",1);
        obj->set_property("monsterweapon",1);
        obj->set_property("enchantment",level/5);
        obj->set_short("%^RESET%^%^RED%^a razor sharp longsword");
        obj->move(TO);
        TO->force_me("wield sword");

        break;

    case 10..20:

        obj = new("/d/token_hunt/obj/low/stormrapier");
        obj->set_property("no curse",1);
        obj->set_property("monsterweapon",1);
        obj->set_property("enchantment",level/5);
        obj->move(TO);
        TO->force_me("wield sword");

        break;

    //case 21..35:
    default:

        obj = new("/d/tharis/barrow/obj/slayer");
        obj->set_property("no curse",1);
        obj->set_property("monsterweapon",1);
        obj->set_property("enchantment",level/5);
        obj->move(TO);
        TO->force_me("wield sword");

        break;

    /*
    default:

        obj = new("/d/islands/common/obj/csabre");
        obj->set_property("no curse",1);
        obj->set_property("monsterweapon",1);
        obj->set_property("enchantment",level/5);
        obj->move(TO);
        TO->force_me("wield sword");

        break;
    */
    }


}

string *query_mini_quests()
{
    return ({ "%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^" });
}

/**
 * This should get called for initial setup of the mercenary after the
 * player hires it. Sets all of the relevant details here everything
 * else the merc can do will be dialogue driven and level dependent
 * only going to have fighter/cleric to cut down on work.
 */
varargs int setup_merc(string myclass, string race, object owner, string myname)
{
    int level,mod;
    string name,gender;
    object whistle;

    myclass = "cleric";

    END_TIME = time() + DAY; // 24000 seconds

    if(!objectp(owner))
    {
        TO->move("/d/shadowgate/void");
        TO->remove();
        return 0;
    }

    if(member_array(myclass,CLASSES) == -1)
    {
        TO->move("/d/shadowgate/void");
        TO->remove();
        return 0;
    }

    if(member_array(race,RACES) == -1)
    {
        TO->move("/d/shadowgate/void");
        TO->remove();
        return 0;
    }

    OWNER = owner;
    OWNER_NAME = OWNER->query_name();

    set_body_type("human");

    level = (int)owner->query_base_character_level();

    if(level < 3) { level = 3; } // make the ones in offestry a little bit stronger

    set_property("spell penetration",level + 10);

    set_property("add kits",50);

    name = choose_name(race,level);
    if(stringp(myname)) { name = myname; }

    set_name(name);

    gender = choose_gender(name);
    set_gender(gender);

    set_race(race);

    set_my_skills(level);

    set_id( ({ "merc","mercenary",name,race,lower_case(name) }) );

    set_hd(level,20);
    set_max_hp((level * 18) + 50);
    set_hp(query_max_hp());

    set_property("full attacks",1);

    set_class(myclass);

    ///if(class != "fighter") { remove_class("fighter"); }

    set_mlevel(myclass,level);
    set_guild_level(myclass,level);

    set_my_stats(myclass,level);

    describe_me(name,myclass,race,gender);

    //set_monster_feats(({ "perfect caster","powerattack","blindfight","regeneration","resistance","combat reflexes","rush","scramble","damage resistance", "daze","shatter","defensive roll","evasion","expertise","force of personality","spell reflection", "spring attack","sunder","greater weapon focus","greater weapon specialization","hardenedminions","toughness", "improved damage resistance","improved resistance","improved toughness","unyielding soul","increased resistance","lightning reflexes","mobility","parry", "reflection","counter","shieldbash","deflection","shieldwall","armored caster","slippery caster","spell focus","spell penetration", "spell power","greater spell focus","greater spell penetration","greater spell power","thick skinned caster","improved spell power" }));
    set_monster_feats( ({ "perfect caster", "regeneration", "damage resistance", "improved damage resistance", "toughness", "improved toughness", "resistance" }) );
    
    TO->force_me("hardenedminions");
    OWNER->add_follower(TO);
    tell_object(OWNER,TO->QCN+" is now following you");
    equip_me();
    //TO->add_attack_bonus(level*2); // they don't seem to hit as well as players for some reason
    /* GOOD, they shouldn't
    TO->add_attack_bonus((level / 32)+2);
    TO->add_damage_bonus((level / 32)+2);
    */
    mod = level / 12;
    //if(mod < 2) { mod = 2; }
    mod = mod < 1 ? 1 : mod;
    //if(mod > 5) { mod = 5; }
    mod = mod > 3 ? 3 : mod;
    
    TO->set_property("fighter_attacks_mod",mod);
    TO->force_me("briefcombat");

    if(!objectp(whistle = present("merc_whistle_999",owner)))
    {
        whistle = new(WHISTLE);
        whistle->setup_whistle(TO);
        whistle->move(OWNER);
        MY_WHISTLE = whistle;
        tell_object(OWNER,"%^RESET%^%^BOLD%^%^GREEN%^The mercenary hands you a silver whistle with some writing on it.%^RESET%^");
    }
    else
    {
        if(whistle->query_end_time()) { END_TIME = whistle->query_end_time(); }
    }

}


void set_my_whistle(object whistle)
{
    if(!objectp(whistle)) { return; }
    MY_WHISTLE = whistle;
}


void sack_me()
{
    object obj;

    obj = new("/d/common/obj/misc/sack.c");
    obj->set_property("monsterweapon",1);
    obj->set_property("no animate",1);
    obj->set_property("no steal",1);
    obj->set_short("worn looking large canvas bag");
    obj->set_max_internal_encumbrance(1000000);
    obj->move(TO);
}

void create()
{
    INFO = ([]);
    ENEMIES = ([]);
    TIMERS = ([]);
    PARTY_COUNTER = 0;

    ::create();

    TO->set_stats("strength",15);
    TO->set_property("water breather",1);
    TO->set_property("demongate flying",1);
    TO->set_property("no_random_treasure",1);
    add_id("merc");
    set_short("a merc");
    set_long("test description");
    sack_me();

}

void check_my_heart()
{
    if(BEAT > 7)
    {
        set_heart_beat(1);
        BEAT = 0;
        call_out("check_my_heart",1);
        return;
    }
    BEAT++;
    call_out("check_my_heart",1);
    return;
}

void say(string str)
{
    TO->force_me("speak wizish");
    TO->force_me("speech say in a gruff tone");
    TO->force_me("say " +"%^BOLD%^%^GREEN%^"+ str + "%^RESET%^");
    return;
}

void take_item(object obj)
{
    object sack;
    int num;

    if(!objectp(obj)) { return; }

    sack = present("sack",TO);

    if(!objectp(sack)) { sack_me(); }

    if(objectp(obj)) { obj->set_property("monsterweapon",1); }

    tell_room(ETO,TO->QCN+" puts "+obj->query_short()+" into "+sack->query_short());
    num = obj->move(sack);
    if(num != MOVE_OK)
    {
        obj->move("/d/shadowgate/void");
        obj->remove();
    }
    return;
}


void receive_given_item(object obj)
{
    mapping map=([]);
    function func;

    if(!objectp(obj)) { return; }

    if(obj->id("kitxyz"))
    {
        map["delay"] = 0.9;
        map["counter"] = 0;
        map["events"] = ([ 0 : (["say"      : "thanks, I'll hang on to these."]),
                           1 : (["emote"    : "raises an eyebrow" ]),
                           2 : (["say"      : "and they're mine now, so don't get any ideas."]),
                           3 : (["endblank" : 0 ]), ]);
        obj->set_property("monsterweapon",1);
        TALKING = 1;
        call_out("process_speech_event",map["delay"],map);
        return;
    }

    func = (: call_other, TO, "take_item" :);

    map["obj"] = obj;
    map["delay"] = 0.9;
    map["counter"] = 0;
    map["events"] = ([ 0 : (["emote"      : "chuckles"]),
                       1 : (["say"        : "I'm sure I can get a few coins out of this."]),
                       2 : (["say"        : "and before you even ask, no, you're not getting it back."]),
                       3 : (["say"        : "I'm not a damn pack mule"]),
                       4 : (["endfuncobj" : func ]), ]);
    TALKING = 1;
    call_out("process_speech_event",map["delay"],map);

    return;
}

void protect_party()
{
    object *allies=({});
    int i;

    if(!objectp(TO)) { return; }
    if(!objectp(OWNER)) { return; }

    allies = query_party();
    if(!sizeof(allies)) { return; }

    for(i=0;i<sizeof(allies);i++)
    {
        if(!objectp(allies[i])) { continue; }
        if(!present(allies[i],ETO)) { continue; }
        if(allies[i] == TO) { continue; }
        allies[i]->add_protector(TO);
    }
    tell_room(ETO,"%^RED%^"+TO->QCN+" takes up a protective stance.%^RESET%^");
    return;
}

int used_name(string *str)
{
    int i;
    string *names=({});
    if(!sizeof(str)) { return 0; }
    names = ({ (string)TO->query_name(), "merc","mercenary","hireling","henchman" });
    for(i=0;i<sizeof(str);i++)
    {
        if(member_array(str[i],names) != -1) { return 1; }
    }
    return 0;
}

int filter_short_words(string str)
{
    string name;
    name = (string)TO->query_name();

    if(!stringp(str) || str == "") { return 0; }
    if(strlen(str) < 2) { return 0; }
    if(str == "merc") { return 0; }
    if(str == "mercenary") { return 0; }
    if(str == "henchman") { return 0; }
    if(str == "hireling") { return 0; }
    if(str == name) { return 0; }
    return 1;
}

// returns how many words in "words" were used in the "str"..  the closer the two strings are in size,
// the more likely the merc should respond
int used_words(string *words, string *str)
{
    int i,count=0;
    if(!sizeof(words)) { return 0; }
    if(!sizeof(str)) { return 0; }

    str = filter_array(str,"filter_short_words",TO); // chops out words like and and the..  not useful for our purposes

    for(i=0;i<sizeof(words);i++)
    {
        if(member_array(words[i],str) != -1) { count++; }
    }

    return count;
}


mapping count_the_words(string *str,string *words)
{
    int i;
    mapping map = ([]);

    for(i=0;i<sizeof(str);i++)
    {
        map[str[i]] = used_words(explode(str[i]," "),words);
    }
    return map;
}

// this tries to pick a dialogue choice intelligently based on the words spoken by the player
// and the amount of players in the room.  Experimental..  hoping it works
// the experiment didn't go as well as expected, think I'll be better off updating this to use whole phrases instead of words
string pick_dialogue(string *words)
{
    // should compare the words spoken to word keys for specific dialogue choices and then
    // respond if there are enough matches.  Chance to respond raises if the merc's name is used
    // or if the words merc, mercenary, henchman or hireling are used
    mapping choices = ([]),map=([]),choice_map=([]);
    object *living=({});
    string *choice=({}),*the_keys=({}),*to_map=({}),*ikeys=({}),the_choice;
    int i,j,chance,pick,count,name_used;

    living = all_living(ETO);
    // less chance they are talking to the henchman if there is more than one player in the room
    living = filter_array(living,"is_player",FILTERS_D);
    living = filter_array(living,"is_non_immortal_player",FILTERS_D);
    //living -= ({ OWNER });

    chance = 100;

    if(sizeof(living)) { chance = chance / sizeof(living); }

    if(used_name(words)) { chance += 100; name_used = 1; }

    //tell_room(ETO,"words: "+identify(words));

    to_map = ({ "heal" });
    choices["heal"] = count_the_words(to_map,words);

    to_map = ({ "poison","poisoned" });
    choices["poison"] = count_the_words(to_map,words);

    to_map = ({ "blind" });
    choices["blind"] = count_the_words(to_map,words);

    to_map = ({ "protect", "defend", "help" });
    choices["protect"] = count_the_words(to_map,words);

    to_map = ({ "fodder","snakes","summon","summon fodder","summon snakes","snake" });
    choices["fodder"] = count_the_words(to_map,words);

    to_map = ({ "food","thirsty","hungry","feast"});
    choices["food"] = count_the_words(to_map,words);

    to_map = ({ "dark", "see", "light" });
    choices["light"] = count_the_words(to_map,words);

    to_map = ({ "bright", "sun", "darkness" });
    choices["dark"] = count_the_words(to_map,words);

    to_map = ({ "animate", "animate object" });
    choices["animate object"] = count_the_words(to_map,words);

    to_map = ({ "water breathing", "drown", "underwater", "water","breathe"});
    choices["water breathing"] = count_the_words(to_map,words);

    to_map = ({ "hello", "hi", "greetings", "salutations", "howdy", "hey", "good day", "good morning",
                "good afternoon", "good evening", "hiya", "heya", "heyya" });
    choices["hello"] = count_the_words(to_map,words);

    to_map = ({ "weather", "rain", "raining", "snow", "snowing", "night", "night time", "hot", "cold", "freezing" });
    choices["weather"] = count_the_words(to_map,words);

    to_map = ({ "abilities",  "good", "skills", "feats","fight"});
    choices["abilities"] = count_the_words(to_map,words);

    to_map = ({ "cost", "much", "price", "expensive" });
    choices["prices"] = count_the_words(to_map,words);

    to_map = ({ "gold","platinum","coins","money","dosh","loot","treasure","gems","jewelry" });
    choices["love of money"] = count_the_words(to_map,words);

    to_map = ({ "give", "mine" });
    choices["give back"] = count_the_words(to_map,words);

    to_map = ({ "sack" });
    choices["big sack"] = count_the_words(to_map,words);

    to_map = ({ "unit", "group" });
    choices["my unit"] = count_the_words(to_map,words);

    to_map = ({ "worship", "god", "deity", "pray", "goddess", });
    choices["god"] = count_the_words(to_map,words);

    to_map = ({ "carry" });
    choices["pack mule"] = count_the_words(to_map,words);

    to_map = ({ "stupid", "useless", "idiot" });
    choices["insult"] = count_the_words(to_map,words);

    the_keys = keys(choices);

    for(i=0;i<sizeof(the_keys);i++)
    {
        map = choices[the_keys[i]];
        ikeys = keys(map);
        for(j=0;j<sizeof(ikeys);j++)
        {
            if(map[ikeys[j]]) { choice_map[the_keys[i]] += map[ikeys[j]]; }
        }
    }

    the_keys = keys(choice_map); // no real way to intelligently determine which one they meant to ask about here.. might as well return a random one
    if(!sizeof(the_keys)) { the_choice = "nothing"; }
    else
    {
        the_choice = the_keys[random(sizeof(the_keys))];
        chance += choice_map[the_choice];
        //tell_room(ETO,"chance: "+chance);
        if(random(100) > chance) { the_choice = "nothing"; }
    }

    if(the_choice == "nothing" && name_used) { the_choice = "name"; }

    //tell_room(ETO,"the_choice: "+the_choice);

    return the_choice;
}


void process_speech_event(mapping map)
{
    int counter;
    mapping events=([]),event=([]);
    string *key=({}),what;

    if(!mapp(map)) { return; }
    if(!objectp(TO)) { return; }

    counter = map["counter"];

    events = map["events"];
    event = events[counter];
    if(!mapp(events) || !sizeof(keys(events)) || !mapp(event))
    {
        TALKING = 0;
        //tell_room(ETO,"ERROR: No dialogue event mapping for "+map["dialogue"]+".");
        return;
    }
    key = keys(event);
    what = implode(key,"");

    switch(what)
    {
    case "emote":
        TO->force_me("emote "+event[what]);
        break;
    case "say":
        say(event[what]);
        break;
    case "endfuncobj":
        TALKING = 0;
        evaluate(event["endfuncobj"],map["obj"]);
        return;
    case "endfuncobjstr":
        TALKING = 0;
        evaluate(event["endfuncobjstr"],map["obj"],map["str"]);
        return;
    case "endblank":
        TALKING = 0;
        return;
    case "endprotect":
        TALKING = 0;
        evaluate(event["endprotect"]);
        return;
    default:
        return;
    }

    counter++;
    map["counter"] = counter;

    call_out("process_speech_event",map["delay"],map);
    return;
}


void parse_speech(string str, object obj)
{
    mapping map=([]),temp=([]),vars=([]);
    object *allies=({}),targ;
    string *words=({}),dialogue;
    function func;
    int i,num,rand;

    str = FILTERS_D->filter_colors(str);
    str = lower_case(str);
    str = replace_string(str,",","");
    str = replace_string(str,".","");
    str = replace_string(str,"?","");

    words = explode(str," ");
    if(!sizeof(words)) { return; }

    dialogue = pick_dialogue(words);

    map["delay"] = 1.1;
    map["counter"] = 0;
    map["obj"] = obj;
    map["events"] = ([]);
    map["dialogue"] = dialogue;
    map["str"] = "";

    func = (: call_other,TO,"perform_action" :);
    targ = 0;

    TALKING = 1;

    switch(dialogue)
    {

    case "heal":

        map["str"] = "mass heal";
        FLAG = 1;

        switch(random(2))
        {
        case 0:
            temp[0] = ([ "emote"            : "nods" ]);
            temp[1] = ([ "say"              : "fine, I can heal you." ]);
            temp[2] = ([ "endfuncobjstr"    : func ]);
            break;

        default:
            temp[0] = ([ "emote"            : "rolls "+TO->QP+" eyes." ]);
            temp[1] = ([ "say"              : "yeah, yeah, keep your panties on." ]);
            temp[2] = ([ "endfuncobjstr"    : func ]);
            break;
        }
        break;

    case "poison":

        allies = query_allies();
        for(i=0;i<sizeof(allies);i++)
        {
            if(!objectp(allies[i])) { continue; }
            if(environment(allies[i]) != ETO) { continue; }
            if(!POISON_D->is_poisoned(allies[i])) { continue; }
            targ = allies[i];
        }
        if(objectp(targ))
        {
            map["str"] = "neutralize poison";
            map["obj"] = targ;

            switch(random(2))
            {
            case 0:
                temp[0] = ([ "emote"            : "grimaces" ]);
                temp[1] = ([ "say"              : "that poison is some nasty stuff, we better take care of that." ]);
                temp[2] = ([ "endfuncobjstr"    : func ]);
                break;
            default:
                temp[0] = ([ "say"              : "you don't look so good." ]);
                temp[1] = ([ "say"              : "lets see if we can get rid of that poison." ]);
                temp[2] = ([ "endfuncobjstr"    : func ]);
                break;
            }
        }
        else
        {
            switch(random(2))
            {
            case 0:
                temp[0] = ([ "emote"    : "shrugs" ]);
                temp[1] = ([ "say"      : "if somebody gets poisoned I can cure them." ]);
                temp[2] = ([ "emote"    : "gives a quick glance around." ]);
                temp[3] = ([ "say"      : "everybody seems fine now though." ]);
                temp[4] = ([ "endblank" : 0 ]);
                break;
            default:
                temp[0] = ([ "emote"    : "looks around carefully" ]);
                temp[1] = ([ "say"      : "doesn't look like anybody is poisoned now." ]);
                temp[2] = ([ "say"      : "just let me know if you get poisoned though, and I'll try to cure you." ]);
                temp[3] = ([ "emote"    : "sighs" ]);
                temp[4] = ([ "say"      : "I suppose I can cure anybody you happen to be traveling with too, if I have to." ]);
                temp[5] = ([ "endblank" : 0 ]);
                break;
            }

        }
        break;

    case "blind":

        allies = query_allies();
        for(i=0;i<sizeof(allies);i++)
        {
            if(!objectp(allies[i])) { continue; }
            if(allies[i] == TO) { TO->set_blind(0); continue; }
            if(environment(allies[i]) != ETO) { continue; }
            if(!allies[i]->query_blind()) { continue; }
            targ = allies[i];
        }
        if(objectp(targ))
        {
            map["str"] = "cure blindness";
            map["obj"] = targ;

            switch(random(2))
            {
            case 0:
                temp[0] = ([ "emote"            : "rolls "+TO->QP+" eyes" ]);
                temp[1] = ([ "say"              : "can't see?  I might be able to help with that." ]);
                temp[2] = ([ "emote"            : "snickers." ]);
                temp[3] = ([ "say"              : "are you sure you want me to though?" ]);
                temp[4] = ([ "say"              : "I mean look on the bright side, this way you don't have to see your reflection when you look in a mirror." ]);
                temp[5] = ([ "endfuncobjstr"    : func ]);
                break;
            default:
                temp[0] = ([ "emote"            : "shuffles quietly over to the side." ]);
                temp[1] = ([ "say"              : "I'm over here!" ]);
                temp[2] = ([ "emote"            : "shuffles some more." ]);
                temp[3] = ([ "say"              : "no, I'm over here!" ]);
                temp[4] = ([ "emote"            : "sputters a short laugh." ]);
                temp[5] = ([ "say"              : "alright, alright, I'm through messing with you." ]);
                temp[6] = ([ "say"              : "that never gets old." ]);
                temp[7] = ([ "endfuncobjstr"    : func ]);
                break;
            }
        }
        else
        {
            switch(random(2))
            {
            case 0:
                temp[0] = ([ "say"      : "who's blind?" ]);
                temp[1] = ([ "say"      : "doesn't look like anybody, no stumbling and falling all over the place." ]);
                temp[2] = ([ "emote"    : "shrugs" ]);
                temp[3] = ([ "endblank" : 0 ]);
                break;
            default:
                temp[0] = ([ "emote"    : "sighs and then rolls "+TO->QP+" eyes" ]);
                temp[1] = ([ "say"      : "yeah, I can cure blindness too." ]);
                temp[2] = ([ "say"      : "it doesn't look like anybody needs it now though." ]);
                temp[3] = ([ "say"      : "let me know if that changes." ]);
                temp[4] = ([ "endblank" : 0 ]);
                break;
            }
        }

        break;

    case "protect":

        func = (:call_other,TO,"protect_party":);
        switch(random(2))
        {
        case 0:
            temp[0] = ([ "say"          : "fine, I'll protect you." ]);
            temp[1] = ([ "emote"        : "mutters something about a bunch of babies" ]);
            temp[2] = ([ "endprotect"   : func ]);
            break;
        default:
            temp[0] = ([ "say"          : "yeah, whatever." ]);
            temp[1] = ([ "say"          : "do you want me to hold your hand too, cupcake?" ]);
            temp[2] = ([ "emote"        : "rolls "+TO->QP+" eyes" ]);
            temp[3] = ([ "endprotect"   : func ]);
            break;
        }

        break;

    case "fodder":

        map["str"] = "summon fodder";

        if(!objectp(ETO)) { return; }
        if(ETO->query_property("no sticks"))
        {
            temp[0] = ([ "emote"    : "shakes "+TO->QP+" head" ]);
            temp[1] = ([ "say"      : "sorry, no sticks here.  I can't make any snakes." ]);
            temp[2] = ([ "emote"    : "frowns" ]);
            temp[3] = ([ "endblank" : 0 ]);
            break;
        }
        if(has_fodder())
        {
            switch(random(5))
            {
            case 0:
                temp[0] = ([ "emote"    : "grins" ]);
                temp[1] = ([ "say"      : "unfortunately, I've got all the snakes I can summon right now." ]);
                temp[2] = ([ "emote"    : "looks off longingly at nothing" ]);
                temp[3] = ([ "say"      : "sometimes I dream of being able to summon more of the slithery little bastards" ]);
                temp[4] = ([ "say"      : "legions and legions of them" ]);
                temp[5] = ([ "say"      : "a mass of writhing snakes, as far as the eye can see" ]);
                temp[6] = ([ "emote"    : "sighs" ]);
                temp[7] = ([ "say"      : "unfortunately, it doesn't work that way." ]);
                temp[8] = ([ "say"      : "so we'll have to make do with the ones we've already got" ]);
                temp[9] = ([ "emote"    : "grins again and gets an evil look in "+TO->QP+" eyes" ]);
                temp[10] = ([ "say"      : "for now." ]);
                temp[11] = ([ "endblank" : 0 ]);
                break;
            default:
                temp[0] = ([ "emote" : "shakes "+TO->QP+" head" ]);
                temp[1] = ([ "say"   : "I've already got too many snakes to summon any more right now." ]);
                temp[2] = ([ "endblank" : 0 ]);
                break;
            }
        }
        else
        {
            switch(random(2))
            {
            case 0:
                temp[0] = ([ "emote"            : "nods." ]);
                temp[1] = ([ "say"              : "okay, I can do that." ]);
                temp[2] = ([ "endfuncobjstr"    : func ]);
                break;
            default:
                temp[0] = ([ "say"              : "snakes, coming right up." ]);
                temp[1] = ([ "endfuncobjstr"    : func ]);
                break;
            }
        }
        break;

    case "food":

        map["str"] = "food";
        if(present("feast",ETO) || (present("pile of food",ETO) && present("pool of water",ETO)))
        {
            temp[0] = ([ "say"   : "don't you think there's already enough to eat and drink here?" ]);
            temp[1] = ([ "endblank" : 0 ]);
            break;
        }
        else
        {
            switch(random(2))
            {
            case 0:
                temp[0] = ([ "emote"            : "licks "+TO->QP+" lips." ]);
                temp[1] = ([ "say"              : "now that you mention it, I'm kind of hungry myself." ]);
                temp[2] = ([ "endfuncobjstr"    : func ]);
                break;
            default:
                temp[0] = ([ "say"              : "okay, I could stand a bite to eat too." ]);
                temp[1] = ([ "endfuncobjstr"    : func ]);
                break;
            }
            break;
        }
        break;

    case "light":

        map["str"] = "light";
        map["obj"] = TO;
        temp[0] = ([ "say"              : "let there be light." ]);
        temp[1] = ([ "endfuncobjstr"    : func ]);
        break;

    case "dark":

        map["str"] = "darkness";
        map["obj"] = TO;
        temp[0] = ([ "say"              : "fine, I can make it darker." ]);
        temp[1] = ([ "endfuncobjstr"    : func ]);
        break;

    case "animate object":

        map["str"] = "animate object";

        temp[0] = ([ "emote"            : "looks around" ]);
        temp[1] = ([ "emote"            : "hmms" ]);
        temp[2] = ([ "say"              : "I don't know.  I guess it's worth a shot." ]);
        temp[3] = ([ "say"              : "it's always good to have something other than yourself to get beat on." ]);
        temp[4] = ([ "endfuncobjstr"    : func ]);
        break;

    case "water breathing":

        map["str"] = "water breathing";
        for(i=0;i<sizeof(allies);i++)
        {
            if(!objectp(allies[i])) { continue; }
            if(allies[i] == TO) { continue; }
            if(environment(allies[i]) != ETO) { continue; }
            if(allies[i]->query_property("water breather")) { continue; }
            targ = allies[i];
        }

        if(objectp(targ))
        {
            map["obj"] = targ;
            temp[0] = ([ "emote"            : "nods" ]);
            temp[1] = ([ "say"              : "we wouldn't want you to drown now, would we?." ]);
            temp[2] = ([ "endfuncobjstr"    : func ]);
        }
        else
        {
            temp[0] = ([ "emote"    : "takes a quick look around" ]);
            temp[1] = ([ "emote"    : "shakes "+TO->QP+" head" ]);
            temp[2] = ([ "say"      : "I don't think anybody here is going to drown." ]);
            temp[3] = ([ "endblank" : 0 ]);
        }

        break;



    // conversation below here

    case "hello":

        switch(random(6))
        {
        case 0:
            temp[0] = ([ "emote"    : "nods" ]);
            temp[1] = ([ "say"      : "hello there." ]);
            temp[2] = ([ "endblank" : 0 ]);
            break;
        case 1:
            temp[0] = ([ "say"      : "howdy" ]);
            temp[1] = ([ "endblank" : 0 ]);
            break;
        case 2:
            temp[0] = ([ "emote"    : "nods "+TO->QP+" head" ]);
            temp[1] = ([ "say"      : "greetings." ]);
            temp[2] = ([ "endblank" : 0 ]);
            break;

        case 3:
            temp[0] = ([ "emote"    : "smiles" ]);
            temp[1] = ([ "say"      : "a pleasure" ]);
            temp[2] = ([ "endblank" : 0 ]);
            break;

        case 4:
            temp[0] = ([ "emote"    : "nods" ]);
            temp[1] = ([ "say"      : "heya" ]);
            temp[2] = ([ "endblank" : 0 ]);
            break;

        default:
            temp[0] = ([ "emote"    : "gives a lopsided grin" ]);
            temp[1] = ([ "say"      : "Ah!  Hi there." ]);
            temp[2] = ([ "endblank" : 0 ]);
            break;
        }
        break;

    case "weather":

        if(objectp(ETO) && ETO->query_property("indoors")) // don't bother talking about the weather when indoors
        {
            TALKING = 0;
            return;
        }

        vars["season"] = season(time());
        vars["weather"] = WEATHER_D->get_weather(TO);
        vars["weather"] = FILTERS_D->filter_colors(vars["weather"]);
        vars["weather"] = replace_string(vars["weather"],".","");
        vars["climate"] = WEATHER_D->get_climate(TO);
        vars["time"] = TOD;
        vars["temp"] = WEATHER_D->get_temp(TO);

        switch(random(4))
        {
        case 0: // temperature

            switch(vars["temp"])
            {
            case 55..80:

                temp[0] = ([ "say"      : "It's too bad the temperature outside isn't like this all the time." ]);
                temp[1] = ([ "endblank" : 0 ]);
                break;

            case 81..94:

                temp[0] = ([ "emote"    : "mutters under "+TO->QP+" breath" ]);
                temp[1] = ([ "say"      : "damn it's hot out here." ]);
                temp[2] = ([ "endblank" : 0 ]);
                break;

            case 95..200:

                switch((string)TO->query_gender())
                {
                case "male":
                    temp[0] = ([ "emote"    : "pulls off "+TO->QP+" helm and wipes the sweat from "+TO->QP+" brow." ]);
                    temp[1] = ([ "say"      : "if it gets any hotter out here, my balls are going to boil like a couple of eggs." ]);
                    temp[2] = ([ "endblank" : 0 ]);
                    break;
                default:
                    temp[0] = ([ "emote"    : "pulls off "+TO->QP+" helm and wipes the sweat from "+TO->QP+" brow." ]);
                    temp[1] = ([ "emote"    : "runs "+TO->QP+" hand back through "+TO->QP+" hair and then puts the helm back on." ]);
                    temp[2] = ([ "say"      : "I'm cooking in this armor." ]);
                    temp[3] = ([ "endblank" : 0 ]);
                    break;
                }
                break;

            default:

                switch((string)TO->query_gender())
                {
                case "male":
                    temp[0] = ([ "emote"    : "shivers and rubs "+TO->QP+" hands together" ]);
                    temp[1] = ([ "say"      : "I hate the cold." ]);
                    temp[2] = ([ "endblank" : 0 ]);
                    break;
                default:
                    temp[0] = ([ "emote"    : "grimaces and rubs at the chest plate of "+TO->QP+" armor" ]);
                    temp[1] = ([ "say"      : "this weather is not good when you're wearing a big suit of metal armor." ]);
                    temp[2] = ([ "endblank" : 0 ]);
                    break;
                }
                break;
            }
            break;

        case 1: // weather

            if(member_array("cloudy",explode(vars["weather"]," ")) != -1)
            {
                temp[0] = ([ "emote"    : "looks up towards the sky" ]);
                temp[1] = ([ "say"      : "You think it's going to rain?" ]);
                temp[2] = ([ "endblank" : 0 ]);
                break;
            }

            if(member_array("clear",explode(vars["weather"]," ")) != -1)
            {
                temp[0] = ([ "emote"    : "glances briefly upwards" ]);
                temp[1] = ([ "say"      : "well, at least it's not cloudy out" ]);
                temp[2] = ([ "endblank" : 0 ]);
                break;
            }

            if(member_array("raining lightly",explode(vars["weather"]," ")) != -1)
            {
                temp[0] = ([ "say"      : "damn rain, gets all in my armor and makes everything wet." ]);
                temp[1] = ([ "endblank" : 0 ]);
                break;
            }

            if(member_array("raining moderately",explode(vars["weather"]," ")) != -1)
            {
                temp[0] = ([ "say"      : "it's really pouring down now." ]);
                temp[1] = ([ "say"      : "all my stuff is drenched." ]);
                temp[2] = ([ "endblank" : 0 ]);
                break;
            }

            if(member_array("raining heavily",explode(vars["weather"]," ")) != -1)
            {
                temp[0] = ([ "emote"    : "holds "+TO->QP+" shield above "+TO->QP+" head to stop the rain." ]);
                temp[1] = ([ "say"      : "I hope I don't drown in this downpour." ]);
                temp[2] = ([ "say"      : "would be just my luck.. armor gets water tight and fills up with rain, and I drown in my own plate." ]);
                temp[3] = ([ "endblank" : 0 ]);
                break;
            }

            if(member_array("snowing lightly",explode(vars["weather"]," ")) != -1)
            {
                temp[0] = ([ "say"      : "everything looks so peaceful when the snow first starts to fall." ]);
                temp[1] = ([ "say"      : "you know, until we get blood all over it." ]);
                temp[2] = ([ "endblank" : 0 ]);
                break;
            }

            if(member_array("snowing moderately",explode(vars["weather"]," ")) != -1)
            {
                temp[0] = ([ "emote"    : "squints and peers into the distance." ]);
                temp[1] = ([ "say"      : "can you see anything through this?" ]);
                temp[2] = ([ "say"      : "if this snow starts falling much harder, it's going to be a full on blizzard." ]);
                temp[3] = ([ "endblank" : 0 ]);
                break;
            }

            if(member_array("snowing heavily",explode(vars["weather"]," ")) != -1)
            {
                temp[0] = ([ "say"      : "I can barely see my own hand in front of my face." ]);
                temp[1] = ([ "say"      : "maybe we should get indoors and out of this before we get burried and freeze to death" ]);
                temp[2] = ([ "endblank" : 0 ]);
                break;
            }
            break;

        case 2: // climate

            if(member_array("temperate",explode(vars["climate"]," ")) != -1)
            {
                temp[0] = ([ "say"      : "you've got to love these temperate climates." ]);
                temp[1] = ([ "say"      : "well, for most of the year at least." ]);
                temp[2] = ([ "endblank" : 0 ]);
                break;
            }

            if(member_array("tropical",explode(vars["climate"]," ")) != -1)
            {
                temp[0] = ([ "emote"    : "looks around with a twisted half-smile, half-frown on "+TO->QP+" face." ]);
                temp[1] = ([ "say"      : "I keep thinking I'm going to find a tropical paradise one day." ]);
                temp[2] = ([ "say"      : "no monsters." ]);
                temp[3] = ([ "say"      : "no crazy natives." ]);
                temp[4] = ([ "say"      : "no giant lizards." ]);
                temp[5] = ([ "say"      : "no undead." ]);
                temp[6] = ([ "say"      : "no pirates." ]);
                temp[7] = ([ "emote"    : "sighs and shakes "+TO->QP+" head." ]);
                temp[8] = ([ "say"      : "just fruity drinks and scantily clad servers." ]);
                temp[9] = ([ "say"      : "no luck yet though." ]);
                temp[10] = ([ "emote"    : "shrugs" ]);
                temp[11] = ([ "endblank" : 0 ]);
                break;
            }

            if(member_array("desert",explode(vars["climate"]," ")) != -1)
            {
                temp[0] = ([ "emote"    : "groans audibly." ]);
                temp[1] = ([ "say"      : "I HATE the desert." ]);
                temp[2] = ([ "say"      : "this armor is like an oven." ]);
                temp[3] = ([ "say"      : "an oven that I'm wearing." ]);
                temp[4] = ([ "endblank" : 0 ]);
                break;
            }

            if(member_array("arctic",explode(vars["climate"]," ")) != -1)
            {
                temp[0] = ([ "say"      : "I'm glad you brought us some place so cold." ]);
                temp[1] = ([ "say"      : "I haven't lost a toe to frost bite in at least a week." ]);
                temp[2] = ([ "emote"    : "rolls "+TO->QP+" eyes" ]);
                temp[3] = ([ "endblank" : 0 ]);
                break;
            }

            if(member_array("mountain",explode(vars["climate"]," ")) != -1)
            {
                temp[0] = ([ "emote"    : "keeps watching the sky warily" ]);
                temp[1] = ([ "say"      : "the thing about mountains.." ]);
                temp[2] = ([ "say"      : "dragons seem to like them." ]);
                temp[3] = ([ "endblank" : 0 ]);
                break;
            }
            break;

        case 3: // time of day

            if(member_array("night",explode(vars["time"]," ")) != -1)
            {
                temp[0] = ([ "emote"    : "looks at the moon" ]);
                temp[1] = ([ "emote"    : "looks around at the sky" ]);
                temp[2] = ([ "say"      : "I've always liked night time" ]);
                temp[3] = ([ "say"      : "especially if it's clear enough to see the stars." ]);
                temp[4] = ([ "endblank" : 0 ]);
                break;
            }

            if(member_array("dawn",explode(vars["time"]," ")) != -1)
            {
                temp[0] = ([ "say"      : "another day almost started" ]);
                temp[1] = ([ "say"      : "some priest of Jarmila is jumping for joy right now." ]);
                temp[2] = ([ "emote"    : "chuckles" ]);
                temp[3] = ([ "endblank" : 0 ]);
                break;
            }

            if(member_array("day",explode(vars["time"]," ")) != -1)
            {
                temp[0] = ([ "say"      : "another day almost started" ]);
                temp[1] = ([ "say"      : "some priest of Jarmila is jumping for joy right now." ]);
                temp[2] = ([ "emote"    : "chuckles" ]);
                temp[3] = ([ "endblank" : 0 ]);
                break;
            }

            if(member_array("twilight",explode(vars["time"]," ")) != -1)
            {
                temp[0] = ([ "emote"    : "looks around warily, squinting at shadows" ]);
                temp[1] = ([ "say"      : "the most dangerous part of the day, twilight." ]);
                temp[2] = ([ "say"      : "still too light for low light vision to work well." ]);
                temp[3] = ([ "say"      : "too dark to see with normal vision very well." ]);
                temp[4] = ([ "say"      : "the shadows are at their longest" ]);
                temp[5] = ([ "say"      : "creatures of the night getting anxious to go on the prowl." ]);
                temp[6] = ([ "emote"    : "looks over "+TO->QP+" shoulder" ]);
                temp[7] = ([ "say"      : "be wary." ]);
                temp[8] = ([ "endblank" : 0 ]);
                break;
            }
            break;

        default: // season

            if(member_array("summer",explode(vars["season"]," ")) != -1)
            {
                temp[0] = ([ "emote"    : "frowns" ]);
                temp[1] = ([ "say"      : "summer..  well, at least it's not winter." ]);
                temp[2] = ([ "emote"    : "chuckles" ]);
                temp[3] = ([ "endblank" : 0 ]);
                break;
            }

            if(member_array("autumn",explode(vars["season"]," ")) != -1)
            {
                temp[0] = ([ "say"      : "fall is the most colorful time of the year." ]);
                temp[1] = ([ "say"      : "if you're not in the tropics anyway." ]);
                temp[2] = ([ "say"      : "or the arctic." ]);
                temp[3] = ([ "emote"    : "hmms" ]);
                temp[4] = ([ "endblank" : 0 ]);
                break;
            }

            if(member_array("winter",explode(vars["season"]," ")) != -1)
            {
                temp[0] = ([ "say"      : "I can hardly ever get warm in the winter." ]);
                temp[1] = ([ "say"      : "cold to the bones even with a fire, it seems." ]);
                temp[2] = ([ "say"      : "I think it must be all in my head." ]);
                temp[3] = ([ "emote"    : "shrugs" ]);
                temp[4] = ([ "say"      : "I hate winter." ]);
                temp[5] = ([ "endblank" : 0 ]);
                break;
            }

            if(member_array("spring",explode(vars["season"]," ")) != -1)
            {
                temp[0] = ([ "emote"    : "smiles" ]);
                temp[1] = ([ "say"      : "Ah, spring." ]);
                temp[2] = ([ "say"      : "birds chirping, everything turning green again" ]);
                temp[3] = ([ "say"      : "no more freezing my ass off in this armor" ]);
                temp[4] = ([ "emote"    : "grins" ]);
                temp[5] = ([ "say"      : "my favorite time of year." ]);
                temp[6] = ([ "endblank" : 0 ]);
                break;
            }
            break;
        }
        break;

    case "abilities":

        switch(random(2))
        {
        case 0:
            temp[0] = ([ "emote"    : "smirks" ]);
            temp[1] = ([ "say"      : "sure, I've got a lot of talents." ]);
            temp[2] = ([ "say"      : "like standing around and looking pretty." ]);
            temp[3] = ([ "say"      : "then collecting my share of your gold." ]);
            temp[4] = ([ "emote"    : "chuckles" ]);
            temp[5] = ([ "say"      : "there's nothing quite as sweet as money for doing nothing." ]);
            temp[6] = ([ "emote"    : "rolls "+TO->QP+" eyes" ]);
            temp[7] = ([ "say"      : "I know what I'm doing, don't worry about me." ]);
            temp[8] = ([ "say"      : "I'll even try to keep you alive." ]);
            temp[9] = ([ "say"      : "you know, repeat customers and all that." ]);
            temp[10] = ([ "endblank" : 0 ]);
            break;
        case 1:
            temp[0] = ([ "emote"    : "nods" ]);
            temp[1] = ([ "say"      : "yeah, yeah.  I have some skills." ]);
            temp[2] = ([ "say"      : "I'm a damn good healer, if I do say so myself." ]);
            temp[3] = ([ "say"      : "I can cure most of your ailments." ]);
            temp[4] = ([ "say"      : "the usual ones from battle anyhow" ]);
            temp[5] = ([ "say"      : "blindness." ]);
            temp[6] = ([ "say"      : "poisons." ]);
            temp[7] = ([ "say"      : "the usual." ]);
            temp[8] = ([ "say"      : "I'm not bad in a fight either." ]);
            temp[9] = ([ "say"      : "but I try to focus on keeping paying customers alive." ]);
            temp[10] = ([ "say"      : "just think of me as a warrior priest, that's about the sum of it." ]);
            temp[11] = ([ "emote"    : "chuckles then shrugs" ]);
            temp[12] = ([ "say"      : "a warrior priest that gets paid for "+TO->QP+" efforts." ]);
            temp[13] = ([ "emote"    : "grins" ]);
            temp[14] = ([ "endblank" : 0 ]);
            break;
        }

        break;

    case "prices":

        switch(random(2))
        {
        case 0:
            temp[0] = ([ "say"      : "don't worry." ]);
            temp[1] = ([ "say"      : "you'll be getting your money's worth" ]);
            temp[2] = ([ "say"      : "I'm well worth the cost." ]);
            temp[3] = ([ "emote"    : "dips into a shallow bow" ]);
            temp[4] = ([ "say"      : "you'll see for yourself." ]);
            temp[5] = ([ "endblank" : 0 ]);
            break;
        case 1:
            temp[0] = ([ "emote"    : "sighs" ]);
            temp[1] = ([ "say"      : "well, there's the initial payment for my services." ]);
            temp[2] = ([ "say"      : "and you'll owe double that amount when you try to higher another merc for each day you keep me past the first." ]);
            temp[3] = ([ "say"      : "so unless you want a big bill the next time you want to hire one of us." ]);
            temp[4] = ([ "say"      : "you better not forget to send me back when we're done." ]);
            temp[5] = ([ "emote"    : "grins." ]);
            temp[6] = ([ "say"      : "cause technically, I'm still in your service till you send me away." ]);
            temp[7] = ([ "say"      : "I do get my cut when you pay that big bill that I mentioned, afterall." ]);
            temp[8] = ([ "emote"    : "winks" ]);
            temp[9] = ([ "endblank" : 0 ]);
            break;
        }
        break;

    case "love of money":

        switch(random(2))
        {
        case 0:
            temp[0] = ([ "emote"    : "looks away blissfully." ]);
            temp[1] = ([ "say"      : "ah.. money" ]);
            temp[2] = ([ "say"      : "my favorite thing in the world." ]);
            temp[3] = ([ "emote"    : "smiles" ]);
            temp[4] = ([ "say"      : "platinum and gold and silver and copper and even electrum." ]);
            temp[5] = ([ "say"      : "sometimes I daydream about mountains of the stuff." ]);
            temp[6] = ([ "say"      : "I would climb to the top then ride down on a sled made of solid gold." ]);
            temp[7] = ([ "emote"    : "sighs wistfully" ]);
            temp[8] = ([ "endblank" : 0 ]);
            break;
        case 1:
            temp[0] = ([ "emote"    : "perks up" ]);
            temp[1] = ([ "say"      : "did somebody say something about money?" ]);
            temp[2] = ([ "say"      : "that's my favorite subject." ]);
            temp[3] = ([ "endblank" : 0 ]);
            break;
        }

        break;

    case "give back":
    case "pack mule":

        switch(random(2))
        {
        case 0:
            temp[0] = ([ "emote"    : "smirks" ]);
            temp[1] = ([ "say"      : "do you see big ears and a tail on me?" ]);
            temp[2] = ([ "emote"    : "looks over "+TO->QP+" shoulder, down towards "+TO->QP+" backside." ]);
            temp[3] = ([ "say"      : "no?" ]);
            temp[4] = ([ "say"      : "that's right, because I'm not a damn pack mule." ]);
            temp[5] = ([ "say"      : "don't give something to me unless you intend for me to keep it." ]);
            temp[6] = ([ "endblank" : 0 ]);
            break;
        case 1:
            temp[0] = ([ "emote"    : "shakes "+TO->QP+" head" ]);
            temp[1] = ([ "say"      : "I don't carry junk for you." ]);
            temp[2] = ([ "say"      : "if you give it to me, it's mine" ]);
            temp[3] = ([ "say"      : "end of discussion" ]);
            temp[4] = ([ "endblank" : 0 ]);
            break;
        }
        break;

    case "big sack":

        switch(random(2))
        {
        case 0:
            temp[0] = ([ "emote"    : "grins" ]);
            temp[1] = ([ "say"      : "you have no idea." ]);
            temp[3] = ([ "say"      : "I don't think this thing has a bottom in it." ]);
            temp[4] = ([ "say"      : "I haven't managed to fill it up yet." ]);
            temp[5] = ([ "say"      : "and believe me, I've tried" ]);
            temp[6] = ([ "endblank" : 0 ]);
            break;
        case 1:
            temp[0] = ([ "say"      : "yeah, I need this sack to carry all the kits I need." ]);
            temp[1] = ([ "say"      : "people drag me around to the most dangerous places." ]);
            temp[2] = ([ "say"      : "all kinds of monsters trying to kill me" ]);
            temp[3] = ([ "endblank" : 0 ]);
            break;
        }
        break;

    case "my unit":

        switch(random(2))
        {
        case 0:
            temp[0] = ([ "say"      : "well, actually" ]);
            temp[1] = ([ "say"      : "we were several small groups" ]);
            temp[2] = ([ "say"      : "our bosses realized they could make more money if we banded together" ]);
            temp[3] = ([ "say"      : "stop fighting wars in the south and start working for adventurers in the north" ]);
            temp[4] = ([ "say"      : "less danger, more money." ]);
            temp[5] = ([ "say"      : "everybody wins" ]);
            temp[6] = ([ "endblank" : 0 ]);
            break;
        case 1:
            temp[0] = ([ "say"      : "you know how it goes." ]);
            temp[1] = ([ "say"      : "find some people who want to get rich." ]);
            temp[2] = ([ "say"      : "join together" ]);
            temp[3] = ([ "say"      : "form a big mercenary band" ]);
            temp[4] = ([ "say"      : "profit" ]);
            temp[5] = ([ "endblank" : 0 ]);
            break;
        }
        break;

    case "god":

        switch(random(2))
        {
        case 0:
            temp[0] = ([ "emote"    : "smirks" ]);
            temp[1] = ([ "say"      : "that's a real personal question" ]);
            temp[2] = ([ "say"      : "how about, none of your business" ]);
            temp[3] = ([ "endblank" : 0 ]);
            break;
        case 1:
            temp[0] = ([ "say"      : "one of the boss' only rules." ]);
            temp[1] = ([ "say"      : "don't talk to the customers about religion." ]);
            temp[2] = ([ "say"      : "bad for business" ]);
            temp[3] = ([ "emote"    : "chuckles" ]);
            temp[4] = ([ "say"      : "also, try not to get the customers killed" ]);
            temp[5] = ([ "say"      : "which is also bad for business" ]);
            temp[6] = ([ "endblank" : 0 ]);
            break;
        }
        break;

    case "insult":

        switch(random(3))
        {
        case 0:
            temp[0] = ([ "emote"    : "smirks" ]);
            temp[1] = ([ "say"      : "are you trying to poke fun at me?" ]);
            temp[2] = ([ "say"      : "how about I just stand here and you can heal yourself, hmm?" ]);
            temp[3] = ([ "endblank" : 0 ]);
            break;
        case 1:
            temp[0] = ([ "say"      : "yeah, yeah, I'm doing all the work and you're talking shit." ]);
            temp[1] = ([ "endblank" : 0 ]);
            break;
        case 2:
            temp[0] = ([ "say"      : "are you talking to me, sweetie?" ]);
            temp[1] = ([ "say"      : "better make sure you've got your big girl pants on first" ]);
            temp[2] = ([ "endblank" : 0 ]);
            break;
        }
        break;

    case "name":

        switch(random(6))
        {
        case 0:
            temp[0] = ([ "emote"    : "raises an eyebrow" ]);
            temp[1] = ([ "say"      : "huh?" ]);
            temp[3] = ([ "endblank" : 0 ]);
            break;
        case 1:
            temp[0] = ([ "say"      : "what?" ]);
            temp[1] = ([ "endblank" : 0 ]);
            break;
        case 2:
            temp[0] = ([ "say"      : "yes?" ]);
            temp[2] = ([ "endblank" : 0 ]);
            break;
        case 3:
            temp[0] = ([ "say"      : "what is it?" ]);
            temp[2] = ([ "endblank" : 0 ]);
            break;
        case 4:
            temp[0] = ([ "emote"    : "rolls "+TO->QP+" eyes" ]);
            temp[1] = ([ "say"      : "what now?" ]);
            temp[2] = ([ "endblank" : 0 ]);
            break;
        case 5:
            temp[0] = ([ "emote"    : "sighs" ]);
            temp[1] = ([ "say"      : "yeah?" ]);
            temp[2] = ([ "endblank" : 0 ]);
            break;
        }
        break;

    default: // don't say or do anything here
        TALKING = 0;
        return;
    }

    map["events"] = temp;
    call_out("process_speech_event",map["delay"],map);

}

// can receive emotes and respond to them here
void receive_message(string cl,string msg)
{
    if(cl != "emote") { return ::receive_message(cl,msg); }

    if(ACTING) { return; }
    if(TALKING) { return; }



    //tell_room(ETO,"emote: "+cl);
    //tell_room(ETO,"msg: "+msg);

}

void catch_say(string str)
{
    object *allies;
    if(TALKING) { return; }
    if(!interactive(TP)) { return; } // don't need them listening to monsters for now
    if(ACTING) { return; }
    if(sizeof(TO->query_attackers())) { return; }
    allies = query_allies();
    if(member_array(TP,allies) == -1) { return; }
    parse_speech(str,TP);
    return;
}

// will just talk about the weather for now, add more crap later
void perform_random_emote()
{
    parse_speech("weather",TO);
    return;
}

// make sure the henchman is in combat with all of the owner's attackers
void adjust_attackers(object *attackers)
{
    int i;

    if(!objectp(TO)) { return; }
    if(!pointerp(attackers)) { return; }
    if(!sizeof(attackers)) { return; }

    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i]))
        {
            TO->remove_attacker(0);
            continue;
        }
        if(!objectp(ETO) || !objectp(environment(attackers[i])) || (ETO != environment(attackers[i])) )
        {
            TO->remove_attacker(attackers[i]);
            attackers[i]->remove_attacker(TO);
            continue;
        }
        if(attackers[i]->is_merc())
        {
            say("Yeah, the company would really like US to fight.  We better stop before we get our pay docked.");
            TO->remove_attacker(attackers[i]);
            attackers[i]->remove_attacker(TO);
        }
        if(attackers[i] == OWNER)
        {
            say("Woah now, my contract forbids me from getting into a fight with you boss, I'm outta here.  Call me back "
                "when you've calmed down.");
            TO->move(HENCH_ROOM);
            OWNER->remove_attacker(TO);
            TO->remove_attacker(OWNER);
            TO->cease_all_attacks();
            TO->force_me("dispell sticks into snakes");
            DITCHED = 1;
            return;
        }
        if(interactive(attackers[i]) || attackers[i]->is_guardsman())
        {
            say("Woah now, my contract forbids me from getting into a fight with "+attackers[i]->QCN+ ", I'm outta here.  Call me back "
                "when you're done fighting.");
            TO->move(HENCH_ROOM);
            TO->cease_all_attacks();
            attackers[i]->remove_attacker(TO);
            DITCHED = 1;
            return;
        }
        add_attacker(attackers[i]);
        attackers[i]->add_attacker(TO);
    }
    return;
}

// returns 0 if there's no attacker, otherwise returns number of heart beats attacker has been alive
int query_alive(object attacker)
{
    object *enemies = ({});
    if(!objectp(attacker)) { return 0; }
    enemies = keys(ENEMIES);
    if(member_array(attacker,enemies) == -1) { return 0; }
    return ENEMIES[attacker];
}

// rebuilds a list of enemies and keeps track of how many heartbeats they have been enemies
mapping refresh_enemies(object *attackers)
{
    object *objs;
    mapping enemies = ([]);

    int i,count;

    if(!pointerp(attackers) || !sizeof(attackers))
    {
        ENEMIES = ([]);
        enemies = ENEMIES;
        return enemies;
    }

    objs = keys(ENEMIES);

    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i])) { continue; }

        if(member_array(attackers[i],objs) == -1) { enemies += ([ attackers[i] : 1 ]); }
        else
        {
            count = ENEMIES[attackers[i]];
            count++;
            enemies += ([ attackers[i] : count ]);
        }
    }

    ENEMIES = enemies;
    //tell_room(ETO,"ENEMIES: "+identify(ENEMIES));
    return enemies;
}

// checks various status effects, used to decide which actions to take in combat
string *query_status_effects(object obj)
{
    string *effects = ({});
    int num;

    if(!objectp(obj)) { return ({}); }

    num = obj->query_hp_percent();
    if(!num || !intp(num)) { num = 0; }

    switch(num)
    {
        case 1..39:     effects += ({ "low health" });  break;
        case 40..79:    effects += ({ "mid health" });  break;
        case 80..10000: effects += ({ "high health" }); break;
        default:        effects += ({ "unconscious" }); break;
    }

    if(obj->query_tripped())                { effects += ({ "tripped" }); }
    if(obj->query_paralyzed())              { effects += ({ "paralyzed" }); }
    if(obj->query_blind())                  { effects += ({ "blind" }); }
    if(POISON_D->is_poisoned(obj))          { effects += ({ "poisoned" }); }
    if(obj->query_property("no knockdown")) { effects += ({ "no knockdown" }); }
    if(obj->query_property("no death"))     { effects += ({ "no death" }); }
    if(obj->query_property("no hold"))      { effects += ({ "no hold" }); }
    if(obj->query_property("no tripped"))   { effects += ({ "no tripped" }); }

    return effects;
}


void resolve_party()
{
    object *members,leader;
    string party;

    party = (string)OWNER->query_party();

    if(!stringp(party) || party == "" || party == " ")
    {
        party = ""+OWNER->query_name()+" party";
    }

    members = PARTY_D->query_party_members(party);
    if(pointerp(members) && sizeof(members))
    {
        if(member_array(TO,members) != -1) { return; }
    }

    if(!(PARTY_COUNTER%5)) // should give them around 30 seconds to change party names if they want to join another group
    {
        PARTY_D->add_member(OWNER,party);
        PARTY_D->remove_member(TO);
        PARTY_D->add_member(TO,party);
    }

    // not 100% sure when this is happening, but sometimes the hireling is getting made the party leader.  We don't want this
    leader = PARTY_D->query_leader(party);
    if(objectp(leader))
    {
        if(leader == TO)
        {
            PARTY_D->change_leader(OWNER);
        }
    }

    PARTY_COUNTER++;
}


object *query_allies()
{
    object *allies = ({});
    string party;

    if(!objectp(OWNER)) { return ({}); }
    party = (string)OWNER->query_party();
    if(!stringp(party) || party == "" || party == " ") { return ({}); }
    allies = PARTY_D->query_party_members(party);
    if(!pointerp(allies) || !sizeof(allies) || (member_array(TO,allies) == -1))
    {
        return ({});
    }
    return allies;
}


void kit_me()
{
    int i,uses,level,num;
    object kit,newkit,sack;
    string type;

    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }

    kit = present("kitxyz",TO);

    if(objectp(kit)) { uses = (int)kit->query_uses(); }

    level = (int)TO->query_level();
    switch(level)
    {
    case 0..11:
        type = "/d/common/obj/potion/healing";
        break;
    case 12..24:
        type = "/d/common/obj/potion/extra_heal";
        break;
    case 25..34:
        type = "/d/common/obj/potion/advanced_heal";
        break;
    default:
        type = "/d/common/obj/potion/legendary_heal";
        break;
    }

    sack = present("sack",TO);
    if(!objectp(sack)) { sack_me(); return; }

    if(objectp(kit) && objectp(sack) && base_name(kit) != type)
    {
        tell_room(ETO,TO->QCN+" puts "+kit->query_short()+" into "+sack->query_short());
        num = kit->move(sack);
        if(num != MOVE_OK)
        {
            kit->move("/d/shadowgate/void");
            kit->remove();
        }
        return;
    }

    if(!objectp(kit) || uses < 35)
    {
        newkit = new(type);
        newkit->set_uses(30);
        newkit->set_property("monsterweapon",1);
        if(objectp(sack))
        {
            sack->set_max_internal_encumbrance(1000000);
            newkit->move(sack);
            TO->force_me("get kit from sack");
            TO->force_me("combine kit with kit");
        }
        else
        {
            newkit->move(TO);
            TO->force_me("combine kit with kit");
        }

    }
    if(objectp(kit = present("kitxyz",TO)))
    {
        kit->set_property("no animate",1);
        kit->set_property("no steal",1);
    }
    return;
}


int is_ally(object obj)
{
    if(!objectp(obj)) { return 0; }
    if(obj == TO) { return 0; }
    if(obj == OWNER) { return 0; }
    if(member_array(obj,query_allies()) == -1) { return 0; }
    return 1;
}


int has_fodder()
{
    int i;
    object *live,*fodder=({});
    mixed tmp;

    if(!objectp(TO)) { return 0; }
    if(!objectp(ETO)) { return 0; }

    live = all_living(ETO);

    if(!sizeof(live)) { return 0; }

    for(i=0;i<sizeof(live);i++)
    {
        if(!objectp(live[i])) { continue; }
        if(!tmp = live[i]->query_property("minion")) { continue; }
        if(tmp != TO) { continue; }
        fodder += ({ live[i] });
    }
    return sizeof(fodder);
}


string get_id(object obj)
{
    string *ids=({});
    int i;

    if(!objectp(obj)) { return ""; }

    ids = (string*)obj->query_id();
    if(!pointerp(ids)) { return ""; }
    if(!sizeof(ids)) { return ""; }

    return ids[0];
}


int target_check(object obj)
{
    object *allies;
    if(!objectp(obj)) { return 0; }
    allies = query_allies();
    if(member_array(obj,allies) == -1) { return 1; }
    return 0;
}


void perform_action(object obj,string action)
{
    int level,i,count;
    object *allies=({}),cast, targ;
    string *effects=({}),spell, targ_id;

    if(!objectp(obj)) { return; }
    if(!objectp(TO)) { return; }
    if(TO->query_casting()) { return; }

    level = (int)TO->query_level();
    level = level + (level / 2); // giving them a boost since they aren't very smart in how they use spells
    ACTING = 1;

    while(i < 20 && !target_check(targ))
    {
        targ_id = get_id(obj)+" "+i;
        targ = present(targ_id,ETO);
        i++;
    }

    switch(action)
    {
    case "blade barrier":

        cast = new("/cmds/spells/b/_blade_barrier")->use_spell(TO,0,level,100,"cleric");
        break;

    case "aura of healing":

        switch(level)
        {
            case 0..14: ACTING = 0; return;
            default:        spell = "/cmds/spells/a/_aura_of_healing";    break;
        }

        cast = new(spell)->use_spell(TO,0,level,100,"cleric");
        break;

    case "mass heal":

        allies = query_allies();
        if(!pointerp(allies) || !sizeof(allies)) { break; }
        for(i=0;i<sizeof(allies);i++)
        {
            if(!objectp(allies[i])) { continue; }
            effects = query_status_effects(allies[i]);
            if(!sizeof(effects)) { continue; }
            if(member_array("mid health",effects) != -1) { count++; }
            if(member_array("low health",effects) != -1) { count++; }
            if(FLAG) { count++; FLAG = 0; }
        }
        if(count)
        {
            switch(level)
            {
            case 1..4:      spell = "_mass_cure_light_wounds";       break;
            case 5..7:      spell = "_mass_cure_moderate_wounds";    break;
            case 8..11:     spell = "_mass_cure_serious_wounds";     break;
            case 12..15:    spell = "_mass_cure_critical_wounds";    break;
            default:        spell = "_mass_heal";                    break;
            }

            cast = new("/cmds/spells/m/"+spell)->use_spell(TO,obj,level,100,"cleric");
            return;
        }

        break;

    case "heal":

        if(TIMERS["heal"] > time()) { break; }
        TIMERS["heal"] = time() + ROUND_LENGTH*3;

        switch(level)
        {
            case 0..15:     spell = "/c/_cure_critical_wounds";        break;
            default:        spell = "/h/_heal";                        break;
        }
        if(environment(obj) != OTO) { return; }
        cast = new("/cmds/spells"+spell)->use_spell(TO,obj,level,100,"cleric");
        break;

    case "neutralize poison":

        if(environment(obj) != OTO) { return; }
        cast = new("/cmds/spells/n/_neutralize_poison")->use_spell(TO,obj,level,100,"cleric");
        break;

    case "remove paralysis":

        if(environment(obj) != OTO) { return; }
        cast = new("/cmds/spells/r/_remove_paralysis")->use_spell(TO,obj,level,100,"cleric");
        break;

    case "cure blindness":

        if(environment(obj) != OTO) { return; }
        cast = new("/cmds/spells/r/_remove_blindness")->use_spell(TO,obj,level,100,"cleric");
        break;

    case "summon fodder":

        if(time() < TIMERS["fodder"]) { return; }
        if(has_fodder() < 3)
        {
            TIMERS["fodder"] = time() + 25;
            new("/cmds/spells/s/_sticks_into_snakes")->use_spell(TO,0,level,100,"cleric");
            return;
        }

        break;

    case "flame strike":

        if(environment(obj) != OTO) { return; }
        new("/cmds/spells/f/_flame_strike")->use_spell(TO,obj,level,100,"cleric");
        break;

    case "sound burst":

        if(environment(obj) != OTO) { return; }
        new("/cmds/spells/s/_sound_burst")->use_spell(TO,obj,level,100,"cleric");
        break;

    case "greater dispel":

        if(environment(obj) != OTO) { return; }
        new("/cmds/spells/g/_greater_dispel_magic")->use_spell(TO,obj,level,100,"cleric");
        break;

    case "shieldbash":

        if(environment(obj) != OTO) { return; }
        TO->force_me("shieldbash "+targ_id);
        break;

    case "shatter":

        if(environment(obj) != OTO) { return; }
        TO->force_me("shatter "+targ_id);
        break;

    case "disarm":

        if(environment(obj) != OTO) { return; }
        TO->force_me("disarm "+targ_id);
        break;

    case "rush":

        if(environment(obj) != OTO) { return; }
        TO->force_me("rush "+targ_id);
        break;

    case "call lightning":

        if(environment(obj) != OTO) { return; }
        new("/cmds/spells/c/_call_lightning")->use_spell(TO,obj,level,100,"cleric");
        break;

    case "food":
    case "water":

        switch(level)
        {
        case 0..15:
            new("/cmds/spells/c/_create_food")->use_spell(TO,0,level,100,"cleric");
            new("/cmds/spells/c/_create_water")->use_spell(TO,0,level,100,"cleric");
            break;
        default:
            new("/cmds/spells/h/_heroes_feast")->use_spell(TO,0,level,100,"cleric");
            break;
        }

        break;

    case "animate object":

        new("/cmds/spells/a/_animate_object")->use_spell(TO,"room",level,100,"cleric");
        break;

    case "light":

        if(environment(obj) != OTO) { return; }
        new("/cmds/spells/l/_light")->use_spell(TO,obj,level,100,"cleric");
        break;

    case "darkness":

        if(environment(obj) != OTO) { return; }
        new("/cmds/spells/d/_darkness")->use_spell(TO,obj,level,100,"cleric");
        break;

    case "water breathing":

        if(environment(obj) != OTO) { return; }
        new("/cmds/spells/w/_water_breathing")->use_spell(TO,obj,level,100,"cleric");
        break;
    }
    return;
}


void make_decision(object obj,string friendorfoe)
{
    object *attackers=({}),*spelled=({});
    string *effects,effect;
    int i,alive;

    if(!objectp(TO)) { return ""; }
    if(!objectp(OWNER)) { return ""; }
    if(!objectp(obj)) { return ""; }

    if(TO->query_casting()) { return; }

    effects = query_status_effects(obj);

    if(sizeof(effects))
    {
        for(i=0;i<sizeof(effects);i++)
        {
            effect = effects[i];

            switch(friendorfoe)
            {

            case "friend":

                switch(effect)
                {
                    case "unconscious":
                    case "low health":
                    case "mid health": // these fall through intentionally

                        perform_action(obj,"heal");
                        break;

                    case "paralyzed":

                        perform_action(obj,"remove paralysis");
                        break;

                    case "blind":

                        perform_action(obj,"cure blindness");
                        break;

                    case "poisoned":

                        perform_action(obj,"neutralize poison");
                        break;
                }

                break;

            default:

                if(!has_fodder())
                {
                    if(!ETO->query_property("no sticks"))
                    {
                        perform_action(obj,"summon fodder");
                        return;
                    }
                }

                attackers = TO->query_attackers();

                if(sizeof(attackers) > 2)
                {
                    switch(random(3))
                    {
                    case 0:  perform_action(obj,"sound burst");  return;
                    default: perform_action(obj,"flame strike"); return;
                    }
                }
                else
                {
                    if(!random(4))
                    {
                        spelled = (object*)obj->query_property("spelled");
                        if(pointerp(spelled) && ( sizeof(spelled) > 2)) { perform_action(obj,"greater dispel"); return; }
                        if(obj->query_casting()) { perform_action(obj,"shieldbash"); return; }
                    }
                    switch(random(100))
                    {
                        case 11..40: perform_action(obj,"call lightning"); return;
                        default: break; // don't do anything here, they should just have normal melee attacks some rounds
                    }
                }
                break;
            }
        }
    }
    return;
}


void decision_matrix(object *allies,object *attackers)
{
    int i;
    if(!objectp(TO)) { return; }
    if(!objectp(OWNER)) { return; }

    if(TO->query_casting()) { return; }

    if(COMBAT_TIME && !sizeof(attackers))
    {
        if(!ETO->query_property("no sticks") && !has_fodder())
        {
            perform_action(TO,"summon fodder");
        }
        if(sizeof(allies))
        {
            for(i=0;i<sizeof(allies);i++)
            {
                if(!objectp(allies[i])) { continue; }
                if((int)allies[i]->query_hp() >= (int)allies[i]->query_max_hp()) { continue; }
                perform_action(TO,"mass heal");
                break;
            }
        }
        if(!TO->query_property((string)TO->query_name()+"_aura_of_healing")) { perform_action(TO,"aura of healing"); }
        if(!TO->query_property("blade barrier")) { perform_action(TO,"blade barrier"); }
    }

    if(sizeof(attackers) && !ACTING) // priority order of self, owner, friends, enemies
    {
        make_decision(TO,"friend");
        make_decision(OWNER,"friend");
        if(sizeof(allies))
        {
            for(i=0;i<sizeof(allies);i++)
            {
                if(!objectp(allies[i])) { continue; }
                if(allies[i] == TO) { continue; }
                if(allies[i] == OWNER) { continue; }
                if(environment(allies[i]) != ETO) { continue; }
                make_decision(allies[i],"friend");
            }
        }
        if(sizeof(attackers))
        {
            for(i=0;i<sizeof(attackers);i++)
            {
                if(!objectp(attackers[i])) { continue; }
                make_decision(attackers[i],"foe");
            }
        }
    }
    return;
}

void set_temp_owner()
{
    int i;
    object *allies=({});
    allies = query_allies();

    if(!pointerp(allies) || !sizeof(allies))
    {
        TEMP_OWNER = 0;
        return;
    }

    for(i=0;i<sizeof(allies);i++)
    {
        if(!objectp(allies[i])) { continue; }
        if(allies[i] == TO) { continue; }
        if(allies[i]->query_ghost()) { continue; }
        TEMP_OWNER = allies[i];
        return;
    }
    return;
}

void ditch_hire() { DITCHED = 1; }

void toggle_following() { DITCHED = 0; }

// this is to avoid having more than one henchman for each three real players
void party_check()
{
    int i,allowed,players=0,mercs=0;
    object *allies=({}),*hires=({});
    mapping map;

    allies = query_allies();
    if(!sizeof(allies)) { return; }
    for(i=0;i<sizeof(allies);i++)
    {
        if(!objectp(allies[i])) { continue; }
        if(allies[i]->is_merc())
        {
            hires += ({ allies[i] });
            mercs++;
        }
        players++;
    }

    allowed = players/3;
    if(!allowed) { allowed = 1; }

    if(mercs > allowed)
    {
        for(i=0;i<sizeof(hires);i++)
        {
            if(hires[i] == TO ) { continue; }
            hires[i]->ditch_hire();
            hires[i]->move(HENCH_ROOM);
            hires[i]->remove();
        }

        map = ([]);

        map["delay"] = 0.9;
        map["counter"] = 0;
        map["events"] = ([  1 : (["say"      : "our contract forbids more than one of us from working with any adventuring party of less than three."]),
                            2 : (["say"      : "the rest of us will go wait until you're done with your group." ]),
                            4 : (["say"      : "or you can sort it out yourselves."]),
                            5 : (["endblank" : 0 ]), ]);
        TALKING = 1;
        call_out("process_speech_event",map["delay"],map);
    }
    return;
}


int in_pkill()
{
    object *attackers=({});
    int i;
    if(!objectp(OWNER)) { return 0; }
    attackers = OWNER->query_attackers();
    if(!sizeof(attackers)) { return 0; }
    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i])) { continue; }
        if(interactive(attackers[i])) { return 1; }
    }
    return 0;
}


void heart_beat()
{
    object *attackers,*tmp,*allies,obj;
    mapping map;

    ACTING = 0;
    BEAT = 0;
    if(FIRED && objectp(TO))
    {
        TO->move(HENCH_ROOM);
        TO->remove();
    }

    if(!objectp(TO)) { return; }

    if((int)TO->query_hp() < 0)
    {
        die(TO);
        return;
    }

    if(!TO->query_name()) { return; }
    if(!objectp(ETO)) { return; }

    reset_condition();

    ::heart_beat();

    if(!objectp(OWNER))
    {
        TO->move(HENCH_ROOM);
        if(IDLE_TIME > 1000) { TO->remove(); }
        if(objectp(obj = find_player(OWNER_NAME))) // if they haven't timed out before the owner logs back in, then bond with the owner again
        {
            OWNER = obj;
            return;
        }
        return;
    }

    if(!objectp(MY_WHISTLE))
    {
        if(!objectp(OWNER))
        {
            TO->move(HENCH_ROOM);
            TO->remove();
            return;
        }
        fire_me();
        return;
    }

    party_check();

    if(!FEATS_D->is_active(TO,"hardenedminions")) { TO->force_me("hardenedminions"); }

    if(time() > END_TIME + DAY)
    {
        fire_me();
        return;
    }

    if((time() > (END_TIME + DAY - 600)) && !NOTIFIED_TWICE && (ETO == OTO))
    {
        map = ([]);

        map["delay"] = 0.9;
        map["counter"] = 0;
        map["events"] = ([  0 : (["emote"    : "frowns" ]),
                            1 : (["say"      : "look boss, I like traveling with you and all."]),
                            2 : (["say"      : "but we're just about at the far limit of my contract." ]),
                            4 : (["say"      : "A few more minutes and I have to leave, no matter what"]),
                            5 : (["endblank" : 0 ]), ]);
        TALKING = 1;
        NOTIFIED_TWICE = 1;
        call_out("process_speech_event",map["delay"],map);
        return;
    }

    if(time() > (END_TIME - 600) && (ETO == OTO))
    {
        if(!NOTIFIED && !sizeof(TO->query_attackers()))
        {
            map = ([]);

            map["delay"] = 0.9;
            map["counter"] = 0;
            map["events"] = ([  0 : (["emote"    : "looks up at the sky" ]),
                                1 : (["say"      : "my contract is about up boss."]),
                                2 : (["say"      : "you'll have to pay double if you keep me longer than my contract lasts for." ]),
                                4 : (["say"      : "just keep that in mind."]),
                                5 : (["endblank" : 0 ]), ]);
            TALKING = 1;
            NOTIFIED = 1;
            call_out("process_speech_event",map["delay"],map);
            return;
        }
    }

    if((time() > END_TIME) && !DOUBLE_PRICE)
    {
        DOUBLE_PRICE = 1;
        HENCH_D->penalize(OWNER_NAME,"late");
    }

    if(objectp(TEMP_OWNER))
    {
        if(environment(REAL_OWNER) == ETO)
        {
            TEMP_OWNER = 0;
            OWNER = REAL_OWNER;

            map = ([]);

            map["delay"] = 0.9;
            map["counter"] = 0;
            map["events"] = ([  0 : (["emote"    : "smiles" ]),
                                1 : (["say"      : "there you are, boss"]),
                                2 : (["say"      : "glad Kelemvor didn't decide to keep you." ]),
                                3 : (["emote"    : "mutters under "+TO->QP+" breath" ]),
                                4 : (["say"      : "still lost my damn bonus though."]),
                                5 : (["endblank" : 0 ]), ]);
            TALKING = 1;
            call_out("process_speech_event",map["delay"],map);
            OWNER->add_follower(TO);
            return;
        }
    }

    if(ETO != OTO)
    {
        if((ALONE > 20) && !DITCHED)
        {
            TO->move(HENCH_ROOM);
            TO->cease_all_attacks();
            ALONE = 0;
        }
        if((ETO != HENCH_ROOM) && !DITCHED) { ALONE++; }
        if(OWNER->query_ghost())
        {
            if(sizeof(query_allies()) < 3) { return; } // shouldn't do anything here if the owner and the merc are the only ones in the party
            set_temp_owner();
            if(objectp(TEMP_OWNER))
            {
                REAL_OWNER = OWNER;
                OWNER = TEMP_OWNER;

                map = ([]);

                map["delay"] = 0.9;
                map["counter"] = 0;
                map["events"] = ([  0 : (["emote"    : "grimaces" ]),
                                    1 : (["say"      : "well damn"]),
                                    2 : (["say"      : "there goes my bonus" ]),
                                    3 : (["emote"    : "sighs" ]),
                                    4 : (["say"      : "I guess I'll stick with somebody else unless my customer comes back."]),
                                    5 : (["endblank" : 0 ]), ]);
                TALKING = 1;
                call_out("process_speech_event",map["delay"],map);
                OWNER->add_follower(TO);
                return;
            }

        }
        if(!DITCHED && can_follow(OTO) && !in_pkill())
        {
            // taking this out for now, see if it helps with the mercs getting lost
            //if(sizeof(TO->query_attackers()))
            //{
            //    if(objectp(MY_WHISTLE) && !random(6)) { tell_object(OWNER,"%^GREEN%^The magical whistle vibrates, perhaps the mercenary can't reach you.%^RESET%^"); }
            //    return;
            //}
            TO->move(OTO);
            say("yeah, yeah, I'm back now.  Lost you for a second.");
            OWNER->add_follower(TO);
        }
    }

    attackers = ({});

    if(!objectp(TO)) { return; }

    if((int)TO->query_hp() < 0 ) { return; }

    TO->force_me("combine kit with kit");

    kit_me();

    if(objectp(obj=present("kitxyz",TO))) { obj->set_property("monsterweapon",1); }

    resolve_party(); // joins owner's party or creates a new one.  Waits if owner drops party to give them enough time to join a different one before joining that one

    attackers = TO->query_attackers();
    if(!sizeof(attackers))
    {
        if(TO->query_paralyzed()) { TO->set_paralyzed(0); }
        if(TO->query_tripped()) { TO->set_tripped(0); }
    }
    if(ETO == OTO) { attackers += OWNER->query_attackers(); }
    attackers = distinct_array(attackers);

    refresh_enemies(attackers); // keeps up with the enemies that we've been fighting, and how long we've been fighting them
    adjust_attackers(attackers); // make sure we're actually in combat with all of our enemies

    if(sizeof(attackers))
    {
        COMBAT_TIME+=2;
        if(COMBAT_TIME > 100) { COMBAT_TIME = 100; }
        IDLE_TIME = 0;
    }
    else
    {
        COMBAT_TIME--;
        IDLE_TIME++;
        if(IDLE_TIME > 30 && !random(20))
        {
            perform_random_emote();
            IDLE_TIME = 0;
        }

        if(present("ball of light",TO))
        {
            if(ETO == OTO)
            {
                force_me("give ball of light to "+OWNER->query_name());
            }
        }

        if(present("globe of darkness",TO))
        {
            if(ETO == OTO)
            {
                force_me("give globe of darkness to "+OWNER->query_name());
            }
        }
    }
    if(COMBAT_TIME < 0) { COMBAT_TIME = 0; }
    allies = query_allies();
    decision_matrix(allies,attackers); // decide what to do here then do it
    return;
}

int can_follow(object room)
{
    int i;
    string room_name,tmp;
    room_name = base_name(room);

    if(!objectp(ETO)) { return 0; }
    if(!objectp(OTO)) { return 0; }

    tmp = base_name(ETO);
    if(strsrch(tmp,"/d/magic/room/in_web") != -1) { return 0; }
    tmp = base_name(OTO);
    if(strsrch(tmp,"/d/magic/room/in_web") != -1) { return 0; }

    for(i=0;i<sizeof(EXCLUDED_ROOMS);i++)
    {
        if(strsrch(EXCLUDED_ROOMS[i],room_name) != -1) { return 0; }
    }
    return 1;
}

void die(object ob)
{
    HENCH_D->penalize(OWNER_NAME,"dead");
    if(objectp(OWNER))
    {
        if(objectp(MY_WHISTLE))
        {
            tell_object(OWNER,"The magical whistle vanishes with the mercenary's death.");
            MY_WHISTLE->remove();
            if(objectp(MY_WHISTLE)) { destruct(MY_WHISTLE); }
        }
    }
    ::die(ob);
    if(objectp(TO)) { TO->remove(); }
}
