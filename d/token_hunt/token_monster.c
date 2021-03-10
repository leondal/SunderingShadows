#include <std.h>
#include <bardcomps.h>
#include "token_hunt.h"

inherit MONSTER;

#include <spellcomponents.h>

#define CLASSES         ({"thief","mage","fighter","cleric","ranger","antipaladin","psion"})
#define MULTICLASS      ([ "thief" : ({ "mage","fighter","psion" }), "mage" : ({ "thief","cleric","fighter" }), "cleric" : ({ "fighter","mage","psion" }), "psion" : ({ "fighter","thief","cleric" }), ])
#define TYPES           ({"human","half-elf","elf","gnome","drow","hobgoblin","voadkyn","beastman","halfling","half-orc","dwarf","goblin","bugbear","firbolg","ogre","half-ogre","orc","half-drow"})
#define SIZES           (["human" : 2,"half-elf" : 2,"elf" : 2,"gnome" : 1,"drow" : 2,"hobgoblin" : 2,"voadkyn" : 3,"beastman" : 2,"halfling" : 1,"half-orc" : 2,"dwarf" : 2,"goblin" : 1,"bugbear" : 2,"firbolg" : 3,"ogre" : 3,"half-ogre" : 3,"orc" : 2,"half-drow" : 2, ])
#define STYLES          ({"%^BOLD%^%^WHITE%^feathers%^RESET%^%^CYAN%^","%^BOLD%^%^BLACK%^s%^RESET%^%^CYAN%^w%^BLUE%^i%^CYAN%^r%^BOLD%^%^BLACK%^ls%^RESET%^%^CYAN%^","%^RED%^flames%^RESET%^%^CYAN%^","%^BLUE%^waves%^RESET%^%^CYAN%^","%^GREEN%^v%^ORANGE%^i%^BOLD%^%^BLACK%^n%^RESET%^%^GREEN%^e%^ORANGE%^s%^RESET%^%^CYAN%^","%^BOLD%^%^GREEN%^leaves%^RESET%^%^CYAN%^"})
#define HAIRS           ({"%^YELLOW%^blonde%^RESET%^%^CYAN%^","%^RED%^red%^RESET%^%^CYAN%^","%^RESET%^%^ORANGE%^brown%^RESET%^%^CYAN%^","%^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^","%^RESET%^gray%^RESET%^%^CYAN%^"})
#define FACES           ({"narrow","wide","heartshaped","hawkish","oval","long"})
#define EYES            ({"%^BOLD%^%^BLUE%^blue%^RESET%^%^CYAN%^","%^GREEN%^green%^RESET%^%^CYAN%^","%^RESET%^%^ORANGE%^h%^GREEN%^a%^BOLD%^%^BLACK%^z%^RESET%^%^GREEN%^e%^ORANGE%^l%^RESET%^%^CYAN%^","%^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^","%^RESET%^%^ORANGE%^brown%^RESET%^%^CYAN%^"})
#define CRYSTALS        ({"%^RED%^ruby%^RESET%^%^CYAN%^","%^GREEN%^jade%^RESET%^%^CYAN%^","%^BOLD%^%^BLACK%^onyx%^RESET%^%^CYAN%^","%^BOLD%^%^BLUE%^sapphire%^RESET%^%^CYAN%^","%^YELLOW%^amber%^RESET%^%^CYAN%^","%^BOLD%^%^WHITE%^diamond%^RESET%^%^CYAN%^","%^RESET%^%^ORANGE%^topaz%^RESET%^%^CYAN%^"})
#define PRIESTS         ({"mace","hammer","flail","morningstar"})
#define SEARCH_PATHS    ([ "fighter" : ({"/cmds/fighter"}), "mage" : ({"/cmds/spells"}), "thief" : ({"/cmds/thief"}), "ranger":({"/cmds/ranger","/cmds/spells"}),"antipaladin":({"/cmds/cavalier","/cmds/antipaladin","/cmds/spells"}),"cleric":({"/cmds/spells"}),"psion":({"/cmds/psion","/cmds/spells"}) ])
#define CLASS_STYLES    ([ "heavy" : ({ "fighter","antipaladin","cleric" }), "light" : ({ "thief","ranger" }),"general" : ({ "mage","psion" }), ])

string MYTYPE,MYSTYLE,MYHAIR,MYFACE,MYEYE,MYCRYSTAL,MYPRIEST,MYCLASS,MYCLASS_TWO,MYGENDER,MONSTER_LEVEL;
string *ABILITIES=({}),EXIT;
object *ENEMIES=({});
int SPLIT,MINIONS;

void set_abilities()
{
    string *abilities=({});
    if(TO->is_class("thief"))       { ABILITIES += ({ "scramble","knockdown" }); }
    if(TO->is_class("mage"))        { ABILITIES += ({ "stoneskin","guardians","blink","lower" }); }
    if(TO->is_class("fighter"))     { ABILITIES += ({ "rush","sunder","shatter","knockdown","shieldbash" }); }
    if(TO->is_class("cleric"))      { ABILITIES += ({ "heal","snakes","aura","regeneration","precision" }); }
    if(TO->is_class("ranger"))      { ABILITIES += ({ "whirl","dispel","knockdown" }); }
    if(TO->is_class("antipaladin")) { ABILITIES += ({ "turn","snakes","pains","hands","charge","shieldbash" }); }
    if(TO->is_class("psion"))       { ABILITIES += ({ "amorpha","ironbody","crystals","resistance" }); }
    ABILITIES += ({ "powder","net","caress","caltrops","block" });
}

void set_extra_items()
{
    object ob;
    string *extra,*comps=({}),*comp_keys;
    int i,num;

    extra = ({ "/d/tharis/obj/bpowder",
               "/d/laerad/obj/net",
               "/d/dagger/drow/obj/hand",
               "/d/tharis/obj/caltrops",});

    for(i=0;i<sizeof(extra);i++)
    {
        if(!file_exists(extra[i]+".c")) { continue; }
        if(MONSTER_LEVEL == "low" && extra[i] == "/d/dagger/drow/obj/hand") { continue; }
        ob = new(extra[i]);
        if(random(2) && !ob->id("caltrops")) { ob->set_property("monsterweapon",1); }
        ob->move(TO);
    }

    if(TO->is_class("mage") || TO->is_class("psion"))
    {
        num = (int)TO->query_level();
        if(TO->is_class("mage"))
        {
            ob = new("/d/magic/comp_bag");
            ob->move(TO);
            comp_keys = MAGE_COMPONENTS;
            for(i=0;i<num;i++)
            {
                comps += ({ comp_keys[random(sizeof(comp_keys))] });
            }
            for(i=0;i<sizeof(comps);i++)
            {
                ob->remote_set_comp(comps[i],roll_dice(1,num));
            }
        }
        if(TO->is_class("psion"))
        {
            ob = new("/d/magic/psi_comp_bag");
            ob->move(TO);

            comp_keys = PSI_COMPONENTS;
            for(i=0;i<num;i++)
            {
                comps += ({ comp_keys[random(sizeof(comp_keys))] });
            }
            for(i=0;i<sizeof(comps);i++)
            {
                ob->remote_set_comp(comps[i],roll_dice(1,num));
            }
        }
    }
    return;
}

