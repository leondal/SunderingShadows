// Random magic weapon generator coded by Bane@Shadowgate
// rweapon.c, changed to n_rweap_d.c & moved to /d/common/daemon to adj. values
//    by Styx 6/2002
// note: these weapons cant be replaced, so if someone loses one
// that weapon is lost forever, you can clone a new one for them
// but it will be totally different.
//This file was modified by Crystal
// After some people got 200k plus gold weapons and due to trying to reduce
// get rich quick situations, scaling back values significantly *Styx* 6/2002
//Added whip and scourge, changed rapier to its own prof
//and updated spear and short sword to the appropriate profs - Cythera 8/05
//Updated with feat profs and long descript - Octothorpe 10/30/09

#include <std.h>
#include <daemons.h>

#define COLOR ({"%^RESET%^%^ORANGE%^amber%^RESET%^",\
"%^BOLD%^%^BLUE%^blue%^RESET%^",\
"%^BOLD%^%^WHITE%^white%^RESET%^",\
"%^BOLD%^%^BLACK%^black%^RESET%^",\
"%^BOLD%^%^GREEN%^jade%^RESET%^",\
"%^YELLOW%^brass%^RESET%^",\
"%^RESET%^%^ORANGE%^bronze%^RESET%^",\
"%^RESET%^%^RED%^crimson",\
"%^BOLD%^%^CYAN%^crystal%^RESET%^",\
"%^BOLD%^%^WHITE%^diamond%^RESET%^",\
"%^GREEN%^em%^BOLD%^e%^RESET%^%^GREEN%^rald%^RESET%^",\
"%^YELLOW%^go%^RESET%^%^ORANGE%^ld%^BOLD%^en%^RESET%^",\
"%^BOLD%^%^WHITE%^iv%^YELLOW%^o%^WHITE%^ry%^RESET%^",\
"%^RESET%^%^BLUE%^iron%^RESET%^",\
"%^RESET%^%^CYAN%^steel%^RESET%^",\
"%^BOLD%^%^CYAN%^mithril%^RESET%^",\
"%^BOLD%^%^BLACK%^obsidian%^RESET%^",\
"%^BOLD%^%^BLACK%^onyx%^RESET%^",\
"%^BOLD%^%^WHITE%^pearl%^RESET%^",\
"%^BOLD%^%^WHITE%^platinum%^RESET%^",\
"%^BOLD%^%^RED%^red%^RESET%^",\
"%^BOLD%^%^BLUE%^sapphire%^RESET%^",\
"%^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r%^RESET%^",\
"%^YELLOW%^topaz%^RESET%^",\
"%^RESET%^%^RED%^garnet%^RESET%^",\
"%^RESET%^%^ORANGE%^s%^RESET%^t%^BOLD%^%^BLACK%^o%^RESET%^n%^ORANGE%^e%^RESET%^",\
"%^BOLD%^%^WHITE%^bone%^RESET%^",\
"%^BOLD%^%^WHITE%^quartz%^RESET%^",\
"%^BOLD%^%^RED%^ruby%^RESET%^",\
"%^BOLD%^%^WHITE%^o%^CYAN%^p%^MAGENTA%^a%^WHITE%^l%^RESET%^"})

#define PREFIX ({"angels","arch-angels","brutal","champions",\
"deadly","fine","glorious","godly","kings","knights","lords","masters",\
"grand","merciless","ruthless","savage","soldiers","valiant","inhuman",\
"defenders","protectors","lethal","fatal","exceptional","exquisite",\
"splendid","celestial","divine","relentless","malicious","gladiators"})

#define SUFFIX ({"of the dragon","of the drake","of the hydra","of the serpent",\
"of the snake","of the wyrm","of the ages","of the bear","of blood",\
"of brilliance","of burning","of carnage","of corruption",\
"of the dark","of the eagle","of fire","of flame","of giants",\
"of gore","of harmony","of the heavens","of hell","of hades",\
"of the abyss","of the jackal","of lightning","of the lion",\
"of maiming","of the mammoth","of might","of the moon","of the night",\
"of tears","of thunder","of the tiger","of titans","of pain",\
"of perfection","of power","of the sky","of slaughter","of slaying",\
"of speed","of the stars","of strength","of thorns","of the vampire",\
"of the lich","of vileness","of the wolf","of deception","of craft",\
"of horror","of wisdom","of the dead","of force","of the undead",\
"of truth","of the skull","of the storm","of doom","of massacre","of nightmares"})

#define WEAPONS ({"dagger","dirk","knife","footmans pick","spear",\
"short sword","harpoon","javelin","awl pike","bec de corbin",\
"bill-guisarme","fauchard","fauchard-fork","glaive-guisarme",\
"guisarme-voulge","halberd","hook fauchard","military fork",\
"partisan","spetum","ranseur","trident","sickle","battle axe",\
"hand axe","broad axe","great axe","khopesh","bastard sword",\
"long sword","scimitar","falchion","sabre","rapier",\
"bardiche","glaive","guisarme","voulge","two handed sword",\
"great sword","claymore","club","flail","mace","morning star",\
"warhammer","quarterstaff","maul","scourge","whip"})

