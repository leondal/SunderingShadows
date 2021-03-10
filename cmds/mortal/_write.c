//
#include <std.h>
#include <daemons.h>
#include <langs.h>

inherit DAEMON;

#define WRITE_PRACTICE 125

int help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

write - write on something

%^CYAN%^SYNOPSIS%^RESET%^

write in %^ORANGE%^%^ULINE%^LANGUAGE%^RESET%^ on %^ORANGE%^%^ULINE%^OBJECT%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This will allow you to write on %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ in %^ORANGE%^%^ULINE%^LANGUAGE%^RESET%^ you specified. Anyone then will be able to %^ORANGE%^<read %^ORANGE%^%^ULINE%^OBJECT%^RESET%^>%^RESET%^ to read your message. You and the reader both must know the %^ORANGE%^%^ULINE%^LANGUAGE%^RESET%^.

Ability to write property is heavily affected by your academics skill. Adacemics skills is rolled against d20 on every word with no critical chances. If you fail, the word gets scrambled.

Typical %^ORANGE%^%^ULINE%^OBJECT%^RESET%^s to write on are, but not limited to, paper, parchment.

%^CYAN%^SEE ALSO%^RESET%^

languages, teach, say, tell, communication
"
        );
    return 1;
}

int cmd_write(string str)
{
    string lang, dest;
    object paper;

    if (!str) {
        return help();
    }
    if (sscanf(str, "in %s on %s", lang, dest) != 2) {
        return help();
    }

    lang = lower_case(lang);

    if (member_array(lang, ANIMAL_LANGS) != -1) {
        tell_object(TP, "You can't write an animal's language.");
        return 1;
    }

    if (TP->query_lang(lang) < 75) {
        tell_object(TP, "You don't know that language well enough to write in it.");
        return 1;
    }

    paper = present(dest, TP);

    if (!objectp(paper)) {
        return notify_fail("You don't have " + dest + "!\n");
    }

    write("Please write your message, Please hit <return> after each line.");
    write("** to end message");
    input_to("long_desc", TP, "", paper, lang);
    return 1;
}

void long_desc(string str, object tp, string long, object ob, string lang)
{
    if (str == "**") {
        end_game(tp, long, ob, lang);
    } else {
        if (!long) {
            long = str + "\n";
        }else {
            long = long + str + "\n";
        }
        input_to("long_desc", tp, long, ob, lang);
    }
}

int end_game(object tp, string str, object ob, string lang)
{
    string old;
    str = do_proficiency(tp, str);
    old = ob->query("read");
    if (stringp(old)) {
        str = old + "\n\n" + str;
    }
    ob->set("read", str);
    ob->set("language", lang);
    return 1;
}

string do_proficiency(object tp, string str)
{
    string* words, * all, * lines, tmp;
    int i, j, prof, total, remainder;
    string line;

    tmp = "";
    prof = (int)tp->query_skill("academics");

    total = tp->query("writing_remainder");
    total += strlen(str);

    remainder = total % WRITE_PRACTICE;
    tp->set("writing_remainder", remainder);


    all = ({});
    lines = explode(str, "\n");
    for (i = 0; i < sizeof(lines); i++) {
        lines[i] = replace_string(lines[i], " ", " ~!");
        words = explode(lines[i], "~!");
        if (sizeof(words)) {
            words[sizeof(words) - 1] = words[sizeof(words) - 1] + "\n";
            all += words;
        } else {
            all += ({ "\n" });
        }
    }
    tmp = "\n";
    for (i = 0; i < sizeof(all); i++) {
        if (prof == 21 || random(20) < prof + 1) {
            all[i] = all[i];
        } else {
            all[i] = morph_word(all[i], all, i);
        }
        tmp += all[i];
    }
    return tmp;
}

string morph_word(string word, string* all, int w)
{
    string s;
    int i = random(20);

    switch (i) {
    case 0..5:
        s = (((i + 1) < sizeof(all))?all[i + 1]:"");
        if ((i + 1) < sizeof(all)) {
            all[i + 1] = word;
        }
        return s;
    case 6..16:
        return jumble(word);
    case 17:
        return "/daemon/language_d"->fakeWord("", strlen(word));
    case 18:
        return word;
    case 19:
        return "";
    }
}

string jumble(string word)
{
    int i, k;
    string tmp, * words;

    words = explode(word, "");
    for (i = 0; i < sizeof(words); i++) {
        k = random(sizeof(words));
        tmp = words[k];
        words[k] = words[i];
        words[i] = tmp;
    }
    tmp = "";
    for (i = 0; i < sizeof(words); i++) {
        tmp += words[i];
    }
    return tmp;
}
