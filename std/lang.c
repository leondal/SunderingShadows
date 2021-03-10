// changing beginning common to 55 + random(int) for all races per discussions
// also maxing % to learn more than one based on int.
// last change was 9/03 *Styx* 9/16/06
//fixed the subtract_lang_overload() function so that garble will work
//changed query_all_langs() so that if its 0 in the langoverload
//mapping it add it and thus you shouldn't see a bunch of
//0's in the languages command - Saide - June 2008
// Bumping base common/undercommon to 75+ as per bunneez approved. Nienne, 04/09.
//Bumping up to full fluency (100) for base common/undercommon, per Tsera & Nienne's approval - Octothorpe 10/11/13

#include <std.h>
#include <daemons.h>
#include <langs.h>

mapping __Lang;
mapping _grammar;
mapping subgrammar;
string choice;
nosave mapping langOverload = ([]);

void init_lang();

void set_grammar(string type, int level);

void set_lang(string type, int level)
{
    if (!__Lang) {
        init_lang();
    }
    choice = "common";

    __Lang[type] = level;
    set_grammar(type, 0);
    subgrammar[type] = 1;
}

mapping query_all_langs()
{
    mapping ret;
    string* langs;
    int i;

    if (!__Lang) {
        init_lang();
    }
    ret = ([]);
    ret += __Lang;
    if (!langOverload) {
        return ret;
    }
    langs = keys(langOverload);

    for (i = 0; i < sizeof(langs); i++) {
        if (!ret[langs[i]]) {
            if (langOverload[langs[i]] != 0) {
                ret[langs[i]] = langOverload[langs[i]];
            }
        }   else {
            ret[langs[i]] += langOverload[langs[i]];
        }
    }
    return ret;
}

int query_lang(string type)
{
    return query_all_langs()[type];
}

int add_lang(string type)
{
    if (query_lang(type)) {
        return 0;
    }
    set_lang(type, 1);
    return 1;
}

void init_lang()
{
    string racefile;
    string* langs, i;
    string race;
    string subrace;

    __Lang = ([]);
    _grammar = ([]);
    subgrammar = ([]);

    race = TO->query_race();
    subrace = TO->query("subrace");
    if (!race || race == "") {
        return;
    }

    racefile = "/std/races/" + race + ".c";
    if (!file_exists(racefile)) {
        return;
    }
    if (!arrayp(racefile->query_languages(subrace)["required"])) {
        return;
    }

    langs = racefile->query_languages(subrace)["required"];
    foreach(i in langs)
    {
        set_lang(i, 100);
    }
}

void set_grammar(string type, int level)
{
    if (!_grammar) {
        _grammar = ([]);
    }
    _grammar[type] = level;
}

int query_grammar(string type)
{
    if (!_grammar) {
        _grammar = ([]);
    }
    if (!_grammar[type]) {
        return 0;
    }
    return _grammar[type];
}

mapping query_all_grammar()
{
    return _grammar;
}

void add_grammar(string type, int level)
{
    int needed;
    int intel;

    if (!query_lang(type)) {
        if (!add_lang(type)) {
            return;
        }
    }
    if (!__Lang[type] && langOverload[type]) {
        return;
    }
    if (!_grammar) {
        _grammar = ([]);
    }
    if (!_grammar[type]) {
        _grammar[type] = 1;
    }
    if (!subgrammar) {
        subgrammar = ([]);
    }
    if (!subgrammar[type]) {
        subgrammar[type] = 1;
    }
    _grammar[type] += level;
    while (_grammar[type] > 99) {
        __Lang[type] += 1;
        _grammar[type] -= 99;
    }
    if(__Lang[type] > 100)
    {
      __Lang[type] = 100;
      _grammar[type] = 0;
    }
}

int set_spoken(string str)
{
    if (TO->is_monster()) {
        choice = str;
        return 1;
    }
    if (!__Lang) {
        init_lang();
    }
    if (!query_lang(str)) {
        return 0;
    }
    choice = str;
    return 1;
}

string query_spoken()
{
    if (choice == 0) {
        choice = "common";
    }
    return choice;
}

void remove_lang(string str)
{
    if (!str) {
        return;
    }
    if (member_array(str, keys(__Lang)) == -1) {
        return;
    }
    map_delete(__Lang, str);
    return;
}

int query_base_lang(string type)
{
    if (!__Lang || !__Lang[type]) {
        return 0;
    }
    return __Lang[type];
}

void add_lang_overload(string type, int amount)
{
    if (!langOverload) {
        langOverload = ([]);
    }
    if (!langOverload[type]) {
        langOverload[type] = amount;
    }else {
        langOverload[type] += amount;
    }
}

int query_lang_overload(string type)
{
    if (!langOverload[type]) {
        return 0;
    }
    return langOverload[type];
}

void remove_lang_overload(string type)
{
    if (!langOverload) {
        return;
    }
    if (!langOverload[type]) {
        return;
    }
    langOverload[type] = 0;
}

void subtract_lang_overload(string type, int amount)
{
    if (!amount) {
        return;
    }
    if (!langOverload) {
        langOverload = ([]);
    }
    if (!langOverload[type]) {
        langOverload[type] = -amount;
    }else {
        langOverload[type] -= amount;
    }
}

mapping query_over_load_mapping()
{
    return langOverload;
}

mapping query_base_lang_mapping()
{
    return __Lang;
}
