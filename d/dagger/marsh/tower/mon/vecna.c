#include <std.h>
#include <daemons.h>
#define VHAND "/d/dagger/marsh/tower/obj/hand.c"

inherit WEAPONLESS;
string *handsp;
int Gbl;

void create() {
    object ob;
    ::create();
    handsp = ({"caress", "healing", "web", "bolt", "flame"});
    set_name("vecna");
    set_id( ({"lich","arch lich","arch lich vecna", "vecna"}) );
    set_short("%^BOLD%^%^BLACK%^Vecna, Arch Lich of Deepingdale%^RESET%^");
    set_long(
        "The apparation that stands before you is a humanoid creature that appears to be undead. Its snarling lips show a jagged row of bony teeth. Its eyes blaze with a black hatred that stares deep into your soul. Judging by its incredibly evil appearance and surroundings, this can only be Vecna."
        );
    set_race( "undead" );
    set_property("undead",1);
    set_alignment(9);
    set_hd(50,1);
    set_class("fighter");
    set_mlevel("fighter", 50);
    set_class("mage");
    set_mlevel("mage",60);
    set_guild_level("mage",60);
    set_gender("male");
    set("aggressive",200);
    add_money("gold",random(15000)+15000);
    set_stats("strength", 25);
    set_stats("constitution", 25);
    set_stats("dexterity", 14);
    set_stats("wisdom", 25);
    set_stats("intelligence", 25);
    set_stats("charisma", 25);
    set_body_type("humanoid");
    set_max_hp(20000);
    set_hp(query_max_hp());
    set_size(2);

    new("/d/dagger/marsh/tower/obj/speedboots.c")->move(TO);
    new("/d/dagger/marsh/tower/obj/dagger_sarfice.c")->move(TO);
    new("/d/dagger/marsh/tower/obj/psicirclet.c")->move(TO);

    if (!random(5)) {
        new("/d/common/obj/misc/tools/portable_crystal_ball.c")->move(TO);
    }

    new(VHAND)->move(TO);
    TO->force_me("attach hand");
    force_me("wearall");
    set_funcs( ({"special", "use_hand", "cast_spells","cast_spells","cast_spells","use_hand"}) );
    set_property("add kits",75);
    set_func_chance(100);
    set_exp(500000);
    set_property("full attacks", 1);
    set_attacks_num(6);
    set_property("weapon resistance", 1);
    set_property("no steal", 1);
    set_property("no paralyze", 1);
    set_property("no tripped",1);
    set_property("magic", 1);
    set_property("no death", 1);
    set_property("no hold", 1);
    set_property("no bows", 1);
    set_mob_magic_resistance("average");
    set_property("spell damage resistance", 30);
    set_property("fire resistance", 10);
    set_emotes(10, ({
                "%^MAGENTA%^Vecna yells out: %^BOLD%^%^RED%^CARESS%^RESET%^ while pointing a mummified finger at you!",
                    "%^MAGENTA%^Vecna yells out: %^BOLD%^%^RED%^HEALING%^RESET%^ while pointing a mummified finger at you!",
                    "%^MAGENTA%^Vecna yells out: %^BOLD%^%^RED%^BOLT%^RESET%^ while pointing a mummified finger at you!",
                    "%^MAGENTA%^Vecna yells out: %^BOLD%^%^RED%^FLAME%^RESET%^ while pointing a mummified finger at you!",
                    "%^MAGENTA%^Vecna yells out: %^BOLD%^%^RED%^WEB%^RESET%^ while pointing a mummified finger at you!",
                    "%^BOLD%^%^RED%^Vecna rubs a great bloody hand across your chest, causing you to scream in pain!",
                    "%^BLUE%^%^BOLD%^Vecna spits a moldy tooth at you.",
                    "%^BOLD%^%^BLACK%^Your heart is crushed by the deepest of despair!",
                    }), 1);
    new("/d/magic/obj/orb_of_scrying.c")->move(TO);
    ob = new("/d/common/obj/brewing/herb_special_inherit");
    ob->set_herb_name("lich dust");
    ob->move(TO);
    set_monster_feats(({ "perfect caster","spell penetration","greater spell penetration" }));
    set_property("cast and attack",1);
    set_property("function and attack",1);
}

void hitem()
{
    int i;

    for(i=0;i<7;i++)
    {
        if(objectp(TO)) { TO->execute_attack(); }
    }
}


void init()
{
    ::init();
    if (!query_property("blinking")) {
        new("/cmds/spells/b/_blink.c")->use_spell(TO, TO, 70, 100, "mage");
    }
    if (!query_property("Gflagprop")) {
        new("/cmds/spells/s/_stoneskin")->use_spell(TO, TO->query_name(), 70, 100, "mage");
        Gbl = 40;
        set_property("Gflagprop", 1);
    }
    if (!wizardp(TP) && !TP->query_true_invis() && userp(TP)) {
        kill_ob(TP, 1);
    }
}


/*
int no_cast(string str) {
   object targ;
   targ = this_player();
   tell_object(targ, "That simply will not work!");
   return 1;
}
*/

