
#include <std.h>

inherit MONSTER;

void create()
{
  ::create();
    set_property("undead",1);
    set_mob_magic_resistance("average");
    set_name("deathknight");
    set_id( ({"DeathKnight","deathknight","knight"}) );
    set_short("%^BOLD%^%^BLACK%^A Death Knight%^RESET%^");
    set_long("%^RESET%^This knight is a horror to behold. Its face is a %^BOLD%^%^BLACK%^blackened "+
             "skull%^RESET%^ covered with shards of %^BOLD%^%^BLACK%^shriveled%^RESET%^, %^ORANGE%^rotting flesh%^RESET%^. "+
             "It has two tiny, %^BOLD%^%^RED%^gl%^RESET%^%^RED%^o%^BOLD%^%^RED%^wing red%^RESET%^ pinpoints for eyes. "+
             "It stands well over 6-feet tall and is a hulking mass of "+
              "unadulterated evil. His eyes seem to bore through you "+
             "and down to your soul, leaving you feeling %^BOLD%^%^BLACK%^cold%^RESET%^.");
    set_race("deathknight");
    set_body_type("human");
    set_gender("male");
    set_alignment(9);
    set_size(3);
    set_hd(20,0);
    set_max_hp(200);
	set_new_exp(10, "normal");
    set_hp(200);
    set_stats("strength",18);
    set_stats("constitution",15);
    set_stats("dexterity",12);
    set_stats("wisdom",15);
    set_stats("intelligence",18);
    set_stats("charisma",4);
    set_wielding_limbs( ({"left hand","right hand"}) );
    new("/d/koenig/town/mon/weapons/deathsword.c")->move(this_object());
    new("/d/koenig/town/mon/weapons/deathdagger.c")->move(this_object());
    new("/d/koenig/town/items/deatharmor.c")->move(this_object());
    command("wear armor");
    command("wield sword");
    command("wield dagger");
    set_overall_ac(6);
}

void die(mixed ob) {
   object *contents, tmp;
    int i;
    int j;
message("other_action","%^BOLD%^%^BLUE%^"+query_cap_name()+" drops dead "
        "before you.",environment(this_object()),({ this_object()}));
message("otheraction","%^BOLD%^%^BLUE%^As "+TO->query_cap_name()+" dies "
        "the body is consumed by a strange and magical blue fire!",
         environment(this_object()),({ this_object() }));
if(!random(30))
    new("/d/koenig/town/mon/weapons/deathsword0.c")->move(environment(TO));
if(!random(20))
    new("/d/koenig/town/items/deatharmor.c")->move(environment(TO));
if(!random(10))
    new("/d/koenig/town/mon/weapons/deathdagger.c")->move(environment(TO));
    new("/d/common/obj/weapon/two_hand_sword.c")->move(ETO);
    tmp=new("/std/obj/coins");
    tmp->add_money("gold",1000);
    tmp->move(ETO);
// changed because it wasn't calling ::die()  *Styx*  1/27/03
//    contents = all_inventory(this_object());
//    j = sizeof(contents);
//    for(i=0;i<j;i++) contents[i]->move("/d/shadowgate/void");
    TO->move("/d/shadowgate/void");
    ::die(ob);
}
