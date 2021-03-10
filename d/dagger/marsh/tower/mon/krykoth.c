//General difficulty increase Octothorpe 5/25/09
#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit MONSTER;
int xx;
void init() {
    ::init();
    add_action("throw_func","throw");
}
void create() {
    :: create();
    set_name("krykoth");
    set_id(({
      "krykoth","demon"
      }));
    set_short("%^RESET%^%^RED%^Krykoth%^RESET%^");
    set_long(
        "%^RESET%^%^RED%^The large demon that stands before you can only "
        "be a Krykoth...one of the most horrible demons to wander "
        "the Abyssal planes of existence. You shiver as the cold "
	"eyes of the "
        "Krykoth seems to gaze right through you. The horns of this one "
	"are close to 4 feet long and it's fangs glisten with blood.%^RESET%^"
    );
    set_gender("male");
    set_hd(25,5);
    set_size(3);
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(-8);

    set_hp(165);
    set_property("no bump",1);
    set_mob_magic_resistance("average");
    set_property("no paralyze",1);
    set_max_hp(165);
    set_exp(12700);
    set_max_level(36);
    set_body_type("humanoid");
    set_race("demon");
    set_class("fighter");
    set_alignment(9);
    set_stats("strength",25);
    set_stats("constitution",23);
    set_stats("dexterity",20);
    set_stats("wisdom",20);
    set_stats("intelligence",20);
    set_stats("charisma",-5);
    set_funcs(({"moves"}));
    set_func_chance(100);
    set("aggressive",50);
    set_resistance("electricity",15);
}
int moves() {
    object ob = this_object();
    object targ = ob->query_current_attacker();
    int i;
    xx=random(4)+1;
    switch(xx) {
    case 1:
    say(
        "%^MAGENTA%^The krykoth cackles and chants to his masters to bring "
        "a rain of fire upon his enemies!\n"
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
        "%^BOLD%^%^RED%^The krykoth's eyes %^FLASH%^%^GREEN%^flash"
        "%^RESET%^%^BOLD%^%^RED%^ "
        "and an intense pain shoots up you spine to the base of your "
        "cranium!%^RESET%^"
    );
    tell_room(environment(targ),
        "%^BOLD%^%^RED%^The krykoth's eyes %^FLASH%^%^GREEN%^flash"
        "%^RESET%^%^BOLD%^%^RED%^ "
        "and "+targ->query_cap_name()+" screams out in "
        "pain!%^RESET%^"
    ,targ);
    targ->cause_typed_damage(targ, "head",roll_dice(5, 8),"mental");
    return 1;
    case 3:
    for(i=0;i<4;i++) {
        say(
            "%^CYAN%^The krykoth mutters a guttural oath of healing to "
            "the lady of spiders.%^RESET%^"
        );
        TO->add_hp(roll_dice(2,3));
    }
    tell_object(targ,
        "%^BOLD%^%^GREEN%^The krykoth lashes out with his claws and "
        "slashs you violently across the face!%^RESET%^"
    );
    tell_room(environment(targ),
        "%^BOLD%^%^GREEN%^The krykoth lashes out with his claws and "
        "slashs "+targ->query_cap_name()+" across the face!%^RESET%^"
    ,targ);
    targ->cause_typed_damage(targ, "head",roll_dice(4, 10),"slashing");
    return 1;
    case 4:
    tell_object(targ,
        "%^BOLD%^%^GREEN%^The krykoth lashes out with his claws and "
        "slashs you violently across the face!%^RESET%^"
    );
    tell_room(environment(targ),
        "%^BOLD%^%^GREEN%^The krykoth lashes out with his claws and "
        "slashs "+targ->query_cap_name()+" across the face!%^RESET%^"
    ,targ);

    targ->cause_typed_damage(targ, "head",roll_dice(3, 6),"slashing");
    TO->force_me("say You Fool! I will take you to the Abyss!");
    tell_object(targ,
        "%^BOLD%^%^BLUE%^The krykoth rears back and slams his horned "
        "skull into your forehead!\nYou are stunned by the blow!%^RESET%^"
    );
    tell_room(environment(targ),
        "%^BOLD%^%^BLUE%^A resounding %^RED%^CRACK%^BLUE%^"
        " is heard as the krykoth "
        "slams his skull into "+targ->query_cap_name()+"'s "
        "forehead!%^RESET%^"
    ,targ);

    targ->cause_typed_damage(targ, "head",roll_dice(3, 10),"bludgeoning");
    targ->set_paralyzed(22,"You are stunned by the blow!");
    TO->force_me("say How do you like that puny mortal!");
    tell_object(targ,
        "%^BOLD%^%^MAGENTA%^The krykoth suddenly spins around and lashes "
        "out with his claws slicing your chest wide open!%^RESET%^"
    );
    tell_room(environment(targ),
        "%^BOLD%^%^MAGENTA%^The krykoth suddenly spins around and lashes "
        "out with his claws slicing "
        +targ->query_cap_name()+"'s chest wide open!%^RESET%^"
    ,targ);
    targ->cause_typed_damage(targ, "torso",roll_dice(6, 4),"slashing");
    TO->force_me("roar");
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
        (string)sucker->query_name() != "vampyre" && 
        (string)sucker->query_name() != "reaver")
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
        sucker->cause_typed_damage(sucker, "torso",roll_dice(5, 10),"fire");
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
int throw_func(string str) {
    write("%^RED%^That action is prevented by the pentagram!%^RESET%^");
    return 1;
}
void die(object ob) {
    message("environment",
        "%^GREEN%^%^BOLD%^The krykoth's body drops dead but his inner "
        "being vanishes back to the Abyss.\n%^BOLD%^%^RED%^"
    ,environment(TO));
      ::die(ob);
}
