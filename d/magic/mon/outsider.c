#include "summoned_monster.h"
inherit WEAPONLESS;

object cast;
int mylevel, myalign, iselemental;
void setup_beastie(object caster, int beastalign);
string fname, castname;

void create()
{
    ::create();
    set_name("outsider");
    set_id(({ "outsider", "greater summon" }));
    set("short", "outsider");
    set("long", "this is an outsider");
    set_hd(4, 1);
    set_hp(40);
    set_exp(1);
    set_size(3);

    set_stats("strength", 20);
    set_stats("constitution", 20);
    set_stats("dexterity", 5);
    set_race("outsider");
    set_gender("neuter");
    set_funcs(({ "my_special" }));
    set_func_chance(20);
    iselemental = 0;
}

int isMagic()
{
    return 5;
}

void setup_beastie(object caster, int beastalign)
{
    if (!objectp(caster)) {
        return;
    }
    cast = caster;
    seteuid(getuid());
    castname = cast->query_name();
    fname = "/d/save/summons/" + castname + "/" + query_name();
    "/daemon/yuck_d"->load_inventory(this_object(), fname);
    myalign = beastalign;
    set_alignment(myalign);

    if (caster->query_property("talossian elementalist")) { // Pangretor's quest reward greeble!
        set_id(({ "elemental", "lightning elemental", "outsider" }));
        set_short("%^RESET%^%^MAGENTA%^Lightning Elemental%^RESET%^");
        set_short("%^YELLOW%^Lig%^WHITE%^ht%^YELLOW%^ni%^WHITE%^n%^YELLOW%^g Elem%^WHITE%^e%^YELLOW%^ntal%^RESET%^");
        set_long("%^RESET%^This creature looks like a %^BLUE%^d%^BOLD%^%^BLACK%^ar%^RESET%^%^BLUE%^k st%^BOLD%^%^BLACK%^or"
                 "%^RESET%^%^BLUE%^mc%^BOLD%^%^BLACK%^lo%^RESET%^%^BLUE%^ud%^RESET%^, its vague outline suggesting a humanoid form that "
                 "trails away to a %^CYAN%^whirling vortex %^RESET%^instead of legs and feet. %^YELLOW%^S%^BOLD%^%^WHITE%^pa"
                 "%^BOLD%^%^WHITE%^rk%^YELLOW%^s%^RESET%^ of energy serve as the creature's eyes, which review the world with a %^RED%^pi"
                 "%^MAGENTA%^t%^RED%^il%^MAGENTA%^e%^RED%^ss %^RESET%^gaze. Long, sweeping arms rise to either side of its ever-shifting "
                 "torso, charged with bolts of %^YELLOW%^li%^BOLD%^%^WHITE%^g%^YELLOW%^ht%^BOLD%^%^WHITE%^ni%^YELLOW%^ng%^RESET%^.");
        set_body_type("humanoid");
        remove_limb("left hand");
        remove_limb("right hand");
        remove_limb("left foot");
        remove_limb("right foot");
        remove_limb("left leg");
        remove_limb("right leg");
        add_limb("vortex", "torso", 0, 0, 0);
        set_attack_limbs(({ "right arm", "left arm" }));
        set_base_damage_type("bludgeoning");
        iselemental = 1;
        return;
    }
    switch (myalign) {
    case 1:   // LG: trumpet archon
        set_id(({ "archon", "trumpet archon", "Archon", "Trumpet Archon", "outsider" }));
        set_short("%^YELLOW%^Tr%^WHITE%^u%^YELLOW%^mp%^WHITE%^e%^YELLOW%^t Arc%^WHITE%^h%^YELLOW%^on%^RESET%^");
        set_long("%^RESET%^This magnificent creature looks somewhat like an %^MAGENTA%^elf%^RESET%^, and yet is far more "
                 "than that.  Bearing the light, angular frame and tapered ears of a fey creature, it carries itself with an easy and "
                 "natural grace.  Its skin is a vivid %^GREEN%^e%^BOLD%^m%^RESET%^%^GREEN%^er%^BOLD%^a%^YELLOW%^l%^RESET%^%^GREEN%^d "
                 "%^RESET%^color, and it is completely hairless save for the brows that arch above its glowing eyes of %^BOLD%^%^WHITE%^l"
                 "%^YELLOW%^i%^WHITE%^ght%^RESET%^.  A pair of %^BOLD%^%^WHITE%^ma%^RESET%^ssi%^BOLD%^ve fea%^RESET%^the%^BOLD%^red w"
                 "%^RESET%^in%^BOLD%^gs %^RESET%^spread from its shoulders, fluttering softly with any of the creature's movements.  "
                 "Flowing white robes lie beneath a %^ORANGE%^go%^YELLOW%^ld%^RESET%^%^ORANGE%^en %^RESET%^breastplate and wrist-guards, "
                 "and a long %^BOLD%^s%^RESET%^i%^BOLD%^%^BLACK%^lve%^RESET%^r%^BOLD%^y %^RESET%^trumpet is held in one of its slender, "
                 "viridian hands.");
        set_body_type("humanoid");
        set_attack_limbs(({ "left hand", "right hand" }));
        set_base_damage_type("bludgeoning");
        break;

    case 2:   // LN: zelekhut, inevitable
        set_id(({ "zelekhut", "Zelekhut", "inevitable", "Inevitable", "outsider" }));
        set_short("%^BOLD%^%^BLACK%^Z%^RESET%^e%^BOLD%^l%^RESET%^e%^BOLD%^%^BLACK%^kh%^RESET%^u%^BOLD%^%^BLACK%^t%^RESET%^");
        set_long("%^RESET%^Looking more like a centaur in frame than anything else, this being appears to be less of a "
                 "living creature, and more of a mechanical construct.  Gaps in its %^BOLD%^%^WHITE%^alabaster %^RESET%^coat of skin "
                 "reveal a %^ORANGE%^bron%^RED%^z%^ORANGE%^ed %^RESET%^framework of wires, struts and cogs that allow it to move with "
                 "surprising grace and speed.  From its back spread a pair of similarly-constructed wings of metal, their pinions as sharp "
                 "as knives.  Its face bears the %^CYAN%^cold%^RESET%^, emotionless expression of a creature unfamiliar with feelings of "
                 "joy or rage.  A pair of %^BOLD%^%^BLACK%^sp%^RESET%^ik%^BOLD%^%^BLACK%^ed ch%^RESET%^ai%^BOLD%^%^BLACK%^ns %^RESET%^lie "
                 "hooked along each of its arms, likely able to be lashed out at a foe with minimal effort or warning.");
        set_body_type("humanoid");
        add_limb("left spiked chain", "torso", 0, 0, 0);
        add_limb("right spiked chain", "torso", 0, 0, 0);
        add_limb("wings", "torso", 0, 0, 0);
        set_attack_limbs(({ "left spiked chain", "right spiked chain" }));
        set_base_damage_type("slashing");
        break;

    case 3:   // bone devil, baatezu
        set_id(({ "devil", "Devil", "bone devil", "Bone Devil", "outsider" }));
        set_short("%^RESET%^Bo%^BOLD%^n%^RESET%^e De%^BOLD%^v%^RESET%^il");
        set_long("%^RESET%^A horrific creature to look upon, the Osyluth is more commonly known as a Bone Devil.  It "
                 "appears as a tall and hideous parody of what might once have been human.  %^ORANGE%^Dried skin %^RESET%^is stretched "
                 "tightly across its %^BOLD%^%^WHITE%^skeletal %^RESET%^form, with spikes that protrude from its knees and elbows.  "
                 "Elongated fingers and toes stretch clawlike, as if seeking flesh to rend.  A tail of bone much like a scorpion's, curls "
                 "up and over its grinning, fanged skull and drips with %^GREEN%^ven%^BOLD%^%^BLACK%^o%^RESET%^%^GREEN%^m%^RESET%^.  A "
                 "stench of %^BLUE%^decay %^RESET%^hangs in a tangible miasma around this monster.");
        set_body_type("humanoid");
        add_limb("spiked tail", "torso", 0, 0, 0);
        add_limb("left claws", "left hand", 0, 0, 0);
        add_limb("right claws", "right hand", 0, 0, 0);
        set_attack_limbs(({ "left claws", "right claws", "spiked tail" }));
        set_base_damage_type("slashing");
        break;

    case 4:   // NG: leonal, guardinal
        set_id(({ "leonal", "Leonal", "outsider" }));
        set_short("%^RESET%^%^ORANGE%^Leo%^RED%^na%^ORANGE%^l%^RESET%^");
        set_long("%^RESET%^This powerful creature stands about the height of a man, but is built with such an impressive "
                 "frame as could surely not be possible for humankind.  %^RED%^Muscles %^RESET%^ripple beneath a coating of short, thick "
                 "fur, and its human-shaped hands end in %^BOLD%^%^BLACK%^v%^RED%^i%^BLACK%^ci%^WHITE%^o%^YELLOW%^u%^BLACK%^s %^RESET%^"
                 "claws.  Its leonine face bears dark, close-set eyes and a short muzzle, all framed within the outline of its lush mane "
                 "of %^ORANGE%^dark gold %^RESET%^hair.  It bears only a belt and a warrior's kilt by way of clothing, with its wrists and "
                 "legs bound in %^BOLD%^%^BLACK%^sturdy leather lashings%^RESET%^.");
        set_body_type("humanoid");
        add_limb("left claws", "left forepaw", 0, 0, 0);
        add_limb("right claws", "right forepaw", 0, 0, 0);
        set_attack_limbs(({ "right claws", "left claws" }));
        set_base_damage_type("slashing");
        break;

    case 5:   // TN: aurumach, rilmani
        set_id(({ "aurumach", "Aurumach", "outsider" }));
        set_short("%^YELLOW%^Au%^RESET%^%^ORANGE%^ru%^YELLOW%^ma%^RESET%^%^ORANGE%^c%^YELLOW%^h%^RESET%^");
        set_long("%^RESET%^This outsider appears as a powerfully muscled, %^YELLOW%^go%^RESET%^%^ORANGE%^ld%^YELLOW%^en"
                 "%^RESET%^-skinned humanoid that would easily match the size of an ogre.  Unlike such a beast, however, the creature is "
                 "completely hairless and smooth-skinned.  A picture of physical perfection, its face falls into a %^CYAN%^neutral "
                 "%^RESET%^expression with golden orbs for eyes that show no hint of emotion in their depths.  It bears no arms or armor, "
                 "but you're quite sure a creature of this size would be a considerable foe in combat.  However, there is an almost "
                 "tangible aura of %^GREEN%^calm %^RESET%^to this surprisingly beautiful creature, that pervades the air around it.");
        set_body_type("humanoid");
        set_base_damage_type("bludgeoning");
        break;

    case 6:   // NE: nycaloth, yugoloth
        set_id(({ "nycaloth", "Nycaloth", "outsider" }));
        set_short("%^RESET%^%^GREEN%^Ny%^ORANGE%^c%^GREEN%^alo%^ORANGE%^t%^GREEN%^h%^RESET%^");
        set_long("%^RESET%^Though large and obviously powerful, this %^BLUE%^bat-winged %^RESET%^monstrosity still evokes "
                 "a sense of speed and agility.  Its dog-like head turns quickly from side to side, much like an alert bird, with "
                 "%^ORANGE%^curled horns %^RESET%^that turn down from atop its crown around either side of its maw.  %^GREEN%^Thick green "
                 "skin %^RESET%^coats the gargoyle-like body, with not one but two arms sprouting from each shoulder.  The claws on the "
                 "end of its powerful fingers look like more than a match for all but the best armor, as does the %^RED%^greataxe %^RESET%^"
                 "gripped in two of its four hands.");
        set_body_type("humanoid");
        add_limb("left claws", "left hand", 0, 0, 0);
        add_limb("right claws", "right hand", 0, 0, 0);
        add_limb("tail", "torso", 0, 0, 0);
        add_limb("wings", "torso", 0, 0, 0);
        set_attack_limbs(({ "left claws", "right claws" }));
        set_base_damage_type("slashing");
        break;

    case 7:   // CG: bralani, eladrin
        set_id(({ "bralani", "Bralani", "outsider" }));
        set_short("%^BOLD%^%^WHITE%^B%^RESET%^r%^BOLD%^al%^CYAN%^a%^WHITE%^ni%^RESET%^");
        set_long("%^RESET%^Before you stands a stocky being, much like a %^ORANGE%^human %^RESET%^at first glance.  Its "
                 "hair is bright %^BOLD%^%^WHITE%^si%^RESET%^lv%^BOLD%^ery-wh%^CYAN%^i%^WHITE%^te %^RESET%^like fresh-fallen snow, "
                 "tumbling askew about an angular face and sharply pointed ears more common to the fey.  Narrow eyes peer forth from "
                 "beneath its craggy brow, shifting through a %^BOLD%^%^WHITE%^ir%^MAGENTA%^i%^WHITE%^des%^GREEN%^c%^CYAN%^e%^WHITE%^nt "
                 "%^RESET%^rainbow of colors that never settles upon a single hue.  Covering its body is the garb of a travelling nomad "
                 "with mismatched pieces of %^ORANGE%^leather %^RESET%^and %^CYAN%^metal %^RESET%^armor, but with enough skin left bare to "
                 "hint at a warm climate of origin, or a very strong tolerance to cold.");
        set_body_type("humanoid");
        set_attack_limbs(({ "left hand", "right hand" }));
        set_base_damage_type("bludgeoning");
        break;

    case 8:   // CN: gray slaad
        set_id(({ "slaad", "Slaad", "gray slaad", "Gray Slaad", "outsider" }));
        set_short("%^BOLD%^%^BLACK%^Gr%^RESET%^a%^BOLD%^%^BLACK%^y S%^RESET%^%^GREEN%^l%^BOLD%^%^BLACK%^aad%^RESET%^");
        set_long("%^RESET%^Bearing the appearance of a two-legged %^GREEN%^frog%^RESET%^, this creature is as tall as a "
                 "man and bears a lean build, possessed of movements that are surprisingly quick.  Its smooth skin is a %^BOLD%^%^BLACK%^"
                 "dap%^RESET%^pl%^BOLD%^%^BLACK%^ed gray %^RESET%^color, with bony ridges over its eyes that flare to either side like "
                 "short horns of %^BOLD%^%^BLACK%^granite%^RESET%^.  Long, humanoid arms lead down to clawed fingers that are surprisingly "
                 "nimble, giving the creature an ease of manipulating and grasping.  Short fangs jut up along the jawline of its blunt face"
                 ", with %^ORANGE%^dark amber eyes %^RESET%^that peer forth with a reptilian intelligence.");
        set_body_type("humanoid");
        add_limb("left claws", "left hand", 0, 0, 0);
        add_limb("right claws", "right hand", 0, 0, 0);
        set_attack_limbs(({ "left claws", "right claws" }));
        set_base_damage_type("slashing");
        break;

    case 9:   // CE: vrock, tanarri
        set_id(({ "vrock", "Vrock", "tanarri", "Tanarri", "outsider" }));
        set_short("%^RESET%^%^MAGENTA%^Vr%^CYAN%^oc%^MAGENTA%^k%^RESET%^");
        set_long("%^RESET%^This monster appears as some kind of horrific humanoid vulture of an impressive size.  Its "
                 "sinewy outline is mostly coated in a fine layer of %^BOLD%^%^BLACK%^gray feathers%^RESET%^, beneath which lies hardened "
                 "skin of a %^MAGENTA%^sickly indigo shade%^RESET%^.  Its forelegs are overly long, allowing it to rise up on two legs or "
                 "run in a loping gait on four.  Each three-toed foot ends in a %^RED%^curled r%^BOLD%^a%^RESET%^%^RED%^ptor's claw"
                 "%^RESET%^, while a whip-like tail offers balance behind.  From its hunched back spread two broad, %^BOLD%^%^BLACK%^gray-"
                 "feathered %^RESET%^wings, which spread above the long, limber neck.  Above is supported a horned head over which its "
                 "skin has been stretched thinly, drawing down to %^BLUE%^sunken eyes %^RESET%^and a cruelly curved beak.");
        set_body_type("humanoid");
        add_limb("left claws", "left forepaw", 0, 0, 0);
        add_limb("right claws", "right forepaw", 0, 0, 0);
        add_limb("wings", "torso", 0, 0, 0);
        set_attack_limbs(({ "right claws", "left claws" }));
        set_base_damage_type("slashing");
        break;
    }
}

