#include <std.h>
inherit "/realms/pegasus/bodies/fish.c";

int spikes;

void create()
{
  ::create();
  set_name("dragonfish");
  set_property("water breather",1);
  set_id( ({"dragonfish", "fish"}) );
  set_short("%^BOLD%^%^CYAN%^a spiny dragonfish%^RESET%^");
   set_long("This is a dragonfish with spines about its body and a rather nasty"+
   " looking mouth. I'd be careful around them if I were you, and don't try to eat them"+
   " unless you enjoy being sick or dying.");
  set_race("dragonfish");
  set_gender("male");
  set_body("fish");
  set_hd(5,5);
  set_max_hp(40);
  set_hp(40);
  set_new_exp(5, "normal");
  set_stats("strength", 18);
  set_stats("constitution", 15);
  set_stats("dexterity", 20);
  set_stats("wisdom", 3);
  set_stats("intelligence", 4);
  set_stats("charisma", 3);
  set_size(1);
  set_funcs( ({"bite"}) );
  set_func_chance(50);
  spikes = random(10) + 1;
}
void bite(object targ)
{
  if(!targ) return 0;
	tell_room(environment(TO),"%^BOLD%^%^CYAN%^You see the dragonfish speed toward "
	+targ->query_cap_name()+" and rip away a small piece of flesh!",targ);
 	 targ->do_damage("torso", (random(6)+1));
   	tell_object(targ,"%^BOLD%^%^RED%^You see the dragonfish speed towards you"+
   	"...SUDDEN PAIN...as it rips a small piece of your flesh away!");
  	return 1;
  }

void init(){
	int i, j;
	::init();

	if(interactive(TP)){
         if(avatarp(TP) && TP->query_true_invis()) return;
		if(spikes){
			i = random(10) - 4;
			if(i < 0) i = 0;
			if(i > spikes) i = spikes;
			spikes -= i;
			if(i){
				write("%^BOLD%^%^BLUE%^As you traverse the body of water you step on a dragonfish!\n"+
				""+i+" spikes break through your boots and lodge themselves in your foot!");
			}
			for(j = 0;j< i;j++){
				new("/d/koenig/town/obj/fishspike")->move(TP);
				TP->do_damage("torso",1);
				TP->add_poisoning(5);
			}
		}
	}
}

