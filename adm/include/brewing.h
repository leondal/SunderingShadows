// database for brewing. Acceptable types:
// kit: /std/brewing/brewed_kit.c (kit covers scaled healing vials)
// potion/elixir: /std/brewing/brewed_potion.c (potion covers all drinkable self-effects, positive and negative)
// oil: per file (weapon-modifying items, including poisons)
// powders: per file (thief & bard only items tossed at a foe for an effect)
// misc: per file (all others; currently just tobacco!)
// filename of potion itself must be in /std/brewing, identical to name on this list with spaces instead of underscores.
// These mostly use herbs & mage comps; for other 'components' found elsewhere, refer /d/common/obj/brewing/herb_special_inherit.c
// note: the mud can't handle more than about 30 lines per definition, or it breaks. Had to split these to potions & elixirs separately.

#define KITS ([ \
                  "healing potion" : (["value" : 5, "dc" : 15, "materials" : ([]), ]), \
                  "extra healing potion" : (["value" : 25, "dc" : 25, "materials" : ([]), ]), \
                  "advanced healing potion" : (["value" : 50, "dc" : 35, "materials" : ([]), ]), \
                  "legendary healing potion" : (["value" : 100, "dc" : 45, "materials" : ([]), ]), \
              ])

#define POTIONS ([ \
                     "potion of neutralize poison" : (["value" : 2, "dc" : 24, "materials" : ([ "coriander" : 3, "valerian" : 1, "werebeast fang" : 1 ]), "color" : "blue"]), \
                     "potion of invisibility" : (["value" : 5, "dc" : 28, "materials" : ([ "rosemary" : 2, "eyelash" : 1, "spirit essence" : 2 ]), "color" : "blue"]), \
                     "potion of detect invisibility" : (["value" : 5, "dc" : 28, "materials" : ([ "ginkgo" : 2, "powdered silver" : 1, "spirit essence" : 1 ]), "color" : "blue"]), \
                     "potion of remove blindness" : (["value" : 9, "dc" : 34, "materials" : ([ "horehound" : 1, "tea" : 2, "nycissa orchid" : 1 ]), "color" : "blue"]), \
                     "potion of optic transmogrification" : (["value" : 5, "dc" : 40, "materials" : ([ "feverfew" : 2, "chicory" : 2, "lich dust" : 1 ]), "color" : "blue"]), \
                     "potion of hirsute transmogrification" : (["value" : 5, "dc" : 40, "materials" : ([ "fennel" : 3, "chicory" : 4, "lich dust" : 1 ]), "color" : "blue"]), \
                     "potion of gender inversion" : (["value" : 5, "dc" : 40, "materials" : ([ "catnip" : 3, "dandelion" : 4, "breath of winter" : 1 ]), "color" : "blue"]), \
                     "potion of youth" : (["value" : 400, "dc" : 45, "materials" : ([ "witch hazel" : 4, "garlic" : 3, "corrupted fey lifeblood" : 3, "divine essence" : 1, "heart of an ancient wyrm" : 1 ]), "color" : "blue"]), \
                 ])

