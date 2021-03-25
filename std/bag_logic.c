#include <std.h>
#include <move.h>
#include <daemons.h>
#include <security.h>

inherit CONTAINER;
string open_long_desc;
string closed_long_desc;
string* open_riddles = ({});
string* open_riddle_answers = ({});
string* riddle_solvers = ({});
mapping lock_data;
int lock_dif, solve_once = 1;
nosave object pilfered_for, pilfered_by, pilfered_at;

void init()
{
    ::init();

    add_action("get_from", "get");
    add_action("put_into", "put");
    add_action("open_container", "open");
    add_action("close_container", "close");
    add_action("unlock_container", "unlock");
    add_action("lock_container", "lock");
    add_action("PickLock", "pick");
}

varargs receive_objects(object ob)
{
    if (!objectp(TO)) {
        return ::receive_objects(ob);
    }
    if (!TO->query_lock_data()) {
        return ::receive_objects(ob);
    }
    if ((string)TO->query_lock_data("status") == "locked") {
        if (!TO->query_closed()) {
            TO->set_closed(1);
        }
    }
    return ::receive_objects(ob);
}

string* query_open_riddles()
{
    return open_riddles;
}

string* query_open_riddle_answers()
{
    return open_riddle_answers;
}

void set_open_riddle(mixed str)
{
    if (!str) {
        return;
    }
    if (!pointerp(str)) {
        str = ({ str });
    }
    open_riddles = str;
}

void set_open_riddle_answers(mixed str)
{
    if (!str) {
        return;
    }
    if (!pointerp(str)) {
        str = ({ str });
    }
    open_riddle_answers = str;
}

int set_solve_only_once(int x)
{
    solve_once = x;
    return solve_once;
}

int isMagic()
{
    int p;
    int n, i;
    object* inven;
    p = ::isMagic();
    inven = all_inventory(TO);
    for (i = 0; i < sizeof(inven); i++) {
        n = inven[i]->isMagic();
        p = p < n?n:p;
    }
    return p;
}

int query_lock_data(string str)
{
    if (!str) {
        if (!lock_data) {
            return 0;
        }else {
            return 1;
        }
    }
    switch (str) {
    case "status":
        return lock_data["status"];
    case "key":
        return lock_data["key"];
    }
}

int query_value()
{
    int val;
    int n, i;
    object* inven;

    val = ::query_value();
    inven = all_inventory(TO);
    for (i = 0; i < sizeof(inven); i++) {
        val += inven[i]->query_value();
    }
    return val;
}

int item_allowed(object item)
{
    return 1;
}

int is_table()
{
    return -1;
}

int put_into(string str)
{
    int res, i, silly;

    object ths, tht, * inv, shapeshift_restricted_commands;
    string this, that, prep, desc;

    if (TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }

    if (stringp(str) && sscanf(str, "%s in %s", this, that) == 2) {
        if (objectp(shapeshift_restricted_commands = to_object("/std/races/shapeshifted_races/restricted_commands"))) {
            if (!avatarp(TP)) {
                if (!shapeshift_restricted_commands->allow_shifted_command(TP, "put", this + "" + that)) {
                    tell_object(TP, "You can't put " + this + " in " + that + " while shapeshifted.");
                    destruct(shapeshift_restricted_commands);
                    return 1;
                }
            }
        }

        if (present(this, TP)) {
            if (present(that, TP) || present(that, ETP)) {
                ths = present(this, TP);
                tht = present(that, TP);

                if (ths == tht) {
                    notify_fail("Get real!\n");
                    return 0;
                }

                if (!tht) {
                    tht = present(that, ETP);
                }
                if (tht != TO) {
                    return 0;
                }

                if (ths->drop()) {
                    notify_fail("You cannot do that!\n");
                    return 0;
                }

                if (tht->receive_objects()) {
                    if (!tht->item_allowed(ths)) {
                        tell_object(TP, "You fail to put " + ths->query_short() + " in " + tht->query_short() + ".\n");
                        return 0;
                    }


                    if (ths->is_baggy() && sizeof(all_inventory(ths))) {
                        tell_object(TP, "You realize " + ths->query_short() + " is too full to fit into " + tht->query_short() + ".\n");
                        return 0;
                    }

                    desc = tht->query_short();
                    res = (int)ths->move(tht);

                    prep = " in ";
                    if (is_table() == 1) {
                        prep = " on ";
                    }
                    if (res == MOVE_OK) {
                        write("You put " + ths->query_short() + prep
                              + desc + ".\n");
                        tell_room(ETP, TPQCN + " puts " + ths->query_short() + prep
                                  + desc + ".", TP);
                        return 1;
                    }

                    if (res == MOVE_NO_ROOM) {
                        notify_fail("For some reason it does not fit...\n");
                    }

                    if (res == MOVE_NOT_ALLOWED) {
                        notify_fail("You are not allowed to do that...\n");
                    }

                    return 0;
                }

                notify_fail("It is closed.\n");
                return 0;
            }

            notify_fail(capitalize(that) + " is not here.\n");
            return 0;
        }

        notify_fail("You are not carrying " + this + ".\n");
        return 0;
    }
    return 0;
}

