//ACTIVELY USED

/*==============================================================================================================================================
a daemon that handles calculating gear bonuses - in an attempt to make
them easier to handle/degrade with gear damage

Will require extensive lib support - for example -

query_attack_bonus would not return a static number but would query this daemon for a bonus
based on gear in inventory, that is equipped, or gives a static bonus for simply being
held and then would modify this bonus based on current gear condition

Also adding support for some other object checks

    Function can_unequip_item(object who, object item, string myAction)

        can I drop this? (called from Object.c)

        can I unequip this? (called from body.c)

    Function can_equip_item(object who, object item)

        can I equip this? (called from body.c)

================================================================================================================================================*/

#include <std.h>
#include <daemons.h>
#include <security.h>
#include <damage_types.h>
#include <valid_bonuses.h>

#define DIFF_BONUS (["empowered" : ({"caster level", "empowered"}), "caster level" : ({"caster level", "empowered"})])

/**
 * @file
 */

#define BHEAD "%^BOLD%^%^BLUE%^\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n"
inherit DAEMON;

mapping BONUS_CATS = ([
 "saving throw" : ({
         "fortitude",
             "will",
             "reflex"
             }),
 "resistances" : ({
         "acid resistance",                 "acid resistance percent",
             "bludgeoning resistance",          "bludgeoning resistance percent",
             "cold resistance",                 "cold resistance percent",
             "damage resistance",               "damage resistance percent",
             "divine resistance",               "divine resistance percent",
             "electricity resistance",          "electricity resistance percent",
             "fire resistance",                 "fire resistance percent",
             "force resistance",                "force resistance percent",
             "magic resistance",                "magic resistance percent",
             "mental resistance",               "mental resistance percent",
             "negative energy resistance",      "negative energy resistance percent",
             "piercing resistance",             "piercing resistance percent",
             "positive energy resistance",      "positive energy resistance percent",
             "silver resistance",               "silver resistance percent",
             "slashing resistance",             "slashing resistance percent",
             "sonic resistance",                "sonic resistance percent",
             "spell damage resistance",         "spell damage resistance percent",
             "untyped resistance",              "untyped resistance percent",
             "cold iron resistance",            "cold iron resistance percent",
             }),
 "stats" : ({
         "charisma",
             "constitution",
             "dexterity",
             "intelligence",
             "wisdom",
             "strength",
             }),
 "skills" : ({
         "athletics",
             "craft, armorsmith",
             "craft, jeweller",
             "craft, leatherwork",
             "craft, tailor",
             "craft, weaponsmith",
             "craft, woodworker",
             "dungeoneering",
             "endurance",
             "healing",
             "influence",
             "perception",
             "rope use",
             "spellcraft",
             "stealth",
             "survival",
             "thievery",
             "academics",
             }),
 "miscellaneous" : ({
         "attack bonus",
             "bonus level eight spell slots",
             "bonus level five spell slots",
             "bonus level four spell slots",
             "bonus level nine spell slots",
             "bonus level one spell slots",
             "bonus level seven spell slots",
             "bonus level six spell slots",
             "bonus level three spell slots",
             "bonus level two spell slots",
             "bonus level zero spell slots",
             "bonus spell slots",
             "caster level",
             "damage bonus",
             "spellTurning",
             "missChance",
             "shieldMiss",
             "sight bonus",
             "light",
             "spell penetration",
             "temporary feats",
             "armor bonus",
             "fast healing",
             "max hp bonus",
             }),]);


