#include <databases.h>

#define LIMB_DIR "/adm/db/races/"
#define MON_DIR "/adm/db/mon_races/"

mapping races, limbs;

void load_races() {
    string *lines, *data, *w_limbs, *borg, *b_types;
    int i, j, tmp, tmp2;

    races = ([]);
    limbs = ([]);
    b_types = ({});

    for(i=0, tmp = sizeof(lines = read_database(RACES_DB)); i<tmp; i++) {
        if(sizeof(data=explode(lines[i], ":")) != 14) continue;
        races[data[0]] =
          ([ "sight":atoi(data[1]), "weight":atoi(data[2]), "fingers":atoi(data[3]), "size":atoi(data[12]), "ac":atoi(data[13]) ]);
        races[data[0]]["wielding"] = ({});
        for(j=0, tmp2=sizeof(w_limbs=explode(data[4], ";")); j<tmp2; j++)
            races[data[0]]["wielding"] += ({ w_limbs[j] });
        races[data[0]]["str"] = atoi(data[5]);
        races[data[0]]["con"] = atoi(data[6]);
        races[data[0]]["int"] = atoi(data[7]);
        races[data[0]]["wis"] = atoi(data[8]);
        races[data[0]]["dex"] = atoi(data[9]);
        races[data[0]]["cha"] = atoi(data[10]);
	races[data[0]]["body type"] = data[11];
	if (member_array(data[11], b_types) == -1)
	  b_types += ({ data[11] });
    }
    for(i = 0, tmp = sizeof(b_types); i < tmp; i++) {
        if(!file_exists(LIMB_DIR+b_types[i])) {
            map_delete(races, b_types[i]);
            continue;
        }
        limbs[b_types[i]] = ([]);
        for(j=0, tmp2=sizeof(lines=explode(read_file(LIMB_DIR+b_types[i]), "\n"));
          j<tmp2; j++) {
            if(lines[j][0] == '#')
	      continue;
            if(sizeof(data = explode(lines[j], ":")) != 4)
	      continue;
            if(data[1] == "0")
	      data[1] = "";
            limbs[b_types[i]][data[0]] =
              ([ "ref":data[1], "max":atoi(data[2]), "attach":data[3] ]);
        }
    }
}

void create() {

    seteuid(getuid());
    races = ([]);
    limbs = ([]);
    load_races();
}

int query_weight(string res, int con) {
    if(!res || !con || !races[res]) return 10000;
    else return ((con-10)*100 + races[res]["weight"]);
}

int query_fingers(string res) {
    if(!res || !races[res]) return 5;
    else return races[res]["fingers"];
}

int query_size(string res) {
	if(!res || !races[res]) return 2;
    else return races[res]["size"];
}

int query_ac(string res) {
//	if(!res || !races[res]) return 0;
//    else return races[res]["ac"];
    return 0;
}

int query_stat_adjustment(string stat, string res);
int query_sight_bonus(string res) {
    if(!res || !races[res]) return 0;
    else return races[res]["sight"];
}

/*
string *query_wielding_limbs(string res) {
    if(!res || !races[res])
        return ({ "right hand", "left hand" });
    else return races[res]["wielding"];
}*/

string *query_wielding_limbs(string res)
{
    object race;
    string file;
    if(!res || !races[res])
        return ({ "right hand", "left hand" });
    file = "/std/races/"+res+".c";
    if(!file_exists(file)) { return ({ "right hand", "left hand" }); }
    race = find_object_or_load(file);
    if(!objectp(race)) { return ({"right hand","left hand"}); }
    else return race->wielding_limbs();
}

int is_race(string res) {
    return (member_array(res, keys(races)) != -1);
}

int query_max_dam(string limb, string res) {
    if(!limb || !res || !races[res] || !limbs[races[res]["body type"]])
      return 2;
    if(limb == "torso") return 1;
    else if(!limbs[races[res]["body type"]][limb]) return 0;
    else return limbs[races[res]["body type"]][limb]["max"];
}

string *query_limbs(string res) {
    if(!res || !limbs[races[res]["body type"]]) return query_limbs("human");
    else return keys(limbs[races[res]["body type"]]);
}

string *query_races() { return keys(races); }

int is_limb(string limb, string res) {
    if(!limb || !res || !limbs[races[res]["body type"]]) return 0;
    else
      return (member_array(limb, keys(limbs[races[res]["body type"]])) != -1);
}

mapping body(object ob) {
    mapping borg;
    string res;
    string *what;
    int i, tmp, max;

    borg = ([]);
    res = (string)ob->query_race();
    if(!res)
      res = "human";
     if (member_array(res,keys(races)) == -1) res = "human";
    max = (int)ob->query_max_hp();
    borg["torso"] =
      ([ "limb_ref": "FATAL", "max_dam": max+1, "damage":0, "ac":0 ]);
    if(!limbs || limbs == ([]) ){
		load_races();
    }
    tmp = sizeof(what = keys(limbs[races[res]["body type"]]));
    if (!tmp)
      load_races();
    tmp = sizeof(what = keys(limbs[races[res]["body type"]]));
    if (!tmp)
      load_races();
    tmp = sizeof(what = keys(limbs[races[res]["body type"]]));
    if (!tmp)
      ob->internal_remove();
    for(i=0; i < tmp; i++)
      borg[what[i]] =
	(["limb_ref":limbs[races[res]["body type"]][what[i]]["ref"],
          "max_dam": max/limbs[races[res]["body type"]][what[i]]["max"],
          "damage":0, "ac":0
	]);
    return borg;
}

