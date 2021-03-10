// random low level trainer type to wander in the newbie area by *Styx*  8/2002
// add others as the nwps go in?
// /d/newbie/rooms/town/square.c loads it and place_d will dump clones there
// changed to be loaded by daemon/monster_d and move file to /d/npc *Styx*  12/21/03
// removed the disguise nwp from the trainer since the NWP is suspenced. Nienne, 02/07

#include <std.h>

inherit NPC;

void make_me();

void create(){
   ::create();
   make_me();
   set_body_type("human");
   set_hd(20,8);
   set_max_level(10);
   set_size(2);
   set_alignment(8);
   set_overall_ac(4);
   set_max_hp(random(20)+60);
   set_hp(query_max_hp());
   set_exp(100);
   set_level(20);
   set_class("mage");
   set_mlevel("mage",15);
   set_guild_level("mage",15);
   set_stats("intelligence", 18);
   set_stats("wisdom", 15);
   set_stats("strength", 18);
   set_stats("charisma", 15);
   set_stats("dexterity", 16);
   set_stats("constitution", 15);
   set_mob_magic_resistance("average");
   set_property("alignment adjustment",-1);
   set_speed(80);
   set_spell_chance(90);
   set_spells(({"hold person","hold person","lightning bolt", "magic missile", "magic missile"}));
/*  moving this to the newbie town square to be consistent with the others *Styx* 1/15/03
   switch(random(3)) {
      case 0: "/daemon/place_d"->place_in("/d/newbie/rooms/forest/",TO);
               break;
      case 1: "/daemon/place_d"->place_in("/d/newbie/rooms/hill/",TO);
              break;
      case 2: "/daemon/place_d"->place_in("/d/newbie/rooms/road/",TO);
              break;
   }
*/
}

void init(){
   ::init();
}

void make_me() {
   switch(random(5)) {
     case 0:
        set_nwp("escape", 5, 500);
   	set_name("Stearel");
	set_id(({"stearel","Stearel","trainer", "wanderer" }));
	set_short("Stearel, a wanderer");
	set_long("Stearel appears to be in her mid-twenties, although it "
	   "appears she has led a difficult life in that short time.  She "
	   "has numerous scars on her lower arms and a few on her face.  "
	   "She seems to be traveling light, wearing a simple blue tunic "
	   "over dark brown breeches that tuck into her boots.");
	set_gender("female");
	set_race("half-elf");
        break;
     case 1:
        set_nwp("forage", 5, 500);
   	set_name("Mardan");
	set_id(({"mardan","Mardan","trainer", "wanderer"}));
	set_short("Mardan, a wanderer");
	set_long("Mardan is a small, lithe man with dark brown hair and "
	   "deep blue eyes.  He wears a backpack that smells of herbs "
	   "and carries a basket that is overflowing with fruits and nuts.  "
	   "His hands and arms are scratched, perhaps from struggling with "
	   "brambles and digging through undergrowth to gather berries and "
	   "such.");
	set_gender("male");
	set_race("human");
        break;
     case 2:
        set_nwp("skinning", 5, 500);
   	set_name("Trundulm");
	set_id(({"trundulm","Trundulm","trainer"}));
	set_short("Trundulm, a wanderer");
	set_long("Trundulm appears to have spent most of his life "
	   "outdoors.  His weatherworn skin and graying auburn hair "
	   "lead you to guess he's in his fifties.  His thick, unkempt "
           "curly beard gives him a somewhat barbaric appearance.  "
	   "He wears simple leather clothing that has stains that look "
           "like dried blood.  There is a pouch around his "
	   "waist and some furs hanging from his belt.  You see the "
	   "hilt of what looks to be a very sturdy looking knife "
	   "sticking out of a small sheath tied on his thigh.");
	set_gender("male");
	set_race("dwarf");
        break;
     case 3:
        set_nwp("hunting", 5, 500);
   	set_name("Jarduen");
	set_id(({"jarduen","Jarduen","trainer"}));
	set_short("Jarduen, a wanderer");
	set_long("Jarduen has a bow slung over his shoulder and a sheath "
	  "for a longsword at his side.  He is dressed in dark leather "
	  "breeches, a doeskin shirt, and wears knee high boots that "
	  "have clearly seen a lot of wear.  He has what looks like the "
	  "teeth and pieces of bone, tusks, and antlers strung from a "
	  "thin strip of leather dangling from his belt, perhaps trophies.");
	set_gender("male");
	set_race("human");
        break;
	case 4:
//          set_nwp("disguise", 5, 500);
	set_name("lillian");
	set_short("Lillian Fardell, travelling bard");
	set_id(({"lillian","Lillian Fardell","bard"}));
	set_long("%^CYAN%^Dressed in a motley array of "+
		"colors and patterns, Lillian looks festive "+
		"and merry.  Her %^RED%^p%^MAGENTA%^a%^BLUE%^t%^YELLOW%^"+
		"c%^WHITE%^h%^CYAN%^w%^BLACK%^o%^BLUE%^r%^MAGENTA%^k"+
		"%^RESET%^%^CYAN%^ robe features such rich fabrics "+
		"as velvet and silk with beaded and metallic trims.  "+
		"Her %^BOLD%^%^WHITE%^silver%^RESET%^%^CYAN%^ streaked"+
		" %^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^ hair is "+
		"pulled into a snood that rests at the base of her "+
		"neck.  A regal looking instrument case is slung onto"+
		" one of her shoulders.  This middle aged woman it is"+
		" said got her start as an actress before following her"+
		" heart and becoming a songstress.  Such a rare treat "+
		"that such an accomplished bard to find her way here!.");
	set_gender("female");
	set_race("half-elf");
        set_emotes(2, ({"%^BOLD%^%^RED%^Lillian hums the chorus from a cheerful song.","%^BOLD%^%^BLACK%^Lillian smiles graciously to a fan who waves at her.","%^RED%^Lillian stops to write down something in her journal."}), 0);
	break;
   }    
  return;
}     