//resistance
object *gear_to_include(object who, string bonus)
{
    object *objs, *gear;
    string *myBonuses,ob_quest, *player_quests;
    mapping tmpMap;
    int x,j;
    if(!objectp(who) || !stringp(bonus)) return ({});
    objs = all_inventory(who);
    gear = ({});
    for(x = 0;x < sizeof(objs);x++)
    {
        if(!objectp(objs[x])) continue;
        if(objs[x]->query_worn() == who ||
        objs[x]->query_wielded() == who ||
        objs[x]->query_property("inanimate bonus"))
        {
            if(!mapp(tmpMap = objs[x]->query_item_bonuses())) continue;

            if(objs[x]->query_property("inanimate bonus") && objs[x]->query_property("quest required"))
            {
                ob_quest = objs[x]->query_property("quest required");
                ob_quest = FILTERS_D->filter_colors(ob_quest);
                ob_quest = lower_case(ob_quest);
                player_quests = who->query_quests();
                player_quests += who->query_mini_quests();
                if(!sizeof(player_quests)) { continue; }
                for(j=0;j<sizeof(player_quests);j++)
                {
                    player_quests[j] = FILTERS_D->filter_colors(player_quests[j]);
                    player_quests[j] = lower_case(player_quests[j]);
                }
                if(member_array(ob_quest, player_quests) == -1) { continue; }
            }
            myBonuses = keys(tmpMap);
            if(member_array(bonus, VALID_DAMAGE_TYPES) != -1)
            {
                if(member_array(bonus, myBonuses) == -1 && member_array(bonus + " resistance", myBonuses) == -1) continue;
                gear += ({objs[x]});
                continue;
            }
            else
            {
                if(member_array(bonus, keys(DIFF_BONUS)) != -1)
                {
                    foreach(string diffbonus in keys(DIFF_BONUS))
                    {
                        if(member_array(diffbonus, myBonuses) == -1) continue;
                        gear += ({objs[x]});
                        break;
                    }
                    continue;
                }
                else if(member_array(bonus, myBonuses) == -1) continue;
                gear += ({objs[x]});
                continue;
            }
            continue;
        }
        continue;
    }
    return gear;
}

int bonus_spell_slots(object ob)
{
    int res = 0;
    if(!objectp(ob)) return 0;
    res += ob->query_item_bonus("bonus_spell_slots");
    res += ob->query_item_bonus("bonus_spell_slots_1");
    res += ob->query_item_bonus("bonus_spell_slots_2");
    res += ob->query_item_bonus("bonus_spell_slots_3");
    res += ob->query_item_bonus("bonus_spell_slots_4");
    res += ob->query_item_bonus("bonus_spell_slots_5");
    res += ob->query_item_bonus("bonus_spell_slots_6");
    res += ob->query_item_bonus("bonus_spell_slots_7");
    res += ob->query_item_bonus("bonus_spell_slots_8");
    res += ob->query_item_bonus("bonus_spell_slots_9");
    return res;
}

