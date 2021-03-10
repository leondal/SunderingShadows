// Fixed many bugs by removing code. 2019-03-29 Ilmarinen
// Most of the suff satchel tried to implement has been moved in other
// pars of the lib.

#include <std.h>
#include <move.h>
inherit "/std/bag_logic";

void set_long(string str);
string order;

void create()
{
    set_name("smart satchel");
    set_id(({ "satchel", "smart satchel", "scroll satchel" }));

    set_short("%^ORANGE%^A smart satchel%^RESET%^");
    set_weight(6);
    set_long((: TO, "long_desc" :));
    set_lore("You have heard something about satchels and other"
             + " containers of this sort prepared by the wiliest of arch"
             + "-magi to aid them in quckly accessing their usable scrolls."
             + " There's no way of knowing who made this one, but it does"
             + " all look very well organised");
    set_property("lore difficulty", 25);
    set_value(1000);
    set_cointype("gold");
    set_max_internal_encumbrance(50);
    set_open_long("" + TO->query_long() + "%^CYAN%^The satchel is open."
                  + "\n%^RESET%^");
    set_closed_long("" + TO->query_long() + "%^CYAN%^The satchel is closed"
                    + " and buckled.\n%^RESET%^");
    set_possible_to_close(1);
}

void init()
{
    ::init();
    add_action("index_cast", "index");
    add_action("check_index", "check");
    add_action("read_satchel", "read");
    add_action("order_scrolls", "order");
}

string long_desc()
{
    return "%^ORANGE%^This smart looking satchel has been carefully"
        + " prepared with a number of %^CYAN%^d%^RED%^i%^GREEN%^v"
        + "%^MAGENTA%^i%^BLUE%^d%^YELLOW%^e%^RESET%^%^ORANGE%^r"
        + "%^BOLD%^%^MAGENTA%^s %^RESET%^%^ORANGE%^inside, and a"
        + " clever %^RESET%^index %^ORANGE%^system of raised marks on"
        + " the tab of each divider, to allow the owner to quickly"
        + " seek out and withdraw a particular item from the bag."
        + " Instructions for using the index have been sewn into the"
        + " material on the inside of the satchel.%^RESET%^\n";
}

string query_long(string str)
{
    string desc, extra, tmp, * true_inv;
    object* inv;
    mapping myInv;
    int j, i;

    extra = "%^CYAN%^" + (query_closed() ? "The satchel is closed and buckled." : "The satchel is open.") + "\n%^RESET%^";
    desc = long_desc() + extra;
    inv = all_inventory(TO);
    if (!sizeof(inv) || query_closed()) {
        return desc;
    }
    myInv = ([]);
    for (i = 0; i < sizeof(inv); i++) {
        if (inv[i]->is_disease()) {
            continue;
        }
        tmp = inv[i]->query_short();
        if (member_array(tmp, keys(myInv)) != -1) {
            myInv[tmp]["quantity"]++;
        }else {
            myInv += ([tmp:(["quantity" : 1, "short" : tmp]), ]);
        }
        continue;
    }

    if (!sizeof(keys(myInv))) {
        return desc;
    }
    if (stringp(desc)) {
        desc += arrange_string("It contains:", 50) + "Amount\n";
    }else {
        desc = "  It contains: \n";
    }
    true_inv = sort_array(keys(myInv), (: strcmp("/daemon/filters_d.c"->filter_colors($1),"/daemon/filters_d.c"->filter_colors($2)) :));
    for (i = 0; i < sizeof(true_inv); i++) {
        j = 55 - strlen("/daemon/filters_d.c"->filter_colors(myInv[true_inv[i]]["short"]));
        desc += myInv[true_inv[i]]["short"] + arrange_string(" ", j) + myInv[true_inv[i]]["quantity"] + "\n";
    }

    return desc;
}

int order_scrolls(string str)
{
    if (str == "scrolls by level") {
        tell_object(TP, "You quickly sort the scrolls into sections according to their level");
        tell_room(ETP, TPQCN + " quckly shuffles the contents of " + TP->QP + " satchel", TP);
        order_contents_alphabetically();
        order_contents_by_spell_level();
        return 1;
    }
    if (str == "scrolls alphabetically") {
        tell_object(TP, "You quickly sort the scrolls into alpabetical order");
        tell_room(ETP, TPQCN + " quckly shuffles the contents of " + TP->QP + " satchel", TP);
        order_contents_alphabetically();
        return 1;
    }
    return notify_fail("Do you want to 'order scrolls by level' or 'order scrolls alphabetically'?");
}

int item_allowed(object item)
{
    string *ids = ({}), stuff = ({ "scroll","paper","parchment" });
    int i;

    ids = item->query_id();
    for(i=0;i<sizeof(ids);i++)
    {
        if(member_array(ids[i],stuff) != -1) { return 1; }
    }

    write("You can only put scrolls, paper, and parchment in this.");
    return 0;
}

// This part coded by Lujke

int read_satchel(string str){
  if (!objectp(TO)||!objectp(ETO)){return 0;}
  if (str!="satchel"){return 0;}
  tell_object(TP,"To use the index, feel rapidly for the mark"
                +" corresponding to the scroll you wish to use."
                +"\n%^BOLD%^%^YELLOW%^<index 'spell name' on 'target"
                +" name'>%^RESET%^\n"
                +"To sort your scrolls conveniently:\n"
                +"%^BOLD%^%^YELLOW%^<order scrolls by level>\n"
                +"%^BOLD%^%^YELLOW%^<order scrolls alphabetically>\n");
  return 1;
}

