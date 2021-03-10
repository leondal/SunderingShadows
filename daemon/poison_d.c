#include <std.h>
#include <daemons.h>
#define POISON_DIR "/d/common/obj/poisons/base/"
#define VALID_METHODS ({"contact", "injury", "ingested", "inhaled"})

//primarily used to handle how objects that are poisoned apply said poison
#define VALID_INGEST_ACTS ({"eat", "drink", "ingested"})
#define VALID_CONTACT_ACTS ({"wield", "wear", "get", "open", "close", "contact"})
#define VALID_INJURY_ACTS ({"hit", "struck", "injury"})

inherit DAEMON;

mapping VALID_POISONS;
//Applies the poison effect to the targ
varargs void ApplyPoison(object targ, object poison, object poisoner, string ApplyType);

//Should process the primary and secondary
//poison effects
void ProcessPoisons(object vic);
void RemovePoisonByKey(int PoisonKey);
void ClearAllPoisons(object vic);

void BuildPoisonList(int flag)
{
    object tmp_ob;
    string *files, poison_name, file;
    int x;
    if(!mapp(VALID_POISONS)) VALID_POISONS = ([]);
    if(sizeof(get_dir(POISON_DIR)) != sizeof(keys(VALID_POISONS)) ||
    flag == 1)
    {
        VALID_POISONS = ([]);

        files = get_dir(POISON_DIR);

        for(x = 0;x < sizeof(files);x++)
        {
            if(!file_exists(POISON_DIR+files[x])) continue;
            tmp_ob = new(POISON_DIR+files[x]);
            file = POISON_DIR+files[x];
            if(!objectp(tmp_ob)) continue;
            poison_name = tmp_ob->query_poison_name();
            if(!VALID_POISONS[file])
            {
                VALID_POISONS[file] = (["DC" : tmp_ob->query_poison_dc(),
                "ApplyType" : tmp_ob->query_delivery_method(), "PoisonName" : poison_name]);
                tmp_ob->remove();
                //destruct(tmp_ob);
                continue;
            }
            continue;
        }
    }
}

void query_poison_application_type(string poison)
{
    int x;
    string tmp, *pnames;
    if(!stringp(poison)) return;
    if(!mapp(VALID_POISONS)) BuildPoisonList(0);
    pnames = keys(VALID_POISONS);
    if(!sizeof(pnames)) return;
    for(x = 0;x < sizeof(pnames);x++)
    {
        if(VALID_POISONS[pnames[x]]["PoisonName"] != poison) continue;
        return VALID_POISONS[pnames[x]]["ApplyType"];
    }
    return;
}


void RebuildPoisonList() { BuildPoisonList(1); }

varargs void QueryPoisonObject(mixed poison, string ApplyType, int Lev)
{
    mapping tmp_mapping = ([]);
    string file, *poisons, *files;
    object tmp_ob;
    int flag = 0, x, y;
    if(!poison) return;

    BuildPoisonList(0);

    if(file_exists(poison+".c") || file_exists(poison))
    {
        flag = 1;
        tmp_ob = new(poison);
        if(tmp_ob->is_poison()) return tmp_ob;
        else tmp_ob->remove();
    }

    poisons = keys(VALID_POISONS);
    if(stringp(ApplyType))
    {
        for(x = 0;x < sizeof(poisons);x++)
        {
            if(VALID_POISONS[poisons[x]]["ApplyType"] == ApplyType)
            {
                tmp_mapping[poisons[x]] = VALID_POISONS[poisons[x]];
                continue;
            }
            continue;
        }
    }
    else tmp_mapping = VALID_POISONS;
    poisons = keys(tmp_mapping);

    if(!sizeof(poisons)) return;

    if(poison == "random" || poison == "any")
    {
        if(!intp(Lev) || !Lev)
        {
            file = poisons[random(sizeof(poisons))];
            tmp_ob = new(file);
            if(objectp(tmp_ob)) return tmp_ob;
            return;
        }
        else
        {
            files = ({});
            for(x = 0;x < sizeof(poisons);x++)
            {
                if(tmp_mapping[poisons[x]]["DC"] > Lev) continue;
                files += ({ poisons[x] });
                continue;
            }
            if(!sizeof(files)) return;
            file = files[random(sizeof(files))];
            tmp_ob = new(file);
            if(objectp(tmp_ob)) return tmp_ob;
            return;
        }
    }

    for(x = 0;x < sizeof(poisons);x++)
    {
        if(!flag)
        {
            if(tmp_mapping[poisons[x]]["PoisonName"] != poison) continue;

                file = poisons[x];
                tmp_ob = new(file);
                break;
        }
        if(poison+".c" != poisons[x] && poison != poisons[x]) continue;
        file = poisons[x];
        tmp_ob = new(file);
        break;
    }

    if(objectp(tmp_ob)) return tmp_ob;
    return;
}