void clear_pilfer()
{
    pilfered_for = 0;
    pilfered_by = 0;
    pilfered_at = 0;
}

int actually_get(object who, object what)
{
    int res;
    if (!objectp(what)) {
        return 0;
    }
    if (!objectp(who)) {
        return 0;
    }
    if (!objectp(TO)) {
        return 0;
    }
    if (who->query_bound() || who->query_unconscious()) {
        who->send_paralyzed_message("info", who);
        return 1;
    }
    res = (int)what->move(TP);
    if (res == MOVE_OK) {
        if (objectp(what)) {
            tell_object(who, "You get " + what->query_short() + " from "
                        + TO->query_short() + ".");
            if (objectp(environment(who))) {
                tell_room(environment(who), who->QCN + " gets " + what->query_short() + " from "
                          + TO->query_short() + ".", who);
            }
            return 1;
        }
    }

    if (res == MOVE_NOT_ALLOWED) {
        tell_object(who, "You can't do that!");
    }
    if (res == MOVE_NO_ROOM) {
        tell_object(who, what->query_short() + ": Too heavy!");
    }
    return 1;
}

void delayed_get(object ob, object who, object where)
{
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ob)) {
        return;
    }
    if (!objectp(who)) {
        return;
    }
    if (!objectp(where)) {
        return;
    }
    if (!objectp(pilfered_for) || !objectp(pilfered_by) || !objectp(pilfered_at)) {
        return;
    }
    if (ob != pilfered_for ||
        who != pilfered_by ||
        where != pilfered_at) {
        clear_pilfer();
        tell_object(who, "You stop pilfering through " + TO->query_short() + "!");
        return;
    }
    actually_get(who, ob);
    clear_pilfer();
    return;
}

int get_from(string str)
{
    int silly, res, i, delay;
    object ob, tmp, * inv, shapeshift_restricted_commands;
    string what, where;

    if (!stringp(str)) {
        return 0;
    }
    if (TP->query_ghost()) {
        return 0;
    }
    if (TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }

    if (sscanf(str, "%s from %s", what, where) != 2) {
        return 0;
    }

    if (objectp(shapeshift_restricted_commands = to_object("/std/races/shapeshifted_races/restricted_commands"))) {
        if (!avatarp(TP)) {
            if (!shapeshift_restricted_commands->allow_shifted_command(TP, "get", what + "" + where)) {
                tell_object(TP, "You can't get " + what + " from " + where + " while shapeshifted.");
                destruct(shapeshift_restricted_commands);
                return 1;
            }
        }
    }

    if (id(where)) {
        tmp = TO;
    }else {
        tmp = parse_objects(ETO, where);
    }
    if (tmp != TO) {
        return 0;
    }

    if (TO->receive_objects()) {
        if (what != "all") {
            ob = present(what, TO);
            if (!ob) {
                ob = parse_objects(TO, what);
            }
            if (!ob) {
                write("There is no " + what + " in " + TO->query_short() + ".");
                return 1;
            }
            if (TO->is_chest()) {
                if (objectp(TP)) {
                    if (sizeof(TP->query_attackers())) {
                        if (pilfered_by != TP || pilfered_at != ETP) {
                            remove_call_out("delayed_get");
                            clear_pilfer();
                        }
                        delay = (int)ob->query_weight() * 3;
                        if (delay < 2) {
                            delay = 2;
                        }
                        if (delay > 10) {
                            delay = 10;
                        }
                        if (objectp(pilfered_for)) {
                            tell_object(TP, "You are already pilfering through the " + TO->query_short() +
                                        " for " + pilfered_for->query_short() + "!");
                            return 1;
                        }
                        tell_object(TP, "You begin pilfering through " + TO->query_short() +
                                    " in an attempt to get " + ob->query_short() + " from it!");
                        tell_room(ETP, TPQCN + " begins pilfering through " + TO->query_short() + "!", TP);

                        pilfered_for = ob;
                        pilfered_by = TP;
                        pilfered_at = ETP;
                        call_out("delayed_get", delay, ob, TP, ETP);
                        return 1;
                    }
                    if (objectp(pilfered_for)) {
                        actually_get(TP, pilfered_for);
                        clear_pilfer();
                        return 1;
                    }
                }
            }
            clear_pilfer();
            actually_get(TP, ob);
            return 1;
        }
        inv = all_inventory(TO);
        if (!sizeof(inv)) {
            write("There is nothing in " + TO->query_short() + ".");
            return 1;
        }
        if (TO->is_chest()) {
            if (sizeof(TP->query_attackers())) {
                tell_object(TP, "You toss your " + TO->query_short() + " upside down " +
                            "on the ground, spilling all of its contents!");
                tell_room(ETP, TPQCN + " tosses " + TP->QP + " " + TO->query_short() + " upside " +
                          "down on the ground, spilling all of its contents!", TP);
                all_inventory(TO)->move(ETP);
                TO->move(ETP);
                clear_pilfer();
                return 1;
            }
        }
        for (i = 0; i < sizeof(inv); i++) {
            actually_get(TP, inv[i]);
            continue;
        }
        return 1;
    }
    write(query_short() + " is closed.");
    return 1;
}

