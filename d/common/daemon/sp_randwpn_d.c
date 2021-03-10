// Random magic weapon generator - originally coded by Bane
// Bane's is /realms/bane/rweapon.c used on Laerad's Knight of the Rose
// adapted by Styx for more general use - /d/common/daemon/sp_randwpn_d
// to generate weapons for /d/common/special/sp_randwpn
// note: these weapons can't be replaced, so if someone loses one
// that weapon is lost forever, you can clone another one
// but it will be totally random and different.
//Updated with feat profs and long descript - Octothorpe 11/30/09
// Set the hit_func here but need them in the sp_rweapon file?

//Added whip and scourge and changed short blades and spear
//updates - Cythera 8/05
//Updated changes to sickle, pick and fork. Revised all stats to 
//match mudwide weapon inherits. Nienne, 03/07.
//Updated with the new critical threat and multiplier stuff and some 
//extra goodies in order to hopefully make these weapons somewhat 
//useful - Octothorpe 5/9/13

#include <std.h>
#include <daemons.h>

#define WOOD ({ "%^ORANGE%^oak", "%^RED%^cedar", "%^RED%^red oak",\
"%^ORANGE%^ironwood", "%^ORANGE%^ash", "%^RED%^mahogany",\
"%^YELLOW%^golden oak" })

#define METAL ({"%^YELLOW%^brass", "%^YELLOW%^gold", "%^BOLD%^silver",\
"%^BOLD%^%^CYAN%^adamantite", "%^YELLOW%^mithril", "%^BLUE%^steel",\
"%^BOLD%^%^BLACK%^iron", "%^BOLD%^platinum", "%^ORANGE%^bronze" })

#define GEMS ({"%^ORANGE%^amber%^RESET%^", "%^GREEN%^jade%^RESET%^",\
"%^BOLD%^crystal%^RESET%^", "%^BOLD%^diamond%^RESET%^",\
"%^BOLD%^%^GREEN%^emerald%^RESET%^", "%^BOLD%^ivory%^RESET%^",\
"%^BOLD%^%^BLACK%^obsidian%^RESET%^", "%^BOLD%^%^BLACK%^onyx%^RESET%^",\
"%^BOLD%^pearl%^RESET%^", "%^BOLD%^%^BLUE%^sapphire%^RESET%^",\
"%^YELLOW%^topaz%^RESET%^", "%^RED%^garnet%^RESET%^", "bone",\
"%^BOLD%^%^CYAN%^quartz%^RESET%^", "%^BOLD%^%^RED%^ruby%^RESET%^",\
"%^YELLOW%^o%^WHITE%^p%^YELLOW%^a%^WHITE%^l%^RESET%^", "moonstone",\
"%^RED%^hematite%^RESET%^", "%^GREEN%^malachite%^RESET%^",\
"%^MAGENTA%^amethyst%^RESET%^" })

#define POLEARMS ({"awlpike", "bec de corbin", "bill-guisarme",\
"fauchard", "glaive", "guisarme", "halberd", "partisan",\
"spetum", "voulge", "scythe", "bardiche" })
 
#define WEAPONS ({"dagger", "dirk", "knife", "footmans pick", "spear",\
"harpoon", "short sword", "javelin", "military fork",\
"trident", "sickle", "battle axe", "hand axe", "broad axe", "giant axe",\
"rapier", "bastard sword", "long sword", "khopesh", "scimitar", "falchion",\
"sabre", "claw", "lance", "two handed sword", "giant sword", "claymore",\
"club", "maul", "flail", "mace", "morning star", "warhammer",\
"large hammer", "quarterstaff", "walking staff", "whip", "scourge", "fan",\
"light rapier"})

inherit DAEMON;

string what, metal, wood, gem, gem2;
int x, enchant, flag, which, my_weight;
void make_random(object obj);
void make_polearm(object obj);

void create() {
	::create();
}

void create_weapon(object obj) {
    if(random(30)) {
       make_random(obj);
       return;
    } else 
    make_polearm(obj);
    return;
}

