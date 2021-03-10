#include <std.h>
inherit WEAPONLESS;

void init() {
    ::init();
    add_action("no_rush","rush");
   add_action("no_rush","toss");
   add_action("no_rush","throw");
}

void create(){
    ::create();
    set_name("intruder");
    set_property("no bows",1);
   set_property("no hold", 1);
    set_id( ({
	"intruder", "warrior", "general"
      }) );
    set("race", "undead");
    set_property("no_paralyze", 1);
    set_gender("male");
    set("short",
      "Intruder the Warrior General of the Kinnesaruda"
    );
    set_long(
      "Intruder is a powerful undead warrior.  His golden armor is gashed from earlier battles but still shines in places.  His face displays malice beneath a coat of rotting leathery flesh and shiny black eyes. "
    );
    set_hd(70,1);
    set_body_type("human");
    set_spell_chance(60);
    set_class("fighter");
    set_class("mage");
    set_mlevel("fighter", 70);
    set_mlevel("mage", 60);
    set_guild_level("fighter", 70);
    set_guild_level("mage", 60);
   set_overall_ac(-12);
    set_spells(({
	"cone of cold",
	"frost orb",
	"web",
	"chill touch",
	"greater shout",
	"greater shout",
	"chain lightning",
	"magic missile",
	"ray of enfeeblement",
	"frost orb"
      }));
     set_spell_chance(40);
    add_limb("forearm mounted blades","forearm mounted blades",96,1,4);
    add_limb("demon gaze","demon gaze",96,1,4);
    add_limb("mystic dagger","mystic dagger",96,1,4);
    add_limb("bonestripper","bonestripper",96,1,4);
    add_limb("mystic sword","mystic sword",96,1,4);
    add_limb("mystic spear","mystic spear",96,1,4);
   set_attacks_num(7);
    set_attack_limbs(({"mystic dagger", "mystic spear", "bonestripper", "demon gaze", "mystic sword", "forearm mounted blades"}));
    set_base_damage_type("piercing");
    set_damage(2,10);
    set("aggressive","aggfunc");
   set_mob_magic_resistance("average");
    set_property("no death",1);
    set_property("magic",1);
   set_alignment(3);
    set_size( 3 );
    set_hp(3000);
    set_sp(1500);
    set_funcs( ({"whistle"}) );
    set_func_chance(40);
    set_exp(120000);
    add_money("silver",random(210));
    add_money("gold",random(620));

    new("/d/attaya/obj/karmor.c")->move(this_object());
    command("wear armor");
    new("/d/attaya/obj/shoulderplate.c")->move(this_object());
    command("wear shoulderplates");
    new("/d/attaya/obj/crysknife.c")->move(TO);
//    new("/d/attaya/obj/doomsday.c")->move(this_object());
}
int no_rush(string str) {
    object targ;
    targ = this_player();
    command( "say Your pathetic attack is no match for my power, "+this_player()->query_cap_name()+". ");
    message("environment",
      "%^BOLD%^%^RED%^Thousands of glowing particles radiate from intruder and fly around the room before slamming into "+this_player()->query_cap_name()+"!\n"
      ,environment(targ));
    targ->do_damage("torso",roll_dice(10,6));
    return 1;
}
void die(object ob) {
    force_me("laugh");
    message("environment",
      "%^BOLD%^%^RED%^Intruder bleeds heavily onto the floor and drops to his knees!\n"
      ,environment(TO));
    force_me("say %^BOLD%^%^RED%^Heed my command, Ancient spirits of evil...  Avenge me and plunge this world into eternal darkness!");
    force_me("master");
    :: die(ob);
}
void whistle(){
    force_me ("whistle");
}
void mega(){
    force_me ("break seal");
}
void aggfunc() {
    string mrace=TP->query_race();
    if (mrace == "undead") {
	force_me ("grin");
	return 1;
    } else {
	if(wizardp(TP)) return 1;
	TP->kill_ob(TO,0);
	force_me("emote grins at you.");
	force_me("emote stands up and walks towards you!");
	force_me("say %^RED%^I have watched your approach, and for a time, I actually considered sparing your worthless little life.");
	force_me("say %^RED%^But now, you shall feel the wrath of the Kinnesaruda!");
	force_me("emote shrieks: %^RED%^Death to all who oppose my power...  I shall crush your entrails beneath my heel!");
	force_me("whistle");
	force_me("cackle very evilly");
    }
}
void set_paralyzed(int time,string message){return 1;}