void set_closed_long(string str)
{
    closed_long_desc = str;
}

void set_open_long(string str)
{
    open_long_desc = str;
}

string query_open_long_desc()
{
    return open_long_desc;
}

string query_closed_long_desc()
{
    return closed_long_desc;
}

string query_cont_long()
{
    return container::query_long("");
}

string query_long(string str)
{
    object* inv;
    int i;
    string desc;

    if (query_possible_to_close()) {
        if (query_closed()) {
            desc = query_closed_long_desc();
        } else {
            desc = query_open_long_desc();
        }
    }
    if (!stringp(desc)) {
        desc = container::query_long(str);
    }
    if (TO->is_sortable_container()) {
        return desc;
    }

    if ((int)TO->receive_objects() || (int)TO->clear()) {
        inv = all_inventory(TO);
        if (sizeof(inv) > 0) {
            if (stringp(desc)) {
                desc += "  It contains:\n";
            }else {
                desc = "  It contains:\n";
            }
            for (i = 0; i < sizeof(inv); i++) {
                if (inv[i]->is_disease()) {
                    continue;
                }
                desc += "  " + (string)inv[i]->query_short() + "\n";
            }
        }
    }
    return desc;
}

void riddle_header()
{
    write("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" +
          "=-=-=-=-");
}

mixed do_riddle_open(object ch)
{
    int which_riddle;
    string current_riddle, riddle_answer;
    if (!objectp(ch)) {
        write("That is not here!");
        return 1;
    }
    if (!sizeof(open_riddles) || !sizeof(open_riddle_answers)) {
        write("Something is wrong with this chest... the riddle " +
              "is messed up.  Please contact a wiz.");
        return 1;
    }
    which_riddle = random(sizeof(open_riddles));
    current_riddle = open_riddles[which_riddle];
    riddle_answer = open_riddle_answers[which_riddle];
    riddle_header();
    write(current_riddle);
    input_to("answer_open_riddle", 0, current_riddle, riddle_answer, ch);
    riddle_header();
    write("Please type your answer or type ~q to quit.");
    riddle_header();
}

void answer_open_riddle(string input, string riddle, string answer, object ch)
{
    if (input == "~q") {
        riddle_header();
        write("Exiting riddle.");
        riddle_header();
        return;
    }
    if (!input || input != answer && input != 0) {
        riddle_header();
        write("Wrong!  Please try again.\n");
        write(riddle);
        riddle_header();
        input_to("answer_open_riddle", 0, riddle, answer, ch);
        riddle_header();
        write("Please type your answer or type ~q to quit.");
        riddle_header();
        return;
    }
    if (input == answer) {
        riddle_header();
        write("That is correct!");
        riddle_header();
        riddle_solvers += ({ environment(ch)->query_name() });
        if ((string)ch->query_open_long_desc()) {
            ch->set_long((string)ch->query_open_long_desc());
            ch->toggle_closed();
            write("You open " + ch->query_short() + ".");
            tell_room(ETP, TPQCN + " opens " +
                      ch->query_short() + ".", TP);
            return;
        }
        return;
    }
}