string query_poison_effect_type(string EffectType)
{
    if(stringp(EffectType)) EffectType = lower_case(EffectType);
    switch(EffectType)
    {
        case "str":
            return "strength";
        case "con":
            return "constitution";
        case "wis":
            return "wisdom";
        case "int":
            return "intelligence";
        case "dex":
            return "dexterity";
        case "cha":
            return "charisma";
    }
    return EffectType;
}

//will return a string of the poisons that were
//cleared

string clear_poisons_by_dc(object vic, int dc, int flag)
{
    int x, y, mydc, count;
    string *poisons, tmp = "", CurPoison;
    mapping tmp_map;
    object tmp_ob;
    if(!objectp(vic)) return 0;
    if(living(vic))
    {
        tmp_map = vic->query("PoisonEffects");
        if(!mapp(tmp_map)) return 0;
        if(!sizeof(keys(tmp_map))) return 0;
        poisons = keys(tmp_map);
        y = sizeof(poisons);
        for(x = 0;x < sizeof(poisons);x++)
        {
            if(tmp_map[poisons[x]]["DC"] <= dc)
            {
                if(!objectp(tmp_ob = QueryPoisonObject(tmp_map[poisons[x]]["ObjectThatPoisons"])))
                {
                    map_delete(tmp_map, poisons[x]);
                    continue;
                }
                count++;
                tmp_ob->end_effect(vic);
                map_delete(tmp_map, poisons[x]);
                tmp_ob->remove();
                if(!flag)
                {
                    if(x == (sizeof(poisons) - 1) && count > 1) tmp += "and "+capitalize(poisons[x]) +".";
                    else if(y == 1 || x == (sizeof(poisons) - 1) && count == 1) tmp += capitalize(poisons[x])+".";
                    else tmp += capitalize(poisons[x]) + ", ";
                }
                if(flag)
                {
                    tmp += capitalize(poisons[x]) + ".";
                    break;
                }
                continue;
            }
        }
        if(y != sizeof(keys(tmp_map)))
        {
            vic->set("PoisonEffects", tmp_map);
            vic->do_encumbrance();
        }
    }
    else if(vic->is_room())
    {
        if(!vic->query("PoisonInfo")) return 0;
        tmp_map = vic->query("PoisonInfo");
        if(!mapp(tmp_map)) return 0;
        if(!sizeof(keys(tmp_map))) return 0;
        poisons = keys(tmp_map);
        y = sizeof(poisons);
        for(x = 0;x < sizeof(poisons);x++)
        {
            CurPoison = tmp_map[poisons[x]]["PoisonType"];
            if(!objectp(tmp_ob = QueryPoisonObject(CurPoison)))
            {
                map_delete(tmp_map, poisons[x]);
                continue;
            }
            dc = (int)tmp_ob->query_poison_dc();
            if(mydc <= dc)
            {
                if(x == (sizeof(poisons)-1) && y > 1)
                {
                    tmp += "and "+capitalize(CurPoison) +" on " +capitalize(poisons[x]) +".";
                }
                else if(y == 1)
                {
                    tmp += capitalize(CurPoison) + " on " +capitalize(poisons[x])+".";
                }
                else
                {
                    tmp += capitalize(CurPoison) + " on " + capitalize(poisons[x]) + ", ";
				}
                map_delete(tmp_map, poisons[x]);
            }
            tmp_ob->remove();
            continue;
        }
        if(y != sizeof(keys(tmp_map))) vic->set("PoisonInfo", tmp_map);
    }
    else
    {
        if(!vic->query("PoisonType")) return 0;
        if(!vic->query("PoisonDoses") && (int)vic->query("PoisonDoses") != -1) return 0;
        if(!objectp(tmp_ob = QueryPoisonObject(vic->query("PoisonType")))) return 0;
        if(tmp_ob->query_poison_dc() <= dc)
        {
            tmp += capitalize(vic->query("PoisonType")) + ".";
            vic->delete("PoisonType");
            vic->delete("PoisonDoses");
            tmp_ob->remove();
        }
    }
    if(!strlen(tmp)) return 0;
    return tmp;
}

