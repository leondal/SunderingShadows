#include <std.h>
inherit "/std/comp_vend.c";

int timer;
string owner;

void create(){
        ::create();
        remove_std_db();
        remove_dbs(({"alchemist"}));
        remove_random_act_dbs(({"alchemistrandom"}));
        set_name("Jelzaba");
        set_short("Jelzaba the Genie, procurer of rare ingredients");
        set_id(({"jelzaba","Jelzaba","genie","Genie"}));
        set_long("%^RESET%^%^CYAN%^A long, muscular %^BOLD%^%^BLUE%^blue-skinned %^RESET%^%^CYAN%^torso rising "
"at the waist from a spill of %^BOLD%^%^MAGENTA%^p%^RESET%^%^MAGENTA%^urp%^RED%^li%^RESET%^%^CYAN%^sh b%^BOLD%^"
"%^BLUE%^lu%^CYAN%^e %^RESET%^%^CYAN%^smoke, this is the first thing most notice about %^BOLD%^Jelzaba the "
"Genie%^RESET%^%^CYAN%^. As eyes travel upward they take in the open front, %^GREEN%^emerald silk %^CYAN%^and %^ORANGE%^"
"gold braid %^CYAN%^sleeveless vest he wears, along with the two muscular arms, clad in a king's ransom worth "
"of %^ORANGE%^golden bangles %^CYAN%^and %^MAGENTA%^j%^BOLD%^%^BLUE%^e%^RED%^w%^GREEN%^e%^RESET%^%^MAGENTA%^l"
"%^BLUE%^s%^RESET%^%^CYAN%^. Eventually one's vision rises high enough to take in the arresting lines of a "
"perfect masculine face, framed by thick waves of %^BOLD%^%^BLACK%^ebony hair%^RESET%^%^CYAN%^. Jewel toned "
"%^GREEN%^emerald eyes %^CYAN%^chased through with faint lines of %^BOLD%^%^BLUE%^blue %^RESET%^%^CYAN%^and "
"otherworldly %^MAGENTA%^magenta %^CYAN%^are highlighted by long %^BOLD%^%^BLACK%^black lashes%^RESET%^%^CYAN%^"
", while lush full lips angle up in an arrogant, lush bow. %^BOLD%^%^BLACK%^S%^RESET%^i%^BOLD%^%^WHITE%^l"
"%^RESET%^v%^BOLD%^%^BLACK%^ery %^RESET%^%^CYAN%^runes chase through the metallic %^BOLD%^%^BLUE%^blue skin "
"%^RESET%^%^CYAN%^of the left side of his face, adding a hint of the %^MAGENTA%^my%^BLUE%^s%^CYAN%^t%^BLUE%^ic"
"%^MAGENTA%^al %^CYAN%^in its revealing and concealing mask. Despite his dominating presence, his focus is for "
"one person and one person alone. The one whose will summoned him.%^RESET%^");
        set_gender("male");
        set_race("genie");
        set_body_type("human");
        set_hd(30,5);
        set_alignment(5);
        set_max_hp(150+random(30));
        set_hp(query_max_hp());
        set_overall_ac(-10);
        set_class("mage");
        set_mlevel("mage",30);
        set_level(30);
        set_stats("intelligence",20);
        set_stats("charisma",10);
        set_stats("dexterity",17);
        set_stats("wisdom",14);
        set_stats("constitution",12);
        set_stats("strength",13);
        set("aggressive",0);
        set_mob_magic_resistance("average");
        set_exp(100);
        set_spells(({"scorcher","ball lightning","disintegrate","lower resistance","gust of wind"}));
        set_spell_chance(100);
        set_components(100);
        set_property("knock unconscious",1);
      timer = 600+random(60);
      setenv("MIN", "$N drifts in.");
      setenv("MOUT", "$N drifts silently $D.");
      command("speech %^MAGENTA%^declare in a s%^BOLD%^%^BLACK%^il%^RESET%^%^MAGENTA%^ke%^RED%^n %^MAGENTA%^accent%^RESET%^");
      set_emotes(1, ({"%^BOLD%^%^BLUE%^Curls of smoke drift up around Jelzaba as he hovers near you."
"%^RESET%^","%^RESET%^%^CYAN%^The genie adjusts the %^ORANGE%^gold %^CYAN%^and %^GREEN%^emerald %^CYAN%^cloth "
"of his vest, smoothing the front panels down as he waits for a command.%^RESET%^","%^RESET%^%^ORANGE%^With a "
"snap of his fingers, Jelzaba summons a %^MAGENTA%^b%^BLUE%^%^BOLD%^e%^RED%^j%^RESET%^%^GREEN%^e%^YELLOW%^w"
"%^BLUE%^e%^RESET%^%^MAGENTA%^l%^BOLD%^%^RED%^e%^RESET%^%^MAGENTA%^d %^ORANGE%^box from out of thin air. After "
"inspecting the contents, he snaps his fingers again and the box vanishes in a puff of smoke.%^RESET%^",
"%^RESET%^%^GREEN%^The genie glances about the room, taking in each being present.%^RESET%^",}), 0);
      call_out("appear",1);
}

