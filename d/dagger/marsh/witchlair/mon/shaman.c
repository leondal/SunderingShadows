#include <std.h>
#include "../witchlair.h"
inherit MONSTER;

void create(){
   ::create();
   set_name("neshkir");
   set_id(({"neshkir","goblin","goblin shaman","shaman"}));
   set_short("%^RESET%^%^RED%^Neshkir%^BOLD%^%^BLACK%^, "
"a %^RESET%^%^RED%^fi%^MAGENTA%^e%^RED%^rce %^GREEN%^goblin"
" %^BOLD%^%^BLACK%^shaman clad in %^WHITE%^b%^RESET%^on"
"%^BOLD%^e %^BLACK%^armor%^RESET%^");
   set_long("%^RESET%^%^RED%^This can only be the leader "
"of the goblins residing here. Though smaller in stature "
"than most of the rest, the faint aura surrounding this one"
" marks him as favored by whatever unholy force these "
"wretched beings worship. Wrinkly flesh the color of "
"%^ORANGE%^tann%^WHITE%^e%^ORANGE%^d hi%^BOLD%^%^BLACK%^d"
"%^RESET%^%^ORANGE%^es %^RED%^shows the weathering of one"
" well into the twilight years of their life, yet he shows"
" no further signs of age, moving with %^BOLD%^%^RED%^an"
"%^BLACK%^g%^RESET%^%^RED%^e%^BOLD%^%^RED%^r-fu"
"%^RESET%^%^MAGENTA%^e%^BOLD%^%^RED%^l%^BLACK%^e%^RED%^d "
"%^GREEN%^vigor %^RESET%^%^RED%^to KILL those who invade"
" his tribe's home. %^WHITE%^B%^BOLD%^o%^RESET%^ne%^RED%^-"
"hewn armor covers his scrawny form, similar to that of "
"the other goblins here, but his station bears more "
"elaborate cloth - such as the hooded %^ORANGE%^b"
"%^BOLD%^%^BLACK%^e%^RESET%^%^WHITE%^a%^ORANGE%^r pelt "
"%^RED%^he wears. Clutched in one hand is a horrid "
"staff, waved in preparation to unleash his patron's "
"might upon you!%^RESET%^");
   set_race("goblin");
   set_gender("male");
   set_size(1);
   set_overall_ac(5);
   set_class("cleric");
   set_mlevel("cleric",26);
   set_guild_level("cleric",26);
   set_max_level(26);
   set_hd(20,10);
   set_max_hp(random(100)+125);
   set_hp(query_max_hp());
   set_wielding_limbs(({"right hand","left hand"}));
   set_body_type("humanoid");
  set_property("swarm",1);
  set_property("damage resistance",5);
   set_property("not random monster", 1); //added by saide in order to prevent these from spawning in alternative worlds
   set_stats("strength",12);
   set_stats("dexterity",12);
   set_stats("constitution",14);
   set_stats("intelligence",14);
   set_stats("wisdom",18);
   set_stats("charisma",16);
   set("aggressive","aggfunc");
   set_exp(40000);
   set_max_level(20);
   set_alignment(9);
   set_property("full attacks");
   new("/d/shadow/room/goblin/obj/bone.c")->move(this_object());
   command("wear armor");
   new(OBJ"bonestaff.c")->move(this_object());
  command("wield staff");
  new("/d/common/obj/armour/sshield")->move(this_object());
  command("wear shield");
   add_money("gold", random(120));
   set_monster_feats(({
     "spell focus","spell penetration","perfect caster",
"shieldwall","deflection"
  }));
   set_spells(({
     "insect plague","insect plague","call lightning",
     "flame strike","unholy orb","blasphemy",
     "phantasmal killer"
   }));
   set_spell_chance(75);
   set_emotes(3, ({"Candles %^BOLD%^%^BLACK%^flicker "
"%^RESET%^%^WHITE%^as the shaman utters an unholy prayer to "
"his unknown patron",
"The shaman sways as it chants rapidly, blood-soaked arms "
"raised."}), 0);
   set_achats(3, "%^RESET%^%^MAGENTA%^The goblin shrieks at "
"you: %^CYAN%^'%^GREEN%^You make good sacrifice for blood-"
"eater lady!%^CYAN%^'");
}

void aggfunc(){
   force_me("emote %^YELLOW%^shrieks %^RESET%^%^WHITE%^and "
"points his staff at you, babbling shrilly!");
   force_me("kill "+TP->query_name());
   return 1;
}

void die(object ob){
   object who;
   tell_room(ETO,"%^BOLD%^%^BLACK%^Neshkir yells one more "
"incomprehensible curse at you before slumping to his knees"
" and manages a final, desperate move! He yanks something"
" from the folds of his pelt cloak and shatters it against"
" the altar! A final, gasping cough escapes him, then he "
"shudders and falls.");
   new(OBJ"note")->move(TO);
   ob = new(OBJ"keyshard.c");
   ob->shard_pick(2);
   ob->move(TO);
   :: die(TO);
}
