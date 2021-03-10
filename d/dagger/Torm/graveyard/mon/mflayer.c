#include <std.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("mindflayer");
    set_id(({
	"mindflayer","flayer"
    }));
    set_short("%^BLUE%^Mindflayer%^RED%^%^BOLD%^");
    set_long(
        "%^RED%^The Mindflayer is a horid sight to behold. It's pale sickly "
	"colored skin glistens with an unknown oily substance. It's "
	"head resembles that of a squid. Four long tentacles stretch "
	"down from the lower portion of it's head. The Mindflayer "
	"is clothed in tattered robes with small skulls clasped to "
	"the robe. It's eyes are pure white globes with no pupils. "
	"From myth, you have heard of the awesome mental powers "
	"they have and of their ability to inflict damage to "
	"their victim's brain and spinal cord.%^RESET%^"
    );
    set_gender("neuter");
    set_hd(8,4);
    set_size(2);
    set_body_type("human");
    set_race("mindflayer");
    add_limb("tentacle 1","tentacle 1",75,1,5);
    add_limb("tentacle 2","tentacle 2",75,1,5);
    add_limb("tentacle 3","tentacle 3",75,0,5);
    add_limb("tentacle 4","tentacle 4",75,0,5);
    set_overall_ac(5);
    set_wielding_limbs(({
	"tentacle 1","tentacle 2","tentacle 3","tentacle4"
    }));
    new("/d/dagger/drow/obj/tentacle.c")->move(TO);
    command("wield tentacle in tentacle 4");
    new("/d/dagger/drow/obj/tentacle.c")->move(TO);
    command("wield tentacle in tentacle 3");
    new("/d/dagger/drow/obj/tentacle.c")->move(TO);
    command("wield tentacle in tentacle 2");
    new("/d/dagger/drow/obj/tentacle.c")->move(TO);
    command("wield tentacle in tentacle 1");
    set_hp(80);
    set_max_hp(80);
    set_exp(2800);
    set_class("mage");
    set_guild_level("mage",8);
    set_stats("strength",14);
    set_stats("constitution",16);
    set_stats("dexterity",16);
    set_stats("wisdom",18);
    set_stats("intelligence",18);
    set_stats("charisma",5);
    set_emotes(10, ({
        "Mindflayer cackles evilly.",
	"Mindflayer's tentacles quiver in anticipation.",
        "You feel a feathery touch pass through your mind.",
	"Mindflayer hisses: Do not impede my progress to the Drow city.",
	"Mindflayer hisses: They fear me. I am one part of five. I "
	"carry one fifth of the power to open it...or to close it."
    }),0);
    set_funcs(({"blast"}));
    set_func_chance(50);
}
int blast() {
    object ob,here,sucker,*players;
    int x,num_p;
	here=environment(TO);
	players=all_inventory(here);
	num_p=sizeof(players);
	for(x=0;x<num_p;x++) 
	{
	sucker=players[x];
	if((living(sucker)) && sucker !=(TO)) 
	{
	tell_object(sucker,
	    "%^BLUE%^The Mindflayer slams you mentally with it's "
	    "%^RED%^psychic blast%^BLUE%^!"
	);
	tell_room(environment(sucker),
	    "%^BLUE%^The Mindflayer slams "+sucker->query_cap_name()+
	    " mentally with it's %^RED%^psychic blast%^BLUE%^!"
	    "%^RESET%^"
	,sucker);
	sucker->do_damage("head",roll_dice(4,6));
	}
    }
    return 1;
}
