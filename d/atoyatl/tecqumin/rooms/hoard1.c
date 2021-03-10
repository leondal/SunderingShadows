#include <std.h>
#include <move.h>
#include <daemons.h>
#include "../tecqumin.h"

inherit ROOM;

mapping takers;
int when_opened, reset_count;
object* torcs, * kilts, * ponchos, knife, sword, head, amulet, headdress, seal, club, shield;

string long_desc();
void set_treasures();

void init()
{
    ::init();
    add_action("take_treasure", "claim");
    add_action("view_treasure", "view");
}

void open()
{
    when_opened = time();
    reset_count = 0;
}

void report(string str)
{
    //"/daemon/reporter_d.c"->report("lujke", base_name(TO) + " reports: " + str);
}

void set_teasures()
{
    object ob, room;
    int i;
    room = find_object_or_load(TECSTORE);
    if (!objectp(room)) {
        report("error with the Tec store");
        tell_room(TO, "Error with the store room. Please make a bug report");
        return;
    } else {
        report("storage room is working perfectly, sir");
    }
    torcs = ({});

    for (i = 1; i < 4; i++) {
        ob = present("torc " + i, room);
        if (objectp(ob)) {
            ob->move("/d/shadowgate/void");
        }
        ob = new(OBJ + "torc_greater");
        ob->move(room);
        torcs += ({ ob });
    }
    torcs = ({ torcs[2], torcs[1], torcs[0] });
    kilts = ({});
    for (i = 1; i < 4; i++) {
        ob = present("kilt " + i, room);
        if (objectp(ob)) {
            ob->move("/d/shadowgate/void");
        }
        ob = new(OBJ + "kilt_greater");
        ob->move(room);
        kilts += ({ ob });
    }
    kilts = ({ kilts[2], kilts[1], kilts[0] });
    ponchos = ({});
    for (i = 1; i < 4; i++) {
        ob = present("poncho " + i, room);
        if (objectp(ob)) {
            ob->move("/d/shadowgate/void");
        }
        ob = new(OBJ + "poncho_greater");
        ob->move(room);
        ponchos += ({ ob });
    }
    ponchos = ({ ponchos[2], ponchos[1], ponchos[0] });
    knife = present("knife", room);
    if (objectp(knife)) {
        knife->move("/d/shadowgate/void");
    }
    knife = new(OBJ + "ether_knife_greater");
    if (objectp(knife)) {
        knife->move(room);
    } else {
        tell_room(TO, "Error with one of the treasures. Please make a bug report");
    }
    sword = present("sword", room);
    if (objectp(sword)) {
        sword->move("/d/shadowgate/void");
    }
    sword = new(OBJ + "ether_sword_greater");
    if (objectp(sword)) {
        sword->move(room);
    } else {
        tell_room(TO, "Error with one of the treasures. Please make a bug report");
    }
    head = present("head", room);
    if (objectp(head)) {
        head->move("/d/shadowgate/void");
    }
    head = new(OBJ + "seeing_head");
    if (objectp(head)) {
        head->move(room);
    } else {
        tell_room(TO, "Error with one of the treasures. Please make a bug report");
    }
    amulet = present("amulet", room);
    if (objectp(amulet)) {
        amulet->move("/d/shadowgate/void");
    }
    amulet = new(OBJ + "amulet_of_seeking");
    if (objectp(amulet)) {
        amulet->move(room);
    } else {
        tell_room(TO, "Error with one of the treasures. Please make a bug report");
    }
    headdress = present("headdress", room);
    if (objectp(headdress)) {
        headdress->move("/d/shadowgate/void");
    }
    headdress = new(OBJ + "plumed_headdress");
    if (objectp(headdress)) {
        headdress->move(room);
    } else {
        tell_room(TO, "Error with one of the treasures. Please make a bug report");
    }
    seal = present("seal", room);
    if (objectp(seal)) {
        seal->move("/d/shadowgate/void");
    }
    seal = new(OBJ + "seal");
    if (objectp(seal)) {
        seal->move(room);
    } else {
        tell_room(TO, "Error with one of the treasures. Please make a bug report");
    }
    club = present("club", room);
    if (objectp(club)) {
        club->move("/d/shadowgate/void");
    }
    club = new(OBJ + "macquahuitl");
    if (objectp(club)) {
        club->move(room);
    } else {
        tell_room(TO, "Error with one of the treasures. Please make a bug report");
    }
    shield = new(OBJ + "stone_shield");
    if (objectp(shield)) {
        shield->move(room);
    } else {
        tell_room(TO, "Error with one of the treasures. Please make a bug report");
    }
}

