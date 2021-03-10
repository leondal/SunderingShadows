// Random magic weapon generator - originally coded by Bane
// Bane's is /realms/bane/rweapon.c used on Laerad's Knight of the Rose
// adapted by Styx for more general use - /d/common/daemon/sp_randwpn_d
// to generate weapons for /d/common/special/sp_randwpn
// note: these weapons can't be replaced, so if someone loses one
// that weapon is lost forever, you can clone another one
// but it will be totally random and different.

// Set the hit_func here but need them in the sp_rweapon file?

//Added whip and scourge and changed short blades and spear
//updates - Cythera 8/05
//Updated changes to sickle, pick and fork. Revised all stats to 
//match mudwide weapon inherits. Nienne, 03/07.
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
"trident", "sickle", "battle axe", "hand axe", "broad axe", "great axe",\
"rapier", "bastard sword", "long sword", "khopesh", "scimitar", "falchion",\
"sabre", "claw", "lance", "two handed sword", "great sword", "claymore",\
"club", "maul", "flail", "mace", "morning star", "warhammer",\
"large hammer", "quarterstaff", "walking staff", "whip", "scourge", "fan"})

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
  obj->set_prof_type("polearm");
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
     case 0:
      obj->set_weight(12);
      obj->set_wc(1,6);
      obj->set_large_wc(1,12);
      obj->set_type("pierce");
      obj->set_weapon_speed(13);
      obj->add_id("awlpike");
      break;
    case 1:
      obj->set_weight(10);
      obj->set_wc(1,8);
      obj->set_large_wc(1,6);
      obj->set_type("pierce");
      obj->set_weapon_speed(8);
      obj->add_id("bec de corbin");
      break;
    case 2:
      obj->set_weight(15);
      obj->set_wc(2,4);
      obj->set_large_wc(1,10);
      obj->set_type("pierce");
      obj->set_weapon_speed(10);
      obj->add_id("bill-guisarme");
      break;
    case 3:
      obj->set_weight(7);
      obj->set_wc(2,5);
      obj->set_large_wc(2,7);
      obj->set_type("slash");
      obj->set_weapon_speed(8);
      obj->add_id("fauchard");
      break;
    case 4:
      obj->set_weight(10);
      obj->set_wc(1,8);
      obj->set_large_wc(1,10);
      obj->set_type("slash");
      obj->set_weapon_speed(8);
      obj->add_id("glaive");
      break;
    case 5:
      obj->set_weight(10);
      obj->set_wc(2,4);
      obj->set_large_wc(2,6);
      obj->set_type("slash");
      obj->set_weapon_speed(8);
      obj->add_id("guisarme");
      break;
    case 6:
      obj->set_weight(10);
      obj->set_wc(1,10);
      obj->set_large_wc(3,6);
      obj->set_type("slash");
      obj->set_weapon_speed(8);
      obj->add_id("halberd");
      break;
    case 7:
      obj->set_weight(10);
      obj->set_wc(1,8);
      obj->set_large_wc(2,5);
      obj->set_type("slash");
      obj->set_weapon_speed(8);
      obj->add_id("partisan");
      break;
    case 8:
      obj->set_weight(10);
      obj->set_wc(1,6);
      obj->set_large_wc(2,6);
      obj->set_type("pierce");
      obj->set_weapon_speed(8);
      obj->add_id("spetum");
      break;
    case 9:
      obj->set_weight(10);
      obj->set_wc(2,4);
      obj->set_large_wc(2,4);
      obj->set_type("slash");
      obj->set_weapon_speed(8);
      obj->add_id("voulge");
      break;
    case 10:
      obj->set_weight(11);
      obj->set_wc(2,7);
      obj->set_large_wc(2,8);
      obj->set_type("slash");
      obj->set_weapon_speed(6);
      obj->add_id("scythe");
      break;
    case 11:
      obj->set_weight(12);
      obj->set_wc(2,4);
      obj->set_large_wc(2,6);
      obj->set_type("slash");
      obj->set_weapon_speed(8);
      obj->add_id("bardiche");
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
  switch(which) {
    case 0..2:
      obj->set_size(1);
      obj->set_weight(2);
      obj->set_wc(1,4);
      obj->set_large_wc(1,3);
      obj->set_type("piercing");
      obj->set_prof_type("small blades");
      obj->set_weapon_speed(2);
      break;
    case 3:
      obj->set_size(1);
      obj->set_weight(6);
      obj->set_wc(1,6);
      obj->set_large_wc(1,6);
      obj->set_type("pierce");
      obj->set_prof_type("short blades");
      obj->set_weapon_speed(5);
      obj->add_id("pick");
      break;
    case 4..5:
      obj->set_size(2);
      obj->set_weight(4);
      obj->set_wc(1,6);
      obj->set_large_wc(1,8);
      obj->set_type("pierce");
      obj->set_prof_type("spear");
      obj->set_weapon_speed(6);
      obj->add_id("spear");
      break;
    case 6:
      obj->set_size(1);
      obj->set_weight(4);
      obj->set_wc(2,3);
      obj->set_large_wc(2,4);
      obj->set_type("slashing");
      obj->set_prof_type("short blades");
      obj->set_weapon_speed(3);
      obj->add_id("sword");
      break;
    case 7:
      obj->set_size(3);
      obj->set_weight(6);
      obj->set_wc(2,4);
      obj->set_large_wc(2,5);
      obj->set_type("pierce");
      obj->set_prof_type("spear");
      obj->set_weapon_speed(10);
      obj->add_id("spear");
      break;
    case 8:
      obj->set_size(3);
      obj->set_weight(7);
      obj->set_wc(1,8);
      obj->set_large_wc(2,4);
      obj->set_type("pierce");
      obj->set_prof_type("spear");
      obj->set_weapon_speed(7);
      obj->add_id("fork");
      break;
    case 9:
      obj->set_size(3);
      obj->set_weight(6);
      obj->set_wc(1,8);
      obj->set_large_wc(3,4);
      obj->set_type("pierce");
      obj->set_prof_type("spear");
      obj->set_weapon_speed(7);
      obj->add_id("trident");
      break;
    case 10:
      obj->set_size(1);
      obj->set_weight(3);
      obj->set_wc(1,6);
      obj->set_large_wc(2,4);
      obj->set_type("slashing");
      obj->set_prof_type("small blades");
      obj->set_weapon_speed(4);
      obj->add_id("sickle");
      break;
    case 11:
      obj->set_size(2);
      obj->set_weight(8);
      obj->set_wc(1,8);
      obj->set_large_wc(1,8);
      obj->set_type("slash");
      obj->set_prof_type("axe");
      obj->set_weapon_speed(7);
      break;
    case 12:
      obj->set_size(1);
      obj->set_weight(5);
      obj->set_wc(1,6);
      obj->set_large_wc(1,4);
      obj->set_type("slashing");
      obj->set_prof_type("axe");
      obj->set_weapon_speed(4);
      break;
    case 13:
      obj->set_size(2);
      obj->set_weight(10);
      obj->set_wc(1,8);
      obj->set_large_wc(2,5);
      obj->set_type("slash");
      obj->set_prof_type("axe");
      obj->set_weapon_speed(7);
      break;
    case 14:
      obj->set_size(3);
      obj->set_weight(10);
      obj->set_wc(3,4);
      obj->set_large_wc(3,4);
      obj->set_type("slash");
      obj->set_prof_type("axe");
      obj->set_weapon_speed(8);
      break;
    case 15:
      obj->set_size(1);
      obj->set_weight(4);
      obj->set_wc(2,3);
      obj->set_large_wc(2,4);
      obj->set_type("slashing");
      obj->set_prof_type("rapier");
      obj->set_weapon_speed(3);
      break;
    case 16..17:
      obj->set_size(2);
      obj->set_weight(10);
      obj->set_wc(1,8);
      obj->set_large_wc(1,10);
      obj->set_type("slashing");
      obj->set_prof_type("medium blades");
      obj->set_weapon_speed(5);
      obj->add_id("sword");
      break;
    case 18..21:
      obj->set_size(2);
      obj->set_weight(8);
      obj->set_wc(1,8);
      obj->set_large_wc(2,5);
      obj->set_type("slash");
      obj->set_prof_type("medium blades");
      obj->set_weapon_speed(5);
      obj->add_id("sword");
      break;
    case 22:
      obj->set_size(1);
      obj->set_weight(5);
      obj->set_wc(1,5);
      obj->set_large_wc(1,4);
      obj->set_type("slashing");
      obj->set_prof_type("knuckles");
      obj->set_weapon_speed(4);
      break;
    case 23:
      obj->set_size(1);
      obj->set_weight(10);
      obj->set_wc(1,6);
      obj->set_large_wc(1,12);
      obj->set_type("pierce");      //need to set type ???????**
      obj->set_prof_type("lance");
      obj->set_property("lance",1);
      obj->set_weapon_speed(8);
      break;
    case 24..26:
      obj->set_size(3);
      obj->set_weight(15);
      obj->set_wc(3,4);
      obj->set_large_wc(3,6);
      obj->set_type("slash");
      obj->set_prof_type("large blades");
      obj->set_weapon_speed(10);
      obj->add_id("sword");
      break;
    case 27:
      obj->set_size(2);
      obj->set_weight(3);
      obj->set_wc(1,8);
      obj->set_large_wc(1,6);
      obj->set_type("bludgeoning");
      obj->set_prof_type("clublike");
      obj->set_weapon_speed(4);
      break;
    case 28:
      obj->set_size(3);
      obj->set_weight(10);
      obj->set_wc(1,8);
      obj->set_large_wc(2,5);
      obj->set_type("bludgeoning");
      obj->set_prof_type("clublike");
      obj->set_weapon_speed(6);
      break;
    case 29:
      obj->set_size(2);
      obj->set_weight(15);
      obj->set_wc(1,6);
      obj->set_large_wc(2,4);
      obj->set_type("bludgeoning");
      obj->set_prof_type("flail");
      obj->set_weapon_speed(7);
      obj->add_id("flail");
      break;
    case 30:
      obj->set_size(2);
      obj->set_weight(10);
      obj->set_wc(1,8);
      obj->set_large_wc(1,8);
      obj->set_type("bludgeoning");
      obj->set_prof_type("mace");
      obj->set_weapon_speed(6);
      obj->add_id("mace");
      break;
    case 31:
      obj->set_size(2);
      obj->set_weight(12);
      obj->set_wc(2,4);
      obj->set_large_wc(1,6);
      obj->set_type("bludgeoning");
      obj->set_prof_type("mace");
      obj->set_weapon_speed(7);
      obj->add_id("morning star");
      break;
    case 32: 
      obj->set_size(2);
      obj->set_weight(10);
      obj->set_wc(1,8);
      obj->set_large_wc(1,8);
      obj->set_type("bludgeoning");
      obj->set_prof_type("hammer");
      obj->set_weapon_speed(5);
      obj->add_id("hammer");
      break;
    case 33: 
      obj->set_size(3);
      obj->set_weight(15);
      obj->set_wc(2,5);
      obj->set_large_wc(2,6);
      obj->set_type("bludgeoning");
      obj->set_prof_type("hammer");
      obj->set_weapon_speed(8);
      obj->add_id("hammer");
      break;
    case 34:
      obj->set_size(3);
      obj->set_weight(6);
      obj->set_wc(2,4);
      obj->set_large_wc(2,5);
      obj->set_type("bludgeoning");
      obj->set_prof_type("staff");
      obj->set_weapon_speed(4);
      obj->add_id("staff");
      break;
    case 35:
      obj->set_size(2);
      obj->set_weight(3);
      obj->set_wc(1,6);
      obj->set_large_wc(1,6);
      obj->set_type("bludgeoning");
      obj->set_prof_type("staff");
      obj->set_weapon_speed(3);
      obj->add_id("staff");
      break;
   case 36:
      obj->set_size(2);
      obj->set_weight(2);
      obj->set_wc(1,6);
      obj->set_large_wc(1,6);
      obj->set_type("lash");
      obj->set_prof_type("whip");
      obj->set_weapon_speed(8);
      obj->add_id("whip");
      break;
   case 37:
      obj->set_size(2);
      obj->set_weight(2);
      obj->set_wc(2,3);
      obj->set_large_wc(2,3);
      obj->set_type("lash");
      obj->set_prof_type("whip");
      obj->set_weapon_speed(5);
      obj->add_id("scourge");
      break;
   case 38:
      obj->set_size(1);
      obj->set_weight(3);
      obj->set_wc(1,5);
      obj->set_large_wc(1,3);
      obj->set_type("piercing");
      obj->set_prof_type("fan");
      obj->set_weapon_speed(3);
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
     case "clublike" :
        obj->set_short("%^RESET%^An exquisite "+metal+" spiked %^RESET%^"+wood+" "
           +what+"%^RESET%^");
        obj->set_long("This is a rare and exquisitely crafted "+wood+" "+
           what+"%^RESET%^.  It has "+metal+" spikes and banding%^RESET%^ "
           "clearly designed to make it sturdier and do more damage.");
        obj->add_id("club");
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
        obj->add_id("axe");
        break;
     case "fan" :
        obj->set_short("%^RESET%^An exquisite "+metal+" "+what+" %^RESET%^with "
          "a jeweled grip");
        obj->set_long("This is an exquisitely crafted "+metal+" "+what+
           "%^RESET%^.  "
           "The ornate grip is set with "+gem+" and "+gem2+", and the paper is "
           "patterned with ancient mystical runes.  The ribs are honed to "
           "extremely sharp tips.");
        obj->add_id("fan");
        break;
     case "knuckles" :
        obj->set_short("%^RESET%^An exquisite "+metal+" "+what+" %^RESET%^with "
          "a jeweled guard");
        obj->set_long("This is an exquisitely crafted "+metal+" "+what+
           "%^RESET%^.  "
           "The ornate guard is set with "+gem+" and "+gem2+".  The long tines "
           "are etched with ancient mystical runes, and honed to an extremely "
           "sharp edge.");
        obj->add_id("claw");
        break;
   }
   flag = 0;
   switch(random(100)){
      case 0..5: 
         enchant = 1;
         break;
      case 6..30: 
         enchant = 2;
         flag += random(2);
         break;
      case 31..79: 
         enchant = 3;
         flag += random(3);
         break;
      case 80..96: 
         enchant = 4;
         flag += random(4);
         break;
      case 97..99: 
         enchant = 5;
         flag += random(5);
         break;
   }
   obj->set_property("enchantment",enchant);
//   obj->set_property("flag", flag);
   if(flag < 0) flag = 0;
   obj->set_value( (flag * 1000) + ((random(5)+1)*500) );
}

set_weight(int x) {
   //::set_weight(x);
   my_weight = x;
}

query_weight() {
   return my_weight;
}
