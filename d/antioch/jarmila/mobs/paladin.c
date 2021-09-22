#include <std.h>
#include <security.h>
#include "../jarmila.h"

inherit MONSTER;

void do_greeting();
object bork_control;

int talked;

void create()
{
    int mylevel = 65;
    ::create();
	talked=0;
    set_name("Rosalind de Montbard");
    set_id(({ "paladin", "guard", "paladin guard", "pguard", "Paladin",
"avatar",}));
    set_short("%^C229%^Ros%^C230%^a%^C229%^lind "+
	"de M%^C230%^o%^C229%^ntb%^C230%^a%^C229%^rd, "+
	"%^C252%^Paladin%^C229%^ of the %^C197%^Rose%^C229%^");
    set_long("%^C229%^Dressed in gleaming heavy armor "+
	"and resting a wonderous sword on her lap, this "+
	"woman is the very image of a paladin. Her equipment "+
	"is immacutely cared for and her clothing cut to a "+
	"tailor's eye. She has a powerful frame and strong, "+
	"yet her movements are fluid and graceful as a "+
	"dancer. Long blonde hair cascades over her shoulderes "+
	"and frames an extiquisitely beautiful face.%^C229%^");
   set_race("deva");
    set_gender("female");
    set_body_type("human");
    set_overall_ac(-70);
    set_alignment(1);

    set("aggressive", 2);
    set_property("swarm", 0);

    set_level(mylevel);
    set_class("paladin");
    set_mlevel("paladin", mylevel);
    set_mlevel("cleric", mylevel);

    set_property("no hold", 1);
    set_property("no death", 1);

    set_max_hp(18 * mylevel + 6000);
    set_hp(query_max_hp());
    set_property("spell damage resistance", 60);
    set_mob_magic_resistance("high"); 
    set_property("damage resistance", 10);

    set_new_exp(mylevel, "boss");

    set("aggressive", 0);
    set_stats("strength", 22);
    set_stats("wisdom", 22);
    set_stats("intelligence", 12);
    set_stats("constitution", 22);
    set_stats("charisma", 26);
    set_stats("dexterity", 18);
    set_diety("jarmila");

    set("speech string", "intone");
    set("describe string", "powerfully");

    new("/d/magic/symbols/jarmila_symbol.c")->move(TO);
    force_me("wear symbol");

    set_thief_skill("perception", 55);

    {
        object obj;
        int ench = 7;

        obj = new("/d/magic/obj/shields/jarmila");
        obj->set_property("enchantment", ench);
        obj->move(TO);
        obj->set_property("monsterweapon", 1);
        force_me("wear shield");

        obj = new("/d/islands/common/obj/new/gdblade");
        obj->set_property("enchantment", ench);
        obj->move(TO);
        obj->set_property("monsterweapon", 1);
        force_me("wield weapon");
    }

    set_monster_feats(({
        "reflection",
        "counter",
        "deflection",
        "parry",
        "shieldbash",
        "shieldwall",
        "rush",
        "smite",
    }));

    set_spells(({ "sunbeam",
                  "holy smite",
                  "sunburst", }));

    set_spell_chance(66);

    set_funcs(({ "rushit", "bashit", "smiteit" }));
    set_func_chance(66);

    set_property("cast and attack", 1);
    set_property("function and attack", 1);
	force_me("pose %^ORANGE%^Sitting on a sunstone, a sword across her lap%^RESET%^");
}

void rushit(object targ)
{
    TO->force_me("rush " + targ->query_name());
}

void smiteit(object targ)
{
    TO->force_me("smite");
}

void bashit(object targ)
{
    TO->force_me("shieldbash " + targ->query_name());
}

void die(object obj)
{
   bork_control =find_object_or_load(ROOMS"top.c");
        tell_room(ETO,"death? not worky",ETO);
        bork_control->turning(0);
    return ::die(obj);

}

void init()
{
    ::init();
    if (!interactive(TP)) {
        return;
    }
        call_out("do_greeting", 1, TP);
        return;
}
		
	
void heart_beat()
{
    object* user;
    int i, j;

    ::heart_beat();

    if(!this_object())
        return;

    if (sizeof(TO->query_attackers())) {
        if (!TO->query_property("angelic_aspect")) {
            new("/cmds/spells/g/_greater_angelic_aspect")->use_spell(TO,
TO, 70, 100);
        }

        if (TO->query_hp() < TO->query_max_hp() / 2) {
            if (!random(8)) {
                new("/cmds/spells/h/_heal")->use_spell(TO, TO, 30, 100);
            }
        }
    }
}

void speak(string msg)
{
    force_me("say %^YELLOW%^" + msg + "%^RESET%^");
}

void do_greeting()
{
    if(talked==1){speak("Lets do this!");return;}
	
	else{
speak("I am glad you have came. The view is too beautiful to not share.");
        tell_room(ETO,"%^C226%^\nThe glow radiates from the paladin%^CRST%^\n");
        speak("Am I not what you expected from your climb?");
        tell_room(ETO,"%^C100%^\nShe chuckles and looks out on the horizon.%^CRST%^\n");
                speak("You may not want to, but we need to fight. My death will bring her power and her love. She will fight you as well. To help your rebirth.");
		tell_room(ETO,"%^C008%^\nShe tightens the clasps on her armor and waits for your move.%^CRST%^\n%^");
	talked = 1;
    return 1;
	}
}
