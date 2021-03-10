#include <std.h>
#include "../witchlair.h"
inherit MONSTER;

void create() {
  ::create();
  set_name("viik");
  set_id(({ "viik","goblin","assassin","goblin assassin" }));
  set_short("%^RESET%^%^RED%^Viik, a be%^BOLD%^%^RED%^ad"
"%^RESET%^%^RED%^y%^BOLD%^%^BLACK%^-%^RESET%^%^RED%^"
"e%^BOLD%^%^RED%^y%^RESET%^%^RED%^ed %^BOLD%^%^BLACK%^little"
" %^RESET%^%^GREEN%^goblin %^BOLD%^%^BLACK%^adorned with "
"%^WHITE%^bon%^RESET%^e%^BOLD%^s");
  set_long("%^RESET%^%^MAGENTA%^This goblin's %^GREEN%^v"
"%^WHITE%^i%^GREEN%^le co%^BOLD%^%^GREEN%^u%^BLACK%^n"
"%^RESET%^%^GREEN%^te%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^an"
"%^RED%^c%^GREEN%^e %^MAGENTA%^easily spurs revulsion. Rubbery, "
"%^BOLD%^%^BLACK%^dark-gray %^RESET%^%^MAGENTA%^flesh covers "
"his sinewy form, slick with the greasy film of an unwashed "
"body. He is exceedingly thin, though with no small degree of "
"%^RED%^m%^BOLD%^%^RED%^us%^RESET%^%^RED%^cle%^MAGENTA%^. His "
"arms in particular are quite well-defined, every vein and "
"muscle standing out against a hairless background. A slightly "
"disproportionate head tops his scrawny neck, dominated by a "
"wide, %^WHITE%^ne%^BOLD%^e%^RESET%^dle-f%^BOLD%^i%^RESET%^ll"
"%^BOLD%^e%^RESET%^d %^MAGENTA%^maw from which a dark %^RED%^to"
"%^BOLD%^%^BLACK%^n%^RESET%^%^RED%^gue %^MAGENTA%^constantly "
"slithers to lick his thin, weathered lips. All but without a "
"nose, mere nostril-holes mark the center of his face below "
"bright %^BOLD%^%^RED%^cr%^WHITE%^i%^RED%^mson e%^WHITE%^y"
"%^RED%^es%^RESET%^%^MAGENTA%^. It's almost a relief that the "
"majority of his head isn't visible, hidden beneath the bleached"
"-white surface of some sort of rodent %^BOLD%^%^WHITE%^skull"
"%^RESET%^%^MAGENTA%^. Bones of all sort are strewn across the "
"%^GREEN%^hi%^CYAN%^d%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^ous "
"%^MAGENTA%^little thing, from studs piercing the sharp ears "
"emerging from his impromptu helmet, to minute vertebrae and "
"ribs clasped around his wrists and forearms.");
  set_race("goblin");
  set_gender("male");
  set_size(1);
  set_overall_ac(0);
  set_class("thief");
  set_mlevel("thief",28);
  set_guild_level("thief",28);
  set_max_level(28);
  set_hd(22,6);
  set_max_hp(random(250)+150);
  set_property("not random monster", 1); //added by saide in order to prevent these from spawning in alternative worlds
  set_hp(query_max_hp());
  set_wielding_limbs(({"right hand","left hand"}));
  set_body_type("humanoid");
  set_property("swarm",1);
  set_property("damage resistance",6);
  set_skill("athletics",40);
  set_stats("strength",14);
  set_stats("dexterity",21);
  set_stats("constitution",15);
  set_stats("intelligence",13);
  set_stats("wisdom",12);
  set_stats("charisma",1);
  set("aggressive","aggfunc");
  set_exp(32000);
  set_max_level(20);
  set_alignment(9);
  set_property("full attacks",5);
  new("/d/shadow/room/goblin/obj/gdagger.c")->move(this_object());
  command("wield dagger");
  new("/d/shadow/room/goblin/obj/gdagger.c")->move(this_object());
  command("wield dagger");
   new(OBJ"ratskull")->move(this_object());
  command("wear skull");
   new("/d/shadow/room/goblin/obj/bone.c")->move(this_object());
   command("wear armor");
   set_invis();
  add_money("gold", random(120));
   set_monster_feats(({
     "dodge","mobility","evasion","scramble",
"weapon finesse","lethal strikes","whirl"
  }));
   set_funcs(({"bite","whirl"}));
  set_func_chance(25);
  set_emotes(10, ({
    "%^RESET%^%^MAGENTA%^The goblin %^RESET%^%^GREEN%^gi"
"%^BOLD%^%^GREEN%^gg%^RESET%^%^GREEN%^les %^BOLD%^%^BLACK%^li"
"ke a madman through his %^WHITE%^da%^RESET%^gg%^BOLD%^er-"
"to%^RESET%^o%^BOLD%^th%^RESET%^e%^BOLD%^d %^BLACK%^grin.",
    "%^RESET%^%^MAGENTA%^A bark of %^BOLD%^%^BLACK%^r"
"%^RESET%^%^ORANGE%^o%^WHITE%^u%^BOLD%^%^BLACK%^gh"
"%^RESET%^%^MAGENTA%^, %^CYAN%^ho%^WHITE%^a%^BOLD%^r"
"%^RESET%^%^CYAN%^se %^MAGENTA%^laughter can be heard from "
"the goblin's accursed mouth.",
  }),1);
}

