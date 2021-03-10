
#include <std.h>
inherit MONSTER;

create (){
::create ();
set_name("bugbear");
set_id( ({"bugbear"}) );
set("short", "A bugbear");
set("long", "This is a Bugbear. It's a giant, hairy cousin
of the goblins. It's 7' tall, hairy and very muscular. It's
greenish white eyes with red pupils stare at you with anger.
He gnashes his fangs and snarls at you!");
set_gender("male");
set("race", "bugbear");
set_body_type("human");
set_hd(13,0);
set_overall_ac(4);
set_size(2);
set_stats("strength", 19);
set_stats("intelligence", 6);
set_stats("dexterity", 15);
set_stats("charisma", 1);
set_stats("wisdom", 5);
set_class("fighter");
set("aggressive", 5);
set_alignment(8);
set_hp(110);
set_exp(800);
set_emotes(20,({"%^YELLOW%^The Bugbear grunts and snarls at you, while making vulgar gestures!",
"%^BOLD%^The Bugbear tosses rocks at you!!"}),0);
set_funcs( ({"bash"}) );
set_func_chance(65);
set_wielding_limbs( ({"left hand","right hand"}) );
new("/d/dagger/marsh/items/wpns/warhammer.c")->move(this_object());
command("wield warhammer in right hand and left hand");
new("/d/dagger/marsh/items/armor/hide.c")->move(this_object());
command("wear armor");
add_money("gold", 5 + random(50));
}


void bash(object targ)
{
  if(!targ) return 0;
  if(random(25) > targ->query_stats("dexterity")){
  tell_room(environment(targ), "%^RED%^The Bugbear bashes "+targ->query_cap_name()+" with his 2-handed Warhammer!",targ);
  tell_object(targ, "%^RED%^The Bashes you hard with his 2-handed Warhammer!");
  targ->do_damage("torso", random(2)+8);
  return 1;

} else {

  tell_object(targ, "%^BOLD%^%^BLUE%^The Bugbear bashes at you with it's 2-handed Warhammer, but you deflect it!");
  tell_room(environment(targ), "%^BOLD%^%^BLUE%^The Bugbear bashes at "+targ->query_cap_name()+" with it's 2-handed Warhammer, but they deflect it!",targ);

}
}