void make_polearm(object obj) {
   which = random(sizeof(POLEARMS));  
   what = POLEARMS[which];
   gem = GEMS[random(sizeof(GEMS))];
   gem2 = GEMS[random(sizeof(GEMS))];
   metal = METAL[random(sizeof(METAL))];
   wood = WOOD[random(sizeof(WOOD))];
   obj->add_id(POLEARMS[which]);
   obj->set_prof_type("polearm");
   obj->set_weapon_prof("martial");
   obj->set_critical_threat_range(1);
   obj->set_critical_hit_multiplier(3);
   obj->set_size(3);
   obj->set_name("exquisite looking "+what);
   obj->set_id(({what,"weapon","rweapon", "polearm"}));
   obj->set_obvious_short("%^RESET%^An exquisite looking "+what);
   obj->set_short("%^RESET%^An exquisitely jeweled "+metal+" %^BOLD%^"
      +what+"%^RESET%^");
   obj->set_long("This is an exquisitely crafted "+metal+" "+what+
      "%^RESET%^.  The "+gem+" and "+gem2+" encrusted shaft is "
      "intricately carved and etched with ancient mystical runes.");
   switch(which) {
     case 0: // awlpike
      obj->set_weight(12);
      obj->set_wc(1,12);
      obj->set_large_wc(1,12);
      obj->set_type("pierce");
      obj->set_weapon_speed(13);
      obj->set_damage_type("piercing");
      break;
    case 1: // bec de corbin
      obj->set_weight(10);
      obj->set_wc(2,6);
      obj->set_large_wc(2,6);
      obj->set_type("piercing");
      obj->set_weapon_speed(8);
      obj->set_damage_type("piercing");
      break;
    case 2: // bill-guisarme
      obj->set_weight(15);
      obj->set_wc(2,6);
      obj->set_large_wc(2,6);
      obj->set_type("pierce");
      obj->set_weapon_speed(10);
      obj->set_damage_type("piercing");
      break;
    case 3: // fauchard
      obj->set_weight(7);
      obj->set_wc(2,6);
      obj->set_large_wc(2,6);
      obj->set_type("slash");
      obj->set_weapon_speed(8);
      obj->set_damage_type("slashing");
      break;
    case 4: // glaive
      obj->set_weight(10);
      obj->set_wc(3,4);
      obj->set_large_wc(3,4);
      obj->set_type("slash");
      obj->set_weapon_speed(8);
      obj->set_damage_type("slashing");
      break;
    case 5: // guisarme
      obj->set_weight(10);
      obj->set_wc(2,4);
      obj->set_large_wc(2,6);
      obj->set_type("slash");
      obj->set_weapon_speed(8);
      obj->set_damage_type("slashing");
      break;
    case 6: // halberd
      obj->set_weight(10);
      obj->set_wc(1,10);
      obj->set_large_wc(3,6);
      obj->set_type("slashing");
      obj->set_weapon_speed(8);
      obj->set_damage_type("slashing");
      break;
    case 7: // partisan
      obj->set_weight(10);
      obj->set_wc(1,8);
      obj->set_large_wc(2,5);
      obj->set_type("slashing");
      obj->set_weapon_speed(8);
      obj->set_damage_type("slashing");
      break;
    case 8: // spetum
      obj->set_weight(10);
      obj->set_wc(1,6);
      obj->set_large_wc(2,6);
      obj->set_type("slashing");
      obj->set_weapon_speed(8);
      obj->set_damage_type("piercing");
      break;
    case 9: // voulge
      obj->set_weight(10);
      obj->set_wc(2,4);
      obj->set_large_wc(2,4);
      obj->set_type("slash");
      obj->set_weapon_speed(8);
      obj->set_damage_type("slashing");
      break;
    case 10: // scythe
	  obj->set_size(2);
      obj->set_weight(7);
      obj->set_wc(2,4);
      obj->set_large_wc(2,5);
      obj->set_type("slashing");
      obj->set_weapon_speed(4);
	  obj->set_weapon_prof("exotic");
	  obj->set_damage_type("slashing");
      break;
    case 11: // bardiche
      obj->set_weight(12);
      obj->set_wc(2,6);
      obj->set_large_wc(2,6);
      obj->set_type("slashing");
      obj->set_weapon_speed(8);
      obj->set_damage_type("slashing");
      break;
  }
}

