//Based on the phantom guardians code.
//additional methods for wizzes to set and query creature type: 
// query_creature() and set_creature(string str)

#include <std.h>
#include "../tecqumin.h"

inherit OBJECT;
string creature;
object caster;
void make_creature();

object *mons = ({});

void create() {
    ::create();
    switch(random(2) + 2){  // change to random(4) when the jaguar and tree spirits are done
    case 0:
      creature = "jaguar";
    case 1:
      creature = "tree";
    case 2:
      creature = "warrior";
    case 3:
      creature = "priest";
    }
    make_creature();
    set_id(({"figurine", "small figurine"}));
}

void init(){
  ::init();
  add_action("sling_figurine", "sling");
}

string query_creature(){
  return creature;
}

int set_creature(string str){
  if (str != "jaguar" && str != "tree" && str != "warrior" && str != "priest"){
    return -1;
  }
  creature = str;
  make_creature();
  return 1;
}

void make_creature(){
  switch(creature){
    case "jaguar": // jaguar
      set_short("small stone figurine of a %^BOLD%^%^BLACK%^jaguar%^RESET%^");
      set_long("The figurine is carved into a stylistic representation of a"
        +" %^BOLD%^%^BLACK%^jaguar%^RESET%^, in a crouched position, with"
        +" its tail wrapped around one of its back leg.");
    set_id(({"figurine", "small figurine","jaguar figurine"}));
    case "tree": // nature spirit 
      set_short("small %^ORANGE%^wooden figurine%^RESET%^ in the shape of a"
        +" tree");
      set_long("The small figurine is carved from ancient wood, hardened by"
        +" the long passage of years. It is in the shape of a %^GREEN%^tree"
        +"%^RESET%^, stylised but clearly representative.");
    set_id(({"figurine", "small figurine", "tree figurine"}));
    case "warrior": // tecqumin warrior
       set_short("small %^CYAN%^t%^RESET%^u%^CYAN%^rqu%^BOLD%^%^CYAN%^o"
         +"%^RESET%^%^CYAN%^ise f%^BOLD%^%^WHITE%^i%^CYAN%^g%^BLUE%^u"
         +"%^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^ne%^RESET%^"
         +" of a warrior%^RESET%^");       
       set_long("The figurine is carved into a stylistic representation of a"
         +" warrior with a spear");
    set_id(({"figurine", "small figurine", "warrior figurine"}));
    case "priest": // tecqumin priest
       set_short("a small %^ORANGE%^a%^YELLOW%^m%^RESET%^%^ORANGE%^ber"
         +" f%^YELLOW%^i%^RESET%^%^ORANGE%^gur%^YELLOW%^i%^RESET%^%^ORANGE%^"
         +"ne%^RESET%^ of a priest%^RESET%^"); 
       set_long("The figurine is carved into a stylistic representation of a"
         +" figure wielding a holy symbol and a sacrificial knife");
    set_id(({"figurine", "small figurine", "priest figurine"}));
  }

}

string query_casting_string() {
    return "%^BOLD%^%^GREEN%^"+ETO->query_cap_name()+" caresses a statue and focuses on a couple large emeralds while chanting.";
}

int preSummon() {
  if (present(ETO->query_name()+"phantommonster",EETO)) {
      tell_object(ETO,"You can't summon multiple sets of guardians.");
      return 0;
  }
  return 1;
}

int sling_figurine(string str) {
  object ob, place;
  int i;
  int level;
  caster = ETO;
  place = EETO;
  if (!TO->id(str)){ return notify_fail("You can't sling that");}
  if (!objectp(ETO)){return 0;}
  if (!interactive(ETO)){return 0;}
  if (!objectp(EETO)){return notify_fail("ERROR - there is a problem with the room you are in");}
  tell_room(place,"%^ORANGE%^"+caster->query_cap_name()+" slings a small figurine to the ground.",caster);
  tell_object(caster,"%^ORANGE%^ you sling the figurine to the ground in front of you.");
  tell_room(place,"%^ORANGE%^The figurine glows and starts to grow.%^RESET%^");
  switch (creature) {
  case "jaguar":
    ob = new("/d/magic/mon/gjaguar");
  case "tree":
    ob = new("/d/magic/mon/gtree");
  case "warrior":
    ob = new(GHOST_WARRIOR);
  case "priest":
    ob = new(GHOST_PRIEST);
  }
  level = ETO->query_highest_level();
  ob->move(EETO);
  ETO->add_protector(ob);
  ob->set_damage_bonus(level/8);
  ob->set_attack_bonus(level/3);
  ob->set_attacks_num(3);
  ob->set_exp(0);
  caster->add_follower(ob);
  ob->set_property("spelled", ({TO}) );
  ob->set_property("spell_creature", TO);
  ob->set_property("spell", TO);
  ob->add_id("summoned monster");
  ob->add_id(ETO->query_name()+"phantommonster");
  mons += ({ob});
}

void dest_effect() {
    int i;
    for (i=0;i<sizeof(mons);i++) {
        if (objectp(mons[i])) 
        {
            if(objectp(caster))
            {
                caster->remove_protector(mons[i]);
            }
            mons[i]->die();
        }
    }
    TO->move("/d/shadowgate/void");
    TO->remove();
}