int open_container(string str)
{
    object ch;
    if (!stringp(str)) {
        tell_object(TP, "Open what?");
        return 1;
    }
    ch = present(str, TP);
    if (!ch) {
        ch = present(str, ETP);
    }
    if (!ch) {
        return 0;
    }
    if (!ch->is_bag()) {
        return 0;
    }

    if (TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    if (ch->query_lock_data()) {
        if ((string)ch->query_lock_data("status") == "locked") {
            write("It is locked.\n");
            return 1;
        }
    }
    if (sizeof(open_riddles) && (!solve_once || member_array(environment(ch)->query_name(), riddle_solvers) == -1)) {
        do_riddle_open(ch);
        return 1;
    }
    if (ch->receive_objects()) {
        write("It is already open.");
    }else {
        if (ch->is_trapped("open")) {
            if (ch->execute_trap("open", TP)) {
                return 1;
            }
        }
        if (ch->trapped("open")) {
            if (ch->do_spec_trap("open")) {
                return 1;
            }
        }
        if (sizeof(open_riddles) && (!solve_once || member_array(environment(ch)->query_name(), riddle_solvers) == -1)) {
            do_riddle_open(ch);
            return 1;
        }

        if ((string)ch->query_open_long_desc()) {
            ch->set_long((string)ch->query_open_long_desc());
        }
        ch->toggle_closed();
        POISON_D->is_object_poisoned(ch, TP, "open", 1);
        write("You open " + ch->query_short() + ".");
        tell_room(ETP, TPQCN + " opens " +
                  ch->query_short() + ".", TP);
    }
    return 1;
}

int close_container(string str)
{
    object ch;

    if (!stringp(str)) {
        tell_object(TP, "Close what?");
        return 1;
    }

    ch = present(str, TP);

    if (!ch) {
        ch = present(str, ETP);
    }
    if (!ch) {
        return 0;
    }
    if (!ch->is_bag()) {
        return 0;
    }

    if (TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }

    if (!ch->receive_objects()) {
        write("It is already closed.");
    }else
        if (!ch->toggle_closed()) {
            write("It cannot be closed.");
        }else {
            if (ch->is_trapped("close")) {
                if (ch->execute_trap("close", TP)) {
                    return 1;
                }
            }
            if (ch->trapped("close")) {
                if (ch->do_spec_trap("close")) {
                    return 1;
                }
            }
            if (ch->query_closed_long_desc()) {
                ch->set_long((string)ch->query_closed_long_desc());
            }
            write("You close " + ch->query_short() + ".");
            POISON_D->is_object_poisoned(ch, TP, "close", 1);
            tell_room(ETP, TPQCN + " closes " +
                      ch->query_short() + ".", TP);
        }
    return 1;
}

int lock_container(string str)
{
    object ch;
    if (!str) {
        notify_fail("Lock what?\n");
        return 0;
    }
    if (TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    ch = present(str, TP);

    if (!ch) {
        ch = present(str, ETP);
    }
    if (!ch) {
        notify_fail("No '" + str + "' here or bad syntax.\n");
        return 0;
    }
    if (!ch->is_bag()) {
        return 0;
    }

    if (!ch->query_lock_data()) {
        write("That " + str + " does not seem to have a lock.\n");
        return 1;
    }
    if (ch->receive_objects()) {
        write("It must be closed before you can lock it.\n");
        return 1;
    }
    if ((string)ch->query_lock_data("status") == "locked") {
        write("It is already locked!\n");
        return 1;
    }
    if ((string)ch->query_lock_data("key")
        && present((string)ch->query_lock_data("key"), TP)) {
        write("You lock the " + str + ".\n");
        tell_room(ETP, TPQCN + " locks the " + str + ".\n", TP);
        ch->toggle_lock();
        return 1;
    } else if (!ch->query_lock_data("key")) {
        write("You lock the " + str + ".\n");
        tell_room(ETP, TPQCN + " locks the " + str + ".\n", TP);
        ch->toggle_lock();
        return 1;
    } else {
        write("Lock the " + str + " with what?\n");
        return 1;
    }
}

int unlock_container(string str)
{
    object ch;
    if (!str) {
        notify_fail("Unlock what?\n");
        return 0;
    }
    if (TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    ch = present(str, TP);
    if (!ch) {
        ch = present(str, ETP);
    }
    if (!ch) {
        notify_fail("No '" + str + "' found.  If you are trying to unlock a door,\n "
                    "try <unlock [door id] with [key id]>.  If there are multiple "
                    "locks,\n try <unlock [lock id] on [door id] with [key id]>.\n");
        return 0;
    }
    if (!ch->is_bag()) {
        return 0;
    }
    if (!ch->query_lock_data()) {
        notify_fail("That " + str + " does not seem to have a lock.\n");
        return 0;
    }
    if ((string)ch->query_lock_data("status") != "locked") {
        notify_fail("The " + str + " is not locked.\n");
        return 0;
    }
    if (!ch->query_lock_data("key")) {
        write("You unlock the " + str + ".\n");
        tell_room(ETP, TPQCN + " unlocks the " + str + ".\n", TP);
        ch->toggle_lock();
        return 1;
    }
    if (!present((string)ch->query_lock_data("key"), TP)) {
        notify_fail("Unlock the " + str + " with what?\n");
        return 0;
    }
    if (ch->is_trapped("unlock")) {
        if (ch->execute_trap("unlock", TP)) {
            return 1;
        }
    }
    if (ch->trapped("unlock")) {
        if (ch->do_spec_trap("unlock")) {
            return 1;
        }
    }

    write("You unlock the " + str + ".\n");
    tell_room(ETP, TPQCN + " unlocks the " + str + ".\n", TP);
    ch->toggle_lock();
    return 1;
}

void toggle_lock()
{
    if (!lock_data) {
        return;
    }
    if (lock_data["status"] == "locked") {
        lock_data["status"] = "unlocked";
    }else {
        lock_data["status"] = "locked";
    }
}

int query_locked()
{
    if (!lock_data) {
        return 0;
    }
    if (lock_data["status"] == "locked") {
        return 1;
    }else {
        return 0;
    }
}

void set_lock(string stat)
{
    if (stat != "locked" && stat != "unlocked") {
        if (!lock_data) {
            lock_data = ([ "status" : "locked" ]);
        }else {
            lock_data["status"] = "locked";
        }
        return;
    }
    if (!lock_data) {
        lock_data = ([ "status" : stat ]);
    }else {
        lock_data["status"] = stat;
    }
}

void set_key(string str)
{
    if (!lock_data) {
        lock_data = ([]);
    }
    lock_data["key"] = str;
}

int is_bag()
{
    return 1;
}

void lock_difficulty(int mod)
{
    lock_dif = mod;
}

int query_mod(string str)
{
    return lock_dif;
}

int PickLock(string str)
{
    object ob;
    object ob2;
    object ch;
    int level;
    int mydiff, modifier, score, percent;
    if (!str) {
        notify_fail("Pick what?\n");
        return 0;
    }
    if (TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    ch = present(str, TP);
    if (!ch) {
        ch = present(str, ETP);
    }
    if (!ch) {
        return 0;
    }

    if (!ch->query_lock_data()) {
        notify_fail("It does not have a lock.\n");
        return 0;
    }
    if ((string)ch->query_lock_data("status") != "locked") {
        notify_fail("It is not locked.\n");
        return 0;
    }
    if (!ch->query_lock_data("key")) {
        write("You unlock the " + str + ".\n");
        tell_room(ETP, TPQCN + " unlocks the " + str + ".\n", TP);
        ch->toggle_lock();
        return 1;
    }

    if (!(ob = present("thief toolx", TP))) {
        if (present("broken tool", TP)) {
            write("You can't use those broken tools.\n");
        }
        notify_fail("You do not have the tools!\n");
        return 0;
    }
    modifier = ch->query_mod();
    score = TP->query_skill("dungeoneering") + modifier + roll_dice(1, 20);
    if (ch->is_trapped("pick")) {
        if (ch->execute_trap("pick", TP)) {
            return 1;
        }
    }
    if (ch->trapped("pick")) {
        if (ch->do_spec_trap("pick")) {
            return 1;
        }
    }

    mydiff = 20;
    if (score >= mydiff) {
        write("You unlock the " + str + ".\n");
        tell_room(ETP, TPQCN + " unlocks the " + str + ".\n", TP);
        ch->toggle_lock();
        return 1;
    } else {
        write("The lock doesn't seem to budge.\n");
        write("You worry about your tools.\n");
        tell_room(environment(TP), "You see " + TPQCN + " struggle to pick
" + str + ".", TP);
        if ((percent - score) > 30) {
            level = TP->query_level();
            percent = random(99);
            if (percent > (70 + level * 2)) {
                ob2 = present("tools", TP);
                ob2->break_picks();
                return 1;
            }
        }
        return 1;
    }
}

int save_me(string file)
{
    object* inv;
    string path, who, fn, fname, * stuff;
    int x, y, i, j, num;

    stuff = explode(file, "/");
    fn = stuff[sizeof(stuff) - 1];
    path = "/";
    for (i = 0; i < sizeof(stuff) - 1; i++) {
        path += stuff[i];
        path += "/";
    }
    seteuid(UID_ROOT);
    inv = all_inventory(TO);
    y = sizeof(inv);
    if (y) {
        for (x = 0; x < y; x++) {
            fname = path + "save" + x + fn;
            j = inv[x]->save_me(fname);
        }
    }
    ::save_me(file);
    seteuid(getuid());
}

void db(string str)
{
    if (objectp(find_player("ares"))) {
        tell_object(find_player("ares"), str);
    }
}

int restore_me(string file)
{
    string* files, fname, fn, who, item, path, * stuff;
    int fsize, pweight;
    int x, i, j, holder, num, cstate, lstate;
    mixed tmp;

    holder = ::restore_me(file);


    seteuid(UID_ROOT);
    sscanf(file, "/inv/%s/%s", who, path);

    if (stringp(path)) {
        sscanf(path, "ob%d", num);
    }

    fsize = sizeof(files = get_dir("/inv/" + first_letter(who) + "/" + who + "/" + num + "save*"));
    cstate = (int)TO->query_closed();
    lstate = (int)TO->query_locked();
    if (cstate == 1) {
        TO->set_closed(0);
    }
    if (lstate == 1) {
        TO->set_locked(0);
    }
    for (x = 0; x < (fsize); x++) {
        fname = "/inv/" + first_letter(who) + "/" + who + "/" + files[x];
        tmp = "/daemon/yuck_d"->restore_files(fname);
        if (stringp(tmp)) {
            write(tmp);
            rm(fname);
        }else {
            pweight = tmp->query_weight();
            tmp->set_weight(0);
            if (tmp->move(TO) != MOVE_OK) {
                tmp->move(EETO);
                write("You dropped " + tmp->query_short() + " from a container!");
            }
            tmp->set_weight(pweight);
            rm(fname);
        }
    }
    stuff = explode(file, "/");
    fn = stuff[sizeof(stuff) - 1];
    path = "/";
    for (i = 0; i < sizeof(stuff) - 1; i++) {
        path += stuff[i];
        path += "/";
    }

    i = 0;

    fsize = sizeof(files = get_dir(path + "save*" + fn + ".*"));
    for (x = 0; x < (fsize); x++) {
        fname = path + files[x];

        tmp = "/daemon/yuck_d"->restore_files(fname);

        if (!read_file(fname)) {
            db("fname: " + fname + " is empty");
        }

        if (stringp(tmp) || !tmp) {
            if (tmp) {
                write(tmp);
            }
            rm(fname);
        }else {
            pweight = tmp->query_weight();
            tmp->set_weight(0);
            if (tmp->move(TO) != MOVE_OK) {
                tmp->move(EETO);
                write("You dropped " + tmp->query_short() + " from a container!");
            }
            tmp->set_weight(pweight);
            rm(fname);
        }
    }
    TO->set_locked(lstate);
    TO->set_closed(cstate);
    seteuid(getuid());
}

void remove()
{
    object* inven;
    int i, j;
    inven = all_inventory(TO);

    if (!TO->is_corpse()) {
        j = sizeof(inven);
        if (j) {
            for (i = 0; i < j; i++) {
                inven[i]->remove();
            }
        }
    }
    return ::remove();
}

int is_baggy()
{
    return 1;
}
