// /std/riding_animal.c
#include <std.h>
#include <daemons.h>
#define PMAXBONUS 50
#define PDIVIDER 1500
#define PBONUS 50
#define MINLEVEL  ((query_level()/ (1 + query_peaceful())) - 3)
inherit WEAPONLESS;

string rider;         /* names of the people riding */
int max_distance;
int curr_people=0;
int peaceful, buck_chance;
int temp, flag;
string orig_short;      /* the original short description */
string myname="";
string mylong="";
object owner;
object riderObj;
string enter_room, exit_room;
int riding_level;

/* add actions */
int enter(string str);  /* to mount */
int exit(string str);   /* to dismount  */
int zoom(string str);   /* to maneuver */
int report();
int leave_room();

int query_max_people();
void set_max_distance(int i);
void set_enter_room(string str);
void set_exit_room(string str);
string query_vehicle_type();
void set_vehicle_short(string str);
void new_short_desc();
string query_riders();
string get_ob_number();
int query_peaceful();
int check_for_buck();
int ditch_animal(string str);
int query_riding_level();
int do_throw(int diff);
//added is_mount to help with tethering posts.  Circe 5/28/04
string is_mount;
// adding a new function for special cases (war horses, etc.) to insure above checks are made and try to zap some bugs once and for all *Styx*  12/12/04
int restrict_mount_ok(object who);

void movement(object tp) {
  TO->move(environment(tp));
}

void create() {  // added "void" (declaration) for bug prevention *Styx* 7/14/05
  ::create();
  rider=0;
  riderObj = 0;
  set_property("riding",1);
  //    if(base_name(TO) != "/std/riding_animal")
  //        write_file("/d/save/ra.log",base_name(TO)+"\n");
}

void init() {  // added "void" (declaration) for bug prevention *Styx* 7/14/05
  ::init();
  add_action("enter","mount");
  add_action("exit","dismount");
  add_action("zoom","ride");
  add_action("kill_something","sic");
  add_action("give_me_away","give");
  add_action("kill_intercept","kill");
  add_action("handle_critter","handle");
  add_action("rename","name");
  add_action("lead_animal","lead");
  add_action("ditch_animal","unlead");
  add_action("redo_long","redescribe");
}

void heart_beat()
{
    ::heart_beat();
    if (!objectp(TO))
        return;
    if (objectp(riderObj) && riderObj->query_ghost()) {
        rider = 0;
        riderObj = 0;
    }
    if (objectp(riderObj) && (riderObj->query_unconscious() || riderObj->query_bound() || riderObj->query_tripped())) {
        tell_object(riderObj, "%^BOLD%^You fall from your mount.");
        tell_room(ETO, "%^BOLD%^" + riderObj->QCN + " falls from " + riderObj->query_possessive() + " mount.", riderObj);
        riderObj->set_in_vehicle(0);
        rider = 0;
        riderObj = 0;
    }
    if (query_unconscious() || query_paralyzed() || query_tripped() || query_bound()) {

        if (objectp(riderObj)) {
            tell_object(riderObj, "%^BOLD%^Your mount collapses and you fall to the ground.");  // moved this down here so it won't repeat if there is no rider. *Styx*
            tell_room(ETO, "%^BOLD%^" + TO->QCN + " collapses and " + riderObj->QCN + " falls to the ground.", riderObj);
            riderObj->set_in_vehicle(0);
            riderObj = 0;
            rider = 0;
        } else {                // objectp(riderObj)
            rider = 0;
            if (objectp(ETO))
                tell_room(ETO, TO->QCN + " collapses to the ground.");
        }
    }
}

int is_animal()
{
    return 1;
}

object query_current_rider()
{
    return riderObj;
}

void set_max_distance(int i)
{
    max_distance = i;
}

void set_enter_room(string str)
{
    enter_room = str;
}

void set_myname(string str)
{
    myname = str;
}

void set_exit_room(string str)
{
    exit_room = str;
}

string query_vehicle_type()
{
    return "riding animal";
}

string query_rider()
{
    return rider;
}

string query_is_mount()
{
    return 1;
}

