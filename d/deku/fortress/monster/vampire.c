#include <std.h>
#include "/d/deku/inherits/graveyard.h"
#include <daemons.h>
inherit WEAPONLESS;

void create() 
{
    ::create();
    set_name("A pale human");
    set_id(({"vampire","male"}));
    set_gender("male");
    set_race("human");
    set_short("A pale human");
    set_long("%^RESET%^This hideously scarred creature stands "+
    "close to six feet tall.  Its body is completely nude and "+
    "it is quite obviously male.  His eyes are a light %^RED%^"+
    "red%^RESET%^ that border on pink, his hair is a thin "+
    "%^BOLD%^%^BLACK%^black%^RESET%^ that is tossed loosely on "+
    "the top of his head.  The %^MAGENTA%^scarred%^RESET%^ flesh "+
    "of this man is an unnaturally pale white, suggesting "+
    "something far worse than a prolonged lack of sunlight.  "+
    "His body is muscled and well toned, revealing, even to the "+
    "most simple minded individual, an extreme physical strength.  "+
    "He occassionally throws his head back in a fit of wild "+
    "laughter and in those moments a hint of his true nature is "+
    "given in the form of two long and %^RED%^blood stained"+
    "%^RESET%^ fangs.");
    set_alignment(9);
    set("aggressive","leaveme");
    set_hd(24,1);
    set_hp(475 + random(21));
    set_new_exp(20, "high");
    set_stats("strength",20);
    set_stats("wisdom",14);
    set_stats("intelligence",13);
    set_stats("dexterity",19);
    set_stats("charisma",13);
    set_stats("constitution",0);
    set_property("no death",1);
    set_property("undead",1);
    set_property("full attacks",1);
    set_property("magic",1);
    set_property("weapon resistance",1);
    add_money("gold",3000 + random(1600));
    set_attack_limbs(({"left hand", "right hand"}));	    
    set_damage(4,6);
    set_attacks_num(5);
    set_overall_ac(-8);
    set_max_level(25);
}

void leaveme() 
{
    TO->force_me("speech growl");
    TO->force_me("say leave my presence!");
    TO->force_me("open glowing door");
    TO->force_me("kill "+TP->query_name());
    new("/cmds/spells/f/_fear")->use_spell(TO,TP,28,28,"cleric");
}

void die(object ob) 
{
    tell_room(ETO,"The pale human screams loudly in agony as his "+
    "broken body falls to the ground!");
    if(base_name(ETO) == GY_ROOMS+"tomb3") 
    {
        ETO->do_open();
    }
    ::die();
}
