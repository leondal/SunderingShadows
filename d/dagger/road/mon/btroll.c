
#include <std.h>

inherit WEAPONLESS;
create ()
{
::create ();
set_name("bridge troll");
set_id( ({"troll","bridge troll"}) );
set("short", "A bridge troll");
set("long", "This is a Bridge Troll. They live under bridges and eat
people like you for breakfast, lunch, dinner and maybe a midnight
snack. He stands 8 feet tall, weighs over 400 pounds and slobbers
uncontrollable as he pictures you on a plate.");
set_gender("male");
set("race", "bridge troll");
set_body_type("human");
set_hd(18,0);
set_overall_ac(4);
set_size(2);
set_stats("strength", 18);
set_stats("intelligence", 6);
set_stats("dexterity", 16);
set_stats("charisma", 1);
set_stats("wisdom", 4);
set_class("fighter");
set("aggressive", 25);
set_base_damage_type("slashing");
set_damage(5,8);
set_attack_limbs(({"right claw","left claw","fangs"}));
set_attacks_num(3);
add_limb("fangs","head",0,0,0);
set_max_hp(400);
set_hp(400);
set_alignment(8);
set_exp(3500);
set_emotes(20,({"%^YELLOW%^The Bridge Troll snarls and attacks!",
"%^BOLD%^The Bridge Troll goes Berserk!!"}),1);
set_funcs( ({"berserk"}) );
set_func_chance(80);
   if(!random(6)) {
      new("/d/deku/armours/ring_p.c")->move(TO);
      command("wear ring");
   }
}


void berserk(object targ)
{
  if(!targ) return 0;
  tell_room(environment(targ), "%^RED%^The Bridge Troll tears into "+targ->query_cap_name()+" biting and clawing like mad!!",targ);
  tell_object(targ, "%^RED%^The Bridge Troll tears into you biting and clawing like mad!!");
  targ->do_damage("torso", random(5)+12);
  return 1;
}



