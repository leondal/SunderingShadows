#include <std.h>
#include "/d/tharis/barrow/short1.h"
inherit MONSTER;
int xx;
void init() {
    ::init();
    add_action("no_func","throw");
    add_action("no_func","stab");
    add_action("no_func","steal");
    add_action("no_func","rush");
}
void create() {
    :: create();
    set_name("priest");
    set_id(({
      "priest","drow","drow priest",
      }));
    set_short("%^RESET%^%^RED%^Drow priest%^RESET%^");
    set_long(
        "%^RESET%^%^RED%^The drow priests of underdark are among "
        "one of the most feared creatures by all races. "
        "Not only are the experts in combat...they have developed and "
        "mastered the use of a horrible craft known only as drow abyssal "
        "mystism. Unlike drow mages, who still draw their energys from the "
        "substance of the universe, the drow priests draw their power "
        "directly from Lloth herself.\n"
        "%^BOLD%^%^MAGENTA%^Drow priest is surrounded by a purple sphere."
        "%^RESET%^"
    );
    set_gender("female");
    set_hd(22,5);
 
    set_size(2);
    set_body_type("humanoid");
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(-7);
    set_hp(185);
    set_property("no bump",1);
    set_mob_magic_resistance("average");
    set_max_hp(185);
    set_exp(15500);
add_money("platinum",random(1000));
    set_alignment(9);
    set_race("Drow");
    set_class("mage");
    set_guild_level("mage",22);
    set_stats("strength",19);
    set_stats("constitution",19);
    set_stats("dexterity",22);
    set_stats("wisdom",22);
    set_stats("intelligence",20);
    set_stats("charisma",17);
    set_funcs(({"moves"}));
    set_func_chance(50);
    new( "/d/dagger/drow/obj/frwand.c" )->move(TO);
    set_emotes(4, ({
        "%^RED%^The drow priest mutters a chant.%^RESET%^",
        "%^RED%^The drow priest cackles and visions of spiders fill your "
        "mind.%^RESET%^",
        "%^RED%^The drow priest looks you over and scowls.",
        "The drow priest grins evilly, sending chills down your "
        "spine.%^RESET%^",
        "%^RED%^The drow priest mumbles: %^RESET%^Syk rak'nor slyetsh.",
        "%^RED%^The drow priest mumbles: %^RESET%^Gr'to mum-buziek.",
        "%^RED%^The drow priest mumbles: %^RESET%^Kyzer sohzay SYZTH!.",
        "%^RED%^The drow priest mumbles: %^RESET%^Krimerz rak kekza.",
        "%^RED%^The drow priest mumbles: %^RESET%^Grapik zokrath's batezie.",
        "%^RED%^The drow priest mumbles: %^RESET%^Shamtwgz Lloth bowgryz.",
    }),0);
}

void reset(){
  object ob;
  ::reset();
  if(!present("scroll")){
    ob = new("/d/magic/scroll");
    ob->set_spell(5);
    ob->move(TO);
  }
}

int no_func(string str) {
    write(
        "%^BOLD%^%^MAGENTA%^As you attempt your action, the sphere grows "
        "bright!%^RESET%^"
    );
    say(
        "%^BOLD%^%^MAGENTA%^"+TPQCN+" attempts to do something but suddenly "
        "ceases moving!%^RESET%^"
    ,TP);
    TP->set_paralyzed(10,"%^BOLD%^%^RED%^You are held by an unseen force!"
        "%^RESET%^");
    return 1;
}
int moves() {
    object ob = this_object();
    object targ = ob->query_current_attacker();
    int i;
    xx=random(4)+1;
    switch(xx) {
    case 1:
    say(
        "%^MAGENTA%^The drow priest mutters, `kyz kyz snrkya'\n"
        "%^BOLD%^%^RED%^An immense heat builds in the area!%^RESET%^"
    );
    call_out("flash_fun",3);
    call_out("fire_fun",5);
    call_out("fire_fun",15);
    call_out("fire_fun",30);
    call_out("endflame_fun",31);
    return 1;
    case 2:
    set_property("magic",1);
    tell_object(targ,
        "%^BOLD%^%^RED%^The drow priest screams, `%^GREEN%^%^FLASH%^"
        "Slyssthizth Muh hauh diabuoli!%^RESET%^BOLD%^%^RED%^' "
        "and an intense pain shoots up you spine to the base of your "
        "cranium!%^RESET%^"
    );
    tell_room(environment(targ),
        "%^BOLD%^%^RED%^The drow priest screams, `%^GREEN%^%^FLASH%^"
        "Slyssthizth Muh hauh diabuoli!%^RESET%^BOLD%^%^RED%^' "
        "and "+targ->query_cap_name()+" screams out in "
        "pain!%^RESET%^"
    ,targ);
    targ->do_damage("head",roll_dice(4,8));
   remove_property("magic");
    return 1;
    case 3:
    if((int)TO->query_hp() < 25) return 1;
    for(i=0;i<4;i++) {
        say(
            "%^CYAN%^The drow priest mutters a guttural oath of healing to "
            "Lloth.%^RESET%^"
        );
        TO->add_hp(roll_dice(2,3));
    }
    return 1;
    case 4:
        tell_object(targ,
        "%^GREEN%^The drow priest chants an oath to %^RED%^"
        "Lloth%^GREEN%^ while staring into your eyes!%^RESET%^"
    );
    tell_room(environment(targ),
        "%^GREEN%^ The drow priest chants an oath to %^RED%^Lloth"
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
    set_property("magic",1);
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
        sucker->do_damage("torso",roll_dice(6,6));
   remove_property("magic");
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
void die(object ob) {
    message("environment",
        "%^GREEN%^%^BOLD%^The Drow priest crumples to the "
        "ground!%^RESET%^"
    ,environment(TO));
    ::die(ob);
}
