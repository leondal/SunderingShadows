#include <std.h>
#include "forest.h"
#include <daemons.h>

inherit DAEMON;

nosave string *gnolls;

void fix_bandits(object ob, int num, object where, int what);

//BANDIT CAMPS ONLY - Used by /d/deku/inherits/foresttraili

void change_room(object where, int which) {
    object ob;
    string nlong, dcamp, ncamp, *fitems, *eitems;
    int x, y;

    fitems = ({"fire","bright fire","camp fire","campfire"});
    eitems = ({"embers","pit of embers"});

    ncamp = "%^BOLD%^%^BLACK%^A circle of rocks surrounds a %^YELLOW%^"+
    "bright fire%^BOLD%^%^BLACK%^ here.%^RESET%^";
    dcamp = "%^BOLD%^%^BLACK%^A circle of rocks surrounds a pit "+
    "of cold %^RED%^embers%^BOLD%^%^BLACK%^ here.%^RESET%^";

    switch(which) {
        case 0:
            where->set_short("%^YELLOW%^A small camp in "+
            "the forest%^RESET%^");
            nlong = where->query_long();
            if(strsrch(nlong,ncamp) == -1) {
                if(strsrch(nlong,dcamp) == -1) {
                    nlong = nlong + "  " + ncamp;
                    where->set_long(nlong);
                }
                if(strsrch(nlong,dcamp) != -1) {
                    nlong = replace_string(nlong, dcamp, ncamp);
                    where->set_long(nlong);
                }
            }
            where->remove_item(eitems);
            where->add_items(fitems,"%^YELLOW%^This fire is surrounded "+
            "by a circle of rocks that has been placed to contain "+
            "it.  It burns brightly, providing warmth and a "+
            "method for cooking to the camps inhabitants.%^RESET%^");
            y = 2 + random(4);
            if(!present("bandit",where)) {
                for(x = 0;x < y;x++) {
                    new("/d/deku/monster/bandit")->move(where);
                }
            }
            tell_object(where,"%^RED%^A group of bandits enter and "+
            "quickly dig a small pit, then surround it with stones, "+
            "and start a fire within.%^RESET%^");
            x = 1;
            if(ob = present("bandit "+x,where)) {
                fix_bandits(ob,x,where,1);
            }
            break;
        case 1:
            where->set_short("%^RED%^An abandoned camp in "+
            "the forest%^RESET%^");
            nlong = where->query_long();
            if(strsrch(nlong,dcamp) == -1) {
                if(strsrch(nlong,ncamp) == -1) {
                    nlong = nlong + "  " + dcamp;
                    where->set_long(nlong);
                }
                if(strsrch(nlong,ncamp) != -1) {
                    nlong = replace_string(nlong, ncamp, dcamp);
                    where->set_long(nlong);
                }
            }
            where->remove_item(fitems);
            where->add_items(eitems,"%^RED%^ "+
            "These are the remains of what was obviously a recent "+
            "fire and judging by the circle of rocks probably a "+
            "controlled camp fire at that.%^RESET%^");
            tell_object(where,"%^RED%^The fire finally burns down "+
            "to nothing more than embers.%^RESET%^");
            x = 1;
            if(ob = present("bandit "+x,where)) {
                fix_bandits(ob,x,where,0);
            }
            break;
    }
}

void fix_bandits(object ob, int num,object where, int what) {
    if(what == 1) {
        ob->make_camp();
    }
    if(what == 0) {
        ob->break_camp();
    }
    num++;
    if(ob = present("bandit "+num,where)) {
        fix_bandits(ob,num,where, what);
    }
}
//Filter to return living contents of room - bandits won't make
//a camp with living contents within it//

int living_things(object *objects) {
    int x;
    for(x = 0;x < sizeof(objects);x++) {
        if(living(objects[x])) return 1;
    }
    return 0;
}

void place_camps(object where, int save) {
    if(living_things(all_inventory(where))) return;
    if(save == 0) {
        where->set_has_camp(1);
        change_room(where,0);
        return;
    }
    if(save == 1 && sizeof(SAVE_D->query_array(CAMPS)) < 9) {
        where->set_has_camp(1);
        change_room(where,0);
        SAVE_D->set_value(CAMPS,base_name(where));
        return;
    }
}

void remove_camps(object where) {
    where->set_has_camp(0);
    change_room(where,1);
    return;
}

//END BANDIT CAMPS

/*HAG && ATHACH (Unique Forest Mobs) - Placement - Used by
/d/deku/inherits/foresttraili.c, riverbanki, and lakebanki
*/

void place_hag(object where) {
    string rn;
    if(objectp(environment(find_object_or_load("/d/deku/monster/bheur")))) { return; }
    if(member_array(base_name(where),INV_C_ROOMS) != -1) { return; }
    rn =  base_name(where);
    rn = replace_string(rn,"/d/deku/forest/dforest","");
    if(member_array(rn,INV_ROOMS) != -1) { return; }
    if((int)where->query_has_camp()) { return; }
    find_object_or_load("/d/deku/monster/bheur")->move(where);
}