string *query_poisons_by_application(string ApplyType)
{
    string *poisons = ({}), *tmp = ({});
    int x;
    BuildPoisonList(0);
    if(stringp(ApplyType))
    {
        poisons = keys(VALID_POISONS);
        for(x = 0;x < sizeof(poisons);x++)
        {
            if(VALID_POISONS[poisons[x]]["ApplyType"] == ApplyType)
            {
                tmp += ({VALID_POISONS[poisons[x]]["PoisonName"]});
            }
            continue;
        }
    }
    return tmp;
}

void query_poisons_list()
{
    BuildPoisonList(0);
    return VALID_POISONS;
}

int can_be_poisoned(object targ)
{
    string trace;
    if (!objectp(targ)) {
        return 0;
    }
    if (targ->query_property("poison immunity")) {
        return 0;
    }
    if (FEATS_D->usable_feat(targ, "venom immunity")) {
        return 0;
    }
    if (FEATS_D->usable_feat(targ, "undead graft")) {
        return 0;
    }
    if (FEATS_D->usable_feat(targ, "purity of body")) {
        return 0;
    }
    if (FEATS_D->usable_feat(targ, "earthen blood")) {
        return 0;
    }
    if (targ->is_undead()) {
        return 0;
    }
    trace = (string)targ->query_race();
    if (trace == "zombie" || trace == "skeleton" || trace == "undead" ||
        trace == "golem" || trace == "construct" || trace == "soulforged") {
        return 0;
    }
    return 1;
}