void aggfunc() {
  force_me("stab "+TP->query_name());
  force_me("emoteat viik %^RESET%^%^MAGENTA%^$M"
"%^RESET%^%^MAGENTA%^'s head seems to be nothing but mouth as "
"his jaw drops with a %^RED%^wic%^BOLD%^%^RED%^ke"
"%^RESET%^%^RED%^d %^MAGENTA%^ca%^CYAN%^c%^RED%^k%^MAGENTA%^le.");
  force_me("say Viik kill you! Give skull to master!");
  return 1;
}

void bite(object targ) {
  string dam;
  if("daemon/saving_d"->saving_throw(targ,"poison")) {
    dam="bites";
  } else {
    dam="poisons";
  }
  tell_object(targ,
    "%^RESET%^%^MAGENTA%^The goblin snarls and leaps at you, "
"slamming into your chest and locking his claws around your neck!"
" You manage to throw the thing off, but not before his claws "
"rake your neck!");
  tell_room(environment(targ),
    "%^RESET%^%^MAGENTA%^The goblin snarls and leaps at "
""+targ->query_cap_name()+", but they manage to throw him off!"
  ,targ);
  if(dam=="poisons"){
    targ->do_damage("neck",roll_dice(3,6));
    tell_object(targ,
      "%^RESET%^%^MAGENTA%^The goblin snarls and leaps at "
"you, slamming into your chest and locking his claws around "
"you too tight to allow escape! With a hiss, the filthy beast"
" sinks his %^ORANGE%^r%^RED%^o%^ORANGE%^t%^MAGENTA%^-"
"%^ORANGE%^co%^BOLD%^%^RED%^a%^RESET%^%^RED%^t%^ORANGE%^ed "
"%^BOLD%^%^WHITE%^fangs %^RESET%^%^MAGENTA%^into your "
"neck!!"
    );
  targ->set_paralyzed(random(10)+15,
    "%^RESET%^%^RED%^You still can't believe that disgusting "
"thing actually bit you!"
    );
  } else {
    targ->do_damage("neck",roll_dice(1,6));
  }
  return 1;
}

void whirl(object targ){
   command("whirl");
}
void die(object ob){
  object who;
  tell_room(ETO,"%^RESET%^%^RED%^The goblin parts from the shadows,"
" sensing his defeat. He pulls "
"something from his armor and flings it to the ground, shattering "
"the object! With that, he slumps to the ground, dead.%^RESET%^");
     ob = new(OBJ"keyshard.c");
     ob->shard_pick(1);
     ob->move(TO);
  :: die(TO);
}
