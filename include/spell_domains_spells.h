/**
 * List of domain spell mapped by domain.
 *
 * Order of spells defines their levels
 *
 * This dataset should be queried from MAGIC_SS_D with
 * query_domain_spells(domain) and query_domains() functions.
 */
nosave mapping DOMAIN_SPELLS = ([]);
DOMAIN_SPELLS = ([
"air" : ({ "whispering wind", "cloak of winds", "gaseous form", "air walk", "airbolt", "chain lightning", "elemental body iv", "windstorm", "elemental swarm" }),
"animal" : ({ "magic fang", "hold animal", "charm monster", "polymorph self", "summon natures ally v", "antilife shell", "true seeing", "shapechange", "summon natures ally ix" }),
"cavern":({"stone throw", "meld into stone", "obsidian flow", "maw of stone", "earth reaver", "wall of stone", "stone body", "earthquake", "clashing rocks"}),
"chaos" : ({ "protection from alignment", "align weapon", "garble", "chaos hammer", "dispel law", "animate object", "word of chaos", "cloak of chaos", "prismatic burst" }),
"charm" : ({ "sleep", "captivate", "charm monster", "heroism", "domination", "bliss", "insanity", "demand", "dominate monster" }),
"cold" : ({ "biting wind", "frostfield", "serac", "ice shield", "cone of cold", "frost breath", "hypothermia", "ice mirror", "glacier" }),
"creation":({"minor creation", "mirror image", "acid breath", "glyph of warding", "sticks into snakes", "greater dispel magic", "cometfall", "powerword stun", "powerword kill"}),
"darkness" : ({ "shadow stream", "fog cloud", "blindness", "shadow conjuration", "darkbolt", "shadow travel", "powerword blind", "listening shadow", "shades" }),
"destruction" : ({ "true strike", "shatter", "rage", "fear", "tremor", "disintegrate", "finger of death", "horrid wilting", "tidal surge" }),
"earth" : ({ "stone throw", "soften earth", "strength of stone", "spike growth", "earth reaver", "stoneskin", "elemental body iv", "stone body", "elemental swarm" }),
"elements":({"shocking grasp", "flaming sphere", "fireball", "fire shield", "chain lightning", "freezing sphere", "vortex", "fire storm", "meteor swarm"}),
"evil" : ({ "protection from alignment", "align weapon", "contagion", "unholy smite", "slay living", "unholy orb", "blasphemy", "unholy aura", "animus blast" }),
"fate":({"true strike", "clairvoyance", "auspicious bolt", "precognitive perception", "trace teleport", "aegis of fate", "foresight", "fortune fate", "astral projection"}),
"fire" : ({ "burning hands", "produce flame", "fireball", "wall of fire", "fire shield", "fire seeds", "elemental body iv", "incendiary cloud", "elemental swarm" }),
"good" : ({ "protection from alignment", "align weapon", "prayer", "holy smite", "burst of glory", "holy orb", "holy word", "holy aura", "gate" }),
"illusion":({"blurred movement", "invisibility", "displacement", "greater invisibility", "phantasmal killer", "screen", "shadow double", "scintillating pattern", "weird"}),
"knowledge" : ({ "true strike", "detect thoughts", "tongues", "deathward", "false vision", "legend lore", "powerword blind", "powerword stun", "powerword kill" }),
"law" : ({ "protection from alignment", "align weapon", "prayer", "deathward", "domination", "repulsion", "dictum", "shield of law", "dominate monster" }),
"madness":({"cause fear", "touch of idiocy", "rage", "confusion", "nightmare", "phantasmal killer", "insanity", "scintillating pattern", "weird"}),
"magic" : ({ "color spray", "resist energy", "break curse", "freedom of movement", "mystic bolt", "protection from spells", "true seeing", "spellscar", "clashing rocks" }),
"mentalism":({"confusion", "detect thoughts", "clairvoyance", "modify memory", "telepathic bond", "bolt of force", "mind blank", "inner eye", "astral projection"}),
"moon":({"faerie fire", "dust of twilight", "deeper darkness", "confusion", "moonbeam", "nightmare", "lunar veil", "insanity", "meteor swarm"}),
"plague":({"touch of sickening", "necrophage", "contagion", "purge spirit", "greater contagion", "epidemic", "plague storm", "horrid wilting", "entropic storm"}),
"plant" : ({ "entangle", "barkskin", "contagion", "thorn body", "wall of thorns", "liveoak", "animate plants", "mind blank", "shambler" }),
"protection" : ({ "divine favor", "shield other", "resist energy", "lesser globe of invulnerability", "invisibility purge", "repulsion", "spell turning", "mind blank", "dimensional lock" }),
"renewal" : ({ "mending", "restoration", "rejuvenation", "freedom of movement", "breath of life", "heroes feast", "aura of healing", "rebirth", "resurrection" }),
"repose" : ({ "spectral touch", "gentle repose", "phantom steed", "deathward", "slay living", "undeath is death", "waves of exhaustion", "destruction", "wail of the banshee" }),
"stars":({"dancing lights", "levitate", "hypnotic pattern", "dimension door", "prying eyes", "sunbeam",  "reverse gravity", "sunburst", "meteor swarm"}),
"storms" : ({ "snowball", "lightning touch", "sleet storm", "ice storm", "stormwinds", "sirocco", "acid fog", "stormrage", "storm of vengeance" }),
"strength" : ({ "enlarge person", "distressing tone", "magic vestments", "globe of invulnerability", "righteous might", "stoneskin", "placeholder", "placeholder", "crushing hand" }),
"suffering":({"touch of sickening", "body blades", "wave of pain", "purge spirit", "kiss of torment", "eyebite", "finger of death", "nightmare maw", "ray of ending"}),
"sun" : ({ "faerie fire", "detect invisibility", "searing light", "nimbus of light", "flame strike", "fire seeds", "sunbeam", "sunburst", "prismatic burst" }),
"travel" : ({ "skate", "clairvoyance", "faithful mount", "dimension door", "teleport", "pass portal", "create portal", "phase door", "astral projection" }),
"trickery" : ({ "conceal alignment", "invisibility", "displacement", "confusion", "false vision", "flee the scene", "mass invisibility", "screen", "timestop" }),
"tyranny":({"cause fear", "oppression", "wave of pain", "modify memory", "fear", "forbiddance", "insanity", "orb of the void", "wail of the banshee"}),
"undeath":({"repair undead", "command undead", "necrophage", "animate dead", "mass repair undead", "create undead", "control undead", "create greater undead", "animus blizzard"}),
"vigilance" : ({ "divine favor", "orders oath", "heroism", "vicarious view", "domination", "inspiring recovery", "greater heroism", "frightful aspect", "overwhelming presence" }),
"void":({"blurred movement", "levitate", "dismissal", "dimension door", "conjure elemental", "phantom guardians",  "reverse gravity", "nightmare maw", "gate"}),
"war" : ({ "magic weapon", "spiritual weapon", "magic vestments", "divine power", "flame strike", "transformation", "powerword blind", "powerword stun", "powerword kill" }),
"water" : ({ "touch of sickening", "acid arrow", "stinking cloud", "ice storm", "cone of cold", "sirocco", "elemental body iv", "horrid wilting", "tidal surge" }),
"martyr":({"command", "shield other", "magic vestments", "vicarious view", "demand", "sacrificial oath", "repulsion", "storm of vengeance", "last sacrifice"}),
]);
