//Crayoned description and added better lore - Octothorpe 1/23/10

#include <std.h>
#define CURSES (["attack bonus": -1, "damage bonus": -1, "reflex": -1, "fortitude": -1, "fire resistance": -1, "acid resistance": -1, "cold resistance": -1,"slashing resistance": -1, "bludgeoning resistance": -1, "piercing resistance": -1, "negative energy resistance": -1, "positive energy resistance": -1, "empowered": -1, "sight bonus": -1, "damage resistance": -1, "spell damage resistance": -1, "strength": -1, "dexterity" : -1, "constitution": -1, "intelligence": -1, "wisdom": -1, "charisma": -1])
inherit OBJECT;



int curse_type;
mapping curse_map, expiry_map;

void create(){
   string * curse_names, curse_name;
   ::create();
   set_name("curse");
   set_id(({"xxxcursexxx", "curse", "black curse"}));
   set_short("%^BOLD%^%^BLACK%^black curse%^RESET%^");
   set_long((:TO, "long_desc":));
   set_weight(0);
   set_property("no animate", 1);
   set_property("no steal", 1);
   set_property("no drop", 1);
   set_property("inanimate bonus", 1);
   curse_names = keys(CURSES);
   curse_type = random(sizeof(curse_names));
   report("Curse type: " + curse_type + " Size of curse_names: " + sizeof(curse_names));
   curse_name = curse_names[curse_type];
   set_item_bonus(curse_name, CURSES[curse_name]);
   curse_map = ([curse_name:({CURSES[curse_name]})]);
   expiry_map = ([curse_name: ({time() + 600}) ]);
}

varargs void report(string str, int i){
  "/daemon/reporter_d"->report("lujke", str);
}

void update_item_bonuses(){
  mapping bonus_map;
  string * bonus_names, bonus_name;
  bonus_map = query_item_bonuses();
  bonus_names = keys(bonus_map);
  if (sizeof(bonus_names)>0)
  {
    foreach(bonus_name in bonus_names)
    {
      set_item_bonus(bonus_name, 0);
    }
  }
  bonus_names = keys(curse_map);
  foreach(bonus_name in bonus_names)
  {
    if (query_curse_level(bonus_name)==0) 
    {
      curse_map = m_delete(curse_map, bonus_name);
      expiry_map = m_delete(expiry_map, bonus_name);
      continue;
    }
    set_item_bonus(bonus_name, query_curse_level(bonus_name));
  }
}

pre_exit_fun(string str){
  if (!objectp(ETO)||!interactive(ETO)) return;
  check_expiries();
  if (!mapp(curse_map) || sizeof(curse_map)<1) dest_effect();  
}

void init(){
  object * curses, curse;
  ::init();
  if (objectp(ETO))
  {
    curses = all_present("curse", ETO);
    foreach(curse in curses)
    {
      if (curse == TO) continue;
      combine_curses(curse);
    }
  }
  check_expiries();
  if (!mapp(curse_map) || sizeof(curse_map)<1) dest_effect();  
}

mapping query_curse_map(){
  return curse_map;
}
mapping query_expiry_map(){
  return expiry_map;
}

int is_curse(){
  return 1;
}

void combine_curses(object c){
  string * curse_names, curse_name, my_curse_names;
  int * old_values, * new_values, old_expiries, new_expiries;
  mapping new_map, new_expiry_map;
  if (!objectp(c) ||!c->is_curse()) return;
  new_map = c->query_curse_map();
  new_expiry_map = c->query_expiry_map();
  if (!mapp(new_map) || sizeof(new_map)<1) return;
  curse_names = keys(new_map);
  my_curse_names = keys(curse_map);
  foreach(curse_name in curse_names)
  {
    new_values = new_map[curse_name];
    new_expiries = new_expiry_map[curse_name];
    if (member_array(curse_name, my_curse_names)==-1)
    {
      curse_map[curse_name] = new_values;
      expiry_map[curse_name] = new_expiries;
      continue;
    } 
    old_values = curse_map[curse_name];
    old_expiries = expiry_map[curse_name];
    curse_map[curse_name] = old_values + new_values;
    expiry_map[curse_name] = old_expiries + new_expiries;
  }
  c->move("/d/shadowgate/void");
  c->remove();
  update_item_bonuses();
}


