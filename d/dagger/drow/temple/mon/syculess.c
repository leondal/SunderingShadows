#include <std.h>
#include "/d/dagger/drow/temple/short.h"
inherit MONSTER;
int xx;
void create() {
    :: create();
    set_name("demoness");
    set_id(({
      "syculess","demoness"
      }));
    set_short("%^RESET%^%^RED%^Syculess, major demoness%^RESET%^");
    set_long(
        "%^RESET%^%^RED%^The large demoness that stands before you can only "
        "be Syculess...one of the most horrible servents of the "
	"demonqueen Lloth. The presense of her upon the prime "
        "material plane within the influence of the Drow can only mean "
	"that Lloth's hold upon this plane is growing incredibly "
	"strong. It is fabled that she teaches the Drow mages "
	"the black art of Abyssal magic. You shiver as the cold eyes "
	"of the Syculess seems to gaze right through you.%^RESET%^"
    );
    set_gender("female");
    set_hd(35,9);
    set_size(3);
    set_wielding_limbs(({"right hand","left hand"}));
   set_overall_ac(-25);
   set_hp(2500);
    set_property("no bump",1);
    set_mob_magic_resistance("average");
    set_property("no paralyze",1);
    set_property("no steal",1);
   set_max_hp(2500);
    set_exp(35000);
    set_body_type("humanoid");
    set_race("demon");
    set_class("fighter");
    set_alignment(9);
    set_stats("strength",27);
    set_stats("constitution",24);
    set_stats("dexterity",25);
    set_stats("wisdom",30);
    set_stats("intelligence",24);
    set_stats("charisma",-10);
    set("aggressive",20);
    new( OPATH "jewel.c" )->move(TO);
    add_money("gold",random(5000)+1000);
    set_funcs(({"moves"}));
    set_func_chance(100);
 
    set_emotes(2, ({
        "%^RED%^Visions of Lloth fill your mind!%^RESET%^",
        "%^RED%^The Syculess attempts to possess you!%^RESET%^",
        "%^RED%^The Syculess screams in Abyssal rage!",
        "The Syculess spins around in a flash!%^RESET%^"
    }),1);
}
int moves() {
    object ob = this_object();
    object targ = ob->query_current_attacker();
    int i;
    xx=random(4)+1;
    switch(xx) {
    case 1:
    say(
        "%^BOLD%^%^RED%^The Syculess cackles and chants to her masters "
	"to bring a rain of fire upon her enemies!\n"
        "%^BOLD%^%^RED%^An immense heat builds in the area!%^RESET%^"
    );
    call_out("flash_fun",3);
    call_out("fire_fun",5);
    call_out("fire_fun",15);
    call_out("fire_fun",30);
    call_out("endflame_fun",31);
    return 1;
    case 2:
    tell_object(targ,
        "%^BOLD%^%^RED%^The Syculess' eyes %^FLASH%^%^GREEN%^flash"
        "%^RESET%^%^BOLD%^%^RED%^ "
        "and an intense pain shoots up you spine to the base of your "
        "cranium!%^RESET%^"
    );
    tell_room(environment(targ),
        "%^BOLD%^%^RED%^The Syculess' eyes %^FLASH%^%^GREEN%^flash"
        "%^RESET%^%^BOLD%^%^RED%^ "
        "and "+targ->query_cap_name()+" screams out in "
        "pain!%^RESET%^"
    ,targ);
    targ->do_damage("head",roll_dice(10,10));
    return 1;
    case 3:
    for(i=0;i<10;i++) {
        say(
            "%^CYAN%^The Syculess mutters a guttural oath of healing to "
            "Lloth.%^RESET%^"
        );
        TO->add_hp(roll_dice(5,4));
    }
    tell_object(targ,
        "%^BOLD%^%^GREEN%^The Syculess hurls a bolt of pure evil "
        "at you!%^RESET%^"
    );
    tell_room(environment(targ),
        "%^BOLD%^%^GREEN%^The Syculess hurls a bolt of pure evil "
        "at "+targ->query_cap_name()+"!%^RESET%^"
    ,targ);
    targ->do_damage("head",roll_dice(6,12));
    return 1;
    case 4:
        tell_object(targ,
	"%^GREEN%^The Syculess chants an oath to %^RED%^"
	"Lloth%^GREEN%^ while staring into your eyes!%^RESET%^"
    );
    tell_room(environment(targ),
	"%^GREEN%^ The Syculess chants an oath to %^RED%^Lloth"
	"%^GREEN%^ while staring into "+targ->query_cap_name()+"'s "
	"eyes!%^RESET%^"
    ,targ);
    new( OPATH "possess.c")->move(targ);
    return 1;
  }
}
int flash_fun() {
    say(
        "%^BOLD%^%^RED%^The area is suddenly filled with flames!%^RESET%^"
    );
    return 1;
}
int fire_fun() {
    object ob,here,sucker,*players;
    int x,num_p;
        here=environment(TO);
        players=all_inventory(here);
        num_p=sizeof(players);
        for(x=0;x<num_p;x++)
        {
        sucker=players[x];
        if((living(sucker)) && sucker !=(TO) &&
        (string)sucker->query_name() != "drow priest")
        {
        tell_object(sucker,
            "%^BOLD%^RED%^The flames within the room suddenly roar in "
            "strength!\n%^YELLOW%^You hear an evil laughter as you are "
            "burned by the heat!%^RESET%^"
        );
        tell_room(environment(sucker),
            "%^BOLD%^%^RED%^"+sucker->query_cap_name()+
            " screams out as the flames burn "
            "their body!%^RESET%^"
        ,sucker);
        sucker->do_damage("torso",roll_dice(8,8));
        }
    }
    return 1;
}
int endflame_fun() {
    say(
        "%^BOLD%^%^CYAN%^The %^RED%^flames%^CYAN%^ in the room seem "
        "to dwindle to a less harmful level.%^RESET%^"
    );
    return 1;
}
void set_paralyzed(int time,string message){return 1;}