mixed gear_bonus(object who, string bonus, int flag)
{
    object *gear;
    int amt = 0, total = 0, actual_amt, cond, x;
    string *bonuses, *temp_feats = ({});
    mixed check;
    mapping my_gear = ([]), tmp = ([]);
    if(!objectp(who) || !stringp(bonus)) return 0;
    //creates a list of gear that should be included in calculating a given bonus
    //either equipped, worn, or gear with the inanimate bonus property on it
    //if(bonus == "caster level") bonus = "empowered";
    if(!sizeof(gear = gear_to_include(who, bonus)))
    {
        if(bonus == "temporary feats") return temp_feats;
        return 0;
    }
    foreach(object item in gear)
    {
        if(!objectp(item)) continue;
        if(member_array(bonus, VALID_DAMAGE_TYPES) != -1)
        {
            actual_amt = item->query_item_bonus(bonus);
            if(!actual_amt) actual_amt = item->query_item_bonus(bonus + " resistance");
            if(!actual_amt) continue;
        }
        /*else if(bonus == "bonus spell slots")
        {
            actual_amt = bonus_spell_slots(item);
            if(!actual_amt) continue;
        }*/
        else if(member_array(bonus, keys(DIFF_BONUS)) != -1)
        {
            foreach(string diffbonus in keys(DIFF_BONUS))
            {
                if(actual_amt > item->query_item_bonus(diffbonus)) continue;
                else actual_amt = item->query_item_bonus(diffbonus);
                continue;
            }
        }
        else
        {
            if(bonus == "temporary feats")
            {
                check = item->query_item_bonus(bonus);
                if(pointerp(check))
                {
                    foreach(string tFeat in check)
                    {
                        temp_feats += ({tFeat});
                        if(!my_gear[bonus]) my_gear += ([bonus : ([ item : ({tFeat}), ]), ]);
                        else if(!my_gear[bonus][item]) my_gear[bonus] += ([ item : ({tFeat}), ]);
                        else my_gear[bonus][item] += ({tFeat});
                        continue;
                    }
                }
                else
                {
                    temp_feats += ({item->query_item_bonus(bonus)});
                    if(!my_gear[bonus]) my_gear += ([bonus : ([item : item->query_item_bonus(bonus)]), ]);
                    else my_gear[bonus] += ([item : item->query_item_bonus(bonus)]);
                }
                continue;
            }
            actual_amt = item->query_item_bonus(bonus);
        }
        if(!actual_amt) continue;
        if(actual_amt < 0 || (WORLD_EVENTS_D->stacking_bonus_active(who) && !WORLD_EVENTS_D->stacking_bonus_active(who, -1)))
        {
            if(bonus == "sight bonus" && member_array((string)who->query_race(),LIVING_D->night_races()) != -1) actual_amt = -1 * actual_amt;
            total += actual_amt;
            if(!my_gear[bonus]) my_gear += ([bonus : ([ item : actual_amt ]), ]);
            else my_gear[bonus] += ([item : actual_amt]);
            actual_amt = 0;
            continue;
        }
        cond = item->query_overallStatus();
        if(cond > 100 || undefinedp(cond)) cond = 100;
        else if(!cond) cond = 1;
        if(cond <= 70) actual_amt = (actual_amt * cond) / 100;
        if(actual_amt > amt && !WORLD_EVENTS_D->stacking_bonus_active(who, -1))
        {
            if(bonus == "sight bonus" && member_array((string)who->query_race(),LIVING_D->night_races()) != -1) tmp = ([item : ([bonus : (actual_amt * -1)]),]);
            else tmp = ([bonus : ([ item : actual_amt ]), ]);
            amt = actual_amt;
        }
        actual_amt = 0;
        continue;
    }
    if(flag)
    {
        bonuses = keys(tmp);
        for(x = 0;x < sizeof(bonuses);x++)
        {
            if(my_gear[bonuses[x]]) my_gear[bonuses[x]] += tmp[bonuses[x]];
            else my_gear += ([bonuses[x] : tmp[bonuses[x]]]);
        }
        return my_gear;
    }
    if(bonus == "sight bonus" && member_array((string)who->query_race(),LIVING_D->night_races()) != -1) amt = amt * -1;
    if(!flag && bonus != "temporary feats") return (total + amt);
    if(!flag && bonus == "temporary feats")
    {
        temp_feats = distinct_array(temp_feats);
        return temp_feats;
    }
}

