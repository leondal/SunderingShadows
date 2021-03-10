
#include <std.h>

inherit MONSTER;

void create()
{
  ::create();
    set_property("undead",1);
    set_mob_magic_resistance("average");
    set_name("knight");
    set_id( ({"DarkKnight","darkknight","knight"}) );
    set_short("%^BOLD%^%^BLACK%^A Dark Knight%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Though this knight is not a death knight it is one of "+
             "his underlings. He wears %^RESET%^armor%^BOLD%^%^BLACK%^ that looks to have been "+
             "scorched by %^RED%^fire%^BOLD%^%^BLACK%^ and his bones hold bits of %^RESET%^%^ORANGE%^rotted "+
             "flesh%^BOLD%^%^BLACK%^. His blazing %^RED%^red eyes%^BOLD%^%^BLACK%^ bore through you as "+
             "he looks you over and takes your worth.");
    set_race("knight");
    set_body_type("human");
    set_gender("male");
    set_alignment(9);
    set_size(2);
    set_class("fighter");
    set_mlevel("fighter",12);
    set_hd(10,0);
    set_max_hp(100);
    set_hp(100);
	set_new_exp(10, "normal");
    set_stats("strength",18);
    set_stats("constitution",15);
    set_stats("dexterity",12);
    set_stats("wisdom",10);
    set_stats("intelligence",18);
    set_stats("charisma",4);
    set_money("gold",random(300));
   set_money("silver",random(300));
    set_wielding_limbs( ({"left hand","right hand"}) );
    if(!random(30))
        new("/d/koenig/town/mon/weapons/darksword0.c")->move(TO);
    else
        new("/d/koenig/town/mon/weapons/darksword.c")->move(this_object());
    new("/d/koenig/town/mon/weapons/darksword.c")->move(this_object());
    new("/d/koenig/town/items/ldeatharmor.c")->move(this_object());
    command("wear armor");
    command("wield sword");
    command("wield sword 2");
    set_overall_ac(6);
}

void die(mixed ob) {
   object tmp;
   tell_room(ETO,"%^BOLD%^%^BLUE%^"+query_cap_name()+" drops dead before you.");
    tell_room(ETO,"%^BOLD%^%^BLUE%^As "+TO->query_cap_name()+" dies the body is consumed by a strange and magical blue fire!");
// added this to make the corpse disappear but at least leave gold *Styx*  1/28/03
    tmp=new("/std/obj/coins");
    tmp->add_money("gold",random(200)+200);
    tmp->move(ETO);
    TO->move("/d/shadowgate/void");
   ::die(ob);
}
