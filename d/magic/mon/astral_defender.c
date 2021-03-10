#include "summoned_monster.h"

inherit MONSTER;

string COLORS = ({"%^BLUE%^","%^RED%^","%^BLUE%^","%^RED%^","%^ORANGE%^","%^MAGENTA%^","%^GREEN%^","%^CYAN%^","%^WHITE%^"});

int create()
{
    ::create();
	set_name("defender");
    set_id(({"astral defender","monster","defender","prism","floating prism","summoned monster"}));
    set_race("construct");
	set_gender("neuter");
	set_short("%^RESET%^%^CYAN%^fl%^BOLD%^oa%^RESET%^%^CYAN%^t%^BOLD%^i%^RESET%^%^CYAN%^ng pr%^BOLD%^i%^RESET%^%^CYAN%^sm%^WHITE%^");
    set_long("%^CYAN%^This is a big floating prism made out of black stone. Surges of power zap out of it periodically with flashes of cyan energy.");
	set_body_type("human");
    set("aggressive",18);
    set_hd(6,1);
    set_alignment(5);
    set_size(2);
    set_stats("intelligence",10);
    set_stats("wisdom",12);
    set_stats("strength",16);
    set_stats("charisma",10);
    set_stats("dexterity",16);
    set_stats("constitution",10);
    set_hp(50);
    set_max_hp(query_hp());
    set_exp(500);
}

int set_p_desc(int power)
{
    string color;
    power = power<0?0:power;
    power = power>8?8:power;
    color = COLORS[power];
    TO->set_short("%^RESET%^"+color+"fl%^BOLD%^oa%^RESET%^"+color+"t%^BOLD%^i%^RESET%^"+color+"ng pr%^BOLD%^i%^RESET%^"+color+"sm%^WHITE%^");
    TO->set_long(""+color+"This is a big floating prism made out of black stone. Surges of power zap out of it periodically with flashes of cyan energy.");
}

int die()
{
    if(objectp(environment(TO)))
        tell_room(environment(TO),"%^CYAN%^Prism is too damaged and vanishes.%^RESET%^");
    TO->remove();

    ::die();
    return 1;
}
