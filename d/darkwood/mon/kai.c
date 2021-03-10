#include <std.h>
#include "/d/darkwood/darcy/darcy.h"

inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_name("Lord Kai");
    set_id(({"kai","archlord","lord kai", "lord"}));
    set_short("Lord Kai the Despot, deposed Archlord of Shadow");
    set_long(
@DARKWOOD
  Kai the Despot was one of the 3 immortal Archlords in the old
Kingdom of Shadow. He deposed great and wise governence for evil
rule, and was soon banished in turn by the rightful wrath of the
gods, to a land of darkness.

  Lord Kai's powers are tremendous, fortunately balanced by his
supreme pomposity and foolishness.  After his long exile, he has
finally convinced himself that he left of his own accord and that
the present rulers of Shadow are usurpers.  He now leads his Death's
Head Legion into battle with Aloysius' armies to lay his claim on
complete domination of Shadow.

  Although he fights with Aloysius, no one doubts that his only
loyalty is to himself.

DARKWOOD
    );
    set_gender("male");
    set_hd(45,6);
    set_size(3);
    set_overall_ac(-1);
    set_class("antipaladin");
    set_guild_level("fighter",45);
    set_guild_level("antipaladin",45);
    set_max_hp(600);
    set_hp(600);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_race("fallen immortal");
    set_property("swarm",1);
    set("aggressive", 23);
    set_property("no_bump",1);
    set_stats("dexterity",25);
    set_stats("constitution",17);
    set_stats("strength",25);
    set_mob_magic_resistance("average");
    set_alignment(9);
    set_exp(75000);
    set_emotes(5,({
        "%^BOLD%^%^GREEN%^Lord Kai sneers as he tosses you in the air like a leaf!",
        "Lord Kai curses you and threatens you with a torrent of curses!",
        "%^MAGENTA%^Lord Kai says:%^RESET%^ I will destroy your little world, and burn its ashes.",
        "Lord Kai pauses for a second, as if reaching for some long-lost power...."
    }),0);
    set_funcs(({"desoul", "axis", "allies"}));
    set_func_chance(40);
    ob=new("/d/attaya/obj/karmor.c");
    if(random(50) < 49) ob->set_property("monsterweapon",1);
    ob->move(this_object());
    command("wear armor");
    ob=new("/d/attaya/obj/shoulderplate.c");
    ob->set_short("Golden Shoulderplates");
    ob->set_property("monsterweapon",1);
    ob->move(this_object());
    command("wear shoulderplates");
    ob = new("/d/shadow/obj/weapon/longsword");
    ob->set_id(({"katana","Katana", "shatterstar"}));
    ob->set_size(3);
    ob->set_wc(3,6);
    ob->set_name("Shatterstar");
    ob->set_short("Shatterstar, Katana of the Archlord");
    ob->set_long("Shatterstar is the evil blade forged by the Archlord Kai in the dark "+
        "days of his rule.  Its black blade is forged from the very cold of the Void itself."
        );
    ob->set_property("enchantment",6);
    if(random(40) < 39) ob->set_property("monsterweapon",1);
    ob->move(TO);
    command("wield shatterstar in left hand");
    new( EQUIPDIR+"desecrator" )->move(TO);
    command("wield sword in right hand");
}

void die(object ob) {
    message("environment",
     "%^BOLD%^%^GREEN%^Lord Kai is cast back into the Darkness, his sneer fading into distance."
    ,environment(TO));
    force_me("scream");
    :: die(ob);
}
void desoul(object targ) {
    string dam;
    if("daemon/saving_d"->saving_throw(targ,"poison")) {
        dam="hurts";
    } else {
        dam="poisons";
    }
   tell_room(environment(targ),
    "%^MAGENTA%^Lord Kai raises his hands to the sky and a vortex of light forms above "+
    targ->query_cap_name()+".",targ);
    tell_object(targ,
       "%^BOLD%^%^MAGENTA%^Suddenly, several phantasmic daggers drop from the vortex."
       "  The mass of shadows congeals again inside your flesh and "+dam+
        " you!%^RESET%^"
    );
    tell_room(environment(targ),
       "%^MAGENTA%^several phantasmic daggers drop from the vortex and pierce"
       +targ->query_cap_name()+"!",targ);
    if(dam=="poisons") {
        targ->do_damage("torso",roll_dice(5,10));
        targ->add_poisoning(30);
        tell_object(targ,
     "%^BOLD%^%^BLACK%^The living shadows wrap wround your internal organs "+
     "and try to squeeze the life from them."
        );
        targ->set_paralyzed(random(30)+10,
             "%^BOLD%^%^RED%^Your very spirit wages a battle inside your body!"
        );
    } else {
        targ->do_damage("torso",roll_dice(7,10));
    }
    return 1;
}

void heart_beat(){
   ::heart_beat();
  if(!objectp(TO)) return;
  if((TO->query_hp()+2) > TO->query_max_hp())
    TO->set_hp(TO->query_max_hp());
  else TO->add_hp(2);
}

void axis(){
       force_me ("axis");
}
void allies(){
       force_me ("allies");
}