void create()
{
    ::create();
    set_indoors(0);
    set_property("light", 2);
    set_terrain(NAT_TUNNEL);
    set_travel(SLICK_FLOOR);
    set_name("A rock walled cavern");
    set_short("A hidden store of treasures");
    set_long((: TO, "long_desc" :));
    set_items(([ ({ "treasure", "treasures", "the treasures", "at the treasures", "hoard" }) : (: TO, "treasure_desc" :)]));
    set_smell("default", "There's nothing to smell here but dust");
    set_listen("default", "This place is quiet as a tomb");
    set_exits((["west" : ROOMS + "processional"]));
    reset_count = 0;
    when_opened = 0;
    takers = ([]);
    set_teasures();
}

int torc_count()
{
    int i, num;
    object room;
    room = find_object_or_load(TECSTORE);
    if (!objectp(room)) {
        return -1;
    }
    num = 0;
    for (i = 0; i < sizeof(torcs); i++) {
        if (present(torcs[i], room)) {
            num++;
        }
    }
    return num;
}

int kilt_count()
{
    int i, num;
    object room;
    room = find_object_or_load(TECSTORE);
    if (!objectp(room)) {
        return -1;
    }
    num = 0;
    for (i = 0; i < sizeof(kilts); i++) {
        if (present(kilts[i], room)) {
            num++;
        }
    }
    return num;
}

int poncho_count()
{
    int i, num;
    object room;
    room = find_object_or_load(TECSTORE);
    if (!objectp(room)) {
        return -1;
    }
    num = 0;
    for (i = 0; i < sizeof(ponchos); i++) {
        if (present(ponchos[i], room)) {
            num++;
        }
    }
    return num;
}

string long_desc()
{
    object room;
    string result;
    room = find_object_or_load(TECSTORE);
    result = "This dusty stone walled room deep inside the %^CYAN%^Tecqumin%^RESET%^ pyramid is lit by an eerie "
             "%^BOLD%^%^CYAN%^sp%^WHITE%^i%^CYAN%^r%^WHITE%^i%^CYAN%^t "
             "%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^ght %^RESET%^with no obvious point of origin. Wispy "
             "%^CYAN%^sp%^RESET%^i%^CYAN%^r%^RESET%^i%^CYAN%^ts%^RESET%^ of %^CYAN%^Tecqumin %^RESET%^ancestors drift lazily through "
             "the air, on guard above piles of %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^%^YELLOW%^ld %^RESET%^and "
             "%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^WHITE%^lv%^RESET%^e%^BOLD%^%^WHITE%^r "
             "%^YELLOW%^t%^WHITE%^r%^RESET%^%^ORANGE%^ea%^BOLD%^%^YELLOW%^s%^WHITE%^u%^RESET%^r%^BOLD%^%^YELLOW%^e%^RESET%^. "
             "An elaborately decorated mummy rests in one corner";
    if (objectp(room) && present(headdress, room)) {
        result += ", a " + headdress->query_obvious_short() + " %^RESET%^resting on its head.";
    } else {
        result += ".";
    }
    if (objectp(room) && present(amulet, room)) {
        result += " A " + amulet->query_obvious_short() + "%^RESET%^ is draped around its neck.";
    }
    if (objectp(room) && present(club, room)) {
        result += " An impressive %^ORANGE%^macquahuitl%^RESET%^, a Tecqumin war club, leans against one wall.";
    }
    if (objectp(room) && present(shield, room)) {
        result += " A great stone shield lies on the floor.";
    }
    switch (kilt_count()) {
    case 1:
        result += " A fine quality kilt is displayed on a clothing rack.";
        break;

    case 2:
    case 3:
        result += " Some fine quality kilts are displayed on a clothing rack.";
    }
    switch (torc_count()) {
    case 1:
        result += " A prestigious looking torc rests atop a pile of %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^"
                  + "%^YELLOW%^ld%^WHITE%^e%^YELLOW%^n tr%^RESET%^%^ORANGE%^ea%^BOLD%^%^YELLOW%^"
                  + "s%^RESET%^%^ORANGE%^u%^BOLD%^%^YELLOW%^re.";
        break;

    case 2:
    case 3:
        result += " Some prestigious looking torcs rest atop piles of %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^"
                  + "%^YELLOW%^ld%^WHITE%^e%^YELLOW%^n tr%^RESET%^%^ORANGE%^ea%^BOLD%^%^YELLOW%^"
                  + "s%^RESET%^%^ORANGE%^u%^BOLD%^%^YELLOW%^re.";
    }
    result += " %^RESET%^You can look at the treasures for a full list of what is here.";
    return result;
}