// to add: nondetection? tongues comes on amulets, mage armor is fairly useless
#define ELIXIRS ([ \
                     "elixir of bless" : (["value" : 2, "dc" : 10, "materials" : ([ "bay" : 2, "saffron" : 1 ]), "color" : "yellow"]), \
                     "elixir of darkvision" : (["value" : 6, "dc" : 12, "materials" : ([ "tarragon" : 2, "werebeast fang" : 1 ]), "color" : "red"]), \
                     "elixir of misdirection" : (["value" : 3, "dc" : 14, "materials" : ([ "eucalyptus" : 1, "kelp" : 2 ]), "color" : "green"]), \
                     "elixir of energy resistance" : (["value" : 4, "dc" : 16, "materials" : ([ "alfalfa" : 3, "reptile scales" : 2 ]), "color" : "green"]), \
                     "elixir of sticky fingers" : (["value" : 4, "dc" : 18, "materials" : ([ "aloe" : 3, "fur" : 2 ]), "color" : "red"]), \
                     "elixir of insight" : (["value" : 4, "dc" : 18, "materials" : ([ "mint" : 3, "fur" : 2 ]), "color" : "red"]), \
                     "elixir of grace" : (["value" : 4, "dc" : 18, "materials" : ([ "juniper" : 3, "fur" : 2 ]), "color" : "red"]), \
                     "elixir of tenacity" : (["value" : 4, "dc" : 18, "materials" : ([ "nettle" : 3, "fur" : 2 ]), "color" : "red"]), \
                     "elixir of water breathing" : (["value" : 4, "dc" : 19, "materials" : ([ "thyme" : 2, "piece of reed" : 1, "reptile scales" : 2 ]), "color" : "green"]), \
                     "elixir of spider climb" : (["value" : 4, "dc" : 21, "materials" : ([ "basil" : 2, "clove" : 1, "spiderweb" : 2 ]), "color" : "green"]), \
                     "elixir of levitation" : (["value" : 6, "dc" : 23, "materials" : ([ "dill" : 2, "marjoram" : 3 ]), "color" : "green"]), \
                     "elixir of pass without trace" : (["value" : 9, "dc" : 26, "materials" : ([ "parsley" : 1, "yarrow" : 4 ]), "color" : "green"]), \
                     "elixir of bears endurance" : (["value" : 7, "dc" : 29, "materials" : ([ "ginseng" : 2, "anise" : 1, "bone dust" : 2 ]), "color" : "yellow"]), \
                     "elixir of bulls strength" : (["value" : 7, "dc" : 29, "materials" : ([ "vervain" : 2, "anise" : 1, "bone dust" : 2 ]), "color" : "yellow"]), \
                     "elixir of cats grace" : (["value" : 7, "dc" : 29, "materials" : ([ "dandelion" : 2, "anise" : 1, "bone dust" : 2 ]), "color" : "yellow"]), \
                     "elixir of eagles splendor" : (["value" : 7, "dc" : 29, "materials" : ([ "lavender" : 2, "cinnamon" : 1, "peryton talon" : 2 ]), "color" : "yellow"]), \
                     "elixir of foxs cunning" : (["value" : 7, "dc" : 29, "materials" : ([ "thyme" : 2, "cinnamon" : 1, "peryton talon" : 2 ]), "color" : "yellow"]), \
                     "elixir of owls wisdom" : (["value" : 7, "dc" : 29, "materials" : ([ "myrrha" : 2, "cinnamon" : 1, "peryton talon" : 2 ]), "color" : "yellow"]), \
                     "elixir of barkskin" : (["value" : 8, "dc" : 31, "materials" : ([ "catnip" : 3, "parsley" : 1, "patch of demonskin" : 1 ]), "color" : "yellow"]), \
                     "elixir of haste" : (["value" : 10, "dc" : 34, "materials" : ([ "ginger" : 2, "tendril of flame" : 2 ]), "color" : "red"]), \
                     "elixir of heroism" : (["value" : 12, "dc" : 37, "materials" : ([ "red pepper" : 2, "sage" : 1, "vermilion" : 1, "breath of winter" : 1 ]), "color" : "red"]), \
                     "elixir of displacement" : (["value" : 11, "dc" : 38, "materials" : ([ "allspice" : 4, "savory" : 2, "dream fragment" : 1 ]), "color" : "green"]), \
                     "elixir of regeneration" : (["value" : 11, "dc" : 41, "materials" : ([ "eucalyptus" : 3, "chamomile" : 1, "eye of newt" : 2 ]), "color" : "green"]), \
                     "elixir of stoneskin" : (["value" : 10, "dc" : 43, "materials" : ([ "clove" : 3, "granite dust" : 2, "living stone" : 2 ]), "color" : "green"]), \
                 ])

// to add: poisons (in their own category???), magic vestment oil (dc 22)
#define OILS ([ \
                  "oil of curse removal" : (["value" : 400, "dc" : 30, "materials" : ([ "parsley" : 5, "skullcap" : 3, "living stone" : 2, "dream fragment" : 4 ]), ]), \
                  "fire oil" : (["value" : 400, "dc" : 40, "materials" : ([ "parsley" : 5, "tendril of flame" : 5, "living stone" : 2, "eye of newt" : 4 ]), ]), \
                  "frost oil" : (["value" : 400, "dc" : 40, "materials" : ([ "skullcap" : 5, "bone dust" : 10, "living stone" : 2, "corrupted fey lifeblood" : 2 ]), ]), \
                  "wizard oil" : (["value" : 500, "dc" : 44, "materials" : ([ "sage" : 6, "allspice" : 4, "vervain" : 3, "tendril of flame" : 5, "nycissa orchid" : 1, "lich dust" : 1 ]), ]), \
              ])

// to add: hallucinogenic powder (dc 46)
#define POWDERS ([ \
                     "blinding powder" : (["value" : 25, "dc" : 22, "materials" : ([ "allspice" : 2, "bone dust" : 1, "nutshells" : 1 ]), ]), \
                     "choking powder" : (["value" : 50, "dc" : 30, "materials" : ([ "red pepper" : 2, "patch of demonskin" : 2, "pinch of soot" : 1 ]), ]), \
                     "powder of life" : (["value" : 75, "dc" : 35, "materials" : ([ "mint" : 1, "lavender" : 2, "corrupted fey lifeblood" : 1 ]), ]), \
                 ])

// to add: tanglefoot bag (dc 16), alchemists fire (dc 28)
#define MISC ([ \
                  "dwarfs pride tobacco" : (["value" : 1, "dc" : 10, "materials" : ([ "tobacco" : 2, ]), ]), \
                  "halflings homeblend tobacco" : (["value" : 1, "dc" : 10, "materials" : ([ "tobacco" : 1, "mint" : 1 ]), ]), \
                  "luxury of tharis tobacco" : (["value" : 1, "dc" : 10, "materials" : ([ "tobacco" : 1, "cinnamon" : 1 ]), ]), \
                  "pirates booty tobacco" : (["value" : 1, "dc" : 10, "materials" : ([ "tobacco" : 1, "vanilla" : 1 ]), ]), \
                  "tsarven tobacco" : (["value" : 1, "dc" : 10, "materials" : ([ "tobacco" : 1, "vanilla" : 1 ]), ]), \
                  "white dragon tobacco" : (["value" : 1, "dc" : 10, "materials" : ([ "tobacco" : 1, "chicory" : 1 ]), ]), \
              ])

// currently on hold, may be useful for future additions:
// all weapon poisons until poison itself can be re-written
// enlarge/reduce person (awaiting lib armor changes)
// protection from alignment (awaiting paladin spell)
// lesser restoration (once level drains exist)