void set_monster_spells()
{
    string *spells = ({});

    switch(MONSTER_LEVEL)
    {
    case "high":

        if(TO->is_class("mage"))
        {
            spells = spells + ({  "scorcher",
                              "hideous laughter",
                             "chain lightning",
                              "meteor swarm",
                                  "prismatic spray",
                                  "meteor swarm",
                                  "cone of cold", });
        }
        if(TO->is_class("cleric"))
        {
            spells = spells + ({  "unholy word",
                                  "unholy word",
                                  "flame strike", });
        }
        if(TO->is_class("psion"))
        {
            spells = spells + ({  "tornado blast",
                                  "ultrablast",
                                  "hail of crystals",
                                  "breath of the black dragon",
                                  "energy cone",});
        }
        if(TO->is_class("ranger"))
        {
            spells = spells + ({  "call lightning",
                                  "cause blindness",
                                  "dispel magic", });
        }
        if(TO->is_class("antipaladin"))
        {
            spells = spells + ({  "cause blindness",
                                  "dispel magic",
                                  "orders oath",
                                  "seeking sword", });
        }
        break;

    case "mid":

        if(TO->is_class("mage"))
        {
            spells = spells + ({ "magic missile",
                                 "scorcher",
                                 "hideous laughter",
                                 "prismatic spray",
                                 "cone of cold", });
        }
        if(TO->is_class("cleric"))
        {
            spells = spells + ({ "unholy orb",
                                 "unholy orb",
                                 "cause blindness",
                                 "flame strike",});
        }
        if(TO->is_class("psion"))
        {
            spells = spells + ({ "swarm of crystals",
                                 "ultrablast",
                                 "breath of the black dragon",
                                 "energy cone",});
        }
        if(TO->is_class("ranger"))
        {
            spells = spells + ({ "call lightning",
                                 "cause blindness",
                                 "dispel magic", });
        }
        if(TO->is_class("antipaladin"))
        {
            spells = spells + ({ "cause blindness",
                                 "dispel magic",
                                 "orders oath",
                                 "seeking sword", });
        }
        break;

    case "low":

        if(TO->is_class("mage"))
        {
            spells = spells + ({ "magic missile",
                                 "scorcher",
                                 "hideous laughter",
                                 "fireball", });
        }
        if(TO->is_class("cleric"))
        {
/*            spells = spells + ({ "lightning touch",
                                 "call lightning",
                                 "cause blindness",
                                 "limb attack",
                                 "hold person",});
*/
            spells = spells + ({ "lightning touch",
                                 "call lightning",
                                 "limb attack",
                                 "hold person",});
        }
        if(TO->is_class("psion"))
        {
            spells = spells + ({ "swarm of crystals",
                                 "mind thrust",
                                 "energy bolt", });
        }
        if(TO->is_class("ranger"))
        {
/*            spells = spells + ({ "call lightning",
                                 "cause blindness",
                                 "dispel magic", });
*/
            spells = spells + ({ "call lightning",
                                 "dispel magic", });
        }
        if(TO->is_class("antipaladin"))
        {
/*            spells = spells + ({ "cause blindness",
                                 "dispel magic",
                                 "orders oath", });
*/
            spells = spells + ({ "dispel magic",
                                 "orders oath", });
        }
        break;
    }

    if(sizeof(spells)) { set_spells(spells); }

    if(TO->is_class("ranger") || TO->is_class("antipaladin"))
    {
        set_spell_chance(20);
        return;
    }
    else if(TO->is_class("cleric") && TO->is_class("mage"))
    {
        set_spell_chance(100);
        return;
    }
    else if(TO->is_class("cleric") && TO->is_class("psion"))
    {
        set_spell_chance(100);
        return;
    }
    else if(TO->query_spells())
    {
        if(TO->is_singleClass()) { set_spell_chance(100); }
        else { set_spell_chance(50); }
    }
    return;
}

void set_weapons()
{
    object ob;

    switch(MONSTER_LEVEL)
    {
    case "high":
        if(TO->is_class("cleric"))
        {
            ob = new("/d/attaya/obj/ice_hammer");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            TO->force_me("wield hammer");
            break;
        }
        if(TO->is_class("thief"))
        {
            ob = new("/d/tharis/obj/wrist_sheath");
            ob->set_property("monsterweapon",1);
            ob->move(TO);
            TO->force_me("wear sheaths");
            ob = new("/d/attaya/obj/screamer");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            ob->move(present("sheath",TO));
            ob = new("/d/attaya/obj/screamer");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            TO->force_me("wield screamer");
            ob = new("/d/attaya/obj/screamer");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            TO->force_me("wield screamer");
            TO->force_me("wield screamer 2");
            break;
        }
        if(TO->is_class("ranger"))
        {
            ob = new("/d/islands/common/obj/rdblade");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            TO->force_me("wield sword");
            ob = new("/d/islands/common/obj/rdblade");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            TO->force_me("wield sword");
            break;
        }
        if(TO->is_class("fighter"))
        {
            ob = new("/d/islands/common/obj/rdblade");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            TO->force_me("wield sword");
            break;
        }
        if(TO->is_class("antipaladin"))
        {
            ob = new("/d/islands/common/obj/rdblade");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            break;
        }
        break;
    case "mid":
        if(TO->is_class("cleric"))
        {
            ob = new("/d/deku/keep/obj/stonecrusherhammer");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            TO->force_me("wield hammer");
            break;
        }
        if(TO->is_class("thief"))
        {
            ob = new("/d/tharis/obj/wrist_sheath");
            ob->set_property("monsterweapon",1);
            ob->move(TO);
            TO->force_me("wear sheaths");
            ob = new("/d/dagger/drow/obj/bldagger");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            ob->move(present("sheath",TO));
            ob = new("/d/dagger/drow/obj/bldagger");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            TO->force_me("wield dagger");
            ob = new("/d/dagger/drow/obj/bldagger");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            TO->force_me("wield dagger");
            TO->force_me("wield dagger 2");
            break;
        }
        if(TO->is_class("ranger"))
        {
            ob = new("/d/tharis/barrow/obj/slayer");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            TO->force_me("wield sword");
            ob = new("/d/tharis/barrow/obj/slayer");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            TO->force_me("wield sword");
            break;
        }
        if(TO->is_class("fighter"))
        {
            ob = new("/d/tharis/barrow/obj/slayer");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            TO->force_me("wield sword");
            break;
        }
        if(TO->is_class("antipaladin"))
        {
            ob = new("/d/tharis/barrow/obj/slayer");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            break;
        }
        break;
    case "low":
        if(TO->is_class("cleric"))
        {
            ob = new("/d/shadow/room/goblin/obj/sceptre");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            TO->force_me("wield sceptre");
            break;
        }
        if(TO->is_class("thief"))
        {
            ob = new("/d/darkwood/yntala/obj/gdagger");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            TO->force_me("wield dagger");
            ob = new("/d/darkwood/yntala/obj/gdagger");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            TO->force_me("wield dagger");
            break;
        }
        if(TO->is_class("ranger"))
        {
            ob = new("/d/shadow/room/goblin/obj/insanity");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            TO->force_me("wield sword");
            ob = new("/d/shadow/room/goblin/obj/insanity");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            TO->force_me("wield sword");
            break;
        }
        if(TO->is_class("fighter"))
        {
            ob = new("/d/shadow/room/goblin/obj/insanity");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            TO->force_me("wield sword");
            break;
        }
        if(TO->is_class("antipaladin"))
        {
            ob = new("/d/shadow/room/goblin/obj/insanity");
            ob->set_property("monsterweapon",1);
            ob->set_size((int)TO->query_size());
            ob->move(TO);
            break;
        }
        break;
    }
    set_monster_spells();
    set_extra_items();
    set_abilities();
    return;
}