void my_special(object target)
{
    if (!objectp(target)) {
        return;
    }

    if (iselemental) { // pangy's quest greeble!
        tell_object(target, "%^BOLD%^%^WHITE%^The elemental lunges forward with the %^RESET%^%^RED%^rumble %^WHITE%^of "
                    "%^BOLD%^%^BLACK%^ro%^RESET%^l%^BOLD%^%^BLACK%^ling thun%^RESET%^d%^BOLD%^%^BLACK%^er%^WHITE%^, unleashing arcs of "
                    "%^YELLOW%^li%^BOLD%^%^WHITE%^g%^YELLOW%^ht%^BOLD%^%^WHITE%^ni%^YELLOW%^ng %^BOLD%^%^WHITE%^at you that wrack your "
                    "body with agonising pain!%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^WHITE%^The elemental lunges forward with the %^RESET%^%^RED%^rumble %^WHITE%^of "
                  "%^BOLD%^%^BLACK%^ro%^RESET%^l%^BOLD%^%^BLACK%^ling thun%^RESET%^d%^BOLD%^%^BLACK%^er%^WHITE%^, unleashing arcs of "
                  "%^YELLOW%^li%^BOLD%^%^WHITE%^g%^YELLOW%^ht%^BOLD%^%^WHITE%^ni%^YELLOW%^ng %^BOLD%^%^WHITE%^at " + target->QCN + " that "
                  "wrack " + target->QP + " entire body!%^RESET%^", target);
        TO->set_property("magic", 1);
        target->do_damage("torso", random(40) + (mylevel * 2));
        TO->remove_property("magic");
        return;
    }

    switch (myalign) {
    case 1:   // LG: trumpet archon (trumpet for stun/dmg)
        tell_object(target, "%^BOLD%^%^YELLOW%^The archon lifts its %^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lve%^RESET%^r"
                    "%^BOLD%^%^WHITE%^y %^YELLOW%^trumpet to its lips, and lets forth a blast of %^CYAN%^piercing%^YELLOW%^, soul-wrenching "
                    "music that shudders painfully through your whole body!%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^YELLOW%^The archon lifts its %^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lve%^RESET%^r%^BOLD%^"
                  "%^WHITE%^y %^YELLOW%^trumpet to its lips, and lets forth a blast of %^CYAN%^piercing%^YELLOW%^, soul-wrenching music "
                  "directed at " + target->QCN + ", who shudders in pain!%^RESET%^", target);
        break;

    case 2:   // LN: zelekhut, inevitable (attack with spiked chain)
        tell_object(target, "%^BOLD%^%^YELLOW%^The zelekhut flares its %^RESET%^%^ORANGE%^metal%^RESET%^l%^ORANGE%^ic "
                    "%^YELLOW%^wings and lashes out with its chain whips, scoring painful blows upon you from both sides!%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^YELLOW%^The zelekhut flares its %^RESET%^%^ORANGE%^metal%^RESET%^l%^ORANGE%^ic "
                  "%^YELLOW%^wings and lashes out with its chain whips, scoring painful blows upon " + target->QCN + " from both sides"
                  "!%^RESET%^", target);
        break;

    case 3:   // LE: bone devil, baatezu (tail poison for damage)
        tell_object(target, "%^BOLD%^%^WHITE%^With lightning speed, the bone devil lashes out with its scorpion-like tail "
                    "and jabs you.  %^RESET%^%^GREEN%^Poi%^BOLD%^s%^RESET%^%^GREEN%^on %^BOLD%^%^WHITE%^races momentarily through your veins "
                    "in searing pain!%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^WHITE%^With lightning speed, the bone devil lashes out with its scorpion-like tail "
                  "and jabs " + target->QCN + ", who writhes in pain!%^RESET%^", target);
        break;

    case 4:   // NG: leonal, guardinal (roar as holy word spell for dmg)
        tell_object(target, "%^BOLD%^%^WHITE%^The leonal braces its feet and spreads its arms as it unleashes a mighty "
                    "%^YELLOW%^r%^WHITE%^o%^RED%^a%^YELLOW%^r %^WHITE%^that hits you like a physical blow, nearly knocking you from your "
                    "feet!%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^WHITE%^The leonal braces its feet and spreads its arms as it unleashes a mighty "
                  "%^YELLOW%^r%^WHITE%^o%^RED%^a%^YELLOW%^r %^WHITE%^that hits " + target->QCN + " like a physical blow, nearly knocking "
                  + target->QO + " from " + target->QP + " feet!%^RESET%^", target);
        break;

    case 5:   // TN: aurumach, rilmani (conjures golden huge +3 halberd swing - fiend folio)
        tell_object(target, "%^BOLD%^%^GREEN%^The aurumach raises its hands above its head, and the air around them "
                    "shimmers as a shining %^RESET%^%^ORANGE%^go%^YELLOW%^ld%^RESET%^%^ORANGE%^en %^BOLD%^%^GREEN%^halberd suddenly appears "
                    "in its grip, which it swings at you in a vicious overhead slash!%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^GREEN%^The aurumach raises its hands above its head, and the air around them "
                  "shimmers as a shining %^RESET%^%^ORANGE%^go%^YELLOW%^ld%^RESET%^%^ORANGE%^en %^BOLD%^%^GREEN%^halberd suddenly appears "
                  "in its grip, which it swings at " + target->QCN + " in a vicious overhead slash!%^RESET%^", target);
        break;

    case 6:   // NE: nycaloth, yugoloth (rake with claws - mm3)
        tell_object(target, "%^BOLD%^%^GREEN%^The nycaloth swings its greataxe at you and nearly takes off your head, "
                    "still managing to scoring a %^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^dy %^GREEN%^wound in your flesh!%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^GREEN%^The nycaloth swings its greataxe at you and nearly takes off " + target->QCN + "'s "
                  "head, still managing to scoring a %^RED%^bl%^RESET%^%^RED%^oo%^BOLD%^dy %^GREEN%^wound in " + target->QP + " flesh"
                  "!%^RESET%^", target);
        break;

    case 7:   // CG: bralani, eladrin (whirlwind blast)
        tell_object(target, "%^BOLD%^%^CYAN%^Dust and debris is picked up around the bralani as it shifts suddenly into a "
                    "%^RESET%^wh%^ORANGE%^i%^RESET%^rli%^BOLD%^%^BLACK%^n%^RESET%^g ma%^YELLOW%^e%^WHITE%^l%^RESET%^str%^CYAN%^o%^RESET%^m"
                    "%^BOLD%^%^CYAN%^, gusts buffeting you from side to side!%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^CYAN%^Dust and debris is picked up around the bralani as it shifts suddenly into a "
                  "%^RESET%^wh%^ORANGE%^i%^RESET%^rli%^BOLD%^%^BLACK%^n%^RESET%^g ma%^YELLOW%^e%^WHITE%^l%^RESET%^str%^CYAN%^o%^RESET%^m"
                  "%^BOLD%^%^CYAN%^, gusts buffeting " + target->QCN + " from side to side!%^RESET%^", target);
        break;

    case 8:   // CN: gray slaad (chaos hammer/lightning bolt, or claws)
        tell_object(target, "%^BOLD%^%^BLUE%^A sweep of the slaad's clawed hand casts forth a %^WHITE%^m%^YELLOW%^u"
                    "%^WHITE%^lti%^MAGENTA%^c%^WHITE%^ol%^CYAN%^o%^GREEN%^r%^WHITE%^ed %^BLUE%^explosion of leaping, ricocheting energy that "
                    "strikes you with full force!%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^BLUE%^A sweep of the slaad's clawed hand casts forth a %^WHITE%^m%^YELLOW%^u%^WHITE%^lti"
                  "%^MAGENTA%^c%^WHITE%^ol%^CYAN%^o%^GREEN%^r%^WHITE%^ed %^BLUE%^explosion of leaping, ricocheting energy that strikes "
                  + target->QCN + " with full force!%^RESET%^", target);
        break;

    case 9:   // CE: vrock, tanarri (wings up and pounce for dmg)
        tell_object(target, "%^BOLD%^%^RED%^The vrock leaps into the air with a powerful thrust of its %^BLACK%^win"
                    "%^RESET%^g%^BOLD%^%^BLACK%^s%^RED%^, and then dives down upon you to rend your flesh with both claws!%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^RED%^The vrock leaps into the air with a powerful thrust of its %^BLACK%^win"
                  "%^RESET%^g%^BOLD%^%^BLACK%^s%^RED%^, and then dives down upon " + target->QCN + " to rend " + target->QP + " flesh with both "
                  "claws!%^RESET%^", target);
        break;

    default:   // error prompt
        tell_room(ETO, "%^BOLD%^%^RED%^Your beastie is broken, contact a wiz!%^RESET%^");
        break;
    }
    TO->set_property("magic", 1);
    target->do_damage("torso", random(40) + (mylevel * 2));
    TO->remove_property("magic");
}

