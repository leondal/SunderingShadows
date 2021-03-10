#include "/d/dagger/road/short.h"
inherit MONSTER;

create (){
  ::create ();
set_name("human guard");
set_id(({"private","guard","tollbooth guard","human","human tollbooth guard","human guard"}));
set_short("A Human guard");
set("long","This is a Human Tollbooth guard wearing the stripes of a private.
He looks experienced at his job and handling a sword.");
set_property("swarm",1);
set_gender("male");
set("race", "human");
set_body_type("human");
set_hd(15,0);
set_size(2);
set_class("fighter");
set_stats("strength", 18);
set_stats("intelligence", 8);
set_stats("dexterity", 13);
set_stats("charisma", 10);
set_stats("wisdom", 14);
set_stats("constitution", 17);
set_alignment(3);
set_max_hp(200);
set_hp(200);
set_exp(2600);
set("aggressive", 0);
set_emotes(5,({
"%^YELLOW%^The Guard says, It'll cost you 20 gold pieces to pass.",
"%^BOLD%^%^BLUE%^The Guard says, Fair weather we're having.",
"%^BOLD%^The Guard comments, Seen any bandits lately?"}),0);
set_emotes(10,({"%^BOLD%^You shall never defeat the Forces of Good!!"}),1);            
add_money("gold", 50 + random(100));
set_wielding_limbs( ({"left hand","right hand"}) );

new(OPATH "Mlong+1.c")->move(this_object());
command("wield sword");
new(OPATH "Mcoif.c")->move(this_object());
command("wear coif");
new(OPATH "Mchain+1.c")->move(this_object());
command("wear chainmail");
new(OPATH "Mshield+1.c")->move(this_object());
command("wear shield");

set_funcs( ({"bash"}) );
set_func_chance(40);
}

void bash(object targ){
        if(!targ) return 0;
        if(random(25) > targ->query_stats("dexterity")){
        tell_room(environment(targ), "%^RED%^The Tollbooth Guard bashes "+targ->query_cap_name()+" in the face with his Mithril Shield!",targ);
        tell_object(targ, "%^RED%^The Tollbooth Guard bashes you in the face with his Mithril Shield!");
        targ->do_damage("head", random(2)+8);
        tell_object(targ, "%^YELLOW%^The Tollbooth Guard rattles your teeth with the shield bash!!");
        if(random(25) > targ->query_stats("constitution"))
        targ->set_paralyzed(random(24), "%^BOLD%^You are stunned by the shield blow to your head and are unable to protect yourself.");
        return 1;

} else {

        tell_object(targ, "%^BOLD%^%^BLUE%^The Tollbooth Guard attempts to bash you in the face with his Mithril Shield....but misses!!");
        tell_room(environment(targ), "%^BOLD%^%^BLUE%^The Tollbooth Guard attempts bash "+targ->query_cap_name()+" in the face with his Mithril Shield....but misses!!",targ);
}
}