string treasure_desc()
{
    int i, count, num;
    string desc, * locations, item_id;
    object* treasures, room;
    room = find_object_or_load(TECSTORE);
    if (!objectp(room)) {
        report("error with the Tec store");
        tell_room(TO, "Error with the store room. Please make a bug report");
        return;
    }
    treasures = ({ headdress }) + torcs + ({ knife, sword }) + kilts + ({ amulet, seal }) + ponchos + ({ head, club, shield });
    locations = ({ "on the head of a %^BOLD%^%^BLUE%^royal %^RESET%^%^ORANGE%^mummy%^RESET%^",
                   "on a pile of %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^"
                   + "%^YELLOW%^ld%^WHITE%^e%^YELLOW%^n tr%^RESET%^%^ORANGE%^"
                   + "ea%^BOLD%^%^YELLOW%^s%^RESET%^%^ORANGE%^u"
                   + "%^BOLD%^%^YELLOW%^re",
                   "on a pile of %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^"
                   + "%^YELLOW%^ld%^WHITE%^e%^YELLOW%^n tr%^RESET%^%^ORANGE%^"
                   + "ea%^BOLD%^%^YELLOW%^s%^RESET%^%^ORANGE%^u"
                   + "%^BOLD%^%^YELLOW%^re",
                   "on a pile of %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^"
                   + "%^YELLOW%^ld%^WHITE%^e%^YELLOW%^n tr%^RESET%^%^ORANGE%^"
                   + "ea%^BOLD%^%^YELLOW%^s%^RESET%^%^ORANGE%^u"
                   + "%^BOLD%^%^YELLOW%^re",
                   "in amongst a pile of %^BOLD%^%^YELLOW%^tr%^RESET%^%^ORANGE%^"
                   + "e%^BOLD%^%^WHITE%^a%^YELLOW%^s%^WHITE%^u%^RESET%^r%^BOLD%^"
                   + "%^YELLOW%^e",
                   "sticking out of a pile of %^BOLD%^%^WHITE%^tr%^RESET%^e"
                   + "%^BOLD%^%^WHITE%^a%^RESET%^s%^BOLD%^%^WHITE%^u%^RESET%^r"
                   + "%^BOLD%^%^WHITE%^e",
                   "on a rack of clothing", "on a rack of clothing", "on a rack of clothing",
                   "round the neck of the royal %^ORANGE%^mummy%^RESET%^",
                   "among a pile of treasures on a high shelf",
                   "on a rack of clothing", "on a rack of clothing", "on a rack of clothing",
                   "a %^ORANGE%^dusty%^RESET%^ shelf all on its own",
                   "leaning against a wall",
                   "resting on the floor" });

    count = sizeof(treasures);
    num = 0;
    for (i = 0; i < count; i++) {
        if (objectp(treasures[i]) && present(treasures[i], room)) {
            num++;
        }
    }
    if (num < 1) {
        tell_object(TP, "All of the unique treasures appear to have been taken, but you could still help yourself to some gold or gems");
        return;
    }
    tell_object(TP, "%^RESET%^%^CYAN%^Among the treasures arrayed, you spot a few that take your eye:");
    for (i = 0; i < count; i++) {
        if (objectp(treasures[i]) && present(treasures[i], room)) {
            item_id = treasures[i]->query_id()[0];
            tell_object(TP, "%^RESET%^%^ORANGE%^" + item_id + " " + treasures[i]->query_id_no(item_id) + "%^RESET%^: " +
                        treasures[i]->query_obvious_short() + " " + locations[i]);
        }
    }
    tell_object(TP, "%^ORANGE%^To view any of the treasures in more detail, you can 'view <item> #'");
    tell_object(TP, "%^CYAN%^To claim one of the treasures, use 'claim <item> # from treasury'");
}