void set_inventory(string level)
{
    // general,heavy,light
    string *HIGH_G,*HIGH_H,*HIGH_L;
    string *MID_G,*MID_H,*MID_L;
    string *LOW_G,*LOW_H,*LOW_L;
    string style_ar = ({ "heavy","light","general" });

    int i;
    string style_one,style_two,style,*tmp=({}),*equipment=({});
    object ob;

    HIGH_G = ({ "/d/islands/common/obj/boots",
                "/realms/loki/ogres/obj/bloodrobe",
                "/d/antioch/ruins/obj/ruby_circlet",
                "/d/dagger/derro/obj/moblemanspants",
                "/d/deku/armors/ring_p",
                "/d/islands/common/obj/shimmeringcape2",
                "/d/antioch/ruins/obj/neutralgloves",
                "/d/azha/obj/gmr_ring",});
    HIGH_H = ({ "/d/common/obj/armour/fullplate",
                "/d/common/obj/armour/helm",
                "/d/islands/common/obj/obj-old-nienne/shield",
                "/d/common/obj/armour/greaves",
                "/d/common/obj/armour/gauntlets", });
    HIGH_L =  ({ "/d/common/obj/armour/hide",
                "/d/common/obj/armour/coif_leather",
                "/d/common/obj/armour/bracers", });

    MID_G =  ({ "/d/barriermnts/ruins/obj/sash",
                "/d/dagger/derro/obj/noblemanspants",
                "/d/azha/obj/gmr_ring",
                "/d/deku/keep/obj/obsidianrobe",
                "/d/deku/armours/ring_p",
                "/d/deku/armours/boots_of_twilight",
                "/d/antioch/ruins/obj/ruby_circlet",
                "/d/islands/tonerra/obj/Lcloak",
                "/d/antioch/ruins/obj/neutralgloves", });
    MID_H =  ({ "/d/common/obj/armour/fullplate",
                "/d/common/obj/armour/helm",
                "/d/dagger/derro/obj/shield",
                "/d/common/obj/armour/gauntlets", });
    MID_L =  ({ "/d/common/obj/armour/hide",
                "/d/common/obj/armour/coif_leather",
                "/d/common/obj/armour/bracers", });

    LOW_G =  ({ "/d/azha/obj/mr_ring",
                "/d/common/obj/armour/robe",
                "/d/laerad/parnelli/asgard/sewer/obj/lsboots",
                "/d/shadow/obj/clothing/silkcloak", });
    LOW_H =  ({ "/d/common/obj/armour/fullplate",
                "/d/common/obj/armour/shield",
                "/d/common/obj/armour/helm", });
    LOW_L =  ({ "/d/common/obj/armour/hide",
                "/d/common/obj/armour/bracers", });

    tmp = keys(CLASS_STYLES);
    for(i=0;i<sizeof(tmp);i++)
    {
        if(MYCLASS_TWO)
        {
            if(member_array(MYCLASS_TWO,CLASS_STYLES[tmp[i]]) != -1)
            {
                style_two = tmp[i];
            }
        }
        else
        {
            if(member_array(MYCLASS,CLASS_STYLES[tmp[i]]) != -1)
            {
                style = tmp[i];
            }
        }
    }
    if(MYCLASS_TWO)
    {
        if(member_array(style,style_ar) < member_array(style_two,style_ar))
        {
            style = style_two;
        }
    }

    if(TO->is_class("thief")) { style = "light"; }
    if(TO->is_class("mage") || TO->is_class("psion")) { style = "general"; }


    switch(level)
    {
    case "high":
        switch(style)
        {
        case "general":
            equipment = HIGH_G;
            break;
        case "light":
            equipment = HIGH_G + HIGH_L;
            break;
        case "heavy":
            equipment = HIGH_G + HIGH_H;
            break;
        }
        break;
    case "mid":
        switch(style)
        {
        case "general":
            equipment = MID_G;
            break;
        case "light":
            equipment = MID_G + MID_L;
            break;
        case "heavy":
            equipment = MID_G + MID_H;
            break;
        }
        break;
    case "low":
        switch(style)
        {
        case "general":
            equipment = LOW_G;
            break;
        case "light":
            equipment = LOW_G + LOW_L;
            break;
        case "heavy":
            equipment = LOW_G + LOW_H;
            break;
        }
        break;
    }

    for(i=0;i<sizeof(equipment);i++)
    {
//        tell_object(find_player("nienne"),equipment[i]);
        if(!file_exists(equipment[i]+".c")) { continue; }
        if(!objectp(ob = new(equipment[i]))) { continue; }

        if(level == "low")
        {
            ob->remove_property("enchantment");
        }
        ob->set_size((int)TO->query_size());
        ob->set_property("monsterweapon",1);
        ob->move(TO);
    }
    TO->force_me("wearall");
    set_weapons();
}

