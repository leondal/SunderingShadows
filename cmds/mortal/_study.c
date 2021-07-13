#include <std.h>
#include <daemons.h>
//#include <damage_types.h>
//#include <favored_types.h>

int cmd_study(string str)
{
    string what, dir, file, *myclasses, *myclassskills, mydisc, *ids;
    object obj, current, monster, *roomList;
    int x;

    if (TP->query_bound()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    if (TP->query_blind()) {
        notify_fail("You can't study something if you can't see it.");
        return 0;
    }
    if ((object)TP->query_attackers() != ({})) {
        notify_fail("You're too busy to be studying that right now!\n");
        return 0;
    }
    if (!str) {
        notify_fail("study what?\n");
        return 0;
    }

    if (sscanf(str, "room %s", what) == 1 || str == "room" && !present(str, TP)) {
        if (!TP->query_time_delay("studying", 3) && !avatarp(TP)) {
            write("You need more time to reflect on your knowledge and " +
                  "research before trying that again.");
            return 1;
        }
        if (what) {
            if (member_array(what, keys(ETP->query_items())) == -1) {
                tell_object(TP, "There is no " + what + " in your general area.");
                return 1;
            }
			if(obj->query_obvious_short()==0)
			{
			tell_object(TP, "You carefully begin studying the " + str + " here.");
            tell_room(ETP, TPQCN + " seems to be carefully studying the " + str +" here.", TP);	
			}
			else{
            tell_room(ETP, TPQCN + " seems to be carefully studying the " + obj->query_obvious_short() +" here.", TP);	
            tell_object(TP, "You carefully begin studying the " + obj->query_obvious_short() + " here.");
			}
            TP->set_time_delay("studying");
            do_room_study(TP, what);
            return 1;
        }
        tell_object(TP, "You carefully begin studying the area around you.");
        tell_room(ETP, TPQCN + " seems to be carefully studying the area.", TP);
        TP->set_time_delay("studying");
        do_room_study(TP, "room");
        return 1;
    }

    if (sscanf(str, "monster %s", what) == 1) {

        if (what == "reset") {
            string *sortrem;
            mapping remembered;
            remembered = ([ ]);
            sortrem = ({ });
            TP->set_study_mons(remembered, sortrem);
            write("Monster data reseted.");
            return 1;
        }

        if(sscanf(str, "monster %s %s", what, dir) != 2){
            return notify_fail("Syntax: study monster [monster name] [direction]\n");
        }

        current = ETP;
        roomList = allocate(1);
        roomList[0] = current;
        
        if (current->query_door(dir) &&
            !current->query_open(current->query_door(dir))) {
            write("There seems to be a closed door between you and your target.");
            return 1;
        }
        current = find_object_or_load((string)current->query_exit(dir));
        x = TP->light_blind_remote(0, current, 1);
        if (x != 0)
        {
            tell_object(TP, "You can't see well enough to observe into that room");
            tell_object(TP, TP->light_blind_fail_message(x));
            return 1;
        }

        monster = present(what, current);

        if (!objectp(monster)) {
            return notify_fail("There is no " + what + " there!\n");
        }
        if (userp(monster)) {
            return notify_fail("You can only study monsters or npcs.\n");
        }
        if (!TP->ok_to_kill(monster)) {
            return notify_fail("Greater forces prevent your malice.\n");
        }
        myclasses = TP->query_classes();
        myclassskills = ({});
        
        for (x = 0;x < sizeof(myclasses);x++) {
            file = DIR_CLASSES + "/" + myclasses[x] + ".c";
            if (file_exists(file))
            {
                if (myclasses[x] == "psion")
                {
                    mydisc = TP->query_discipline();
                    myclassskills += (string*)file->discipline_skills(mydisc);
                }
                else if (myclasses[x] == "monk")
                {
                    mydisc = TP->query("monk way");
                    myclassskills += (string*)file->way_skills(mydisc);
                }
                else if (myclasses[x] == "oracle")
                {
                    mydisc = TP->query_mystery();
                    myclassskills += (string*)file->mystery_skills(mydisc);
                }
                else  myclassskills += (string*)file->class_skills(TP);
            }
            continue;
        }
        if (FEATS_D->usable_feat(TP, "skill focus"))
        {
            myclassskills += ({ ((string)TP->query("skill_focus")) });
        }
        myclassskills = distinct_array(myclassskills);

        if (member_array("academics", myclassskills) == -1 && !TP->is_favored_enemy(monster)) {
            return notify_fail("You need training in academics to study this monster.\n");
        }
        
        if (!TP->query_time_delay("studying_monster", 5) && !avatarp(TP)) {
            write("You need more time to reflect on your knowledge and " +
                "research before trying that again.");
            return 1;
        }
        if (monster) {
            tell_object(TP, "You carefully begin studying the " + monster->query_short() + ".");
            tell_room(ETP, TPQCN + " seems to be carefully studying the " +
                monster->query_short() + " here.", TP);
            TP->set_time_delay("studying_monster");
            do_monster_study(TP, monster);
            do_monster_read(TP, file_name(monster));
            return 1;
        }
        tell_object(TP, "You carefully begin studying the creature in the area.");
        tell_room(ETP, TPQCN + " seems to be carefully studying a creature.", TP);
        TP->set_time_delay("studying");
        do_monster_study(TP, monster);
        do_monster_read(TP, file_name(monster));
        return 1;
    }

    if (!obj = present(str, TP)) {
        notify_fail("You don't have that.\n");
        return 0;
    }
    if (!TP->query_time_delay("studying", 3) && !avatarp(TP)) {
        write("You need more time to reflect on your knowledge and " +
              "research before trying that again.");
        return 1;
    }
    ids = obj->query_id();
    if (!TP->query_invis()) {
		if(obj->query_obvious_short()==0)
		{
		tell_object(TP, "You carefully begin studying the " + str + " here.");
        tell_room(ETP, TPQCN + " seems to be carefully studying the " + str +" here.", TP);	
		}
		else{
        tell_room(ETP, TPQCN + " seems to be carefully studying the " + obj->query_obvious_short() +" here.", TP);
        tell_object(TP, "You carefully begin studying the " + obj->query_obvious_short() + " here.");
		}
    }
    TP->set_time_delay("studying");
    if ((int)obj->is_brewed()) {
        do_potion_study(TP, obj, str);
    }else {
        do_study(TP, obj, str);
        do_id(TP, obj, str);
    }
    return 1;
}

int do_room_study(object myplayer, string which)
{
    int enchant, diff, level, x, baselevel;
    string message0, message1;
    string* ppl, who, * room_items, fail_msg, succ_msg, msg, * f_study = ({}), * s_study = ({});
    mixed rlore, info = 0, this_item;
    mapping ri_info, rs_info;

    object where;

    if (!objectp(myplayer)) {
        return 0;
    }
    where = environment(myplayer);
    if (!objectp(where)) {
        return 0;
    }
    rlore = where->query_property("room lore");

    if (!rlore || !mapp(rlore)) {
        tell_object(myplayer, "%^BOLD%^%^YELLOW%^You " +
                    "study the " + which + " carefully, but can neither recall " +
                    "nor ascertain anything of remark.%^RESET%^");
        return 1;
    }

    diff = 20;
    baselevel = (int)myplayer->query_skill("academics");
    level = baselevel + roll_dice(1, 20);
    ri_info = where->query_property("room lore");
    room_items = keys(ri_info);

    for (x = 0; x < sizeof(room_items); x++) {
        if (sizeof(room_items[x])) {
            if (member_array(which, room_items[x]) != -1) {
                info = ri_info[room_items[x]];
                this_item = room_items[x];
                break;
            }
        }
        if (room_items[x] == which) {
            info = ri_info[room_items[x]];
            this_item = room_items[x];
            break;
        }
        continue;
    }

    if (!info) {
        tell_object(myplayer, "%^BOLD%^%^YELLOW%^You " +
                    "study the " + which + " carefully, but can neither recall " +
                    "nor ascertain anything of remark.%^RESET%^");
        return 1;
    }
    if (sizeof(info) == 2) {
        diff = info[1];
        msg = info[0];
    }

    if (!sizeof(info)) {
        msg = info;
    }

    succ_msg = "%^BOLD%^%^YELLOW%^You carefully study the " +
        which + " and are able to determine the following : %^RESET%^" +
        msg;

    fail_msg = "%^BOLD%^%^YELLOW%^You are unable to determine " +
        "anything of relevance about the " + which + "%^RESET%^.  Perhaps " +
        "you need to research more.";
    rs_info = where->query_property("successful study");
    if (mapp(rs_info)) {
        if (rs_info[this_item]) {
            s_study = rs_info[this_item];
        }
    }

    rs_info = where->query_property("failed study");
    if (mapp(rs_info)) {
        if (rs_info[this_item]) {
            f_study = rs_info[this_item];
        }
    }
    if (member_array(myplayer->query_name(), s_study) != -1) {
        tell_object(myplayer, succ_msg);
        return 1;
    }
    if (member_array(myplayer->query_name(), f_study) != -1) {
        tell_object(myplayer, "%^BOLD%^%^YELLOW%^You are still unable " +
                    "to determine anything of relevance about the " + which + "%^RESET%^.");
        return 1;
    }


    if (diff > level) {
        tell_object(myplayer, fail_msg);
        f_study += ({ myplayer->query_name() });
        where->set_property("failed study", ([this_item: f_study]));
        return 1;
    }
    tell_object(myplayer, succ_msg);
    s_study += ({ myplayer->query_name() });
    where->set_property("successful study", ([this_item: s_study]));
    return 1;
}

int do_potion_study(object myplayer, object obj, string str)
{
// this uses add- and query-identified for tracking if the potion has been recognized.
// it then uses add- and query-studied for tracking the extra information of a botch/non-botch (5DC higher).
// as both are healing-skill based, there was no need for separate rolls for ID'd name and lore. N, 12/11.

    int diff, level, baselevel, failed_level;
    string message0, message1, message2, message3, who;
    mapping failed;

    baselevel = (int)myplayer->query_skill("healing");
    level = baselevel + roll_dice(1, 20);
    diff = obj->query_property("lore difficulty");
    if (!diff || !intp(diff)) {
        diff = 1;
    }
    who = myplayer->query_name();

    message0 = "You aren't knowledgeable enough in alchemy to discern the purpose of this brewed item.";
    message1 = "%^BOLD%^%^CYAN%^" + obj->query_lore();
    message2 = message1 + "\n%^BOLD%^%^WHITE%^You're fairly sure this particular mix is potent enough to work properly.";
    message3 = message1 + "\n%^BOLD%^%^WHITE%^You're fairly sure there is something botched about this particular mix.";

    if (avatarp(myplayer)) {
        if ((int)obj->is_reversed()) {
            write(message3);
        }else {
            write(message2);
        }
        return 1;
    }
    if (member_array(who, obj->query_identified()) != -1) { // success on lore/ID
        if (member_array(who, obj->query_studied()) != -1) { // success on botched/not as well
            if ((int)obj->is_reversed()) {
                write(message3);
            }else {
                write(message2);
            }
        }else {
            write(message1);
        }
        return 1;
    }
    failed = obj->query("identified_failed");
    if (!failed) {
        failed = ([]);
    }
    if (member_array(who, keys(failed)) != -1) {
        failed_level = failed[who];
        if (failed_level >= baselevel) {
            write("You haven't improved your knowledge of alchemy since last you examined this specific vial.");
            return 1;
        }
    }

    if (level < diff) {
        failed[who] = baselevel;
        write(message0);
    }else {
        if (level < (diff + 5)) {
            obj->add_studied(who);
            obj->add_identified(who);
            if ((int)obj->is_reversed()) {
                write(message3);
            }else {
                write(message2);
            }
            return 1;
        }
        obj->add_identified(who);
        map_delete(failed, who);
        write(message1);
    }
    obj->delete("identified_failed");
    obj->set("identified_failed", failed);
    return 1;
}

int do_monster_study(object myplayer, object monster) {

    string name, obname, a, b, * sortrem, filename, t1;
    mapping remembered;
    int newsize, * temp = ({}), i;
    int myRoll, myCheck, myDC, myResult, myStat;
    filename = file_name(monster);
    if (sscanf(filename, "%s#", t1)) {
        filename = t1;
    }
    
    if (!remembered = myplayer->query_study_mons()) {// mapping ([name:place])
        remembered = ([ filename : ({ 0, 0, 0, 0 }) ]);
    }
    if (!sortrem = myplayer->query_study_mons_sort()) {//names
        sortrem = ({});
    }
    
    if (!remembered[filename]) {
        remembered[filename] = ({ 0, 0, 0, 0 });
    }
    if (sizeof(remembered[filename])) {
        //use monsterrace and favored_types to select another skill, modify do_monster_read to get the skill
        myCheck = myplayer->query_skill("academics");
        if (FEATS_D->usable_feat(myplayer, "monster lore")) {
            myCheck += myplayer->query_base_stats("wisdom");
        }
        if (myplayer->query_class() == "ranger") {
            if (myplayer->is_favored_enemy(monster)) {
                myCheck += 2;
                myCheck += (FEATS_D->usable_feat(myplayer, "second favored enemy") * 2);
                myCheck += (FEATS_D->usable_feat(myplayer, "third favored enemy") * 2);

                if (monster->is_undead() && FEATS_D->usable_feat(myplayer, "resist undead"))
                    myCheck += 2;
            }
        }
        myRoll = roll_dice(1, 20);
        myDC = monster->query_level() + 10;
        if (myRoll == 1) {
            myResult = "1";
        }else if (myRoll == 20) {
            myResult = "20";
        }else if (myCheck + myRoll < myDC) {
            myResult = "fail";
        }else {
            myResult = "pass";
        }
        switch (myResult) {
        case "1":
            if (member_array(0, remembered[filename]) != -1) {//first fill the array
                myStat = member_array(0, remembered[filename]);
                remembered[filename][myStat] = 1;
            }else if (member_array(2, remembered[filename]) != -1) {//then worsen fails
                myStat = member_array(2, remembered[filename]);
                remembered[filename][myStat] = 2;
            }else if (member_array(3, remembered[filename]) != -1) {//then unlearn stuff
                myStat = member_array(3, remembered[filename]);
                remembered[filename][myStat] = 3;
            }
            break;
        case "fail":
            if (member_array(0, remembered[filename]) != -1) {//first fill the array
                myStat = member_array(0, remembered[filename]);
                remembered[filename][myStat] = 2;
            }
            break;
        case "pass":
            if (member_array(0, remembered[filename]) != -1) {//first fill the array
                myStat = member_array(0, remembered[filename]);
                remembered[filename][myStat] = 3;
            }
            break;
        case "20":
            if (member_array(0, remembered[filename]) != -1) {//first fill the array
                myStat = member_array(0, remembered[filename]);
                remembered[filename][myStat] = 3;
            }
            else if (member_array(2, remembered[filename]) != -1) {//then worsen fails
                myStat = member_array(2, remembered[filename]);
                remembered[filename][myStat] = 3;
            }
            else if (member_array(1, remembered[filename]) != -1) {//then unlearn stuff
                myStat = member_array(1, remembered[filename]);
                remembered[filename][myStat] = 2;
            }
            break;
        default:
            break;
        }
    }
    sortrem = distinct_array(({ filename }) + sortrem);
    newsize = (int)myplayer->query_base_stats("intelligence") * 2;
    if (FEATS_D->usable_feat(myplayer, "monster lore")) {
        if (myplayer->query_base_stats("wisdom") > myplayer->query_base_stats("intelligence")) {
            newsize = (int)myplayer->query_base_stats("wisdom") * 2;
        }
    }
    if (sizeof(sortrem) > newsize && !avatarp(myplayer)) {
        while (sizeof(sortrem) > newsize) {
            map_delete(remembered, sortrem[sizeof(sortrem) - 1]);
            sortrem -= ({ sortrem[sizeof(sortrem) - 1] });
        }
        tell_object(myplayer, "oversize");
    }
    myplayer->set_study_mons(remembered, sortrem);
    tell_object(myplayer, "You study the monster, looking its behavior and learning it.");

    return 1;
}

int do_monster_read(object myplayer, string monster) {
    string filename, t1;
    mapping remembered;
    int result, msgCheck, myVar;
    filename = monster;
    if (sscanf(filename, "%s#", t1)) {
        filename = t1;
    }

    if (!remembered = myplayer->query_study_mons()) {
        tell_object(myplayer, "You haven't studied a foe yet.");
        return 1;
    }
    //Thx to Chernobog for clarifying the messages!
    switch (remembered[filename][0]) {
    case 0:
    case 2:
        break;
    case 1:
        result = myplayer->query_level() - filename->query_level();
        if (result > 9) {
            t1 = "It appears to be exceptionally seasoned.";
        }else if (result > 3) {
            t1 = "It appears to be experienced.";
        }else if (abs(result) < 4) {
            t1 = "It appears clueless.";
        }else if (result < -9) {
            t1 = "It appears to have a familiar aptitude to yourself.";
        }else if (result < -3) {
            t1 = "It appears slightly naive.";
        }
        msgCheck = 1;
        tell_object(myplayer, "(level) " + t1);
        break;
    case 3:
        result = myplayer->query_level() - filename->query_level();
        if (result > 9) {
            t1 = "It appears clueless.";
        }else if (result > 3) {
            t1 = "It appears slightly naive.";
        }else if (abs(result) < 4) {
            t1 = "It appears to have a familiar aptitude to yourself.";
        }else if (result < -9) {
            t1 = "It appears to be exceptionally seasoned.";
        }else if (result < -3) {
            t1 = "It appears to be experienced.";
        }
        msgCheck = 1;
        tell_object(myplayer, "(level) " + t1);
        break;
    default:
        break;
    }

    switch (remembered[filename][1]) {
    case 0:
    case 2:
        break;
    case 1:
        result = (myplayer->query_max_hp() - filename->query_max_hp()) * 100 / myplayer->query_max_hp();
        if (result > 49) {
            t1 = "You could keep up with it.";
        }else if (result > 19) {
            t1 = "You could outlast it easily.";
        }else if (abs(result) < 20) {
            t1 = "You could probably knock it over with a breath.";
        }else if (result < -49) {
            t1 = "You could never compare to its stamina.";
        }else if (result < -19) {
            t1 = "You couldn't match it for very long.";
        }
        msgCheck = 1;
        tell_object(myplayer, "(hp) " + t1);
        break;
    case 3:
        result = (myplayer->query_max_hp() - filename->query_max_hp()) * 100 / myplayer->query_max_hp();
        if (result > 49) {
            t1 = "You could never compare to its stamina.";
        }else if (result > 19) {
            t1 = "You couldn't match it for very long.";
        }else if (abs(result) < 20) {
            t1 = "You could keep up with it.";
        }else if (result < -49) {
            t1 = "You could probably knock it over with a breath.";
        }else if (result < -19) {
            t1 = "You could outlast it easily.";
        }
        msgCheck = 1;
        tell_object(myplayer, "(hp) " + t1);
        break;
    default:
        break;
    }

    switch (remembered[filename][2]) {
    case 0:
    case 2:
        break;
    case 1:
        myVar = myplayer->query_stats("strength") + myplayer->query_stats("constitution") + myplayer->query_stats("dexterity");
        result = (myVar - (filename->query_stats("strength") + filename->query_stats("constitution") + filename->query_stats("dexterity"))) * 100 / myVar;
        if (result > 49) {
            t1 = "It probably would see you as an equal challenger.";
        }else if (result > 19) {
            t1 = "It probably avoids fights if possible.";
        }else if (abs(result) < 20) {
            t1 = "It probably needs a rest every few minutes.";
        }else if (result < -49) {
            t1 = "It probably overpowers any threats it encounters.";
        }else if (result < -19) {
            t1 = "It probably wins more fights than it loses.";
        }
        msgCheck = 1;
        tell_object(myplayer, "(physical) " + t1);
        break;
    case 3:
        myVar = myplayer->query_stats("strength") + myplayer->query_stats("constitution") + myplayer->query_stats("dexterity");
        result = (myVar - (filename->query_stats("strength") + filename->query_stats("constitution") + filename->query_stats("dexterity"))) * 100 / myVar;
        if (result > 49) {
            t1 = "It probably overpowers any threats it encounters.";
        }else if (result > 19) {
            t1 = "It probably wins more fights than it loses.";
        }else if (abs(result) < 20) {
            t1 = "It probably would see you as an equal challenger.";
        }else if (result < -49) {
            t1 = "It probably needs a rest every few minutes.";
        }else if (result < -19) {
            t1 = "It probably avoids fights if possible.";
        }
        msgCheck = 1;
        tell_object(myplayer, "(physical) " + t1);
        break;
    default:
        break;
    }

    switch (remembered[filename][3]) {
    case 0:
    case 2:
        break;
    case 1:
        myVar = myplayer->query_stats("intelligence") + myplayer->query_stats("wisdom") + myplayer->query_stats("charisma");
        result = (myVar - (filename->query_stats("intelligence") + filename->query_stats("wisdom") + filename->query_stats("charisma"))) * 100 / myVar;
        if (result > 49) {
            t1 = "There is a familiar strategy to its behavior.";
        }else if (result > 19) {
            t1 = "There is an obvious method to its madness.";
        }else if (abs(result) < 20) {
            t1 = "There is no way this could outsmart you.";
        }else if (result < -49) {
            t1 = "There is a terrifying intellect to its strategies.";
        }else if (result < -19) {
            t1 = "There is a clever implication in its movements.";
        }
        msgCheck = 1;
        tell_object(myplayer, "(mental) " + t1);
        break;
    case 3:
        myVar = myplayer->query_stats("intelligence") + myplayer->query_stats("wisdom") + myplayer->query_stats("charisma");
        result = (myVar - (filename->query_stats("intelligence") + filename->query_stats("wisdom") + filename->query_stats("charisma"))) * 100 / myVar;
        if (result > 49) {
            t1 = "There is a terrifying intellect to its strategies.";
        }else if (result > 19) {
            t1 = "There is a clever implication in its movements.";
        }else if (abs(result) < 20) {
            t1 = "There is a familiar strategy to its behavior.";
        }else if (result < -49) {
            t1 = "There is no way this could outsmart you.";
        }else if (result < -19) {
            t1 = "There is an obvious method to its madness.";
        }
        msgCheck = 1;
        tell_object(myplayer, "(mental) " + t1);
        break;
    default:
        break;
    }
    if (!msgCheck) {
        tell_object(myplayer, "You don't know anything about this foe.");
    }
    return 1;
}

int do_study(object myplayer, object obj, string str)
{
    int enchant, diff, level, baselevel, test, droll, adjlvl, failed_level;
    string message0, message1;
    string* ppl, who;

    baselevel = (int)myplayer->query_skill("academics");
    level = baselevel + roll_dice(1, 20);
    enchant = absolute_value(obj->query_property("enchantment"));
    diff = obj->query_property("lore difficulty");
    if (!diff || !intp(diff)) {
        diff = 1;
    }
    who = myplayer->query_name();
    message0 = "You haven't seen enough of the world yet to know "
        "anything about this item.";
    message1 = "%^BOLD%^%^CYAN%^After carefully studying the " + str + ", you "
        "recall having heard or discovered the following:%^RESET%^\n"
        + obj->query_lore();

    if (!obj->query_lore()) {
        switch (random(6)) {
        case 0:  write("%^ORANGE%^You don't seem to recall any lore " +
                       "about this item.");
            break;
        case 1:  write("%^CYAN%^You don't find any unusual markings " +
                       "on this item.");
            break;
        case 2:  write("%^GREEN%^This item seems rather ordinary, " +
                       "and you cannot recall anything about it.");
            break;
        case 3:  write("%^RED%^There seem to be no legends or " +
                       "stories surrounding this particular item.");
            break;
        case 4:  write("%^BOLD%^%^BLUE%^You have never run across " +
                       "anything in your studies to tell you anything " +
                       "about this item.");
            break;
        case 5:  write("%^MAGENTA%^This item seems rather mundane " +
                       "in nature, and you cannot recall hearing any " +
                       "stories about it at all.");
            break;
        }
        return 1;
    }
//so wizzes and avs can always find out lore.
    if (avatarp(myplayer)) {
        write(message1);
        return 1;
    }
    if (objectp(obj) && pointerp(obj->query_studied()) && member_array(who, obj->query_studied()) != -1) {
        write(message1);
        return 1;
    }
    if (obj->is_studied_failed(who)) {
        failed_level = obj->is_studied_failed(who);
        if (failed_level >= baselevel) {
            write("You still cannot seem to find any stories related " +
                  "to this object.  You might need to research it more.");
            return 1;
        }
    }
    if (!diff) {
        diff = enchant * 5;
        if (level < diff) {
            obj->add_studied_failed(who, baselevel);
            write(message0);
        }else {
            obj->add_studied(who);
            write(message1);
        }
        return 1;
    }
    if (level < diff) {
        obj->add_studied_failed(who, baselevel);
        write(message0);
    }else {
        obj->add_studied(who);
        write(message1);
    }
    return 1;
}

int do_id(object myplayer, object obj, string str)
{
    int enchant, diff, level, baselevel, failed_level;
    string message0, message1, message2, charges;
    string* ppl, who, myaura;
    mapping failed;

    baselevel = myplayer->query_skill("spellcraft");
    level = baselevel + roll_dice(1, 20);
    enchant = absolute_value(obj->query_property("enchantment"));
    diff = obj->query_property("id difficulty");
    who = myplayer->query_name();
    message0 = "You can't detect any magical attributes of this item.";
    message1 = "%^BOLD%^%^GREEN%^You carefully inspect the " + str + ", taking "
        "note of any hidden properties.%^RESET%^";
    message2 = "%^BOLD%^%^GREEN%^You carefully inspect the " + str + ", but "
        "can't discern an enchantment circle upon it.%^RESET%^";

//so wizzes and avs can always find out lore.
// revoking this section as it's preventing identification of non-enchant items with other bonuses. N, 12/13.
/*  if(!obj->query_obvious_short() && !enchant) {
    write(message2);
    return 1;
    } */
    if (avatarp(myplayer)) {
        obj->add_identified(who);
        write(message1);
        if ((string)obj->query("effect") == "spell_effect") {
            myaura = (string)obj->query("spell");
            charges = (string)obj->query("uses");
            write("%^BOLD%^%^YELLOW%^You can detect an enchantment of " + myaura + " with " + charges +
                  " charges of " + obj->query("level") + " caster level.%^RESET%^");
        }
        return 1;
    }
    if ((string)obj->query("effect") == "spell_effect") {
        if ((int)obj->query("level") / 2 < (int)myplayer->query_skill("spellcraft")) {
            myaura = (string)obj->query("spell");
            charges = (string)obj->query("uses");
            write("%^BOLD%^%^YELLOW%^You can detect an enchantment of " + myaura + " with " + charges +
                  " charges of " + obj->query("level") + " caster level.%^RESET%^");
        }
    }
    if (member_array(who, obj->query_identified()) != -1) {
        write("You are already aware of the magical properties of this item.");
        return 1;
    }
    failed = obj->query("identified_failed");
    if (!failed) {
        failed = ([]);
    }
    if (member_array(who, keys(failed)) != -1) {
        failed_level = failed[who];
        if (failed_level >= baselevel) {
            write("You have already studied this item, but cannot detect any "
                  "further hidden attributes until you expand your knowledge of spellcraft.");
            return 1;
        }
    }
    if (!diff) {
        diff = (enchant + 1) * 5;
        if (level < diff) {
            failed[who] = baselevel;
            diff = diff - 5;
            if (level < diff) {
                write(message0);
            }else {
                switch (enchant) {
                case 1: myaura = "a %^CYAN%^faint blue"; break;
                case 2: myaura = "a %^CYAN%^blue"; break;
                case 3: myaura = "a %^CYAN%^bright blue"; break;
                case 4: myaura = "a %^CYAN%^very bright blue"; break;
                case 5: myaura = "an %^CYAN%^extremely bright blue"; break;
                default: myaura = "a %^CYAN%^nearly blinding blue"; break;
                }
                write("%^BOLD%^%^GREEN%^You're fairly sure you can detect " +
                      myaura + " %^GREEN%^glow around the " + str + ".%^RESET%^");
            }
        }else {
            obj->add_identified(who);
            map_delete(failed, who);
            write(message1);
        }
        obj->delete("identified_failed");
        obj->set("identified_failed", failed);
        return 1;
    }
    if (level < diff) {
        failed[who] = baselevel;
        diff = diff - 5;
        if (level < diff) {
            write(message0);
        }else {
            switch (enchant) {
            case 1: myaura = "a %^CYAN%^faint blue"; break;
            case 2: myaura = "a %^CYAN%^blue"; break;
            case 3: myaura = "a %^CYAN%^bright blue"; break;
            case 4: myaura = "a %^CYAN%^very bright blue"; break;
            case 5: myaura = "an %^CYAN%^extremely bright blue"; break;
            default: myaura = "a %^CYAN%^nearly blinding blue"; break;
            }
            write("%^BOLD%^%^GREEN%^You're fairly sure you can detect " +
                  myaura + " %^GREEN%^glow around the " + str + ".%^RESET%^");
        }
    }else {
        obj->add_identified(who);
        map_delete(failed, who);
        write(message1);
    }
    obj->delete("identified_failed");
    obj->set("identified_failed", failed);
    return 1;
}

void help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

study - learn some lore

%^CYAN%^SYNOPSIS%^RESET%^

study [%^ORANGE%^%^ULINE%^ITEM%^RESET%^|room|monster %^ORANGE%^%^ULINE%^MONSTERNAME%^RESET%^ %^ORANGE%^%^ULINE%^DIRECTION%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

Study will try to discern lore and magical properties about an %^ORANGE%^%^ULINE%^ITEM%^RESET%^. Lore check depends on your academics skill, while magical enchanments depend on your knowledge of spellcraft.

If you fail to study an item you may try againonce you have gained higher rank in appropriate skills. There are also spells that replace this command with gaining knowledge through devination or other means.

Some rooms have lore set as well and you may try to %^ORANGE%^<study room>%^RESET%^ to gain lore and knowledge about it.

You can also study monsters to compare their power with yours. You need to be one room away from a monster to study it.
You can discover up to 4 statistics of your foe.
To fix your monster list use %^ORANGE%^<study monster reset>%^RESET%^. This will clear your monster list.

%^CYAN%^SEE ALSO%^RESET%^

skills, academics, spellcraft, repair, look, recall, unremember
"
        );
}