void which_torc(string str)
{
    object torc;
    torc = present(str, find_object_or_load(TECSTORE));
    if (!objectp(torc) || !torc->id("torc")) {
        tell_object(TP, "That is not a torc");
        return;
    }
    tell_room(TO, TPQCN + "%^RESET%^ reaches out and takes "
              + torc->query_obvious_short() + "%^RESET%^ from a pile"
              + " of %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^"
              + "%^YELLOW%^ld%^WHITE%^e%^YELLOW%^n tr%^RESET%^%^ORANGE%^"
              + "ea%^BOLD%^%^YELLOW%^s%^RESET%^%^ORANGE%^u"
              + "%^BOLD%^%^YELLOW%^re", TP);
    tell_object(TP, "You reach out and take "
                + torc->query_obvious_short() + "%^RESET%^ from a pile of"
                + " %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^"
                + "%^YELLOW%^ld%^WHITE%^e%^YELLOW%^n"
                + " tr%^RESET%^%^ORANGE%^ea%^BOLD%^%^YELLOW%^s%^RESET%^"
                + "%^ORANGE%^u%^BOLD%^%^YELLOW%^re");
    torc->move(TO);
}

void which_kilt(string str)
{
    object kilt;
    kilt = present(str, find_object_or_load(TECSTORE));
    if (!objectp(kilt) || !kilt->id("kilt")) {
        tell_object(TP, "That is not a kilt");
        return;
    }
    tell_room(TO, TPQCN + "%^RESET%^ reaches out and takes "
              + kilt->query_obvious_short() + "%^RESET%^ from a rack"
              + " of clothing", TP);
    tell_object(TP, "You reach out and take "
                + kilt->query_obvious_short() + "%^RESET%^ from a rack"
                + " of clothing");
    kilt->move(TO);
}

void which_poncho(string str)
{
    object poncho;
    poncho = present(str, find_object_or_load(TECSTORE));
    if (!objectp(poncho) || !poncho->id("poncho")) {
        tell_object(TP, "That is not a poncho");
        return;
    }
    tell_room(TO, TPQCN + "%^RESET%^ reaches out and takes "
              + poncho->query_obvious_short() + "%^RESET%^ from a rack"
              + " of clothing", TP);
    tell_object(TP, "You reach out and take "
                + poncho->query_obvious_short() + "%^RESET%^ from a rack"
                + " of clothing");
    poncho->move(TO);
}

void view2(object ob, string str)
{
    if (!objectp(ob) || !present(ob, TO)) {
        return;
    }
    tell_object(TP, "%^ORANGE%^To claim it, type %^RESET%^'claim " + str + " from treasury'");
}

int view_treasure(string str)
{
    object ob, room;
    room = find_object_or_load(TECSTORE);
    if (!objectp(room)) {
        tell_object(TP, "There was an error loading the Tecqumin store room. Please make a bug report from here");
        return 1;
    }
    ob = present(str, room);
    if (!objectp(ob)) {
        tell_object(TP, str + " is not among the treasures displayed here. Look at the treasures to see what there is.");
        return 1;
    }
    tell_object(TP, "%^CYAN%^Among the treasures here, you examine " + ob->query_obvious_short());
    tell_object(TP, ob->query_long());
    call_out("view2", 3, TP, str);
    return 1;
}

