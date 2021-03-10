// Use this file by hand, uncrustify and other tools make a mess of it
mapping class_spell_storage = ([]);


// Arrays in this storage for most classes store spells in order by level. If you miss some level, use "".
// Notable exceptions are "all" specials applied to all characters and some PRC bonus spells.
class_spell_storage =

([
"oracle":
([
    "all":
        ({"cure light wounds", "cause light wounds",
          "cure moderate wounds", "cause moderate wounds",
          "cure serious wounds", "cause serious wounds",
          "cure critical wounds", "cause critical wounds",
          "mass cure light wounds", "mass cause light wounds",
          "mass cure moderate wounds", "mass cause moderate wounds",
          "mass cure serious wounds", "mass cause serious wounds",
          "mass cure critical wounds", "mass cause critical wounds",}),
    "darkness":
        ({"shadow stream","dust of twilight","deeper darkness","shadow conjuration","vampiric shadow shield","shadow travel","greater shadow conjuration","greater shadow evocation","polar midnight"}),
    "dragon":
        ({"cause fear","levitate","resist energy","obsidian flow","fear","protection from spells","true seeing","shapechange","overwhelming presence"}),
    "godclaw":
        ({"cause fear","hold person","break curse","orders wrath","seeking sword","gale fist","dictum","shield of law","imprisonment"}),
    "reaper":
        ({"chill touch","spectral hand","sands of time","purge spirit","slay living","undeath is death","destruction","horrid wilting","wail of the banshee"}),
    "bones":
        ({"cause fear","false life","animate dead","boneshatter","slay living","circle of death","waves of exhaustion","horrid wilting","wail of the banshee"}),
    "battle":
        ({"enlarge person", "fog cloud", "magic vestments", "wall of fire", "righteous might", "transformation", "foresight", "earthquake", "storm of vengeance"}),
    "flame":
        ({"burning hands", "resist energy", "fireball", "wall of fire", "conjure elemental", "fire seeds", "fire storm", "incendiary cloud", "fiery body"}),
    "elemental":
        ({"guidance", "resist energy", "elemental aura", "elemental body i", "elemental body ii", "elemental body iii", "elemental body iv", "create demiplane", "elemental swarm"}),
    "whimsy":
        ({"faerie fire", "hideous laughter", "phantom steed", "confusion", "false vision", "eyebite", "project image", "irresistible dance", "weird"}),
    "heavens":
        ({"color spray", "hypnotic pattern", "daylight", "rainbow pattern", "angelic aspect", "chain lightning", "prismatic spray", "sunburst", "meteor swarm"}),
    "life":
        ({"mending", "restoration", "remove blindness", "neutralize poison", "breath of life", "heal", "regeneration", "mass heal", "resurrection"}),
    "shadow":
        ({"blurred movement", "invisibility", "deeper darkness", "shadow stride", "vampiric shadow shield", "shadow travel", "umbral strike", "greater shadow evocation", "shades"}),
    "solar":
        ({"faerie fire", "flaming sphere", "daylight", "dimension door", "solar siege shot", "sirocco", "sunbeam", "sunburst", "hellball"}),
    "spellscar":
        ({"armor", "resist energy", "dispel magic", "true form", "siphon magic", "globe of invulnerability", "spell turning", "spellscar", "imprisonment"}),
    "apocalypse":
        ({"summon swarm", "fog cloud", "sleet storm", "ice storm", "insect plague", "circle of death", "fire storm", "incendiary cloud", "meteor swarm"}),
    "ancestor":
        ({"unseen servant", "spiritual weapon", "heroism", "spiritual ally", "telekinetic push", "greater heroism","vision", "timeless body", "astral projection"}),
    "lore":
        ({"magic missile","clairvoyance","tongues","modify memory","telepathic bond","legend lore","vision","screen","timestop"}),
    "nature":
        ({"entangle", "barkskin", "charm monster", "polymorph self", "wall of thorns", "summon natures ally vi", "animate plants", "shapechange", "shambler"}),
    "stone":
        ({"stone throw", "soften earth", "meld into stone", "obsidian flow", "earth reaver", "wall of stone", "statue", "stone body", "clashing rocks"}),
    "metal":
        ({"mending", "heat metal", "heart of metal", "keen edge", "greater magic weapon", "blade barrier", "statue", "silver sight", "iron body"}),
    "lunar":
        ({"sleep", "dust of twilight", "rage", "moonbeam", "aspect of the wolf", "litany of madness", "eclipse", "polar midnight"}),
    "waves":
        ({"endure elements", "fog cloud", "water breathing", "ice storm", "conjure elemental", "pass portal", "vortex", "seamantle", "tidal surge"}),
    "wind":
        ({"biting wind", "gust of wind", "cloak of winds", "air walk", "stormwinds", "sirocco", "repulsion", "windstorm", "storm of vengeance"}),
    "winter":
        ({"endure elements", "frostfield", "sleet storm", "ice storm", "cone of cold", "frost breath", "hypothermia", "ice mirror", "polar midnight"}),
]),

"sorcerer":
([
    "aberrant":
        ({"enlarge person","detect invisibility","tongues","black tentacles","prying eyes","impenetrable veil","phase door","shapechange"}),
    "abyssal":
        ({"acid splash","darkness","acid orb","fear","domination","impenetrable veil","acid fog","unholy aura"}),
    "accursed":
        ({"touch of fatigue","touch of idiocy","garble","bestow curse","ruin","eyebite","powerword blind","spellscar"}),
    "arcane":
        ({"identify","mirror image","dispel magic","break curse","siphon magic","repulsion","foresight","screen"}),
    "astral":
        ({"flare","invisibility","blink","suppress wild magic","dismissal","contingency","greater teleport","antimagic field"}),
    "boreal":
        ({"enlarge person","bears endurance","rage","stoneskin","cone of cold","transformation","true strike","polar ray"}),
    "celestial":
        ({"light","eagles splendor","lightning bolt","shout","angelic aspect","serenity","project image","protection from spells"}),
    "draconic":
        ({"armor","resist energy","fireball","fear","acid breath","disintegrate","protection from spells","shapechange"}),
    "elemental":
        ({"burning hands","scorcher","fireball","ice storm","cone of cold","chain lightning","incendiary cloud","meteor swarm"}),
    "fey":
        ({"dancing lights","glitterdust","phantom steed","confusion","domination","eyebite","reverse gravity","irresistible dance"}),
    "ghoul":
        ({"chill touch","ray of enfeeblement","vampiric touch","boneshatter","teleport","circle of death","finger of death","horrid wilting"}),
    "infernal":
        ({"infernal healing","scorcher","fireball","fire shield","mind fog","hellfire ray","finger of death","powerword stun"}),
    "possessed":
        ({"sleep","blindness","displacement","phantasmal killer","false vision""eyebite","visions from within","euphoric tranquility"}),
    "shadow":
        ({"touch of fatigue","alter self","phantom steed","shadowform","angelic aspect","shadow alteration","umbral strike","greater shadow evocation"}),
    "stormborn":
        ({"shocking grasp","lightning bolt","gust of wind","lightning arc","chain lightning","phase door","stormbolts","ride the lightning"}),
    "undead":
        ({"chill touch","spectral hand","necrotic burst","animate dead","create undead","exhume corpses","finger of death","create greater undead"}),
]),

"shadow_adept":
([
    "all":
        ({ "umbral sight", "shield of shadows", "shadow vortex", "night armor", "darkbolt", "shadow blast", "shadow double", "nightmare maw", "shadow nova" }),
]),

"chronicler":
([
    "all":
        ({ "doom", "sands of time", "spiritual ally", "foresight", "timeless body", "timestop" }),
]),

"archdruid":
([
    "all":
        ({"faerie fire", "entangle", "animal messenger", "meld into nature", "flame strike", "wall of thorns", "wall of stone", "vortex", "euphoric tranquility", "regenerate",}),
]),

"psion":
([
    "egoist":
        ({"thicken skin","animal affinity","chameleon","deathward","breath of life","restoration","lesser transformation","shadow double","shadow body"}),
    "seer":
        ({"dissonance","clairvoyance","hypercognition","escape detection","remote viewing","legend lore","prying eyes","fortune fate","foresight"}),
    "shaper":
        ({"minor creation","astral construct","web","creation","hail of crystals","ruin","rebirth","create demiplane","implosion"}),
    "kineticist":
        ({"animate object","energy emanation","energy cone","hold person","energy current","bolt of force","reddopsi","crushing hand","tornado blast"}),
    "nomad":
        ({"dimension slide","phantom steed","trace teleport","dimensional anchor","psionic teleport","create demiplane","planar portal","astral projection","timestop"}),
    "telepath":
        ({"command","charm monster","hostile empathic transfer","modify memory","domination","serenity","visions from within","mindnet","overwhelming presence"}),
]),

"warlock":
([
    "all":
        ({"eldritch blast", "eldritch claws", "summon companion", "eldritch bow", "detect magic", "eldritch glaive","eldritch scimitar","eldritch chain","eldritch burst"}),
]),

]);