string get_ob_number()
{
    string junk, numb;

    sscanf(file_name(TO), "%s#%s", junk, numb);
    return numb;
}

void set_peaceful()
{
    peaceful = 1;
}

int query_peaceful()
{
    return peaceful;
}

int query_riding_level()
{
    return riding_level;
}

void set_riding_level(int i)
{
    riding_level = i;
}

int set_owner(object new_owner)
{
    owner = new_owner;
    add_id(owner->query_name() + "'s " + query_name());
    return 1;
}

void remove_owner()
{
    owner = 0;
}

object query_owner()
{
    return owner;
}

void set_buck_chance(int chance)
{
    buck_chance = chance;
}

void set_vehicle_short(string str)
{
    set_short(str);
}

void set_short(string str)
{
    orig_short = str;
    ::set_short(str);
}

string query_short()
{
    string hold;

    if (myname != "")
        hold = capitalize(myname);
    else
        hold =::query_short();
    if (!rider || !objectp(riderObj) || riderObj->query_invis())
        return hold;
    return hold + " (ridden by " + riderObj->QCN + ")";
}

string query_name(){
  if (myname != "")
    return myname;
  else
    return ::query_name();
}

int restrict_mount_ok(object who) { return 1; }
// default to 1 for no restrictions unless a restriction is added so a fail from there means fail here *Styx*

int enter(string str)
{
    object ob;
    string which;

    if (TP->query_bound() || TP->query_unconscious() || TP->query_tripped()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }

    if (!str)
        return notify_fail("Mount what?\n");
    if ((object) TP->query_in_vehicle()) {
        write("You are already riding an animal or in a vehicle!");
        return 1;
    }

    if (TO == present(str, ETP)) {
        if (member_array(TP, query_attackers()) >= 0) {

            write("The " + orig_short + " won't let you mount it!");
            return 0;
        }
        if (riderObj && objectp(riderObj)) {
            write("The animal is being ridden by " + query_current_rider()->QCN + ".\n");
            return 1;
        }
        if (query_size() < TP->query_size()) {
            write("You are clearly too large for the " + QCN + ".");
            notify_fail("");    // need this so it won't return What? also
            return 0;
        }

        if (TP->query_property("flying")) {
            write("You can't ride and fly at the same time.\n");
            return 0;
        }
        if (restrict_mount_ok(TP)) {
            if (pointerp(TP->query_followers()) && (member_array(TO, TP->query_followers()) != -1))
                ditch_animal(query_id()[0]);
            write("You mount the " + orig_short + "\nType ride <direction> <distance> to move.");
            tell_room(ETP, TPQCN + " mounts the " + orig_short + ".", TP);
            TP->set_in_vehicle(TO);

            rider = TPQCN;
            riderObj = TP;
            return 1;
        } else {
            write("You fail to mount the " + orig_short + ".");
            return 0;
        }
    }
    return notify_fail("There doesn't seem to be a " + str + " here you can ride.\n");
}