int index_cast(string str)
{
    string spellname, word, targetname, scrollspell;
    object* ob;
    int i;
    if (!objectp(TO) || !objectp(ETO) || !objectp(TP)) {
        return 0;
    }
    if (!str || strlen(str) < 3) {
        tell_object(ETO, "Try 'index <spell name>' or index <spell name> on <target name>'");
        return 1;
    }
    word = str[0..0];
    for (i = 1; i < strlen(str); i++) {
        if (str[i..i] != " ") {
            word = word + str[i..i];
        }else {
            if (word == "on") {
                if (spellname && strlen(spellname) > 1) {
                }
                break;
            }
            if (!spellname) {
                spellname = word;
            }else {
                spellname = spellname + " " + word;
            }
            word = "";
        }
    }
    if (!spellname) { // this section catches the case where the spell
                      // name is only one word
        spellname = str;
    }else {
        if (i < strlen(str) - 2) {
            targetname = str[i + 1..strlen(str)];
        }else {         // This section catches spells with more than one
            spellname = str; // word in the name, but which don't have a target
        }
    }
    //  Add 1 to the end of the spellname, so the mudcode doesn't get fooled
    // into thinking it is looking for the first instance of
    // 'monster summoning' rather than looking for 'monster summoning i'
    spellname += " 1";
    if (!present(spellname, TO)) {
        tell_object(ETO, "There is no scroll with the spell " + spellname
                    + " in the satchel. Or at least, if there is your"
                    + " indexing has gone horribly wrong!\n");
        tell_room(EETO, ETO->QCN + " searches for a scroll in "
                  + ETO->QP + " satchel, but doesn't seem to"
                  + " find what " + ETO->QS + " is looking"
                  + " for.", ETO);
        return 1;
    }
    tell_object(ETO, "Your fingers move deftly along the index to the"
                + " scroll you were looking for and you draw it from"
                + " the satchel with a flourish!");
    tell_room(EETO, TPQCN + " draws a scroll deftly from "
              + TP->query_possessive(), ETO);
    TP->force_me("get " + spellname + " from satchel");
    if (targetname && strlen(targetname) > 1) {
        TP->force_me("use " + spellname + " on " + targetname);
    }else {
        TP->force_me("use scroll");
    }
    return 1;
}

void report(string str){
//  "/daemon/reporter_d"->report("lujke", str);
}

void order_contents_alphabetically( )
{
    object item, next_item, * result, * contents;
    int i, j, count;
    string spellname, next_spellname;
    result = ({});
    contents = all_inventory(TO);
    count = sizeof(contents);
    if (count < 1) {
        return;
    }
    next_item = 0;
    j = 0;
    report("About to order " + count + " items");
    while (sizeof(contents) > 0 && j < 50) {
        j++;
        contents = all_inventory(TO);
        count = sizeof(contents);
        next_item = 0;
        report("Cycle " + j + " New size of contents: " + count);
        for (i = count - 1; i >= 0; i--) {
            if (sizeof(result) > 0 && member_array(contents[i], result) != -1) {
                continue;
            }
            if (!objectp(next_item)) {
                report("%^BOLD%^%^CYAN%^Next item was not a valid object");
                next_item = contents[i];
                next_spellname = next_item->query_spell_name();
            } else {
                report("%^BOLD%^%^RED%^Next item was a valid object");
            }
            if (contents[i]->query_spell_name() > next_spellname) {
                report("" + contents[i]->query_spell_name() + " > " + next_spellname);
                next_item = contents[i];
                next_spellname = next_item->query_spell_name();
            } else {
                report("" + contents[i]->query_spell_name() + " <= " + next_spellname);
            }
        }
        report("Next spell: " + next_spellname);
        result += ({ next_item });
        report("%^BOLD%^%^MAGENTA%^New size of result: " + sizeof(result));
//    contents -= ({next_item});
        if (objectp(next_item)) {
            next_item->move(ETO);
        }
    }
    for (i = 0; i < sizeof(result); i++) {
        item = result[i];
        item->move(TO);
    }
}

void order_contents_by_spell_level()
{
    object item, next_item, * result, * contents;
    int i, j, count, spell_level, next_spell_level;
    result = ({});
    contents = all_inventory(TO);
    count = sizeof(contents);
    if (count < 1) {
        return;
    }
    next_item = 0;
    j = 0;
    report("About to order " + count + " items");
    while (sizeof(contents) > 0 && j < 50) {
        j++;
        contents = all_inventory(TO);
        count = sizeof(contents);
        next_item = 0;
        report("Cycle " + j + " New size of contents: " + count);
        for (i = count - 1; i >= 0; i--) {
            if (sizeof(result) > 0 && member_array(contents[i], result) != -1) {
                continue;
            }
            if (!objectp(next_item)) {
                report("%^BOLD%^%^CYAN%^Next item was not a valid object");
                next_item = contents[i];
                next_spell_level = next_item->query_spell_level();
            } else {
                report("%^BOLD%^%^RED%^Next item was a valid object");
            }
            if (contents[i]->query_spell_level() > next_spell_level) {
                report("" + contents[i]->query_spell_level() + " > " + next_spell_level);
                next_item = contents[i];
                next_spell_level = next_item->query_spell_level();
            } else {
                report("" + contents[i]->query_spell_level() + " <= " + next_spell_level);
            }
        }
        report("Next spell: " + next_spell_level);
        result += ({ next_item });
        report("%^BOLD%^%^MAGENTA%^New size of result: " + sizeof(result));
//    contents -= ({next_item});
        if (objectp(next_item)) {
            next_item->move(ETO);
        }
    }
    for (i = 0; i < sizeof(result); i++) {
        item = result[i];
        item->move(TO);
    }
}
