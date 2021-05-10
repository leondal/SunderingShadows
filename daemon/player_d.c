/**
 * @file
 * @brief a daemon to keep track of player progress
 */

//      /adm/daemon/player_d.c
//      from the Nightmare Mudlib
//      a daemon to keep track of player progress
//      created by Descartes of Borg 10 july 1993

#include <objects.h>
#include <save.h>
#include <security.h>
#include <daemons.h>

string* monsters, * monsters2, * monsters3, * monsters4, * monsters5;

mapping* player_list;

void create()
{
    seteuid(getuid());
    monsters = ({});
    player_list = ({});
    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_PLAYER_LIST);
    seteuid(getuid());
}

mapping* query_player_list()
{
    return player_list;
}

varargs void add_player_info(object ob)
{
    int exp, x;
    int i;

    if (!objectp(ob)) {
        if (!(ob = previous_object()) || !userp(ob)) {
            return;
        }
    }
    if (avatarp(ob)) {
        i = sizeof(player_list);
        while (i--) {
            if (player_list[i]["name"] == (string)ob->query_name() && avatarp(ob)) {
                player_list -= ({ player_list[i] });
            }
        }
        return;
    }
    x = -1;
    i = sizeof(player_list);
    while (i--) {
        if (player_list[i]["name"] == (string)ob->query_name()) {
            x = i;
        }
    }
    if ((sizeof(player_list) == 20) && (x == -1) &&
        (((int)ob->query_exp()) < player_list[19]["experience"])) {
        return;
    }
    if (x > -1) {
        player_list -= ({ player_list[x] });
    }
    if (!arrayp(player_list)) {
        player_list = ({});
    }

    player_list += ({ ([ "name" : (string)ob->query_name(), "experience" : (int)ob->query_exp(),
                         "kills" : sizeof((string*)ob->query_kills()),
                         "deaths" : sizeof((mixed*)ob->query_deaths()),
                         "quests" : sizeof((string*)ob->query_quests()),
                         "major accomplishments" : sizeof((mixed*)ob->query_mini_quests()),
                         "level" : (int)ob->query_level(),
                         "class" : (string)ob->query_class(),
                         "guild" : (string)ob->query_guild()
                       ]) });
    player_list = sort_array(player_list, "sort_list", this_object());
    if (sizeof(player_list) > 20) {
        player_list = player_list[0..19];
    }
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_PLAYER_LIST);
    seteuid(getuid());
}

int sort_list(mapping alpha, mapping beta)
{
    if (alpha["experience"] > beta["experience"]) {
        return -1;
    }else if (alpha["experience"] < beta["experience"]) {
        return 1;
    }else {
        return strcmp(alpha["name"], beta["name"]);
    }
}

int count_unique_monsters()
{
    int tmp, x;
    monsters -= ({ 0 });
    monsters2 -= ({ 0 });
    monsters3 -= ({ 0 });
    monsters4 -= ({ 0 });
    monsters5 -= ({ 0 });
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_PLAYER_LIST);
    seteuid(getuid());
    return (sizeof(monsters) + sizeof(monsters2) + sizeof(monsters3) + sizeof(monsters4) + sizeof(monsters5));
}

int add_kill(string str)
{
    int x;

    if (!monsters) {
        monsters = ({});
    }
    if (!monsters2) {
        monsters2 = ({});
    }
    if (!monsters3) {
        monsters3 = ({});
    }
    if (!monsters4) {
        monsters4 = ({});
    }
    if (!monsters5) {
        monsters5 = ({});
    }

    if ((x = member_array(str, monsters)) == -1) {
        if ((x = member_array(str, monsters2)) == -1) {
            if ((x = member_array(str, monsters3)) == -1) {
                if ((x = member_array(str, monsters4)) == -1) {
                    if ((x = member_array(str, monsters5)) == -1) {
                        monsters5 += ({ str });
                        x = member_array(str, monsters5);
                        seteuid(UID_DAEMONSAVE);
                        save_object(SAVE_PLAYER_LIST);
                        seteuid(getuid());
                    }
                    x += 15000;
                }
                x += 15000;
            }
            x += 15000;
        }
        x += 15000;
    }
    return x;
}