void class_setup()
{
    int i,level;
    string *tmp=({});

    set_name(MYTYPE);
    set_race(MYTYPE);
    add_id(MYTYPE);
    add_id(MYCLASS);

    if(MYTYPE == "wemic") { set_body_type("wemic"); }
    else { set_body_type("human"); }

    set_size(SIZES[MYTYPE]);

    set_class(MYCLASS);
    if(MYCLASS_TWO)
    {
        set_class(MYCLASS_TWO);
        add_id(MYCLASS_TWO);
    }

    switch(MONSTER_LEVEL)
    {
    case "high": level = 34 + roll_dice(1,6); break;
    case "mid":  level = 20 + roll_dice(1,6); break;
    case "low":  level = 8  + roll_dice(1,8); break;
    }

    if(MYCLASS_TWO)
    {
        set_mlevel(MYCLASS_TWO,level);
        set_guild_level(MYCLASS_TWO,level);
        tmp = SEARCH_PATHS[MYCLASS_TWO];
        for(i=0;i<sizeof(tmp);i++)
        {
            add_search_path(tmp[i]);
        }
    }
    set_mlevel(MYCLASS,level);

    switch(MYCLASS)
    {
    case "cleric":
    case "antipaladin":
    case "ranger":
        set_guild_level("cleric",level);
        break;
    case "mage":
        set_guild_level("mage",level);
        break;
    case "psion":
        set_guild_level("psion",level);
        break;
    }
    switch(MYCLASS_TWO)
    {
    case "cleric":
    case "antipaladin":
    case "ranger":
        set_guild_level("cleric",level);
        break;
    case "mage":
        set_guild_level("mage",level);
        break;
    case "psion":
        set_guild_level("psion",level);
        break;
    }

    if(pointerp(tmp = SEARCH_PATHS[MYCLASS]))
    {
        for(i=0;i<sizeof(tmp);i++)
        {
            add_search_path(tmp[i]);
        }
    }
    set_hd(level,12);
   set_max_hp(roll_dice(level,30));
    set_hp(query_max_hp());
    set_property("full attacks",1);

    switch(MONSTER_LEVEL)
    {
    case "high":
        set_stats("strength",19);
        set_stats("dexterity",19);
        set_stats("wisdom",19);
        break;
    case "mid":
        set_stats("strength",17);
        set_stats("dexterity",17);
        set_stats("wisdom",17);
        break;
    case "low":
        set_stats("strength",15);
        set_stats("dexterity",15);
        set_stats("wisdom",15);
        break;
    }

    set_inventory(MONSTER_LEVEL);

    return;
}

void initial_setup()
{
    mapping SHORTS;
    string *tmp=({});

    MYTYPE          = TYPES[random(sizeof(TYPES))];
    MYCLASS         = CLASSES[random(sizeof(CLASSES))];
    MYSTYLE         = STYLES[random(sizeof(STYLES))];
    MYHAIR          = HAIRS[random(sizeof(HAIRS))];
    MYFACE          = FACES[random(sizeof(FACES))];
    MYEYE           = EYES[random(sizeof(EYES))];
    MYCRYSTAL       = CRYSTALS[random(sizeof(CRYSTALS))];
    MYPRIEST        = PRIESTS[random(sizeof(PRIESTS))];
    MYGENDER        = random(2)?"male":"female";


    set_gender(MYGENDER);

    if(!random(4))
    {
        tmp = keys(MULTICLASS);
        if(member_array(MYCLASS,tmp) != -1)
        {
            tmp = MULTICLASS[MYCLASS];
            MYCLASS_TWO = tmp[random(sizeof(tmp))];
        }
    }

    SHORTS = ([
        "thief"         : "%^RESET%^%^RED%^A shifting "+MYGENDER+" "+MYTYPE+" with "+MYEYE+"%^RESET%^%^RED%^ eyes and "+MYHAIR+"%^RESET%^%^RED%^ hair",
        "mage"          : "%^RESET%^%^RED%^A bookish "+MYGENDER+" "+MYTYPE+" with "+MYEYE+"%^RESET%^%^RED%^ eyes and "+MYHAIR+"%^RESET%^%^RED%^ hair",
        "fighter"       : "%^RESET%^%^RED%^A grizzled "+MYGENDER+" "+MYTYPE+" with "+MYEYE+"%^RESET%^%^RED%^ eyes and "+MYHAIR+"%^RESET%^%^RED%^ hair",
        "cleric"        : "%^RESET%^%^RED%^A pious "+MYGENDER+" "+MYTYPE+" with "+MYEYE+"%^RESET%^%^RED%^ eyes and "+MYHAIR+"%^RESET%^%^RED%^ hair",
        "ranger"        : "%^RESET%^%^RED%^A woodsy "+MYGENDER+" "+MYTYPE+" with "+MYEYE+"%^RESET%^%^RED%^ eyes and "+MYHAIR+"%^RESET%^%^RED%^ hair",
        "antipaladin"   : "%^RESET%^%^RED%^A gallant "+MYGENDER+" "+MYTYPE+" with "+MYEYE+"%^RESET%^%^RED%^ eyes and "+MYHAIR+"%^RESET%^%^RED%^ hair",
        "psion"         : "%^RESET%^%^RED%^An introspective "+MYGENDER+" "+MYTYPE+" with "+MYEYE+"%^RESET%^%^RED%^ eyes and "+MYHAIR+"%^RESET%^%^RED%^ hair"
             ]);

    set_short(SHORTS[MYCLASS]);

    switch(MYCLASS)
    {
    case "thief":
        set_long("%^RESET%^%^CYAN%^Dressed in thick, supple leather and dark clothing, "
            "this "+MYTYPE+" swaggers with an obvious confidence born out of much practice "
            "and awareness of "+TO->QP+" skills. Stylized designs of "+MYSTYLE+" decorate "
            "the leather armor. Glowing with a faint %^MAGENTA%^arcane light%^CYAN%^, "
            "the "+MYSTYLE+" are pressed into the supple material speaking of high quality "
            "and magical protection. The design carries through other parts of "+TO->QP+" "
            "clothing, appearing along the cuffs of "+TO->QP+" sleeves and on the ankles "
            "of "+TO->QP+" boots. Several small sheaths can be seen tucked about "+TO->QP+" "
            "person, indicative of the capabilities that "+TO->QS+" possesses. "+TO->QP+" "
            "short "+MYHAIR+" hair is almost unseen under a leather cap, only a few stray "
            "bits around "+TO->QP+" "+MYFACE+" face can be seen. Lithe and agile, "+TO->QS+" "
            "moves about, completely silent with "+TO->QP+" "+MYEYE+" eyes always watchful "
            "of "+TO->QP+" surroundings.%^RESET%^");
        break;
    case "mage":
        set_long("%^RESET%^%^CYAN%^"+MYCRYSTAL+" garments of flowing silk adorn this "+MYTYPE+"'s "
            "body and conceal the thin, soft body below. Eyes of "+MYEYE+" nearly glow with "
            "%^MAGENTA%^arcane power%^CYAN%^ as "+TO->QS+" surveys the area. All about "+TO->QO+" "
            "items designed to assist "+TO->QO+" in conjuring can be seen, from the pouch of "
            "components upon "+TO->QP+" belt, to the thick, leather wrapped volume of "+TO->QP+" "
            "spellbook. Even the small sheath at his side sports a glowing blade adorned with "
            "ornate designs of "+MYSTYLE+" etched into the hilt. While fairly small for a "
            "typical "+MYTYPE+", "+TO->QS+" still has a powerful presence about "+TO->QO+" that "
            "might make one hesitant to tangle with his skills.%^RESET%^");
        break;
    case "fighter":
        set_long("%^RESET%^%^CYAN%^Bands of metal enchase this "+MYTYPE+" warrior with their "
            "protective strength. Though a bit dented and battered in some places, the armor "
            "looks almost as a second skin against the ruddy, worn and scarred features. Despite "
            "this, there is an easy confidence and certain prowess about "+TO->QO+" that suggests "
            ""+TO->QS+" has won far more battles then "+TO->QS+" has lost. "+MYEYE+" eyes gleam "
            "from under heavy brows, set into a "+MYFACE+" face. "+MYHAIR+" hair falls to the "
            "shoulders and is a bit damp from prior exertion in such heavy armor. Held at the "
            "ready in one hand is a weapon bedecked in "+MYCRYSTAL+" gems, while in the other "
            "hand a large shield rests, ready to defend.%^RESET%^");
        break;
    case "cleric":
        set_long("%^RESET%^%^CYAN%^A "+MYCRYSTAL+" colored tabard rests over the metal armor of "
            "this "+MYTYPE+" priest. Decorated with several images of "+MYSTYLE+" and "+MYEYE+" "
            "threads along the edge, the garment is kept clean and free of stains. At "+TO->QP+" "
            "hip a holster hangs, within which rests a "+MYCRYSTAL+" "+MYPRIEST+" whose grip is "
            "wrapped in fine, if not a bit worn leather. About "+TO->QP+" neck a "+MYCRYSTAL+" "
            "amulet hangs, etched into its surface is the symbol of "+TO->QP+" faith. With "
            ""+TO->QP+" "+MYHAIR+" hair cut short, the strong, wise features of "+TO->QP+" "
            ""+MYFACE+" face are revealed. Though only of average height for a "+MYTYPE+" the "
            "faith that "+TO->QS+" carries within gives "+TO->QO+" a noble and commanding "
            "stature that draws the eyes and beacons one to follow "+TO->QO+" in furthering "
            "the work of "+TO->QP+" faith.%^RESET%^");
        break;
    case "ranger":
        set_long("%^RESET%^%^CYAN%^A warrior of nature, this "+MYTYPE+" is bedecked in garments "
            "of %^ORANGE%^brown%^CYAN%^ and %^GREEN%^green%^CYAN%^ with highlights of %^BOLD%^"
            "%^BLACK%^blacks%^RESET%^%^CYAN%^, %^BOLD%^%^WHITE%^whites%^RESET%^%^CYAN%^ and "
            "%^RESET%^grays%^CYAN%^ to further enhance "+TO->QP+" ability to blend in with the "
            "surrounding environment. "+TO->QP+" "+MYHAIR+" hair has been drawn back into a neat "
            "braid that is clasped with a simple %^ORANGE%^leather%^CYAN%^ thong. A fine set "
            "of %^ORANGE%^leather%^CYAN%^ armor rests about "+TO->QP+" shoulders, decorated "
            "with brands of "+MYSTYLE+" and other nature symbols. A set of well worn hilts "
            "pokes out from behind "+TO->QP+" cloak, their grips showing a great deal of wear "
            "and long use as though "+TO->QP+" is well accustom to protecting "+TO->QP+"self "
            "and that which "+TO->QS+"cares for.%^RESET%^");
        break;
    case "antipaladin":
        set_long("%^RESET%^%^CYAN%^There is very little to be seen of this knight's appearance "
            "besides the thick sheets of gleaming armor that covers "+TO->QO+" head to toe. "
            "Intense "+MYEYE+" eyes watch from within the narrow slit that cuts across the "
            "front of "+TO->QP+" full helm. A calm watchful gaze that gives a sense of confidence "
            "and security of "+TO->QP+" position within the world. At "+TO->QP+" hip, a bejeweled "
            "blade rests within a fine leather sheath, while a heavy lance and mighty warhorse are "
            "never far from "+TO->QP+" side. Upon the breast plate of "+TO->QP+" armor and along "
            "the shoulderplates and greaves are etched decorations of "+MYSTYLE+" that are enhanced "
            "by slivers of "+MYCRYSTAL+" which glitter in the light.%^RESET%^");
        call_out("horse_me",2);
        break;
    case "psion":
        set_long("%^RESET%^%^CYAN%^This "+MYEYE+"-eyed "+MYTYPE+" is dressed in long flowing robes "
            "that sweep about "+TO->QP+" slender, tall frame. The hem, cuffs and collar all glow "
            "with %^MAGENTA%^s%^BLUE%^w%^WHITE%^i%^BLUE%^r%^MAGENTA%^li%^BLUE%^n%^MAGENTA%^g r"
            "%^BLUE%^u%^WHITE%^n%^MAGENTA%^es %^CYAN%^that appear to take the general shape of "
            ""+MYSTYLE+". "+TO->QP+" long "+MYHAIR+" hair is swept back behind "+TO->QP+" ears "
            "with the bangs held away from "+TO->QP+" "+MYFACE+" face by a %^BOLD%^%^WHITE%^silver "
            "circlet%^RESET%^%^CYAN%^. Hanging from this circlet is a shard of "+MYCRYSTAL+" which "
            "glitters, much like the gleam within "+TO->QP+" knowledgable "+MYEYE+" eyes. A few other "
            "glitters of jewelry can be seen decorating "+TO->QP+" hands and neck, and there always "
            "appears to be a few crystals that "+TO->QS+" keeps loose within "+TO->QP+" fingers. Almost "
            "as if "+TO->QS+" anticipates something happening soon.%^RESET%^");
        break;
    }
    class_setup();
    return;
}