varargs void ApplyPoison(object targ, mixed poison, object poisoner, string ApplyType, string myDoor)
{
    int Duration, Count, AllowsSave, WhichSave, IsPlayer, DC, *y, flag, pLev;
    string PoisonApplier, PoisonName;
    mixed WhoDoneIt;
    mapping PoisonEffects;
    object pEnv;
    object PoisonerOb; //Object responsible for applying the poison
                 //can be an actual poison "object" or filename
                //if it is a filename will attempt to load the file
                //and get the relevant info from that file
    if(!objectp(targ)) return;

    if(!objectp(poisoner)) return;

    if(poisoner->is_player())
    {
        PoisonApplier = poisoner->query_name();
        IsPlayer = 1;
    }
    else
    {
        PoisonApplier = base_name(poisoner);
        IsPlayer = 0;
    }
    if(!ApplyType || member_array(ApplyType, VALID_METHODS) == -1)
    {
        if(living(poisoner))
        {
            ApplyType = "injury";
            pLev = poisoner->query_level();
        }
        else if(poisoner->is_food() || poisoner->is_drink())
        {
            pLev = 14;
            ApplyType = "ingested";
        }
        else
        {
            ApplyType = "contact";
            if(objectp(pEnv = environment(poisoner)))
            {
                if(living(pEnv)) pLev = pEnv->query_level();
                else pLev = 14;
            }
            else pLev = 14;
        }
    }
    if(pLev < 14) pLev = 14;
    //if(objectp(find_player("saide"))) tell_object(find_player("saide"), "Plev = "+pLev);

    PoisonEffects = targ->query("PoisonEffects");

    if(!mapp(PoisonEffects))
    {
        PoisonEffects = ([]);
    }
    if(!objectp(poison))
    {
        PoisonerOb = POISON_D->QueryPoisonObject(poison, ApplyType, pLev);
        if(!objectp(PoisonerOb)) return;
    }
    else PoisonerOb = poison;
    if(!objectp(PoisonerOb))
    {
        PoisonerOb = POISON_D->QueryPoisonObject(poison, ApplyType, pLev);
        if(!objectp(PoisonerOb)) return;
    }
    //How long this poison stays on a person
    //Have it count down to zero
    Duration = PoisonerOb->query_duration();

    //Length between primary and secondary
    //poison effects or subsequent effects
    Count = PoisonerOb->query_delay(1);

    //Does this allow a saving throw?
    AllowsSave = (int)PoisonerOb->query_save_allowed(1);

    WhichSave = (string)PoisonerOb->query_saving_throw(1);

    PoisonName = (string)PoisonerOb->query_poison_name();

    //moved this up to a seperate function - cleaner and allows us a way to check if someone is immune to poisons (for monsters or whatever) - Saide, August 2017
    if(!can_be_poisoned(targ))
    {
        tell_object(targ,"%^CYAN%^Your immunity to poison wards off the effects of the "+PoisonName+"!%^RESET%^");
        PoisonerOb->remove();
        return 1;
    }

    //for now not letting them stack - Saide - May, 2013
    if(PoisonEffects[PoisonName])
    {
        PoisonerOb->remove();
        return 1;
    }
    if(!IsPlayer && living(poisoner))
    {
        DC = 10 + ((int)poisoner->query_level()/2);
    }
    else
    {
        DC = (int)PoisonerOb->query_poison_dc(1);
        //DC+= //any player mods - Saide
    }
    flag = 0;
    if(!flag)
    {
        if(living(poisoner)) WhoDoneIt = poisoner->QCN;
        else if(poisoner->is_room())
        {
            if(stringp(myDoor)) WhoDoneIt = "the "+myDoor;
            else WhoDoneIt = "something";
        }
        else WhoDoneIt = poisoner->query_short();
        if(!WhoDoneIt || !stringp(WhoDoneIt)) WhoDoneIt = "something";
        if(objectp(environment(targ)))
        {
            if(!targ->query_invis())
            {
                tell_room(environment(targ), targ->QCN+"%^BOLD%^%^GREEN%^ "+
                "suddenly looks ill!%^RESET%^", targ);
            }
        }
        tell_object(targ, "%^BOLD%^%^GREEN%^You have been "+
        "poisoned by "+WhoDoneIt+"!%^RESET%^");
    }
    if(flag)
    {
        tell_object(targ, poisoner->QCN+"%^BOLD%^%^GREEN%^ "+
        "has poisoned you with "+PoisonName+" poison!%^RESET%^");
    }

    //basically what I am thinking is keeping track of poison by
    //it's name - if you get poisoned twice by the same poison it
    //resets the duration and the effect state, but keeps the
    //actual poison effects and just adds to them
    if(!PoisonEffects[PoisonName])
    {
        PoisonEffects[PoisonName] = (["PoisonApplier" : PoisonApplier,
        "ObjectThatPoisons" : base_name(PoisonerOb), "Duration" : Duration,
        "Count" : Count, "AllowsSave" : AllowsSave, "WhichSave" : WhichSave,
        "Effects" : ([]), "DC" : DC, "WhichEffect" : 1, "PoisonName" : PoisonName,
        "SaveFails" : 0 ]);
    }
    else
    {
        PoisonEffects[PoisonName]["PoisonApplier"] = PoisonApplier;
        PoisonEffects[PoisonName]["ObjectThatPoisons"] = base_name(PoisonerOb);
        PoisonEffects[PoisonName]["Duration"] = Duration,
        PoisonEffects[PoisonName]["Count"] = Count;
        PoisonEffects[PoisonName]["WhichEffect"] = 1;
        PoisonEffects[PoisonName]["SaveFails"] = 0;
        PoisonEffects[PoisonName]["DC"] = DC;
    }
    targ->set("PoisonEffects", PoisonEffects);
    PoisonerOb->remove();
    return 1;
    //destruct(PoisonerOb);
}

