//Thief for assassin quest by Bane//
#include <std.h>
inherit MONSTER;

void create(){
    ::create();
    set_id(({"thief","baston","Baston","traveller"}));
    set_name("baston");
    set_short("Baston, traveller of the realms");
    set_long(
@DESC
Baston is dressed in black from head to toe and wears a black eye 
patch over his left eye. He looks pretty strong, like he knows how
to use his weapons. From the way he keeps looking over his shoulder,
he seems to be worried about something. He appears to be very at home
in the shadows, as if he is part of some rogue guild.
DESC
    );
    set_gender("male");
    set_race("human");
    set_alignment(9);
    set_hd(20,4);
    set_class("thief");
    set_mlevel("thief",20);
    set_hp(200);
    set_exp(5000);
    set_overall_ac(-3);
    set_mob_magic_resistance("average");
    set_property("no dominate",1);
    set_property("no death",1);
    set("aggressive",0);
    set_guild_level("thief",20);
    set_emotes(7,({"Baston grumbles.","%^MAGENTA%^Baston says%^RESET%^: What the hell do you want?!","Baston looks around carefully.","Baston looks over his shoulder."}),0);
    new("/d/tharis/Tharis/cguilds/thief/ring")->move(TO);
    command("wear ring");
    new("/d/common/obj/weapon/shortsword")->move(TO);
    command("wield sword");
    new("/d/common/obj/weapon/dagger")->move(TO);
    command("wield dagger");
    set_stats("strength",20);
    set_stats("dexterity",20);
    set_thief_skill("hide in shadows",120);
    set_thief_skill("move silently",120);
    set_speed(20);
    set_scrambling(1);
}

void die(object ob) {
    object ob2, ob3;
    ob2 = query_current_attacker();
    if(!objectp(ob2)) ::die(ob);
    ob2->set_mini_quest("killed Baston", 0, "killed Baston");
    if(ob3 = present("Xring"))
        ob3->move(ob2);
    ::die(ob);
}