void make_random(object obj) {
   which = random(sizeof(WEAPONS));
   what = WEAPONS[which];
   gem = GEMS[random(sizeof(GEMS))];
   gem2 = GEMS[random(sizeof(GEMS))];
   metal = METAL[random(sizeof(METAL))];
   wood = WOOD[random(sizeof(WOOD))];
   obj->add_id(WEAPONS[which]);
  switch(which) {
    case 0..1: // dagger/dirk
      obj->set_size(1);
      obj->set_weight(2);
      obj->set_wc(1,4);
      obj->set_large_wc(1,4);
      obj->set_type("piercing");
      obj->set_prof_type("small blades");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(2);
      obj->set_critical_threat_range(2);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("piercing");
      break;
    case 2: // knife
      obj->set_size(1);
      obj->set_weight(2);
      obj->set_wc(1,3);
      obj->set_large_wc(1,2);
      obj->set_type("piercing");
      obj->set_prof_type("small blades");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(2);
      obj->set_critical_threat_range(2);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("piercing");
      break;
    case 3: // footman's pick
      obj->set_size(2);
      obj->set_weight(6);
      obj->set_wc(1,6);
      obj->set_large_wc(2,3);
      obj->set_type("piercing");
      obj->set_prof_type("short blades");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(5);
	  obj->add_id("pick");
	  obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(4);
      obj->set_damage_type("piercing");
      break;
    case 4..5: // spear/harpoon
      obj->set_size(2);
      obj->set_weight(4);
      obj->set_wc(1,6);
      obj->set_large_wc(1,8);
      obj->set_type("piercing");
      obj->set_prof_type("spear");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(6);
      obj->set_property("repairtype",({"woodwork"}));
      obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("piercing");
      break;
    case 6: // short sword
      obj->set_size(1);
      obj->set_weight(4);
      obj->set_wc(2,3);
      obj->set_large_wc(2,3);
      obj->set_type("slashing");
      obj->set_prof_type("short blades");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(3);
      obj->set_critical_threat_range(2);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("slashing");
      break;
    case 7: // javelin (large spear)
      obj->set_size(3);
      obj->set_weight(6);
      obj->set_wc(2,6);
      obj->set_large_wc(3,4);
      obj->set_type("piercing");
      obj->set_prof_type("spear");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(10);
      obj->set_property("repairtype",({"woodwork"}));
      obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(3);
      obj->set_damage_type("piercing");
      break;
    case 8: // military fork
      obj->set_size(3);
      obj->set_weight(7);
      obj->set_wc(1,8);
      obj->set_large_wc(2,4);
      obj->set_type("pierce");
      obj->set_prof_type("spear");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(7);
      obj->add_id("fork");
      obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("piercing");
      break;
    case 9: // trident
      obj->set_size(2);
      obj->set_weight(6);
      obj->set_wc(1,8);
      obj->set_large_wc(3,4);
      obj->set_type("pierce");
      obj->set_prof_type("spear");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(7);
      obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("piercing");
      break;
    case 10: // sickle
      obj->set_size(1);
      obj->set_weight(3);
      obj->set_wc(1,4);
      obj->set_large_wc(1,4);
      obj->set_type("slashing");
      obj->set_prof_type("small blades");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(4);
      obj->set_property("repairtype",({"woodwork"}));
      obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("piercing");
      break;
    case 11: // battle axe
      obj->set_size(2);
      obj->set_weight(7);
      obj->set_wc(1,8);
      obj->set_large_wc(1,8);
      obj->set_type("slashing");
      obj->set_prof_type("axe");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(6);
	  obj->add_id("axe");
	  obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(3);
      obj->set_damage_type("slashing");
      break;
    case 12: // hand axe
      obj->set_size(1);
      obj->set_weight(5);
      obj->set_wc(1,6);
      obj->set_large_wc(1,4);
      obj->set_type("slashing");
      obj->set_prof_type("axe");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(4);
	  obj->add_id("axe");
	  obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(3);
      obj->set_damage_type("slashing");
      break;
    case 13: // broad axe (large axe)
      obj->set_size(3);
      obj->set_weight(10);
      obj->set_wc(3,4);
      obj->set_large_wc(3,4);
      obj->set_type("slashing");
      obj->set_prof_type("axe");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(8);
	  obj->add_id("axe");
	  obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(3);
      obj->set_damage_type("slashing");
      break;
    case 14: // giant axe
      obj->set_size(4);
      obj->set_weight(15);
      obj->set_wc(3,6);
      obj->set_large_wc(3,6);
      obj->set_type("slash");
      obj->set_prof_type("axe");
      obj->set_weapon_speed(7);
	  obj->add_id("axe");
	  obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(3);
      obj->set_damage_type("slashing");
      break;
    case 15: // rapier
      obj->set_size(2);
      obj->set_weight(4);
      obj->set_wc(1,7);
      obj->set_large_wc(1,6);
      obj->set_type("piercing");
      obj->set_prof_type("rapier");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(3);
      obj->set_critical_threat_range(3);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("piercing");
      break;
    case 16: // bastard sword
      obj->set_size(2);
      obj->set_weight(10);
      obj->set_wc(1,8);
      obj->set_large_wc(1,8);
      obj->set_type("slashing");
      obj->set_prof_type("medium blades");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(6);
      obj->add_id("sword");
      obj->set_critical_threat_range(2);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("slashing");
      break;
    case 17: // long sword
      obj->set_size(2);
      obj->set_weight(7);
      obj->set_wc(1,8);
      obj->set_large_wc(1,8);
      obj->set_type("slashing");
      obj->set_prof_type("medium blades");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(5);
      obj->add_id("sword");
      obj->set_critical_threat_range(2);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("slashing");
	break;
    case 18: case 20: // khopesh/falchion
      obj->set_size(2);
      obj->set_weight(7);
      obj->set_wc(2,4);
      obj->set_large_wc(2,5);
      obj->set_type("slashing");
      obj->set_prof_type("medium blades");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(9);
      obj->set_critical_threat_range(2);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("slashing");
      break;
    case 19: case 21: // scimitar/sabre
      obj->set_size(2);
      obj->set_weight(4);
      obj->set_wc(1,8);
      obj->set_large_wc(1,8);
      obj->set_type("piercing");
      obj->set_prof_type("medium blades");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(5);
      obj->set_critical_threat_range(3);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("slashing");
      break;
    case 22: // claw
      obj->set_size(1);
      obj->set_weight(5);
      obj->set_wc(1,6);
      obj->set_large_wc(1,6);
      obj->set_type("slashing");
      obj->set_prof_type("knuckles");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(4);
      obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("slashing");
      break;
    case 23: // lance
      obj->set_size(1);
      obj->set_weight(10);
      obj->set_wc(1,6);
      obj->set_large_wc(1,12);
      obj->set_type("piercing");
      obj->set_prof_type("lance");
	  obj->set_weapon_prof("martial");
      obj->set_property("lance",1);
      obj->set_weapon_speed(8);
	  obj->set_property("repairtype",({"woodwork"}));
	  obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(3);
      obj->set_damage_type("piercing");
      break;
    case 24: case 26: // two handed sword/claymore
      obj->set_size(3);
      obj->set_weight(15);
      obj->set_wc(3,4);
      obj->set_large_wc(3,4);
      obj->set_type("slashing");
      obj->set_prof_type("large blades");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(10);
      obj->add_id("sword");
      obj->set_critical_threat_range(2);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("slashing");
      break;
    case 25: // giant sword
      obj->set_size(4);
      obj->set_weight(15);
      obj->set_wc(3,6);
      obj->set_large_wc(3,6);
      obj->set_type("slash");
      obj->set_prof_type("large blades");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(8);
      obj->add_id("sword");
      obj->set_critical_threat_range(2);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("slashing");
      break;
    case 27: // club
      obj->set_size(2);
      obj->set_weight(4);
      obj->set_wc(1,8);
      obj->set_large_wc(1,6);
      obj->set_type("bludgeoning");
      obj->set_prof_type("club");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(4);
	  obj->set_property("repairtype",({"woodwork"}));
	  obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("bludgeoning");
      break;
    case 28: // maul
      obj->set_size(3);
      obj->set_weight(10);
      obj->set_wc(2,5);
      obj->set_large_wc(2,5);
      obj->set_type("bludgeoning");
      obj->set_prof_type("club");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(6);
	  obj->set_property("repairtype",({"woodwork"}));
	  obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("bludgeoning");
      break;
    case 29: // flail
      obj->set_size(2);
      obj->set_weight(15);
      obj->set_wc(1,8);
      obj->set_large_wc(1,8);
      obj->set_type("bludgeoning");
      obj->set_prof_type("flail");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(7);
      obj->add_id("flail");
      obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("bludgeoning");
      break;
    case 30: // mace
      obj->set_size(2);
      obj->set_weight(10);
      obj->set_wc(1,8);
      obj->set_large_wc(1,8);
      obj->set_type("bludgeoning");
      obj->set_prof_type("mace");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(6);
      obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("bludgeoning");
      break;
    case 31: // morning star
      obj->set_size(2);
      obj->set_weight(12);
      obj->set_wc(2,4);
      obj->set_large_wc(1,6);
      obj->set_type("bludgeoning");
      obj->set_prof_type("mace");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(7);
      obj->add_id("star");
      obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("bludgeoning");
      break;
    case 32: // warhammer
      obj->set_size(2);
      obj->set_weight(10);
      obj->set_wc(1,8);
      obj->set_large_wc(1,8);
      obj->set_type("bludgeoning");
      obj->set_prof_type("hammer");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(5);
      obj->add_id("hammer");
      obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(3);
      obj->set_damage_type("bludgeoning");
      break;
    case 33: // large hammer
      obj->set_size(3);
      obj->set_weight(15);
      obj->set_wc(2,5);
      obj->set_large_wc(2,6);
      obj->set_type("bludgeoning");
      obj->set_prof_type("hammer");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(8);
      obj->add_id("hammer");
      obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(3);
      obj->set_damage_type("bludgeoning");
      break;
    case 34: // quarterstaff
      obj->set_size(3);
      obj->set_weight(4);
      obj->set_wc(2,4);
      obj->set_large_wc(2,5);
      obj->set_type("bludgeoning");
      obj->set_prof_type("staff");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(4);
	  obj->set_property("repairtype",({"woodwork"}));
      obj->add_id("staff");
      obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("bludgeoning");
      break;
    case 35: // walking staff
      obj->set_size(2);
      obj->set_weight(3);
      obj->set_wc(1,6);
      obj->set_large_wc(1,6);
      obj->set_type("bludgeoning");
      obj->set_prof_type("staff");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(3);
	  obj->set_property("repairtype",({"woodwork"}));
      obj->add_id("staff");
      obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("bludgeoning");
      break;
   case 36: // whip
      obj->set_size(2);
      obj->set_weight(2);
      obj->set_wc(1,6);
      obj->set_large_wc(1,6);
      obj->set_type("lash");
      obj->set_prof_type("whip");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(8);
	  obj->set_property("repairtype",({"leatherwork"}));
	  obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("slashing");
      break;
   case 37: // scourge
      obj->set_size(2);
      obj->set_weight(2);
      obj->set_wc(2,3);
      obj->set_large_wc(2,3);
      obj->set_type("lash");
      obj->set_prof_type("whip");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(5);
	  obj->set_property("repairtype",({"leatherwork"}));
	  obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("piercing");
      break;
   case 38: // fan
      obj->set_size(1);
      obj->set_weight(3);
      obj->set_wc(1,5);
      obj->set_large_wc(1,5);
      obj->set_type("piercing");
      obj->set_prof_type("fan");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(3);
      obj->set_critical_threat_range(1);
      obj->set_critical_hit_multiplier(3);
      obj->set_damage_type("piercing");
      break;
   case 39: // light rapier
      obj->set_size(1);
      obj->set_weight(4);
      obj->set_wc(1,5);
      obj->set_large_wc(1,5);
      obj->set_type("piercing");
      obj->set_prof_type("rapier");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(3);
      obj->set_critical_threat_range(3);
      obj->set_critical_hit_multiplier(2);
      obj->set_damage_type("piercing");
      break;
  }
  obj->set_name("exquisite looking "+what);
  obj->add_id(({what,"weapon","rweapon"}));
  switch(random(4)) {
     case 0:  obj->set_obvious_short("%^RESET%^An exquisite "+what);
              break;
     case 1:  obj->set_obvious_short("%^RESET%^An ornate "+what);
              break;
     case 2:  obj->set_obvious_short("%^RESET%^A heavily jeweled "+what);
              break;
     case 3:  obj->set_obvious_short("%^RESET%^An ornately engraved "+what);
              break;
  }
  switch((string)obj->query_prof_type()) {
     case "clublike":
     case "club":
        obj->set_short("%^RESET%^An exquisite "+metal+" spiked %^RESET%^"+wood+" "
           +what+"%^RESET%^");
        obj->set_long("This is a rare and exquisitely crafted "+wood+" "+
           what+"%^RESET%^.  It has "+metal+" spikes and banding%^RESET%^ "
           "clearly designed to make it sturdier and do more damage.");
        break;
     case "mace" :
     case "morning star" :
     case "flail" :
     case "hammer" :
        obj->set_short("%^RESET%^An ornate "+metal+" "+what+" %^RESET%^with "
           "a carved "+wood+" handle%^RESET%^");
        obj->set_long("This is an exquisitely crafted "+metal+" "+what+".  "
           "%^RESET%^It has a sturdy, intricately carved, "+gem+" and "+gem2+
           " encrusted "+wood+" handle%^RESET%^ laced with "+metal+" %^RESET%^"
           "for durability and strength and engraved with ancient mystic runes.");
        break;
     case "fork" :
     case "staff" :
     case "spear" :
     case "lance" :
        obj->set_short("%^RESET%^An exquisitely jeweled "+metal+" %^BOLD%^"
           +what+"%^RESET%^");
        obj->set_long("This is an exquisitely crafted "+metal+" "+what+
           "%^RESET%^.  The "+gem+" and "+gem2+" encrusted shaft is "
           "intricately carved and etched with ancient mystical runes.");
        break;
     case "small blades" :
     case "short blades" :
     case "medium blades" :
     case "large blades" :
     case "giant blades" :
     case "rapier" :
     case "light rapier" :
        obj->set_short("%^RESET%^An exquisite "+metal+" "+what+" %^RESET%^with "
          "a jeweled hilt");
        obj->set_long("This is an exquisitely crafted "+metal+" "+what+
           "%^RESET%^.  "
           "The ornate, "+gem+" and "+gem2+" encrusted hilt and pommel are "
           "intricately etched with ancient mystical runes.  The blade is "
           "honed to an extremely sharp edge.");
        break;
     case "whip" :
          obj->set_short("%^RESET%^An exquisite "+metal+" "+what+" %^RESET%^with "
          "a jeweled handle");
        obj->set_long("This is an exquisitely crafted "+what+"%^RESET%^.  "
           "The leather strips are interwoven with "+metal+"%^RESET%^,"+
           " giving the"+
           " "+what+" added strength.  The ornate, "+gem+" and "+gem2+" "+
           "encrusted handle is intricately etched with ancient "+
           "mystical runes.");
        break;
     case "axe" :
        obj->set_short("%^RESET%^An exquisite "+metal+" "+what+" %^RESET%^with "
          "an ornate "+wood+" handle%^RESET%^");
        obj->set_long("This is an exquisitely crafted "+metal+" "+what+
           "%^RESET%^.  The ornate, "+gem+" and "+gem2+" encrusted "+wood+
           " handle %^RESET%^has a leather-bound grip.  The blade is etched "
           "with ancient mystical runes and honed to an extremely sharp edge.");
        break;
     case "fan" :
        obj->set_short("%^RESET%^An exquisite "+metal+" "+what+" %^RESET%^with "
          "a jeweled grip");
        obj->set_long("This is an exquisitely crafted "+metal+" "+what+
           "%^RESET%^.  "
           "The ornate grip is set with "+gem+" and "+gem2+", and the paper is "
           "patterned with ancient mystical runes.  The ribs are honed to "
           "extremely sharp tips.");
        break;
     case "knuckles" :
        obj->set_short("%^RESET%^An exquisite "+metal+" "+what+" %^RESET%^with "
          "a jeweled guard");
        obj->set_long("This is an exquisitely crafted "+metal+" "+what+
           "%^RESET%^.  "
           "The ornate guard is set with "+gem+" and "+gem2+".  The long tines "
           "are etched with ancient mystical runes, and honed to an extremely "
           "sharp edge.");
        break;
   }
   flag = 0;
   switch(random(100)){
      case 0..4: 
         enchant = 1;
         break;
      case 5..19: 
         enchant = 2;
         flag += random(2);
         break;
      case 20..39: 
         enchant = 3;
         flag += random(3);
         break;
      case 40..75: 
         enchant = 4;
         flag += random(4);
         break;
      case 76..98: 
         enchant = 5;
         flag += random(5);
         break;
      case 99: 
         enchant = 6;
         flag += random(6);
         break;		 
   }
   obj->set_property("enchantment",enchant);
   if(flag < 0) flag = 0;
   obj->set_value( (flag * 2000) + ((random(5)+1)*2000) );
   switch((int)obj->query_property("enchantment")){
	case 1:
         switch(random(100)){
            case 0..90:
               	break;
            case 91:
               obj->set_item_bonus("attack bonus",1);
               	break;
            case 92:
            	obj->set_item_bonus("damage bonus",1);
            	break;
            case 93:
            	obj->set_item_bonus("sight bonus",1);
            	break;
            case 94:
            	obj->set_item_bonus("magic resistance",1);
            	break;
            case 95:
            	obj->set_item_bonus("spell resistance",5);
            	break;
            case 96:
            	obj->set_item_bonus("fortitude",1);
            	break;
            case 97:
           		obj->set_item_bonus("reflex",1);
            	break;
            case 98:
            	obj->set_item_bonus("will",1);
            	break;
            case 99:
            	obj->set_item_bonus("fortitude",1);
            	break;
         }
         break;
    case 2:
    	switch(random(100)){
    		case 0..81:
    			break;
    		case 82..83:
    			obj->set_item_bonus("attack bonus",1);
              	break;
            case 84..85:
            	obj->set_item_bonus("damage bonus",1);
            	break;
            case 86..87:
            	obj->set_item_bonus("sight bonus",1);
            	break;
            case 88..89:
            	obj->set_item_bonus("magic resistance",1);
            	break;
            case 90..91:
            	obj->set_item_bonus("spell resistance",5);
            	break;
            case 92..93:
            	obj->set_item_bonus("fortitude",1);
            	break;
            case 94..95:
           		obj->set_item_bonus("reflex",1);
            	break;
            case 96..97:
            	obj->set_item_bonus("will",1);
            	break;
            case 98..99:
            	obj->set_item_bonus("fortitude",1);
            	break;
        }
        break;
    case 3:
    	switch(random(100)){
    		case 0..54:
    			break;
    		case 55..59:
    			obj->set_item_bonus("attack bonus",1);
               	break;
            case 60..64:
            	obj->set_item_bonus("damage bonus",1);
            	break;
            case 65..69:
            	obj->set_item_bonus("sight bonus",1);
            	break;
            case 70..74:
            	obj->set_item_bonus("magic resistance",1);
            	break;
            case 75..79:
            	obj->set_item_bonus("spell resistance",5);
            	break;
            case 80..84:
            	obj->set_item_bonus("fortitude",1);
            	break;
            case 85..89:
           		obj->set_item_bonus("reflex",1);
            	break;
            case 90..94:
            	obj->set_item_bonus("will",1);
            	break;
            case 95..99:
            	obj->set_item_bonus("fortitude",1);
            	break;
        }
        break;
    case 4:
    	switch(random(100)){
    		case 0..9:
    			break;
    		case 10..19:
    			obj->set_item_bonus("attack bonus",random(2)+1);
               	break;
            case 20..29:
            	obj->set_item_bonus("damage bonus",random(2)+1);
            	break;
            case 30..39:
            	obj->set_item_bonus("sight bonus",random(2)+1);
            	break;
            case 40..49:
            	obj->set_item_bonus("magic resistance",random(6)+1);
            	break;
            case 50..59:
            	obj->set_item_bonus("spell resistance",random(6)+5);
            	break;
            case 60..69:
            	obj->set_item_bonus("fortitude",random(2)+1);
            	break;
            case 70..79:
           		obj->set_item_bonus("reflex",random(2)+1);
            	break;
            case 80..89:
            	obj->set_item_bonus("will",random(2)+1);
            	break;
            case 90..99:
            	obj->set_item_bonus("fortitude",random(2)+1);
            	break;
        }
        break;
    case 5:
    	switch(random(100)){
    		case 0..8:
    			break;
    		case 9:
    			obj->set_item_bonus("able to cast",1);
               	break;
    		case 10..19:
    			obj->set_item_bonus("attack bonus",random(2)+2);
               	break;
            case 20..29:
            	obj->set_item_bonus("damage bonus",random(2)+2);
            	break;
            case 30..39:
            	obj->set_item_bonus("sight bonus",random(2)+2);
            	break;
            case 40..49:
            	obj->set_item_bonus("magic resistance",random(6)+1);
            	break;
            case 50..59:
            	obj->set_item_bonus("spell resistance",random(6)+10);
            	break;
            case 60..69:
            	obj->set_item_bonus("fortitude",random(2)+2);
            	break;
            case 70..79:
           		obj->set_item_bonus("reflex",random(2)+2);
            	break;
            case 80..89:
            	obj->set_item_bonus("will",random(2)+2);
            	break;
            case 90..99:
            	obj->set_item_bonus("fortitude",random(2)+2);
            	break;
        }
        break;
    case 6:
    	switch(random(100)){
    		case 0..9:
    			obj->set_item_bonus("able to cast",1);
               	break;
    		case 10..19:
    			obj->set_item_bonus("attack bonus",random(2)+2);
               	break;
            case 20..29:
            	obj->set_item_bonus("damage bonus",random(2)+2);
            	break;
            case 30..39:
            	obj->set_item_bonus("sight bonus",random(2)+2);
            	break;
            case 40..49:
            	obj->set_item_bonus("magic resistance",random(6)+1);
            	break;
            case 50..59:
            	obj->set_item_bonus("spell resistance",random(6)+10);
            	break;
            case 60..69:
            	obj->set_item_bonus("fortitude",random(2)+2);
            	break;
            case 70..79:
           		obj->set_item_bonus("reflex",random(2)+2);
            	break;
            case 80..89:
            	obj->set_item_bonus("will",random(2)+2);
            	break;
            case 90..99:
            	obj->set_item_bonus("fortitude",random(2)+2);
            	break;
        }
        break;
   }   
}

set_weight(int x) {
   //::set_weight(x); it's inheriting daemon, so no call to super allowed for set_weight
   my_weight = x;
}

query_weight() {
   return my_weight;
}
