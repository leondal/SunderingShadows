#include <std.h>
#include "summoned_monster.h"
inherit MONSTER;

void set_mytype(string heritage);
string myheritage;

void create() {
    ::create();
    set_name("outsider");
    set_id(({"outsider"}));
    set_long("This is an outsider.");
    set_hd(2,1);
    set_hp(16);
    set_body_type("humanoid");
    set_attack_limbs(({"left hand","right hand"}));
    set_damage(1,3);
    set_attacks_num(1);
    set_base_damage_type("piercing");
    set_gender("neuter");
    set_race("outsider");
}

void set_mytype(string heritage) {
    myheritage = heritage;
    switch(heritage) {
    case "celestial":
        set_short("%^RESET%^%^ORANGE%^bright coure%^RESET%^");
        set_name("bright coure");
        set_id(({"outsider","bright coure","coure"}));
        set_long("%^RESET%^%^ORANGE%^This tiny being appears much like a slender elf, but shrunk to an improbable size, and clad in an equally improbable array of "
"%^BOLD%^%^MAGENTA%^bright %^RESET%^%^ORANGE%^and utterly mismatched garments. Unruly, glistening %^YELLOW%^golden hair %^RESET%^%^ORANGE%^curls about pointed ears "
"that jut to either side of a face that appears almost perpetually given to a smile. Bright %^BOLD%^%^CYAN%^crystalline eyes %^RESET%^%^ORANGE%^survey its "
"surroundings with active curiosity. %^RESET%^Gossamer wings %^ORANGE%^carry the little celestial about with seemingly ceaseless energy. As you watch, it "
"occasionally blinks in and out of its humanoid form to become a tiny ball of %^YELLOW%^bright light%^RESET%^%^ORANGE%^.%^RESET%^");
        set_fake_limbs(({"torso","head","vine"}));
        set_attack_limbs(({"torso","head""vine"}));
        break;

    case "fey":
        set_short("%^RESET%^%^CYAN%^lively sprite%^RESET%^");
        set_name("lively sprite");
        set_id(({"outsider","lively sprite","sprite"}));
        set_long("%^RESET%^%^CYAN%^This fey creature looks in some ways very much like an elf, although it would be lucky to surpass much more than a foot in height. "
"It bears a slender frame clad in loose and %^RESET%^flimsy %^CYAN%^garments that do little to hide its form. Sharply pointed ears peek forth from beneath a wave of "
"vibrant %^BOLD%^%^BLUE%^cobalt hair%^RESET%^%^CYAN%^, while its skin is a %^BOLD%^%^CYAN%^pale azure %^RESET%^%^CYAN%^swirled with lines of %^BOLD%^%^WHITE%^snowy "
"white%^RESET%^%^CYAN%^. Diaphanous wings rise from its shoulders, bearing it aloft with a rapid flutter. Its %^BOLD%^%^BLUE%^sapphire eyes %^RESET%^%^CYAN%^gleam "
"with mischief, and it occasionally winks in and out of view as you watch.%^RESET%^");
        set_fake_limbs(({"wings"}));
        set_attack_limbs(({"right hand","left hand"}));
        break;

    case "abyssal":
        set_short("%^RESET%^%^GREEN%^demonic quasit%^RESET%^");
        set_name("demonic quasit");
        set_id(({"outsider","demonic quasit","quasit"}));
        set_long("%^RESET%^%^GREEN%^This little demon has a humanoid shape, and stands perhaps only a foot and a half tall. A broad spread of %^RED%^bat-wings "
"%^GREEN%^bear it aloft, covered in the same %^BOLD%^%^GREEN%^sickly-greenish skin %^RESET%^%^GREEN%^that encloses the rest of its tiny frame. %^ORANGE%^Warts "
"%^GREEN%^and %^BLUE%^pustules %^GREEN%^mark its long and slender body, from its horn-spiked head to the tip of its tapered tail. Its eyes gleam with a %^YELLOW%^sharp "
"intellect%^RESET%^%^GREEN%^, and you suspect its viciously sharp claws and teeth could do considerable damage despite its size. The creature occasionally winks in and "
"out of view as you watch.%^RESET%^");
        set_fake_limbs(({"tail","wings","claws","teeth"}));
        set_attack_limbs(({"claws","teeth"}));
        break;

    case "astral":
        set_short("%^BOLD%^%^BLACK%^night gaunt%^RESET%^");
        set_name("night gaunt");
        set_id(({"outsider","night gaunt","gaunt"}));
        set_long("%^BOLD%^%^BLACK%^This thing has a slender humanoid body with stretched and spindly limbs, all covered in a rubbery black skin. Sharp talons extend from their ugly prehensile paws, and two leathery wings jut out from their back. A long %^RESET%^barbed tail %^BOLD%^%^BLACK%^lashes back and forth needlessly. Its head is crowned by a pair of curved horns, but where one might expect a face is only a blank expanse of senseless flesh. It moves silently but with a %^RESET%^%^MAGENTA%^hungry %^BOLD%^%^BLACK%^purpose.%^RESET%^");
        set_fake_limbs(({"claws","wings","horns"}));
        set_attack_limbs(({"claws","horns"}));
        break;
		
    case "gloom":
        set_short("%^RESET%^%^BLUE%^winged shadow%^RESET%^");
        set_name("winged shadow");
        set_id(({"outsider","winged shadow","shadow"}));
        set_long("%^RESET%^%^BLUE%^This creature is difficult to discern, being made entirely from the stuff of %^BOLD%^%^BLACK%^shadows%^RESET%^%^BLUE%^, and can "
"be difficult at times to track visually as it fades in and out of view. Tiny, at only a couple feet tall, it has a vaguely humanoid form with limbs that fade away "
"to wisps of %^RESET%^mist %^BLUE%^and darkness. %^BOLD%^%^BLACK%^Black wings %^RESET%^%^BLUE%^rise up and out to either side of its frame, keeping the creature aloft "
"with seemingly effortless motions. Its features are nearly impossible to make out, except for the %^BOLD%^%^RED%^glowing crimson embers %^RESET%^%^BLUE%^that must "
"serve as the creature's eyes.%^RESET%^");
        set_fake_limbs(({"wings","claws"}));
        set_attack_limbs(({"wings","claws"}));
        break;

    case "infernal":
        set_short("%^RESET%^%^RED%^devilish imp%^RESET%^");
        set_name("devilish imp");
        set_id(({"outsider","imp","devilish imp"}));
        set_long("%^RESET%^%^RED%^This tiny humanoid stands at barely two feet tall, although its %^ORANGE%^leathery bat-wings %^RED%^spread easily as far again to "
"either side. Its face is all sharp angles, with a %^BOLD%^%^BLACK%^tapered beard%^RESET%^%^RED%^, sharply pointed ears, and several smaller ridges that run across its "
"skull between the two taller, twisted horns. Its %^YELLOW%^amber eyes %^RESET%^%^RED%^glow with a malevolent light as it surveys its surrounds. A scorpion's segmented "
"tail curls into the air behind it, complete with a %^GREEN%^stinger %^RED%^at its end. The creature occasionally winks in and out of view as you watch.%^RESET%^");
        set_fake_limbs(({"tail","wings","claws"}));
        set_attack_limbs(({"claws","tail"}));
        break;
    }
}

void die(object ob) {
   switch(myheritage) {
     case "celestial": tell_room(ETO,"%^YELLOW%^The coure blinks out of existence in a flash of bright light!%^RESET%^"); break;
     case "fey": tell_room(ETO,"%^BOLD%^%^CYAN%^The sprite flits unsteadily left, right, and quite suddenly vanishes!%^RESET%^"); break;
     case "abyssal": tell_room(ETO,"%^BOLD%^%^GREEN%^The quasit hisses, flits backwards and pops quite suddenly out of existence!%^RESET%^"); break;
     case "astral": tell_room(ETO,"%^BOLD%^%^BLACK%^The night gaunt melts into a strange pool and fades away!%^RESET%^"); break;
	 case "gloom": tell_room(ETO,"%^RESET%^%^BLUE%^The shadow flutters, whirls and disappears!%^RESET%^"); break;
     case "infernal": tell_room(ETO,"%^BOLD%^%^RED%^The imp shrieks and blinks out of existence!%^RESET%^"); break;
     default: tell_room(ETO,"The spirit shrieks and disappears!"); break;
   }
   TO->remove();
}