void place_athach(object where) {
    string rn;
    if(objectp(environment(find_object_or_load("/d/deku/monster/athach")))) { return; }
    if(member_array(base_name(where),INV_C_ROOMS) != -1) { return; }
    rn =  base_name(where);
    rn = replace_string(rn,"/d/deku/forest/dforest","");
    if(member_array(rn,INV_ROOMS) != -1) { return; }
    if((int)where->query_has_camp()) { return; }
    find_object_or_load("/d/deku/monster/athach")->move(where);
}
//END HAG && ATACH PLACEMENT

/*GNOLL PACK CREATION/PLACEMENT - FOR GNOLLS AND GNOLL WARLORD
USED BY "/d/deku/inherits/foresttrailenc.c, riverbanki.c, and
lakebanki.c*/

void make_gnoll_pack(object where) {
    object ob, lead;
    string rn;
    int num, x;
    if(member_array(base_name(where),INV_C_ROOMS) != -1) { return; }
    rn = base_name(where);
    rn = replace_string(rn,"/d/deku/forest/dforest","");
    if(member_array(rn,INV_ROOMS) != -1) { return; }
    if((int)where->query_has_camp()) { return; }
    num = 2 + random(3);
    lead = new("/d/deku/monster/gnoll");
    lead->make_me(1);
    lead->move(where);
    for(x = 0;x < num;x++) {
        ob = new("/d/deku/monster/gnoll");
        ob->make_me(0);
        ob->move(where);
        lead->add_follower(ob);
    }
}
//END GNOLL STUFF

/*REMOVES WEREWOLVES THAT REMAIN DURING THE DAY
Used by /d/deku/inherits/foresttrailenc., lakebanki.c, and riverbanki.c
*/

void remove_werewolf(object where) {
    object ob;
    if(ob = present("werewolf",where))
        if(!userp(ob))
        {
            if(sizeof(ob->query_attackers()) < 1) {
                ob->force_me("emote %^RED%^growls%^RESET%^ loudly "+
                             "and runs off into the forest!%^RESET%^");
                ob->move("/d/shadowgate/void");
                ob->remove();
                return remove_werewolf(where);
            }
            return;
        }
}
//END WEREWOLF STUFF

void forest_event()
{
    switch(random(10))
    {
        case 0..6:
            WORLD_EVENTS_D->inject_event((["A More Rewarding Forest!" : (["start message" : "%^BOLD%^%^GREEN%^A magical mist seeps through the "+
            "ShadowLord forest, for the next 45 minutes experience gained within it will award an additional %^BOLD%^%^CYAN%^(25%)%^BOLD%^"+
            "%^GREEN%^!%^RESET%^",
            "event type" : "exp bonus", "length" : 45,
            "notification" : "25% Additional Exp in ShadowLord Forest!", "event name" : "A More Rewarding Forest!", "modifier" : 25, "announce" : 1,
            "announce to" : "/d/deku/forest" ]),]));
            break;
        case 7..9:
            WORLD_EVENTS_D->inject_event((["A More Dangerous Forest!" : (["start message" : "%^BOLD%^%^RED%^A blood red mist seeps through "+
            "the ShadowLord Forest, angering and strenghtening the monsters within it! For the next 45 minutes the monsters within the forest "+
            "will be stronger!%^RESET%^",
            "event type" : "monster modifications", "length" : 45,
            "notification" : "More Dangerous Monsters in ShadowLord Forest!", "event name" : "A More Dangerous Forest!", "modifier" : (["strength" : 1, "dexterity" : 1, "intelligence" : 1,
            "wisdom" : 1, "constitution" : 1, "charisma" : 1, "level" : 4, "health" : roll_dice(8,4)]), "announce" : 1, "announce to" : "/d/deku/forest" ]),]));
            break;
    }
    return;
}

/*Fixes the nogo and speed of every mob that spawns in the
forest - called from within the mob file
mobs that use it are
/d/deku/keep/monster/werewolf.c
/d/deku/monster/athach.c, bheur.c, goblin.c, kobold.c,
gnoll.c (make_me(1)), owlbear.c
*/

void fix_nogo(object mob)
{
    int x;
    string *rooms;
    rooms = ({});
    if(sizeof(mob->query_nogo()) > 0) {
        rooms += mob->query_nogo();
    }
    for(x = 0;x < sizeof(INV_ROOMS);x++) {
        rooms += ({"/d/deku/forest/dforest"+INV_ROOMS[x]});
    }
    rooms += NOGO_ROOMS;
    mob->set_nogo(rooms);
    mob->set_speed(40 + random(41));
    if(!random(145)) forest_event();
    //forest_event();
}
//END NOGO && SPEED FIX