void die(object obj)
{
    if (objectp(cast)) {
        cast->remove_property("has_elemental");
    }
    tell_room(ETO, "%^BOLD%^%^RED%^Unable to maintain corporeal form, outsider return to their home plane.%^RESET%^");

    remove();
}

set_caster(object ob)
{
    if (objectp(ob)) {
        cast = ob;
    }else {
        remove();
    }
}

object query_caster()
{
    return cast;
}

void set_mylevel(int x)
{
    mylevel = x;
    set_hd(mylevel, 10);
    set_mlevel("fighter", mylevel);
    set_max_hp(mylevel * 20);
    set_hp((int)TO->query_max_hp());
    set_attacks_num((mylevel / 13) + 1);
    set_damage(1, mylevel);
    set_overall_ac(10 - mylevel);
    set_stats("strength", 20);
    set_stats("constitution", 20);
    set_stats("dexterity", 20);
    set_property("effective_enchantment", (mylevel / 7) + 1);
    set_property("extra encumbrance", -205); //override to drop them to 100 carrying capacity, not meant to be pack mules
}

void defend()
{
    int num, numfoes;
    object* tmp;

    tmp = ({});
    numfoes = sizeof(tmp = cast->query_attackers());
    for (num = 0; num < numfoes; num++) {
        if (!objectp(tmp[num])) {
            continue;
        }
        if (member_array(tmp[num], (object*)TO->query_attackers()) != -1) {
            continue;
        }
        if (!objectp(TO)) {
            continue;
        }
        TO->kill_ob(tmp[num], 1);
        tell_room(cast, "%^BOLD%^%^RED%^The outsider attacks " + tmp[num]->QCN + "!");
    }
    return;
}

int remove()
{
    reset_all_status_effects();
    save_outsider();
    all_inventory(TO)->remove();
    ::remove();
}

void heart_beat()
{
    string party;
    int i;
    ::heart_beat();
    if (!objectp(cast)) {
        remove();
    }
    if (!objectp(TO)) {
        remove();
    }
    if (!sizeof(cast->query_attackers())) {
        return;
    }
    if ((object*)cast->query_attackers() != ({})) {
        defend();
    }
    TO->remove_attacker(0);

    if (query_hp_percent() < 70 && present("vial", TO)) {
        for (i = 0; i < 4; i++) {
            command("quaff vial");
        }
    }

    if (query_hp() < query_max_hp()) {
        add_hp(query_max_hp() / 25);
    }
}

void save_outsider()
{
    seteuid(getuid());
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    mkdir("/d/save/summons/" + castname);
    mkdir(fname);
    "/daemon/yuck_d"->save_inventory(this_object(), fname);
}
