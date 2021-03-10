#include <std.h>
#include <move.h>

#define VOID "/d/shadowgate/void"

inherit DAEMON;

mapping targets = ([]);

int help();

object errant_hit(object foe)
{
    int i;

    object* inven = all_inventory(environment(foe));
    if (random(30) < sizeof(inven)) {
        return inven[random(sizeof(inven))];
    }
    return 0;
}

int cmd_throw(string str)
{
    string target, dir, what, what2, * exits, remainder, tmp, door;
    int distance, flag, inc, tohitroll, thaco, perfect, damage, num, targetless, i;
    object foe, current, what_ob, alt_foe;
    object* roomList = ({}), * wielded;
    flag = 0;
    targetless = -1;
    if (!str) {
        return help();
    }
    if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }

    wielded = TP->query_wielded();
    if (sizeof(wielded) < 1) {
        tell_object(TP, "You can only throw something you are wielding!");
        return 1;
    }
    if (sscanf(str, "%s %s %s", what, what2, remainder) < 3) {
        if (sscanf(str, "%s %s", what, remainder) < 2) {
            return help();
        }
    }
    for (i = 0; i < sizeof(wielded); i++) {
        if (wielded[i]->id(what + " " + what2)) {
            what_ob = wielded[i];
            flag = 1;
            break;
        }
    }
    if (!objectp(what_ob)) { //If that didn't work, see if anything is identified by the first word only
        for (i = 0; i < sizeof(wielded); i++) {
            if (wielded[i]->id(what)) {
                what_ob = wielded[i];
                flag = 0;
                break;
            }
        }
    }
    if (!objectp(what_ob)) {
        tell_object(TP, "You can only throw something you are wielding!");
        return 1;
    }

    if (objectp(what_ob) && what_ob->query_property("no drop")) {
        tell_object(TP, "You are unable to throw " + what_ob->query_name() + ".");
        return 1;
    }
    //adjust the remainder of the string, depending whether two words or one were used as the identifier
    switch (flag) {
    case 0:
        if (what2 == 0) {
            str = remainder;
        } else {
            str = what2 + " " + remainder;
        }
        break;
    case 1:
        str = remainder;
        break;
    }
    //now check whether the item is to be thrown at a target
    if (interact("at", str)) {
        if (sscanf(str, "at %s %s %d", target, dir, distance) != 3) {
            if (sscanf(str, "at %s %s", target, dir) == 2) {
                distance = 1;
            } else {
                if (sscanf(str, "at %s", target) != 1) {
                    return help();
                } else {
                    dir = "here";
                }
            }
        }
    } else {
        if (sscanf(str, "%s %d", dir, distance) != 2) {
            dir = remainder;
            distance = 1;
        }
        targetless = 1;
    }
    exits = ETP->query_exits();
    if (sizeof(exits) < 1 || member_array(dir, exits) == -1 && dir != "here") {
        tell_object(TP, "You can't throw in that direction. There's no '" + dir + "' exit in this room!");
        return 1;
    }
    if (what_ob->is_cursed()) {
        tell_object(TP, "The curse resists your attempt to throw.");
        return 1;
    }

    if (!what_ob->thrown()) {
        tell_object(TP, "You can't throw that item.");
        return 1;
    }

    if (dir == "rift") {
        tell_object(TP, "You can't get a clear shot through the magical passage.");
        return 1;
    }
    if (dir != "here" && (string)environment(TP)->query_exit(dir) == VOID) {
        tell_object(TP, "You want to throw the walls?");
        return 1;
    }

    current = ETP;
    roomList += ({ current });

    if (dir != "here" && distance > 0) {
        for (i = 0; i < distance; i++) {
            tmp = (string)current->query_exit(dir);
            if (!tmp) {
                tell_object(TP, "Error, exit " + dir + " seems to lead nowhere.");
                return 1;
            }

            if (tmp == VOID) {
                tell_object(TP, "You can't throw that far to the " + dir);
                return 1;
            }

            catch(call_other(tmp, "??"));
            current = find_object_or_load(tmp);

            if (door = current->query_door(dir)) {
                if (!current->query_open(door)) {
                    tell_object(TP, "There seems to be a closed door in your way.");
                    return 1;
                }
            }

            if (i < distance - 1) {
                tell_room(current, "Something wizzes by your head.");
            }

            if (current->query_property("indoors")) {
                if (ETP->query_property("indoors") && (distance > 1)) {
                    tell_object(TP, "You can't throw that far while indoors.");
                    return 1;
                }else if (ETP->query_property("indoors")) {
                    if (i < distance - 1) {
                        tell_object(TP, "You can't throw through an indoor room.");
                        return 1;
                    }
                }
            }
            roomList += ({ current });
        }
    }

    flag = 0;
    if (targetless == -1) { //added by Lujke
        if (!foe = present(target, current)) {
            tell_object(TP, "There is no " + target + " there!");
            return 1;
        }
        if (!TP->ok_to_kill(foe)) {
            tell_object(TP, "Greater forces prevent your malice.");
            return 1;
        }
        if (foe->query_property("no bows")) {
            tell_object(TP, "You can't seem to get a clean throw at them from here!!");
            return 1;
        }

        //tohitroll = adjust_to_hit(tohitroll);
        thaco = TP->Thaco(1, foe, what_ob);
        flag = 1;
        // Funny, this stuff seemed to be missing but important... - Garrett and Styx.
        tohitroll = random(20) + 1;
        if (tohitroll == 20) {
            perfect = 1;
        }
        if (tohitroll == 1) {
            perfect = -1;
        }
        // added by Styx to log what bugged from not having a set_name() 4/17/03
        if (((tohitroll < thaco) && (perfect != 1)) || perfect == -1) {
            if (objectp(alt_foe = errant_hit(foe)) && (random(20) > TP->Thaco(1, alt_foe, TO))) {
                tell_room(current, capitalize(what_ob->query_name()) + " flies by " + capitalize(target), foe);
                tell_object(foe, capitalize(what_ob->query_name()) + " barely misses you!");
                foe = alt_foe;
            } else {
                flag = 0;
                tell_room(current, capitalize(what_ob->query_name()) + " flies by " + capitalize(target), foe);
                tell_object(foe, capitalize(what_ob->query_name()) + " barely misses you!");
                write("You missed...");
            }
        }
    }


    if (flag) {
        if (perfect) {
            write("Perfect shot!");
        }
        tell_room(current, foe->query_cap_name() + " is hit with a " + what_ob->query_name(), foe);
        write("You hit the " + foe->query_cap_name() + " with a " + what_ob->query_name() + "!");
        tell_object(foe, "You are hit with a " + what_ob->query_name());
        foe->add_poisoning(what_ob->query_poisoning());
        damage = what_ob->thrown_hit(foe);
        damage += distance;
        foe->add_attacker(TP);

        if (objectp(what_ob) && what_ob->query_damage_type()) {
            foe->cause_typed_damage(foe, foe->return_target_limb(), damage, what_ob->query_damage_type());
        } else {
            foe->bow_hit(TP, damage);
        }

        if (objectp(what_ob)) {
            if (objectp(foe)) {
                if (what_ob->move(foe) != MOVE_OK) {
                    what_ob->move(environment(foe));
                }
            } else {
                what_ob->move(distance > 0?roomList[sizeof(roomList) - 1]:ETP);
            }
        }
        if (foe->check_death()) {
            write("You have killed " + target + "!!!");
            return 1;
        }
    } else {
        what_ob->move(current);
    }
    if (targetless < 1) {
        if (objectp(foe) && !userp(foe) && living(foe)) {
            if (foe->query_paralyzed() ||
                ((object*)foe->query_attackers() != ({})
                 && (member_array(TP, foe->query_attackers()) == -1
                     && !present(TP, ETP)))) {
                return 1;
            } else {
                if (!living(foe)) {
                    return 1;
                }
                if (!targets[foe] || targets[foe] == ({})) {
                    call_out("move_monster", 2, foe, TP);
                }
                targets[foe] = roomList;
            }
        }
    } else {
        tell_room(ETP, TPQCN + " throws " + what_ob->query_short()
                  + " in the " + dir + " direction.", TP);
        tell_object(TP, "You throw " + what_ob->query_short()
                    + " in the " + dir + " direction.");
    }
    return 1;
}