mixed all_active_bonuses(object who, int flag)
{
    string *myBonuses, Bonus, myDisplay = "", myName, itemDisplay, *SpellSlots;
    string *statDisplay = ({}), *skillDisplay = ({}), *resistanceDisplay = ({}), *savingDisplay = ({}), *miscDisplay = ({});
    mapping myItems, myTmp;
    object item, *items;
    int x, totalBon, y, dodisplay;
    if(!objectp(who)) return 0;
    myName = who->query_true_name();
    myBonuses = VALID_BONUSES;
    if((x = member_array("empowered", myBonuses)) != -1) myBonuses[x] = "caster level";
    myBonuses = distinct_array(myBonuses);
    myBonuses = sort_array(myBonuses, 1);
    myItems = ([]);
    for(x = 0;x < sizeof(myBonuses);x++)
    {
        if(!mapp(myTmp = gear_bonus(who, myBonuses[x], 1))) continue;
        if(!myItems[myBonuses[x]])
        {
            myItems += ([ myBonuses[x] : myTmp[myBonuses[x]], ]);
        }
        else { myItems[myBonuses[x]] += myTmp[myBonuses[x]]; }
        if(myBonuses[x] == "empowered") myBonuses[x] = "caster level";
    }
    for(x = 0;x < sizeof(myBonuses);x++)
    {
        Bonus = myBonuses[x];

        totalBon = 0;
        itemDisplay = "";
        dodisplay = 1;
        if(mapp(myItems[Bonus]))
        {
            items = keys(myItems[Bonus]);
            for(y = 0; y < sizeof(items);y++)
            {
                if(!objectp(item = items[y])) continue;
                if(item->is_identified(myName))
                {
                    itemDisplay += "\n  "+item->query_short()+"%^RESET%^ is granting (%^BOLD%^%^WHITE%^";

                    if(!pointerp(myItems[Bonus][item]))
                    {
                        itemDisplay += myItems[Bonus][item];
                    }
                    else itemDisplay += implode(myItems[Bonus][item], ", ");
                    itemDisplay +=  "%^RESET%^).";
                }
                continue;
            }
        }
        if(strsrch(Bonus, "bonus_spell_slots") != -1)
        {
            if(Bonus == "bonus_spell_slots")
            {
                totalBon = who->query_property("bonus_spell_slots");
                Bonus = "bonus spell slots";
            }
            else
            {
                totalBon = who->query_property(Bonus);
                SpellSlots = explode(Bonus, "_");
                Bonus = SpellSlots[0] + " level " +consolidate_number(to_int(SpellSlots[3])) + " " + SpellSlots[1] + " " +SpellSlots[2];
            }
        }
        else
        {
            switch(Bonus)
            {
            case "sight bonus":
                totalBon = who->query_sight_bonus();
                break;
            case "strength": case "dexterity": case "constitution": case "intelligence": case "wisdom": case "charisma":
                totalBon = who->query_stats(Bonus);
                dodisplay = 0;
                break;
            case "fortitude": case "will": case "reflex":
                totalBon = SAVING_THROW_D->get_save(who, Bonus);
                break;
            case "academics": case "athletics": case "craft, armorsmith": case "craft, jeweller": case "craft, leatherwork":
            case "craft, tailor": case "craft, weaponsmith": case "craft, woodworker": case "disguise": case "dungeoneering":
            case "endurance": case "healing": case "influence": case "perception": case "rope use": case "stealth":
            case "spellcraft": case "survival": case "thievery":
                totalBon = who->query_skill(Bonus);
                dodisplay = 0;
                break;
            case "attack bonus":
                totalBon = who->query_attack_bonus();
                break;
            case "damage bonus":
                totalBon = who->query_damage_bonus();
                break;
            case "armor bonus":
                totalBon = who->query_ac_bonus();
                break;
            case "max hp bonus":
                totalBon = who->query_max_hp_bonus();
                break;
                // misc bonuses held in set_property()
            case "magic resistance": case "spell damage resistance": case "damage resistance": case "spell penetration":
                totalBon = who->query_property(Bonus);
            break;
            case "caster level":
                totalBon = who->query_property("empowered");
                break;
            case "spellTurning":
                totalBon = who->query_spellTurning();
                break;
            case "missChance":
                totalBon = who->query_missChance();
                break;
            case "shieldMiss":
                totalBon = who->query_shieldMiss();
                break;
            case "fast healing":
                totalBon = who->query_property("fast healing");
                break;
            case "light":
                totalBon = who->query_property("light");
                break;
            case "fire resistance": case "cold resistance": case "water resistance": case "air resistance":
            case "earth resistance": case "bludgeoning resistance": case "piercing resistance": case "slashing resistance":
            case "silver resistance": case "cold iron resistance": case "electricity resistance": case "acid resistance": case "sonic resistance":
            case "positive energy resistance": case "negative energy resistance": case "force resistance": case "divine resistance": case "untyped resistance":
            case "mental resistance": case "light resistance": case "darkness resistance": case "nature resistance":
            case "bludgeoning resistance": case "piercing resistance": case "slashing resistance":
            case "positive energy resistance": case "negative energy resistance": case "force resistance": case "divine resistance": case "untyped resistance":
                totalBon = who->query_resistance(replace_string(Bonus, " resistance", ""));
                break;
            case "fire resistance percent": case "cold resistance percent": case "water resistance percent": case "air resistance percent":
            case "earth resistance percent": case "bludgeoning resistance percent": case "piercing resistance percent": case "slashing resistance percent":
            case "silver resistance percent": case "cold iron resistance percent": case "electricity resistance percent": case "acid resistance percent": case "sonic resistance percent":
            case "positive energy resistance percent": case "negative energy resistance percent": case "force resistance percent": case "divine resistance percent": case "untyped resistance percent":
            case "mental resistance percent": case "light resistance percent": case "darkness resistance percent": case "nature resistance percent":
            case "bludgeoning resistance percent": case "piercing resistance percent": case "slashing resistance percent":
            case "positive energy resistance percent": case "negative energy resistance percent": case "force resistance percent": case "divine resistance percent": case "untyped resistance percent":
                totalBon = who->query_resistance_percent(replace_string(Bonus, " resistance percent", ""));
                break;
            case "temporary feats":
                totalBon = sizeof(who->query_temporary_feats());
                break;
            }
        }
        if(!dodisplay && itemDisplay == "" || totalBon == 0)
        {
            continue;
        }
        if(Bonus == "temporary feats")
        {
            myDisplay = "%^RESET%^You have (%^BOLD%^%^WHITE%^"+totalBon+"%^RESET%^)";
            if(totalBon < 2) myDisplay += " %^BOLD%^%^WHITE%^Temporary Feat%^RESET%^.%^RESET%^";
            else myDisplay += " %^BOLD%^%^WHITE%^Temporary Feats%^RESET%^.%^RESET%^";
        }
        else if(Bonus == "caster level")
        {
            myDisplay = "%^RESET%^%^BOLD%^%^WHITE%^"+capitalize(Bonus)+" bonus %^RESET%^is "+
            "(%^BOLD%^%^WHITE%^"+totalBon+"%^RESET%^).";
        }
        else
        {
            myDisplay = "%^RESET%^%^BOLD%^%^WHITE%^"+capitalize(Bonus)+" %^RESET%^is "+
            "(%^BOLD%^%^WHITE%^"+totalBon+"%^RESET%^).";
        }
        if(itemDisplay != "") myDisplay += itemDisplay;
        if(member_array(Bonus, BONUS_CATS["stats"]) != -1)
        {
            if(!sizeof(statDisplay))
            {
                 statDisplay = ({"%^BLUE%^-=%^BOLD%^<%^GREEN%^ Stats %^BLUE%^>%^RESET%^%^BLUE%^=-", myDisplay});
            }
            else statDisplay += ({myDisplay});
        }
        else if(member_array(Bonus, BONUS_CATS["skills"]) != -1)
        {
            if(!sizeof(skillDisplay))
            {
                skillDisplay = ({"\n%^BLUE%^-=%^BOLD%^<%^GREEN%^ Skills %^BLUE%^>%^RESET%^%^BLUE%^=-", myDisplay});
            }
            else skillDisplay += ({myDisplay});
        }
        else if(member_array(Bonus, BONUS_CATS["saving throw"]) != -1)
        {
            if(!sizeof(savingDisplay))
            {
                savingDisplay = ({"\n%^BLUE%^-=%^BOLD%^<%^GREEN%^ Saving Throws %^BLUE%^>%^RESET%^%^BLUE%^=-", myDisplay});
            }
            else savingDisplay += ({myDisplay});
        }
        else if(member_array(Bonus, BONUS_CATS["resistances"]) != -1)
        {
            if(!sizeof(resistanceDisplay))
            {
                resistanceDisplay = ({"\n%^BLUE%^-=%^BOLD%^<%^GREEN%^ Resistances %^BLUE%^>%^RESET%^%^BLUE%^=-", myDisplay});
            }
            else resistanceDisplay += ({myDisplay});
        }
        else if(member_array(Bonus, BONUS_CATS["miscellaneous"]) != -1)
        {
            if(!sizeof(miscDisplay))
            {
                miscDisplay = ({"\n%^BLUE%^-=%^BOLD%^<%^GREEN%^ Miscellaneous %^BLUE%^>%^RESET%^%^BLUE%^=-", myDisplay});
            }
            else miscDisplay += ({myDisplay});
        }
        continue;
    }
    if(flag) return myItems;
    else
    {
        return (statDisplay + skillDisplay + savingDisplay + resistanceDisplay + miscDisplay);
    }
}