int take_treasure(string str)
{
    string what, where;
    int num, i;
    object treasure, room;
    num = sscanf(str, "%s from %s", what, where);
    if (!userp(TP)) {
        return;
    }
    if (num < 2 || where != "treasury") {
        tell_object(TP, "Try 'claim <item> from treasury'");
        return 1;
    }
    room = find_object_or_load(TECSTORE);
    if (!objectp(room)) {
        tell_object(TP, "There is an error with the Tecqumin treasure store. Please make a bug report for here");
        return 1;
    }
    if (EVENT_RECORDS_D->completed_event(TP->query_name(), "claimed a second Tecqumin treasure") > 0 && !present("keystone", TP)) {
        tell_object(TP, "It is less than a week since you last claimed a second treasure. The %^CYAN%^Tecqumin
%^BOLD%^sp%^WHITE%^i%^CYAN%^r%^WHITE%^i%^CYAN%^ts%^RESET%^ will not allow you to claim another now.");
        return 1;
    }
    switch (what) {
    case "seal":
    case "seal 1":
        if (!present("seal", room)) {
            tell_object(TP, "Sorry that has already been taken");
            return 1;
        }
        treasure = seal;
        where = "among a pile of treasures on a high shelf";
        break;

    case "amulet":
    case "amulet 1":
        if (!present("amulet", room)) {
            tell_object(TP, "Sorry that has already been taken");
            return 1;
        }
        treasure = amulet;
        where = "round the neck of the royal %^ORANGE%^mummy%^RESET%^";
        break;

    case "torc 1":
    case "torc 2":
    case "torc 3":
        treasure = present(what, room);
        where = "%^RESET%^ a pile of %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^"
                + "%^YELLOW%^ld%^WHITE%^e%^YELLOW%^n tr%^RESET%^%^ORANGE%^ea%^BOLD%^%^YELLOW%^"
                + "s%^RESET%^%^ORANGE%^u%^BOLD%^%^YELLOW%^re";
        break;

    case "torc":
        if (!present("torc", find_object_or_load(TECSTORE))) {
            tell_object(TP, "There are no torcs available");
            return;
        }
        tell_object(TP, "Which torc do you want to take? The options are:");
        i = 1;
        while (present("torc " + i, find_object_or_load(TECSTORE)) && i < 4) {
            tell_object(TP, "Torc " + i + ": " + present("torc " + i, find_object_or_load(TECSTORE))->query_obvious_short());
            i++;
        }
        tell_object(TP, "%^GREEN%^Type anything else to choose something different");
        input_to("which_torc", 0);
        break;
        return 1;

    case "kilt":
        if (!present("kilt", find_object_or_load(TECSTORE))) {
            tell_object(TP, "There are no kilts available");
            return;
        }
        tell_object(TP, "Which kilt do you want to take? The options are:");
        i = 1;
        while (present("kilt " + i, find_object_or_load(TECSTORE)) && i < 4) {
            tell_object(TP, "Kilt " + i + ": " + present("kilt " + i, find_object_or_load(TECSTORE))->query_obvious_short());
            i++;
        }
        tell_object(TP, "%^GREEN%^Type anything else to choose something different");
        input_to("which_kilt", 0);
        break;
        return 1;

    case "kilt 1":
    case "kilt 2":
    case "kilt 3":
        treasure = present(what, room);
        if (!objectp(treasure)) {
            tell_object(TP, "Sorry that has already been taken");
            return 1;
        }

        where = "a clothing rack";
        break;

    case "bangle":
        break;

    case "poncho":
        if (!present("poncho", find_object_or_load(TECSTORE))) {
            tell_object(TP, "There are no poncho available");
            return;
        }
        tell_object(TP, "Which poncho do you want to take? The options are:");
        i = 1;
        while (present("poncho " + i, find_object_or_load(TECSTORE)) && i < 4) {
            tell_object(TP, "Torc " + i + ": " + present("poncho " + i, find_object_or_load(TECSTORE))->query_obvious_short());
            i++;
        }
        tell_object(TP, "%^GREEN%^Type anything else to choose something different");
        input_to("which_poncho", 0);
        break;
        return 1;

    case "poncho 1":
    case "poncho 2":
    case "poncho 3":
        treasure = present(what, room);
        where = "a clothing rack";
        break;

    case "knife":
    case "knife 1":
    case "amber knife":
        treasure = knife;
        where = "a pile of
%^BOLD%^%^YELLOW%^tr%^RESET%^%^ORANGE%^e%^BOLD%^%^WHITE%^a%^YELLOW%^s%^WHITE%^u%^RESET%^r%^BOLD%^%^YELLOW%
^e";
        break;

    case "sword":
    case "sword 1":
    case "amber sword":
        treasure = present(what, room);
        where = "a pile of
%^BOLD%^%^WHITE%^tr%^RESET%^e%^BOLD%^%^WHITE%^a%^RESET%^s%^BOLD%^%^WHITE%^u%^RESET%^r%^BOLD%^%^WHITE%^e";
        break;

    case "club":
    case "club 1":
    case "macquahuitl":
        if (!present("club", room)) {
            tell_object(TP, "Sorry that has already been taken");
            return 1;
        }
        treasure = club;
        where = "where it leans against a wall";
        break;

    case "headdress":
    case "headdress 1":
    case "plumed headdress":
        if (!present("headdress", room)) {
            tell_object(TP, "Sorry that has already been taken");
            return 1;
        }
        treasure = headdress;
        where = "the head of a %^BOLD%^%^BLUE%^royal %^RESET%^%^ORANGE%^mummy%^RESET%^";
        break;

    case "head 1":
    case "head":
    case "shrunken head":
        if (!present("head", room)) {
            tell_object(TP, "Sorry that has already been taken");
            return 1;
        }
        treasure = head;
        where = "a %^ORANGE%^dusty%^RESET%^ shelf all on its own";
        break;

    case "shield 1":
    case "shield":
    case "stone shield":
        if (!present("shield", room)) {
            tell_object(TP, "Sorry that has already been taken");
            return 1;
        }
        treasure = shield;
        where = "the floor";
        break;

    default:
        tell_object(TP, "Sorry there is no " + what + " here for you to claim. You can look at the treasure to see what there is");
        return 1;
    }
    if (!objectp(treasure)) {
        tell_object(TP, "Sorry, there was an error finding the " + what + ". Please make a bug report. You may still be able to claim something else.");
        return 1;
    }
    tell_object(TP, "You take " + treasure->query_short() + "%^RESET%^ from " + where);
    tell_room(TO, TPQCN + " takes " + treasure->query_short() + "%^RESET%^ from " + where, TP);
    treasure->move(TO);
    if (present("keystone", TP)) {
        tell_object(TP, "As you take the treasure, the keystone vanishes from your grasp");
        present("keystone", TP)->remove();
        if (!present("keystone", TP)) {
            tell_object(TP, "The %^BOLD%^%^CYAN%^sp%^WHITE%^i%^CYAN%^r%^RESET%^i%^BOLD%^%^CYAN%^ts%^RESET%^ of the
%^CYAN%^Tecqumin anc%^RESET%^e%^CYAN%^st%^RESET%^o%^CYAN%^rs%^RESET%^ usher you out of the treasury");
            TP->move_player(ROOMS + "processional");
        }
    }
    if (EVENT_RECORDS_D->completed_event(TP->query_name(), "claimed a first Tecqumin treasure") > 0) {
        EVENT_RECORDS_D->record_event(TP->query_name(), "claimed a second Tecqumin treasure", time());
    } else {
        EVENT_RECORDS_D->record_event(TP->query_name(), "claimed a first Tecqumin treasure", time());
    }
    return 1;
}

void eject()
{
    object* critters, room;
    int i, count;
    critters = all_living(TO);
    count = sizeof(critters);
    if (count > 0) {
        for (i = 0; i < count; i++) {
            if (objectp(critters[i])) {
                tell_object(critters[i], "The spirits of the %^CYAN%^Tecqumin"
                            + " ancestors%^RESET%^ move you out of the room, as your time"
                            + " among their %^BOLD%^%^YELLOW%^tr%^RESET%^%^ORANGE%^ea"
                            + "%^BOLD%^%^YELLOW%^s%^WHITE%^u%^YELLOW%^r%^RESET%^%^ORANGE%^"
                            + "e%^BOLD%^s%^RESET%^ has expired");
                critters[i]->move(ROOMS + "processional1");
                critters[i]->force_me("look");
            }
        }
    }
    room = find_object_or_load(ROOMS + "processional1");
    if (objectp(room)) {
        room->remove_exit("east");
    }
    remove_exit("west");
    return;
}

void reset()
{
    object* critters, room;
    int i, count;
    ::reset();
    if (reset_count > 3) {
        eject();
        return;
    }
    if (reset_count > 2) {
        critters = all_living(TO);
        count = sizeof(critters);
        if (count > 0) {
            for (i = 0; i < count; i++) {
                if (objectp(critters[i])) {
                    tell_object(critters[i], "The %^BOLD%^%^CYAN%^sp%^WHITE%^i%^CYAN%^r"
                                + "%^WHITE%^i%^CYAN%^ts %^RESET%^of the %^CYAN%^Tecqumin ancestors"
                                + " %^BOLD%^%^WHITE%^sw%^RESET%^i%^BOLD%^%^WHITE%^rl%^RESET%^"
                                + " around you. Whispered voices, half-heard in the privacy of"
                                + " your own thoughts, urge you to make your choice and%^MAGENTA%^"
                                + " leave %^RESET%^this place %^BOLD%^%^RED%^soon%^RESET%^.");
                }
            }
        }
    }
    reset_count++;
}
