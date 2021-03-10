#include <std.h>
#include "../deep_echo.h"
inherit WEAPONLESS;

void create()
{  object pap;
   ::create();
   set_name("crazed beast");
   set_short("A crazed humanoid beast");
   set_id(({"beast","crazed beast","monster","human","crazed"}));
   set_long(
   "%^RED%^This looks somewhat like cross between a man and a beast.  "+
   "He is dressed in rags.  %^BOLD%^blood soaked"+
   " hair%^RESET%^%^RED%^ covers his "+
   "entire body.  His cat-like eyes are yellow and furry skin black."+
   "  He has fangs and two %^BOLD%^large claws%^RESET%^"+
   "%^RED%^ where his hands should "+
   "be.  He almost seven feet tall.  He looks to weigh several"+
   " hundred pounds.  His body is corded with muscles that"+
   " twitch in anticipation.  His ears are also like a feline,"+
   " protruding from the top of his head.  He has a long straight"+
   " tail that is also covered in blood." );
   set_hd(20,10);
   set_race("human");
   set_gender("male");
   set_body_type("human");
   set_overall_ac(2);
   set("aggressive",19);
  set_property("swarm",1);
  set_level(20);
  set_class("fighter");
  set_mlevel("fighter",20);
  set_hp(random(300)+400);
  set_exp(10000);
  set_stats("strength",20);
  set_stats("intelligence",3);
  set_stats("dexterity",16);
  set_stats("constitution",16);
  set_stats("wisdom",3);
  set_stats("charisma",3);
  set_base_damage_type("slashing");
  set_attacks_num(5);
  add_limb("left claw","left hand",0,0,0);
  add_limb("right claw","right hand",0,0,0);
  add_limb("mouth","head",0,0,0);
  set_attack_limbs(({"left claw","right claw","mouth"}));
  set_hit_funcs((["mouth" : (:TO,"bite":) ]));
  set_overall_ac(4);
  set_alignment(5);
  set_damage(2,10);
  set_emotes(4,({
  "The beast crouches low to the ground, ready to pounce.",
  "The beast snarls.",
  "The beast %^RED%^rages!",
  "The beast licks his lips.",
  }),0);
  set_emotes(1,({
  "The beast's eyes glow %^RED%^red%^RESET%^ focused on you.",
  "The beast lashes out for you!",
  "%^RED%^The beast tries to tear you to bits"
  }),1);
  
  set_max_level(25);
  set_missChance(10);
  new(OBJ"bbelt")->move(TO);
  command("wear belt");
  pap = new("/d/common/obj/misc/paper");
  pap->move(TO);
  pap->set("language","common");
  pap->set("read","%^GREEN%^Knight's Journal\n\n%^RESET%^"+
     "I was tasked to kill a hundred ogres in echo mountians"+
	 " to prove myself worthy of the title paladin of Tyr.  "
	 "All was going well until I came across an outcropping"+
	 " I fell down and suddenly was attacked by ogres better "+
	 "armed than the ones above.  I was able to kill them and "+
	 "continued my quest down in these dark caves.  Eventually "+
	 "I came face to face with a half-ogre hunter.  \n"+
	 "I challenged him and lost. \n\nNow I'm in this terrible "+
	 "place.  The malarites are constantly killing creatures "+
	 "here.  I've been forced to eat raw meat and drink blood.  "+
	 "It is disgusting, I feel like I'm part of a sick "+
	 "experement.  Tyr save me.  I feel like I'm loosing my mind"+
	 ".  My heart is constantly pounding and my head screaming "+
	 "They made me wear this belt.  It was still dripping with "+
	 "blood when they held me down and forced in on me.  "+
	 "I've been growing hair like crazy, my skin has turned black.  "+
	 "I don't look human anymore.  \n\nWhat are these fangs?  Claws?"+
	 "\n\n  %^RED%^The rest is just a smear of blood.");
}



void bite(object targ)
{
   tell_object(targ,"%^RED%^The beast jumps on you and bites your neck!");
   tell_room(ETO,"%^RED%^The beast jumps on"+
   " "+targ->query_cap_name()+" and bites them hard.",targ);
   targ->do_damage(targ->return_target_limb(),random(10)+20);

 if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-15))
    targ->set_paralyzed(10+random(20),
     "%^MAGENTA%^Loss of blood has left you weak!");
   return 1;
}