void special(object targ){
    int dam;

    hitem();
    TO->force_me( "say Now I shall bring about your enslavement!");
    TO->force_me( "say Once I am finished with you, all shall perish!");
    TO->force_me("watch");
    tell_object(targ, "%^BOLD%^%^BLUE%^Vecna drains the life force of your soul!%^RESET%^");
    tell_room(ETO, "%^BOLD%^%^BLUE%^Vecna drains the life force of "+targ->query_cap_name()+"'s soul!%^RESET%^", targ);
    dam = to_int(targ->query_max_hp() * 0.55);
    set_property("noMissChance",1);
    targ->do_damage("torso",dam);
    set_property("noMissChance",-1);
    targ->set_paralyzed(14,"%^MAGENTA%^You are stunned by the blow and unable to move!%^RESET%^");
    TO->force_me("cackle "+targ->query_name());
    return 1;
}

void use_hand(object targ){
    string str;

    hitem();

    if(sizeof(handsp)) {
      str = handsp[random(sizeof(handsp))];
    } else {
      str = "default";
    }
    if((TO->query_hp() < 500) && member_array("healing", handsp))
      str = "healing";

    switch(str){
      case "caress":
          set_property("noMissChance",1);
        force_me("caress "+targ->query_name());
        set_property("noMissChance",-1);
        //handsp -= ({"caress"});
        break;
      case "heal":
        force_me("healing vecna");
        //handsp -= ({"healing"});
        break;
      case "bolt":
          set_property("noMissChance",1);
        force_me("bolt "+targ->query_name());
        set_property("noMissChance",-1);
        //handsp -= ({"bolt"});
        break;
      case "flame":
          set_property("noMissChance",1);
        force_me("flame "+targ->query_name());
        set_property("noMissChance",-1);
        //handsp -= ({"flame"});
        break;
      case "web":
        force_me("web "+targ->query_name());
        //handsp -= ({"web"});
        break;
      default:
        tell_room(ETO, "%^BOLD%^Vecna glows as his wounds seem to recover of their own accord.");
        add_hp(100);
        break;
    }
}

void cast_spells(object targ){
    int X;
    object merc;
    X = 9;

    hitem();

    if(objectp(merc = present("merc",ETO)))
    {
        new("/cmds/spells/f/_finger_of_death")->use_spell(TO,merc,65,100,"mage");
    }

    if(objectp(present("corpse",ETO)))
    {
        tell_room(ETO, "%^BOLD%^%^BLACK%^RISE AND SERVE%^RESET%^");
        if(random(3))
            new("/cmds/spells/c/_create_undead")->use_spell(TO,TO,70,100,"mage");
        else
            new("/cmds/spells/c/_create_greater_undead")->use_spell(TO,TO,70,100,"mage");
    }

    if(!random(3)&&!objectp(present("corpse",ETO)))
    {
        new("/cmds/spells/e/_exhume_corpses")->use_spell(TO,TO,70,100,"mage");
    }

    switch(random(X)){
    case 0:
        new("/cmds/spells/c/_circle_of_death")->use_spell(TO,targ,50,100,"mage");
        break;
    case 1:
        new("/cmds/spells/f/_fireball")->use_spell(TO,targ,95,100,"mage");
        break;
    case 2:
        new("/cmds/spells/c/_cone_of_cold")->use_spell(TO,targ,85,100,"mage");
        break;
    case 3:
        new("/cmds/spells/w/_waves_of_exhaustion")->use_spell(TO, targ,65,100,"mage");
        break;
    case 4:
        new("/cmds/spells/r/_ray_of_enfeeblement")->use_spell(TO,targ,85,100,"mage");
        break;
    case 5:
        new("/cmds/spells/m/_magic_missile")->use_spell(TO,targ,85,100,"mage");
        break;
    case 6:
        new("/cmds/spells/g/_globe_of_invulnerability")->use_spell(TO,TO,65,100,"mage");
        break;
    case 7:
        new("/cmds/spells/c/_cloudkill")->use_spell(TO,TO,45,100,"mage");
        break;
    case 8:
        tell_room(ETO, "%^BOLD%^Vecna starts to move around the room at an inhuman speed.");
        Gbl = 30;
        break;
    }
}



void heart_beat() {
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(query_hp() < query_max_hp())
      add_hp(50);
    if(Gbl > 0)
      Gbl--;
}
void set_paralyzed(int time,string message){return;}

void die(object ob){
    object ob2;
    ob2 = present("hand");
    if(objectp(ob2)) ob2->remove();
    new(VHAND)->move(TO);
    WORLD_EVENTS_D->kill_event("Waking An Ancient Evil");
    WORLD_EVENTS_D->inject_event((["Banishing An Ancient Evil" : (["start message" : "%^BOLD%^%^CYAN%^The death of an ancient "+
    "evil has temporarily manipulated the weave world wide.... for the next %^BOLD%^%^WHITE%^45 minutes%^BOLD%^%^CYAN%^ monsters "+
    "will have a %^BOLD%^%^WHITE%^10%%^BOLD%^%^CYAN%^ increased chance to drop random treasure!%^RESET%^",
    "event type" : "treasure drop rate", "length" : 45,
    "notification" : "10% increased random treasure drop rate!", "event name" : "Banishing An Ancient Evil", "modifier" : 10, "announce" : 1, "announce to" : "world" ]),]));
    ::die(ob);
}

int query_blinking() { return Gbl; }