//VOICE OF THE SHADOWLORD THAT WILL KILL NON-INTERACTIVE
//Creatures that fail their saving throw vs. death//

void doomsday_voice(object room) {
    object *liv, *contents;
    int x;
    string rn;
    rn = base_name(room);
    rn = replace_string(rn,"/d/deku/forest/dforest","");

    if(member_array(rn,DOOMED_ROOMS) != -1) {

        liv = all_inventory(room);

        tell_room(room,"%^RED%^A voice booms through the "+
        "forest:%^RESET%^  ALL THINGS DIE!!%^RESET%^");
        if(sizeof(liv) < 1) return;
        for(x = 0;x < sizeof(liv);x++) {
            if(!living(liv[x]) || liv[x]->query_true_invis()) continue;
            if(interactive(liv[x])) {
                if(!SAVING_D->saving_throw(liv[x],"paralyzation_poison_death")) {
                    tell_object(liv[x],"%^RED%^An invisible force "+
                    "eats at your lifeforce, wracking your body "+
                    "with severe pain!%^RESET%^");
                    liv[x]->do_damage("head",roll_dice(6,6));
                    liv[x]->add_attacker(room);
                    liv[x]->continue_attack();
                    if(objectp(liv[x])) {
                        liv[x]->remove_attacker(room);
                    }
                    continue;
                }
                tell_object(liv[x],"%^RED%^An invisible force "+
                "tugs at your lifeforce!%^RESET%^");
                continue;
            }
            if(!SAVING_D->saving_throw(liv[x],"paralyzation_poison_death",-35)) {
                if(member_array(liv[x]->query_name(),SAFE_NAMES) == -1) {
                    liv[x]->die();
                    continue;
                }
                continue;
            }
            continue;
        }
    }
    return;
}

//FOG THAT DISSOLVES ALL OBJECTS IN ROOM//

void dissolve_me(object room)
{
    //going to make this dissolve everything, except for corpses/player died
    //items and a few special mobs - the hag, drakkan, and the attach
    //this way it shouldn't cause as much lag *HOPEFULLY* and there
    //wont be as much free stuff laying around, should only happen in
    //rooms with no people - Saide - 12/05/08
    int x, flag;
    object *items, *ppl;
    items = all_inventory(room);
    ppl = all_living(room);
    for(x = 0;x < sizeof(ppl);x++)
    {
        if(userp(ppl[x]) && !ppl[x]->query_true_invis()) return;
        continue;
    }
    if(sizeof(items) < 1) return;
    for(x = 0;x < sizeof(items);x++)
    {
        if(userp(items[x])) continue;
        if(time() - (int)items[x]->query_property("died time") < 6000) continue;
        if(items[x]->id("questob")) continue;
        if(items[x]->query_property("no offer")) continue;
        if((int)items[x]->query_weight() > 300) continue;
        if(items[x]->id("yurnklaw") ||
        items[x]->id("monstrous abomination") ||
        items[x]->id("elderly lady") ||
        items[x]->id("bandit") ||
        items[x]->id("firealtarguard"))
        {
            continue;
        }
        if(items[x]->id("corpse"))
        {
            if(items[x]->get_was_user()) continue;
        }
        if(living(items[x])) continue;
        items[x]->move("/d/shadowgate/void");
        if(!objectp(items[x])) continue;
        items[x]->remove();
        continue;
    }
	//getting rid of the msg to prevent lag - moot point since users
	//wont be seeing it if they are present in the room
	//should now dissolve corpses that weren't players, as well as
	//mobs and any items that weren't recently in a player death - Saide
	//tell_room(room, "%^BOLD%^%^WHITE%^A dark fog collects over the room, "+
	//"dissolving almost everything!%^RESET%^");
}

/*TO MAKE CERTAIN MOB EXP DOESN'T GO WAY UP WITH THEIR BATTLES*/

void fix_exp(object me, int amt) {
    if((int)me->query_exp() > amt) {
        me->set_exp(amt);
    }
}
//END EXP FIX FUNCTION

//MAKE KOBOLD GANGS - like gnoll packs, cept have 2 sorcerers

void make_kobold_gang(object where) {
    object ob, lead;
    string rn;
    int num, x;
    if(member_array(base_name(where),INV_C_ROOMS) != -1) { return; }
    rn = base_name(where);
    rn = replace_string(rn,"/d/deku/forest/dforest","");
    if(member_array(rn,INV_ROOMS) != -1) { return; }
    if((int)where->query_has_camp()) { return; }
    num = 2 + random(2);
    lead = new("/d/deku/monster/kobold");
    lead->make_me(1);
    lead->move(where);
    fix_nogo(lead);
    for(x = 0;x < num;x++) {
        ob = new("/d/deku/monster/kobold");
        if(x == (num - 1)) {
            ob->make_me(1);
        }
        else {
            ob->make_me(0);
        }
        ob->move(where);
        lead->add_follower(ob);
    }
}