void move_monster(object foe, object player)
{
    object current;
    int grx, grnum_p;
    object* grplayers, grhere, grvictim, * roomList;
    if (!objectp(foe)) {
        return;
    }
    if (!targets[foe]) {
        return;
    }
    if (foe->query_paralyzed() || foe->query_tripped() || ((object*)foe->query_attackers() != ({})
                                                           && (member_array(player, foe->query_attackers()) == -1 && !present(player, environment(foe))))) {
        return 1;
    }
    roomList = targets[foe];

    if (!pointerp(roomList) || !sizeof(roomList)) {
        return;
    }

    current = roomList[sizeof(roomList) - 1];
    grhere = environment(foe);
    foe->move_player(current, "in a rage");
    foe->kill_ob(player, 1);

    if (foe->query_property("swarm")) {
        grplayers = all_inventory(grhere);
        grplayers -= ({ foe });
        grnum_p = sizeof(grplayers);
        for (grx = 0; grx < grnum_p; grx++) {
            grvictim = grplayers[grx];
            if (living(grvictim) && !userp(grvictim) && grvictim->query_property("swarm") && grvictim != foe && !grvictim->query_paralyzed()) {
                grvictim->move_player(current, "in a rage");
                TP->kill_ob(grvictim, 1);
            }
        }
    }
    roomList -= ({ current });
    targets[foe] = roomList;
    if (sizeof(roomList)) {
        call_out("move_monster", 2, foe, player);
    }
}

int help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

throw - makes stuff fly

%^CYAN%^SYNOPSIS%^RESET%^

throw %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ at %^ORANGE%^%^ULINE%^TARGET%^RESET%^
throw %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ at %^ORANGE%^%^ULINE%^TARGET%^RESET%^ %^ORANGE%^%^ULINE%^DIRECTION%^RESET%^ %^ORANGE%^%^ULINE%^DISTANCE%^RESET%^
throw %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ %^ORANGE%^%^ULINE%^DIRECTION%^RESET%^
throw %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ %^ORANGE%^%^ULINE%^DIRECTION%^RESET%^ %^ORANGE%^%^ULINE%^DISTANCE%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

Throw can be applied to any wielded object. Throwing at a target starts combat. Some objects will do nothing when they hit a target. Others will explode, capture pierce or otherwise wound the target. Oh some might just break.

Throwing an object without naming a target moves it to the relevant room.

When wielding a bow, you can use shoot command instead.

%^CYAN%^EXAMPLES%^%^RESET%^

The command only looks at objects you are wielding. So, if you wish to throw 'dagger 2' in your inventory at a target in the same room as you, use the commands:

  wield dagger 2
  throw dagger at %^ORANGE%^%^ULINE%^TARGET%^RESET%^

%^CYAN%^SEE ALSO%^RESET%^

peer, look, mmap, map, help
"
        );
    return 1;
}