string query_monster_level()
{
    if(MONSTER_LEVEL != "high" && MONSTER_LEVEL != "mid" && MONSTER_LEVEL != "low")
    {
        MONSTER_LEVEL = "high";
    }
    return MONSTER_LEVEL;
}

void set_monster_level(string level)
{
    MONSTER_LEVEL = level;
    initial_setup();
}

void horse_me()
{
    object ob;
    set_nwp("riding",50);
    ob = new("/d/common/mounts/war_horse");
    ob->set_owner(TO);
    ob->set_property("water breather",1);
    ob->set_level((int)TO->query_level());
    ob->set_size((int)TO->query_size());
    ob->move(ETO);
    TO->force_me("mount horse");
    if(objectp(ob) && objectp(TO)) { ob->add_protector(TO); }
    ob = new("/d/common/obj/weapon/lance");
    ob->set_property("enchantment",(int)TO->query_level()/10);
    ob->set_property("monsterweapon",1);
    ob->set_size((int)TO->query_size());
    ob->move(TO);
    TO->force_me("wield lance");
    return;
}

void dest_me()
{
    object *ppl;
    int i;

    if(!objectp(TO)) { return; }
    if(!objectp(ETO))
    {
        destruct(TO);
        return;
    }

    ppl = all_living(ETO);

    for(i=0;i<sizeof(ppl);i++)
    {
        if(!objectp(ppl[i])) { continue; }
        if(ppl[i]->is_player())
        {
            call_out("dest_me",300);
            return;
        }
    }

    TO->move("/d/shadowgate/void");
    destruct(TO);
    return;
}