void set_owner(string str) { owner = str; }

void init() {
  ::init();
  add_action("dismissme_fun","dismissme");
}

void heart_beat() {
  ::heart_beat();
  if(!timer) TO->dismissed();
  timer--;
  if(owner) { if(!present(owner,ETO)) TO->dismissed(); }
}

void die(object ob) {
  if(!objectp(TO)) return;
  tell_room(ETO,"%^RESET%^%^CYAN%^With a snap of his fingers, Jelzaba vanishes from sight, leaving you to "
"ponder what vengeance a genie might take upon his attacker.%^RESET%^");
  TO->remove();
}

void appear() {
   command("say %^RESET%^%^CYAN%^'%^BOLD%^%^BLUE%^Salutations Master.%^RESET%^%^CYAN%^'%^RESET%^");
   tell_room(ETO,"%^RESET%^%^CYAN%^Jelzaba places the palms of his hands together and bows at the waist.%^RESET%^");
   command("say %^RESET%^%^CYAN%^'%^BOLD%^%^BLUE%^I have traveled far since last we met and bring you a "
"selection of the rarest components. You have but to ask, and I shall reveal a %^MAGENTA%^list%^BLUE%^ of them "
"to you. Simply %^MAGENTA%^dismissme%^BLUE%^ when you are done.%^RESET%^%^CYAN%^'%^RESET%^");
}

void dismissed() {
   command("say %^RESET%^%^CYAN%^'%^BOLD%^%^BLUE%^Farewell Master. May the many gods bless you with their "
"benevolence.%^RESET%^%^CYAN%^'%^RESET%^");
   command("emoteat jelzaba %^RESET%^%^CYAN%^$M vanishes in a puff of rolling %^BOLD%^%^BLUE%^electric blue "
"%^RESET%^%^CYAN%^smoke.%^RESET%^");
   TO->remove();
}

int __Buy(string str){
        if((string)TP->query_name() == owner) return ::__Buy(str);
        command("speech %^MAGENTA%^say with a %^GREEN%^ve%^CYAN%^no%^GREEN%^mous %^MAGENTA%^voice%^RESET%^");
        command("emoteat "+TP->query_name()+" %^RESET%^%^MAGENTA%^$M sneers at $N.");
        command("say %^RESET%^%^CYAN%^'%^BOLD%^%^BLUE%^As though I would serve someone like you. Begone! Like "
"the foul winds which blew you here.%^RESET%^%^CYAN%^'%^RESET%^");
        command("speech %^MAGENTA%^declare in a s%^BOLD%^%^BLACK%^il%^RESET%^%^MAGENTA%^ke%^RED%^n %^MAGENTA%^accent%^RESET%^");
        return 1;
}

int __List(string str){
        if((string)TP->query_name() == owner) return ::__List(str);
        command("speech %^MAGENTA%^say with a %^GREEN%^ve%^CYAN%^no%^GREEN%^mous %^MAGENTA%^voice%^RESET%^");
        command("emoteat "+TP->query_name()+" %^RESET%^%^MAGENTA%^$M sneers at $N.");
        command("say %^RESET%^%^CYAN%^'%^BOLD%^%^BLUE%^As though I would serve someone like you. Begone! Like "
"the foul winds which blew you here.%^RESET%^%^CYAN%^'%^RESET%^");
        command("speech %^MAGENTA%^declare in a s%^BOLD%^%^BLACK%^il%^RESET%^%^MAGENTA%^ke%^RED%^n %^MAGENTA%^accent%^RESET%^");
        return 1;
}

int __Help(string str){
        if((string)TP->query_name() == owner) return ::__Help(str);
        command("speech %^MAGENTA%^say with a %^GREEN%^ve%^CYAN%^no%^GREEN%^mous %^MAGENTA%^voice%^RESET%^");
        command("emoteat "+TP->query_name()+" %^RESET%^%^MAGENTA%^$M sneers at $N.");
        command("say %^RESET%^%^CYAN%^'%^BOLD%^%^BLUE%^As though I would serve someone like you. Begone! Like "
"the foul winds which blew you here.%^RESET%^%^CYAN%^'%^RESET%^");
        command("speech %^MAGENTA%^declare in a s%^BOLD%^%^BLACK%^il%^RESET%^%^MAGENTA%^ke%^RED%^n %^MAGENTA%^accent%^RESET%^");
        return 1;
}

int dismissme_fun(string str) {
    if(str) {
      notify_fail("Just <dismissme>.\n");
      return 0;
    }
    if((string)TP->query_name() != owner && !avatarp(TP)) {
      force_me("emoteat "+TP->query_name()+" pointedly ignores $N.");
      return 1;
    }
    TO->dismissed();
    return 1;
}