mapping do_rolls(string res) {
    mapping borg;
    string *stats;
    int tmp, i;

    if(!res || !races[res]) return 0;
    borg = ([
      "strength": random(10) + 7 + races[res]["str"],
      "constitution": random(10) + 7 + races[res]["con"],
      "intelligence": random(10) + 7 + races[res]["int"],
      "wisdom": random(10) + 7 + races[res]["wis"],
      "dexterity": random(10) + 7 + races[res]["dex"],
      "charisma": random(10) + 7 + races[res]["cha"]
    ]);
    for(i=0, tmp=(sizeof(stats=keys(borg))); i<tmp; i++) {
      if(borg[stats[i]] > 23) borg[stats[i]] = 23;
      else if(borg[stats[i]] < 2) borg[stats[i]] = 2;
    }
    return borg;
}

mapping query_limb_info(string limb, string res) {
    if(!res || !limbs[res]) res = "human";
    if(!limb || !limbs[res][limb]) return 0;
    return limbs[res][limb];
}

int query_stat_adjustment(string stat, string res) {
    if(!stat || !res || !races[res]) return 0;
    return races[res][stat];
}

// Monster Race related code
// by Valodin, June 28, 1993
int is_monster_race(string str)
{
  if(is_race(str))
    return 1;
  return (member_array(str, get_dir(MON_DIR)) != -1);
}

mapping monster_body(string mon_race, int max)
{
    mapping borg;
    string *what, *lines, *data;
    int i, tmp;

    borg = ([]);
    if(!mon_race || !is_monster_race(mon_race)) mon_race = "human";
    borg["torso"] =
      ([ "limb_ref": "FATAL", "max_dam": max+1, "damage":0, "ac":0 ]);
    if (is_race(mon_race))
      for(i=0, tmp = sizeof(what=keys(limbs[races[mon_race]["body type"]]));
	  i < tmp; i++)
        borg[what[i]] =
	  (["limb_ref":limbs[races[mon_race]["body type"]][what[i]]["ref"],
	    "max_dam": max/limbs[races[mon_race]["body type"]][what[i]]["max"],
	    "damage":0, "ac":0
	    ]);
    else
    {
      for(i = 1, tmp = sizeof(lines = explode(read_file(MON_DIR + mon_race),
					      "\n")); i < tmp; i++) {
	if(sizeof(data=explode(lines[i], ":")) != 4) continue;
	if(data[1] == "0") data[1] = "";
	borg[data[0]] =
          ([ "limb_ref": data[1], "max_dam": max/atoi(data[2]), "damage":0, "ac":0 ]);
      }
    }
    return borg;
}

string *query_monster_wielding_limbs(string race)
{
  string *lines;

  if(is_race(race))
    return query_wielding_limbs(race);
  else
  {
    if(file_size(MON_DIR + race) < 0)
      return query_wielding_limbs("human");
    lines = explode(read_file(MON_DIR + race), "\n");
    lines = explode(lines[0], ":");
    return (explode(lines[1],";"));
  }
}

int query_monster_fingers(string race)
{
  string *lines;

  if(is_race(race))
    return query_fingers(race);
  else
  {
    if(file_size(MON_DIR + race) < 0)
      return query_fingers("human");
    lines = explode(read_file(MON_DIR + race), "\n");
    lines = explode(lines[0], ":");
    return (atoi(lines[0]));
  }
}

int query_max_mon_dam(string limb, string b_type) {
  string *lines, *data;
  int i, tmp;

  if(!limb || !b_type)
    return 2;
  if(limb == "torso") return 1;
  else if(!limbs[b_type])
  {
    if(file_size(MON_DIR + b_type) < 0) return 2;
    for(i = 1, tmp = sizeof(lines = explode(read_file(MON_DIR + b_type),
					    "\n")); i < tmp; i++) {
      if(sizeof(data=explode(lines[i], ":")) != 4) continue;
      if(data[0] == limb) return atoi(data[2]);
    }
    return 2;
  }
  else if(!limbs[b_type][limb]) return 2;
  else return limbs[b_type][limb]["max"];
}

int can_fly(object ob)
{

    string* flyraces = ({ "deva", "faery", "nightwing"});
    string* flysubraces = ({ "fey'ri", "rock gnome", "trixie", "sildruath",});
    string* flyprofiles = ({ "druid_bird_999", "druid_dragon_999", "mage_red_dragon_999", "mage_demon_999", "vampire_bat_999", "vampire_vampire_999", "vampire_varghulf_999", "mage_pixie_999" });

    if (!objectp(ob)) {
        return;
    }
    
    if(ob->is_deva())
        return 1;

    return (member_array(TP->query_visual_race(), flyraces) != -1) ||
        (member_array(TP->query("subrace"), flysubraces) != -1) ||
        (member_array(TP->query("relationship_profile"), flyprofiles) != -1);
}

int is_valid_blooddrain_target(object targobj, object vampobj)
{
    if (!objectp(targobj)) {
        return;
    }

    if (!vampobj->ok_to_kill(targobj)) {
        return 0;
    }

    if (!is_race(targobj->query_race())) {
        return 0;
    }

    if (targobj->query_property("spell_creature") ||
        targobj->query("not living")) {
        return 0;
    }

    if (targobj->is_undead()) {
        return 0;
    }

    return 1;

}