void create()
{
    ::create();
    set_id(({"monster","token monster","shifter","shapeshifter"}));
    set_property("add kits",50);
    set_alignment(9);
    set_nogo(({"/d/islands/common/aramanth/mountain11"}));
    set_property("demongate flying",1);
    set_property("water breather",1);
    set_property("no death",1);

    //set_speed(1); // remove after they've finished bug finding
    //set_moving(1);
    //set_speed(1);

    set_monster_feats(({ "spell focus",
                         "spell penetration",
                         "perfect caster",
                         "hardenedminions",
						 "expertise",
                         "knockdown",
                         "shieldbash",
						 "powerattack",
						 "shatter",
						 "sunder",
						 "rush",
						 "mounted combat",
						 "ride-by attack",
						 "ambidexterity",
						 "two weapon fighting",
						 "improved two weapon fighting",
						 "parry",
						 "whirl",
						 "dodge",
						 "mobility",
						 "evasion",
						 "spring attack",
						 "combat reflexes"}));

    call_out("dest_me",2700); // remove in 45 minutes if it's not already gone
}

int cast_check(object obj)
{
    if(!objectp(obj)) { return 0; }
    if(obj->query_property("spell_casting")) { return 0; }
    return 1;
}

void non_combat_action(string action)
{
    int num;
    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
    if(!stringp(action)) { return; }
    num = (int)TO->query_level();

    switch(action)
    {
    case "stoneskin":
        if(!TO->query_property("stoneskin_timer") || (int)TO->query_property("stoneskin_timer") < time())
        {
            if(!cast_check(TO)) { break; }
            if(!TO->query_stoneSkinned())
            {
                new("/cmds/spells/s/_stoneskin.c")->use_spell(TO,TO,num,100);
                TO->remove_property("stoneskin_timer");
                TO->set_property("stoneskin_timer",time()+60);
            }
        }
        break;
    case "guardians":
        if(!TO->query_property("my_summon_timer") || (int)TO->query_property("my_summon_timer") < time())
        {
            if(!cast_check(TO)) { break; }
            if(!present("phantom",ETO))
            {
                new("/cmds/spells/p/_phantom_guardians.c")->use_spell(TO,"soldiers",num,100);
                TO->remove_property("my_summon_timer");
                TO->set_property("my_summon_timer",time()+40);
            }
        }
        break;
    case "blink":
        if(!TO->query_property("my_blink_timer") || (int)TO->query_property("my_blink_timer") < time())
        {
            if(!cast_check(TO)) { break; }
            if(!TO->query_blinking())
            {
                TO->set_blinking((int)TO->query_level()+6);
                TO->remove_property("my_blink_timer");
                TO->set_property("my_blink_timer",time() + 60);
            }
        }
        break;
    case "heal":
        if(!TO->query_property("my_heal_timer") || (int)TO->query_property("my_heal_timer") < time())
        {
            if(!cast_check(TO)) { break; }
            if((int)TO->query_hp() < ((int)TO->query_max_hp() - 100))
            {
                new("/cmds/spells/h/_heal.c")->use_spell(TO,TO,num,100);
                TO->remove_property("my_heal_timer");
                TO->set_property("my_heal_timer",time()+25);
            }
        }
        break;
    case "snakes":
        if(!TO->query_property("my_snake_timer") || (int)TO->query_property("my_snake_timer") < time())
        {
            if(!cast_check(TO)) { break; }
            if(!present("snake",ETO))
            {
                new("/cmds/spells/s/_sticks_into_snakes.c")->use_spell(TO,TO,num,100);
                TO->remove_property("my_snake_timer");
                TO->set_property("my_snake_timer",time()+40);
            }
        }
        break;
    case "regeneration":
        if(!TO->query_property("regeneration_spell"))
        {
            if(!cast_check(TO)) { break; }
            new("/cmds/spells/r/_regenerate.c")->use_spell(TO,TO,num,100);
        }
        break;
    case "precision":
        if(!TO->query_property("spell penetration"))
        {
            TO->set_property("spell penetration",num);
        }
        break;
    case "amorpha":
        if(!TO->query_property("amorpha"))
        {
            if(!cast_check(TO)) { break; }
            new("/cmds/spells/c/_concealing_amorpha.c")->use_spell(TO,TO,num,100);
        }
        if(MONSTER_LEVEL != "low")
        {
            if(!cast_check(TO)) { break; }
            if(!TO->query_property("timeless body"))
            {
                new("/cmds/spells/t/_timeless_body.c")->use_spell(TO,TO,num,100);
            }
        }
        break;
    case "ironbody":
        if(!TO->query_property("stoneskin_timer") || (int)TO->query_property("stoneskin_timer") < time())
        {
            if(!cast_check(TO)) { break; }
            if(!TO->query_stoneSkinned())
            {
                new("/cmds/spells/i/_iron_body.c")->use_spell(TO,TO,num,100);
                TO->remove_property("stoneskin_timer");
                TO->set_property("stoneskin_timer",time()+60);
            }
        }
        break;
    case "crystals":
        if(!TO->query_property("my_summon_timer") || (int)TO->query_property("my_summon_timer") < time())
        {
            if(!cast_check(TO)) { break; }
            if(!present("crystal",ETO))
            {
                new("/cmds/spells/c/_call_crystals.c")->use_spell(TO,TO,num,100);
                TO->remove_property("my_summon_timer");
                TO->set_property("my_summon_timer",time()+30);
            }
        }
        break;
    }
}