int exit(string str)
{
    if (TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    if ((object) TP->query_in_vehicle() != TO)
        return notify_fail("You are not on the " + orig_short + "!\n");
    write("You dismount the " + orig_short + ".");
    tell_room(ETP, TPQCN + " dismounts the " + orig_short + ".", TP);
    TP->set_in_vehicle(0);
    riderObj = 0;
    rider = 0;
    return 1;
}

int do_prof()
{
    int prof = riderObj->query_skill("athletics") + roll_dice(1, 20);

    if (query_riding_level() > prof)
        return do_throw(query_riding_level() - prof);
    return 1;
}

int move_forward()
{
    //    write("moving");
    if (query_bound() || query_unconscious() || query_tripped() || query_paralyzed())
        return 0;
    if (!objectp(TP))
        return 1;
    return do_prof();
}

int zoom(string str)
{
    string newroom, prefunc, dir, y, path, messa, messb;
    int dist, i, bonus;
    object who, oldroom, tp;

    if (owner && (owner != TP))
        return notify_fail("You are not this animal's owner!\n");
    if (TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    if (!str)
        return notify_fail("Please use the format ride <direction> <distance>.\n");
    if ((object) TP->query_in_vehicle() != TO){
        write("You must be on the " + orig_short + " to command it.\n");
        return;
    }
    if (sscanf(str, "%s %d", dir, dist) != 2) {
        sscanf(str, "%s", dir);
        dist = 1;
    }
    if (TP->query_paralyzed())
        return notify_fail(TP->query_paralyze_message());
    if (!dir)
        return notify_fail("Please use the format ride <direction> <distance>.\n");
    if (query_paralyzed())
        return notify_fail("Your steed can't seem to move.\n");
    if (dist > max_distance || dist < 0)
        return notify_fail("This " + orig_short + " can travel 0-" + max_distance + " per turn.\n");
    if (TP->query_disable())
        return notify_fail("You can't leave while doing something else.\n");
    switch (dir) {
    case "n":
        dir = "north";
        break;
    case "s":
        dir = "south";
        break;
    case "e":
        dir = "east";
        break;
    case "w":
        dir = "west";
        break;
    case "nw":
        dir = "northwest";
        break;
    case "ne":
        dir = "northeast";
        break;
    case "sw":
        dir = "southwest";
        break;
    case "se":
        dir = "southeast";
        break;
    case "u":
        dir = "up";
        break;
    case "d":
        dir = "down";
        break;
    case "o":
        dir = "out";
        break;
    }
    // Do the actual moving here
    tp = TP;
    while (dist) {
        newroom = environment(TO)->query_exit(dir);
        if (stringp(newroom) && newroom != "/d/shadowgate/void") {
            TP->force_me(dir);
        } else {
            return notify_fail("You can't go in that direction!\n");
        }
        dist--;
    }
    write("You bring the " + orig_short + " to a stop.");
    tell_room(ETP, TPQCN + " brings the " + orig_short + " to a halt.", TP);
    return 1;
}

int kill_something(string str)
{
    object target;

    if ((!objectp(TO)))
        return 0;

    if ((object)TP->query_in_vehicle() != TO) {
        write("You must be on the " + orig_short + " to command it.\n");
        return;
    }

    if (owner && (TP != owner))
        return notify_fail("You are not this animal's owner!\n");
    if (!str)
        return notify_fail("sic what?\n");
    if (TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    riderObj = TP;
    if (query_peaceful())
        return notify_fail("This animal cannot fight.\n");
    if (!do_prof())
        return 1;
    target = present(str, environment(TO));
    if (!objectp(target))
        return 1;
    if ((object) target->query_in_vehicle() == TO)
        return notify_fail("The " + orig_short + " looks at you as if to say:  Are you nuts?\n");
    if (target == TO)
        return notify_fail("The " + orig_short + " looks at you as if to say:  Are you nuts?\n");
    if (!target)
        return notify_fail("There's nothing here by that name to attack!\n");
    if (!riderObj->ok_to_kill(target))
        return notify_fail("Supernatural forces prevent that.\n");
    if ((target->is_player() && (query_level() - 10) > (int) target->query_highest_level()))
        return notify_fail("Supernatural forces prevent that.\n");
    //   target->add_attacker(owner);
    if (!target->kill_ob(riderObj, 0))
        riderObj->kill_ob(target, 0);
    tell_room(ETO, TOQCN + " attacks " + target->QCN + ".", TP);
    force_me("kill " + str);
    return 1;
}

int give_me_away(string str)
{
    string what, who;
    object new_owner;

    if (sscanf(str, "%s to %s", what, who) != 2)
        return notify_fail("give what to who?\n");
    if (!id(what))
        return 0;
    if (owner != TP)
        return notify_fail("You can't give away an animal you don't own!\n");
    if (TP->query_unconscious()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    new_owner = present(who);
    if (!new_owner)
        return notify_fail("That person is not here.\n");
    if (!TO->set_owner(new_owner)) {
        write(new_owner->QCN + " is unable to accept your gift.");
        tell_object(new_owner, TPQCN + " tries to give you " + TP->query_possessive() + " " + orig_short + ".\n");
    } else {
        write("You give the " + orig_short + " to " + new_owner->QCN + ".");
        if (TP->query_followers() != 0)
            if (member_array(TO, TP->query_followers()) != -1)
                ditch_animal(query_id()[0]);
        TP->remove_pet(TO);
        TO->set_owner(new_owner);
        new_owner->add_pet(TO);
        tell_object(new_owner, TPQCN + " gives you " + TP->query_possessive() + " " + orig_short + ".\n");
        tell_room(environment(TO), TPQCN + " gives " + new_owner->QCN + " a " + orig_short + ".", ( {
                                                                                                   TP, new_owner}
                  ));
    }
    return 1;
}

int stop_goto(string str)
{
    if ((object) TP->query_in_vehicle() != TO)
        return 0;
    write("You better dismount first, unless you want things to get messed up.");
    return 1;
}

int query_value()
{
    int temp_value;

    if (temp_value = query_property("value"))
        return temp_value;
    temp_value = query_level() * 40;
    temp_value += query_stats("strength") * 20;
    temp_value /= query_peaceful() + 1;
    temp_value += 100;
    temp_value /= query_max_hp();
    temp_value *= query_hp();
    return temp_value;
}

void set_value(int new_value)
{
    if (new_value < query_value())
        return;
    ::set_value(new_value);
}

int kill_intercept(string str)
{
    if (!stringp(str))
        return 0;
    if (present(str, environment()) != TO)
        return 0;
    if (owner) {
        if (owner == TP) {
            owner = 0;
            TP->remove_pet(TO);
        } else
            tell_object(owner, "Your mount cries out in distress!\n");
    }
    if ((object) TP->query_in_vehicle() == TO) {
        write("The " + orig_short + " throws you off!");
        tell_room(ETP, TPQCN + " is thrown off by " + TP->QP + " " + orig_short + "!", TP);
        exit(orig_short);
        TP->cause_typed_damage(TP, "torso", query_stats("strength") / 2, "bludgeoning");
        return 0;
    }
    return 0;
}

int handle_critter(string str)
{
    object ob;
    string which;
    int prof, num;

    if ((int) TP->query_property("handled_time") > time()) {
        tell_object(TP, "You can't do that again yet.");
        return 1;
    }

    if (TP->query_bound() || TP->query_unconscious() || TP->query_tripped()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    if (!str)
        return notify_fail("Handle what?\n");
    if ((object) TP->query_in_vehicle()) {
        write("You can't handle another mount while riding another animal.");
        return 1;
    }
/*   once we establish we're working with the right animal, these failures should
 *  work correctly as write and return 1 *Styx* 12/26/05
 *    using QCN in this section so these error messages refer to the object kicking
 *  them out for better clarity
 */
//  hmm, wonder if this would be a better way for this... (from kits)
//   if(!id(word)) return 0; //added by Circe so it won't conflict with quivers
    if (TO == present(str, ETP)) {
        tell_room(ETO, TPQCN + " seems to be trying to make friends with " + QCN + ".", TP);
        write("You begin trying to make friends with " + QCN + ".");
        if (riderObj && objectp(riderObj)) {
            write("The " + QCN + " is busy being ridden by " + query_current_rider()->QCN + ".");
            return 1;
        }
        if (owner) {
            if (TP->query_name() == owner->query_name()) {
                write("You already own that " + str + ".\n");
                return 1;
            }
            if (present((string) owner->query_name(), ETP)) {
                write("The " + str + " isn't going to accept you with the owner so near.\n");
                return 1;
            }
            if (TO->is_warhorse()) {
                write("A war horse will not respond to any but its owner.\n");
                return 1;
            }
            // fall through to the other checks if these don't restrict it
        }
        if (member_array(TP, query_attackers()) >= 0) {
            write("The " + QCN + " seems to be a little angry at you!");
            return 1;
        }
        TP->remove_property("handled_time");
        TP->set_property("handled_time", time() + 180);

        if (TO->query_flying_prof()) {
            num = (int) TO->query_flying_prof();
        } else {
            num = riding_level;
        }
        if (TP->is_class("ranger")) {
            num -= 5;
        }
        prof = (int) TP->query_skill("survival");

        if ((prof + roll_dice(1, 20)) < (num + 10)) {
            tell_object(TP, "The " + orig_short + " snorts at you.");
            return 1;
        }

        if (owner && objectp(owner))
            owner->remove_pet(TO);
        TO->set_owner(TP);
        TP->add_pet(TO);
        write("%^BOLD%^You use your skills to convince the " + QCN + " to become obedient to you.");
        return 1;
    }                           // here we *do* need to refer to the str they specified in their command....
    return notify_fail("There doesn't seem to be a " + str + " here for you to handle.\n");
}

int rename(string str)
{
    object ob;
    string myid, newname, *orig_ids;
    int num;

    if (!str)
        return notify_fail("Name what?\n");
    if (sscanf(str, "%s %d %s", myid, num, newname) == 3)
        myid = myid + " " + num;
    else if (sscanf(str, "%s %s", myid, newname) != 2)
        return 0;
    if (!ob = present(myid, ETO))
        return 0;
    if (TP != (object) ob->query_owner())
        return notify_fail("You can only name your own pets.\n");
    orig_ids = ob->query_id();
    if (myname != "") {
        orig_ids = orig_ids - ( {
                capitalize(myname)}
            );
        orig_ids = orig_ids - ( {
                lower_case(myname)}
            );
    }
    ob->set_id(orig_ids);
    ob->add_id(lower_case(newname));
    ob->add_id(capitalize(newname));
    ob->set_myname(newname);
    write("You name your animal " + newname + ".");
    return 1;
}

int lead_animal(string str)
{
    if (TP->query_bound() || TP->query_unconscious() || TP->query_tripped()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    if (!str)
        return notify_fail("Lead what?\n");
    if ((object) TP->query_in_vehicle()) {
        write("You are already riding an animal or in a vehicle!");
        return 1;
    }
// *need* to use write for these failures so they don't get lost in a later failure on another riding animal object
    if (TO == present(str, ETP)) {
        notify_fail("");        // need this so don't get the "What?" thing from these
        if (TP != owner) {
            write("The " + orig_short + " isn't yours to lead.");
            return 0;
        }
        if (query_current_rider()) {
            write("You cannot lead the " + orig_short + " with someone riding it.");
            return 0;
        }
        if (query_property("tethered")) {
//added in response to a bug report that tethered animals were still following their owners
            write("You need to untether the the " + orig_short + " before you can lead it.");
            return 0;
        }
        if (member_array(TP, query_attackers()) >= 0) {
            write("The " + orig_short + " won't let you lead it!");
            return 0;
        }
        TP->add_follower(TO);
        tell_object(TP, QCN + " is now following you.");
        tell_room(ETP, TPQCN + " begins leading " + QCN + ".", TP);
        return 1;
    }
// hopefully don't need this failure
//  return notify_fail("You fail to lead the "+orig_short+".");
    if (!present(str, ETP))
        return notify_fail("There is no " + str + " here.\n");
//  return 1;
}

int ditch_animal(string str)
{
    if (!str || !id(str))
        return 0;
    if (member_array(TO, TP->query_followers()) == -1)
        return notify_fail(QCN + " is not following you now.\n");
    TP->remove_follower(TO);
    tell_object(TP, TO->QCN + " will no longer follow you.");
    tell_room(ETP, TPQCN + " releases the reins and stops leading " + TO->QCN + ".", TP);
    return 1;
}

int redo_long(string str)
{
    string myid, newlong, *orig_ids;
    int num;

    if (!str)
        return notify_fail("Redescribe what?\n");
    if (sscanf(str, "%s %d %s", myid, num, newlong) == 3)
        myid = myid + " " + num;
    else if (sscanf(str, "%s %s", myid, newlong) != 2)
        return 0;
    if (!present(myid, ETO) == TO)
        return 0;
    if (TP != owner)
        return notify_fail("You can only describe your own pets.\n");
    mylong = newlong;
    write("Your animal's description now reads:\n" + query_name() + " " + mylong);
    return 1;
}

string query_long(string unused)
{
    string pre, stuff, reg, sub;
    int x;

    if (mylong == "")
        return::query_long();
    else {
        reg = "";
        pre = "%^CYAN%^%^BOLD%^You look over the " + query_gender() + " " + query_race() + ".%^RESET%^\n";
        pre += "%^CYAN%^" + capitalize(query_name()) + " " + mylong + "%^RESET%^\n";
        sub = capitalize(query_subjective());
        x = ((player_data["general"]["hp"] * 100) / player_data["general"]["max_hp"]);
        if (x > 90)
            reg += "%^YELLOW%^" + sub + " is in top shape.%^RESET%^\n";
        else if (x > 75)
            reg += "%^WHITE%^%^BOLD%^" + sub + " is in decent shape.%^RESET%^\n";
        else if (x > 60)
            reg += "%^WHITE%^" + sub + " is slightly injured.%^RESET%^\n";
        else if (x > 45)
            reg += "%^MAGENTA%^" + sub + " is hurting.%^RESET%^\n";
        else if (x > 30)
            reg += "%^ORANGE%^" + sub + " is badly injured.%^RESET%^\n";
        else if (x > 15)
            reg += "%^RED%^%^BOLD%^" + sub + " is terribly injured.%^RESET%^\n";
        else
            reg += "%^RED%^" + sub + " is near death.%^RESET%^\n";
        stuff = describe_item_contents(( {
                }
                ));
        if (stuff == "")
            reg += capitalize(query_subjective()) + " is empty handed.\n";
        else {
            stuff = " " + stuff;
            stuff = replace_string(stuff, ",", "\n");
            stuff = replace_string(stuff, " are here.", "");
            reg += "%^GREEN%^%^BOLD%^" + capitalize(query_subjective()) + " is carrying:%^RESET%^\n" + "%^GREEN%^" + stuff + "%^RESET%^";
        }
        reg = pre + reg;
        return reg;
    }
}

int do_throw(int diff){
    switch(diff) {
    case 0:
    case 1:
    case 2:
      write("%^BOLD%^The "+query_short()+" refuses to follow your command.");
      tell_room(ETP,"%^BOLD%^The "+query_short()+" refuses to follow "+TPQCN+"'s commands.",TP);
      return 0;
    case 3:
    case 4:
    case 5:
      write("%^BOLD%^The "+query_short()+" refuses to follow your command. It rears up and tries to throw you but fails.");
      tell_room(ETP,"%^BOLD%^The "+query_short()+" refuses to follow "+TPQCN+"'s commands. It rears up and tries to throw "+TP->query_objective()+" but fails.",TP);
      return 0;
    case 6:
      write("%^BOLD%^The "+query_short()+" refuses to follow your command. It rears up, bucks, and throws you from its saddle.");
      tell_room(ETP,"%^BOLD%^The "+query_short()+" refuses to follow "+TPQCN+"'s commands. It rears up, bucks, and throws "+TP->query_objective()+" from the saddle.",TP);
      write("%^BOLD%^You hit the ground hard from being thrown.");
      exit(orig_short);
      TP->cause_typed_damage(TP, "torso", random(((int)TP->query_max_hp()) / 4), "bludgeoning");
      TP->add_attacker(TO);
      TP->check_death();
      TP->remove_attacker(TO);
      return 0;

    default:
      write("%^BOLD%^The "+query_short()+" refuses to follow your command. It rears up, bucks and throws you from its saddle.");
      tell_room(ETP,"%^BOLD%^The "+query_short()+" refuses to follow "+TPQCN+"'s commands. It rears up, bucks and throws "+TP->query_objective()+" from the saddle.",TP);
      exit(orig_short);
      write("%^BOLD%^You hit the ground hard from being thrown.");
      TP->cause_typed_damage(TP, "torso", random(((int)TP->query_max_hp()) / 4), "bludgeoning");
      write("%^BOLD%^The enraged animal turns and attacks you!");
      tell_room(ETO,"The enraged animal turns and attacks "+TPQCN+"!",TP);
      TO->kill_ob(TP,1);
      return 0;
    }
  return 1;
}

int clean_up()
{
    if (objectp(query_rider()))
        return 1;
    if (objectp(query_owner()))
        return 1;
    else
        return::clean_up();
}
