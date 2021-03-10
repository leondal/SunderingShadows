#include <std.h>
#include "/d/dagger/drow/temple/short.h"
inherit MONSTER;
int xx;
void create() {
    :: create();
    set_name("priest");
    set_id(({
      "priest","drow","drow priest","drowmon"
      }));
    set_short("%^RESET%^%^RED%^Drow priest%^RESET%^");
    set_long(
        "%^RESET%^%^RED%^The drow priests of underdark are among "
        "one of the most feared creatures by all races. "
      "Not only are they experts in combat...they have developed and "
	"mastered the use of a horrible craft known only as drow abyssal "
   "mysticism. Unlike drow mages, who still draw their energies from the "
	"substance of the universe, the drow priests draw their power "
	"directly from Lloth herself."
    );
    set_gender("female");
    set_hd(19,5);
    set_size(2);
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(-5);
    set_hp(175);
    set_property("no bump",1);
    set_mob_magic_resistance("average");
    set_property("swarm",1);
    set_max_hp(175);
    set_exp(15000);
    set_body_type("humanoid");
    set_race("Drow");
    set_class("cleric");
    set_stats("strength",19);
    set_stats("constitution",19);
    set_stats("dexterity",20);
    set_stats("wisdom",20);
    set_stats("intelligence",20);
    set_stats("charisma",17);
    set_alignment(9);
    add_money("gold",750);
    new ( OPATH "sticki.c" )->move(TO);
    set_funcs(({"moves"}));
    set_func_chance(30);
    set_emotes(2, ({
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
    return 1;
    case 3:
    for(i=0;i<4;i++) {
        say(
            "%^CYAN%^The drow priest mutters a guttural oath of healing to "
	    "Lloth.%^RESET%^"
        );
	TO->add_hp(roll_dice(2,3));
    }
    return 1;
    case 4:
        if(random(100) < targ->query_level()) {
	tell_object(targ,
	"%^GREEN%^The drow priest chants an oath to %^RED%^"
	"Lloth%^GREEN%^ while staring into your eyes!%^RESET%^\n"
	"%^BLUE%^You avoid the possession!%^RESET%^"
    );
    tell_room(environment(targ),
	"%^GREEN%^ The drow priest chants an oath to %^RED%^Lloth"
	"%^GREEN%^ while staring into "+targ->query_cap_name()+"'s "
	"eyes!%^RESET%^\n"
	"%^BLUE%^You avoid the possession!%^RESET%^"
    ,targ);
    return 1;
    }
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
	sucker->do_damage("torso",roll_dice(3,6));
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

int kill_ob(object victim, int which){
  int hold;
  hold = ::kill_ob(victim, which);
  if(hold){
    if(interactive(victim))
    new("/cmds/spells/a/_animate_object.c")->use_spell(TO,victim->query_name(),30,100,"cleric");
  }
  return hold;
}