void combat_action(string action)
{
    object *attackers=({}),*objs=({}),attacker;
    int i,num;
    string *exits=({}),exit,*ids=({});

    if(!stringp(action)) { return; }
    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }

    num = (int)TO->query_level();
    attackers = TO->query_attackers();
    attackers -= ({0});
    attacker = TO->query_current_attacker();
    if(!sizeof(attackers)) { return; }
    if(!objectp(attacker)) { return; }
    exits = ETO->query_exits();

    switch(action)
    {
    case "shieldbash":
        if(TO->query_property("my_shieldbash_timer") || (int)TO->query_property("my_shieldbash_timer") < time())
        {
            TO->force_me("shieldbash "+attacker->query_name()+"");
            TO->remove_property("my_shieldbash_timer");
            TO->set_property("my_shieldbash_timer",time() + 20);
        }
        break;
    case "knockdown":
        if(TO->query_property("my_knockdown_timer") || (int)TO->query_property("my_knockdown_timer") < time())
        {
            TO->force_me("knockdown "+attacker->query_name()+"");
            TO->remove_property("my_knockdown_timer");
            TO->set_property("my_knockdown_timer",time() + 20);
        }
        break;
    case "scramble":
        if(!TO->query_scrambling())
        {
            TO->force_me("scramble");
        }
        break;
    case "lower":
        //if(!objectp(attacker)) { break; }
        //if(!attacker->query_property("lowered resistance"))
        //{
        //    if(!cast_check(TO)) { break; }
        //    new("/cmds/spells/l/_lower_resistance.c")->use_spell(TO,attacker,num,100);
        //}
        //break;
    case "rush":
        for(i=0;i<sizeof(attackers);i++)
        {
            if(!objectp(attackers[i])) { continue; }
            TO->force_me("rush "+attackers[i]->query_name()+"");
        }
        break;
    case "parry":
        if(!TO->query_parrying())
        {
            TO->force_me("parry");
        }
        break;
    case "aura":
        if(!TO->has_property(TO->query_name() + "_aura_of_healing"))
        {
            if(!cast_check(TO)) { break; }
            new("/cmds/spells/a/_aura_of_healing.c")->use_spell(TO,TO,num,100);
        }
        break;
    case "whirl":
        if(!TO->query_property("my_whirl_timer") || (int)TO->query_property("my_whirl_timer") < time())
        {
            TO->force_me("whirl");
            TO->remove_property("my_whirl_timer");
            TO->set_property("my_whirl_timer",time()+10);
        }
        break;
	case "sunder":
        for(i=0;i<sizeof(attackers);i++)
        {
            if(!objectp(attackers[i])) { continue; }
            TO->force_me("sunder "+attackers[i]->query_name()+"");
        }
        break;
	case "shatter":
        for(i=0;i<sizeof(attackers);i++)
        {
            if(!objectp(attackers[i])) { continue; }
            TO->force_me("shatter "+attackers[i]->query_name()+"");
        }
        break;
    case "dispel":
        if(!TO->query_property("my_dispel_timer") || (int)TO->query_property("my_dispel_timer") < time())
        {
            if(!cast_check(TO)) { break; }
            TO->remove_property("my_dispel_timer");
            TO->set_property("my_dispel_timer",time() + 25);
            new("/cmds/spells/d/_dispel_magic.c")->use_spell(TO,0,num,100);
        }
        break;
    case "heal":
        if(!TO->query_property("my_heal_timer") || (int)TO->query_property("my_heal_timer") < time())
        {
            if(!cast_check(TO)) { break; }
            if((int)TO->query_hp() < ((int)TO->query_max_hp() - 100))
            {
                new("/cmds/spells/h/_heal.c")->use_spell(TO,TO,num,100);
                TO->remove_property("my_heal_timer");
                TO->set_property("my_heal_timer",time()+25);
            }
        }
        break;
    case "pains":
        if(!TO->query_property("my_pains_timer") || (int)TO->query_property("my_pains_timer") < time())
        {
            if(!cast_check(TO)) { break; }
            TO->remove_property("my_pains_timer");
            TO->set_property("my_pains_timer",time() + 15);
            TO->force_me("cause wracking pains "+attacker->query_name()+"");
        }
        break;
    case "charge":
        TO->force_me("charge "+attacker->query_name()+"");
        break;
    case "resistance":
        if(!attacker->query_property("lowered psionic"))
        {
            if(!cast_check(TO)) { break; }
            new("/cmds/spells/p/_power_resistance.c")->use_spell(TO,""+attacker->query_name()+" to lower",num,100);
        }
        break;
    case "powder":
        if(!TO->query_property("my_stun_timer") || (int)TO->query_property("my_stun_timer") < time())
        {
            if(!attacker->query_property("powdered"))
            {
                TO->force_me("toss powder at "+attacker->query_name()+"");
                TO->remove_property("my_stun_timer");
                TO->set_property("my_stun_timer",time() + 25);
            }
        }
        break;
    case "net":
        if(!TO->query_property("my_stun_timer") || (int)TO->query_property("my_stun_timer") < time())
        {
            if(present("net",TO))
            {
                TO->force_me("unwield hammer");
                TO->force_me("unwield sceptre");
                TO->force_me("unwield dagger");
                TO->force_me("unwield sword");
                TO->force_me("wield net");
                TO->force_me("throw net at "+attacker->query_name()+"");
                TO->force_me("wield hammer");
                TO->force_me("wield sceptre");
                TO->force_me("wield dagger");
                TO->force_me("wield sword");
                TO->remove_property("my_stun_timer");
                TO->set_property("my_stun_timer",time() + 25);
            }
        }
        break;
    case "caress":
        if(!TO->query_property("my_stun_timer") || (int)TO->query_property("my_stun_timer") < time())
        {
            if(present("hand",TO))
            {
                TO->force_me("caress "+attacker->query_name()+"");
                TO->remove_property("my_stun_timer");
                TO->set_property("my_stun_timer",time()+15);
            }
        }
        break;
    case "caltrops":
        if(!sizeof(exits)) { break; }
        if(present("caltrops",TO))
        {
            EXIT = exits[random(sizeof(exits))];
            TO->force_me("spread caltrops "+EXIT+"");
        }
        break;
    case "block":
        if(!TO->query_paralyzed() && !TO->query_tripped())
        {
            exits -= ({ EXIT });
            if(sizeof(exits) && !TO->query_property("blocking_an_exit"))
            {
                TO->set_property("blocking_an_exit",1);
                exit = exits[random(sizeof(exits))];
                TO->force_me("block "+exit+"");
            }
        }
        break;
    }

    if(TO->query_property("animated by") && (TO->is_class("mage") || TO->is_class("cleric") || TO->is_class("ranger") || TO->is_class("antipaladin") || TO->is_class("psion")))
    {
        if(!TO->query_property("animate_timer") || (int)TO->query_property("animate_timer") < time())
        {
            if(!TO->query_property("animate_timer"))
            {
                TO->set_property("animate_timer",time()+7);
                new("/cmds/spells/d/_dispel_magic")->use_spell(TO,0,num,100);
                return;
            }
            TO->remove_property("animate_timer");
            TO->set_property("animate_timer",time()+12);

            if(pointerp(objs = (object *)TO->query_property("my animated stuff")))
            {
                if(sizeof(objs))
                {
                    for(i=0;i<sizeof(objs);i++)
                    {
                        if(!objectp(objs[i])) { continue; }
                        if(present(objs[i],ETO))
                        {
                            ids = objs[i]->query_id();
                            if(!sizeof(ids)) { continue; }
                            TO->force_me("get "+ids[0]+"");
                            if(present(objs[i],TO)) { TO->remove_property_value("my animated stuff",({ objs[i] })); }
                        }
                    }
                }
            }

            if(TO->is_class("cleric") && pointerp(objs = (object *)TO->query_property("animated by")))
            {
                for(i=0;i<sizeof(objs);i++)
                {
                    if(!objectp(objs[i])) { continue; }
                    if(!present(objs[i],ETO)) { continue; }
                    if(TO->is_class("cleric"))
                    {
                        new("/cmds/spells/a/_animate_object.c")->use_spell(TO,objs[i],num,100);
                        TO->remove_property_value("animated by",({ objs[i] }));
                        return;
                    }
                }
            }
        }
    }
    return;
}

