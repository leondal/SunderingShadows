// created by Tsera for Deku, 12/03 based on other multi-purpose trainers by *Styx*

#include <std.h>
inherit NPC;

void make_me();

void create(){
   ::create();
   make_me();
   set_body_type("human");
   set_hd(20,8);
   set_size(2);
   set_alignment(8);
   set_overall_ac(-1);
   set_max_hp(random(40)+100);
   set_hp(query_max_hp());
   set_exp(100);
   set_level(20);
   set_class("mage");
   set_mlevel("mage",20);
   set_guild_level("mage",20);
   set_stats("intelligence", 18);
   set_stats("wisdom", 15);
   set_stats("strength", 18);
   set_stats("charisma", 15);
   set_stats("dexterity", 16);
   set_stats("constitution", 15);
   set_mob_magic_resistance("average");
   set_speed(60);
   set_spell_chance(95);
   set_spells(({"lightning bolt","lightning bolt","magic
missile", "hideous laughter","fireball","fireball","cone of cold"}));
}

void init(){
   ::init();
}

void make_me() {
   switch(random(4)) {
      case 0:
         set_nwp("escape",12);
         set_name("Lanalai");
         set_id(({"Lanalai","lanalai","trainer","wanderer"}));
         set_short("Lanalai, a wanderer");
         set_long("%^RESET%^Lanalai is a slim human female who appears "
	  "to be in her early twenties.  Her wide, deep %^BOLD%^%^BLUE%^b%^RESET%^"
	  "%^BLUE%^l%^CYAN%^u%^BOLD%^%^CYAN%^e %^RESET%^eyes constantly shift "
	  "around and her lithe body moves with ease and fluidity.  She has thick, "
	  "%^YELLOW%^golden-blonde %^RESET%^hair that falls in wavy lengths to her "
	  "shoulders, brushing softly against her %^BOLD%^%^BLACK%^dark cape.  "
	  "%^RESET%^She wears a formfitting %^BOLD%^%^BLACK%^leather bodice "
	  "%^RESET%^over %^ORANGE%^tan %^RESET%^leggings that tuck into %^ORANGE%^"
	  "deerskin boots.  %^RESET%^Hanging from the small belt worn on her waist "
	  "is a %^ORANGE%^rope, %^RESET%^a %^BOLD%^%^BLACK%^net, %^RESET%^a small "
	  "bag of %^BOLD%^%^WHITE%^powder, %^RESET%^and various other tools of "
	  "entrapment.");
         set_gender("female");
         set_race("human");
         set_emotes(1,({
            "%^RESET%^%^ORANGE%^Lanalai ties a piece of rope around her wrists and then expertly struggles free of it.",
            "Lanalai absently plays with a %^ORANGE%^rope, %^RESET%^expertly twisting it around into impossible knots and then quickly undoing them."}),0);
         break;
      case 1:
         set_nwp("forage",12);
         set_name("Deldar");
         set_id(({"Deldar","deldar","trainer","wanderer"}));
         set_short("Deldar, a wanderer");
         set_long("%^RESET%^This fellow is a fuzzy little man who wears "
	  "%^ORANGE%^brown breeches %^RESET%^that look a little long for him with "
	  "bottom hems that are covered in %^BOLD%^%^BLACK%^mud.  %^RESET%^His feet "
	  "are bare but the only thing that you can see are his nubby little toes "
	  "sticking out from under his pants and their knuckles are quite hairy.  "
	  "His grey eyes are kind though, and he seems to not have any weapons on "
	  "his person whatsoever.  His fingers are stained red, as are a few of the "
	  "pouches worn on his body.  Oddly enough, he smells like freshly picked "
	  "%^BOLD%^%^RED%^b%^RESET%^%^RED%^er%^MAGENTA%^r%^RED%^ie%^BOLD%^%^RED%^s, "
	  "%^RESET%^and every once in a while a few %^ORANGE%^nuts %^RESET%^fall out "
	  "of another overflowing pouch.");
         set_gender("male");
         set_race("halfling");
         set_size(1);
         set_emotes(1,({
            "%^RESET%^%^GREEN%^Deldar sniffs around and then begins to poke around in some bushes.",
            "Deldar pulls a few %^ORANGE%^nuts %^RESET%^from his pouch and eats them hungrily."}),0);

         break;
      case 2:
         set_nwp("skinning",12);
      set_nwp("tracking",12);
         set_name("Chella");
         set_id(({"Chella","chella","wanderer","trainer"}));
         set_short("Chella, a wanderer");
         set_long("%^RESET%^Chella is a barbaric looking female human that "
	   "towers over the average human.  Her wild long %^BOLD%^%^BLACK%^black hair "
	  "%^RESET%^is kept in a tight braid at the base of her neck and is tied "
	  "with a %^ORANGE%^leather thong, %^RESET%^though a few strands refuse to "
	  "comply and hang loosely around her stern face.  Her %^GREEN%^green eyes "
	  "%^RESET%^have a calm, cool look to them and are framed by several faint "
	  "wrinkles, indicating that she is perhaps older, or has seen much in her "
	  "lifetime.  A thick, %^BOLD%^%^BLACK%^w%^RESET%^o%^BOLD%^%^BLACK%^l%^"
	  "RESET%^f%^BOLD%^%^BLACK%^sk%^RESET%^i%^BOLD%^%^BLACK%^n %^RESET%^cloak "
	  "layers over another cloak made of %^ORANGE%^deerskin, %^RESET%^while even "
	  "more %^ORANGE%^skins %^RESET%^hang over her right shoulder, concealing "
	  "most of her frame from view.  The %^BOLD%^%^BLACK%^handle %^RESET%^of a "
	  "large hunting knife can be seen sticking out from her %^BOLD%^%^BLACK%^"
	  "bearskin boots, %^RESET%^and by the %^RED%^bloodstains %^RESET%^on it, "
	  "it looks like it may be well used.");
         set_gender("female");
         set_race("human");
         set_emotes(1,({
            "%^RESET%^%^RED%^Chella pulls out her knife and sharpens it expertly.",
            "%^RESET%^Chella begins to work on a %^ORANGE%^skin, %^RESET%^separating any loose %^BOLD%^%^WHITE%^f%^RESET%^a%^BOLD%^%^WHITE%^t %^RESET%^from it with ease."}),0);

         break;
      case 3:
         set_nwp("concealment",12);
         set_name("Deloran");
         set_id(({"deloran","Deloran","wanderer","trainer"}));
         set_short("Deloran, a wanderer");
         set_long("%^RESET%^Deloran is a shifty little half-elf that wears a "
	  "long, %^BOLD%^%^BLACK%^dark cloak.  %^RESET%^His %^ORANGE%^brown hair "
	  "%^RESET%^is kept short and neat, and his %^GREEN%^emerald eyes %^RESET%^are "
	  "always darting around.  He keeps his hands tucked out of sight, and if he "
	  "has any belongings, they are well hidden, as you can't even seem to see "
	  "one single bulge anywhere in his clothing.");
         set_gender("male");
         set_race("half-elf");
         set_emotes(1,({
            "%^BOLD%^%^BLACK%^Deloran slides something into his cloak and it seemingly disappears."}),0);
         break;
   }    
}     