void ProcessPoisons(object vic)
{
    int x, WhichEffect, Count, Duration, EffectAmt, flag = 0, DC, sf, StrAffect;
    int CurPoison;
    object PoisonerOb;
    string PoisonFile, EffectType, PoisonName, *pnames;
    mapping PoisonEffects;
    if(!objectp(vic)) return;
    PoisonEffects = vic->query("PoisonEffects");
    if(!mapp(PoisonEffects)) return;
    if(!sizeof(keys(PoisonEffects)))
    {
        return;
    }
    pnames = keys(PoisonEffects);
    for(x = 0;x < sizeof(pnames);x++)
    {
        CurPoison = pnames[x];
        flag = 0;
        if(undefinedp(PoisonEffects[CurPoison])) continue;

        PoisonFile = PoisonEffects[CurPoison]["ObjectThatPoisons"];

        if(!objectp(PoisonerOb = POISON_D->QueryPoisonObject(PoisonFile)))
        {
            map_delete(PoisonEffects, CurPoison);
            continue;
        }

        Count = PoisonEffects[CurPoison]["Count"];
        Duration = PoisonEffects[CurPoison]["Duration"];

        WhichEffect = PoisonEffects[CurPoison]["WhichEffect"];

        Duration--;

        if(Count > 0)
        {
            Count--;
            PoisonEffects[CurPoison]["Count"] = Count;
            PoisonEffects[CurPoison]["Duration"] = Duration;
            PoisonerOb->remove();
            //destruct(PoisonerOb);
            continue;
        }
        Count = (int)PoisonerOb->query_delay(WhichEffect+1);

        PoisonEffects[CurPoison]["Count"] = Count;

        if(Duration <= 0)
        {
            if(!PoisonerOb->end_effect(TO))
            {
                PoisonName = PoisonEffects[CurPoison]["Poison Name"];
                tell_object(vic, "%^BOLD%^%^GREEN%^You "+
                "feel the effects of the "+PoisonName+" wear"+
                "off!%^RESET%^");
            }
            if(mapp(PoisonEffects[CurPoison]["Effects"]))
            {
                if(member_array("strength", keys(PoisonEffects[CurPoison]["Effects"])) != -1) StrAffect = 1;
            }
            map_delete(PoisonEffects, CurPoison);
            PoisonerOb->remove();
            //destruct(PoisonerOb);
            continue;
        }

        sf += PoisonEffects[CurPoison]["SaveFails"];

        if((WhichEffect > (int)PoisonerOb->query_number_of_effects() &&
        (int)PoisonerOb->query_number_of_effects() != -1))
        {
            if(!sf)
            {
                if(!PoisonerOb->end_effect(vic))
                {
                    PoisonName = PoisonEffects[CurPoison]["Poison Name"];
                    tell_object(vic, "%^BOLD%^%^GREEN%^You "+
                    "feel the effects of the "+PoisonName+" wear"+
                    "off!%^RESET%^");
                }
                if(mapp(PoisonEffects[CurPoison]["Effects"]))
                {
                    if(member_array("strength", keys(PoisonEffects[CurPoison]["Effects"])) != -1) StrAffect = 1;
                }
                map_delete(PoisonEffects, CurPoison);
            }
            PoisonerOb->remove();
            //destruct(PoisonerOb);
            continue;
        }

        EffectType = (string)PoisonerOb->query_effect_type(WhichEffect);
        if(EffectType == "strength") StrAffect = 1;
        //EffectAmt = (int)PoisonerOb->query_effect_amount(WhichEffect);

        DC = (int)PoisonerOb->query_poison_dc(WhichEffect);
        if(DC < PoisonEffects[CurPoison]["DC"])
        {
            DC = PoisonEffects[CurPoison]["DC"];
        }

        EffectAmt = (int)PoisonerOb->ProcessEffect(vic, WhichEffect, DC);
        if(EffectAmt) sf++;

        if(PoisonEffects[CurPoison]["Effects"][EffectType])
        {
            PoisonEffects[CurPoison]["Effects"][EffectType] += EffectAmt;
        }
        else
        {
            PoisonEffects[CurPoison]["Effects"][EffectType] = EffectAmt;
        }

        WhichEffect++;
        PoisonEffects[CurPoison]["WhichEffect"] = WhichEffect;
        PoisonEffects[CurPoison]["SaveFails"] = sf;
        PoisonerOb->remove();
        //destruct(PoisonerOb);
        continue;
    }
    vic->set("PoisonEffects", PoisonEffects);
    if(StrAffect) vic->do_encumbrance();
}

void ClearAllPoisons(object vic)
{
    if(!objectp(vic)) return;
    if(living(vic))
    {
        vic->delete("PoisonEffects");
        vic->do_encumbrance();
    }
    else if(vic->is_room())
    {
        vic->delete("PoisonInfo");
    }
    else
    {
        vic->delete("PoisonDoses");
        vic->delete("PoisonType");
    }
}