inherit DAEMON;

string type1,
 name,
 blah,
 prefix,
 color,
 suffix;

int enchant, flag, a, b, c, d, my_weight;

void create() {
	::create();
}

void create_weapon(object obj) {
   a = random(sizeof(WEAPONS));
   type1 = WEAPONS[a];
// adding flag = 1 here to insure it's not compounding with each creation
   flag = 1;
   if(random(2)){
      b = random(sizeof(COLOR));
      color = COLOR[b];
      flag += random(2);
   } 
   else {
      color = 0;
   }
   if(random(2)){
      c = random(sizeof(PREFIX));
      prefix = PREFIX[c];
      flag += random(2);
   } 
   else {
      prefix = 0;
   }
   if(random(2)){
      d = random(sizeof(SUFFIX));
      suffix = SUFFIX[d];
      flag += random(2);
   } 
   else {
      suffix = 0;
   }
   obj->set_id(({type1,prefix,color,"weapon","rweapon"}));
   name = 0;
   if(prefix){
      if(color) name = prefix;
      if(!color) name = prefix+" "+type1;
   }
   if(color){
      if(!prefix) name = color+" "+type1;
      if(prefix) name = name+" "+color+" "+type1;
   }
   if(!name) name = type1;
   if(suffix){
      name = name+" "+suffix;
   }
    obj->set_name(type1);
   blah = "A";
   if(prefix){
      if(member_array(prefix[0],({'a','e','i','o','u'})) != -1) blah = "An";
   }
   if(!prefix){
      if(color){
         if(member_array(color[0],({'a','e','i','o','u'})) != -1) blah = "An";
      }
   }
   if(!prefix){
      if(!color){
         if(type1 == "awl pike") blah = "An";
      }
   }
   obj->set_short(blah+" "+name);
    obj->set_obvious_short(type1);
   obj->set_long("%^BOLD%^%^WHITE%^This is a well-crafted weapon which "+
      "is rumored to hail from the Astral Plane, and beyond.%^RESET%^");
 switch(a) {
   case 0..2:
      obj->set_size(1);
      obj->set_weight(1);
      obj->set_wc(1,4);
      obj->set_large_wc(1,4);
      obj->set_type("piercing");
      //obj->set_prof_type("small blades");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(2);
      break;
   case 3:
      obj->set_size(2);
      obj->set_weight(4);
      obj->set_wc(1,4)+1;
      obj->set_large_wc(1,4);
      obj->set_type("pierce");
      //obj->set_prof_type("tool");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(7);
      break;
   case 4:
      obj->set_size(2);
      obj->set_weight(5);
      obj->set_wc(1,6);
      obj->set_large_wc(1,8);
      obj->set_type("pierce");
      //obj->set_prof_type("spear");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(6);
      break;
   case 5:
      obj->set_size(1);
      obj->set_weight(5);
      obj->set_wc(2,3);
      obj->set_large_wc(2,3);
      obj->set_type("slashing");
      //obj->set_prof_type("short blades");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(3);
      break;
   case 6:
      obj->set_size(3);
      obj->set_weight(10);
      obj->set_wc(2,4);
      obj->set_large_wc(2,6);
      obj->set_type("pierce");
      //obj->set_prof_type("spear");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(7);
      break;
   case 7:
      obj->set_size(3);
      obj->set_weight(2);
      obj->set_wc(1,6);
      obj->set_large_wc(1,6);
      obj->set_type("pierce");
      //obj->set_prof_type("spear");
	  obj->set_weapon_prof("simple");
	  obj->set_weapon_speed(10);
      break;
   case 8:
      obj->set_size(3);
      obj->set_weight(12);
      obj->set_wc(1,6);
      obj->set_large_wc(1,12);
      obj->set_type("pierce");
      //obj->set_prof_type("polearm");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(13);
      break;
   case 9:
      obj->set_size(3);
      obj->set_weight(10);
      obj->set_wc(1,8);
      obj->set_large_wc(1,6);
      obj->set_type("pierce");
      //obj->set_prof_type("polearm");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(9);
      break;
   case 10:
      obj->set_size(3);
      obj->set_weight(15);
      obj->set_wc(2,4);
      obj->set_large_wc(1,10);
      obj->set_type("pierce");
      //obj->set_prof_type("polearm");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(10);
      break;
   case 11:
      obj->set_size(3);
      obj->set_weight(7);
      obj->set_wc(1,6);
      obj->set_large_wc(1,8);
      obj->set_type("pierce");
      //obj->set_prof_type("polearm");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(8);
      break;
   case 12:
      obj->set_size(3);
      obj->set_weight(9);
      obj->set_wc(1,8);
      obj->set_large_wc(1,10);
      obj->set_type("pierce");
      //obj->set_prof_type("fork");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(8);
      break;
   case 13:
      obj->set_size(3);
      obj->set_weight(10);
      obj->set_wc(2,4);
      obj->set_large_wc(2,6);
      obj->set_type("pierce");
      //obj->set_prof_type("polearm");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(9);
      break;
   case 14:
      obj->set_size(3);
      obj->set_weight(15);
      obj->set_wc(2,4);
      obj->set_large_wc(2,4);
      obj->set_type("pierce");
      //obj->set_prof_type("polearm");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(10);
      break;
   case 15:
      obj->set_size(3);
      obj->set_weight(15);
      obj->set_wc(1,10);
      obj->set_large_wc(2,6);
      obj->set_type("pierce");
      //obj->set_prof_type("polearm");
	  obj->set_weapon_prof("exotic");
	  obj->set_weapon_speed(11);
      break;
   case 16:
      obj->set_size(3);
      obj->set_weight(8);
      obj->set_wc(1,4);
      obj->set_large_wc(1,4);
      obj->set_type("pierce");
      //obj->set_prof_type("polearm");
	  obj->set_weapon_prof("exotic");
	  obj->set_weapon_speed(12);
      break;
   case 17:
      obj->set_size(3);
      obj->set_weight(7);
      obj->set_wc(1,8);
      obj->set_large_wc(2,4);
      obj->set_type("pierce");
      //obj->set_prof_type("fork");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(7);
      break;
   case 18:
      obj->set_size(3);
      obj->set_weight(8);
      obj->set_wc(1,6);
      obj->set_large_wc(1,6)+1;
      obj->set_type("pierce");
      //obj->set_prof_type("polearm");
	  obj->set_weapon_prof("exotic");
	  obj->set_weapon_speed(10);
      break;
   case 19:
      obj->set_size(3);
      obj->set_weight(7);
      obj->set_wc(1,6)+1;
      obj->set_large_wc(2,6);
      obj->set_type("pierce");
      //obj->set_prof_type("polearm");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(8);
      break;
   case 20:
      obj->set_size(3);
      obj->set_weight(15);
      obj->set_wc(2,4);
      obj->set_large_wc(2,4);
      obj->set_type("pierce");
      //obj->set_prof_type("polearm");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(10);
      break;
   case 21:
      obj->set_size(3);
      obj->set_weight(5);
      obj->set_wc(1,6)+1;
      obj->set_large_wc(3,4);
      obj->set_type("pierce");
      //obj->set_prof_type("fork");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(7);
      break;
   case 22:
      obj->set_size(1);
      obj->set_weight(3);
      obj->set_wc(1,4)+1;
      obj->set_large_wc(1,4);
      obj->set_type("slashing");
      //obj->set_prof_type("tool");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(4);
      break;
   case 23:
      obj->set_size(2);
      obj->set_weight(8);
      obj->set_wc(1,8);
      obj->set_large_wc(1,8);
      obj->set_type("slash");
      //obj->set_prof_type("medium axe");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(7);
      break;
   case 24:
      obj->set_size(1);
      obj->set_weight(5);
      obj->set_wc(1,6);
      obj->set_large_wc(1,4);
      obj->set_type("slashing");
      //obj->set_prof_type("small axe");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(4);
      break;
   case 25..26:
      obj->set_size(2);
      obj->set_weight(10);
      obj->set_wc(1,8);
      obj->set_large_wc(1,12);
      obj->set_type("slashing");
      //obj->set_prof_type("medium axe");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(7);
      break;
   case 27:
      obj->set_size(2);
      obj->set_weight(7);
      obj->set_wc(2,4);
      obj->set_large_wc(1,6);
      obj->set_type("slashing");
      //obj->set_prof_type("medium blades");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(9);
      break;
   case 28..29:
      obj->set_size(2);
      obj->set_weight(10);
      obj->set_wc(1,8);
      obj->set_large_wc(1,12);
      obj->set_type("slashing");
      //obj->set_prof_type("medium blades");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(5);
      break;
   case 30..32:
      obj->set_size(2);
      obj->set_weight(8);
      obj->set_wc(1,8);
      obj->set_large_wc(1,8);
      obj->set_type("slash");
      //obj->set_prof_type("medium blades");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(5);
      break;
   case 33:
      obj->set_size(1);
      obj->set_weight(4);
      obj->set_wc(2,3);
      obj->set_large_wc(2,4);
      obj->set_type("piercing");
      //obj->set_prof_type("rapier");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(4);
      break;
   case 34:
      obj->set_size(3);
      obj->set_weight(12);
      obj->set_wc(2,4);
      obj->set_large_wc(2,6);
      obj->set_type("slash");
      //obj->set_prof_type("large axe");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(9);
      break;
   case 35:
      obj->set_size(3);
      obj->set_weight(8);
      obj->set_wc(1,6);
      obj->set_large_wc(1,10);
      obj->set_type("slash");
      //obj->set_prof_type("polearm");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(8);
      break;
   case 36:
      obj->set_size(3);
      obj->set_weight(8);
      obj->set_wc(2,4);
      obj->set_large_wc(1,8);
      obj->set_type("slash");
      //obj->set_prof_type("polearm");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(8);
      break;
   case 37:
      obj->set_size(3);
      obj->set_weight(12);
      obj->set_wc(2,4);
      obj->set_large_wc(2,4);
      obj->set_type("slash");
      //obj->set_prof_type("polearm");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(10);
      break;
   case 38..40:
      obj->set_size(3);
      obj->set_weight(15);
      obj->set_wc(1,10);
      obj->set_large_wc(3,6);
      obj->set_type("slash");
      //obj->set_prof_type("large blades");
	  obj->set_weapon_prof("exotic");
      obj->set_weapon_speed(8);
      break;
   case 41:
      obj->set_size(2);
      obj->set_weight(3);
      obj->set_wc(1,6);
      obj->set_large_wc(1,3);
      obj->set_type("bludgeoning");
      //obj->set_prof_type("medium clublike");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(4);
      break;
   case 42:
      obj->set_size(2);
      obj->set_weight(15);
      obj->set_wc(1,6)+1;
      obj->set_large_wc(2,4);
      obj->set_type("bludgeoning");
      //obj->set_prof_type("flail");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(7);
      break;
   case 43:
      obj->set_size(2);
      obj->set_weight(10);
      obj->set_wc(1,6)+1;
      obj->set_large_wc(1,6);
      obj->set_type("bludgeoning");
      //obj->set_prof_type("mace");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(7);
      break;
   case 44:
      obj->set_size(2);
      obj->set_weight(12);
      obj->set_wc(2,4);
      obj->set_large_wc(1,6)+1;
      obj->set_type("bludgeoning");
      //obj->set_prof_type("mace");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(7);
      break;
   case 45:
      obj->set_size(2);
      obj->set_weight(6);
      obj->set_wc(1,4)+1;
      obj->set_large_wc(1,4);
      obj->set_type("bludgeoning");
      //obj->set_prof_type("medium hammer");
	  obj->set_weapon_prof("martial");
      obj->set_weapon_speed(4);
      break;
   case 46:
      obj->set_size(3);
      obj->set_weight(15);
      obj->set_wc(1,6);
      obj->set_large_wc(1,6);
      obj->set_type("bludgeoning");
      //obj->set_prof_type("staff");
	  obj->set_weapon_prof("simple");
      obj->set_weapon_speed(4);
      break;
   case 47:
      obj->set_size(3);
      obj->set_weight(15);
      obj->set_wc(1,10);
      obj->set_large_wc(1,12);
      obj->set_type("bludgeoning");
      //obj->set_prof_type("large clublike");
	  obj->set_weapon_prof("simple");
	  obj->set_weapon_speed(6);
      break;
   case 48:
      obj->set_size(2);
      obj->set_weight(2);
      obj->set_wc(1,6);
      obj->set_large_wc(1,6);
      obj->set_type("lash");
      //obj->set_prof_type("whip");
	  obj->set_weapon_prof("exotic");
	  obj->set_weapon_speed(8);
      break;
   case 49:
      obj->set_size(2);
      obj->set_weight(4);
      obj->set_wc(2,3);
      obj->set_large_wc(2,3);
      obj->set_type("lash");
      //obj->set_prof_type("whip");
	  obj->set_weapon_prof("simple");
	  obj->set_weapon_speed(8);
      break;
 }
   switch(random(100)){
      case 0..14: 
         enchant = 1;
         break;
      case 15..29: 
         enchant = 2;
         flag += random(2);
         break;
      case 30..60: 
         enchant = 3;
         flag += random(4);
         break;
      case 61..89: 
         enchant = 4;
         flag += random(6);
         break;
      case 90..98: 
         enchant = 5;
         flag += random(8);
         break;
      case 99: 
         enchant = 6;
         flag += random(10);
         break;		 
   }
   obj->set_property("enchantment",enchant);
   if(flag < 0) flag = 0;
// changed this from flag * 2000 to flag * 300, still a nice value
// especially since they get a kit (if it's not all used) too
//Changing it back to *2000 for kicks - Octothorpe 10/30/09
   obj->set_value((flag * 2000) + 1000);
}

set_weight(int x) {
   //::set_weight(x);
   my_weight = x;
}

query_weight() {
   return my_weight;
}
