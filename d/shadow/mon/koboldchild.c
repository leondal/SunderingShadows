//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//kobold child for kobold lair in DD - Circe 6/8/04
#include <std.h>
#include "/d/common/common.h"
#include "/d/shadow/room/cave/ddcaves.h"

inherit MONSTER;

void create() {
   ::create();
   set_name("kobold child");
   set_id(({"kobold","child","kobold child","monster","cave kobold","dirty kobold child"}));
   set_race("kobold");
   set_gender(random(2)?"male":"female");
   set_short("%^RESET%^%^BLUE%^A dirty kobold child");
   if((string)TO->query_gender() == "female"){
      set_long("This tiny kobold must be little more than a child.  "+
         "She stands just under two and a half feet tall with arms "+
         "graced by a child's thinness.  Her beady eyes are filled "+
         "with mischief and malice, however, and the cold grin on "+
         "her face is hardly endearing.  She is dressed in rags, "+
         "already looking much like her elder kin.");
   }else{
      set_long("This tiny kobold must be little more than a child.  "+
         "He stands just under two and a half feet tall with arms "+
         "graced by a child's thinness.  His beady eyes are filled "+
         "with mischief and malice, however, and the cold grin on "+
         "his face is hardly endearing.  He is dressed in rags, "+
         "already looking much like his elder kin.");
   }
   set_level(4);
   set_hd(4,4);
   set_body_type("human");
   set_alignment(3);
   set("aggressive",8);
   set_class("thief");
   set_mlevel("thief",6);
   set_guild_level("thief",4);
   add_search_path("/cmds/thief");
   set_thief_skill("pick pockets",65);
   set_scrambling(1);
   set_size(1);
   set_overall_ac(8);
   set_stats("intelligence",6);
   set_stats("wisdom",4);
   set_stats("strength",15);
   set_stats("charisma",3);
   set_stats("dexterity",12);
   set_stats("constitution",14);
   set_max_hp(query_hp());
   set_wielding_limbs( ({ "right hand", "left hand"}) );
   "/d/common/daemon/randgear_d"->arm_me(TO,"edgeds",5,1,60);
   add_money("silver",random(10));
   add_money("copper",random(20));
   set_hp(random(15)+35);
   //set_exp(250);
//   set_exp(600);
   set_new_exp(4,"normal");
   set_max_level(8);
   toggle_steal();
   set_emotes(2, ({
      "The kobold's beady eyes seem to be studying your money pouch.",
      "The kobold picks its nose and wipes something on your sleeve.",
      "The kobold barks something, then begins laughing.",
      "The kobold darts into the shadows and stares at you with glittering eyes.",
      "The kobold catches a bug and eats it."
   }),0);
   set_achats(5,({
      "%^MAGENTA%^Kobold child barks%^RESET%^: You baddie!  They kill you!",
      "The kobold child lunges for your throat.",
      "The kobold child tries to dart around behind you."
   }));
   switch(random(20)){
      case 0: new(DDOBJ"electrumring")->move(TO);
              command("wear ring");
              break;
      case 1: new(DDOBJ"leatherring")->move(TO);
              command("wear ring");
              break;
      case 2: new(DDOBJ"lightningring")->move(TO);
              command("wear ring");
              break;
      case 3: new(DDOBJ"glassmedallion")->move(TO);
              command("wear medallion");
              break;
      case 4: new(DDOBJ"rosemedallion")->move(TO);
              command("wear medallion");
              break;
      case 5: new(DDOBJ"lavamedallion")->move(TO);
              command("wear medallion");
              break;
      case 6: new(DDOBJ"platinumwand")->move(TO);
              break;
      case 7: new(DDOBJ"granitewand")->move(TO);
              break;
      case 8: new(DDOBJ"stormwand")->move(TO);
              break;
      default: break;
   }
}
