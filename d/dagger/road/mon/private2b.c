
#include "/d/dagger/road/short.h"

inherit MONSTER;
create (){
  ::create ();
set_name("half-elven guard");
set_id(({"private","guard","tollbooth guard","half-elf","half-elven guard","half-elven tollbooth guard"}));
set_short("A Half-elven guard");
set("long","This is a Half-elven Tollbooth guard wearing the stripes of a private.
He looks experienced at his job and handling his 2 swords.");
set_property("swarm",1);
set_gender("male");
   set("race","half-elf");
set_body_type("human");
set_hd(18,1);
set_size(2);
set_class("ranger");
set_stats("strength", 15);
set_stats("intelligence", 13);
set_stats("dexterity", 17);
set_stats("charisma", 16);
set_stats("wisdom", 10);
set_stats("constitution", 14);
set_alignment(3);
set_max_hp(300);
set_hp(300);
set_exp(3500);
set("aggressive", 0);
set_emotes(5,({
"%^YELLOW%^The Guard says, It'll cost you 20 gold pieces to pass.",
"%^BOLD%^%^BLUE%^The Guard says, Hows the weather?",
"%^BOLD%^The Guard comments, Seen any bandits lately?"}),0);
set_emotes(5, ({"%^BOLD%^You shall never defeat the Forces of Good!!"}), 1);
add_money("gold", 50 + random(100));
set_wielding_limbs( ({"left hand","right hand"}) );

new(OPATH "Mlong+1.c")->move(this_object());
command("wield sword in right hand");
new(OPATH "studded+1.c")->move(this_object());
command("wear studded");
new(OPATH "Mlong+1.c")->move(this_object());
command("wield sword in left hand");

set_funcs( ({"slice"}) );
set_func_chance(50);
}

void slice(object targ){
     if(!targ) return 0;
     if(random(25) > targ->query_stats("dexterity")){
     tell_room(environment(targ), "%^RED%^The Tollbooth Guard's sword slips past "+targ->query_cap_name()+"'s guard and slices them in the arm!",targ);
     tell_object(targ, "%^RED%^The Tollbooth Guard sword slips past your guard and slices you deeply in the arm!");
     targ->do_damage("left arm", random(2)+9);
     return 1;

     } else {

     tell_object(targ, "%^BOLD%^%^BLUE%^The Tollbooth Guard attempts to slip past your guard with his sword.... but you avoid the blow!");
     tell_room(environment(targ), "%^BOLD%^%^BLUE%^The Tollbooth Guard attempts slip past "+targ->query_cap_name()+"'s guard with his sword.... but the blow is avoided!",targ);
}
}