void dest_effect(){
  if (objectp(ETO) && interactive(ETO)) tell_object(ETO, "You feel the lifting of a weight on your soul, as a curse you picked up from the trapped gate lfts");
  move("/d/shadowgate/void");
  remove();
}

void check_expiries(){
  int t, i, * expiries, * expired, * values, flag;
  string * curse_names, curse_name;
  if (!mapp(curse_map) || sizeof(curse_map)<1)
  {
    move("/d/shadowgate/void");
    return;
  }
  flag = 0;
  t = time();
  curse_names = keys(curse_map);
  expired = ({});
  foreach(curse_name in curse_names)
  {
    expiries = expiry_map[curse_name];
    for (i=0;i<sizeof(expiries);i++)
    {
      if (expiries[i] >t ) continue;
      expired += ({i});
      if (objectp(ETO) && interactive(ETO)) tell_object(ETO, "%^BOLD%^%^BLACK%^The curse upon you loses some power");
    }
    if (sizeof(expired)<1) continue;
    flag ++;
    values = curse_map[curse_name];
    for (i=sizeof(expired)-1; i>=0;i--)
    {
       if (expired[i]==0)
       {
         curse_map[curse_name] = values[1..sizeof(values)-1];
         expiry_map[curse_name] = expiries[1..sizeof(expiries)-1];
       }
       else {
         if (i == sizeof(values)-1)
         {
           curse_map[curse_name] = values[0..i-1];
           expiry_map[curse_name] = expiries[0..i-1];
         } else
         {
           curse_map[curse_name] = values[0..i-1] + values[i+1..sizeof(values)-1];
           expiry_map[curse_name] = expiries[0..i-1] + expiries[i+1..sizeof(expiries)-1];
         }
       }
    }
  }
  update_item_bonuses();
}

int count_curses(){
  string * curse_names, curse_name;
  int * values, result;
  if (!mapp(curse_map) || sizeof(curse_map)<1) return 0;
  curse_names = keys(curse_map);
  result = 0;
  foreach(curse_name in curse_names)
  {
    values = curse_map[curse_name];
    result += sizeof(values);
  }
  return result;
}

string long_desc(){
  string result, curse_names, curse_name;
  int spellcraft, level;
  if (count_curses()<2) result = "A %^BOLD%^%^BLACK%^black curse%^RESET%^";
  else result = "A number of %^BOLD%^%^BLACK%^black curses%^RESET%^";
  if (objectp(ETO))
  {
    if (count_curses()<2) result += " lays upon ";
    else result += " lay upon ";
    if (TP == ETO)
    {
      result += "your ";
    } else result += ETP->QCN + "'s ";
    result += "soul";
  }
  result += ".\n";
  spellcraft = TP->query_skill("spellcraft");
  report ("spellcraft: " + spellcraft + " spellcraft_target: " + ((level/5) + 4 + level));
  if (objectp(ETO) && living(ETO)) level = ETO->query_base_character_level();
  else level = 50;
  if (spellcraft < (level/5) + 4 + level && !TP->query_true_invis()) return result;
  if (count_curses()<2) result += "It is harming the following ability:\n";
  else result += "They are harming the following abilities:\n";
  curse_names = keys(curse_map);
  foreach(curse_name in curse_names)
  {
    result += "%^CYAN%^" + curse_name;
    if (spellcraft >= (level/2) + 6 + level || TP->query_true_invis()) result += " %^RESET%^(%^BOLD%^%^YELLOW%^" + query_curse_level(curse_name) + "%^RESET%^)\n";
  }
  return result;
}



int query_curse_level(string curse_name){
  string * curse_names;
  int * vals, result, val;
  curse_names = keys(curse_map);
  if (member_array(curse_name, curse_names)==-1) return 0;
  vals = curse_map[curse_name];
  result = 0;
  foreach(val in vals) result += val;
  return result;
}