varargs int is_poisoned(object vic, string myDoor)
{
    string *tmp;
    mapping PoisonEffects;
    if(!objectp(vic)) return 0;
    if(living(vic))
    {
        PoisonEffects = vic->query("PoisonEffects");
        if(!PoisonEffects || !mapp(PoisonEffects)) return 0;
        return sizeof(keys(PoisonEffects));
    }
    else if(vic->is_room())
    {
        if(!vic->query("PoisonInfo")) return 0;
        PoisonEffects = vic->query("PoisonInfo");
        if(!mapp(PoisonEffects)) return 0;
        tmp = keys(PoisonEffects);
        if(!sizeof(tmp)) return 0;
        if(!stringp(myDoor)) myDoor = tmp[random(sizeof(tmp))];
        else if(stringp(myDoor))
        {
            if(member_array(myDoor, tmp) == -1) return 0;
        }
        return PoisonEffects[myDoor]["PoisonDoses"];
    }
    else return vic->query("PoisonDoses");
}

int query_poison_effect(object vic, string EffectType)
{
    int x, mod = 0;
    string *pnames;
    mapping PoisonEffects;
    if(!objectp(vic)) return 0;
    PoisonEffects = vic->query("PoisonEffects");
    if(!mapp(PoisonEffects))
    {
        PoisonEffects = ([]);
        return 0;
    }
    if(!sizeof(keys(PoisonEffects))) return 0;

    EffectType = query_poison_effect_type(EffectType);

    pnames = keys(PoisonEffects);
    for(x; x < sizeof(pnames);x++)
    {
        if(PoisonEffects[pnames[x]]["Effects"][EffectType])
        {
            mod += PoisonEffects[pnames[x]]["Effects"][EffectType];
            continue;
        }
    }
    return (mod*-1);
}

varargs mixed query_poisons_affecting(object vic)
{
    int x, y, doses;
    string *poisons, myPoison, tmpstr;
    mapping tmp_map, poison_map = ([]);
    object tmp_ob;
    if(!objectp(vic)) return;
    if(living(vic))
    {
        tmp_map = vic->query("PoisonEffects");
        if(!mapp(tmp_map)) return;
        if(!sizeof(keys(tmp_map))) return;
        poisons = keys(tmp_map);
        y = sizeof(poisons);
        for(x = 0;x < sizeof(poisons);x++)
        {
            if(!objectp(tmp_ob = QueryPoisonObject(tmp_map[poisons[x]]["ObjectThatPoisons"])))
            {
                map_delete(tmp_map, poisons[x]);
                continue;
            }
            poison_map[poisons[x]] = (["DC" : tmp_map[poisons[x]]["DC"],
            "Info" : tmp_ob->query_poison_info(),
            "TrueInfo" : tmp_ob->query_poison_true_info()]);
            tmp_ob->remove();
            continue;
        }
        if(y != sizeof(keys(tmp_map))) vic->set("PoisonEffects", tmp_map);
    }

    else if(vic->is_room())
    {
        if(!vic->is_vault()) return;
        tmp_map = vic->query("PoisonInfo");
        if(!mapp(tmp_map)) return;
        if(!sizeof(keys(tmp_map))) return;
        poisons = keys(tmp_map);
        y = sizeof(poisons);
        for(x = 0;x < sizeof(poisons);x++)
        {
            if(!objectp(tmp_ob = QueryPoisonObject(tmp_map[poisons[x]]["PoisonType"])))
            {
                map_delete(tmp_map, poisons[x]);
                continue;
            }
            tmpstr = tmp_ob->query_poison_name() + " on the " + poisons[x];

            poison_map[tmpstr] = (["DC" : tmp_ob->query_poison_dc(),
            "Info" : tmp_ob->query_poison_info(),
            "TrueInfo" : tmp_ob->query_poison_true_info() ]);
            tmp_ob->remove();
        }
        if(y != sizeof(keys(tmp_map))) vic->set("PoisonInfo", tmp_map);
    }

    else
    {
        if(!vic->query("PoisonType")) return;
        if(!(int)vic->query("PoisonDoses") && (int)vic->query("PoisonDoses") != -1) return;
        if(!objectp(tmp_ob = QueryPoisonObject(vic->query("PoisonType")))) return;
        poison_map[vic->query("PoisonType")] = (["DC" : tmp_ob->query_poison_dc(),
        "Info" : tmp_ob->query_poison_info(),
        "TrueInfo" : tmp_ob->query_poison_true_info()]);
        tmp_ob->remove();
    }
    if(!sizeof(keys(poison_map))) return 0;
    return poison_map;
}