string query_monster(int x)
{
    if (x <= sizeof(monsters)) {
        if (!monsters[x]) {
            return "unknown";
        }else {
            return monsters[x];
        }
    }else if (x - 15000 <= sizeof(monsters2)) {
        x = x - 15000;
        if (!monsters2[x]) {
            return "unknown";
        }else {
            return monsters2[x];
        }
    }else if (x - 30000 <= sizeof(monsters3)) {
        x = x - 30000;
        if (!monsters3[x]) {
            return "unknown";
        }else {
            return monsters3[x];
        }
    }else if (x - 45000 <= sizeof(monsters4)) {
        x = x - 45000;
        if (!monsters4[x]) {
            return "unknown";
        }else {
            return monsters4[x];
        }
    }else if (x - 60000 <= sizeof(monsters5)) {
        x = x - 60000;
        if (!monsters5[x]) {
            return "unknown";
        }else {
            return monsters5[x];
        }
    }
    return "unknown";
}

void remove_player(int i)
{
    mapping tmp;
    player_list[i]["experience"] = 0;
    player_list -= ({ player_list[i] });
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_PLAYER_LIST);
    seteuid(getuid());
}

int calc_height(object play, int hpct)
{
    int heightbase, heightmod;
    string myfile, myrace, mygender;

    if (!objectp(play)) {
        return 0;
    }
    myrace = (string)play->query_race();
    if (!myrace) {
        return 0;
    }
    myfile = "/std/races/" + myrace + ".c";
    if (!file_exists(myfile)) {
        return 0;
    }
    mygender = (string)play->query_gender();

    heightbase = (int)myfile->height_base(mygender);
    if (!heightbase) {
        heightbase = 60;           // default setting
    }
    heightmod = (int)myfile->height_mod(mygender);
    if (!heightmod) {
        heightmod = 20;          // default setting
    }
    return (heightbase + ((hpct * heightmod) / 80));
}

