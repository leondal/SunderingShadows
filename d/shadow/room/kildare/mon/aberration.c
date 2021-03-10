//aberration.c - new monster for Kildare Glen
//expanding to include the sister everyone seems so interested in ;)
//~Circe~ 6/3/07

#include <std.h>

inherit WEAPONLESS;

void make_me();
void class_me();
int dlvl;
object ob;

void create() {
   ::create();
   dlvl = 8+random(4);
   make_me();
   class_me();
   set_name("peryton aberration");
   set_race("peryton aberration");
   set_body_type("fowl");
   set_size(2);
   set_alignment(9);
   set_overall_ac(0);
   set_hd(dlvl,6);
   set_level(dlvl);
   set_hp(random(75)+125);
   set_max_hp(query_hp());
   set_damage(1,6);
   set_attacks_num(2);
   set_base_damage_type("slashing");
   set_property("swarm",1);
   set("aggressive",18);
   set_stats("strength",17);
   set_max_level(15);  
   set_exp(300*dlvl);   
   add_money("gold",random(150)+25);
   set_mob_magic_resistance("average");
}

void make_me(){
   switch(random(4)){
      case 0:  set_gender("female");
               set_short("A twisted bird-woman");
               set_id(({"monster","peryton","aberration","peryton aberration","woman","bird woman","bird-woman","kildare_mon"}));
               set_long("This twisted creation is a strange mixture of "+
                  "%^BOLD%^woman%^RESET%^%^CYAN%^, %^YELLOW%^bird%^RESET%^%^CYAN%^, "+
                  "and %^ORANGE%^stag%^CYAN%^.  She has the lower legs of "+
                  "a %^ORANGE%^stag%^CYAN%^, complete with vicious-looking "+
                  "%^BOLD%^%^BLACK%^black hooves%^RESET%^%^CYAN%^.  Her "+
                  "torso is that of a %^BOLD%^woman%^RESET%^%^CYAN%^, though "+
                  "it is covered with %^GREEN%^m%^CYAN%^o%^GREEN%^t%^CYAN%^t"+
                  "%^GREEN%^l%^CYAN%^e%^GREEN%^d feathers %^CYAN%^that "+
                  "give her a sickly, unkempt appearance.  Her face is "+
                  "dominated by a large %^YELLOW%^beak %^RESET%^%^CYAN%^"+
                  "and topped by %^ORANGE%^antlers %^CYAN%^peeking out "+
                  "from a strange mass of %^BOLD%^%^BLACK%^black curls "+
                  "%^RESET%^%^CYAN%^and %^GREEN%^green feathers%^CYAN%^.");
               add_limb("right arm","torso",0,0,0);
               add_limb("right hand","right arm",0,0,0);
               add_limb("left arm","torso",0,0,0);
               add_limb("left hand","left arm",0,0,0);
               add_limb("horns","head",0,0,0);
               set_attack_limbs(({"right hand","left hand","beak","horns"}));
               remove_limb("right wing");
               remove_limb("left wing");
               break;
      case 1:  set_gender("female");
               set_short("A twisted stag-woman");
               set_id(({"monster","peryton","aberration","peryton aberration","woman","stag woman","stag-woman","kildare_mon"}));
               set_long("More stag than woman, this wretched creature "+
                  "has back legs like a %^ORANGE%^stag %^CYAN%^and "+
                  "front arms like a %^BOLD%^human woman%^RESET%^"+
                  "%^CYAN%^, but she walks on all fours.  Her "+
                  "face is a horrid mess of %^GREEN%^m%^CYAN%^o%^GREEN%^t%^CYAN%^t"+
                  "%^GREEN%^l%^CYAN%^e%^GREEN%^d feathers %^CYAN%^"+
                  "on a %^ORANGE%^stag's muzzle%^CYAN%^, and it is "+
                  "impossible to tell if she has any sort of "+
                  "expression - or thought - at all.  Useless "+
                  "%^RESET%^wings %^CYAN%^sprout from her back, "+
                  "serving to add to the confusion of what, "+
                  "exactly, she is.");
               add_limb("right arm","torso",0,0,0);
               add_limb("right hand","right arm",0,0,0);
               add_limb("left arm","torso",0,0,0);
               add_limb("left hand","left arm",0,0,0);
               add_limb("mouth","head",0,0,0);
               set_attack_limbs(({"right hand","left hand","mouth","horns"}));
               remove_limb("beak");
               break;
      case 3:  set_gender("neuter");
               set_short("A twisted aberration");
               set_id(({"monster","peryton","aberration","peryton aberration","kildare_mon"}));
               set_long("This unfortunate creature seems the stuff of "+
                  "nightmares.  Its twisted body is a mass of patches "+
                  "of %^ORANGE%^fur%^CYAN%^, %^BOLD%^feathers%^RESET%^"+
                  "%^CYAN%^, and %^BOLD%^%^MAGENTA%^pale skin%^RESET%^"+
                  "%^CYAN%^.  It has several single %^RESET%^wings "+
                  "%^CYAN%^sprouting from its frame, along with "+
                  "several %^BOLD%^%^BLACK%^clawed appendages%^RESET%^"+
                  "%^CYAN%^.  It seems to be shaped like nothing, "+
                  "but it manages to move on a few stronger limbs.  "+
                  "It has a %^ORANGE%^beak %^CYAN%^in the center of "+
                  "its body and several %^BOLD%^%^BLACK%^beady eyes"+
                  "%^RESET%^%^CYAN%^, but no face to speak of.");
               add_limb("middle claw","torso",0,0,0);
               remove_limb("right wing");
               remove_limb("left wing");
               set_attack_limbs(({"right claw","left left","middle claw","beak"}));
               break;
      default:  set_gender("male");
               set_short("A twisted man-bird");
               set_id(({"monster","peryton","aberration","peryton aberration","man","man-bird","man bird","kildare_mon"}));
               set_long("This wretched creature seems to be almost entirely "+
                  "some type of giant bird, much like an eagle.  His face "+
                  "bears no resemblance to a human, shaped as a bird's "+
                  "and covered completely in %^RESET%^white feathers%^CYAN%^.  "+
                  "A dull, sharp %^BOLD%^%^BLACK%^beak %^RESET%^%^CYAN%^"+
                  "extends from beneath its %^BOLD%^%^BLUE%^blue eyes "+
                  "%^RESET%^%^CYAN%^- the only sign of humanity on this "+
                  "twisted beast.  Instead of claws, the man-bird's "+
                  "muscular legs are %^ORANGE%^furred %^CYAN%^and end "+
                  "in %^BOLD%^%^BLACK%^hooves%^RESET%^%^CYAN%^.  He "+
                  "has what seems to be a second set of non-functioning "+
                  "wings growing from his feathered chest.");
               remove_limb("right claw");
               remove_limb("left claw");
               add_limb("right hoof","right leg",0,0,0);
               add_limb("left hoof","left leg",0,0,0);
               set_attack_limbs(({"right hoof","left hoof","beak"}));
               break;
   }
}


void class_me(){
   switch(random(8)){
      case 0..1:  set_class("cleric");
               set_mlevel("cleric",dlvl);
               set_guild_level("cleric",dlvl);
               add_search_path("/cmds/priest/");
               set_spells(({"limb attack","limb attack","cause moderate wounds","cause moderate wounds","cause light wounds"}));
               set_spell_chance(25);
               break;
      case 2..3:  set_class("mage");
               set_mlevel("mage",dlvl);
               set_guild_level("mage",dlvl);
               add_search_path("/cmds/wizard");
               set_spells(({"acid orb","frost orb","sonic orb","lightning orb","magic missile","magic missile","magic missile","scorcher"}));
               set_spell_chance(25);
               break;
      default:  set_class("fighter");
                set_mlevel("fighter",dlvl);
                set_property("full attacks",1);
                break;
   }
}