void QueryPoisons(object vic)
{
    if(!objectp(vic)) return;
    return vic->query("PoisonEffects");
}

//added the ability to not poison yourself in combat or otherwise if you applied the poison
//with a feat such as perfect poisoner (should we ever create one) or certain spells
//if flag == 2 then you can still poison yourself regardless, such as when trying to poison
//an already poisoned item - Saide

varargs mixed is_object_poisoned(object myOb, object vic, string myAct, int flag, string myDoor)
{
    object tmp_ob;
    int doses;
    string myPoison, ApplyType, whoImmune;
    mapping tmp_map;

    if(!objectp(myOb)) return;
    if(!objectp(vic)) return;
    if(!stringp(myAct)) return;
    if(!intp(flag)) return;
    if(!myOb->is_room())
    {
        if(!intp(doses = myOb->query("PoisonDoses")) ||
        !stringp(myPoison = myOb->query("PoisonType")) )
        {
            myOb->delete("PoisonDoses");
            myOb->delete("PoisonType");
            myOb->delete("whoImmune");
            return;
        }
        if(doses <= 0 && doses != -1)
        {
            myOb->delete("PoisonDoses");
            myOb->delete("PoisonType");
            myOb->delete("whoImmune");
            return;
        }
    }

    if(myOb->is_room())
    {
        if(!stringp(myDoor)) return;
        tmp_map = myOb->query("PoisonInfo");
        if(!mapp(tmp_map)) return;
        if(!sizeof(keys(tmp_map))) return;
        if(!tmp_map[myDoor]) return;
        if(!intp(doses = tmp_map[myDoor]["PoisonDoses"]) ||
        !stringp(myPoison = tmp_map[myDoor]["PoisonType"]) )
        {
            return;
        }
        if(doses <= 0 && doses != -1)
        {
            map_delete(tmp_map, myDoor);
            myOb->set("PoisonInfo",tmp_map);
            return;
        }
        whoImmune = tmp_map["whoImmune"];
    }
    else whoImmune = myOb->query("whoImmune");

    if(member_array(myAct, VALID_INGEST_ACTS) != -1) ApplyType = "ingested";
    else if(member_array(myAct, VALID_CONTACT_ACTS) != -1) ApplyType = "contact";
    else ApplyType = "injury";

    tmp_ob = POISON_D->QueryPoisonObject(myPoison, ApplyType);
    if(!objectp(tmp_ob)) return;

    if(flag)
    {
        //If someone is immune to their own poison do nothing
        //a perfect poisoner feat or psywarrior applied poisons should have this set - Saide - April 2016
        if(stringp(whoImmune) && flag == 1)
        {
            if((string)vic->query_name() == whoImmune)
            {
                if(objectp(tmp_ob)) tmp_ob->remove();
                return;
            }
        }

        POISON_D->ApplyPoison(vic, myPoison, myOb, ApplyType, myDoor);
        if(doses != -1)
        {
            doses--;
            if(myOb->is_room())
            {
                if(doses <= 0)
                {
                    map_delete(tmp_map, myDoor);
                    myOb->set("PoisonInfo",tmp_map);
                }
                else
                {
                    tmp_map[myDoor]["PoisonDoses"] = doses;
                    myOb->set("PoisonInfo", tmp_map);
                }
            }
            else
            {
                if(doses <= 0)
                {
                    myOb->delete("PoisonDoses");
                    myOb->delete("PoisonType");
                    myOb->delete("whoImmune");
                }
                else myOb->set("PoisonDoses", doses);
            }
        }
    }

    tmp_ob->remove();
    if(!flag)
    {
        if(myOb->is_room())
        {
            return tmp_map[myDoor]["PoisonType"];
        }
        else return myOb->query("PoisonType");
    }
}
