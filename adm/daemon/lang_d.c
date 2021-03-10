// Language daemon create by Valodin as an experimental racial language 
// reference

#include <std.h>
#include <databases.h>

inherit DAEMON;
mapping language_list;

mapping read_languages();

void create()
{
  ::create();
  language_list = read_languages();
}

void init_languages(object ob)
{
  string race, tmp;
  int prof;

  race = ob->query_race();
  prof = 10;
  if(sscanf(race, "half-%s", tmp) == 1)
  {
    race = tmp;
    ob->set_lang_prof(language_list["human"], 6);
    prof = 6;
  }
  if(tmp = language_list[race])
  {
    ob->set_lang_prof(tmp, prof);
    ob->set_lang_prof("common",50);
    ob->set_primary_lang("common");
    return;
  }
  else
  {
    ob->set_lang_prof(race + "ish", prof);
    ob->set_lang_prof("common",50);
    ob->set_primary_lang("common");
    return;
  }
}

mapping read_languages()
{
  mapping langs;
  string *lines, *line;
  int i, lnsz;

  langs = ([]);
  for(i=0, lnsz = sizeof(lines = read_database(LANGUAGES_DB)); i<lnsz; i++) {
    line = explode(lines[i], ":");
    langs[line[0]] = line[1];
  }
  return langs;
}

string *all_languages()
{
  return values(language_list);
}

string *all_races()
{
  return keys(language_list);
}
