#include <std.h>
#include <terrain.h>
#include "../tunnel.h"

#define PASSWORDS ({"vashud quaaltahzd praalng fleg",\
"wrgled grelmzd ngzd maarshurkzn",\
"ahgzun dun wart",\
"vashud inngzazn ngzd denminakhz",\
"vaarghutz bhaarg zimshaz",\
"grnhazrh bhaarg vaarkshaz",\
"denwar dun war",\
"den vershz garhleng",\
"umprlazz golm grromhaz",\
"bhaarg hxagrin traalhaxzn",\
"vashud penshugszzat flsh venhagraxn",\
"kuz vashud shlumshlakan",\
"omzet znnuslah, inngzaz",\
"slev vashud drrp flsh brzzharatchzd",\
"Shllorg flsh gruntahrx baatuzd",\
"war unz naklz",\
"vashud unglazzaraz gsh vashud munz",\
"lagh denwarzd flsh uglinzd",\
"vashud drrpgunchn flsh krsplshaczd",\
"grep praalnchn gushazd",\
"ukplaz ut ng nrrzn",\
"zarkn gsh naklz",\
"forgag gnushorn flantarz znnuslah",\
"zek vleshd plek",\
"murzzd flsh rahrchn baatzd",\
"norhaz vashud shlumshlakan ng wrch dshnakring golm vashud rejh",\
"zimchaz vraxhelzaz praxz zalslaz"})


#define COMMWORDS ({"the fires burn high",\
"many souls are gathered",\
"battle to death",\
"the conquered are slaves",\
"summon your power",\
"follow your leader",\
"live to kill",\
"do not touch",\
"delight in disaster",\
"your realm invaded ",\
"the source of knowledge ",\
"hail the devourer",\
"With fear, conquer",\
"taste the blood of elves",\
"Lord of the lower Hells",\
"kill and plunder",\
"the drow on the stake",\
"four lives of humans",\
"The bleeding of sacrifices",\
"Three burning hearts",\
"reclaim what is owed",\
"embark on plunder",\
"let proud races fear",\
"a secret incantation",\
"hordes of howling devils",\
"Even the devourer is most deadly in the dark",\
"every deviation has peril"})


inherit VAULT; 

int query_day_number();
string query_password(int day);
string query_commword(int day);

create()
{
  ::create();
}

string * query_passwords(){
  return PASSWORDS;
}

int query_day_number()
{
  //returns the number of the day in the year.
  int day,mon;
  day = date(time());
  switch (month(time()))
  {
  case "Winterstime":
    mon = 0;
    break;
  case "Renewal":
    mon = 1;
    break;
  case "Springstime":
    mon = 2;
    break;
  case "Plantingdays": 
    mon = 3;
    break;
  case "Sundays":
    mon = 4;
    break;
  case "Summerstime":
    mon = 5;
    break;
  case "Growingdays":
    mon = 6;
    break;
  case "Harvestdays":
    mon = 7;
    break;
  case "Autumnstime":
    mon = 8;
    break;
  case "Colddays":
    mon = 9;
    break;
  }
  return (mon*10)+day;
}

string query_password(int day)
{
  int passnum;
  passnum = day%sizeof(PASSWORDS);
  return PASSWORDS[passnum];
}

string query_commword(int day)
{
  int commnum;
  commnum = day%sizeof(COMMWORDS);
  return COMMWORDS[commnum];
}