void parse_actions(string type)
{
    int i;

    if(!objectp(TO)) { return; }
    if(!sizeof(ABILITIES)) { return; }
    if(TO->query_paralyzed()) { return; }
    if(TO->query_casting()) { return; }
    if(TO->query_property("spell_casting")) { return; }

    switch(type)
    {
    case "combat":
        for(i=0;i<sizeof(ABILITIES);i++)
        {
            combat_action(ABILITIES[i]);
            non_combat_action(ABILITIES[i]);
        }
        break;
    case "noncombat":
        for(i=0;i<sizeof(ABILITIES);i++)
        {
            non_combat_action(ABILITIES[i]);
        }
        break;
    }
    return;
}

int valid_level(object target)
{
    if(!objectp(TO)) { return 1; }
    if(!objectp(target)) { return 1; }
    if(!interactive(target)) { return 1; }

    switch(MONSTER_LEVEL)
    {
    case "high":
        if((int)target->query_level() < 30) { return 2; }
        break;
    case "mid":
        if((int)target->query_level() < 20) { return 2; }
        if((int)target->query_level() > 30) { return 3; }
        break;
    case "low":
        if((int)target->query_level() < 10) { return 2; }
        if((int)target->query_level() > 20) { return 3; }
        break;
    }
    return 1;
}


void level_reaction(int num,object target)
{
    object room;
    if(!objectp(TO)) { return; }
    if(!objectp(target)) { return; }
    if(!objectp(room=environment(target))) { return; }
    if(ETO != room) { return; }

    switch(num)
    {
    case 2:
        TO->force_me("say You aren't worth my time "+target->query_race()+".");
        TO->force_me("chuckle");
        TO->force_me("say But here's a little something to remember me by.");
        tell_room(room,""+TO->query_short()+" pulls a strange dart from "
            "a fold in "+TO->QP+" clothes and throws it at "+target->QCN+"!",target);
        tell_room(room,"%^RED%^The dart slams into "+target->QCN+" and "
            ""+target->QS+" instantly doubles over in pain!",target);
        tell_object(target,""+TO->query_short()+" pulls a strange dart from "
            "a fold in "+TO->QP+" clothes and quickly throws it at you!");
        tell_object(target,"%^RED%^You try to dodge out of the way but the "
            "throw was perfect and the dart slams into you!");
        tell_object(target,"%^RED%^A wave of posion rips through your body causing "
            "you to convulse in unbearable pain!");
        target->set_paralyzed(roll_dice(1,(int)TO->query_level()),"%^RED%^You are thrasing "
            "on the ground in agony!%^RESET%^");
        target->set_hp(roll_dice(2,12));
        tell_room(room,""+TO->query_short()+" produces a small glass sphere from "
            "a fold in "+TO->QP+" clothes and quickly smashes it!");
        new("/d/tharis/barrow/obj/sphere")->move(TO);
        TO->force_me("smash sphere");
        TO->move("/d/shadowgate/void");
        TO->remove();
        return;
    case 3:
        TO->force_me("say Woah, I don't want any part of this, I'm outta here.");
        tell_room(room,""+TO->query_short()+" produces a small glass sphere from "
            "a fold in "+TO->QP+" clothes and quickly smashes it!");
        new("/d/tharis/barrow/obj/sphere")->move(TO);
        TO->force_me("smash sphere");
        TO->move("/d/shadowgate/void");
        TO->remove();
        return;
    }
    return;
}

// 1 just right, 2 too low, 3 too high
void level_test()
{
    object *attackers =({});
    int i,result;

    attackers = TO->query_attackers();
    if(!objectp(TO)) { return; }
    if(sizeof(attackers))
    {
        for(i=0;i<sizeof(attackers);i++)
        {
            if(!objectp(attackers[i])) { continue; }
            result = valid_level(attackers[i]);
            if(result != 1)
            {
                level_reaction(result,attackers[i]);
                return;
            }
        }
    }
}

void enemy_test()
{
    object *ghosts=({});
    int i;

    if(!objectp(ETO)) { return; }
    if(!sizeof(ENEMIES)) { return; }
    for(i=0;i<sizeof(ENEMIES);i++)
    {
        if(!objectp(ENEMIES[i])) { continue; }
        if(ENEMIES[i]->query_ghost()) { ghosts += ({ ENEMIES[i] }); }
        if(member_array(ENEMIES[i],(object *)TO->query_attackers()) == -1)
        {
            if(present(ENEMIES[i],ETO))
            {
                TO->force_me("kill "+ENEMIES[i]->query_name()+"");
            }
        }
    }
    ENEMIES -= ({0});
    ENEMIES -= ghosts;
    return;
}

void split_vials()
{
    if(!objectp(TO)) { return; }
    if(!present("kit",TO)) { return; }
    TO->force_me("take 10 from kit");
    TO->force_me("take 10 from kit");
    TO->force_me("take 10 from kit");
    TO->force_me("take 10 from kit");
    SPLIT = 1;
    return;
}

void heart_beat()
{
    int i;
    object *attackers=({});

    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }

    level_test();

    ::heart_beat();

    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }

    if(!MINIONS) { TO->force_me("hardenedminions"); MINIONS = 1; }
    if(!SPLIT) { split_vials(); }

    if(objectp(TO) && TO->is_class("antipaladin"))
    {
        if(!TO->query_in_vehicle())
        {
            TO->force_me("mount horse");
            TO->force_me("unwield lance");
            TO->force_me("wield sword");
        }
        else
        {
            TO->force_me("unwield sword");
            TO->force_me("wield lance");
        }
    }

    if(!objectp(TO)) { return; }
    enemy_test();
    attackers = TO->query_attackers();
    if(sizeof(attackers))
    {
        for(i=0;i<sizeof(attackers);i++)
        {
            if(!objectp(attackers[i])) { continue; }
            ENEMIES += ({ attackers[i] });
        }
        ENEMIES = distinct_array(ENEMIES);
        parse_actions("combat");
    }
    else
    {
        if(random(8)) { return; }
        parse_actions("noncombat");
    }
    return;
}

void die(object ob)
{
    object token,obj;
    int i,num;
    string type;

    if(!objectp(TO)) { return; }

    for(i=0;i<5;i++)
    {
        if(objectp(obj=present("kit "+i+"",TO)))
        {
            if(random(2)) { obj->set_property("monsterweapon",1); }
        }
    }

    switch(MONSTER_LEVEL)
    {
    case "high": type = "gold";   num = roll_dice(1,8) + 4; break;
    case "mid":  type = "silver"; num = roll_dice(1,8) + 4; break;
    case "low":  type = "copper"; num = roll_dice(1,8) + 4; break;
    }
    if(!objectp(TO)) { return; }
    for(i=0;i<num;i++)
    {
        token = new(FILE_PATH"single_token.c");
        token->set_token_type(type);
        token->move(TO);
    }
    ::die(ob);
}

int cmd_stab(string str)
{
    if(!objectp(TP)) { return 0; }
    if(!objectp(TO)) { return 0; }
    if(TO->id(str))
    {
        ENEMIES += ({ TP });
        return 0;
    }
    return 0;
}

void init()
{
    ::init();
    add_action("cmd_stab","stab");
    return;
}