int* calc_weight(object play, int wpct)
{
    int base, num, adjust, die, max;
    int* vals;
    string gender;
    int height, weight;

    vals = allocate(2);
    gender = play->query_gender();
    height = play->query_height();
    switch ((string)play->query_race()) {
    case "dwarf":
        if (gender == "male") {
            base = 130;
            switch (height) {
            case 43..45:
                adjust = -20;
                die = 15;
                break;

            case 46..50:
                adjust = 0;
                die = 10;
                break;

            case 51..53:
                adjust = 0;
                die = 15;
                break;

            case 54..56:
                adjust = 20;
                die = 20;

            default:
                adjust = 0;
                die = 10;
            }
        }else {
            base = 105;
            switch (height) {
            case 41..43:
                adjust = -20;
                die = 15;
                break;

            case 44..48:
                adjust = 0;
                die = 10;
                break;

            case 49..51:
                adjust = 0;
                die = 15;
                break;

            case 52..54:
                adjust = 15;
                die = 20;

            default:
                adjust = 0;
                die = 10;
            }
        }
        num = 4;
        break;

    case "elf":
        if (gender == "male") {
            base = 90;
            switch (height) {
            case 55..57:
                adjust = -10;
                die = 15;
                break;

            case 58..62:
                adjust = 0;
                die = 10;
                break;

            case 63..65:
                adjust = 0;
                die = 15;
                break;

            case 66..68:
                adjust = 15;
                die = 15;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }else {
            base = 70;
            switch (height) {
            case 50..52:
                adjust = -15;
                die = 15;
                break;

            case 53..57:
                adjust = 0;
                die = 10;
                break;

            case 58..60:
                adjust = 0;
                die = 15;
                break;

            case 61..63:
                adjust = 5;
                die = 15;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }
        num = 3;
        break;

    case "drow":
        if (gender == "male") {
            base = 70;
            switch (height) {
            case 50..52:
                adjust = -15;
                die = 15;
                break;

            case 53..57:
                adjust = 0;
                die = 10;
                break;

            case 58..60:
                adjust = 0;
                die = 15;
                break;

            case 61..63:
                adjust = 5;
                die = 15;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }else {
            base = 90;
            switch (height) {
            case 55..57:
                adjust = -15;
                die = 15;
                break;

            case 58..62:
                adjust = 0;
                die = 10;
                break;

            case 63..65:
                adjust = 0;
                die = 15;
                break;

            case 66..68:
                adjust = 15;
                die = 15;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }
        num = 3;
        break;

    case "half-elf":
        if (gender == "male") {
            base = 110;
            switch (height) {
            case 60..62:
                adjust = -18;
                die = 18;
                break;

            case 63..68:
                adjust = 0;
                die = 12;
                break;

            case 69..72:
                adjust = 0;
                die = 18;
                break;

            case 73..75:
                adjust = 15;
                die = 20;
                break;

            default:
                adjust = 0;
                die = 12;
            }
        }else {
            base = 85;
            switch (height) {
            case 58..60:
                adjust = -18;
                die = 18;
                break;

            case 61..66:
                adjust = -5;
                die = 12;
                break;

            case 67..70:
                adjust = 0;
                die = 18;
                break;

            case 71..73:
                adjust = 10;
                die = 20;
                break;

            default:
                adjust = 0;
                die = 12;
            }
        }
        num = 3;
        break;

    case "half-drow":
        if (gender == "male") {
            base = 100;
            switch (height) {
            case 55..57:
                adjust = -18;
                die = 18;
                break;

            case 58..63:
                adjust = -10;
                die = 12;
                break;

            case 64..67:
                adjust = 0;
                die = 18;
                break;

            case 68..70:
                adjust = 10;
                die = 20;
                break;

            default:
                adjust = 0;
                die = 12;
            }
        }else {
            base = 110;
            switch (height) {
            case 57..59:
                adjust = -18;
                die = 18;
                break;

            case 60..65:
                adjust = -5;
                die = 12;
                break;

            case 66..69:
                adjust = 0;
                die = 18;
                break;

            case 70..72:
                adjust = 15;
                die = 20;
                break;

            default:
                adjust = 0;
                die = 12;
            }
        }
        num = 3;
        break;

    case "gnome":
        if (gender == "male") {
            base = 72;
            switch (height) {
            case 38..40:
                adjust = -10;
                die = 6;
                break;

            case 41..43:
                adjust = 0;
                die = 4;
                break;

            case 44..45:
                adjust = 0;
                die = 6;
                break;

            default:
                adjust = 0;
                die = 4;
            }
        }else {
            base = 68;
            switch (height) {
            case 36..38:
                adjust = -10;
                die = 6;
                break;

            case 39..41:
                adjust = 0;
                die = 4;
                break;

            case 42..43:
                adjust = 0;
                die = 6;
                break;

            default:
                adjust = 0;
                die = 4;
            }
        }
        num = 5;
        break;

    case "halfling":
        if (gender == "male") {
            base = 52;
            switch (height) {
            case 32..36:
                adjust = -10;
                die = 6;
                break;

            case 37..43:
                adjust = 0;
                die = 4;
                break;

            case 44..48:
                adjust = 0;
                die = 6;
                break;

            case 49..52:
                adjust = 5;
                die = 6;
                break;

            default:
                adjust = 0;
                die = 4;
            }
        }else {
            base = 48;
            switch (height) {
            case 30..34:
                adjust = -10;
                die = 6;
                break;

            case 35..41:
                adjust = 0;
                die = 4;
                break;

            case 42..46:
                adjust = 0;
                die = 6;
                break;

            case 47..50:
                adjust = 5;
                die = 6;
                break;

            default:
                adjust = 0;
                die = 4;
            }
        }
        num = 5;
        break;

    case "human":
        if (gender == "male") {
            base = 150;
            switch (height) {
            case 60..65:
                adjust = -40;
                die = 15;
                break;

            case 66..74:
                adjust = -10;
                die = 10;
                break;

            case 75..80:
                adjust = 20;
                die = 15;
                break;

            case 81..86:
                adjust = 30;
                die = 25;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }else {
            base = 110;
            switch (height) {
            case 55..60:
                adjust = -10;
                die = 15;
                break;

            case 61..69:
                adjust = -5;
                die = 10;
                break;

            case 70..75:
                adjust = 0;
                die = 15;
                break;

            case 76..81:
                adjust = 15;
                die = 15;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }
        num = 8;
        break;

    case "yuan-ti":
        if (gender == "male") {
            base = 150;
            switch (height) {
            case 60..65:
                adjust = -40;
                die = 15;
                break;

            case 66..74:
                adjust = -10;
                die = 10;
                break;

            case 75..80:
                adjust = 20;
                die = 15;
                break;

            case 81..86:
                adjust = 30;
                die = 25;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }else {
            base = 110;
            switch (height) {
            case 55..60:
                adjust = -10;
                die = 15;
                break;

            case 61..69:
                adjust = -5;
                die = 10;
                break;

            case 70..75:
                adjust = 0;
                die = 15;
                break;

            case 76..81:
                adjust = 15;
                die = 15;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }
        num = 8;
        break;

    case "beastman":
        if (gender == "male") {
            base = 105;
            switch (height) {
            case 55..57:
                adjust = -15;
                die = 15;
                break;

            case 58..64:
                adjust = 0;
                die = 10;
                break;

            case 65..67:
                adjust = 0;
                die = 15;
                break;

            case 68..70:
                adjust = 10;
                die = 18;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }else {
            base = 85;
            switch (height) {
            case 50..52:
                adjust = -10;
                die = 15;
                break;

            case 53..59:
                adjust = 0;
                die = 10;
                break;

            case 60..62:
                adjust = 0;
                die = 15;
                break;

            case 63..65:
                adjust = 10;
                die = 18;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }
        num = 3;
        break;

    case "bugbear":
        if (gender == "male") {
            base = 210;
            switch (height) {
            case 72..77:
                adjust = -30;
                die = 15;
                break;

            case 78..86:
                adjust = 0;
                die = 10;
                break;

            case 87..92:
                adjust = 0;
                die = 15;
                break;

            case 93..98:
                adjust = 10;
                die = 18;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }else {
            base = 180;
            switch (height) {
            case 68..73:
                adjust = -30;
                die = 15;
                break;

            case 74..82:
                adjust = 0;
                die = 10;
                break;

            case 83..88:
                adjust = 0;
                die = 15;
                break;

            case 89..94:
                adjust = 10;
                die = 18;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }
        num = 6;
        break;

    case "firbolg":
        if (gender == "male") {
            base = 780;
            switch (height) {
            case 120..122:
                adjust = -30;
                die = 15;
                break;

            case 123..129:
                adjust = 0;
                die = 10;
                break;

            case 130..132:
                adjust = 0;
                die = 15;
                break;

            case 133..135:
                adjust = 10;
                die = 18;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }else {
            base = 740;
            switch (height) {
            case 114..116:
                adjust = -30;
                die = 15;
                break;

            case 117..123:
                adjust = 0;
                die = 10;
                break;

            case 124..126:
                adjust = 0;
                die = 15;
                break;

            case 127..129:
                adjust = 10;
                die = 18;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }
        num = 6;
        break;

    case "voadkyn":
        if (gender == "male") {
            base = 675;
            switch (height) {
            case 108..110:
                adjust = -30;
                die = 15;
                break;

            case 111..117:
                adjust = 0;
                die = 10;
                break;

            case 118..120:
                adjust = 0;
                die = 15;
                break;

            case 121..123:
                adjust = 15;
                die = 18;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }else {
            base = 650;
            switch (height) {
            case 102..104:
                adjust = -30;
                die = 15;
                break;

            case 105..111:
                adjust = 0;
                die = 10;
                break;

            case 112..114:
                adjust = 0;
                die = 15;
                break;

            case 115..117:
                adjust = 10;
                die = 18;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }
        num = 6;
        break;

    case "gnoll":
        if (gender == "male") {
            base = 180;
            switch (height) {
            case 84..86:
                adjust = -20;
                die = 15;
                break;

            case 87..93:
                adjust = 0;
                die = 10;
                break;

            case 94..96:
                adjust = 0;
                die = 15;
                break;

            case 97..99:
                adjust = 10;
                die = 17;

            default:
                adjust = 0;
                die = 10;
            }
        }else {
            base = 160;
            switch (height) {
            case 80..82:
                adjust = -20;
                die = 15;
                break;

            case 83..89:
                adjust = 0;
                die = 10;
                break;

            case 90..92:
                adjust = 0;
                die = 15;
                break;

            case 93..95:
                adjust = 10;
                die = 17;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }
        num = 4;
        break;

    case "minotaur":
        if (gender == "male") {
            base = 180;
            switch (height) {
            case 84..86:
                adjust = -20;
                die = 15;
                break;

            case 87..93:
                adjust = 0;
                die = 10;
                break;

            case 94..96:
                adjust = 0;
                die = 15;
                break;

            case 97..99:
                adjust = 10;
                die = 17;

            default:
                adjust = 0;
                die = 10;
            }
        }else {
            base = 160;
            switch (height) {
            case 80..82:
                adjust = -20;
                die = 15;
                break;

            case 83..89:
                adjust = 0;
                die = 10;
                break;

            case 90..92:
                adjust = 0;
                die = 15;
                break;

            case 93..95:
                adjust = 10;
                die = 17;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }
        num = 4;
        break;

    case "goblin":
    case "ratkin":
        if (gender == "male") {
            base = 72;
            switch (height) {
            case 43..45:
                adjust = -10;
                die = 6;
                break;

            case 46..50:
                adjust = 0;
                die = 4;
                break;

            case 51..53:
                adjust = 0;
                die = 6;
                break;

            case 54..56:
                adjust = 5;
                die = 7;
                break;

            default:
                adjust = 0;
                die = 4;
            }
        }else {
            base = 68;
            switch (height) {
            case 41..43:
                adjust = -10;
                die = 6;
                break;

            case 44..48:
                adjust = 0;
                die = 4;
                break;

            case 49..51:
                adjust = 0;
                die = 6;
                break;

            case 52..54:
                adjust = 5;
                die = 7;
                break;

            default:
                adjust = 0;
                die = 4;
            }
        }
        num = 5;
        break;

    case "hobgoblin":
        if (gender == "male") {
            base = 150;
            switch (height) {
            case 72..73:
                adjust = -20;
                die = 15;
                break;

            case 74..78:
                adjust = 0;
                die = 10;
                break;

            case 79..80:
                adjust = 0;
                die = 15;
                break;

            case 81..82:
                adjust = 10;
                die = 17;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }else {
            base = 130;
            switch (height) {
            case 68..69:
                adjust = -20;
                die = 15;
                break;

            case 70..74:
                adjust = 0;
                die = 10;
                break;

            case 75..76:
                adjust = 0;
                die = 15;
                break;

            case 77..78:
                adjust = 5;
                die = 17;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }
        num = 5;
        break;

    case "kobold":
        if (gender == "male") {
            base = 130;
            switch (height) {
            case 32..34:
                adjust = -10;
                die = 6;
                break;

            case 35..41:
                adjust = 0;
                die = 4;
                break;

            case 42..44:
                adjust = 0;
                die = 6;
                break;

            case 45..47:
                adjust = 5;
                die = 7;
                break;

            default:
                adjust = 0;
                die = 4;
            }
        }else {
            base = 105;
            switch (height) {
            case 30..32:
                adjust = -10;
                die = 6;
                break;

            case 33..39:
                adjust = 0;
                die = 4;
                break;

            case 40..42:
                adjust = 0;
                die = 6;
                break;

            case 43..45:
                adjust = 5;
                die = 7;
                break;

            default:
                adjust = 0;
                die = 4;
            }
        }
        num = 5;
        break;

    case "ogre":
        if (gender == "male") {
            base = 320;
            switch (height) {
            case 96..101:
                adjust = -30;
                die = 30;
                break;

            case 102..114:
                adjust = 0;
                die = 20;
                break;

            case 115..120:
                adjust = 0;
                die = 30;
                break;

            case 121..127:
                adjust = 20;
                die = 32;
                break;

            default:
                adjust = 0;
                die = 20;
            }
        }else {
            base = 280;
            switch (height) {
            case 93..98:
                adjust = -30;
                die = 30;
                break;

            case 99..111:
                adjust = 0;
                die = 20;
                break;

            case 112..117:
                adjust = 0;
                die = 30;
                break;

            case 118..124:
                adjust = 20;
                die = 32;
                break;

            default:
                adjust = 0;
                die = 20;
            }
        }
        num = 3;
        break;

    case "half-ogre":
        if (gender == "male") {
            base = 270;
            switch (height) {
            case 84..86:
                adjust = -20;
                die = 15;
                break;

            case 87..93:
                adjust = 0;
                die = 10;
                break;

            case 94..96:
                adjust = 0;
                die = 15;
                break;

            case 97..99:
                adjust = 10;
                die = 17;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }else {
            base = 220;
            switch (height) {
            case 78..80:
                adjust = -20;
                die = 15;
                break;

            case 81..87:
                adjust = 0;
                die = 10;
                break;

            case 88..90:
                adjust = 0;
                die = 15;
                break;

            case 91..93:
                adjust = 10;
                die = 17;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }
        num = 6;
        break;

    case "ogre-mage":
        if (gender == "male") {
            base = 810;
            switch (height) {
            case 114..116:
                adjust = -20;
                die = 15;
                break;

            case 117..123:
                adjust = 0;
                die = 10;
                break;

            case 124..126:
                adjust = 0;
                die = 15;
                break;

            case 127..129:
                adjust = 15;
                die = 17;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }else {
            base = 780;
            switch (height) {
            case 96..98:
                adjust = -20;
                die = 15;
                break;

            case 99..105:
                adjust = 0;
                die = 10;
                break;

            case 106..108:
                adjust = 0;
                die = 15;
                break;

            case 109..111:
                adjust = 10;
                die = 17;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }
        num = 4;
        break;

    case "orc":
        if (gender == "male") {
            base = 130;
            switch (height) {
            case 58..60:
                adjust = -30;
                die = 15;
                break;

            case 61..67:
                adjust = 0;
                die = 10;
                break;

            case 68..70:
                adjust = 0;
                die = 15;
                break;

            case 71..73:
                adjust = 15;
                die = 17;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }else {
            base = 90;
            switch (height) {
            case 56..58:
                adjust = -30;
                die = 15;
                break;

            case 59..65:
                adjust = 0;
                die = 10;
                break;

            case 66..68:
                adjust = 0;
                die = 15;
                break;

            case 69..71:
                adjust = 10;
                die = 17;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }
        num = 6;
        break;

    case "half-orc":
        if (gender == "male") {
            base = 135;
            switch (height) {
            case 60..62:
                adjust = -30;
                die = 15;
                break;

            case 63..69:
                adjust = 0;
                die = 10;
                break;

            case 70..72:
                adjust = 0;
                die = 15;
                break;

            case 73..75:
                adjust = 15;
                die = 17;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }else {
            base = 95;
            switch (height) {
            case 58..60:
                adjust = -15;
                die = 15;
                break;

            case 61..67:
                adjust = 0;
                die = 10;
                break;

            case 68..70:
                adjust = 0;
                die = 15;
                break;

            case 71..73:
                adjust = 10;
                die = 17;
                break;

            default:
                adjust = 0;
                die = 10;
            }
        }
        num = 6;
        break;

    case "wemic":
        if (gender == "male") {
            base = 700;
            switch (height) {
            case 78..84:
                adjust = -40;
                die = 30;
                break;

            case 85..92:
                adjust = 0;
                die = 20;
                break;

            case 93..97:
                adjust = 0;
                die = 30;
                break;

            case 98..101:
                adjust = 30;
                die = 32;
                break;

            default:
                adjust = 0;
                die = 20;
            }
        }else {
            base = 670;
            switch (height) {
            case 75..81:
                adjust = -40;
                die = 30;
                break;

            case 82..89:
                adjust = 0;
                die = 20;
                break;

            case 90..94:
                adjust = 0;
                die = 30;
                break;

            case 95..98:
                adjust = 30;
                die = 32;
                break;

            default:
                adjust = 0;
                die = 20;
            }
        }
        num = 4;
        break;

    case "centaur":
        if (gender == "male") {
            base = 700;
            switch (height) {
            case 78..84:
                adjust = -40;
                die = 30;
                break;

            case 85..92:
                adjust = 0;
                die = 20;
                break;

            case 93..97:
                adjust = 0;
                die = 30;
                break;

            case 98..101:
                adjust = 30;
                die = 32;
                break;

            default:
                adjust = 0;
                die = 20;
            }
        }else {
            base = 670;
            switch (height) {
            case 75..81:
                adjust = -40;
                die = 30;
                break;

            case 82..89:
                adjust = 0;
                die = 20;
                break;

            case 90..94:
                adjust = 0;
                die = 30;
                break;

            case 95..98:
                adjust = 30;
                die = 32;
                break;

            default:
                adjust = 0;
                die = 20;
            }
        }
        num = 4;
        break;

    default:
        base = 140;
        num = 8;
        die = 10;
        adjust = 0;
    }
    max = base + (num * die) / 2 + adjust; // average weight
    num = wpct * num / 100;
    base = wpct * base / 100;
    adjust = (wpct > 100 ? wpct : 100) * adjust / 100;
    weight = base + roll_dice(num, die) + adjust;
    vals[0] = weight;
    vals[1] = max;
    return vals;
}

// For new lighting system / race night blindness...
// 12/31/2003 - garrett
string* night_races()
{
    return ({ "drow", "half-drow", "bugbear", "kobold", "hobgoblin", "gnoll", "orc", "lich", "ogre", "ogre-mage", "goblin", "minotaur", "ratkin", "troll"});
}

string* list_base_classes()
{
    string* possible_classes, * classlist = ({}), myname;
    int i;
    object class_ob;
    myname = TP->query_name();
    possible_classes = get_dir("/std/class/*.c");
    possible_classes = explode(implode(possible_classes, ""), ".c");
    if (sizeof(possible_classes)) {
        for (i = 0; i < sizeof(possible_classes); i++) {
            if (possible_classes[i] == "cavalier" ||
                possible_classes[i] == "antipaladin") {
                continue;
            }
            class_ob = find_object_or_load("/std/class/" + possible_classes[i] + ".c");
            if (objectp(class_ob) &&
                class_ob->is_prestige_class()) {
                continue;
            }
            classlist += ({ possible_classes[i] });
        }
    }
    return classlist;
}

string* list_classes()
{
    string* possible_classes, * classlist = ({}), myname;
    int i;
    object class_ob;
    myname = TP->query_name();
    possible_classes = get_dir("/std/class/*.c");
    possible_classes = explode(implode(possible_classes, ""), ".c");
    possible_classes -= ({ "cavalier", "antipaladin" });
    if (sizeof(possible_classes)) {
        for (i = 0; i < sizeof(possible_classes); i++) {
            class_ob = find_object_or_load("/std/class/" + possible_classes[i] + ".c");
            classlist += ({ possible_classes[i] });
        }
    }
    return classlist;
}

int sizeof_monsters()
{
    return sizeof(monsters4);
}

int opposed_alignment(object me, object you)
{
    string *opposed;
    int my_align, your_align;
    
    if(!me || !you)
        return 0;
    
    my_align = me->query_true_align();
    your_align = you->query_true_align();
    
    if(my_align == 5 || your_align == 5)
        return 0;
    
    //If you're the polar opposite
    if(my_align - (10 - your_align) == 0)
        return 2;
    
    opposed = ({ "000", "78936", "789", "78914", "369", "000", "147", "12369", "123", "12347" });
    
    if(strsrch(opposed[my_align], your_align + "") >= 0)
        return 1;
    
    return 0;
}
    

int check_aura(object target, string type)
{
    object *allies;
    string aura;
    int prot;

    if(!target || !type)
        return 0;

    allies = PARTY_D->query_party_members(target->query_party());

    if(!sizeof(allies))
        allies = ({ target });

    //Immunity
    if(FEATS_D->usable_feat(target, "aura of " + type))
        return 1;

    allies -= ({ target });

    //+4
    foreach(object ally in allies)
    {
        if(FEATS_D->usable_feat(ally, "aura of " + type))
            return 2;
    }

    return 0;
}

int immunity_check(object obj, string type)
{
    string myrace, mysubrace;
    int num;
    if (!objectp(obj)) {
        return 0;
    }
    myrace = obj->query_race();
    mysubrace = obj->query("subrace");

    switch (type) {
    case "sleep":
    {
        if (obj->is_undead()) {
            return 1;
        }
        switch (myrace) {
        case "elf":
        case "drow":
        case "half-elf":
        case "half-drow":
        case "golem":
        case "soulforged":
            return 1;
        default:
            return 0;
        }
        return 0;
    }

    case "charm":
    {
        switch (myrace) {
            case "barrus":
                return 1;
                break;
        }

        if (check_aura(obj, "resolve") == 1) {
            return 1;
        }
    }

    case "fear":
    {

        if (FEATS_D->usable_feat(obj, "no fear of the flame")) {
            return 1;
        }

        if (FEATS_D->usable_feat(obj, "bravery")) {
            return 1;
        }

        if(check_aura(obj, "courage") == 1)
            return 1;

        if (obj->query_property("fear_immunity")) {
            return 1;
        }
        
        if(obj->query_property("intellect fortress"))
            return 1;
        
        if(FEATS_D->usable_feat(obj, "fearless rage") && obj->query_property("raged"))
            return 1;

        switch (myrace) {

        case "halfling":
            return 1;

        case "troll":
            return 1;

        case "firbolg":
            return 1;

        case "human":
            if (mysubrace == "attayan") {
                return 1;
            }
            break;

        default:
            return 0;
        }
        return 0;
    }

    case "fatigue":
    {
        if (obj->is_undead()) {
            return 1;
        }
        if (member_array(obj->query_race(),
                         ({"golem", "construct", "soulforged"}))) {
            return 1;
        }

        return 0;
    }


    default:
        return 0;
    }

    return 0;
}
